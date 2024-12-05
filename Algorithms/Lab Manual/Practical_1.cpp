/*Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)*/

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
    cout << "\n\nNumber of elements in array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int key = 0, count = 0;
    bool found = false;
    cout << "Key Element: ";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
      count++;
      if (arr[i] == key)
      {
        found = true;
        break;
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
