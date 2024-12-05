/*Given an array of nonnegative integers, design an algorithm and a program to count the
 number of pairs of integers such that their difference is equal to a given key, K.*/

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
    cout << "\n\nEnter size of srray: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int key = 0, count = 0;
    cout << "Enter the key value: ";
    cin >> key;
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (abs(arr[j] - arr[i]) == key)
          count++;
      }
    }
    cout << "Number of Pairs: " << count;
  }
  return 0;
}