import java.io.*;
import java.util.Objects;

public class Copyer {

    public String copyable(File src, File dst){
        if (Objects.equals(src.toString(), dst.toString())) return "Duplicate names";
        if (dst.exists()) return "Destination exists";
        if (!src.exists()) return "Source not exists";
        return "Copyable";
    }

    public void copy(String src, String dst) throws IOException {
        FileInputStream in = new FileInputStream(src);
        FileOutputStream out = new FileOutputStream(dst);
        int content;
        while( (content=in.read())!=-1 )
            out.write(content);
        in.close();
        out.close();
    }

}
