#include <iostream>
#include <vector>
#include <string>
using namespace std;

void input_multigraph(int& n, vector<vector<int>>& adj, bool& directed) {
    int m;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh (co the trung): ";
    cin >> m;
    cout << "Do thi co huong? (y/n): ";
    string s; cin >> s;
    directed = (s == "y" || s == "Y");
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cout << "Nhap canh u v: ";
        cin >> u >> v;
        adj[u].push_back(v);
        if (!directed)
            adj[v].push_back(u);
    }
}

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v, adj, visited);
    }
}

int main() {
    int n;
    bool directed;
    vector<vector<int>> adj;
    input_multigraph(n, adj, directed);
    vector<bool> visited(n, false);
    int s;
    cout << "Nhap dinh bat dau: ";
    cin >> s;
    cout << "Thu tu duyet: ";
    dfs(s, adj, visited);
    return 0;
}