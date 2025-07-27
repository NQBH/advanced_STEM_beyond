#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v; // 0-based indexing
		// adjacency list represented as a bitmask
		adj[u] |= (1 << v);
		adj[v] |= (1 << u);
	}
	vector<int> dp(1 << n, INT32_MAX);
	for (int mask = 0; mask < (1 << n); ++mask) {
		bool connected = true;
		for (int u = 0; u < n; ++u)
			if (((mask >> u) & 1) != 0)
				// check if u is connected to all other nodes in mask
				if (((adj[u] | (1 << u)) & mask) != mask) {
					connected = false;
					break;
				}
		if (connected) dp[mask] = 1;
	}
	for (int mask = 0; mask < (1 << n); ++mask)
		for (int submask = mask; submask; submask = (submask - 1) & mask) {
			int subset = mask ^ submask;
			// submask has everything in mask but not in subset
			if (dp[subset] != INT32_MAX && dp[submask] != INT32_MAX)
				dp[mask] = min(dp[mask], dp[subset] + dp[submask]);
		}
	cout << dp[(1 << n) - 1] << '\n';
}