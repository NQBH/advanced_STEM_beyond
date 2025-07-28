#include <iostream>
#include <vector>
#include <queue>

// Breadth-first search algorithm for a general graph (repeated edges and loops allowed)
// Author: Nguyễn Ngọc Thạch
// This program performs BFS traversal on a general graph starting from a given vertex.

using namespace std;

// BFS function for general graph
void bfs(const vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";
        for (int neighbor : adj[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v) for each edge (0-indexed vertices, loops and repeated edges allowed):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected general graph: add both directions, including loops
    }
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    cout << "BFS traversal: ";
    bfs(adj, start);
    cout << endl;
    return 0;
}
