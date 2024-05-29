#include <bits/stdc++.h>
using namespace std;

// Function to build the Longest Proper Prefix Suffix (LPS) array for the pattern.
vector<int> buildlps(string p)
{
  int m = p.size();
  vector<int> lps(m, 0); // Initialize LPS array with all zeros.
  int len = 0;           // Length of the previous longest prefix suffix.
  int i = 1;

  while (i < m)
  {
    if (p[i] == p[len])
    {
      len++;        // Characters match, extend the prefix/suffix
      lps[i] = len; // Store the length of the longest prefix suffix
      i++;
    }
    else if (len != 0)
    {
      len = lps[len - 1]; // Mismatch, backtrack using the LPS array
    }
    else
    {
      lps[i] = 0; // No match, so LPS value is 0
      i++;
    }
  }
  return lps;
}

// Knuth-Morris-Pratt (KMP) string searching algorithm
int KMP(string str, string pattern)
{
  int n = str.size(), m = pattern.size();
  vector<int> lps = buildlps(pattern); // Build the LPS array

  int i = 0, j = 0, count = 0; // i: index for str, j: index for pattern
  while (i < n)
  {
    if (str[i] == pattern[j])
    {
      i++; // Move to the next character in both text and pattern
      j++;
    }

    // If pattern is found, increment count and reset pattern index using LPS
    if (j == m)
    {
      count++;
      j = lps[j - 1]; // Reset the pattern index (j) to the appropriate value using LPS
    }
    else if (i < n && str[i] != pattern[j])
    {
      // Mismatch: backtrack in pattern using the LPS array
      if (j != 0)
      {
        j = lps[j - 1]; // Move to the next potential partial match in the pattern
      }
      else
      {
        i++; // Move to the next character in the text
      }
    }
  }
  return count; // Return the number of occurrences of the pattern in the text
}

int main()
{
  // Get input from the user
  string str, pattern;
  cout << "Enter the original string: ";
  cin >> str;
  cout << "Enter the pattern: ";
  cin >> pattern;

  // Find and output the number of occurrences using KMP algorithm
  int ans = KMP(str, pattern);
  cout << "Number of occurrences: " << ans << endl;
  return 0;
}
