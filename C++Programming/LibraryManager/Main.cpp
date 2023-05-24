# include <iostream>
# include <ctime>
# include "Database.h"
# pragma warning(disable:4996)

/* 一些仅仅让编程更便利的简单函数 */
void print(string arg) { cout << arg << endl; }
void print_no_endl(string arg) { cout << arg; }
void pause() { getchar(); getchar(); }


int main(int argc, char* argv[]) {

/* 从命令行读入数据并且从指定文件加载数据 */
    string args(argv[1]);
    Database database = Database(args);
    print("\033c图书馆管理系统 [版本 0.1]\n(c) MTDoven. All right reserved.\n");
    print("————————————图书馆管理系统启动————————————");
    print("数据加载自:" + args + ".xxx"); print("以下是所有图书和人员信息：");
    print_no_endl(database.toString()); print("数据加载完成，按回车键继续...");
    getchar();
    int operation = -1;


main:
    while (true) {

/* 主页面可以选择各种功能 */
        print("\033c\n————————————图书馆管理系统————————————");
        print("0.保存数据并退出程序"); print("1.管理员 添加/删除 书籍/人员");
        print("2.学生 借书/还书"); print("3.查询学生借阅情况"); print("4.查询书籍借阅情况");
        print("5.书籍模糊查找"); print("6.获取更多帮助");  print_no_endl("请输入数字:");
        cin >> operation;
        switch (operation) {
        case 0: { goto exit; break; }
    /* 管理员操作页面 */
        case 1: { 
            print("\033c\n————————————管理员功能界面————————————");
            print("0.返回上一级功能目录"); print("1.添加书籍"); print("2.删除书籍");
            print("3.添加人员"); print("4.删除人员"); print_no_endl("请输入数字:");
            cin >> operation;
            switch (operation) {
            case 0: { goto main; break; }
            case 1: {
                print_no_endl("输入书籍名称：");
                string name; cin >> name;
                print_no_endl("输入出版社：");
                string publisher; cin >> publisher;
                print_no_endl("输入作者：");
                string writer; cin >> writer;
                print_no_endl("输入数量：");
                int number; cin >> number;
                int id = database.addbook(number, name, publisher, writer);
                Book book = database.search_book(id);
                print(book.toString());
                print("以上书籍已添加到图书馆管理系统中");
                print("\n操作完成，按任意键返回主界面...");
                pause();
                break;
            }
            case 2: {
                print_no_endl("输入书籍ID:");
                int id; cin >> id;
                Book book = database.search_book(id);
                if (book.getId() == -1) {
                    print("该书籍编号不存在，请确认书籍编号");
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                }
                else {
                    print_no_endl(book.toString()); print(" 已删除");
                    database.delbook(book);
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                }
                break;  }
            case 3: {
                print_no_endl("输入学号：");
                Long id; cin >> id;
                print_no_endl("输入姓名：");
                string name; cin >> name;
                id = database.addstudent(id, name);
                Student student = database.search_student(id);
                print(student.toString());
                print("以上人员已添加到图书馆管理系统中");
                print("\n操作完成，按任意键返回主界面...");
                pause();
                break; }
            case 4: {
                print_no_endl("输入学号:");
                Long id; cin >> id;
                Student student = database.search_student(id);
                if (student.getId() == 0) {
                    print("该人员不存在，请确认人员编号");
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                }
                else {
                    print_no_endl(student.toString()); print(" 已删除");
                    database.delstudent(student);
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                }
                break; }
            }
            break; }
    /* 学生操作页面 */
        case 2: {
            print("\033c\n————————————学生操作界面————————————");
            print("0.返回上一级功能目录"); print("1.借书"); print("2.还书");
            print_no_endl("请输入数字:");
            cin >> operation;
            switch (operation) {
            case 0: { goto main; break; }
            case 1: {
                print_no_endl("输入学号：");
                Long id_s; cin >> id_s;
                Student student = database.search_student(id_s);
                if (student.getId() == 0) {
                    print("该人员不存在，请确认人员编号");
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                    goto main;
                }
                if (!student.is_borrowable()) {
                    print("已经借满三本书，请归还后再借书");
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                    goto main;
                }
                print_no_endl("输入书籍编号:");
                int id_b; cin >> id_b;
                Book book = database.search_book(id_b);
                if (book.getId() == -1) {
                    print("该书籍编号不存在，请确认书籍编号");
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                    goto main;
                }
                if (!book.is_available()) {
                    print("抱歉，该书籍已借空");
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                    goto main;
                }
                book.borrow();
                student.borrow();
                database.students[student.getId()] = student;
                database.books[book.getId()] = book;
                print(to_string(student.getNumber()));
                print(student.getName() + " borrowed " + book.getName());
                print("\n操作完成，按任意键返回主界面...");
                pause();
                break; }
            case 2: {
                print_no_endl("输入学号：");
                Long id_s; cin >> id_s;
                Student student = database.search_student(id_s);
                if (student.getId() == 0) {
                    print("该人员不存在，请确认人员编号");
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                    goto main;
                }
                print_no_endl("输入书籍编号:");
                int id_b; cin >> id_b;
                Book book = database.search_book(id_b);
                if (book.getId() == -1) {
                    print("该书籍编号不存在，请确认书籍编号");
                    print("\n操作完成，按任意键返回主界面...");
                    pause();
                    goto main;
                }
                book.restore();
                student.restore();
                database.students[student.getId()] = student;
                database.books[book.getId()] = book;
                print(student.getName() + " returned " + book.getName());
                print("\n操作完成，按任意键返回主界面...");
                pause();
                break; }
            }
            break; }
    /* 查询页面 */
        case 3: {
            print("\033c\n————————————查询界面————————————");
            print_no_endl("请输入学号：");
            Long id; cin >> id;
            Student student = database.search_student(id);
            if (student.getId() == 0) {
                print("该人员不存在，请确认人员编号");
                print("\n操作完成，按任意键返回主界面...");
                pause();
                goto main;
            }
            print(student.getName() + "还可借阅" + to_string(student.getNumber()) + "本");
            print("\n操作完成，按任意键返回主界面...");
            pause();
            break; }
        case 4: {
            print("\033c\n————————————查询界面————————————");
            print_no_endl("请输入书籍编号：");
            int id; cin >> id;
            Book book = database.search_book(id);
            if (book.getId() == -1) {
                print("该书籍不存在，请确认书籍编号");
                print("\n操作完成，按任意键返回主界面...");
                pause();
                goto main;
            }
            print(book.toString());
            print("操作完成，按任意键返回主界面...");
            pause();
            break; }
        case 5: {
            print("\033c\n————————————查询界面————————————");
            print_no_endl("请输入书籍名称或出版社或作者姓名：");
            string str; cin >> str;
            list<Book> books = database.search_book(str);
            for (auto book : books) { print(book.toString()); }
            print("\n操作完成，按任意键返回主界面...");
            pause();
            break; }
    /* 帮助页面 */
        case 6: {
            print("\n都写的这么清楚了还来看帮助？");
            print("Contact me if there's any problem");
            print("E-mail: MTDovent@gmail.com");
            print("QQ: 1317867671");
            print("\n操作完成，按任意键返回主界面...");
            pause();
            break; }
        default: {
            print("请输入正确的数字");
            print("\n操作完成，按任意键返回主界面...");
            pause();
            break; }
        }
    }

/* 保存并退出 */
exit:
    int count = database.save(args);
    print("\n所有数据已保存到:" + args + ".xxx  共有" + to_string(count) + "条");
    print("————————————图书馆管理系统退出————————————");
}


