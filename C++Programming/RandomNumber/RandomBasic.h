#pragma once

# include <iostream>
# include <functional>
# include <string>
# include <chrono>
# include <sstream>
# include <iomanip>

using namespace std;


class Random {

private:

	int random_mode;
	stringstream string_stream;
	hash<string> hasher;

public:

	Random();
	void randomstamp();
	int randint(int low, int high);
	double random();
};


