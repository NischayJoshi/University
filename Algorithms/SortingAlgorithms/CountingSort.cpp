#include <iostream>
using namespace std;

int main()
{
  int arr[17] = {3, 3, 5, 2, 7, 8, 6, 7, 9, 8, 7, 7, 2, 4, 5, 7, 1};
  int n = 17;

  // Find the maximum value in the array
  int maxVal = arr[0];
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > maxVal)
    {
      maxVal = arr[i];
    }
  }

  // Count occurrences of each element (0 to maxVal)
  int freq[maxVal + 1] = {0};
  for (int num : arr)
  {
    freq[num]++;
  }

  // Calculate cumulative frequencies
  for (int i = 1; i <= maxVal; i++)
  {
    freq[i] += freq[i - 1];
  }

  // Build the sorted array
  int sorted_array[n];
  for (int i = n - 1; i >= 0; i--)
  {
    sorted_array[--freq[arr[i]]] = arr[i]; // Place element at its sorted position
  }

  // Print the sorted array
  cout << "Sorted array: ";
  for (int num : sorted_array)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
