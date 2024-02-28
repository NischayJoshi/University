#include <stdio.h>

// Linear Search by Iteration
int iterativeLS(int *arr, int target, int len)
{
  // Iterate through the array
  for (int i = 0; i < len; i++)
  {
    // Check if the current element equals the target
    if (arr[i] == target)
    {
      // If found, return the index
      return i;
    }
  }
  // If not found, return -1
  return -1;
}

// Linear Search by Recursion
int recursiveLS(int *arr, int target, int start, int end)
{
  // Base case: If index reaches the end of the array, target is not found
  if (start == end)
  {
    return -1;
  }

  // If target is found, return the index
  if (arr[start] == target)
  {
    return start;
  }

  // Recursively search in the next element
  return recursiveLS(arr, target, start + 1, end);
}

// Menu-driven main function
int main()
{
  int arr[8] = {10, 3, 5, 2, 8, 1, 0, 23};
  int n = 1, index = 0, target = 0, len = 8;
  while (n)
  {
    printf("Enter 1 for Iterative Linear Search.\nEnter 2 for Recursive Linear Search.\nEnter 0 to exit.\n:");
    scanf("%d", &n);
    if (n)
    {
      printf("Enter the element to search: ");
      scanf("%d", &target);
      if (n == 1)
        index = iterativeLS(arr, target, len);
      else
        index = recursiveLS(arr, target, 0, len);
      if (index == -1)
        printf("Element not found!\n\n");
      else
        printf("Element found at %d index.\n\n", index);
    }
    else
      return 0;
  }
}