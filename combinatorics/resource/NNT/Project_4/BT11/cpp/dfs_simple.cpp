#include <iostream>
#include <vector>
#include <stack>

// Depth-first search algorithm for a finite simple graph
// Author: Nguyễn Ngọc Thạch
// This program performs DFS traversal on a simple graph starting from a given vertex.

using namespace std;

// Function to perform DFS using recursion
// adj: adjacency list representation of the graph
// visited: array to track visited vertices
// vertex: current vertex to visit
void dfs_recursive(const vector<vector<int>>& adj, vector<bool>& visited, int vertex) {
    visited[vertex] = true;
    cout << vertex << " "; // Print the current vertex
    
    // Visit all adjacent vertices
    for (int neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            dfs_recursive(adj, visited, neighbor);
        }
    }
}

// Function to perform DFS using stack (iterative approach)
// adj: adjacency list representation of the graph
// start: starting vertex for DFS
void dfs_iterative(const vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> s;
    
    // Push starting vertex onto stack
    s.push(start);
    
    while (!s.empty()) {
        int vertex = s.top();
        s.pop();
        
        if (!visited[vertex]) {
            visited[vertex] = true;
            cout << vertex << " "; // Print the current vertex
            
            // Push all unvisited neighbors onto stack
            // Note: We push in reverse order to maintain DFS order
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
    cout << "Enter edges (u v) for each edge (0-indexed vertices):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since the graph is undirected
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
