import java.net.SocketTimeoutException;
import java.util.Scanner;

public class Floyd {
  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    System.out.println("Welcome to Floyd's Triangle.");
    System.out.println("Enter the number of rows: ");
    int rows = cin.nextInt();
    int count = 1;
    System.out.println("Floys's Triangle");
    for (int i = 1; i <= rows; i++) {
      for (int j = 0; j < i; j++) {
        System.out.print((count++) + "/t");
      }
      System.out.println();
    }
    System.out.println("Thank You!");
  }
}
