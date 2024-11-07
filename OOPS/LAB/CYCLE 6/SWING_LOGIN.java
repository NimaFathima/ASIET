import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class test implements ActionListener{
	JLabel l1,l2,l3;
	JTextField t1,t2;
	JButton b1,b2;
	test(){
		JFrame f = new JFrame("LOGIN");
		l1 = new JLabel("USER ID : ");
		l2 = new JLabel("PASSWORD :");
		t1 = new JTextField(20);
		t2 = new JTextField(20);
		b1 = new JButton("SUBMIT");
		b2 = new JButton("CLEAR");
		l3 = new JLabel("");
		JPanel p = new JPanel(new GridLayout(4,2));
		p.add(l1);
		p.add(t1);
		p.add(l2);
		p.add(t2);
		p.add(b1);
		p.add(b2);
		p.add(l3);
		b1.addActionListener(this);
		b2.addActionListener(this);
		f.add(p);
		f.setSize(300,300);
		f.show();
	}
	public void actionPerformed(ActionEvent e){
		String s = e.getActionCommand();
		if(s.equals("SUBMIT")){
			if(t1.getText().equals("abcd@gmail.com") && t2.getText().equals("1234")){
				l3.setText("WELCOME  " + t1.getText());
			}
			else{
				l3.setText("INCORRECT ID, PASSWORD -TRY AGAIN");
			}
		}
		if(s.equals("CLEAR")){
			t1.setText("");
			t2.setText("");
		}
	}

	public static void main (String args[]){
		test t = new test();
	}
}			
