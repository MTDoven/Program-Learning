import java.io.*;
import java.util.ArrayList;

public class Matcher {

    public ArrayList<File> findfiles(File file){
        ArrayList<File> result = new ArrayList<>();
        assert file.isDirectory();
        File[] files = file.listFiles();
        if (files == null) return result;
        for (File this_file: files) {
            if (this_file.isFile()) result.add(this_file);
            else if (this_file.isDirectory()) result.addAll(findfiles(this_file));
        } return result;
    }

    public boolean contain(String strcmp, BufferedReader in) throws IOException {
        StringBuilder strall = new StringBuilder();
        String str;
        while ((str = in.readLine()) != null) { strall.append(str); }
        return strall.toString().contains(strcmp);
    }
}
