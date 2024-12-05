#include <stdio.h>
#include <math.h>

float f(float x)
{
  return x * x;
}

float trapezoidal(float a, float b, int n)
{
  float h = (b - a) / n;
  float sum = (f(a) + f(b)) / 2;
  for (int i = 1; i < n; i++)
  {
    sum += f(a + (i * h));
  }
  sum *= h;
  return sum;
}

int main()
{
  float a, b;
  int n;
  printf("Enter the lower limit: ");
  scanf("%f", &a);
  printf("Enter the upper limit: ");
  scanf("%f", &b);
  printf("Enter the number of intervals: ");
  scanf("%d", &n);

  float area = trapezoidal(a, b, n);
  printf("The area of the curve: %f\n", area);
  return 0;
}