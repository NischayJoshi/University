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

  float u = (x - X[0]) / h; // Calculate u for Newton forward formula

  // Compute the forward difference table
  for (int j = 1; j < n; j++)
  {
    for (int i = 0; i < n - j; i++)
    {
      Y[i][j] = Y[i + 1][j - 1] - Y[i][j - 1];
    }
  }

  // Uncomment this block to print the difference table (optional)
  /*
  printf("\nForward Difference Table:\n");
  for (int i = 0; i < n; i++) {
    printf("%f ", X[i]);
    for (int j = 0; j < n - i; j++) {
      printf("%f\t", Y[i][j]);
    }
    printf("\n");
  }
  */

  // Compute the interpolated value
  float y = Y[0][0]; // Starting with the first term
  float p = 1;
  int fact = 1;

  for (int i = 1; i < n; i++)
  {
    p *= (u - (i - 1));        // Compute (u)(u-1)(u-2)... iteratively
    fact *= i;                 // Compute i! iteratively
    y += (p * Y[0][i]) / fact; // Add each term of the formula
  }

  printf("The interpolated value of y at x = %f is: %f\n", x, y);
  return 0;
}
