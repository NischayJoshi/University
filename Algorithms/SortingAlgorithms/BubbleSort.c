#include <stdio.h>

// Function to perform Bubble Sort on an array of integers
void BubbleSort(int *arr, int n)
{
  int temp = 0;
  // Outer loop iterates over each element of the array
  for (int i = 0; i < n; i++)
  {
    // Inner loop compares adjacent elements and swaps them if they are in the wrong order
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap arr[j] and arr[j+1]
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d array elements: ", n);
  // Input elements into the array
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  // Call BubbleSort to sort the array
  BubbleSort(arr, n);
  printf("The sorted array: ");
  // Output the sorted array
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}
