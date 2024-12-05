// Fixed Point Iteration or Successive Approximation Method

#include <stdio.h>
#include <math.h>

float f(float x)
{
  return cos(x) - 3 * x + 1;
}
float g(float y)
{
  return (cos(y) + 1) / 3;
}
float gd(float x)
{
  return -sin(x) / 3;
}

int main()
{
  // Taking the first approximation as input
  float x0;
  printf("Enter the first appromixation: ");
  scanf("%f", &x0);
  if (fabs(gd(x0)) < 1)
  {
    printf("Proceeding with approximatin.\n");
  }
  else
  {
    printf("No root exist for the given approximation.");
    return 0;
  }

  // Taking the tolerance as input
  float tolerance;
  printf("Enter the tolerance: ");
  scanf("%f", &tolerance);

  // Running the iteration to get the approximate root

  int max_iteration = 50;
  for (int i = 0; i < max_iteration; i++)
  {
    float x1 = g(x0);
    printf("Iteration %d : x = %.2f, value = %.2f\n", i, x1, f(x1));
    if (fabs(f(x1)) <= tolerance)
    {
      printf("Root = %f\n", x1);
      return 0;
    }
    else
    {
      x0 = x1;
    }
  }
  printf("No root found in given number of iterations and tolerance.");
  return 0;
}