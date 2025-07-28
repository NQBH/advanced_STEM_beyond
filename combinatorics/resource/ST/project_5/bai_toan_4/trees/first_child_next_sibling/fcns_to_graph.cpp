#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, const vector<int>& fc, const vector<int>& ns,
         vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;

    if (fc[u] != -1) {
        int v = fc[u];
        adj[u].push_back(v);
        adj[v].push_back(u);
        dfs(v, fc, ns, adj, visited);
    }

    if (ns[u] != -1) {
        int v = ns[u];
        adj[u].push_back(v);
        adj[v].push_back(u);
        dfs(v, fc, ns, adj, visited);
    }
}

int main() {
    int n;
    cout << "Nhap so nut: ";
    cin >> n;

    vector<int> fc(n), ns(n);
    cout << "Nhap mang fc:\n";
    for (int i = 0; i < n; ++i) cin >> fc[i];
    cout << "Nhap mang ns:\n";
    for (int i = 0; i < n; ++i) cin >> ns[i];

    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    dfs(0, fc, ns, adj, visited);

    cout << "Danh sach ke (Graph):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : adj[i])
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}