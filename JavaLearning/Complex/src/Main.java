import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        Complex test = Complex.valueOf("3+4i");
        do {
            System.out.print("Input A by real imag: ");
            Complex A = new Complex(s.nextDouble(), s.nextDouble());
            System.out.print("Input B by real imag: ");
            Complex B = new Complex(s.nextDouble(), s.nextDouble());
            System.out.println("Add: " + Complex.add(A, B));
            System.out.println("Sub: " + Complex.sub(A, B));
            System.out.println("Multiply: " + Complex.multiply(A, B));
            System.out.println("Divide: " + Complex.divide(A, B));
            System.out.print("A: " + A + "; ");
            System.out.println("B: " + B);
            System.out.print("Input 0 to exit or anything else to continue: ");
        } while (s.nextInt() != 0);
        System.out.println(test);
        s.close();
    }
}