#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
  return (x - y) / (x + y);
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
    float k1, k2, k3, k4, K;
    k1 = h * f(x, y);
    k2 = h * f(x + (h / 2), y + (k1 / 2));
    k3 = h * f(x + (h / 2), y + (k2 / 2));
    k4 = h * f(x + h, y + k3);

    K = (k1 + (2 * k2) + (2 * k3) + k4) / 6;

    y = y + K;
    printf("For x= %f: Value of y= %f\n", x, y);
    x += h;
  }
  printf("Approximate value of y = %f\n", y);
}