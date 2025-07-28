#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// Dijkstra's algorithm for a finite simple graph
// Author: Nguyễn Ngọc Thạch
// This program finds the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.

using namespace std;

// Type alias for readability
using pii = pair<int, int>; // (distance, vertex)

// Function to perform Dijkstra's algorithm
// n: number of vertices (vertices are 0-indexed)
// adj: adjacency list where adj[u] = vector of pairs (v, w) meaning edge u-v with weight w
// src: source vertex
vector<int> dijkstra(int n, const vector<vector<pii>>& adj, int src) {
    vector<int> dist(n, numeric_limits<int>::max()); // Distance from src to each vertex
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap priority queue
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        // If we have already found a better path, skip
        if (d > dist[u]) continue;
        // Explore neighbors
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    cout << "Enter edges (u v w) for each edge (0-indexed vertices):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Since the graph is undirected
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    vector<int> dist = dijkstra(n, adj, src);
    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == numeric_limits<int>::max())
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << "\n";
    }
    return 0;
}