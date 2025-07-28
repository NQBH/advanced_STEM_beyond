#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

typedef pair<int, int> pii; 

void dijkstra(int start, unordered_map<int, vector<pii>>& graph, int n) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();

        for (auto [v, weight] : graph[u]) {
            if (dist[v] > curr_dist + weight) {
                dist[v] = curr_dist + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Khoảng cách ngắn nhất từ đỉnh " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Tới " << i << " = ";
        if (dist[i] == INT_MAX)
            cout << "∞";
        else
            cout << dist[i];
        cout << endl;
    }
}

int main() {
    int n = 4; 
    unordered_map<int, vector<pii>> graph;

    graph[0] = {{1, 2}, {2, 5}};
    graph[1] = {{0, 2}, {2, 1}, {3, 4}};
    graph[2] = {{0, 5}, {1, 1}, {3, 2}};
    graph[3] = {{1, 4}, {2, 2}};

    dijkstra(0, graph, n);

    return 0;
}
