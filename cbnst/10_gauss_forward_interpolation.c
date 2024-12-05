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
  float x;
  printf("Enter the value of x to interpolate: ");
  scanf("%f", &x);
  int h = X[1] - X[0];
  int mid = n / 2;
  float u = (x - X[mid]) / h;
  // Compute the interpolated value

  float y = Y[mid][0] + (u * Y[mid][1]);
  int fact = 1, p = 1;
  for (int j = 2; j < n; j++)
  {
    if (j % 2 == 0)
    {
      p *= (u - (j / 2));
    }
    else
    {
      p *= (u + (j / 2));
    }
    fact *= j;
    y += (p * Y[mid - (j / 2)][j]) / fact;
  }

  printf("The interpolated value of y at x = %f is: %f\n", x, y);
  return 0;
}
