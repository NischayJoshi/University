#include <stdio.h>
#include <math.h>

#define maximum 10
#define tolerance 1e-4

int main()
{

  // Taking the equations as input
  float A[maximum][maximum], B[maximum], x[maximum], new_x[maximum];
  int n;
  printf("Enter the number of equations: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    x[i] = 0;
    new_x[i] = 0;
  }
  printf("Enter the coefficients of equations: \n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%f", &A[i][j]);
    }
  }
  printf("Enter the constants: \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &B[i]);
  }

  // Checking for diagonal dominance
  for (int i = 0; i < n; i++)
  {
    float sum = 0;
    for (int j = 0; j < n; j++)
    {
      if (j != i)
      {
        sum += fabs(A[i][j]);
      }
    }
    if (fabs(A[i][i]) < sum)
    {
      printf("Diagonal Dominance not found, try again!\n");
      return 0;
    }
  }

  // Proceeding with iteration;
  int max_iteration = 50;
  for (int k = 0; k < max_iteration; k++)
  {
    float error = 0;
    // Running K-th iteration for each row
    for (int i = 0; i < n; i++)
    {
      float sum = B[i];
      // Summing up the values of each column in given row
      for (int j = 0; j < n; j++)
      {
        if (j != i)
        {
          sum -= A[i][j] * new_x[j];
        }
      }
      // Updating the new value of x for the given row
      new_x[i] = sum / A[i][i];
      error = fmax(error, fabs(x[i] - new_x[i]));
    }
    // Updating the result array
    for (int i = 0; i < n; i++)
    {
      x[i] = new_x[i];
    }
    if (error <= tolerance)
    {
      printf("Solution: \n");
      for (int i = 0; i < n; i++)
      {
        printf("x%d = %f\n", i, x[i]);
      }
    }
  }
  printf("No solution found for given iterations and tolerance.");
}