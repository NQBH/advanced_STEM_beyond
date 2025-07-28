#include <iostream>
#include <vector>
using namespace std;

void dfs_multigraph(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v])
            dfs_multigraph(v, adj, visited);
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 1, 2},
        {0, 0, 2},
        {0, 1, 2},
        {}
    };

    int n = graph.size();
    vector<bool> visited(n, false);
    cout << "DFS traversal: ";
    dfs_multigraph(0, graph, visited);
    cout << endl;

    return 0;
}
