#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
  return (x - y) / (y + x);
}

int main()
{
  float x, y, xn, h;
  int n;
  printf("Enter the initial value of x: ");
  scanf("%f", &x);
  printf("Enter the initial value of y: ");
  scanf("%f", &y);
  printf("Enter the number of intervals: ");
  scanf("%d", &n);
  printf("Enter the final value of x: ");
  scanf("%f", &xn);

  h = (xn - x) / n;
  for (int i = 0; i < n; i++)
  {
    y = y + h * f(x + (i * h), y);
    printf("For x= %f: Value of y= %f\n", x, y);
  }
  printf("Approximate value of y = %f\n", y);
}