#include <iostream>
#include <vector>
#include <stack>

// Depth-first search algorithm for a general graph (repeated edges and loops allowed)
// Author: Nguyễn Ngọc Thạch
// This program performs DFS traversal on a general graph starting from a given vertex.

using namespace std;

// Recursive DFS for general graph
void dfs_recursive(const vector<vector<int>>& adj, vector<bool>& visited, int vertex) {
    visited[vertex] = true;
    cout << vertex << " ";
    for (int neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            dfs_recursive(adj, visited, neighbor);
        }
    }
}

// Iterative DFS for general graph
void dfs_iterative(const vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(start);
    while (!s.empty()) {
        int vertex = s.top();
        s.pop();
        if (!visited[vertex]) {
            visited[vertex] = true;
            cout << vertex << " ";
            for (int i = adj[vertex].size() - 1; i >= 0; --i) {
                int neighbor = adj[vertex][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
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
    cout << "\nDFS using recursion: ";
    vector<bool> visited(n, false);
    dfs_recursive(adj, visited, start);
    cout << endl;
    cout << "DFS using iteration: ";
    dfs_iterative(adj, start);
    cout << endl;
    return 0;
}
