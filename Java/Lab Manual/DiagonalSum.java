import java.util.Scanner;
public class DiagonalSum {
  public static void main(String[] args)
  {
    Scanner cin = new Scanner(System.in);
    int m = 0, n = 0;
    System.out.println("Number of Rows: ");
    m = cin.nextInt();
    System.out.println("Nuber of Columns: ");
    n = cin.nextInt();
    int mat[][]=new int[m][n];
    System.out.println("Enter the elements in Matrix: ");
    for(int i=0;i<m;i++)
    {
      for (int j = 0; j < n; j++) {
        mat[i][j] = cin.nextInt();
      }
    }
    System.out.println("The Matrix : ");
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        System.out.print(mat[i][j] + " ");
      }
      System.out.println();
    }
    int smol = m < n ? m : n;
    int sum = 0;
    for(int i=0;i<smol;i++)
    {
      sum += mat[i][i];
    }
    System.out.println("Sum of the diagonals of the matrix: "+sum);

  }
}
