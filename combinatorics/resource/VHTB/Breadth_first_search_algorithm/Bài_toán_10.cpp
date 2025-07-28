#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs_component(int start, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& comp) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        comp.push_back(u);
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void bfs_general(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int component_id = 1;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> comp;
            bfs_component(i, adj, visited, comp);
            cout << "Component " << component_id++ << ": ";
            for (int v : comp) cout << v << " ";
            cout << "\n";
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 1},
        {0, 2},
        {1, 2},
        {},
        {5},
        {4}
    };

    cout << "All BFS components:\n";
    bfs_general(graph);

    return 0;
}
