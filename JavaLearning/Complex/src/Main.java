

public class Main {
    public static void main(String[] args) {
        try {
            Complex test = new Complex("3+4j");
        } catch (IllegalComplexNumberException e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Finished!");
        }
    }
}
