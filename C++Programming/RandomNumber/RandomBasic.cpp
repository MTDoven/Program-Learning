# include "RandomBasic.h"

Random::Random() {
	auto t = chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	string_stream << put_time(localtime(&t), "%Y%M%H%m%d%S");
	int random_mode = 1;
} // init

void Random::randomstamp() {
	string rubbish;
	rubbish = string_stream.str();
	if (rubbish.size() > 1024) {
		string_stream.str("");
		string_stream.clear();
	} // avoid too long
	auto t = chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	if (random_mode == 1) {
		string_stream << put_time(localtime(&t), "%m%Y%d%S%H%M");
		random_mode == 2;
	} else if (random_mode == 2) {
		string_stream << put_time(localtime(&t), "%Y%S%m%M%d%H");
		random_mode == 3;
	} else { // (random_mode == 3)
		string_stream << put_time(localtime(&t), "%Y%M%H%m%d%S");
		random_mode == 1;
	} // put into string_stream
} // set random stamp

int Random::randint(int low, int high) {
	randomstamp();
	unsigned int randint = (unsigned int)hasher(string_stream.str());
	int result = randint % (high - low + 1) + low;
	return result;
} // get randint

double Random::random() {
	double result = ((double)randint(0,195225786)) / 195225786.0;
	return result;
} // get randdouble
