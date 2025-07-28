#include <iostream>
#include <vector>
using namespace std;

class SimpleGraph {
public:
    int n;
    vector<vector<int>> adj;

    SimpleGraph(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs_util(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
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
    SimpleGraph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    cout << "DFS on Simple Graph: ";
    g.dfs(0);
    return 0;
}