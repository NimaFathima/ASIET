import java.io.*;
class JavaWriter{
	public static void main(String args[]){
		try{
			FileWriter f= new FileWriter("a.txt");
			String s ="cylcle 4 - Java";
			f.write(s);		
		}
		catch(Exception e){
			System.out.println("ERROR");
		}
		finally{
			f.close();
		}
	}
}

