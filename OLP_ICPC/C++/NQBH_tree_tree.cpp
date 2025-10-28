#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> sz;

void dfs_sz(int v, int parent) {
	sz[v] = 1;
	for (int child : g[v]) {
		if (child == parent) continue;
		dfs_sz(child, v);
		sz[v] += sz[child];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		g.assign(n + 1, {});
		sz.assign(n + 1, 0);
        dfs_sz(1, 1);
        ll ans = 0;
        for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int v = 1; v <= n; ++v) { // v: root
			ll cnt = 0;
			if (n >= k) ++cnt;
			for (int c : g[v])
				if (sz[c] >= k) cnt += sz[c];
			cout << cnt << ' '; // debug
			ans += cnt;		
		}
		cout << ans << '\n';
	}
}