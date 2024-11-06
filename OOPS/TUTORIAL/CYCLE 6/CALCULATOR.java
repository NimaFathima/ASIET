import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleCalculator {
    
    private JFrame frame;
    private JTextField textField;
    private String operator;
    private double num1, num2, result;
    
    public SimpleCalculator() {
        frame = new JFrame("Simple Calculator");
        frame.setSize(300, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        textField = new JTextField();
        textField.setEditable(false);
        textField.setHorizontalAlignment(JTextField.RIGHT);
        
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(5, 4, 10, 10));  // 5 rows, 4 columns grid layout
        
        String[] buttons = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "C", "0", "=", "+",
            "%", "", "", ""
        };
        
        // Add buttons to the panel
        for (String text : buttons) {
            JButton button = new JButton(text);
            button.addActionListener(new ButtonClickListener());
            panel.add(button);
        }
        
        frame.setLayout(new BorderLayout());
        frame.add(textField, BorderLayout.NORTH);
        frame.add(panel, BorderLayout.CENTER);
        
        frame.setVisible(true);
    }
    
    // Inner class to handle button clicks
    private class ButtonClickListener implements ActionListener {
        
        @Override
        public void actionPerformed(ActionEvent e) {
            JButton source = (JButton) e.getSource();
            String command = source.getText();
            
            if (command.matches("[0-9]")) {  // If a number button is pressed
                textField.setText(textField.getText() + command);
            } 
            else if (command.equals("C")) {  // Clear button
                textField.setText("");
                num1 = num2 = result = 0;
                operator = null;
            } 
            else if (command.equals("=")) {  // Equals button
                num2 = Double.parseDouble(textField.getText());
                switch (operator) {
                    case "+":
                        result = num1 + num2;
                        break;
                    case "-":
                        result = num1 - num2;
                        break;
                    case "*":
                        result = num1 * num2;
                        break;
                    case "/":
                        if (num2 != 0) {
                            result = num1 / num2;
                        } else {
                            textField.setText("Error");
                            return;
                        }
                        break;
                    case "%":
                        result = num1 % num2;
                        break;
                }
                textField.setText(String.valueOf(result));
                num1 = result;
            } 
            else {  // If an operator is pressed
                if (!textField.getText().isEmpty()) {
                    num1 = Double.parseDouble(textField.getText());
                    operator = command;
                    textField.setText("");
                }
            }
        }
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new SimpleCalculator());
    }
}

/* OUTPUT
-----------------------------------
|  TextField (Result Display)    |
-----------------------------------
|  7   |  8   |  9   |  /       |
-----------------------------------
|  4   |  5   |  6   |  *       |
-----------------------------------
|  1   |  2   |  3   |  -       |
-----------------------------------
|  C   |  0   |  =   |  +       |
-----------------------------------
|  %   |      |      |          |
-----------------------------------
*/
