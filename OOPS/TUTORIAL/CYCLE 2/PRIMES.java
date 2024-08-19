//program to print primes until
import java.util.*;
class primesuntil 
{	public static void main(String args[])
  	{ 
	  int i,j,c=0;
	  Scanner s= new Scanner(System.in);
    	  System.out.print("ENTER THE NUMBER: ");
	  int n= s.nextInt();
	  for(i=1;i<=n;i++)
	  {	for(j=1;j<=i;j++)
		{      if(i%j==0)
		           c++;
		}
		if(c==1)
		   System.out.println(i);
	  }
	  s.close();		   

        }
}
