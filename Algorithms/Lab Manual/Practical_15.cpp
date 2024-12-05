// You have been given two sorted integer arrays of size m and n.
// Design an algorithm and implement it using a program to find list of
// elements which are common to both.(Time Complexity = O(m + n))

#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
  vector<int> ans;
  int i = 0, j = 0;

  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());

  while (i != m && j != n)
  {
    if (arr1[i] == arr2[j])
    {
      ans.push_back(arr1[i]);
      i++;
      j++;
    }
    else if (arr1[i] < arr2[j])
      i++;
    else
      j++;
  }
  return ans;
}

int main()
{

  int m, n;
  cout << "Number of elements in first array: ";
  cin >> m;
  cout << "Enter the elements of first array: ";
  vector<int> arr1(m);
  for (int i = 0; i < m; i++)
  {
    cin >> arr1[i];
  }
  cout << "Number of elements in second array: ";
  cin >> n;
  cout << "Enter the elements of second array: ";
  vector<int> arr2(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr2[i];
  }

  vector<int> ans = commonElements(arr1, arr2, m, n);
  if (ans.size() == 0)
    cout << "No Common Element" << endl;
  else
  {
    cout << "Common elements in both arrays: ";
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
  }
  return 0;
}
