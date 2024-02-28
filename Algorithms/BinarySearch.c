#include <stdio.h>

// Binary Search by Recursion
int recursiveBS(int *arr, int target, int start, int end)
{
  // Base case: If the start index surpasses the end index, the target is not found
  if (start > end)
  {
    return -1;
  }

  // Calculate the middle index
  int mid = (start + end) / 2;

  // If the middle element equals the target, return its index
  if (arr[mid] == target)
  {
    return mid;
  }
  // If the middle element is less than the target, search in the right half
  else if (arr[mid] < target)
  {
    return recursiveBS(arr, target, mid + 1, end);
  }
  // If the middle element is greater than the target, search in the left half
  else
  {
    return recursiveBS(arr, target, start, mid - 1);
  }
}

// Binary Search by Iteration
int iterativeBS(int *arr, int target, int len)
{
  // Initialize start and end indices
  int start = 0, end = len - 1;
  int mid = 0;

  // Iterate until the start index is less than or equal to the end index
  while (start <= end)
  {
    // Calculate the middle index
    mid = (start + end) / 2;

    // If the middle element equals the target, return its index
    if (arr[mid] == target)
    {
      return mid;
    }
    // If the middle element is less than the target, update the start index to search in the right half
    else if (arr[mid] < target)
    {
      start = mid + 1;
    }
    // If the middle element is greater than the target, update the end index to search in the left half
    else
    {
      end = mid - 1;
    }
  }
  // If the target is not found, return -1
  return -1;
}

// Main function for binary search demonstration
int main()
{
  // Sorted array for binary search
  int arr[15] = {1, 3, 4, 7, 9, 10, 13, 15, 17, 19, 22, 25, 27, 29, 30};
  int n = 1, index = 0, target = 0, len = 15; // Length of the array

  // Menu-driven interface for selecting the search method
  while (n)
  {
    printf("Enter 1 for Iterative Binary Search.\nEnter 2 for Recursive Binary Search.\nEnter 0 to exit.\n:");
    scanf("%d", &n);
    if (n)
    {
      printf("Enter the element to search: ");
      scanf("%d", &target);
      // Perform binary search based on user's choice
      if (n == 1)
        index = iterativeBS(arr, target, len); // Perform iterative binary search
      else
        index = recursiveBS(arr, target, 0, len - 1); // Perform recursive binary search
      // Display search result
      if (index == -1)
        printf("Element not found!\n\n");
      else
        printf("Element found at %d index.\n\n", index);
    }
    else
      return 0; // Exit the program
  }
}
