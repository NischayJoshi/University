/*Given an unsorted array of integers, design an algorithm and implement it using a
 program to sort an array of elements by dividing the array into two subarrays and
 combining these subarrays after sorting each one of them. Your program should also
 find number of comparisons and inversions during sorting the array*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right, int &c, int &in)
{
  vector<int> one(mid - left + 1);
  vector<int> two(right - mid);
  for (int i = 0; i < one.size(); i++)
  {
    one[i] = arr[left + i];
  }
  for (int j = 0; j < two.size(); j++)
  {
    two[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  while (i < one.size() && j < two.size())
  {
    c++;
    if (one[i] < two[j])
      arr[k++] = one[i++];
    else
    {
      arr[k++] = two[j++];
      in += mid - left + 1 - i;
    }
  }
  while (i < one.size())
  {
    arr[k++] = one[i++];
  }
  while (j < two.size())
  {
    arr[k++] = two[j++];
  }
}
void mergesort(vector<int> &arr, int left, int right, int &c, int &in)
{
  if (left >= right)
    return;
  int mid = left + (right - left) / 2;
  mergesort(arr, left, mid, c, in);
  mergesort(arr, mid + 1, right, c, in);
  merge(arr, left, mid, right, c, in);
}

int main()
{
  int t;
  cout << "Enter the number of test cases: ";
  cin >> t;
  while (t--)
  {
    int n = 0;
    cout << "\n\nEnter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements in array: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int c = 0, in = 0;
    mergesort(arr, 0, n - 1, c, in);
    cout << "Sorted array: ";
    for (int num : arr)
    {
      cout << num << " ";
    }
    cout << endl
         << "Number of comparisions: " << c << endl;
    cout << "Number of inversions: " << in;
  }
  return 0;
}