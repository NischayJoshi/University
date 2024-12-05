#include <stdio.h>
#include <math.h>

// returns the value of y given x in function
float fx(float x)
{
  return (x * x * x) - x - 1;
}

// main function
int main()
{
  // Taking the interval as input
  float a, b;
  printf("Enter the value of a: ");
  scanf("%f", &a);
  printf("Enter the vlaue of b: ");
  scanf("%f", &b);
  if (fx(a) * fx(b) > 0)
  {
    printf("No root exist in given interval\n");
    return 0;
  }

  // Taking the tolerance as input
  float tolerance;
  printf("Enter the tolerance: ");
  scanf("%f", &tolerance);

  // Running iterations to find the approximate root
  int max_iteration = 50;
  for (int i = 1; i <= max_iteration; i++)
  {
    float x = (a + b) / 2;
    printf("Iteration %d:  x= %f, value = %f\n", i, x, fx(x));
    if (fabs(fx(x)) <= tolerance)
    {
      printf("Root : %f\n", x);
      return 0;
    }
    else
    {
      if (fx(x) * fx(a) < 0)
        b = x;
      else
        a = x;
    }
  }
  printf("No root found in given number of iterations and tolerance!");
  return 0;
}