class Counter {
    private int count = 0;

    // Synchronized method to increment the counter
    public synchronized void increment() {
        count++;
    }

    // Method to get the current value of the counter
    public int getCount() {
        return count;
    }
}

class CounterThread extends Thread {
    private Counter counter;

    public CounterThread(Counter counter) {
        this.counter = counter;
    }

    public void run() {
        for (int i = 0; i < 1000; i++) {
            counter.increment();
        }
    }
}

public class ThreadSynchronizationDemo {
    public static void main(String[] args) {
        Counter counter = new Counter();

        // Creating two threads that share the same counter object
        CounterThread thread1 = new CounterThread(counter);
        CounterThread thread2 = new CounterThread(counter);

        // Starting both threads
        thread1.start();
        thread2.start();

        try {
            // Waiting for both threads to finish
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted: " + e.getMessage());
        }

        // Printing the final value of the counter
        System.out.println("Final Counter Value: " + counter.getCount());
    }
}
