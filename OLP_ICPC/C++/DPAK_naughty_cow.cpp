#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> adj[1005];
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (visited[v] == true) continue;
            visited[v] = true;
            q.push(v);
        }
    }
    int flag = 0;
    for (int i = 2; i <= n; i++) {
        if (visited[i] == false) {
            cout << i << " ";
            flag = 1;
        }
    }
    if (flag == 0) cout << 0;
}