#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the maximum profit
int recur(const vector<pair<int, int>> &item, int index, int cap)
{
  // Base cases: No more items or no capacity left
  if (index < 0 || cap == 0)
  {
    return 0; // No profit possible
  }

  // Recursive case: Explore two options - take or not take the current item
  int not_take = recur(item, index - 1, cap); // Don't include the current item

  // Initialize profit if taking the current item
  int take = 0;

  // Check if the item's weight is within the remaining capacity
  if (item[index].second <= cap)
  {
    // Calculate profit with the current item and the remaining capacity
    take = item[index].first + recur(item, index - 1, cap - item[index].second);
  }

  // Return the maximum of the two possibilities (take or not take)
  return max(not_take, take);
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

  // Start recursion from the last item with the full knapsack capacity
  int ans = recur(item, n - 1, k);

  // Output: Display the maximum achievable profit
  cout << "Maximum Profit: " << ans;
  return 0;
}
