//NIMA FATHIMA - 46
import java.io.*;
public class FileReadWriteExample {
    public static void main(String[] args) {
        String inputFile = "input.txt";  
        String outputFile = "output.txt"; 
        FileReader reader = null;
        FileWriter writer = null;

        try {
            reader = new FileReader(inputFile);
            writer = new FileWriter(outputFile);
            int character;
            while ((character = reader.read()) != -1) {
                writer.write(character);
            }
            System.out.println("FILE CONTENT COPIED SUCCESSFULLY");
        } 
        catch (FileNotFoundException e) {
            System.out.println("Error: Input file not found - " + inputFile);
        } 
        catch (IOException e) {
            System.out.println("Error: An I/O error occurred.");
        }
    }
}

//OUTPUT
//FILE CONTENT COPIED SUCCESSFULLY

//OUTPUT.TXT WILL CONTAIN:
//Hello, Java World!
