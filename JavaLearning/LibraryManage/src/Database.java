import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;


public class Database implements Serializable{

    @Serial private static final long serialVersionUID = 1024L;
    private HashMap<Integer,Book> books = new HashMap<>();
    private HashMap<Long,Student> students = new HashMap<>();
    private ArrayList<Log> log = new ArrayList<>();
    private int countbook=0;
    private int countstudent=0;

    public Database() { return; } // create a new database
    public Database(String path) throws IOException, ClassNotFoundException {
        File file = new File(path); if (!file.exists()) return;
        FileInputStream infile = new FileInputStream(file);
        ObjectInputStream instream = new ObjectInputStream(infile);
        Database database_old = (Database) instream.readObject();
        instream.close();
        infile.close();
        this.books = database_old.getBooks();
        this.students = database_old.getStudents();
        this.log = database_old.getLog();
        this.countbook = database_old.getCountbook();
        this.countstudent = database_old.getCountstudent();
    } // Construct function
    public void save(String path) throws IOException {
        File file = new File(path);
        FileOutputStream outfile = new FileOutputStream(file);
        ObjectOutputStream outstream = new ObjectOutputStream(outfile);
        outstream.writeObject(this);
        outstream.close();
        outfile.close();
    } // save

    public int addbook(int number, String name, String publisher, String[] writers){
        this.countbook++;
        Book book = new Book(this.countbook,number,name,publisher,writers);
        for(Book inbook: this.books.values()){
            if (inbook.equals(book)){ inbook.add(number); return inbook.getId();}
        } // if it has been in library
        this.books.put(this.countbook,book);
        return book.getId();
    } // Construct function
    public void delbook(Book book){
        this.books.remove(book.getId());
    } // Construct function
    public long addstudent(long id, String name){
        for(Student student: this.students.values()){
            if (student.getId()==id){ return id; }
        } // if it has been in library
        this.countstudent++;
        Student student = new Student(id,name);
        this.students.put(id, student);
        return id;
    } // Construct function
    public void delstudent(Student student){
        this.countstudent--;
        this.students.remove(student.getId());
    } // Construct function

    public ArrayList<Book> search_book(String str) {
        ArrayList<Book> book_list = new ArrayList<>(this.books.values());
        book_list.sort((book1, book2) -> {
            double a = book1.Similarity(str);
            double b = book2.Similarity(str);
            return Double.compare(b, a); } );
        return book_list;
    } // search_book by name
    public Book search_book(int id) {
        for(Book book: this.books.values()){
            if(book.getId()==id) return book;
        } return null;
    } // search_book by id
    public Student search_student(String str) {
        for(Student student: this.students.values()){
            if(student.getName().equals(str)) return student;
        } return null;
    } // search_student by name
    public Student search_student(long id) {
        for(Student student: this.students.values()){
            if(student.getId()==id) return student;
        } return null;
    } // search_student by id
    public ArrayList<Object> search_all(String str) {
        ArrayList<Object> _return = new ArrayList<>();
        try{ // input id
            long id = Long.parseLong(str);
            Student student = search_student(id);
            if (student == null) throw new NumberFormatException();
            _return.add(student);
            return _return;
        } catch (NumberFormatException e) {
            Student student = search_student(str);
            if (student != null) { _return.add(student); }
            else { // not student
                ArrayList<Book> books = search_book(str);
                _return.addAll(books);
            } // not student
            return _return;
        } // input book or student
    } // search anything

    public HashMap<Integer,Book> getBooks(){ return books; }
    public HashMap<Long,Student> getStudents(){ return students; }
    public ArrayList<Log> getLog(){ return this.log; }
    public int getCountbook() { return countbook; }
    public int getCountstudent() { return countstudent; }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for(Student student: this.students.values()){
            str.append(student.toString());
            str.append("\n");
        } // print student
        for(Book book: this.books.values()){
            str.append(book.toString());
            str.append("\n");
        } // print book
        return str.toString();
    } // get information
}


