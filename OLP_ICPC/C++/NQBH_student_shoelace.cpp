#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, ans = 0;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bool found_sz1;
	vector<bool> kick(n + 1, false);
	for (int i = 1; i <= n; ++i)
		if (adj[i].empty()) kick[i] = true; // ignore lonely students
	queue<int> q;
	while (1) {
		found_sz1 = false;
		for (int i = 1; i <= n; ++i)
			if (!kick[i] && adj[i].size() == 1) {
				found_sz1 = true;
				q.push(i);
			}
		if (!found_sz1) break;
		else ++ans;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			if (kick[x]) continue;
			else kick[x] = true;
			int y = adj[x][0]; // only neighbor of x
			if (adj[y].size() == 1) kick[y] = true;
			else adj[y].erase(remove(adj[y].begin(), adj[y].end(), x), adj[y].end());
		}
	}
	cout << ans << '\n';
}