# include "RandomBasic.h"
# define LARGEST_ITEMS 100
# define RUBBISH_LENGTH 100

using namespace std;
void RandomNumberGenerater(Random& randomer);
void GuessNumberGame(Random& randomer);
void pause() {
	cout << "\nPress enter to continue...\n";
	getchar();
} // pause

int main() {
	Random randomer;

start:

	cout << "\033cRandom Game [Version 0.1.2]\n";
	cout << "(c)MTDoven. All right reserved.\n\n";
	cout << "-------------------- Random Game --------------------\n";
	cout << "0. To Exit\n";
	cout << "1. Random Number Generater\n";
	cout << "2. Number Guessing Game\n";
	cout << "3. Get Help\n";
	cout << "Input your number: ";
	int choice; cin >> choice; getchar();

	if (choice == 1) {
		RandomNumberGenerater(randomer);
		pause(); goto start;
	} else if (choice == 2) {
		GuessNumberGame(randomer);
		pause(); goto start;
	} else if (choice == 0){
		goto end;
	} else if (choice == 3) {
		cout << "\nContact me if any problem.\n";
		cout << "E-mail: MTDovent@gmail.com\n";
		cout << "QQ: 1317867671\n";
		pause(); goto start;
	}

end:

	cout << "\nThank you for using ^_^\n";
	return 0;
}


void GuessNumberGame(Random& randomer) {
	cout << "\n";
	cout << "Here start the game!\n\n";
	int number = randomer.randint(0,99);
	int user_answer = -1;
	while (true) {
		cout << "Put in your number: ";
		cin >> user_answer;
		if (user_answer > number) {
			cout << "\tToo big!\n";
		} else if (user_answer < number) {
			cout << "\tToo small!\n";
		}else if (user_answer == number) {
			cout << "\tYou win! Good job!\n";
			getchar(); // clear
			break;
		} else // Unexpected value
			throw "Unexpected value";
	} // main circle in game
}

void RandomNumberGenerater(Random& randomer) {
	cout << "\n";
	cout << "How many numbers do you want: ";
	int items; cin >> items;
	if (items < 0) items = -items;
	cout << "Input the lower and higher bound of numbers: ";
	int low, high;
	char rubbish[RUBBISH_LENGTH] = "";
	scanf("%[^0-9]%d%[^0-9]%d", rubbish, &low, rubbish, &high);
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear
	// input and time counting
	if (items > high - low + 1) {
		cout << "Number of items is bigger than bound.\n";
		return;
	} // check number
	int randints[LARGEST_ITEMS] = { 0 };
	for (int i = 0; i < items; i++) {
		int randint = randomer.randint(low, high);
		randints[i] = randint;
		for (int j = 0; j < i; j++)
			if (randint == randints[j])	i--;
	} // get random numebr
	cout << "\nOutput of the random number: \n";
	for (int i = 0; i < items; i++)
		cout << randints[i] << " ";
	cout << "\n";
	// output
}