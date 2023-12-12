#pragma once
#include "define.h"
#include "stack.h"
#include "Helper.h"
#include <cmath>
#include <cstring>
#include <ctype.h>

char type_is(char x);
void extract_string(char* src, char dst[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME]);
// 将输入计算式中的数字和运算符分离，并存储到二维数组中

int sign_level(char a);
int sign_compare(char a, char b);
double compute_one_step(double x, char sign, double y);
// 判断运算等级和优先级，并进行简单一目或二目运算

double Compute(char expression[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME]);
// 调用上面的函数，完成计算式的求值并返回结果

void to_global(char expression[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME]);
double Compute_with_unknown(Point point);
// 处理具有未知量的表达式，计算它在特定点处的值


// u:unknow
// n:number
// a:alpha
// s:sign
// 1:end

// a:+
// b:-
// c:*
// d:/
// e:^
// r:%
// s:! 
// t:`
// u:(
// v:)
// w:min
// x:max
// y:positive
// z:negtive
// f:log
// g:lg
// h:ln
// i:sin
// j:cos
// k:tan
// l:arcsin
// m:arccos
// n:arctan
// o:csc
// p:sec
// q:cot