#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

void input_graph(int& n, vector<vector<int>>& adj, bool& directed) {
    int m;
    cout << "Nhap so dinh: ";
    cin >> n;
    cout << "Nhap so canh: ";
    cin >> m;
    cout << "Do thi co huong? (y/n): ";
    string ans; cin >> ans;
    directed = (ans == "y" || ans == "Y");
    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cout << "Nhap canh u v: ";
        cin >> u >> v;
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }
}

void bfs_general(int start, const vector<vector<int>>& adj, int n) {
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
    bool directed;
    vector<vector<int>> adj;
    input_graph(n, adj, directed);
    int s;
    cout << "Nhap dinh bat dau: ";
    cin >> s;
    bfs_general(s, adj, n);
    return 0;
}