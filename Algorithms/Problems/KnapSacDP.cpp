#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the maximum value obtainable from items
int recur(const vector<pair<int, int>> &item, int i, int k, vector<vector<int>> &dp)
{
  // Base Case: No more items left (i < 0) or knapsack is full (k == 0)
  if (i < 0 || k == 0)
    return 0;

  // Check if the result for this subproblem is already calculated
  if (dp[i][k] != -1)
    return dp[i][k]; // Return the stored value

  // Recursive case:
  else
  {
    // Case 1: Exclude the current item (don't take it)
    int not_take = recur(item, i - 1, k, dp); // Calculate value without this item

    // Case 2: Take the current item (if it fits in the remaining capacity)
    int take = 0;
    if (k >= item[i].second)
    {
      take = item[i].first + recur(item, i - 1, k - item[i].second, dp);
      // Value of current item + value obtained with remaining items and reduced capacity
    }

    // Store the maximum of the two cases in the DP table and return it
    dp[i][k] = max(take, not_take);
    return dp[i][k];
  }
}

int main()
{
  // Input: Get knapsack capacity and number of items
  int k = 0;
  cout << "Enter the capacity of the Sac: ";
  cin >> k;

  int n = 0;
  cout << "Enter the number of items: ";
  cin >> n;

  // Data Structure: Store items as pairs (value, weight)
  vector<pair<int, int>> item;

  // Input: Get value and weight for each item
  cout << "Enter the value and weight of each item respectively: " << endl;
  for (int i = 0; i < n; i++)
  {
    int value = 0, weight = 0;
    cin >> value >> weight;
    item.push_back({value, weight});
  }

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1)); // Memoization table
  int ans = recur(item, n - 1, k, dp);                   // Call the recursive function

  cout << "Maximum Profit: " << ans;
  return 0;
}
