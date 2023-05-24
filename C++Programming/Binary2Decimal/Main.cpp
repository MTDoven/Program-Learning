# include <iostream>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# define MAX_INPUT_LENGTH 100

using namespace std;
int AsciiToInt(char ascii);
long long pow2(int times);

int main() {
	cout << "Input a binary number: ";
	char str[MAX_INPUT_LENGTH] = { 0 };
	scanf("%s", str);
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		int this_number = AsciiToInt(str[i]);
		if (this_number < 0 || this_number>1) {
			cout << "Please input binary number with right format.";
			return 1;
		} // check if between 0,1
		str[i] = this_number;
	} // get input finished
	
	int result = 0;
	for (int i = length-1; i >= 0; i--)
		result += str[length-i-1] * pow2(i);
	cout << "Output of decimal number: " << result<<endl;
	system("pause");

	return 0;
}


int AsciiToInt(char ascii) {
	if (ascii >= 48 && ascii <= 57)
		return ascii - 48;
	else return -1;
}
long long pow2(int times) {
	long long result = 1;
	for (int i = 0; i < times; i++) {
		result *= 2;
	} // Circle to pow
	return result;
}