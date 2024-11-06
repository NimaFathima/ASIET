// File: mypackage/Greetings.java
package mypackage;

public class Greetings {
    public void greet() {
        System.out.println("Hello from the user-defined package!");
    }
}

// File: Main.java
import mypackage.Greetings;

public class Main {
    public static void main(String[] args) {
        // Create an instance of the Greetings class from the mypackage package
        Greetings greetings = new Greetings();
        
        // Call the greet method
        greetings.greet();
    }
}
