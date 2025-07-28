#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

typedef pair<int, int> Edge;

unordered_map<char, vector<Edge>> graph;

unordered_map<char, int> dijkstra_multigraph(char start) {
    unordered_map<char, int> dist;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist.count(u)) continue;
        dist[u] = d;
        for (auto [v, weight] : graph[u]) {
            if (!dist.count(v))
                pq.push({d + weight, v});
        }
    }
    return dist;
}

int main() {
    graph['A'].push_back({'B', 4});
    graph['A'].push_back({'B', 2});
    graph['A'].push_back({'C', 5});
    graph['B'].push_back({'C', 1});
    graph['C'].push_back({'D', 3});

    auto dist = dijkstra_multigraph('A');
    for (auto [node, d] : dist) {
        cout << "Khoảng cách ngắn nhất từ A đến " << node << ": " << d << endl;
    }
    return 0;
}