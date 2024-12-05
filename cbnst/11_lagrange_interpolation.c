#include <stdio.h>
#define max 10

int main()
{
  // Taking pair input
  float X[max], Y[max];
  int n = 0;
  printf("Enter the number of variable pair: ");
  scanf("%d", &n);

  printf("Enter all the values of x\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &X[i]);
  }
  printf("Enter all the values of y\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &Y[i]);
  }

  // Lagrange Interpolation Calculation
  float x = 0;
  printf("Enter the value of x to interpolate: ");
  scanf("%f", &x);

  float y = 0;
  for (int i = 0; i < n; i++)
  {
    float numerator = 1, denominator = 1;
    for (int j = 0; j < n; j++)
    {
      if (i != j)
      {
        numerator *= (x - X[j]);
        denominator *= (X[i] - X[j]);
      }
    }
    y += (numerator / denominator) * Y[i];
  }
  printf("Value of y = %f\n", y);
}