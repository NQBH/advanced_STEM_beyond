#include <iostream>
#include <vector>
using namespace std;

class GeneralGraph {
public:
    int n;
    vector<vector<pair<int, int>>> adj;

    GeneralGraph(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int u, int v, int edge_id) {
        adj[u].push_back({v, edge_id});
        adj[v].push_back({u, edge_id});
    }

    void dfs_util(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto [u, edge_id] : adj[v]) {
            if (!visited[u] && u != v) { // Skip self-loops
                dfs_util(u, visited);
            }
        }
    }

    void dfs(int s) {
        vector<bool> visited(n, false);
        dfs_util(s, visited);
        cout << endl;
    }
};

int main() {
    GeneralGraph g(5);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 4);
    g.add_edge(1, 4, 5);
    g.add_edge(0, 0, 6);
    cout << "DFS on General Graph: ";
    g.dfs(0);
    return 0;
}