#include <bits/stdc++.h>
using namespace std;

int main()
{
  // Input: Get the number of activities from the user
  int n;
  cout << "Enter the number of activities: ";
  cin >> n;

  // Data Structure: Store activity information as pairs (end time, start time)
  vector<pair<int, int>> activity;
  cout << "Enter the starting and ending times of each activity respectively: " << endl;

  // Input: Get starting and ending times for each activity
  for (int i = 0; i < n; i++)
  {
    int start = 0, end = 0;
    cin >> start >> end;

    // Store the activity with end time as the first element (for easy sorting)
    activity.push_back({end, start});
  }

  // Sorting: Sort activities based on their ending times (ascending)
  sort(activity.begin(), activity.end());

  // Initialize: Track the ending time of the last selected activity
  int end = -1;
  int count = 0; // Count the number of activities selected

  // Activity Selection Algorithm
  for (auto act : activity)
  {
    // Check if the current activity's start time is after or equal to the last selected activity's end time
    if (act.second >= end)
    {                  // act.second represents start time
      count++;         // Increment the count of selected activities
      end = act.first; // Update the ending time of the last selected activity
    }
  }

  // Output: Display the maximum number of activities that can be done
  cout << "Maximum number of activities : " << count;
  return 0;
}
