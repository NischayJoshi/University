/*Given an unsorted array of integers, design an algorithm and a program to sort the array
 using insertion sort. Your program should be able to find number of comparisons and
 shifts ( shifts- total number of times the array elements are shifted from their place)
 required for sorting the array*/

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
    cout << "\n\nEnter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    int comp = 1, shift = 0;
    for (int i = 1; i < n;i++)
    {
      int temp = arr[i];
      int j = i - 1;
      while(j>=0 && arr[j]>temp)
      {
        comp++;
        arr[j + 1] = arr[j];
        shift++;
        j--;
      }
      arr[j + 1] = temp;
      shift++;
    }
    cout << "Sorted Array: ";
    for (int num: arr)
    {
      cout << num << " ";
    }
    cout << endl
         << "Comparisons: " << comp << "  and Shifts: " << shift;
  }
  return 0;
}