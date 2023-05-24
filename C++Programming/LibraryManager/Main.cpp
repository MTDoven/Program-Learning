# include <iostream>
# include <ctime>
# include "Database.h"
# pragma warning(disable:4996)

/* һЩ�����ñ�̸������ļ򵥺��� */
void print(string arg) { cout << arg << endl; }
void print_no_endl(string arg) { cout << arg; }
void pause() { getchar(); getchar(); }


int main(int argc, char* argv[]) {

/* �������ж������ݲ��Ҵ�ָ���ļ��������� */
    string args(argv[1]);
    Database database = Database(args);
    print("\033cͼ��ݹ���ϵͳ [�汾 0.1]\n(c) MTDoven. All right reserved.\n");
    print("������������������������ͼ��ݹ���ϵͳ����������������������������");
    print("���ݼ�����:" + args + ".xxx"); print("����������ͼ�����Ա��Ϣ��");
    print_no_endl(database.toString()); print("���ݼ�����ɣ����س�������...");
    getchar();
    int operation = -1;


main:
    while (true) {

/* ��ҳ�����ѡ����ֹ��� */
        print("\033c\n������������������������ͼ��ݹ���ϵͳ������������������������");
        print("0.�������ݲ��˳�����"); print("1.����Ա ���/ɾ�� �鼮/��Ա");
        print("2.ѧ�� ����/����"); print("3.��ѯѧ���������"); print("4.��ѯ�鼮�������");
        print("5.�鼮ģ������"); print("6.��ȡ�������");  print_no_endl("����������:");
        cin >> operation;
        switch (operation) {
        case 0: { goto exit; break; }
    /* ����Ա����ҳ�� */
        case 1: { 
            print("\033c\n����������������������������Ա���ܽ��桪����������������������");
            print("0.������һ������Ŀ¼"); print("1.����鼮"); print("2.ɾ���鼮");
            print("3.�����Ա"); print("4.ɾ����Ա"); print_no_endl("����������:");
            cin >> operation;
            switch (operation) {
            case 0: { goto main; break; }
            case 1: {
                print_no_endl("�����鼮���ƣ�");
                string name; cin >> name;
                print_no_endl("��������磺");
                string publisher; cin >> publisher;
                print_no_endl("�������ߣ�");
                string writer; cin >> writer;
                print_no_endl("����������");
                int number; cin >> number;
                int id = database.addbook(number, name, publisher, writer);
                Book book = database.search_book(id);
                print(book.toString());
                print("�����鼮����ӵ�ͼ��ݹ���ϵͳ��");
                print("\n������ɣ������������������...");
                pause();
                break;
            }
            case 2: {
                print_no_endl("�����鼮ID:");
                int id; cin >> id;
                Book book = database.search_book(id);
                if (book.getId() == -1) {
                    print("���鼮��Ų����ڣ���ȷ���鼮���");
                    print("\n������ɣ������������������...");
                    pause();
                }
                else {
                    print_no_endl(book.toString()); print(" ��ɾ��");
                    database.delbook(book);
                    print("\n������ɣ������������������...");
                    pause();
                }
                break;  }
            case 3: {
                print_no_endl("����ѧ�ţ�");
                Long id; cin >> id;
                print_no_endl("����������");
                string name; cin >> name;
                id = database.addstudent(id, name);
                Student student = database.search_student(id);
                print(student.toString());
                print("������Ա����ӵ�ͼ��ݹ���ϵͳ��");
                print("\n������ɣ������������������...");
                pause();
                break; }
            case 4: {
                print_no_endl("����ѧ��:");
                Long id; cin >> id;
                Student student = database.search_student(id);
                if (student.getId() == 0) {
                    print("����Ա�����ڣ���ȷ����Ա���");
                    print("\n������ɣ������������������...");
                    pause();
                }
                else {
                    print_no_endl(student.toString()); print(" ��ɾ��");
                    database.delstudent(student);
                    print("\n������ɣ������������������...");
                    pause();
                }
                break; }
            }
            break; }
    /* ѧ������ҳ�� */
        case 2: {
            print("\033c\n������������������������ѧ���������桪����������������������");
            print("0.������һ������Ŀ¼"); print("1.����"); print("2.����");
            print_no_endl("����������:");
            cin >> operation;
            switch (operation) {
            case 0: { goto main; break; }
            case 1: {
                print_no_endl("����ѧ�ţ�");
                Long id_s; cin >> id_s;
                Student student = database.search_student(id_s);
                if (student.getId() == 0) {
                    print("����Ա�����ڣ���ȷ����Ա���");
                    print("\n������ɣ������������������...");
                    pause();
                    goto main;
                }
                if (!student.is_borrowable()) {
                    print("�Ѿ����������飬��黹���ٽ���");
                    print("\n������ɣ������������������...");
                    pause();
                    goto main;
                }
                print_no_endl("�����鼮���:");
                int id_b; cin >> id_b;
                Book book = database.search_book(id_b);
                if (book.getId() == -1) {
                    print("���鼮��Ų����ڣ���ȷ���鼮���");
                    print("\n������ɣ������������������...");
                    pause();
                    goto main;
                }
                if (!book.is_available()) {
                    print("��Ǹ�����鼮�ѽ��");
                    print("\n������ɣ������������������...");
                    pause();
                    goto main;
                }
                book.borrow();
                student.borrow();
                database.students[student.getId()] = student;
                database.books[book.getId()] = book;
                print(to_string(student.getNumber()));
                print(student.getName() + " borrowed " + book.getName());
                print("\n������ɣ������������������...");
                pause();
                break; }
            case 2: {
                print_no_endl("����ѧ�ţ�");
                Long id_s; cin >> id_s;
                Student student = database.search_student(id_s);
                if (student.getId() == 0) {
                    print("����Ա�����ڣ���ȷ����Ա���");
                    print("\n������ɣ������������������...");
                    pause();
                    goto main;
                }
                print_no_endl("�����鼮���:");
                int id_b; cin >> id_b;
                Book book = database.search_book(id_b);
                if (book.getId() == -1) {
                    print("���鼮��Ų����ڣ���ȷ���鼮���");
                    print("\n������ɣ������������������...");
                    pause();
                    goto main;
                }
                book.restore();
                student.restore();
                database.students[student.getId()] = student;
                database.books[book.getId()] = book;
                print(student.getName() + " returned " + book.getName());
                print("\n������ɣ������������������...");
                pause();
                break; }
            }
            break; }
    /* ��ѯҳ�� */
        case 3: {
            print("\033c\n��������������������������ѯ���桪����������������������");
            print_no_endl("������ѧ�ţ�");
            Long id; cin >> id;
            Student student = database.search_student(id);
            if (student.getId() == 0) {
                print("����Ա�����ڣ���ȷ����Ա���");
                print("\n������ɣ������������������...");
                pause();
                goto main;
            }
            print(student.getName() + "���ɽ���" + to_string(student.getNumber()) + "��");
            print("\n������ɣ������������������...");
            pause();
            break; }
        case 4: {
            print("\033c\n��������������������������ѯ���桪����������������������");
            print_no_endl("�������鼮��ţ�");
            int id; cin >> id;
            Book book = database.search_book(id);
            if (book.getId() == -1) {
                print("���鼮�����ڣ���ȷ���鼮���");
                print("\n������ɣ������������������...");
                pause();
                goto main;
            }
            print(book.toString());
            print("������ɣ������������������...");
            pause();
            break; }
        case 5: {
            print("\033c\n��������������������������ѯ���桪����������������������");
            print_no_endl("�������鼮���ƻ�����������������");
            string str; cin >> str;
            list<Book> books = database.search_book(str);
            for (auto book : books) { print(book.toString()); }
            print("\n������ɣ������������������...");
            pause();
            break; }
    /* ����ҳ�� */
        case 6: {
            print("\n��д����ô����˻�����������");
            print("Contact me if there's any problem");
            print("E-mail: MTDovent@gmail.com");
            print("QQ: 1317867671");
            print("\n������ɣ������������������...");
            pause();
            break; }
        default: {
            print("��������ȷ������");
            print("\n������ɣ������������������...");
            pause();
            break; }
        }
    }

/* ���沢�˳� */
exit:
    int count = database.save(args);
    print("\n���������ѱ��浽:" + args + ".xxx  ����" + to_string(count) + "��");
    print("������������������������ͼ��ݹ���ϵͳ�˳�������������������������");
}


