#include <stdio.h>
#define max 10

int main()
{
  float X[max], Y[max];
  int n;
  printf("Enter the number of (x,y) pair: ");
  scanf("%d", &n);

  printf("Enter the x values");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &X[i]);
  }
  printf("Enter the y values");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &Y[i]);
  }

  float sumX = 0, sumY = 0, sumXY = 0, sumXX = 0;
  for (int i = 0; i < n; i++)
  {
    sumX += X[i];
    sumY += Y[i];
    sumXY += X[i] * Y[i];
    sumXX += X[i] * X[i];
  }

  float d, a, b;

  d = (n * sumXX) - (sumX * sumX);
  a = ((n * sumXY) - (sumX * sumY)) / d;
  b = ((sumY * sumXX) - (sumX * sumXY)) / d;

  printf("Equation: y = %f * x + %f\n", a, b);
}