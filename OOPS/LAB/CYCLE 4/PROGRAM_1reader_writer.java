//NIMA FATHIMA - 46
import java.io.*;
public class FileHandling {
    public static void main(String[] args) {
        String file = "example.txt";
        String content = "Hello World";

        try {
            FileWriter writer = new FileWriter(file);
            writer.write(content);
            writer.close();
            System.out.println("CONTENT WRITTEN TO THE FILE");
            
            FileReader reader = new FileReader(file);
            int character;
            System.out.println("READING CONTENT FROM THE FILE : ");
            while ((character = reader.read()) != -1) {
                System.out.print((char) character);
            }
            reader.close();
        } 
        catch (IOException e) {
            System.out.println("An error occurred ");
        }
    }
}

//OUTPUT
//CONTENT WRITTEN TO THE FILE
//READING CONTENT FROM THE FILE : 
//Hello World

