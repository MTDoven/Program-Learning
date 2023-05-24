# include "Database.h"


/* class Database below */

Database::Database() {
    this->countbook = 0;
    this->countstudent = 0;
} // Construct no usage
Database::Database(string path) {
    int count = 0;
    printf("%s", (path + ".book").c_str());
    FILE* fp1 = fopen((path + ".book").c_str(), "rb");
    int book_number = 0;
    fscanf(fp1, "%d %d", &book_number, &this->countbook);
    for (int i = 0; i < book_number; i++) {
        int id = 0;
        int number = 0;
        char name[50] = { 0 };
        char publisher[50] = { 0 };
        char writer[50] = { 0 };
        fscanf(fp1, "%d %d %s %s %s", &id, &number, name, publisher, writer);
        Book book = Book(id, number, (string)name, (string)publisher, (string)writer);
        books[id] = book;
        count++;
    } fclose(fp1);
    // Load book information
    FILE* fp2 = fopen((path + ".student").c_str(), "rb");
    int student_number = 0;
    fscanf(fp2, "%d %d", &student_number, &this->countstudent);
    for (int i = 0; i < student_number; i++) {
        Long id = 0;
        int number = 0;
        char name[50] = { 0 };
        fscanf(fp2, "%lld %d %s", &id, &number, name);
        Student student = Student(id, number, (string)name);
        students[id] = student;
        count++;
    } fclose(fp2);
    // Load student information
} // Construct from database

int Database::save(string path) {
    int count = 0;
    FILE* fp1 = fopen((path + ".book").c_str(), "w");
    if (!fp1) return -1;
    fprintf(fp1, "%d %d\n", books.size(), countbook);
    for (map<int, Book>::iterator it = books.begin(); it != books.end(); it++) {
        Book book = it->second;
        fprintf(fp1, "%d %d %s %s %s\n", book.getId(), book.getNumber(),
            book.getName().c_str(), book.getPublisher().c_str(), book.getWriters().c_str());
        count++;
    } fclose(fp1);
    // Save book information
    FILE* fp2 = fopen((path + ".student").c_str(), "w");
    if (!fp2) return -1;
    fprintf(fp2, "%d %d\n", students.size(), countstudent);
    for (map<Long, Student>::iterator it = students.begin(); it != students.end(); it++) {
        Student student = it->second;
        fprintf(fp2, "%lld %d %s\n", student.getId(), student.getNumber(),
            student.getName().c_str());
        count++;
    } fclose(fp2);
    // Save student information
    return count;
} // Save to database

int Database::addbook(int number, string name, string publisher, string writer) {
    this->countbook++;
    Book book = Book(this->countbook, number, name, publisher, writer);
    for (auto inbook_pair : this->books) {
        Book inbook = inbook_pair.second;
        if (inbook.equals(book)) { inbook.add(number); return inbook.getId(); }
    } // Check if existed
    this->books[this->countbook] = book;
    return book.getId();
} // add book
void Database::delbook(Book book) {
    this->books.erase(book.getId());
} // del book

Long Database::addstudent(Long id, string name) {
    for (auto student_pair : this->students) {
        Student student = student_pair.second;
        if (student.getId() == id) { return id; }
    } // Check if existed
    this->countstudent++;
    Student student = Student(id, name);
    this->students[id] = student;
    return id;
} // add student 
void Database::delstudent(Student student) {
    this->countstudent--;
    this->students.erase(student.getId());
} // del student

string Database::toString() {
    string str = "";
    for (auto student_pair : this->students) {
        Student student = student_pair.second;
        str += student.toString();
        str += "\n";
    } // print student
    for (auto book_pair : this->books) {
        Book book = book_pair.second;
        str += book.toString();
        str += "\n";
    } // print book
    return str;
} // get information

map<int, Book> Database::getBooks() { return books; }
map<Long, Student> Database::getStudents() { return students; }
int Database::getCountbook() { return countbook; }
int Database::getCountstudent() { return countstudent; }
// Get basic value

list<Book> Database::search_book(string str) {
    list<Book> book_list;
    for (auto book_pair : this->books)
        book_list.push_back(book_pair.second);
    auto book_compare = [=](Book book1, Book book2) {
        double a = book1.Similarity(str);
        double b = book2.Similarity(str);
        return b < a;
    }; // lambda function
    book_list.sort(book_compare);
    // sort by similarity
    return book_list;
} // Search book by name/writer/publisher
Book Database::search_book(int id) {
    for (auto book_pair : this->books) {
        Book book = book_pair.second;
        if (book.getId() == id) return book;
    } return Book(-1, -1, "None", "None", "None");
} // Search book by ID

Student Database::search_student(string str) {
    for (auto student_pair : this->students) {
        Student student = student_pair.second;
        if (student.getName() == str) return student;
    } return Student(0, "None");
} // Search student by name
Student Database::search_student(Long id) {
    for (auto student_pair : this->students) {
        Student student = student_pair.second;
        if (student.getId() == id) return student;
    } return Student(0, "None");
} // Search student by ID


