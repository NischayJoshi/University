// Given a graph, design an algorithm and implement it using a program to find 
// if a graph is bipartite or not .(Hint : use BFS)

#include <bits/stdc++.h>
using namespace std;
bool isBipartite(vector<vector<int>> &g, int V, int node, vector<int> &color)
{
  queue<int> q;
  q.push(node);
  color[node] = 1;
  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    for (int ele : g[curr])
    {
      if (color[ele] == color[curr])
        return false;
      if (color[ele] == -1)
      {
        color[ele] = 1 - color[curr];
        q.push(ele);
      }
    }
  }
}

bool bipartite(vector<vector<int>> &g, int V)
{
  vector<int> color(V + 1, -1);
  for (int i = 1; i <= V; i++)
  {
    if (color[i] == -1)
    {
      if (!isBipartite(g, V, i, color))
        return false;
    }
  }
  return true;
}

int main()
{
  int V, E;
  cin >> V >> E;
  vector<vector<int>> g(V + 1);
  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(u);
  }

  if (bipartite(g, V))
    cout << "Bipartite" << endl;
  else
    cout << "Not Bipartite" << endl;
  return 0;
}
