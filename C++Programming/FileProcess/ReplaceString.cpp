#include "ReplaceString.h"

using namespace std;

string replace_string(string str, string to_erase, string to_add) {
	str = regex_replace(str, regex(to_erase), to_add);
	return str;
}
string replace_string_icase(string str, string to_erase, string to_add) {
	str = regex_replace(str, regex(to_erase, regex::icase), to_add);
	return str;
}
string string_tolower(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}