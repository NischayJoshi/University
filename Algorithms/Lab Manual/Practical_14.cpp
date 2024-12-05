// Given an unsorted array of integers, design an algorithm and implement it
// using a program to find whether two elements exist such that their sum is
// equal to the given key element.(Time Complexity = O(n log n))

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, vector<pair<int, int>> &ans, int key)
{
  int n = v.size();
  int i = 0, j = n - 1;
  int flag = 0;
  sort(v.begin(), v.end());
  while (i < j)
  {
    if ((v[i] + v[j]) == key)
    {
      flag = 1;
      ans.push_back(make_pair(v[i], v[j]));
      break;
    }
    else if ((v[i] + v[j]) > key)
      j--;
    else
      i++;
  }
  if (flag == 0)
    ans.push_back(make_pair(-1, -1));
}

int main()
{
  int T;
  cin >> T;
  vector<pair<int, int>> ans;
  int it = 0;
  while (T--)
  {
    cout << endl;
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    int key;
    cout << "Enter Key: ";
    cin >> key;
    solve(v, ans, key);
    v.clear();

    if (ans[it].first == -1)
      cout << "No Such Element Exists" << endl;
    else
      cout << "The pair : " << ans[it].first << " " << ans[it].second << endl;
    it++;
  }
  return 0;
}
