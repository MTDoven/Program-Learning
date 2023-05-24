#include "CalculateWords.h"

string string_filter(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	str = regex_replace(str, regex("[^a-zA-Z ]"), " ");
	str = regex_replace(str, regex(" +"), " ");
	return str;
}

void print_word_map(map<string, int> map) {
	cout << "\nNumber of Words:\n";
	for (auto& pair : map) {
		printf("\t%s: %d\n", pair.first.c_str(), pair.second);
	} // "\n" existed above
}

map<string, int> calculate_words(string str) {
	map<string, int> map;
	string temp = "";
	str = string_filter(str);
	for (char character : str) {
		if (character==' ' && (!temp.empty())) {
			if (map.count(temp) == 0) map[temp] = 1;
			else map[temp]++;
			temp = "";
		} else if (character != ' ')
			temp += character;
	} // list every charactor
	if (!temp.empty()) {
		if (map.count(temp) == 0) map[temp] = 1;
		else map[temp]++;
	} // last word, without any sign followed.
	return map;
}