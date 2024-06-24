#include <bits/stdc++.h> // Include all standard C++ headers for convenience
using namespace std;

// Recursive function to calculate the number of occurrences of string B as a subsequence of string A
int recur(string A, string B, int i, int j, vector<vector<int>> &memo)
{
  // Base Case: If the end of either string is reached, no subsequence can be formed
  if (i >= A.size() || j >= B.size())
    return 0;

  // Memoization: Check if this subproblem has already been solved
  if (memo[i][j] != -1)
    return memo[i][j];

  // If characters at current indices match
  if (A[i] == B[j])
  {
    // Result is 1 (for this match) + result of matching the remaining parts of the strings
    memo[i][j] = 1 + recur(A, B, i + 1, j + 1, memo);
  }
  else
  {
    // Characters don't match, find the maximum of:
    // - Skipping the current character in A
    // - Skipping the current character in B
    memo[i][j] = max(recur(A, B, i + 1, j, memo), recur(A, B, i, j + 1, memo));
  }

  // Return the result
  return memo[i][j];
}

int main()
{
  string A = "thisis"; // String to search in
  string B = "is";     // Subsequence to search for

  // Initialize a memoization table with -1 (indicating results not yet calculated)
  vector<vector<int>> memo(A.size(), vector<int>(B.size(), -1));

  // Call the recursive function to get the count of subsequences
  int subseq = recur(A, B, 0, 0, memo);

  cout << subseq; // Print the count
  return 0;
}
