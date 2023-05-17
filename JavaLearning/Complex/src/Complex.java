
public final class Complex extends Number implements Comparable<Complex>{
    // Construct
    private double real=0;
    private double imag=0;
    public Complex(double real, double imag){
        this.real = real;
        this.imag = imag;
    }

    // override
    @Override
    public int hashCode() {
        double temp = this.real*31 + this.imag;
        return Double.hashCode(temp);
    }
    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Complex) return equals((Complex)obj);
        else return Complex.equals(this,(Number)obj);
    }
    @Override
    public String toString() {
        String str;
        if (this.imag<0) str = String.format("%.2f", this.real)+String.format("%.2f", this.imag)+"i";
        else str = String.format("%.2f", this.real)+"+"+String.format("%.2f", this.imag)+"i";
        return str;
    }
    public static Complex valueOf(String str) {
        // Verify input
        if (str == null) { throw new NullPointerException("Input string is null"); }
        str = str.trim(); // Remove leading and trailing white spaces
        if (str.isEmpty()) { throw new IllegalArgumentException("Input string is empty"); }
        if (!str.matches("-?\\d+(\\.\\d+)?([+-]\\d+(\\.\\d+)?i)?")) {
            throw new IllegalArgumentException("Invalid input string: " + str); }
        // Remove all white spaces and split string by "+" or "-"
        String[] parts = str.replaceAll("\\s", "").split("(?=[+-])");
        double real = 0;
        double imag = 0;
        for (String part : parts) {
            if (part.endsWith("i")) {
                // imaginary part
                part = part.substring(0, part.length() - 1); // remove "i" suffix
                if (part.equals("+") || part.equals("-")) { part += "1"; }
                imag += Double.parseDouble(part);
            } else { // real part
                real += Double.parseDouble(part); }
        }
        return new Complex(real, imag);
    }

    // Force conversion
    public int intValue() throws NumberFormatException{
        if(!double_equal(imag,0D)) throw new NumberFormatException("Make sure the imaginary part is 0.");
        return (int)(this.real+0.5D);
    }
    public long longValue() throws NumberFormatException{
        if(!double_equal(imag,0D)) throw new NumberFormatException("Make sure the imaginary part is 0.");
        return Math.round(this.real);
    }
    public float floatValue() throws NumberFormatException{
        if(!double_equal(imag,0D)) throw new NumberFormatException("Make sure the imaginary part is 0.");
        return (float)this.real;
    }
    public double doubleValue() throws NumberFormatException{
        if(!double_equal(imag,0D)) throw new NumberFormatException("Make sure the imaginary part is 0.");
        return this.real;
    }
    public byte byteValue() throws NumberFormatException{
        if(!double_equal(imag,0D)) throw new NumberFormatException("Make sure the imaginary part is 0.");
        return (byte)(this.real+0.5D);
    }
    public short shortValue() throws NumberFormatException{
        if(!double_equal(imag,0D)) throw new NumberFormatException("Make sure the imaginary part is 0.");
        return (short)(this.real+0.5D);
    }

    // add
    private static Complex complexAddcomplex(Complex _complex1, Complex _complex2){
        return new Complex(_complex1.real+ _complex2.real, _complex1.imag+ _complex2.imag);
    }
    public static Complex add(Number x1, Number x2){
        if(x1 instanceof Complex && x2 instanceof Complex){
            return Complex.complexAddcomplex(((Complex)x1),((Complex)x2));
        } else if(x1 instanceof Complex) {
            return Complex.complexAddcomplex((Complex)x1,new Complex(x2.doubleValue(),0D));
        } else if(x2 instanceof Complex) {
            return Complex.complexAddcomplex(new Complex(x1.doubleValue(),0D),(Complex)x2);
        } else return new Complex(x1.doubleValue()+x2.doubleValue() ,0D);
    }
    // sub
    private static Complex complexSubcomplex(Complex _complex1, Complex _complex2){
        return new Complex(_complex1.real- _complex2.real, _complex1.imag- _complex2.imag);
    }
    public static Complex sub(Number x1, Number x2){
        if(x1 instanceof Complex && x2 instanceof Complex){
            return Complex.complexSubcomplex(((Complex)x1),((Complex)x2));
        } else if(x1 instanceof Complex) {
            return Complex.complexSubcomplex((Complex)x1,new Complex(x2.doubleValue(),0D));
        } else if(x2 instanceof Complex) {
            return Complex.complexSubcomplex(new Complex(x1.doubleValue(),0D),(Complex)x2);
        } else return new Complex(x1.doubleValue()-x2.doubleValue() ,0D);
    }
    // multiply
    private static Complex complexMultiplycomplex(Complex _complex1, Complex _complex2){
        double temp_real = _complex1.real*_complex2.real-_complex1.imag*_complex2.imag;
        double temp_imag = _complex1.real*_complex2.imag+_complex1.imag*_complex2.real;
        return new Complex(temp_real,temp_imag);
    }
    public static Complex multiply(Number x1, Number x2){
        if(x1 instanceof Complex && x2 instanceof Complex){
            return Complex.complexMultiplycomplex(((Complex)x1),((Complex)x2));
        } else if(x1 instanceof Complex) {
            return Complex.complexMultiplycomplex((Complex)x1,new Complex(x2.doubleValue(),0D));
        } else if(x2 instanceof Complex) {
            return Complex.complexMultiplycomplex(new Complex(x1.doubleValue(),0D),(Complex)x2);
        } else return new Complex(x1.doubleValue()*x2.doubleValue() ,0D);
    }
    // divide
    private static Complex complexDividecomplex(Complex _complex1, Complex _complex2){
        Complex temp = Complex.multiply(_complex1, _complex2.getConjugate());
        double division = (_complex2.real*_complex2.real + _complex2.imag*_complex2.imag);
        temp.imag /= division; temp.real /= division;
        return temp;
    }
    public static Complex divide(Number x1, Number x2){
        if(x1 instanceof Complex && x2 instanceof Complex){
            return Complex.complexDividecomplex(((Complex)x1),((Complex)x2));
        } else if(x1 instanceof Complex) {
            return Complex.complexDividecomplex((Complex)x1,new Complex(x2.doubleValue(),0D));
        } else if(x2 instanceof Complex) {
            return Complex.complexDividecomplex(new Complex(x1.doubleValue(),0D),(Complex)x2);
        } else return new Complex(x1.doubleValue()/x2.doubleValue() ,0D);
    }
    // compare
    private static boolean complexEqualscomplex(Complex _complex1, Complex _complex2){
        return (double_equal(_complex1.real, _complex2.real) && double_equal(_complex1.imag, _complex2.imag));
    }
    private boolean equals(Number _x) {
        if(_x instanceof Complex) return Complex.complexEqualscomplex(this,(Complex)_x);
        else return Complex.complexEqualscomplex(this,new Complex(_x.doubleValue(),0D));
    }
    public static boolean equals(Number x1, Number x2){
        if(x1 instanceof Complex && x2 instanceof Complex){
            return Complex.complexEqualscomplex(((Complex)x1),((Complex)x2));
        } else if(x1 instanceof Complex) {
            return Complex.complexEqualscomplex((Complex)x1,new Complex(x2.doubleValue(),0D));
        } else if(x2 instanceof Complex) {
            return Complex.complexEqualscomplex(new Complex(x1.doubleValue(),0D),(Complex)x2);
        } else return (x1.doubleValue()==x2.doubleValue());
    }

    // Get
    public Complex getConjugate(){
        return new Complex(this.real, -this.imag);
    }
    public double getModulus(){
        return this.real*this.real + this.imag*this.imag;
    }
    public double getTheta() {
        return Math.atan(this.imag/this.real);
    }
    public double getReal() {
        return real;
    }
    public double getImag() {
        return imag;
    }

    // Other tools
    private static boolean double_equal(double x,double y){
        double x_y = x-y;
        return (x_y>-0.00000001 && x_y<0.00000001);
    }
    public Complex copy(){
        return new Complex(this.real, this.imag);
    }
    public void show(String ... end){
        if(end.length==0) {
            System.out.println(this);
        } else {
            System.out.print(this);
            for(String i:end) System.out.print(i);
        }
    }

    @Override
    public int compareTo(Complex o) {
        return Double.compare(this.getModulus(), o.getModulus());
    }
}
