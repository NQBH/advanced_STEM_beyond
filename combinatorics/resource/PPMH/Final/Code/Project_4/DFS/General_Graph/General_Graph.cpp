#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adj;

    void dfs_util(int v, unordered_set<int>& visited) {
        visited.insert(v);
        cout << v << " ";
        for (int neighbor : adj[v]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs_util(neighbor, visited);
            }
        }
    }

public:
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    void dfs() {
        unordered_set<int> visited;
        for (auto& pair : adj) {
            int vertex = pair.first;
            if (visited.find(vertex) == visited.end()) {
                dfs_util(vertex, visited);
            }
        }
    }
};

int main() {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "DFS của đồ thị: ";
    g.dfs();
    cout << endl;

    return 0;
}