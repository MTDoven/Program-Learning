#pragma once

# include "Utils.h"

using namespace std;
typedef unsigned long long Long;


class Database {

private:
    int countbook;
    int countstudent;

public:
    map<int, Book> books;
    map<Long, Student> students;
    Database();
    Database(string path);
    int save(string path);

    int addbook(int number, string name, string publisher, string writer);
    void delbook(Book book);
    Long addstudent(Long id, string name);
    void delstudent(Student student);
    
    string toString();
    map<int, Book> getBooks();
    map<Long, Student> getStudents();
    int getCountbook();
    int getCountstudent();

    list<Book> search_book(string str);
    Book search_book(int id);
    Student search_student(string str);
    Student search_student(Long id);
};

