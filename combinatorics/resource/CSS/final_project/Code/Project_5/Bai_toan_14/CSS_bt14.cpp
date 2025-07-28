#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class SimpleGraph {
public:
    int n;
    vector<vector<pair<int, int>>> adj; // (vertex, weight)

    SimpleGraph(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Undirected
    }

    void dijkstra(int s) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q; // (dist, vertex)

        dist[s] = 0;
        Q.push({0, s});

        while (!Q.empty()) {
            int d = Q.top().first;
            int u = Q.top().second;
            Q.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    Q.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra on Simple Graph from vertex " << s << ":\n";
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
    SimpleGraph g(5);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 8);
    g.add_edge(1, 2, 2);
    g.add_edge(1, 3, 5);
    g.add_edge(2, 3, 5);
    g.add_edge(2, 4, 9);
    g.add_edge(3, 4, 4);
    g.dijkstra(0);
    return 0;
}