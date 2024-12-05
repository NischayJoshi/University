/*Given an unsorted array of integers, design an algorithm and implement a program to
 sort this array using selection sort. Your program should also find number of
 comparisons and number of swaps required.*/

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

    int comp = 0, swap = 0;
    for (int i = 0; i < n - 1; i++)
    {
      int min = i;
      for (int j = i + 1; j < n; j++)
      {
        comp++;
        if (arr[j] < arr[min])
          min = j;
      }
      comp++;
      if (i != min)
      {
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        swap++;
      }
    }
    cout << "Sorted Array: ";
    for (int num : arr)
    {
      cout << num << " ";
    }
    cout << endl
         << "Comparisons: " << comp << "  and Swaps: " << swap;
  }
  return 0;
}