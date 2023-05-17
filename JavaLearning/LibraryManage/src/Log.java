import java.io.Serial;
import java.io.Serializable;

public class Log implements Serializable {

    @Serial private static final long serialVersionUID = 1027L;
    private final Student student;
    private final Book book;
    private final String state;
    private final String time;

    public Log(Student student, Book book, String state, String time){
        this.student = student;
        this.book = book;
        this.state = state;
        this.time = time;
    }

    public boolean isBorrow(){ return this.state.equals("borrow"); }
    public boolean isRestore(){ return this.state.equals("restore"); }
    public String getState(){ return this.state; }
    public int getBookId(){ return this.book.getId(); }
    public long getStudentId(){ return this.student.getId(); }

    @Override
    public String toString() {
        if (this.isBorrow()){ return student.getName()+" borrowed "+book.getName()+"(id:"+book.getId()+") on "+time;}
        else if (this.isRestore()){ return student.getName()+" returned "+book.getName()+"(id:"+book.getId()+") on "+time;}
        else { return student.getName()+" "+state+" "+book.getName()+" on "+time;}
    } // get information

}
