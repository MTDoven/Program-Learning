import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException {
        int mode = ChooseMode(args);
        switch (mode){
            case 1 -> {
                Counter counter = new Counter();
                BufferedReader bufferin = new BufferedReader(new FileReader(args[0]));
                bufferin.mark((int)(new File(args[0])).length()+1);
                int paragraphcount = counter.countParagraph(bufferin); bufferin.reset();
                int wordcount = counter.countWord(bufferin); bufferin.reset();
                HashMap<Character,Integer> lettercount = counter.countLetters(bufferin);
                print("Paragraph: "+paragraphcount);
                print("Words: "+wordcount);
                System.out.print("Letter: ");
                print_9items(lettercount);
                bufferin.close();
            }
            case 2 -> {
                Matcher matcher = new Matcher();
                File file = new File(args[0]);
                ArrayList<File> files = matcher.findfiles(file);
                for (File this_file: files){
                    BufferedReader bufferin = new BufferedReader(new FileReader(this_file));
                    if(matcher.contain(args[1], bufferin)) print(this_file);
                    bufferin.close();
                } // check and output
            }
            case 3 -> {
                Copyer copyer = new Copyer();
                File src = new File(args[0]); File dst = new File(args[1]);
                if (!copyer.copyable(src, dst).equals("Copyable")){
                    print("Fail to copy. Reason: "+copyer.copyable(src, dst));
                    return;
                } // cannot copy
                copyer.copy(args[0],args[1]);
                print("Copy succeed.");
            }
            default -> throw new IllegalStateException("Unexpected value: " + mode);
        }
    }

    private static int ChooseMode(String[] args){
        if (args.length==2) {
            File file = new File(args[0]);
            if (file.isDirectory()) return 2;
            else if (file.isFile()) return 3;
            else throw new IllegalArgumentException("Unrecognised File type "+file);
        } // length 2
        else if (args.length==1) {
            File file = new File(args[0]);
            if (!file.isFile() || !file.canRead())
                throw new IllegalArgumentException("Not a readable file "+file);
            return 1;
        } else throw new IllegalArgumentException("Expect 1 or 2 arguments, given "+args.length);
    }
    private static void print(Object obj){
        System.out.println(obj);
    }
    private static void print_9items(HashMap<Character,Integer> map){
        String str = map.toString();
        str = str.replace("=",":");
        str = str.replace(",","");
        str = str.substring(1,str.length()-1);
        String[] strlist = str.split(" ");
        try { // Circle to output
            for (int i = 0; i < 9; i++) { System.out.print(strlist[i] + " "); }
            System.out.println(); System.out.print("\t");
            for (int i = 9; i < 18; i++) { System.out.print(strlist[i] + " "); }
            System.out.println(); System.out.print("\t");
            for (int i = 18; i < 27; i++) { System.out.print(strlist[i] + " "); }
            System.out.println();
        } catch (IndexOutOfBoundsException ignored) {}
    }
}

