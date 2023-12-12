#include "Search.h"

Point get_new_node(Point origin, int vars, double std) {
	Point new_node = (Point)malloc((vars + 1) * sizeof(double));
	for (int i = 0; i < vars; i++)
		new_node[i] = random(origin[i], std);
	new_node[vars] = NAN;
	return new_node;
}

int lenlist(List list) {
	for (int length = 0; true; length++)
		if (list[length] == NULL) return length;
}

void clearlist(List list) {
	if (lenlist(list) < MAX_LIST_LENGTH - 1024)
		return;
	for (int i = MAX_LIST_LENGTH / 2; list[i + 1] != NULL; i++)
		free(list[i]);
	list[MAX_LIST_LENGTH / 2] = NULL;
}

void sortlist(List list, double (*func)(Point)) {
	int length = lenlist(list);
	double* results = (double*)malloc(length * sizeof(double));
	for (int i = 0; i < length; i++)
		results[i] = (*func)(list[i]);
	for (int i = 0; i < length - 1; i++)
		for (int j = 0; j < length - 1 - i; j++)
			if (results[j] > results[j + 1]) {
				double temp1 = results[j + 1];
				results[j + 1] = results[j];
				results[j] = temp1;
				Point temp2 = list[j + 1];
				list[j + 1] = list[j];
				list[j] = temp2;
			}
	free(results);
}

Point Search_min(double (*func)(Point), int vars, double stop_loss) {
	List OPEN = (List)malloc((MAX_LIST_LENGTH + 1) * sizeof(Point));
	double min = 1.79768e+308;
	int count = (int)pow(2.0, pow((double)vars, 0.45)) + 8;
	double bias = INIT_BIAS;
	double now_number = 0;
	int length = 0;

	Point now_point = (Point)malloc((vars + 1) * sizeof(double));
	for (int i = 0; i < vars; i++)
		now_point[i] = 0.0;
	now_point[vars] = NAN;

	while (bias > stop_loss && now_number > MIN_BOUND) {
		for (int i = length; i < count + length; i++)
			OPEN[i] = get_new_node(now_point, vars, bias);
		OPEN[count + length] = NULL;

		length = lenlist(OPEN);
		sortlist(OPEN, *func);
		clearlist(OPEN);
		now_number = (*func)(OPEN[0]);

		if (min > now_number) {
			min = now_number;
			now_point = OPEN[0];
		}
		else {
			bias = bias / 2.0;
			continue;
		}
	}

	Point result = (Point)malloc((vars + 1) * sizeof(double));
	for (int i = 0; i < vars; i++)
		result[i] = now_point[i];
	for (int i = 0; OPEN[i + 1] != NULL; i++)
		free(OPEN[i]);
	free(OPEN);

	return result;
}
