#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 1;

vector<int> parent(MAXN, 0);
vector<ll> h(MAXN, 0), d(MAXN, 0); // parent[u] = p if p is parent of u
vector<vector<pair<int, int>>> adj(MAXN);

void dfs(int u) {
	for (auto e : adj[u]) {
		int v = e.first, l = e.second;
		if (v == parent[u]) continue;
		d[v] = d[u] + 1;
		h[v] = h[u] + l;
		parent[v] = u;
		dfs(v);
	}
}

// source: https://wiki.vnoi.info/algo/data-structures/lca-binlift.md
int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	while (h[u] > h[v]) u = parent[u];
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q, u, v, w;
	cin >> n >> q;
	
	for (int i = 1; i < n; ++i) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs(1);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, y;
			cin >> x >> y;
			cout << (ll)(h[x] + h[y] - 2 * h[lca(x, y)]) << '\n';
		} else {
			int x, y, k;
			cin >> x >> y >> k;
			int a = lca(x, y);
			if (d[x] - d[a] + 1 >= k) {
				for (int i = 1; i < k; ++i) x = parent[x];
				cout << x << '\n';
			} else {
				int step = d[x] + d[y] - 2 * d[a] + 1 - k;
				for (int i = 1; i <= step; ++i) y = parent[y];
				cout << y << '\n';
			}
		}
	}
}