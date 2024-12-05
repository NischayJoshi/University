#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 10

int main()
{
  float X[max], Y[max][max];

  // Initialize the difference table to 0
  for (int i = 0; i < max; i++)
  {
    for (int j = 0; j < max; j++)
    {
      Y[i][j] = 0;
    }
  }

  int n;
  printf("Enter the number of value pairs: ");
  scanf("%d", &n);

  printf("Enter all the X values:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &X[i]);
  }

  printf("Enter all the Y values:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &Y[i][0]); // First column is filled with given Y values
  }

  float h = X[1] - X[0]; // Assuming equally spaced X values
  float x;
  printf("Enter the value of x to interpolate: ");
  scanf("%f", &x);

  float u = (x - X[n - 1]) / h; // Calculate u for Newton backward formula

  // Compute the backward difference table
  for (int j = 1; j < n; j++)
  {
    for (int i = n - 1; i >= j; i--)
    {
      Y[i][j] = Y[i][j - 1] - Y[i - 1][j - 1];
    }
  }

  // Uncomment this block to print the difference table (optional)
  /*
  printf("\nBackward Difference Table:\n");
  for (int i = 0; i < n; i++) {
    printf("%f ", X[i]);
    for (int j = 0; j <= i; j++) {
      printf("%f\t", Y[i][j]);
    }
    printf("\n");
  }
  */

  // Compute the interpolated value
  float y = Y[n - 1][0]; // Starting with the last value
  float p = 1;
  int fact = 1;

  for (int i = 1; i < n; i++)
  {
    p *= (u + (i - 1));                // Compute (u)(u+1)(u+2)... iteratively
    fact *= i;                         // Compute i! iteratively
    y += (p * Y[n - 1 - i][i]) / fact; // Add each term of the formula
  }

  printf("The interpolated value of y at x = %f is: %f\n", x, y);
  return 0;
}
