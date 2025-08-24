#include <iostream>
#include <vector>
using namespace std;

// int n, q, a[N], parent[N], sz[N], color[N][N];
int n, q;
vector<int> a, parent, sz, not_merge_color;
vector<vector<int>> color;

void make_set_size(int i) {
	parent[i] = i;
	sz[i] = 1;
}

int find_set_size(int v) {
	return v == parent[v] ? v : parent[v] = find_set_size(parent[v]);
}

void union_set_size(int u, int v) {
	u = find_set_size(u);
	v = find_set_size(v);
	if (u != v) {
		if (sz[u] < sz[v]) swap(u, v);
		parent[v] = u;
		sz[u] += sz[v];
		if (not_merge_color[v]) { // have not taken colors in node v yet
			for (int i = 1; i <= n; ++i) {
				color[u][i] += color[v][i];
				not_merge_color[v] = false;
			}
		}
	}
}

int main() {
	cin >> n >> q;
	a.resize(n + 1);
	parent.resize(n + 1);
	sz.resize(n + 1);
	not_merge_color.resize(n + 1);
	color.resize(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i) {
		not_merge_color[i] = true;
		cin >> a[i];
		make_set_size(i);
		color[i][a[i]] = 1;
	}
	for (int i = 0; i < q; ++i) {
		int query_type;
		cin >> query_type;
		if (query_type == 1) {
			int u, v;
			cin >> u >> v;
			union_set_size(u, v);
		}
		else {
			int u, c;
			cin >> u >> c;
			u = find_set_size(u);
			cout << color[u][c] << '\n';
		}
	}
}
// MLE on test 2 VNOI OJ