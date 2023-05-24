#include "ProcessCFile.h"

string erase_annotation(string str) {
	string regex_string = "(/\\*([^*]|[\\r\\n]|(\\*+([^*/]|[\\r\\n])))*\\*+/)|(//(.*)\\n)";
	str = regex_replace(str, regex(regex_string), "");
	return str;
} // erase annotation

string add_linehead(string str) {
	int number = 2;
	string builder = "1\t";
	for (char letter : str) {
		if (letter == '\n') {
			builder += ("\n" + to_string(number) + "\t");
			number++;
		} // next line
		else builder += letter;
	} // search all characters
	return builder;
} // add linehead



