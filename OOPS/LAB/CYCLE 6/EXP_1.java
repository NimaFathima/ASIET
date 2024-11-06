import java.util.*;

public class QuickSort {
    private static int partition(String[] array, int low, int high) {
        String pivot = array[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (array[j].compareTo(pivot) <= 0) {
                i++;
                String temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        String temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        return i + 1;
    }

    private static void quickSort(String[] array, int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);
            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of names:");
        int n = scanner.nextInt();
        scanner.nextLine();

        String[] names = new String[n];
        System.out.println("Enter the names:");
        for (int i = 0; i < n; i++) {
            names[i] = scanner.nextLine();
        }

        System.out.println("Original Array: ");
        for (String name : names) {
            System.out.print(name + " ");
        }
        System.out.println();

        quickSort(names, 0, names.length - 1);

        System.out.println("Sorted Array: ");
        for (String name : names) {
            System.out.print(name + " ");
        }
        System.out.println();
    }
}

/*
OUTPUT:
Enter the number of names:
3
Enter the names:
RAHUL
ASWATHY
AMMU
Original Array:
RAHUL ASWATHY AMMU
Sorted Array:
AMMU ASWATHY RAHUL
*/
