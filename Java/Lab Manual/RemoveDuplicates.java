// Write a Java program to find the duplicate characters in the given paragraph using StringBuffer class methods.
import java.util.Scanner;

public class RemoveDuplicates {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter the String: ");
    String input = sc.nextLine();

    System.out.println("The given String is: " + input);

    StringBuffer result = new StringBuffer();
    for (int i = 0; i < input.length(); i++) {
      char ch = input.charAt(i);
      if (result.indexOf(String.valueOf(ch)) == -1) {
        result.append(ch);
      }
    }

    System.out.println("After removing duplicate characters the new string is: " + result.toString());

    sc.close();
  }
}
