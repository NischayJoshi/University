#include <bits/stdc++.h>
using namespace std;

int main()
{
  // Input: Get the number of jobs
  int n, m = 0; // m will store the maximum deadline
  cout << "Enter the number of Jobs: ";
  cin >> n;

  // Input: Get profit and deadline for each job
  cout << "Enter the Profit and Deadline of each job respectively: " << endl;
  vector<pair<int, int>> job; // Store jobs as (profit, deadline) pairs

  for (int i = 0; i < n; i++)
  {
    int profit = 0;
    cin >> profit;
    int deadline = 0;
    cin >> deadline;

    // Update the maximum deadline (m) if needed
    m = max(m, deadline);

    // Store the job details in the vector
    job.push_back({profit, deadline});
  }

  // Sorting: Sort jobs in descending order of profit
  sort(job.begin(), job.end(), greater<pair<int, int>>());

  // Initialize: Create a vector to track time slots, initially all empty (0)
  int profit = 0; // Total profit
  vector<int> time(m, 0);

  // Job Sequencing Algorithm
  for (auto itr : job)
  {
    // Get the deadline and calculate the index of the corresponding time slot
    int j = itr.second - 1;

    // Find the latest available time slot before the deadline
    while (j >= 0 && time[j] == 1)
    {
      j--;
    }

    // If an available time slot is found, schedule the job
    if (j >= 0)
    {
      time[j] = 1;         // Mark the slot as filled
      profit += itr.first; // Add the job's profit
    }
  }

  // Output: Display the maximum achievable profit
  cout << "Maximum Profit: " << profit;
  return 0;
}
