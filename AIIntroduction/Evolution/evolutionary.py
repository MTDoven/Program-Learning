import torch
from typing import Union, Callable, Any

Tensor = Union[torch.Tensor, torch.cuda.FloatTensor]
Float = Union[float, torch.Tensor, torch.cuda.FloatTensor]


class Evolutionary:
    def __init__(self,
                 fittness_fn: Callable,
                 initiation: Any,
                 encoder: Callable = None,
                 decoder: Callable = None,
                 clamp_fn: Callable = None,
                 crossover_prob: float = 0.8,
                 mutation_prob: float = 0.05,
                 mutation_std: float = 0.25,
                 fitness_upper_bound=None,
                 num_offsprings: int = None,
                 max_iter = 100000,
                 device = "cpu",
                 ) -> None:
        """
        Evolutionary algorithm
        :param fittness_fn: (Callable) Fitness function
        :param initiation: (Any) Initial point, not encoded
        :param encoder: (Callable) Encoder, default lambda x:x
        :param decoder: (Callable) Decoder, default lambda x:x
        :param clamp_fn: (Callable) clamp_fn, receive decoded information
        :param crossover_prob: (float) The probability of crossing
        :param mutation_prob: (float) The probability of mutation
        :param fitness_upper_bound: ()
        :param num_offsprings: (int) The number of each generation (default: same as initialization)
        :param max_iter: Maximum number of iterations (default: 100000)
        """
        self.encoder = encoder if encoder is not None else lambda x:x
        self.decoder = decoder if decoder is not None else lambda x:x
        self.clamp_fn = clamp_fn
        self.fittness_fn = fittness_fn
        self.group = self.encoder(initiation) if clamp_fn is None else self.encoder(self.clamp_fn(initiation))
        self.num_offsprings = num_offsprings if num_offsprings is not None else len(self.group)
        self.fitness_upper_bound = fitness_upper_bound if fitness_upper_bound is not None else torch.nan
        self.crossover_prob = crossover_prob
        self.mutation_prob = mutation_prob
        self.mutation_std = mutation_std
        self.max_iter = max_iter
        self.device = device
        # counter
        self.accumulated_iter = 0
        self.accumulated_accumulated_iter = 0

    def fit(self,
            callback: Callable = None
            ) -> Any:
        """
        To fit the function
        :param callback: callback function executed every iteration
        :return: (Any) decoded results
        """
        temp = torch.randn_like(self.group[:self.num_offsprings//20])
        for i in range(self.max_iter):
            offsprings = self.select(self.group, num_offsprings=self.num_offsprings)
            offsprings = self.crossover(offsprings, self.crossover_prob)
            offsprings = self.mutate(offsprings, self.mutation_prob)
            try:  # Get rid of maladaptive individuals
                self.group = self.eliminate(self.group, offsprings)
            except StopIteration:
                break
            # process stuck
            if torch.allclose(self.group[:self.num_offsprings//20], temp):
                self.accumulated_iter += 1
            temp = self.group[:self.num_offsprings//20].clone()
            if self.accumulated_iter >= 20:
                self.mutation_std = self.mutation_std/2 if self.mutation_std > 1e-12 else 1e-15
                self.mutation_prob = self.mutation_prob+0.05 if self.mutation_prob<0.9 else self.mutation_prob
                self.crossover_prob = self.mutation_std/2 if self.mutation_std > 1e-12 else 1e-15
                self.accumulated_accumulated_iter += 1
                self.accumulated_iter = 0
            if self.accumulated_accumulated_iter >= 20:
                break
            if callback is not None:
                callback(self.decoder(self.group))
        return self.decoder(self.group)

    def eliminate(self,
                  parents: Tensor,
                  offsprings: Tensor
                  ) -> Tensor:
        """
        Get rid of maladaptive individuals
        :param parents: (Tensor) shape is (num_individuals, num_parameters)
        :param offsprings: (Tensor) shape is (num_individuals, num_parameters)
        :return: (Tensor) shape is (num_individuals, num_parameters)
        """
        group = torch.cat((parents, offsprings), dim=0)
        fitness = self.fittness_fn(self.decoder(group)).flatten()
        probability = torch.softmax(fitness / (fitness.std()+1e-5), dim=0)
        _, elite_index = torch.topk(probability, k=self.num_offsprings//20 or 1)
        elites = torch.index_select(group, dim=0, index=elite_index)
        normal_index = torch.multinomial(probability, self.num_offsprings-self.num_offsprings//20, replacement=False)
        offsprings = torch.index_select(group, dim=0, index=normal_index)
        offsprings = torch.cat((elites, offsprings), dim=0)
        if (torch.index_select(fitness, dim=0, index=elite_index) > self.fitness_upper_bound).all():
            self.group = offsprings
            raise StopIteration
        return offsprings

    def select(self,
               parents: Tensor,
               num_offsprings: Float = None
               ) -> Tensor:
        """
        Select the offspring population
        :param parents: (Tensor) shape is (num_individuals, num_parameters)
        :param num_offsprings: how many offsprings there will be
        :return:
        """
        num_parents = len(parents)
        num_offsprings = num_offsprings if num_offsprings is not None else num_parents
        fitness = self.fittness_fn(self.decoder(parents)).flatten()
        probability = torch.softmax(fitness / (fitness.std()+1e-5), dim=0)
        index = torch.multinomial(probability, num_offsprings, replacement=True)
        offsprings = torch.index_select(parents, dim=0, index=index)
        return offsprings

    def mutate(self,
               offsprings: Tensor,
               probability: Float = 0.1
               ) -> Tensor:
        """
        Do the mutation
        :param offsprings: (Tensor) shape is (num_individuals, num_parameters)
        :param probability: (Float) probability of mutation
        :param std: (Float) Standard deviation of the Gaussian distribution of the range of variation
        :return: (Tensor) shape is the same as parameters
        """
        mask_to_mutate: Tensor = torch.rand_like(offsprings) < probability
        all_mutated_parameters = offsprings + torch.randn_like(offsprings) * self.mutation_std
        offsprings = torch.where(mask_to_mutate, all_mutated_parameters, offsprings)
        if self.clamp_fn is not None:
            offsprings = self.encoder(self.clamp_fn(self.decoder(offsprings)))
        return offsprings

    def crossover(self,
                  offsprings: Tensor,
                  probability: Float = 0.8
                  ) -> Tensor:
        """
        Do the crossover
        :param parameters: (Tensor) shape is (num_individuals, num_parameters)s
        :param probability: (Float) probability of mutation
        :return: (Tensor) shape is the same as parameters
        """
        def _shuffle(tensors):
            index = torch.randperm(offsprings.shape[0])
            tensors = tensors[index].view(tensors.shape)
            return tensors
        def _swap(vectors: Tensor):
            if torch.rand(1) > probability: return
            vector1, vector2 = vectors[0], vectors[1]
            i = torch.randint(0, len(vector1) + 1, [2])
            i = i if i[0] <= i[1] else torch.flip(i, dims=[0])
            temp = vector2[i[0]:i[1]].clone()
            vector2[i[0]:i[1]] = vector1[i[0]:i[1]]
            vector1[i[0]:i[1]] = temp
        num_offsprings = len(offsprings)
        offsprings = _shuffle(offsprings).view((num_offsprings//2, 2, offsprings.shape[-1]))
        map(_swap, offsprings)
        if self.clamp_fn is not None:
            offsprings = self.encoder(self.clamp_fn(self.decoder(offsprings)))
        return offsprings.view(num_offsprings, -1)

