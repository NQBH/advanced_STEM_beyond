#include <iostream>
#include <vector>
using namespace std;

void dfs_component(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& comp) {
    visited[u] = true;
    comp.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v])
            dfs_component(v, adj, visited, comp);
    }
}

void general_dfs(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int comp_id = 1;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> comp;
            dfs_component(i, adj, visited, comp);
            cout << "Component " << comp_id++ << ": ";
            for (int v : comp) cout << v << " ";
            cout << "\n";
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 1},
        {1, 2},
        {},
        {5},
        {4}
    };

    general_dfs(graph);
    return 0;
}
