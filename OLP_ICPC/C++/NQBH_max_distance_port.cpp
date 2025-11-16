#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max(); // Represents infinity

// Function to implement Dijkstra's algorithm
vector<int> dijkstra(int numVertices, const vector<vector<int>>& adj, int startNode) {
	vector<int> dist(numVertices, INF); // Initialize distances to infinity
	dist[startNode] = 0; // Distance to source is 0

	// Priority queue to store pairs of (distance, vertex)
	// pair<int, int> stores (distance, vertex_index)
	// The default priority_queue is a max-heap, so we use greater to make it a min-heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, startNode}); // Push the source node with distance 0

	while (!pq.empty()) {
		int d = pq.top().first; // Current shortest distance to 'u'
		int u = pq.top().second; // Current vertex 'u'
		pq.pop();

		// If we found a shorter path to 'u' already, skip this
		if (d > dist[u]) continue;

		// Explore neighbors of 'u'
		for (const int& v : adj[u]) {
			// If a shorter path to 'v' is found through 'u'
			if (dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				pq.push({dist[v], v});
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), ans(k + 1, 0);
	for (int &x : a) cin >> x;
	vector<vector<int>> adj(n, {0});
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> shortestDistances = dijkstra(n, adj, 0);
	for (int i = 0; i < n; ++i) ans[a[i]] = max(ans[a[i]], shortestDistances[i]);
	for (int i = 1; i <= k; ++i) cout << ans[i] << ' ';
	cout << '\n';
}