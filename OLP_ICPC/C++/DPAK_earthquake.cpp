#include <bits/stdc++.h>
#define int long long
using namespace std;
int p, c, n;
const int MAXP = 30005;
set<int> adj[30005];
vector<int> report(MAXP, 0);
vector<bool> visited(MAXP, false);
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> p >> c >> n;
    for (int i = 1; i <= c; i++) {
        int u, v; cin >> u >> v;
        if (u == v) continue;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        for (auto v : adj[u]) {
            report[v] = 1;
        }
    }
    queue<int> q; q.push(1);
    visited[1] = true;

    int res = 0;

    while(q.empty() == false) {
        int u = q.front(); q.pop();
        res++;
        for (auto v : adj[u]) {
            if (visited[v] == false && report[v] == 0) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    int ans = p - res;
    cout << ans;

    return 0;
}