// Newtom Raphson Method

#include <stdio.h>
#include <math.h>

float f(float x)
{
  return 3 * x - cos(x) - 1;
}

float df(float x)
{
  return 3 + sin(x);
}

int main()
{
  // Taking first approximation as input
  float x0;
  printf("Enter first approximation: ");
  scanf("%f", &x0);

  // Taking tolerance as input
  float tolerance;
  printf("Enter the tolerance: ");
  scanf("%f", &tolerance);

  // Iterating to get the root
  int max_iterations = 50;
  for (int i = 0; i < max_iterations; i++)
  {
    if (df(x0) == 0)
    {
      printf("No root found.\n");
      return 0;
    }
    float x1 = x0 - (f(x0) / df(x0));
    printf("Iteration %d: For x= %f, value = %f\n", i, x1, f(x1));
    if (fabs(f(x1)) <= tolerance)
    {
      printf("Root = %f", x1);
      return 0;
    }
    else
    {
      x0 = x1;
    }
  }
  printf("No root found in given iteratoins and tolerance.");
}