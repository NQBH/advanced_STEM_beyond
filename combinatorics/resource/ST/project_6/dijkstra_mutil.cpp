#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void input_graph(int& n, vector<vector<pii>>& adj, int& s) {
    int m;
    cout << "Nhap so dinh: "; cin >> n;
    cout << "Nhap so canh: "; cin >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cout << "Nhap canh u v w: ";
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);  // cho phep trung cung
        // Neu la vo huong: adj[v].emplace_back(u, w);
    }
    cout << "Nhap dinh bat dau: ";
    cin >> s;
}

vector<int> dijkstra(int n, const vector<vector<pii>>& adj, int s) {
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

int main() {
    int n, s;
    vector<vector<pii>> adj;
    input_graph(n, adj, s);
    vector<int> dist = dijkstra(n, adj, s);
    for (int i = 0; i < n; ++i)
        cout << "Khoang cach tu " << s << " den " << i << ": " << dist[i] << endl;
    return 0;
}