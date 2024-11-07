import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Calculator implements ActionListener {
    JFrame frame;
    JLabel label1, label2, resultLabel;
    JTextField textField1, textField2;
    JButton addButton, subButton, mulButton, divButton, clrButton;
    double num1, num2, result;

    Calculator() {
        frame = new JFrame("Simple Calculator");

        label1 = new JLabel("Enter First Number:");
        label2 = new JLabel("Enter Second Number:");
        resultLabel = new JLabel("Result:");

        textField1 = new JTextField(15);
        textField2 = new JTextField(15);

        addButton = new JButton("+");
        subButton = new JButton("-");
        mulButton = new JButton("*");
        divButton = new JButton("/");
        clrButton = new JButton("Clear");

        addButton.addActionListener(this);
        subButton.addActionListener(this);
        mulButton.addActionListener(this);
        divButton.addActionListener(this);
        clrButton.addActionListener(this);

        frame.setLayout(new FlowLayout());

        frame.add(label1);
        frame.add(textField1);
        frame.add(label2);
        frame.add(textField2);
        frame.add(addButton);
        frame.add(subButton);
        frame.add(mulButton);
        frame.add(divButton);
        frame.add(clrButton);
        frame.add(resultLabel);

        frame.setSize(300, 300);
        frame.setVisible(true);
    }
    
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        try {
            num1 = Double.parseDouble(textField1.getText());
            num2 = Double.parseDouble(textField2.getText());
        } catch (NumberFormatException ex) {
            resultLabel.setText("Invalid Input. Please enter valid numbers.");
            return;
        }

        if (command.equals("+")) {
            result = num1 + num2;
            resultLabel.setText("Result: " + result);
        } else if (command.equals("-")) {
            result = num1 - num2;
            resultLabel.setText("Result: " + result);
        } else if (command.equals("*")) {
            result = num1 * num2;
            resultLabel.setText("Result: " + result);
        } else if (command.equals("/")) {
            if (num2 == 0) {
                resultLabel.setText("Error: Division by zero!");
            } else {
                result = num1 / num2;
                resultLabel.setText("Result: " + result);
            }
        } else if (command.equals("Clear")) {
            textField1.setText("");
            textField2.setText("");
            resultLabel.setText("Result:");
        }
    }

    public static void main(String[] args) {
        new Calculator();
    }
}

