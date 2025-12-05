#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
const int LOG = 18;

vector<pair<int, int>> adj[MAXN];
int n, q, up[MAXN][LOG],  lvl[MAXN]; // up[u][i]: ancestor 2^i-th of u
ll dist[MAXN];

void dfs(int u, int p, int l, ll d) {
	lvl[u] = l;
	dist[u] = d;
	up[u][0] = p; // 2^0: direct parent
	for (int i = 1; i < LOG; ++i) up[u][i] = up[up[u][i - 1]][i - 1];
	for (auto &e : adj[u]) {
		int v = e.first, w = e.second;
		if (v != p) dfs(v, u, l + 1, d + w);
	}
}

int lca(int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);
	for (int i = LOG - 1; i >= 0; --i)
		if (lvl[u] - (1 << i) >= lvl[v]) u = up[u][i];
	if (u == v) return u;
	for (int i = LOG - 1; i >= 0; --i)
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	return up[u][0];
}

int get_kth_ancestor(int v, int k) {
	for (int i = 0; i < LOG; ++i)
		if ((k >> i) & 1) v = up[v][i];
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }
    dfs(1, 1, 0, 0);
    while (q--) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		int x, y;
    		cin >> x >> y;
    		int a = lca(x, y);
    		ll ans = dist[x] + dist[y] - 2 * dist[a];
    		cout << ans << '\n';
    	} else {
    		int x, y, k;
    		cin >> x >> y >> k;
    		int a = lca(x, y);
    		int node_left = lvl[x] - lvl[a] + 1;
    		if (k <= node_left) cout << get_kth_ancestor(x, k - 1) << '\n';
    		else {
    			int all_node = lvl[x] + lvl[y] - 2 * lvl[a] + 1;
    			cout << get_kth_ancestor(y, all_node - k) << '\n';
    		}
    	}
    }
}