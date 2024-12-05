/* Given a sorted array of positive integers containing few duplicate elements,
 design an algorithm and implement it using a program to find whether the given key element
 is present in the array or not .If present, then also find the number of copies of given key.
 (Time Complexity = O(log n)) */

#include <iostream>
#include <vector>

using namespace std;
int main()
{
  int t = 0;
  cout << "Number of test cases: ";
  cin >> t;
  while (t--)
  {
    int n = 0;
    cout << "\n\nEnter the number of elements in the sorted array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int key = 0;
    cout << "Enter the key element to find: ";
    cin >> key;
    int count = 0;
    int left = 0, right = n - 1;
    while (left <= right)
    {
      int mid = (left + right) / 2;
      if (arr[mid] == key)
      {
        left = mid - 1;
        right = mid + 1;
        count++;
        while (left >= 0 && arr[left] == key)
        {
          count++;
          left--;
        }
        while (right < n && arr[right] == key)
        {
          count++;
          right++;
        }
        break;
      }
      else
      {
        if (arr[mid] > key)
          right = mid - 1;
        else
          left = mid + 1;
      }
    }
    cout << "Number of Occurences: " << count;
  }
  return 0;
}