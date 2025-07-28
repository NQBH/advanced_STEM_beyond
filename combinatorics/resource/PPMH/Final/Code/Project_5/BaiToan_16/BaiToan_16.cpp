#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

typedef pair<int, int> Edge; 
typedef unordered_map<int, vector<Edge>> Graph;

unordered_map<int, int> dijkstra(Graph& graph, int start) {
    unordered_map<int, int> dist;
    for (auto& [u, _] : graph) dist[u] = INT_MAX;
    dist[start] = 0;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [w, v] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    Graph graph;
    graph[0] = {{2, 1}, {4, 2}};
    graph[1] = {{1, 2}, {7, 3}};
    graph[2] = {{3, 3}};
    graph[3] = {};

    auto dist = dijkstra(graph, 0);
    for (auto& [v, d] : dist) {
        cout << "Khoảng cách từ 0 đến " << v << ": " << d << "\n";
    }

    return 0;
}