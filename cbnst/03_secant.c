// Secant Method
#include <stdio.h>
#include <math.h>

float f(float x)
{
  return ((x * x * x) - (5 * x) + 1);
}

int main()
{
  // Taking the interval as input
  float x0, x1;
  printf("Enter x0: ");
  scanf("%f", &x0);
  printf("Enter x1: ");
  scanf("%f", &x1);
  if (f(x1) * f(x0) > 0)
  {
    printf("No root exists in given interval.");
    return 0;
  }

  // Taking tolerance as input
  float tolerance;
  printf("Enter the tolerance: ");
  scanf("%f", &tolerance);

  // Running iterations
  int max_iterations = 50;
  for (int i = 0; i < max_iterations; i++)
  {
    float x2 = x1 - (((x1 - x0) / (f(x1) - f(x0))) * f(x1));
    printf("Iteration %d: For x= %f, value= %f\n", i, x2, f(x2));
    if (fabs(f(x2)) <= tolerance)
    {
      printf("Root = %f\n", x2);
      return 0;
    }
    else
    {
      x0 = x1;
      x1 = x2;
    }
  }
  printf("No root found for given iterations and tolerance.");
  return 0;
}