import java.util.Scanner;
public class MatrixAddition {
  public static void main(String[] args)
  {
    Scanner cin = new Scanner(System.in);
    int m = 0, n = 0;
    System.out.print("Number of Rows in matrices: ");
    m = cin.nextInt();
    System.out.print("Number of Columns in matrices: ");
    n = cin.nextInt();
    int mat1[][] = new int[m][n];
    int mat2[][] = new int[m][n];
    System.out.println("Enter the elements of Matrix 1: ");
    for(int i=0;i<m;i++)
    {
      for (int j = 0; j < n; j++) {
        mat1[i][j] = cin.nextInt();
      }
    }
    System.out.println("Enter the elements of Matrix 2: ");
    for(int i=0;i<m;i++)
    {
      for (int j = 0; j < n; j++) {
        mat2[i][j] = cin.nextInt();
      }
    }
    int mat_sum[][] = new int[m][n];
    for(int i=0;i<m;i++)
    {
      for (int j = 0; j < n; j++) {
        mat_sum[i][j] = mat1[i][j] + mat2[i][j];
      }
    }
    System.out.println("The Sum Matrix: ");
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        System.out.print(mat_sum[i][j] + " ");
      }
      System.out.println();
    }
  }
}
