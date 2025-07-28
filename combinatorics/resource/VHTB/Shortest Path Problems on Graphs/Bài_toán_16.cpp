#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra_general(int n, vector<vector<pii>> &adj, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (du > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > du + w) {
                dist[v] = du + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << "Khoảng cách từ " << src << " đến " << i << ": " << dist[i] << endl;
}

int main() {
    int n = 5;
    vector<vector<pii>> adj(n);

    adj[0].push_back({1, 2});
    adj[0].push_back({1, 1});
    adj[0].push_back({0, 0});

    adj[1].push_back({2, 1});
    adj[1].push_back({3, 5});

    adj[2].push_back({3, 1});
    adj[3].push_back({4, 1});
    adj[3].push_back({4, 3});

    dijkstra_general(n, adj, 0);
    return 0;
}
