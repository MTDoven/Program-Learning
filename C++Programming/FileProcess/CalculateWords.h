#pragma once

#include <iostream>
#include <algorithm>
#include <regex>
#include <map>

using namespace std;

string string_filter(string str);
void print_word_map(map<string, int> map);
map<string, int> calculate_words(string str);
