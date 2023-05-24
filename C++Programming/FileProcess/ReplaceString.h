#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

string replace_string(string str, string to_erase, string to_add);
string replace_string_icase(string str, string to_erase, string to_add);
string string_tolower(string str);