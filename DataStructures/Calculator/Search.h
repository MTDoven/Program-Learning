#pragma once
#include "define.h"
#include "Helper.h"
#include <malloc.h>

Point get_new_node(Point origin, int vars, double std);
// 在原有节点周边拓展新的节点

int lenlist(List list);
void clearlist(List list);
void sortlist(List list, double (*func)(Point));
// 对OPEN表和CLOSE表进行的相关操作

Point Search_min(double (*func)(Point), int vars, double stop_loss);
// 综合以上算法搜索最小值



