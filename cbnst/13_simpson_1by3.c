#include <stdio.h>
#include <math.h>

float f(float x)
{
  return x * x;
}

float simpson(float a, float b, int n)
{
  float h = (b - a) / n;
  float sum = f(a) + f(b);
  for (int i = 1; i < n; i++)
  {
    if (i % 2 == 0)
    {
      sum += 2 * f(a + (i * h));
    }
    else
    {
      sum += 4 * f(a + (i * h));
    }
  }
  sum *= (h / 3);
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
  if (n % 2 != 0)
  {
    printf("Number of intervals is not divisible by 2, cannot proceed.\n");
    return 0;
  }

  float area = simpson(a, b, n);
  printf("The area of the curve: %f\n", area);
  return 0;
}