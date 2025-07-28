#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MultiGraph {
public:
    int n;
    vector<vector<pair<int, int>>> adj;

    MultiGraph(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int u, int v, int edge_id) {
        adj[u].push_back({v, edge_id});
        adj[v].push_back({u, edge_id});
    }

    void bfs(int s) {
        vector<bool> visited(n, false);
        vector<int> distance(n, -1);
        queue<int> Q;

        visited[s] = true;
        distance[s] = 0;
        Q.push(s);

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            cout << u << " ";

            for (auto [v, edge_id] : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    Q.push(v);
                }
            }
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            if (distance[i] != -1) {
                cout << "Distance to " << i << ": " << distance[i] << endl;
            }
        }
    }
};

int main() {
    MultiGraph g(5);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 1, 2); // Multiple edges
    g.add_edge(0, 2, 3);
    g.add_edge(1, 3, 4);
    g.add_edge(1, 4, 5);
    cout << "BFS on Multigraph: ";
    g.bfs(0);
    return 0;
}