#include <stdio.h>

// Function to perform Insertion Sort on an array
void InsertionSort(int *arr, int n)
{
  for (int i = 1; i < n; i++)
  {
    int temp = arr[i]; // Store the current element to be inserted
    int j = i - 1;     // Initialize the index of the previous element

    // Shift elements of arr[0..i-1], that are greater than temp, to one position ahead of their current position
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j]; // Move the element to the right
      j--;
    }
    arr[j + 1] = temp; // Insert the stored element at the correct position
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

  // Call InsertionSort to sort the array
  InsertionSort(arr, n);

  printf("The sorted array: ");

  // Output the sorted array
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}
