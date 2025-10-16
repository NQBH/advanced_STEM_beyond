#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5, LOG = 17;

int n, q;
vector<int> adj[MAXN];
int up[MAXN][LOG + 1], depth[MAXN];
// up[u][i]: to tien thu 2^i cua u
// depth[i]: do sau tu root (1) toi i

void dfs(int u, int p) {
    up[u][0] = p; // parent
    for (int i = 1; i <= LOG; ++i)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = LOG; i >= 0; --i)
        if (diff & (1 << i))
            a = up[a][i];
    if (a == b) return a;
    for (int i = LOG; i >= 0; --i)
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    return up[a][0];
}

int dist(int a, int b) {
    int L = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[L];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (dist(x, z) == dist(x, y) + dist(y, z)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}