#include<bits/stdc++.h>
using namespace std;

vector<int> bellman(vector<vector<int>> edge, int v, int source)
{
  vector<int> dist(v, INT_MAX);
  dist[source] = 0;
  for (int i = 0; i < v - 1;i++)
  {
    for (int j = 0; j < edge.size();j++)
    {
      for(auto ed: edge)
      {
        int u = ed[0];
        int v = ed[1];
        int wt = ed[2];

        if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
          dist[v] = dist[u] + wt;
      }
    }
  }
  return dist;
}