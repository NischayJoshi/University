/*Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int t = 0;
  cout << "Number of Test Cases: ";
  cin >> t;
  while (t--)
  {
    int n = 0;
    cout << "\n\nNumber of elements in sorted array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements in sorted order: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int key = 0, count = 0;
    bool found = false;
    cout << "Key Value: ";
    cin >> key;
    int start = 0, end = n - 1;
    while (start <= end)
    {
      count++;
      int mid = (start + end) / 2;
      if (arr[mid] == key)
      {
        found = true;
        break;
      }
      else
      {
        if (key > arr[mid])
          start = mid + 1;
        else
          end = mid - 1;
      }
    }
    if (found)
    {
      cout << "Present " << count;
    }
    else
    {
      cout << "Not Present";
    }
  }
  return 0;
}
