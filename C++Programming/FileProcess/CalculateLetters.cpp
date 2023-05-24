#include "CalculateLetters.h"

map<char, int> calculate_letters(string str) {
	map<char, int> map;
	for (char letter : str) {
		letter = letter_filter(letter);
		if (map.count(letter) == 0) map[letter] = 1;
		else map[letter]++;
	} // count
	return map;
}
char letter_filter(char letter) {
	if (letter >= 65 && letter <= 90)
		return letter + 32;
	else if (letter >= 97 && letter <= 122)
		return letter;
	else // not a letter
		return -1;
}
void print_letter_map(map<char, int> map) {
	cout << "\nNumber of Letters:\n\t";
	for (char i = 97; i <= 105; i++) {
		if (map.count(i) != 0)
			printf("%c:%d\t", i - 32, map.find(i)->second);
	} printf("\n\t");
	for (char i = 106; i <= 114; i++) {
		if (map.count(i) != 0)
			printf("%c:%d\t", i - 32, map.find(i)->second);
	} printf("\n\t");
	for (char i = 115; i <= 122; i++) {
		if (map.count(i) != 0)
			printf("%c:%d\t", i - 32, map.find(i)->second);
	} printf("\n");
}