//Program to find THE LARGEST ELEMENT  - Nima Fathima46
import java.util.*;
class Largest
 {
    	public static void main(String args[])
         {
        	 Scanner s = new Scanner(System.in);
           int n,largest=0;
        	 System.out.println("ENTER THE NUMBER OF ELEMENTS: ");
        	 n = s.nextInt();
        	 System.out.println("ENTER THE ELEMENTS:");
        	 for (int i = 0; i < n; i++) 
        	 {
                int a = s.nextInt();
                if(a>largest)
                {
                    largest=a;
                }
        	 }
        	 System.out.println("THE LARGEST ELEMENT IS:"+largest);
       }
}






