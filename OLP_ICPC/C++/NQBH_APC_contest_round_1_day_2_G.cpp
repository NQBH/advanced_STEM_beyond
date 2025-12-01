#include <bits/stdc++.h>
using namespace std;
const int MAX = 5000;

int n, m, depth[MAX], ans = 0;
vector<vector<int>> g(MAX + 1);
vector<bool> visited(MAX + 1, false);

// DFS with depth
void dfs(int u, int p, int d) { // p : parent of u
	visited[u] = true;
	depth[u] = d;
	for (int v : g[u]) {
		if (v == p) continue; // skip
		if (visited[v]) { // visit u again: cycle
			if (depth[u] > depth[v]) ans = max(ans, depth[u] - depth[v] + 1);
		} else dfs(v, u, d + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int u, v;
	cin >> n >> m;	
	while (m--) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		if (!visited[i]) dfs(i, -1, 0);
	cout << ans;
}