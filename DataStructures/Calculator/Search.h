#pragma once
#include "define.h"
#include "Helper.h"
#include <malloc.h>

Point get_new_node(Point origin, int vars, double std);
int lenlist(List list);
void clearlist(List list);
void sortlist(List list, double (*func)(Point));
Point Search_min(double (*func)(Point), int vars, double stop_loss);