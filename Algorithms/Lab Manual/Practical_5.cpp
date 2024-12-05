/*Given a sorted array of positive integers, design an algorithm and implement it using a
program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].*/

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
    int flag = 0;
    int k = n - 1;
    while (k >= 2)
    {
      int i = 0, j = k - 1;
      while (i < j)
      {
        int sum = arr[i] + arr[j];
        if (sum == arr[k])
        {
          cout << "arr[" << i << "]+arr[" << j << "]=arr[" << k << "]";
          flag++;
          break;
        }
        else if (sum < arr[k])
          i++;
        else
          j--;
      }
      if (flag != 0)
        break;
      k--;
    }
    if (flag == 0)
      cout << "No Sequence Found.";
  }
  return 0;
}