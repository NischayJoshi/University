#include <stdio.h>
#include <math.h>
#define maximum 10

void print_matrix(float A[maximum][maximum], float B[maximum], int n)
{
  printf("Matrix: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%f\t", A[i][j]);
    }
    printf("%f\n", B[i]);
  }
  printf("\n");
}

void gauss_jordan(float A[maximum][maximum], float B[maximum], int n)
{
  for (int i = 0; i < n; i++)
  {
    // Pivoting
    float pivot = A[i][i];
    for (int j = 0; j < n; j++)
    {
      A[i][j] /= pivot;
    }
    B[i] /= pivot;

    // Making Identity matrix
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
  float A[maximum][maximum], B[maximum];
  int n;
  printf("Enter the number of equations: ");
  scanf("%d", &n);
  printf("Enter the coefficients of each equation: \n");
  for (int i = 0; i < n; i++)
  {
    printf("Equation %d: ", i + 1);
    for (int j = 0; j < n; j++)
    {
      scanf("%f", &A[i][j]);
    }
  }

  printf("Enter the constants of each equation: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &B[i]);
  }
  print_matrix(A, B, n);

  gauss_jordan(A, B, n);
  // Printing the roots
  printf("The roots are: ");
  for (int i = 0; i < n; i++)
  {
    printf("%f, ", B[i]);
  }
}