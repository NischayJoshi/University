/*Given an unsorted array of integers, design an algorithm and implement it using a
 program to find Kth smallest or largest element in the array. (Worst case TimeComplexity = O(n))*/

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int left, int right)
{
  int pivot = arr[right];
  int i = left - 1;
  for (int j = left; j < right; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[right]);
  return i + 1;
}

int quickselect(vector<int> &arr, int left, int right, int k)
{
  if (left <= right)
  {
    int pivotIndex = partition(arr, left, right);
    int leftSize = pivotIndex - left + 1;
    if (leftSize == k)
    {
      return pivotIndex;
    }
    else if (k < leftSize)
    {
      return quickselect(arr, left, pivotIndex - 1, k);
    }
    else
    {
      return quickselect(arr, pivotIndex + 1, right, k - leftSize);
    }
  }
  return -1; // Return -1 if left > right (base case)
}

int main()
{
  int t;
  cout << "Number of test cases: ";
  cin >> t;
  while (t--)
  {
    int n;
    cout << "\n\nEnter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int k;
    cout << "Enter the value of K: ";
    cin >> k;
    int index = quickselect(arr, 0, n - 1, k);
    if (index != -1)
    {
      cout << "Kth smallest element of the array: " << arr[index] << endl;
    }
    else
    {
      cout << "Invalid input for K!" << endl;
    }
  }
  return 0;
}
