import java.util.Scanner;

public class PrimeNumberCheck {

    public static boolean isPrime(int num) {
        if (num <= 1) {
            return false; // 0 and 1 are not prime
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false; // Divisible by i, not prime
            }
        }
        return true; // Prime number
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = scanner.nextInt();

        if (isPrime(num)) {
            System.out.println(num + " is a prime number.");
        } else {
            System.out.println(num + " is not a prime number.");
        }

        scanner.close();
    }
}

/*
Example Output:

Enter a number: 7
7 is a prime number.

Enter a number: 10
10 is not a prime number.
*/
