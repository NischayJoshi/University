import java.util.Scanner;
class Calculator
{
  public static void main(String[] args)
  {
    Scanner cin = new Scanner(System.in);
    while (true) {
      System.out.print("Enter first number : ");
      int num1 = cin.nextInt();
      System.out.print("Enter second number : ");
      int num2 = cin.nextInt();
      System.out.print("Enter the operaton to execute [+,-,*,/,%] : ");
      char op = cin.next().charAt(0);
      int answer = 0;
      switch (op) {
        case '+':
          answer = num1 + num2;
          break;
        case '-':
          answer = num1 - num2;
          break;
        case '*':
          answer = num1 * num2;
          break;
        case '/':
          answer = num1 / num2;
          break;
        case '%':
          answer = num1 % num2;
          break;
        default: {
          System.out.println("Invalid operator input.");
        }
      }
      System.out.println("Answer : " + answer);
      System.out.println("Enter 1 if you want to continue...");
      answer = cin.nextInt();
      if (answer != 1) {
        break;
      }
    }
    System.out.println("Thank You!");
    cin.close();
  }
}