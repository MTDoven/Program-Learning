import torch
from evolutionary import Evolutionary


def function1(x):
    y = torch.sum(torch.square(x), dim=-1, keepdim=True)
    return -y


def function2(x):
    y = torch.prod(torch.abs(x), dim=-1) + torch.sum(torch.abs(x), dim=-1)
    return -y


def function3(x):
    y = torch.sum(torch.square(torch.cumsum(x, dim=-1)), dim=-1, keepdim=True)
    return -y


def function4(x):
    y = -x * torch.sin(torch.sqrt(torch.abs(x)))
    y = torch.sum(y, dim=-1, keepdim=True)
    return -y


def function5(x):
    y = x**2 - 10 * torch.cos(2*torch.pi*x) + 10
    y = torch.sum(y, dim=-1, keepdim=True)
    return -y


def function6(x):
    y1 = torch.mean(x**2, dim=-1, keepdim=True)
    y2 = torch.mean(torch.cos(2*torch.pi*x), dim=-1, keepdim=True)
    y1 = torch.exp(-0.2*y1)
    y2 = torch.exp(y2)
    y = 20*(1-y1)+torch.e-y2
    return -y


function = function1


result_list = []
def callback(group):
    best = -function(group[0:1])
    result_list.append(best.item())
init = torch.rand([1000, 2])*100-50

group = Evolutionary(
    fittness_fn=function,
    initiation=init,
    encoder=None,
    decoder=None,
    clamp_fn=None,
    crossover_prob=0.8,
    mutation_prob=0.1,
    num_offsprings=None,
    fitness_upper_bound=None,
    max_iter=10000
).fit(callback=callback)

print(list(reversed(result_list)))



