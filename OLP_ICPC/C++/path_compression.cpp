#include <iostream>
#include <vector>
using namespace std;
#define N 30001
int root[N];
bool visited[N];
int active[N];
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

}