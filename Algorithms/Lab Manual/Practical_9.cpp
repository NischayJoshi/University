/*Given an unsorted array of positive integers, design an algorithm and implement it using
a program to find whether there are any duplicate elements in the array or not. (use
sorting) (Time Complexity = O(n log n))*/

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int left, int right)
{
  int p = arr[right];
  int i = left - 1, j = left;
  while (j < right)
  {
    if (arr[j] < p)
    {
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
  return i;
}

void quicksort(vector<int> &arr, int left, int right)
{
  if (left >= right)
    return;
  int pivot = partition(arr, left, right);
  quicksort(arr, left, pivot - 1);
  quicksort(arr, pivot + 1, right);
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
    quicksort(arr, 0, n - 1);
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
      if (arr[i] == arr[i + 1])
      {
        flag++;
        break;
      }
    }
    if (flag == 0)
      cout << "No duplicates found.";
    else
      cout << "Yes, duplicates are found.";
  }
  return 0;
}