// Given an unsorted array of alphabets containing duplicate elements.
// Design an algorithm and implement it using a program to find which alphabet has a
// maximum number of occurrences and print it.(Time Complexity = O(n))(Hint : Use counting sort)

#include <bits/stdc++.h>
using namespace std;
void countSort(vector<char> &arr)
{
  vector<int> helper(26, 0);
  for (auto itr : arr)
  {
    helper[itr - 'a']++;
  }
  int maxCount = 0;
  char maxChar = '\0';
  for (int i = 0; i < 26; i++)
  {
    if (helper[i] > maxCount)
    {
      maxCount = helper[i];
      maxChar = i + 'a';
    }
  }
  if (maxCount == 1)
    cout << "No Duplicates Present" << endl;
  else
    cout << maxChar << "-" << maxCount<<endl;
}
int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    cout << endl;
    vector<char> arr;
    int v;
    cin >> v;
    while (v--)
    {
      char ch;
      cin >> ch;
      arr.push_back(ch);
    }
    countSort(arr);
  }
}
