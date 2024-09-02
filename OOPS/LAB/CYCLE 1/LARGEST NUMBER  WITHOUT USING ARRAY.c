//Program to find THE LARGEST ELEMENT  - Nima Fathima46
import java.util.Scanner;

class Palindrome
{
    public static void main(String[] args) 
    {
        String S = "", rev = "";
        Scanner s = new Scanner(System.in);
        System.out.println("ENTER THE STRING: ");
        S = s.nextLine();
        S=S.toLowerCase();
        int len = S.length();
        
        for (int i = len - 1; i >= 0; i--)
        {
            rev = rev + S.charAt(i);
        }
        
        if (rev.equals(S))
        {
            System.out.println("THE GIVEN STRING IS A PALINDROME.");
        } 
        else 
        {
            System.out.println("THE GIVEN STRING IS NOT A PALINDROME.");
        }
    }
}


