#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs(v, adj, visited);
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    // Sửa: input 1-based thành 0-based
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> reps;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            reps.push_back(i);
        }
    }

    cout << reps.size() - 1 << '\n';
    // Sửa: dùng size_t và xuất output 1-based
    for (size_t i = 1; i < reps.size(); i++) {
        cout << reps[i - 1] + 1 << " " << reps[i] + 1 << '\n';
    }
    return 0;
}
