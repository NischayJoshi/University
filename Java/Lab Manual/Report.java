import java.util.Scanner;

public class Report {
  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    System.out.print("Enter the number of Students: ");
    int n = cin.nextInt();
    int arr[] = new int[n];
    System.out.println("Enter marks of students");
    for (int i = 0; i < n; i++) {
      arr[i] = cin.nextInt();
    }
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
      int marks = arr[i];
      if (marks >= 81 && marks <= 100)
        a++;
      else if (marks >= 61 && marks <= 80)
        b++;
      else if (marks >= 41 && marks <= 60)
        c++;
      else
        d++;
    }
    System.out.println(a + " Students scored in the range of 81-100.");
    System.out.println(b + " Students scored in the range of 61-80.");
    System.out.println(c + " Students scored in the range of 41-60.");
    System.out.println(d + " Students scored in the range of 0-40.");
  }
}
