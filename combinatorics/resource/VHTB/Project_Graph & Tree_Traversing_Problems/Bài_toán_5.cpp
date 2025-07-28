#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v, adj, visited);
    }
}

bool is_connected(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    dfs(0, adj, visited);
    for (bool v : visited)
        if (!v) return false;
    return true;
}

bool is_tree(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    function<bool(int)> dfs_tree = [&](int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                if (!dfs_tree(v)) return false;
            } else if (parent[u] != v)
                return false;
        }
        return true;
    };

    if (!dfs_tree(0)) return false;
    for (bool v : visited)
        if (!v) return false;
    return true;
}

int count_components(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            ++count;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> adj = {
        {1}, {0, 2}, {1}, {}
    };
    int n = 4;

    cout << "Connected: " << (is_connected(adj, n) ? "Yes" : "No") << "\n";
    cout << "Is Tree: " << (is_tree(adj, n) ? "Yes" : "No") << "\n";
    cout << "Components: " << count_components(adj, n) << "\n";
    return 0;
}
