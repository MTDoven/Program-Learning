import java.io.Serial;
import java.io.Serializable;
import java.util.*;


public class Book implements Serializable {

    @Serial private static final long serialVersionUID = 1025L;
    private final int id;
    private int number;
    private final String name;
    private final String publisher;
    private final ArrayList<String> writers = new ArrayList<>();
    private final ArrayList<Log> log = new ArrayList<>();

    public Book(int id, int number, String name, String publisher, String[] writers){
        this.id = id;
        this.number = number;
        this.name = name;
        this.publisher = publisher;
        this.writers.addAll(Arrays.asList(writers));
        Collections.sort(this.writers);
    } // Construct function

    @Override
    public boolean equals(Object book) {
        if(book instanceof Book){
            boolean a = ((Book) book).getName().equals(this.name);
            boolean b = ((Book) book).getPublisher().equals(this.publisher);
            boolean c = ((Book) book).writers.equals(this.writers);
            return a && b && c;
        } else return false;
    } // Compare

    @Override
    public String toString() {
        return "ID:"+this.id+"  Number:"+this.number+"  Name:"+this.name
                +"  Publisher:"+this.publisher+"  Writers:"+this.writers;
    } // get information

    public double Similarity(String str){
        double max = Levenshtein(str, this.name);
        double temp; // for writer save; cut calculate
        for(String writer: this.writers){
            temp = Levenshtein(str, writer);
            if (temp>max) { max=temp; }
        } // writer
        temp = Levenshtein(str, this.publisher);
        if (temp>max) { max=temp; }
        return max;
    } // get similarity

    public boolean is_available(){ return this.number!=0; }
    public void borrow(Log log){
        this.number--;
        this.log.add(log);
    } // borrow
    public void restore(Log log){
        this.number++;
        this.log.add(log);
    } // restore
    public void add(int number){
        this.number += number;
    } // add

    public int getId(){ return this.id; }
    public int getNumber(){ return this.number; }
    public String getName(){ return this.name; }
    public String getPublisher(){ return this.publisher; }
    public ArrayList<String> getWriters(){ return this.writers; }
    public ArrayList<Log> getLog(){ return this.log; }

    private double Levenshtein(String s1, String s2) {
        int s1_len = s1.length();
        int s2_len = s2.length();
        if (s1_len == 0) { return s2_len; }
        if (s2_len == 0) { return s1_len; }
        // avoid 0 length input
        double[][] distance = new double[s1_len+1][s2_len+1];
        for (int i=0; i<=s1_len; i++) { distance[i][0]=i; }
        for (int j=0; j<=s2_len; j++) { distance[0][j]=j; }
        for (int i=1; i<=s1_len; i++) {
            char s1_i = s1.charAt(i - 1);
            for (int j=1; j<=s2_len; j++) {
                char s2_j = s2.charAt(j-1);
                if (s1_i == s2_j) {
                    distance[i][j] = distance[i-1][j-1];
                } else { // same or not
                    double min = distance[i-1][j];
                    if (distance[i][j-1] < min) { min=distance[i][j-1]; }
                    if (distance[i-1][j-1] < min) { min = distance[i-1][j-1]; }
                    distance[i][j] = min + 1;
        }   }   } // circles
        return 1 - distance[s1_len][s2_len] / Math.max(s1.length(), s2.length());
    } // Levenshtein distance

}

