#include <stdio.h>
#include <math.h>
#define maximum 10

int main()
{
  // Taking input
  int n;
  printf("Enter the number of rows: ");
  scanf("%d", &n);
  float X[maximum], Y[maximum][maximum];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      Y[i][j] = 0;
    }
  }

  printf("Enter the x and y in pairs: \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%f", &X[i]);
    scanf("%f", &Y[i][0]);
  }

  // Compute the difference table
  for (int j = 1; j < n; j++)
  {
    for (int i = 0; i < n - j; i++)
    {
      Y[i][j] = Y[i + 1][j - 1] - Y[i][j - 1];
    }
  }

  float x, h, u;
  printf("Enter the value of x: ");
  scanf("%f", &x);
  printf("Enter the value of : ");
  scanf("%f", &h);
  u = (x - X[0]) / h;

  float ans = Y[0][0] + u * Y[0][1] + (u * (u - 1) * Y[0][2]) / 2 + (u * (u - 1) * (u - 2) * Y[0][3]) / 6 + (u * (u - 1) * (u - 2) * (u - 3) * Y[0][4]) / 24;
  printf("Answer: %f", ans);
  return 0;
}