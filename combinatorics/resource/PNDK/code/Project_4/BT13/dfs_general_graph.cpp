#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void read_general_graph(const string& filename, int& n, vector<vector<int>>& adj) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Cannot open file: " << filename << endl;
        exit(1);
    }
    int m;
    fin >> n >> m;
    adj.assign(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        if (u != v) adj[v].push_back(u); // vô hướng
    }
    fin.close();

    for (int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
}

void dfs_from(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent, vector<int>& dfs_order) {
    visited[u] = true;
    dfs_order.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs_from(v, adj, visited, parent, dfs_order);
        }
    }
}

int main() {
    int n;
    vector<vector<int>> adj;
    read_general_graph("general_graph.inp", n, adj);

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> dfs_order;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs_from(i, adj, visited, parent, dfs_order);
        }
    }

    cout << "DFS forest order (general graph): ";
    for (int v : dfs_order) cout << v << " ";
    cout << "\nParent array: ";
    for (int p : parent) cout << p << " ";
    cout << "\n";

    return 0;
}
