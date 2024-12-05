#include <stdio.h>
#include <math.h>
int main()
{
  float true_value = 0, approximate_value = 0;
  printf("Enter the true value: ");
  scanf("%f", &true_value);
  printf("Enter the appriximated value: ");
  scanf("%f", &approximate_value);
  float absolute_error = 0, relative_error = 0, percentage_error = 0;
  absolute_error = fabs(true_value - approximate_value);
  relative_error = absolute_error / true_value;
  percentage_error = relative_error * 100;
  printf("Absolute Error: %f\n", absolute_error);
  printf("Relative Error: %f\n", relative_error);
  printf("Percentage Error: %f\n", percentage_error);
}