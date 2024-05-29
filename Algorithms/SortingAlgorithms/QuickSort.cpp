#include <iostream>
using namespace std;

// Partition function to rearrange the elements around a pivot
int partition(int arr[], int start, int end)
{
  int i = start - 1; // Index of smaller element
  int pivot = end;   // Pivot element index
  for (int j = start; j < end; j++)
  {
    // If current element is smaller than pivot
    if (arr[j] < arr[pivot])
    {
      i++; // Increment index of smaller element
      // Swap arr[i] and arr[j]
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  // Swap arr[i+1] and arr[pivot] (pivot element)
  int temp = arr[i + 1];
  arr[i + 1] = arr[pivot];
  arr[pivot] = temp;
  return i + 1; // Return partitioning index
}

// QuickSort function to recursively sort the array
void quicksort(int arr[], int start, int end)
{
  if (start >= end)
    return;                               // Base case: if start index is greater than or equal to end index, return
  int pivot = partition(arr, start, end); // Partition the array and get the pivot index
  quicksort(arr, start, pivot - 1);       // Recursively sort elements before pivot
  quicksort(arr, pivot + 1, end);         // Recursively sort elements after pivot
}

// Main function
int main()
{
  int arr[7] = {5, 2, 7, 3, 8, 4, 9}; // Input array
  quicksort(arr, 0, 6);               // Call quicksort function to sort the array
  // Print the sorted array
  for (int i = 0; i < 7; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}
