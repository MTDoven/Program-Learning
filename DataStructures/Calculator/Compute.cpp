#include "Compute.h"

char global_space[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME] = { 0 };

char type_is(char x) {
	if (isdigit(x) || x == '.') return 'n';
	if (isalpha(x)) return 'a';
	if (x == '%' || x == '!' || x == '`' ||
		x == '*' || x == '/' || x == '+' || x == '-' || x == '^' || 
		x == '(' || x == ')' || x == '[' || x == ']' || x == '{' || x == '}') return 's';
	if (x == '_') return 'u';
	if (x == '\0') return '1';
	return '1';
}

void extract_string(char* src, char dst[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME]) {
	int index = 1;
	int item_number = 0;
	int item_index = 0;
	char sign = '0';
	while (true) {
		if (sign == '0') {
			sign = type_is(src[index]);
		}
		else if (sign == 'n') {
			sign = type_is(src[index]);
			if (sign != 'n') {
				item_number++;
				item_index = 0;
			}
		}
		else if (sign == 'a') {
			sign = type_is(src[index]);
			if (sign != 'a') {
				item_number++;
				item_index = 0;
			}
		}
		else if (sign == 's') {
			sign = type_is(src[index]);
			item_number++;
			item_index = 0;
		}
		else if (sign == 'u') {
			dst[item_number][item_index] = src[index];
			index++;
			item_index = 0;
			sign = type_is(src[index+1]);
			continue;
		}
		else if (sign == '1') {
			break;
		}
		dst[item_number][item_index] = src[index];
		index++;
		item_index++;
	}
	item_number = 0;
	while (true) {
		if (strcmp(dst[item_number], "e") == 0)
			strcpy(dst[item_number], "2.71828182845905");
		else if (strcmp(dst[item_number], "pai") == 0)
			strcpy(dst[item_number], "3.14159265358979");
		else if (dst[item_number][0] == '[' || dst[item_number][0] == '{')
			dst[item_number][0] = '(';
		else if (dst[item_number][0] == ']' || dst[item_number][0] == '}')
			dst[item_number][0] = ')';
		else if (strcmp(dst[item_number], "log") == 0)
			strcpy(dst[item_number], "f");
		else if (strcmp(dst[item_number], "lg") == 0)
			strcpy(dst[item_number], "g");
		else if (strcmp(dst[item_number], "ln") == 0)
			strcpy(dst[item_number], "h");
		else if (strcmp(dst[item_number], "sin") == 0)
			strcpy(dst[item_number], "i");
		else if (strcmp(dst[item_number], "cos") == 0)
			strcpy(dst[item_number], "j");
		else if (strcmp(dst[item_number], "tan") == 0)
			strcpy(dst[item_number], "k");
		else if (strcmp(dst[item_number], "arcsin") == 0)
			strcpy(dst[item_number], "l");
		else if (strcmp(dst[item_number], "arccos") == 0)
			strcpy(dst[item_number], "m");
		else if (strcmp(dst[item_number], "arctan") == 0)
			strcpy(dst[item_number], "n");
		else if (strcmp(dst[item_number], "csc") == 0)
			strcpy(dst[item_number], "o");
		else if (strcmp(dst[item_number], "sec") == 0)
			strcpy(dst[item_number], "p");
		else if (strcmp(dst[item_number], "cot") == 0)
			strcpy(dst[item_number], "q");
		else if (strcmp(dst[item_number], "min") == 0)
			strcpy(dst[item_number], "w");
		else if (strcmp(dst[item_number], "max") == 0)
			strcpy(dst[item_number], "x");
		else if (strcmp(dst[item_number], "positive") == 0)
			strcpy(dst[item_number], "y");
		else if (strcmp(dst[item_number], "negative") == 0)
			strcpy(dst[item_number], "z");
		else if (strcmp(dst[item_number], "solve") == 0)
			strcpy(dst[item_number], "A");
		else if (dst[item_number][0] == '\0')
			break;
		item_number++;
	}
}

