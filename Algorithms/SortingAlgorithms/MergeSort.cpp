#include <iostream>
using namespace std;

// Function to merge two subarrays into one sorted array
void merge(int arr[], int left, int mid, int right)
{
  // Allocate memory for left and right subarrays
  int *leftarr = new int[mid - left + 1];
  int *rightarr = new int[right - mid];

  // Copy data to left and right subarrays
  for (int i = left; i <= mid; i++)
  {
    leftarr[i - left] = arr[i];
  }
  for (int i = mid + 1; i <= right; i++)
  {
    rightarr[i - mid - 1] = arr[i];
  }

  // Merge the left and right subarrays back into the original array
  int i = 0, j = 0, k = left;
  while (i < mid - left + 1 && j < right - mid)
  {
    if (leftarr[i] <= rightarr[j])
    {
      arr[k++] = leftarr[i++];
    }
    else
    {
      arr[k++] = rightarr[j++];
    }
  }
  // Copy any remaining elements of left and right subarrays
  while (i < mid - left + 1)
  {
    arr[k++] = leftarr[i++];
  }
  while (j < right - mid)
  {
    arr[k++] = rightarr[j++];
  }

  // Free allocated memory
  delete[] leftarr;
  delete[] rightarr;
}

// Function to recursively sort an array using merge sort
void mergesort(int arr[], int left, int right)
{
  if (left < right)
  {
    // Find the middle index
    int mid = left + (right - left) / 2;
    // Recursively sort the left and right halves
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

int main()
{
  // Test array
  int arr[7] = {5, 2, 7, 3, 8, 4, 9};
  // Perform merge sort
  mergesort(arr, 0, 6);
  // Print sorted array
  for (int i = 0; i < 7; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}
