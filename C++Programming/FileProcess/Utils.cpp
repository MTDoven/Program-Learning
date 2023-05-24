#include "Utils.h"

void pause() {
	cout << "\nPress enter to continue...\n";
	getchar();
} // Pause.

void string_to_file(string str, string file) {
    ofstream fileptr;
    fileptr.open(file, ios::out);
    fileptr << str;
    fileptr.close();
} // Save string to file.

