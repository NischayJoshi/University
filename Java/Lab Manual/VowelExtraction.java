// Write a Java program to write some sentences in a file and extract vowels from it and show at the output screen.

import java.io.*;

public class VowelExtraction {

  public static void writeSentencesToFile(String fileName, String[] sentences) {
    try (FileWriter writer = new FileWriter(fileName)) {
      for (String sentence : sentences) {
        writer.write(sentence + System.lineSeparator());
      }
      System.out.println("Sentences written to file successfully.");
    } catch (IOException e) {
      System.out.println("An error occurred while writing to the file.");
      e.printStackTrace();
    }
  }

  public static void extractVowelsFromFile(String fileName) {
    String vowels = "AEIOUaeiou";
    StringBuilder vowelBuilder = new StringBuilder();

    try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
      String line;
      while ((line = reader.readLine()) != null) {
        for (char c : line.toCharArray()) {
          if (vowels.indexOf(c) != -1) {
            vowelBuilder.append(c);
          }
        }
      }
      System.out.println("Vowels extracted from the file: " + vowelBuilder.toString());
    } catch (IOException e) {
      System.out.println("An error occurred while reading the file.");
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    String fileName = "sentences.txt";
    String[] sentences = {
        "This is the first sentence.",
        "Another example sentence here.",
        "Let's see how this works!",
        "Vowels will be extracted from these sentences."
    };
    writeSentencesToFile(fileName, sentences);
    extractVowelsFromFile(fileName);
  }
}
