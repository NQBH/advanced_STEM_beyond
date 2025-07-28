#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class MultiGraph {
public:
    int n;
    vector<vector<tuple<int, int, int>>> adj; // (vertex, weight, edge_id)

    MultiGraph(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int u, int v, int weight, int edge_id) {
        adj[u].push_back({v, weight, edge_id});
        adj[v].push_back({u, weight, edge_id});
    }

    void dijkstra(int s) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;

        dist[s] = 0;
        Q.push({0, s});

        while (!Q.empty()) {
            int d = Q.top().first;
            int u = Q.top().second;
            Q.pop();

            if (d > dist[u]) continue;

            for (auto [v, w, edge_id] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    Q.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra on Multigraph from vertex " << s << ":\n";
        for (int i = 0; i < n; ++i) {
            if (dist[i] != INT_MAX) {
                cout << "Distance to " << i << ": " << dist[i] << endl;
            } else {
                cout << "Distance to " << i << ": unreachable" << endl;
            }
        }
    }
};

int main() {
    MultiGraph g(5);
    g.add_edge(0, 1, 4, 1);
    g.add_edge(0, 1, 2, 2); // Multiple edges
    g.add_edge(0, 2, 8, 3);
    g.add_edge(1, 3, 5, 4);
    g.add_edge(1, 4, 9, 5);
    g.dijkstra(0);
    return 0;
}