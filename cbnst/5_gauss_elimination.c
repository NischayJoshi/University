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

void gauss_elimination(float A[maximum][maximum], float B[maximum], int n)
{
  // Forward Elimination
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      float factor = A[j][i] / A[i][i];
      for (int k = i; k < n; k++)
      {
        A[j][k] -= factor * A[i][k];
      }
      B[j] -= factor * B[i];
    }
  }
}

void backward_substitution(float A[maximum][maximum], float B[maximum], int n)
{
  // Backward Substitution
  for (int i = n - 1; i >= 0; i--)
  {
    B[i] /= A[i][i];
    for (int j = i - 1; j >= 0; j--)
    {
      B[j] -= A[j][i] * B[i];
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

  // Applying Gauss Elimination
  gauss_elimination(A, B, n);
  printf("Matrix after gauss elimination: \n");
  print_matrix(A, B, n);

  // Applying Backward Substitution
  backward_substitution(A, B, n);

  // Printing output:
  printf("The values of the variables are: \n");
  for (int i = 0; i < n; i++)
  {
    printf("x%d = %f\n", i, B[i]);
  }
  return 0;
}