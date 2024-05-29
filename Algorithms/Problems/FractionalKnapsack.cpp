#include <bits/stdc++.h>
using namespace std;

int main()
{
  // Input: Get knapsack capacity and number of items
  int k = 0;
  cout << "Enter the capacity of the sac: ";
  cin >> k;

  int n = 0;
  cout << "Enter the number of items: ";
  cin >> n;

  // Data Structure: Store items as pairs (value/weight ratio, weight)
  vector<pair<float, float>> item;

  // Input: Get value and weight for each item
  cout << "Enter the Value and Weight for each item respectively: " << endl;
  for (int i = 0; i < n; i++)
  {
    float value = 0, weight = 0;
    cin >> value;
    cin >> weight;
    float rate = value / weight; // Calculate value per unit weight (ratio)

    // Store the item as (ratio, weight) for sorting
    item.push_back({rate, weight});
  }

  // Sorting: Sort items in descending order of their value/weight ratio
  sort(item.begin(), item.end(), greater<pair<float, float>>());

  // Initialize: Current item index and total profit
  int i = 0, profit = 0;

  // Fractional Knapsack Algorithm
  while (i < n && k > 0)
  { // Continue while there are items left and space in knapsack
    // Check if the entire item can be included
    if (item[i].second <= k)
    {
      // Calculate profit from the whole item and round to the nearest integer
      int add = round(item[i].first * item[i].second);
      profit += add;
      k -= item[i].second; // Reduce knapsack capacity
    }
    else
    {
      // Calculate profit from the fraction that can be included
      int add = round(item[i].first * k);
      profit += add;
      k = 0; // Knapsack is full
    }
    i++; // Move to the next item
  }

  // Output: Display the maximum achievable profit
  cout << "Maximum Profit: " << profit;
  return 0;
}
