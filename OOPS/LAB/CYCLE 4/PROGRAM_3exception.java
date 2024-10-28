//NIMA FATHIMA - 46
public class ExceptionHandling {
    public static void divide(int a, int b) throws ArithmeticException {
        if (b == 0) {
            throw new ArithmeticException("CANNOT DIVIDE BY ZERO");
        } else {
            int result = a / b;
            System.out.println("RESULT : " + result);
        }
    }

    public static void main(String[] args) {
        try {
            divide(10, 0);
        } 
        catch (ArithmeticException e) {
            System.out.println("EXCEPTION CAUGHT");
        } 
        finally {
            System.out.println("FINALLY BLOCK EXECUTED");
        }
    }
}

//OUTPUT
//EXCEPTION CAUGHT
//FINALLY BLOCK EXECUTED

