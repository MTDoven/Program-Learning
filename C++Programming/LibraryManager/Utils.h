#pragma once

# include <string>
# include <list>
# include <map>

using namespace std;
typedef unsigned long long Long;


class Book {
private:
    int id;
    int number;
    string name;
    string publisher;
    string writer;
public:
    Book();
    Book(int id, int number, string name, string publisher, string writers);
    int getId();
    int getNumber();
    string getName();
    string getPublisher();
    string getWriters();
    bool equals(Book book);
    string toString();
    double Levenshtein(const string& s1, const string& s2);
    double Similarity(string str);
    bool is_available();
    void borrow();
    void restore();
    void add(int number);
};

class Student {
private:
    Long id;
    string name;
    int number;
public:
    Student();
    Student(Long id, string name);
    Student(Long id, int number, string name);
    Long getId();
    string getName();
    int getNumber();
    bool equals(Student stu);
    string toString();
    bool is_borrowable();
    void borrow();
    void restore();
};
