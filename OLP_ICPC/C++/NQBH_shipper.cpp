#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

int dijkstra(int n, vector<vector<vector<int>>> &adj, int src, int des) {
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	vector<int> dist(n, INT_MAX);
	pq.push({0, src});
	dist[src] = 0;
	while (!pq.empty()) {
		int u = pq.top()[1];
		pq.pop();
		for (auto x : adj[u]) {
			int v = x[0];
			int weight = x[1];
			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push({dist[v], v});
			}
		}
	}
	return dist[des];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	// vector<int> V(n);
	// for (int i = 0; i < n; ++i) V[i] = i;
	vector<vector<vector<int>>> adj(n);
	for (int i = 1; i <= m; ++i) {
		int u, v, t;
		cin >> u >> v >> t;
		--u;
		--v;
		adj[u].push_back({v, t});
		adj[v].push_back({u, t});
	}
	for (int i = 1; i <= q; ++i) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		ll ans = 0;
		ans = dijkstra(n, adj, x, y);
		cout << ans << '\n';
	}
}