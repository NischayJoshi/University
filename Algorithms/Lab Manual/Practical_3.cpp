/*Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[nl, search at the indexes arr[2], arr[4].... arr[2k] and so on. Once the interval (arr[2k] <
key < arr[2(k+1)] is found, perform a linear search operation from the index 2k to find the element
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):
Jump Search*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int jumpSearch(vector<int> arr, int n, int key, int &comparisons)
{
  int jump = sqrt(n);
  int left = 0;
  int right = jump;

  while (right < n && arr[right] <= key)
  {
    comparisons++;
    left = right;
    right += jump;
  }

  for (int i = left; i < min(right, n); ++i)
  {
    comparisons++;
    if (arr[i] == key)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int t = 0;
  cout << "Number of test cases: ";
  cin >> t;
  while (t--)
  {
    int size = 0;
    cout << "\n\nEnter the number of elements in the sorted array: ";
    cin >> size;
    vector<int> arr(size);
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
    {
      cin >> arr[i];
    }
    int key = 0;
    cout << "Enter the key element to find: ";
    cin >> key;
    int comparisons = 0;

    int index = jumpSearch(arr, size, key, comparisons);

    if (index != -1)
    {
      cout << "The key element " << key << " is present at index " << index << " in the array." << endl;
    }
    else
    {
      cout << "The key element " << key << " is not present in the array." << endl;
    }

    cout << "Total number of comparisons: " << comparisons << endl;
  }
  return 0;
}