double compute_one_step(double x, char sign, double y) {
	switch (sign){
		case '+': return x + y;
		case '-': return x - y;
		case '*': return x * y;
		case '/': return x / y;
		case '^': return pow(x, y);
		case '%': return x / 100.0;
		case '!': return factorial(x);
		case '`': return x * 3.14159265358979 / 180.0;
		case 'f': return log(y) / log(x);
		case 'g': return log(y) / log(10.0);
		case 'h': return log(y);
		case 'i': return sin(y);
		case 'j': return cos(y);
		case 'k': return tan(y);
		case 'l': return asin(y);
		case 'm': return acos(y);
		case 'n': return atan(y);
		case 'o': return 1.0 / sin(y);
		case 'p': return 1.0 / cos(y);
		case 'q': return 1.0 / tan(y);
		case 'y': return y;
		case 'z': return 0.0 - y;
	}
}

int sign_level(char a) {
	if (a == '%' || a == '!' || a == '`') return 5;
	if (a == '^' || a == 'f') return 4;
	if ((a >= 'g' && a <= 'q') || a == 'y' || a == 'z') return 3;
	if (a == '*' || a == '/') return 2;
	if (a == '+' || a == '-') return 1;
	std::cout << "unknown sign: " << a << "\n";
	return -1;
}

int sign_compare(char a, char b) {
	if (a == '(' || b == '(') return 1;
	else if (a == ')' || b == ')') return -1;
	else if (sign_level(a) > sign_level(b)) return 1;
	else if (sign_level(a) < sign_level(b)) return -1;
	else return 0;
}


double Compute(char expression[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME]){
	struct SqStack<double> NUMBER_init, *NUMBER;	
	initStack<double>(&NUMBER_init); 
	NUMBER = &NUMBER_init;
	struct SqStack<char> SIGNS_init, *SIGNS; 
	initStack<char>(&SIGNS_init); 
	SIGNS = &SIGNS_init;

	push<char>(SIGNS, '(');
	int item_number = 0;
	char* this_string;
	char this_sign;
	double this_number_a;
	double this_number_b;
	double this_number_r;
	int this_sign_level;

	while (true) {
		this_string = expression[item_number];

		if (this_string[0] == '\0') {
			break;
		} // finished
		if (type_is(this_string[0]) == 'n') {
			push<double>(NUMBER, atof(this_string));
			item_number++;
			continue;
		} // is a number
		if (type_is(this_string[0]) == 'u') {
			push<double>(NUMBER, atof(this_string+2));
			item_number++;
			continue;
		} // is an unknown
		if (this_string[0] == ')' && getTop<char>(SIGNS) == '(') {
			pop<char>(SIGNS);
			item_number++;
			continue;
		} // process (###)
		if (sign_compare((this_string[0]), getTop<char>(SIGNS)) > 0) {
			push<char>(SIGNS, this_string[0]);
			item_number++;
			continue;
		} // prior level

		this_sign = pop<char>(SIGNS);
		this_sign_level = sign_level(this_sign);
		if (this_sign_level == 5) {
			this_number_b = 0.0;
			this_number_a = pop<double>(NUMBER);
		}
		else if (this_sign_level == 4 || this_sign_level == 2 || this_sign_level == 1) {
			this_number_b = pop<double>(NUMBER);
			this_number_a = pop<double>(NUMBER);
		}
		else if (this_sign_level == 3) {
			this_number_b = pop<double>(NUMBER);
			this_number_a = 0.0;
		}
		this_number_r = compute_one_step(this_number_a, this_sign, this_number_b);
		push<double>(NUMBER, this_number_r);
	}

	this_number_r = pop<double>(NUMBER);
	return this_number_r;
}


void to_global(char expression[MAX_OPERATE_NUMBER][MAX_OPERATE_NAME]) {
	int item_number = 0;
	while (expression[item_number][0] != '\0') {
		strcpy(global_space[item_number], expression[item_number]);
		item_number++;
	}
}
double Compute_with_unknown(Point point) {
	int item_number = 0;
	char* this_string = global_space[0];
	char temp_string[MAX_OPERATE_NAME] = { 0 };
	while (this_string[0] != '\0') {
		this_string = global_space[item_number];
		if (this_string[0] == '_') {
			sprintf(temp_string, "%.16lf", point[this_string[1]-48]);
			strcpy(this_string+2, temp_string);
		}
		item_number++;
	}
	return Compute(global_space);
}

