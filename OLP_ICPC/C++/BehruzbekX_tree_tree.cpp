#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	using ll = long long;
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int>> a(n);
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v, --u, --v;
			a[u].emplace_back(v);
			a[v].emplace_back(u);
		}
		ll ans = 0;
		vector<int> sz(n, 1); // initial subtree sizes
		auto dfs = [&] (auto &dfs, int v, int p) -> void { // performing DFS in the tree
			for (int u : a[v]) {
				if (u != p) { // to avoid visiting parent again
					dfs(dfs, u, v); // recursively visit subtree
					sz[v] += sz[u]; // merge
				}
			}
		};
		/*
            |S_1| = (sz[1] >= k) + (sz[2] >= k) + ... (sz[n] >= k) (root is 1)
            |S_2| = (sz[1] >= k) + (sz[2] >= k) + ... (sz[n] >= k) (root is 2)
            |S_3| = (sz[1] >= k) + (sz[2] >= k) + ... (sz[n] >= k) (root is 3)
            ...                                                    (root is i)
            |S_n| = (sz[1] >= k) + (sz[2] >= k) + ... (sz[n] >= k) (root is n)
            We should add them for each node (calculating contribution):
        */
        dfs(dfs, 0, -1); // Arbitrary starting point
        for (int i = 0; i < n; ++i) cout << sz[i] << ' ';
        cout << '\n';
        for (int i = 0; i < n; ++i) {
        	if (n - sz[i] >= k) ans += sz[i];
        	if (sz[i] >= k) ans += n - sz[i];
        }
        cout << ans + n << '\n';
	}
}