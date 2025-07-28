#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Dijkstra tren do thi tong quat
vector<int> dijkstra(int n, const vector<tuple<int, int, int>>& edges, int start) {
    vector<vector<pair<int, int>>> graph(n); // graph[u] = (v, w)

    // Xay dung do thi
    for (auto [u, v, w] : edges) {
        graph[u].emplace_back(v, w);  // Do thi co huong
        // graph[v].emplace_back(u, w); // Neu do thi vo huong
    }

    vector<int> dist(n, INT_MAX);     // Ban dau gan vo cung
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);  // (khoang cach, dinh)

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    cout << "Nhap cac canh u v w:\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    int s;
    cout << "Nhap dinh bat dau: ";
    cin >> s;

    vector<int> dist = dijkstra(n, edges, s);
    cout << "Khoang cach ngan nhat tu " << s << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << s << " -> " << i << ": " << dist[i] << '\n';
    }

    return 0;
}