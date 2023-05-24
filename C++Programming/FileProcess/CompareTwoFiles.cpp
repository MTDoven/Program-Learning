#include "CompareTwoFiles.h"

string compare_strings(string str1, string str2) {
	int length = (str1.size() < str2.size()) ? str1.size(): str2.size();
	const char* cstr1 = str1.c_str();
	const char* cstr2 = str2.c_str();
	int same_flag = 0;
	int i;
	for (i = 0; i < length; ) {
		if (same_flag == 0) {
			if (cstr1[i] == cstr2[i]) {
				i++; continue;
			} else {
				same_flag = 1;
			} // find different
		} else if (same_flag == 1) {
			i--;
			if (cstr1[i] == '\n') {
				same_flag = 2; break;
			} // find "\n"
		} else throw "Invalid flag";
	} // start from the different line
	if (i == length) return "";
	int i_backup = i;
	string strout = "File1: ";
	while (cstr1[++i] != '\n')
		strout += cstr1[i];
	strout += "\nFile2: ";
	i = i_backup;
	while (cstr2[++i] != '\n')
		strout += cstr2[i];
	strout += '\n';
	return strout;
}

string file_to_string(ifstream& fileptr) {
	stringstream stringstream;
	stringstream.str("");
	stringstream.clear();
	stringstream << fileptr.rdbuf();
	string str = stringstream.str();
	fileptr.close();
	return str;
}