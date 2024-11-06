import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class FactorialApplet extends Applet {

    TextField inputField;
    Button calculateButton;
    Label resultLabel;

    public void init() {
        setLayout(new FlowLayout());

        inputField = new TextField(20);
        add(new Label("Enter a number: "));
        add(inputField);

        calculateButton = new Button("Calculate Factorial");
        add(calculateButton);

        resultLabel = new Label("Factorial: ");
        add(resultLabel);

        calculateButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    int num = Integer.parseInt(inputField.getText());
                    long factorial = calculateFactorial(num);
                    resultLabel.setText("Factorial: " + factorial);
                } catch (NumberFormatException ex) {
                    resultLabel.setText("Please enter a valid number.");
                }
            }
        });
    }

    private long calculateFactorial(int num) {
        long factorial = 1;

        for (int i = 1; i <= num; i++) {
            factorial *= i;
        }

        return factorial;
    }
}

/*HTML Code to Run the Applet
<!DOCTYPE html>
<html>
    <head>
        <title>Factorial Applet</title>
    </head>
    <body>
        <h1>Java Applet to Calculate Factorial</h1>
        <applet code="FactorialApplet.class" width="300" height="200">
        </applet>
    </body>
</html> */

/* output:
Enter a number: 5
Factorial: 120
*/
