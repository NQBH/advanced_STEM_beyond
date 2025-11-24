#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, u, v, ans = 0;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> deg(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		++deg[u];
		++deg[v];
	}
	queue<int> q;
	vector<bool> rm(n + 1, false);
	for (int i = 1; i <= n; ++i)
		if (deg[i] < 2) {
			q.push(v);
			rm[i] = true;
		}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : g[u]) {
			if (rm[v]) continue;
			--deg[v];
			if (deg[v] < 2) {
				rm[v] = 1;
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!rm[i]) ++ans;
	cout << ans << '\n';
}