import java.io.*;

public class FileReading {
  public static void main(String args[]) {
    String fileName = "samplefile.txt";
    try {
      FileReader fr = new FileReader(fileName);
      BufferedReader bfr = new BufferedReader(fr);

      int characterCount = 0;
      int wordCount = 0;
      int lineCount = 0;

      String line;
      while ((line = bfr.readLine()) != null) {
        lineCount++;
        characterCount += line.length();
        String words[] = line.split("\\s+");
        wordCount += words.length;
      }

      System.out.println("Number of characters: " + characterCount);
      System.out.println("Number of Words: " + wordCount);
      System.out.println("Number of lines: " + lineCount);

      bfr.close();
      fr.close();
    } catch (IOException e) {
      System.out.println(e);
    }
  }
}
