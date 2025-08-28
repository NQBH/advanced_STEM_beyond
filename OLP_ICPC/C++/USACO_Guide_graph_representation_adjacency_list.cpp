#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj.at(u).push_back(v);
		adj.at(v).push_back(u);
	}
	{
		int u = 1;
		cout << "deg(u) = " << adj.at(u).size() << '\n'; // print number of vertices adjacent to u
		// print all edges with u as an endpoint
		for (int v : adj.at(u)) cout << "{" << u << ", " << v << "}" << '\n';
	}
}