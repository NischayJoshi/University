#include <stdio.h>
#include <math.h>
#define maximum 10

void print_matrix(float A[maximum][maximum], float B[maximum], int n)
{
  // Printing the matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%.2f\t", A[i][j]);
    }
    printf("%.2f\n", B[i]);
  }
}

void gauss_jordan(float A[maximum][maximum], float B[maximum], int n)
{
  for (int i = 0; i < n; i++)
  {
    // Normalizing all matrices
    float pivot = A[i][i];
    for (int j = 0; j < n; j++)
    {
      A[i][j] /= pivot;
    }
    B[i] /= pivot;

    // Turning matrix to identity
    for (int j = 0; j < n; j++)
    {
      if (j != i)
      {
        float factor = A[j][i];
        for (int k = 0; k < n; k++)
        {
          A[j][k] -= factor * A[i][k];
        }
        B[j] -= factor * B[i];
      }
    }
  }
}

int main()
{
  // Taking the matrix as input
  int n;
  printf("Enter the number of equations: ");
  scanf("%d", &n);
  float A[maximum][maximum], B[maximum];
  printf("Enter the coefficients of the equations as input: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%f", &A[i][j]);
    }
  }
  printf("Enter the constants as input: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &B[i]);
  }

  // Printing the matrix
  printf("The given matrix: \n");
  print_matrix(A, B, n);

  // Applying Gauss Jordan
  gauss_jordan(A, B, n);
  printf("Matrix after converting it to identity: \n");
  print_matrix(A, B, n);

  // Printing output:
  printf("The values of the variables are: \n");
  for (int i = 0; i < n; i++)
  {
    printf("x%d = %f\n", i, B[i]);
  }
  return 0;
}