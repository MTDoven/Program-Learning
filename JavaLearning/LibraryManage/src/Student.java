import java.io.Serial;
import java.io.Serializable;
import java.util.ArrayList;


public class Student implements Serializable{

    @Serial private static final long serialVersionUID = 1026L;
    private final long id;
    private final String name;
    private int number=3;
    private final ArrayList<Log> log = new ArrayList<>();

    public Student(long id, String name) {
        this.id = id;
        this.name = name;
    } // Construct function

    @Override
    public boolean equals(Object stu) {
        if (stu instanceof Student) {
            return ((Student) stu).getId()==this.id;
        } else return false;
    } // Compare

    @Override
    public String toString() {
        return "ID:"+this.id+"  Name:"+this.name;
    } // get information

    public boolean is_borrowable(){ return this.number!=0; }
    public void borrow(Log log){
        this.number--;
        this.log.add(log);
    } // borrow
    public void restore(Log log){
        this.number++;
        this.log.add(log);
    } // restore

    public long getId(){ return this.id; }
    public String getName(){ return this.name; }
    public int getNumber(){ return this.number; }
    public ArrayList<Log> getLog(){ return this.log; }

}

