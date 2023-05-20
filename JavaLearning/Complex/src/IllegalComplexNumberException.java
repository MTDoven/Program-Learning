public class IllegalComplexNumberException extends IllegalArgumentException{
    public IllegalComplexNumberException() {
        super("\nInputed an illegal Complex, please use \"a+bi\" as input."); }
    public IllegalComplexNumberException(String message) {
        super("\n"+message+" is an illegal Complex, please use \"a+bi\" as input."); }
}
