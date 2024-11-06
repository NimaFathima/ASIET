import java.util.*;

class NumberGenerator extends Thread {
    public void run() {
        Random random = new Random();
        while (true) {
            int num = random.nextInt(100);
            System.out.println("Generated Number: " + num);
            if (num % 2 == 0) {
                new Square(num).start();
            } else {
                new Cube(num).start();
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted: " + e.getMessage());
            }
        }
    }
}

class Square extends Thread {
    int number;

    Square(int number) {
        this.number = number;
    }

    public void run() {
        int square = number * number;
        System.out.println("Square of " + number + " is: " + square);
    }
}

class Cube extends Thread {
    int number;

    Cube(int number) {
        this.number = number;
    }

    public void run() {
        int cube = number * number * number;
        System.out.println("Cube of " + number + " is: " + cube);
    }
}

public class MultiThreadingDemo {
    public static void main(String[] args) {
        new NumberGenerator().start();
    }
}

/*
OUTPUT:
Square of 28 is: 784
Generated Number: 73
Cube of 73 is: 389017
Generated Number: 65
Cube of 65 is: 274625
Generated Number: 46
Square of 46 is: 2116
*/
