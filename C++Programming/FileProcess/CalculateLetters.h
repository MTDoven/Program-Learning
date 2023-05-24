#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> calculate_letters(string str);
char letter_filter(char letter);
void print_letter_map(map<char, int> map);
