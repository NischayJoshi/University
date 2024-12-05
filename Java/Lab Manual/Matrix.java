// Write a program to print the diagonal sum of a m*n matrix.

import java.util.*;

public class Matrix {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the values of n and m: ");
    int n = sc.nextInt();
    int m = sc.nextInt();

    int[][] arr = new int[n][m];

    System.out.println("Enter the elements of the matrix:");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        arr[i][j] = sc.nextInt();
      }
    }

    int sum = 0;
    for (int i = 0; i < Math.min(n, m); i++) {
      sum += arr[i][i];
    }
    System.out.println("The sum of diagonal elements are: " + sum);

    sc.close();
  }
}
