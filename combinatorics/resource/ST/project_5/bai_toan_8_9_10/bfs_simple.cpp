#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Ham nhap do thi
void input_graph(int& n, vector<vector<int>>& adj) {
    int m;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cout << "Nhap canh u v: ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Vo huong
    }
}

// Ham BFS
void bfs(int start, vector<vector<int>>& adj, int n) {
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
    input_graph(n, adj);
    int s;
    cout << "Nhap dinh bat dau: ";
    cin >> s;
    bfs(s, adj, n);
    return 0;
}