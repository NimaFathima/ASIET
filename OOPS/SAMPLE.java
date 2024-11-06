import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class test implements ActionListener{
	JLabel l;
	JTextField t;
	JButton b;
	
	test(){
		JFrame f = new JFrame("textfield");
		l= new JLabel ("nothing entered");
		t= new JTextField(16);
		b= new JButton("submit");
		
		JPanel p= new JPanel();
		
		p.add(l);
		p.add(t);
		p.add(b);
		
		b.addActionListener(this);
		f.add(p);
		f.setSize(300,300);
		f.show();	
	}
	
	//if the button is pressed
	
	public void actionPerformed(ActionEvent e)
	{
		String s = e.getActionCommand();
		if(s.equals("submit")){
			String a = t.getText();
			l.setText(a);
		
		}
	}
	
	public static void main (String args[])
	{
		test t = new test();
	
	}
}
