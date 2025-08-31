#include <iostream>
#include <vector>
using namespace std;

const int sz = 2e5;
vector<int> children[sz];
int subtree_size[sz], depth[sz];

void dfs_size(int node) {
	subtree_size[node] = 1; // represent the root of `node's` subtree (which would be `node` itself)
	for (int child :  children[node]) {
		depth[child] = depth[node] + 1; // not needed for this problem
		dfs_size(child);
		subtree_size[node] += subtree_size[child]; // add `node's` children's subtrees to the size of `node's` subtree
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int parent;
		cin >> parent;
		--parent; // this node is the parent of node i, also notice the decrement operator in order to make the node 0-indexed
		children[parent].push_back(i);
	}
	dfs_size(0);
	for (int i = 0; i < n; ++i) {
		cout << subtree_size[i] - 1;
		if (i != n - 1) cout << " ";
	}
	cout << '\n';
}