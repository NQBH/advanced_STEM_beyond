#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple> 
using namespace std;

class GeneralGraph {
public:
    int n;
    vector<vector<tuple<int, int, int>>> adj;

    GeneralGraph(int vertices) : n(vertices) {
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
                if (v != u && dist[u] + w < dist[v]) { // Skip self-loops
                    dist[v] = dist[u] + w;
                    Q.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra on General Graph from vertex " << s << ":\n";
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
    GeneralGraph g(5); // 5 vertices (0 to 4)
    g.add_edge(0, 0, 4, 1);   // 0 -> 0: self-loop with weight 4
    g.add_edge(0, 1, 1, 2);   // 0 -> 1: weight 1
    g.add_edge(1, 2, 2, 3);   // 1 -> 2: parallel edge, weight 2
    g.add_edge(1, 2, 3, 4);   // 1 -> 2: parallel edge, weight 3
    // No edge from 2 to 3
    g.add_edge(3, 4, 1, 5);   // 3 -> 4: parallel edge, weight 1
    g.add_edge(3, 4, 5, 6);   // 3 -> 4: parallel edge, weight 5
    g.add_edge(3, 4, 7, 7);   // 3 -> 4: parallel edge, weight 7
    g.dijkstra(1); // Source is 1, target is 3
    return 0;
}