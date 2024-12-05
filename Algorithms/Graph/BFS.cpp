#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS traversal on a graph
void bfs(vector<vector<int>> adjlist, int source, vector<bool> &visited)
{
  // Mark the source node as visited
  visited[source] = true;

  // Create a queue to manage the order of node exploration
  queue<int> que;

  // Start by enqueueing the source node
  que.push(source);

  // Iterate while the queue is not empty
  while (!que.empty())
  {
    // Dequeue the node at the front of the queue (current node)
    int curr = que.front();
    que.pop();

    // Print the current node's label/value
    cout << curr << " ";

    // Iterate over all the neighbors of the current node
    for (int neigh : adjlist[curr])
    {
      // If the neighbor hasn't been visited yet
      if (visited[neigh] == false)
      {
        // Mark the neighbor as visited
        visited[neigh] = true;

        // Enqueue the neighbor for future processing
        que.push(neigh);
      }
    }
  }
}

int main()
{
  // Get the number of nodes in the graph
  int n = 0;
  cout << "Enter the number of nodes: ";
  cin >> n;

  // Create an adjacency list representation of the graph
  vector<vector<int>> adjlist(n);

  // Get the number of edges in the graph
  int m = 0;
  cout << "Enter the number of edges: ";
  cin >> m;

  // Get edge information (node pairs) from the user
  cout << "Enter the node pair for each edge: " << endl;
  for (int i = 0; i < m; i++)
  {
    int node1 = 0, node2 = 0;
    cin >> node1 >> node2;
    adjlist[node1].push_back(node2); // Add edges to adjacency list
    adjlist[node2].push_back(node1);
  }

  // Create a vector to keep track of visited nodes (initially all false)
  vector<bool> visited(n, false);

  // Perform BFS traversal starting from node 0
  cout << "BFS Traversal of the graph is as follow: " << endl;
  bfs(adjlist, 0, visited);
  return 0;
}
