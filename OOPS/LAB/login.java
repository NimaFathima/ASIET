import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class test implements ActionListener{
	JLabel l1,l2;
	JTextField t1,t2;
	JButton b;
	
	final String USERNAME = "admin";
        final String PASSWORD = "123";
	
	test(){
		JFrame f = new JFrame("LOGIN");
		l1= new JLabel ("USER_NAME");
		t1= new JTextField(16);
		l2= new JLabel("PASSWORD");
		t2= new JTextField(16);
		b= new JButton("submit");
		
		JPanel p= new JPanel();
		
		p.add(l1);
		p.add(t1);
		p.add(l2);
		p.add(t2);
		p.add(b);
		
		b.addActionListener(this);
		f.add(p);
		f.setSize(300,300);
		f.setVisible(true);	
	}
	
	//if the button is pressed
	
	public void actionPerformed(ActionEvent e)
	{
		String s = e.getActionCommand();
		if(s.equals("submit")){
			l.setText(t.getText());
			t.setText(" ");
		
		}
	}
	
	public static void main (String args[])
	{
		test t = new test();
	
	}
}
    
    /
        JPanel p = new JPanel();
        p.setLayout(new GridLayout(4, 2, 10, 10)); // Setting a GridLayout
        
        p.add(lUser);
        p.add(tUser);
        p.add(lPass);
        p.add(tPass);
        p.add(new JLabel("")); // Empty space in the layout
        p.add(lMessage); // Message will be shown here
        p.add(new JLabel("")); // Empty space in the layout
        p.add(bSubmit);
        
        // ActionListener for the button
        bSubmit.addActionListener(this);
        
        // Adding the panel to the frame
        f.add(p);
        f.setSize(300, 200); // Adjusted size for better visibility
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Close the app when window is closed
        f.setVisible(true);
    }
    
    // Action performed when the button is pressed
    public void actionPerformed(ActionEvent e) {
        String enteredUsername = tUser.getText();
        String enteredPassword = new String(tPass.getPassword()); // Convert password to string
        
        // Validate username and password
        if (enteredUsername.equals(USERNAME) && enteredPassword.equals(PASSWORD)) {
            lMessage.setText("Login Successful");
            lMessage.setForeground(Color.GREEN); // Success message in green
        } else {
            lMessage.setText("Invalid Username or Password");
            lMessage.setForeground(Color.RED); // Error message in red
        }
        
        // Clear the text fields
        tUser.setText("");
        tPass.setText("");
    }
    
    public static void main(String args[]) {
        new Test(); // Create an instance of the Test class (i.e., start the app)
    }
}
