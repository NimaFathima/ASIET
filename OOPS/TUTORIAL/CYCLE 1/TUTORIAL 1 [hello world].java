//Write a Java program to find the sum of digits in an integer read from the keyboard.

import java.util.*;
class digitsum
{
  public static void main(String args[])
  { Scanner s= new Scanner(System.in);
    System.out.print("ENTER THE NUMBER: ");
    int n = s.nextInt();
    int sum=0;
    while(n>0)
    {	sum=sum+n%10;
	n=n/10;
    }  
    System.out.println("SUM OF THE DIGITS: "+sum);
    s.close();
  }
}

