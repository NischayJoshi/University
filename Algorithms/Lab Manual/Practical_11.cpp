/*Given an unsorted array of integers, design an algorithm and implement it using a
 program to sort an array of elements by partitioning the array into two subarrays based
 on a pivot element such that one of the sub array holds values smaller than the pivot
 element while another sub array holds values greater than the pivot element. Pivot
 element should be selected randomly from the array. Your program should also find
 number of comparisons and swaps required for sorting the array.*/

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int left, int right, int &c, int &s)
{
  int p = arr[right];
  int i = left - 1, j = left;
  while (j < right)
  {
    c++;
    if (arr[j] < p)
    {
      s++;
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    j++;
  }
  i++;
  int temp = arr[i];
  arr[i] = p;
  arr[right] = temp;
  s++;
  return i;
}

void quicksort(vector<int> &arr, int left, int right, int &c, int &s)
{
  if (left >= right)
    return;
  int pivot = partition(arr, left, right, c, s);
  quicksort(arr, left, pivot - 1, c, s);
  quicksort(arr, pivot + 1, right, c, s);
}

int main()
{
  int t = 0;
  cout << "Number of test cases: ";
  cin >> t;
  while (t--)
  {
    int n = 0;
    cout << "\n\nEnter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int c = 0, s = 0;
    quicksort(arr, 0, n - 1, c, s);
    cout << "Sorted array: ";
    for (int num : arr)
    {
      cout << num << " ";
    }
    cout << endl
         << "Number of comparisions: " << c << endl;
    cout << "Number of swaps: " << s;
  }
  return 0;
}