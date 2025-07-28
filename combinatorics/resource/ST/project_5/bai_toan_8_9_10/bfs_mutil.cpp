#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Nhap do thi
void input_multigraph(int& n, vector<vector<int>>& adj) {
    int m;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cout << "Nhap canh u v (co the trung): ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Do thi vo huong, trung canh
    }
}

// BFS
void bfs_multigraph(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "Thu tu duyet: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n;
    vector<vector<int>> adj;
    input_multigraph(n, adj);
    int s;
    cout << "Nhap dinh bat dau: ";
    cin >> s;
    bfs_multigraph(s, adj, n);
    return 0;
}