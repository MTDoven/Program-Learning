#include "Utils.h"
#include "CalculateLetters.h"
#include "CalculateWords.h"
#include "ReplaceString.h"
#include "ProcessCFile.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main(int argn, char* args[]) {

/* Void neccessary varies */
	ifstream fileptr;
	stringstream stringstream;
	string str;
	map<char, int> letters_map;
	map<string, int> words_map;
	string replaced_string;
	string arg;
	

/* Preprocess to avoid some problem caused by invalid input */
	if (argn != 2) {
		goto reload;
	} // Only one parameter can be accept
	arg = string(args[1]);

load:

/* Read all the file into str */
	fileptr = ifstream(arg);
	if (!fileptr.is_open()) {
		cout << "Input a proper file name (path to a file).\n";
		goto reload;
	} // Ensure file exists and is readable.
	stringstream.str("");
	stringstream.clear();
	stringstream << fileptr.rdbuf();
	str = stringstream.str();
	fileptr.close();
	// Read the whole text into a string.
	

/* Main part, for user operation. */

start:

	cout << "\033c"; // clear
	cout << "File Operater [Version 0.1.3]\n";
	cout << "(c)MTDoven. All rights reserved.\n";
	cout << "\n-------------------- File Operater --------------------\n";
	cout << "0. Close file and exit.\n";
	cout << "1. Count the number of letters.\n";
	cout << "2. Search and replace a string.\n";
	cout << "3. Count the number of words.\n";
	cout << "4. Search and replace a word.\n";
	cout << "5. Process C/C++ files.\n";
	cout << "6. Reload another file.\n";
	cout << "7. Get help.\n";
	cout << "Enter a number: ";
	int choice; cin >> choice; getchar();
	// Start page.

	if (choice == 0) {
		goto end;
	} // To exit.

	else if (choice == 1) {
		letters_map = calculate_letters(str);
		print_letter_map(letters_map);
		pause(); goto start;
	} // Count the number of letters.

	else if (choice == 2) {
		cout << "\nEnter the string you want to erase: ";
		string string_to_erase; cin >> string_to_erase;
		cout << "Enter the string you want to add: ";
		string string_to_add; cin >> string_to_add; 
		getchar(); // clear input stream
		replaced_string = replace_string(str, string_to_erase, string_to_add);
		string_to_file(replaced_string, arg);
		cout << "Save replaced file to " << arg << endl;
		pause(); goto load;
	} // Search and replace a string.

	else if (choice == 3) {
		words_map = calculate_words(str);
		print_word_map(words_map);
		pause(); goto start;
	} // Count the number of words.

	else if (choice == 4) {
		cout << "\nEnter the word you want to erase: ";
		string string_to_erase; cin >> string_to_erase;
		cout << "Enter the word you want to add: ";
		string string_to_add; cin >> string_to_add;
		getchar(); // clear input stream
		words_map = calculate_words(str);
		if (words_map.count(string_tolower(string_to_erase)) == 0) {
			cout << "Cannot find word " << string_to_erase << endl;
			pause(); goto start;
		} // connot find inputed word
		replaced_string = replace_string_icase(str, string_to_erase, string_to_add);
		string_to_file(replaced_string, arg);
		cout << "Save replaced file to " << arg << endl;
		pause(); goto load;
	} // Search and replace a word.

	else if (choice == 5) {
		string outputfile;
		cout << "\nEnter output file name: ";
		cin >> outputfile;
		getchar(); // clean instream
		string processed_string;
		processed_string = erase_annotation(str);
		processed_string = add_linehead(processed_string);
		string_to_file(processed_string, outputfile);
		cout << "Save processed file to " << outputfile << endl;
		pause(); goto load;
	} // Process C/C++ files.

	else if (choice == 6) {
reload:
		cout << "\nEnter new file name: ";
		cin >> arg;
		goto load;
	} // To reload

	else if (choice == 7) {
		cout << "\nContact me if any problem.\n";
		cout << "E-mail: MTDovent@gmail.com\n";
		cout << "QQ: 1317867671\n";
		pause(); goto start;
	} // Get help

	else { // invalid number
		cout << "Please enter a proper number.\n";
		pause(); goto start;
	} // When an invalid number inputted.


end:
	cout << "\nThank you for using ^_^\n";
	return 0;
}



