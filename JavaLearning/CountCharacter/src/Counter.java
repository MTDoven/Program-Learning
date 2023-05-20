import java.io.*;
import java.util.HashMap;

public class Counter {

    public int countParagraph(BufferedReader in) throws IOException {
        String str;
        int count = 0;
        while( (str=in.readLine()) !=null ){ if(!str.isEmpty()) count++; }
        return count;
    }

    public int countWord(BufferedReader in) throws IOException {
        String str;
        int count = 0;
        while( (str=in.readLine()) !=null ){
            str = str.replaceAll("[^0-9a-zA-Z ]","");
            str = str.replaceAll(" +"," ");
            str = str.trim();
            String[] strlist = str.split(" ");
            count += strlist.length;
        } // Circle for all lines
        return count;
    }

    public HashMap<Character,Integer> countLetters(BufferedReader in) throws IOException{
        String str;
        HashMap<Character,Integer> count = new HashMap<>();
        while( (str=in.readLine()) !=null ){
            str = str.replaceAll("[^a-zA-Z ]","");
            str = str.replaceAll(" +"," ");
            str = str.toLowerCase();
            for (Character character: str.toCharArray()){
                if (character==' ') continue;
                count.merge(character, 1, Integer::sum);
            } // get count map
        } // Circle for all lines
        return count;
    }

}
