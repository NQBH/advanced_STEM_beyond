#include <iostream>
#include <vector>
using namespace std;
#define N 300001

int root[N], active[N], ans = 0;
bool visited[N];
vector<int> stack;

// disjoint sets structure
int find(int u) {
	if (root[u] != u) root[u] = find(root[u]);
	return root[u];
}

void dfs(int u, const vector<vector<int>>& adj_list) {
	visited[u] = true;
	root[u] = u; // init
	stack.push_back(u);
	for (int v : adj_list[u])
		if (visited[v]) {
			v = find(active[v]);
			while (stack.back() != v) {
				root[find(stack.back())] = v;
				stack.pop_back();
			}
		}
	for (int v : adj_list[u])
		if (!visited[v]) {
			active[u] = v;
			dfs(v, adj_list);
		}
	if (stack.back() == u) stack.pop_back();
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> adj_list(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b;
		adj_list[a].push_back(b);
	}
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) dfs(1, adj_list);
	}
	

}