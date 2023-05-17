import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws IOException, ClassNotFoundException {

        final SimpleDateFormat timeformat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        Scanner input=new Scanner(System.in);
        Database database = new Database(args[0]);
        print("图书馆管理系统 [版本 0.1] (c) MTDoven.");
        print("————————————图书馆管理系统启动————————————");
        print("数据加载自:",args[0]); print("以下是所有图书和人员信息：");
        print_no_endl(database); print("数据加载完成，按任意键继续...");
        input.nextLine();
        int operation=6;
        // initialize

        main:while(true) {
            print("\033c————————————图书馆管理系统————————————");
            print("0.保存数据并退出程序"); print("1.管理员 添加/删除 书籍/人员");
            print("2.学生 借书/还书"); print("3.查询学生借阅情况"); print("4.查询书籍借阅情况");
            print("5.任意信息搜索"); print("6.获取更多帮助"); print_no_endl("请输入数字:");
            operation = input.nextInt(); input.nextLine();

            switch (operation) {
                case 0 -> {
                    database.save(args[0]);
                    print("所有数据已保存到:",args[0]);
                    print("————————————图书馆管理系统退出————————————");
                    break main;
                }
                case 1 -> {
                    print("\033c————————————管理员功能界面————————————");
                    print("0.返回上一级功能目录"); print("1.添加书籍"); print("2.删除书籍");
                    print("3.添加人员"); print("4.删除人员"); print_no_endl("请输入数字:");
                    operation = input.nextInt(); input.nextLine();
                    switch (operation){
                        case 0 -> { continue main; }
                        case 1 -> {
                            print_no_endl("输入书籍名称：");
                            String name = input.nextLine();
                            print_no_endl("输入出版社：");
                            String publisher = input.nextLine();
                            print_no_endl("输入作者(多作者用“/”分隔)：");
                            String[] writers = input.nextLine().split("/");
                            print_no_endl("输入数量：");
                            int number = input.nextInt(); input.nextLine();
                            int id = database.addbook(number,name,publisher,writers);
                            Book book = database.search_book(id);
                            print(book.toString());
                            print("以上书籍已添加到图书馆管理系统中");
                            print("操作完成，按任意键返回主界面...");
                            input.nextLine();
                        }
                        case 2 -> {
                            print_no_endl("输入书籍ID:");
                            int id = input.nextInt(); input.nextLine();
                            Book book = database.search_book(id);
                            if (book==null){
                                print("该书籍编号不存在，请确认书籍编号");
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                            } else {
                                print_no_endl(book); print(" 已删除");
                                database.delbook(book);
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                            }
                        }
                        case 3 -> {
                            print_no_endl("输入学号：");
                            long id = input.nextLong(); input.nextLine();
                            print_no_endl("输入姓名：");
                            String name = input.nextLine();
                            id = database.addstudent(id,name);
                            Student student = database.search_student(id);
                            print(student.toString());
                            print("以上人员已添加到图书馆管理系统中");
                            print("操作完成，按任意键返回主界面...");
                            input.nextLine();
                        }
                        case 4 -> {
                            print_no_endl("输入学号:");
                            long id = input.nextLong(); input.nextLine();
                            Student student = database.search_student(id);
                            if (student==null){
                                print("该人员不存在，请确认人员编号");
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                            } else {
                                print_no_endl(student); print(" 已删除");
                                database.delstudent(student);
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                            }
                        }
                    }
                }
                case 2 -> {
                    print("\033c————————————学生操作界面————————————");
                    print("0.返回上一级功能目录"); print("1.借书"); print("2.还书");
                    print_no_endl("请输入数字:");
                    operation = input.nextInt();  input.nextLine();
                    switch (operation) {
                        case 0 -> { continue main; }
                        case 1 -> {
                            print_no_endl("输入学号：");
                            long id_s = input.nextLong(); input.nextLine();
                            Student student = database.search_student(id_s);
                            if (student==null){
                                print("该人员不存在，请确认人员编号");
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                                continue main;}
                            if (!student.is_borrowable()){
                                print("已经借满三本书，请归还后再借书");
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                                continue main;}
                            print_no_endl("输入书籍编号:");
                            int id_b = input.nextInt(); input.nextLine();
                            Book book = database.search_book(id_b);
                            if (book==null){
                                print("该书籍编号不存在，请确认书籍编号");
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                                continue main;}
                            if (!book.is_available()){
                                print("抱歉，该书籍已借空");
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                                continue main;}
                            Log log = new Log(student,book,"borrow",timeformat.format(new Date()));
                            book.borrow(log);
                            student.borrow(log);
                            print(log);
                            print("操作完成，按任意键返回主界面...");
                            input.nextLine();
                        }
                        case 2 -> {
                            print_no_endl("输入学号：");
                            long id_s = input.nextLong(); input.nextLine();
                            Student student = database.search_student(id_s);
                            if (student==null){
                                print("该人员不存在，请确认人员编号");
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                                continue main;}
                            print_no_endl("输入书籍编号:");
                            int id_b = input.nextInt(); input.nextLine();
                            Book book = database.search_book(id_b);
                            if (book==null){
                                print("该书籍编号不存在，请确认书籍编号");
                                print("操作完成，按任意键返回主界面...");
                                input.nextLine();
                                continue main;}
                            for(Log log: student.getLog()){
                                if (log.getBookId()==book.getId()){
                                    if(log.getState().equals("borrow")) {
                                        Log log_return = new Log(student, book, "restore", timeformat.format(new Date()));
                                        student.restore(log_return);
                                        book.restore(log_return);
                                        print(log_return);
                                        print("操作完成，按任意键返回主界面...");
                                        input.nextLine();
                                        continue main;
                            } else break; } }
                            print("您未借出这本书");
                            print("操作完成，按任意键返回主界面...");
                            input.nextLine();
                        }
                    }
                }
                case 3 -> {
                    print("\033c————————————查询界面————————————");
                    print_no_endl("请输入学号：");
                    long id = input.nextLong(); input.nextLine();
                    Student student = database.search_student(id);
                    if (student==null){
                        print("该人员不存在，请确认人员编号");
                        print("操作完成，按任意键返回主界面...");
                        input.nextLine();
                        continue main;}
                    for(Log log: student.getLog()){ print(log); }
                    print("操作完成，按任意键返回主界面...");
                    input.nextLine();
                }
                case 4 -> {
                    print("\033c————————————查询界面————————————");
                    print_no_endl("请输入书籍编号：");
                    int id = input.nextInt(); input.nextLine();
                    Book book = database.search_book(id);
                    if (book==null){
                        print("该书籍不存在，请确认书籍编号");
                        print("操作完成，按任意键返回主界面...");
                        input.nextLine();
                        continue main;}
                    print(book);
                    for(Log log: book.getLog()) print(log);
                    print("操作完成，按任意键返回主界面...");
                    input.nextLine();
                }
                case 5 -> {
                    print("\033c————————————查询界面————————————");
                    print_no_endl("请输入书籍 名称/作者/出版社/姓名/学号：");
                    String str = input.nextLine();
                    ArrayList<Object> objs = database.search_all(str);
                    if (objs.size()==1){
                        print(objs.get(0));
                        if (objs.get(0) instanceof Student){
                            for(Log log:((Student) objs.get(0)).getLog()) print(log);}
                        else if (objs.get(0) instanceof Book){
                            for(Log log:((Book) objs.get(0)).getLog()) print(log);}
                        print("操作完成，按任意键返回主界面...");
                        input.nextLine();
                        continue main;
                    } // exact information input
                    for(int i=0; i<5; i++){ print(objs.get(i)); }
                    print("操作完成，按任意键返回主界面...");
                    input.nextLine();
                }
                case 6 -> {
                    print("都写的这么清楚了还来看帮助？");
                    print("Contact me if there's any problem");
                    print("E-mail: MTDovent@gmail.com");
                    print("QQ: 1317867671");
                    print("操作完成，按任意键返回主界面...");
                    input.nextLine();
                }
                default -> {
                    print("请输入正确的数字");
                    print("操作完成，按任意键返回主界面...");
                    input.nextLine();
                }
            }
        }
    }

    private static void print(Object... objs){
        for(Object obj: objs){ System.out.print(obj); }
        System.out.println();
    } // quick print
    private static void print_no_endl(Object... objs){
        for(Object obj: objs){ System.out.print(obj); }
    } // quick print
}