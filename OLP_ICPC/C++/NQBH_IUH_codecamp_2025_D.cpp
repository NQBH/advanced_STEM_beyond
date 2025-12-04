#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
const int MAXN = 200001;

vector<int> a(MAXN), adj[MAXN];
int n, dist[MAXN], up[MAXN][20]; // distance from starting vertex: start from a leaf better

pair<int, int> bfs(int start) {
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	int farthest_node = start, max_dist = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (dist[u] > max_dist) {
			max_dist = dist[u];
			farthest_node = u;
		}
		for (int v : adj[u])
			if (dist[v] == -1) { // unvisited
				dist[v] = dist[u] + 1;
				q.push(v);
			}
	}
	return {farthest_node, max_dist};
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, u, v;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// this works for day 1 or m = 1 in particular
	pair<int, int> p1 = bfs(1); // farthest vertex from vertex 1
	int A = p1.first;
	pair<int, int> p2 = bfs(A);
	int diam = p2.second;
	cout << 2 * (n - 1) - diam; // formula of shortest path on a tree
	if (m == 1) return 0;
	// day 2 to m
	vector<int> b; // contain all vertices needed for current day to pass through
	for (int x = 2; x <= m; ++x) { // day i
		b.clear();
		for (int i = 1; i <= n; ++i)
			if (a[i] % x == 0) b.push_back(i);
		if (b.size() <= 1) cout << "0\n";
		else {
			cout << b.size() - 1 << '\n';
		}
	}
}