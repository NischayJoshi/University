/* Write a JAVA Program to implement various String class functions such as 
length(), concat(), replace(), replaceAll(), trim() etc.  */
import java.util.Scanner;
public class StringMethods {
  public static void main(String[] args)
  {
    Scanner cin = new Scanner(System.in);
    System.out.println("Enter a String: ");
    String str = cin.nextLine();
    System.out.println("Length of the string: " + str.length());
    System.out.println("Enter another string: ");
    String str2 = cin.nextLine();
    String con = str.concat(str2);
    System.out.println("The concatinated string: " + con);
    str = "This is a sample string";
    System.out.println("String before replace function: "+str);
    str2=str.replace('i', 'R');
    System.out.println("String after replace function: " + str2);
    str = "Apple Banana Apple Mango";
    System.out.println("String before ReplaceAll function: " + str);
    str2=str.replaceAll("Apple", "Grapes");
    System.out.println("String after ReplaceAll function: " + str2);
    str = "    Text here    ";
    System.out.println("String before Trim Function: "+ str);
    str2=str.trim();
    System.out.println("String after Trim Function: " + str2);
    System.out.println("Thank You!");
    cin.close();
  }
}
