import java.util.Scanner;

public class SumOfNNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements (N): ");
        int N = scanner.nextInt();
        
        int sum = 0;
        
        System.out.println("Enter " + N + " numbers:");
        for (int i = 1; i <= N; i++) {
            System.out.print("Enter number " + i + ": ");
            int num = scanner.nextInt();
            sum += num;
        }
        
        System.out.println("The sum of the " + N + " numbers is: " + sum);
        scanner.close();
    }
}

/*
Example Output:

Enter the number of elements (N): 5
Enter 5 numbers:
Enter number 1: 10
Enter number 2: 20
Enter number 3: 30
Enter number 4: 40
Enter number 5: 50
The sum of the 5 numbers is: 150
*/
