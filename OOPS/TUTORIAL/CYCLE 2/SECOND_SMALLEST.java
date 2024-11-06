import java.util.Scanner;

public class SecondSmallest {
    public static int findSecondSmallest(int[] arr) {
        int smallest = Integer.MAX_VALUE;
        int secondSmallest = Integer.MAX_VALUE;

        for (int num : arr) {
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else if (num < secondSmallest && num != smallest) {
                secondSmallest = num;
            }
        }

        return secondSmallest;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int secondSmallest = findSecondSmallest(arr);
        if (secondSmallest == Integer.MAX_VALUE) {
            System.out.println("There is no second smallest element.");
        } else {
            System.out.println("The second smallest element is: " + secondSmallest);
        }

        scanner.close();
    }
}

/*
Example Output:

Enter the number of elements in the array: 5
Enter the elements of the array:
12 5 8 20 3
The second smallest element is: 5
*/
