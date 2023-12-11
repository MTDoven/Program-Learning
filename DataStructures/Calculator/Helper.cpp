#include "helper.h"


double random(double mean, double std) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(mean, std);
    return distribution(generator);
}

void input(char*& string) {
    char* instring = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    std::cout << "\n\033[4;32mInput you expression:\033[0m ";
    std::cin >> instring;
    string = (char*)malloc((strlen(instring) + 3) * sizeof(char));
    strcpy(string + 1, instring);
    string[0] = '(';
    string[strlen(instring) + 1] = ')';
    string[strlen(instring) + 2] = '\0';
    free(instring);
    std::cout << "Your input expression is " << string << "\n";
}

double factorial(double number) {
    if (number < 0) return 0.0;
    int num = (int)(number + 0.5);
    long sum = 1;
    for (int i = 1; i <= num; i++)
        sum *= i;
    return (double)sum;
}