# include "Utils.h"


/* class Book below */

Book::Book() {};
Book::Book(int id, int number, string name, string publisher, string writers) {
    this->id = id;
    this->number = number;
    this->name = name;
    this->publisher = publisher;
    this->writer = writers;
} // Construct

int Book::getId() { return this->id; }
int Book::getNumber() { return this->number; }
string Book::getName() { return this->name; }
string Book::getPublisher() { return this->publisher; }
string Book::getWriters() { return this->writer; }
// Get some basic value

bool Book::equals(Book book) {
    bool a = book.getName() == this->name;
    bool b = book.getPublisher() == this->publisher;
    bool c = book.writer == this->writer;
    return a && b && c;
} // If the book is same as this one
string Book::toString() {
    return "ID:" + to_string(this->id) + "  Number:" + to_string(this->number)
            + "  Name:" + this->name + "  Publisher:" + this->publisher
            + "  Writers:" + this->writer;
} // Show information for this book 

double Book::Levenshtein(const string& s1, const string& s2) {
    const int m = s1.size();
    const int n = s2.size();
    int* v1 = new int[n + 1];
    int* v2 = new int[n + 1];
    for (int i = 0; i <= n; ++i) { v1[i] = i; }
    for (int i = 0; i < m; ++i) {
        v2[0] = i + 1;
        for (int j = 0; j < n; ++j) {
            int deletionCost = v1[j + 1] + 1;
            int insertionCost = v2[j] + 1;
            int substitutionCost = v1[j];
            if (s1[i] != s2[j]) { ++substitutionCost; }
            if (deletionCost < insertionCost) {
                v2[j + 1] = deletionCost < substitutionCost ?
                    deletionCost : substitutionCost;
            } else {
                v2[j + 1] = insertionCost < substitutionCost ?
                    insertionCost : substitutionCost; }
        } int* tmp = v1;  v1 = v2; v2 = tmp;
    } // Never touch
    int retval = v1[n];
    delete[]v1; delete[]v2;
    return 1.0 - (double)retval / max(m, n);
} // Levenshtein algorithm for string similarity calculate
double Book::Similarity(string str) {
    double max = Levenshtein(str, this->name);
    double temp; // saving max value
    temp = Levenshtein(str, this->writer);
    if (temp > max) { max = temp; }
    temp = Levenshtein(str, this->publisher);
    if (temp > max) { max = temp; }
    return max;
} // Similarity between input string and this book 

bool Book::is_available() { return this->number != 0; }
void Book::borrow() { this->number--; }
void Book::restore() { this->number++; }
void Book::add(int number) { this->number += number; }



/* class Student below */

Student::Student() {};
Student::Student(Long id, string name) {
    this->id = id;
    this->name = name;
    this->number = 3;
} // Construct for user
Student::Student(Long id, int number, string name) {
    this->id = id;
    this->name = name;
    this->number = number;
} // Construct for system
    
Long Student::getId() { return this->id; }
string Student::getName() { return this->name; }
int Student::getNumber() { return this->number; }
bool Student::equals(Student stu) { return stu.getId() == this->id; }
string Student::toString() { return "ID:" + to_string(this->id) + "  Name:" + this->name; }
bool Student::is_borrowable() { return this->number != 0; }
void Student::borrow() { this->number--; }
void Student::restore() { this->number++; }
// Get some basic value