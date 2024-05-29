#include <bits/stdc++.h>
using namespace std;

// Function to calculate the nth Fibonacci number using memoization
int fibonacci(int n, vector<int> &memo)
{
  // Base cases for the first three Fibonacci numbers (0, 1, 1)
  if (n <= 1)
  {
    return n;
  }

  // Check if the result for 'n' is already calculated and stored in 'memo'
  if (memo[n] != -1)
  {
    return memo[n]; // Return the stored value
  }

  // Recursive case: Calculate fib(n) = fib(n-1) + fib(n-2)
  // Store the result in 'memo[n]' for future use (memoization)
  int fib = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
  memo[n] = fib;

  return fib;
}

int main()
{
  // Get the length of the desired Fibonacci series from the user
  int n = 0;
  cout << "Enter the length of Fibonacci Series: ";
  cin >> n;

  // Create a vector 'memo' to store calculated Fibonacci numbers
  // Initialize with -1 to indicate not yet calculated
  vector<int> memo(n + 1, -1);

  // Display the Fibonacci series
  cout << "Fibonacci Series: ";
  for (int i = 0; i < n; i++)
  {
    // Start from index 0 for a complete series
    int answer = fibonacci(i, memo);
    cout << answer << " ";
  }

  return 0;
}
