#pragma once
#include "define.h"
#include "stack.h"
#include "Helper.h"
#include <cmath>
#include <cstring>
#include <ctype.h>

char type_is(char x);
void extract_string(char* src, char dst[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME]);
// ���������ʽ�е����ֺ���������룬���洢����ά������

int sign_level(char a);
int sign_compare(char a, char b);
double compute_one_step(double x, char sign, double y);
// �ж�����ȼ������ȼ��������м�һĿ���Ŀ����

double Compute(char expression[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME]);
// ��������ĺ�������ɼ���ʽ����ֵ�����ؽ��

void to_global(char expression[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME]);
double Compute_with_unknown(Point point);
// �������δ֪���ı��ʽ�����������ض��㴦��ֵ


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