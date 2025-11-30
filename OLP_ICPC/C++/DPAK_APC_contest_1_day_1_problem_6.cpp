#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200005];

int main() {
    int n, m; cin >> n >> m;
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    queue<int> q;
    vector<char> removed(n + 1, false);

    for (int u = 1; u <= n; u++) if (deg[u] <= 1) q.push(u);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (removed[u]) continue;
        removed[u] = true;
        for (int v : adj[u]) {
            if (removed[v]) continue;
            if (--deg[v] == 1) q.push(v);
        }
    }

    int ans = 0;
    for (int u = 1; u <= n; ++u)
        if (!removed[u]) ans++;

    cout << ans;
    return 0;
}

/*
Đại loại là sẽ pop các đỉnh có bậc <= 1, sau khi loại, tính lại bậc của các đỉnh bị ảnh hưởng, nếu bậc <= 1 --> tiếp tục loại đến khi nào ko còn đỉnh bị ảnh hưởng (tất cả bậc đều > 1) 
*/
