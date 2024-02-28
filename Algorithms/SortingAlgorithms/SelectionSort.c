#include <stdio.h>

// Function to perform Selection Sort on an array
void SelectionSort(int *arr, int n)
{
  int temp = 0; // Temporary variable for swapping

  // Iterate over the array
  for (int i = 0; i < n - 1; i++)
  {
    int min = i; // Assume the current index as the minimum

    // Find the index of the minimum element in the unsorted portion
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }

    // Swap the current element with the minimum element
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

// Main function
int main()
{
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n]; // Declare an array of size n
  printf("Enter %d array elements: ", n);

  // Input elements into the array
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  // Call SelectionSort to sort the array
  SelectionSort(arr, n);

  printf("The sorted array: ");

  // Output the sorted array
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}
