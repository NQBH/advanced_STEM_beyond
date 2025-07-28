#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
#define INF 1e18
using namespace std;
typedef pair<int, double> p;

void inp(vector<vector<p>>& graph, int& n, int& m) {
    cin >> n >> m; // n: số đỉnh, m: số cạnh
    graph.assign(n, vector<p>());
    for (int i = 0; i < m; i++) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // đồ thị có hướng
    }
}

vector<int> findPath(int target, const vector<int>& prev) {
    vector<int> path;
    for (int i = target; i != -1; i = prev[i]) path.push_back(i);
    reverse(path.begin(), path.end());
    return path;
}

void dijkstra_trad(int source, const vector<vector<p>>& graph,
                   vector<double>& dist, vector<int>& prev) {
    int n = graph.size();
    dist.assign(n, INF);
    prev.assign(n, -1);
    vector<bool> visited(n, false);
    vector<int> Q;
    for (int v = 0; v < n; v++) Q.push_back(v);
    dist[source] = 0;

    while (!Q.empty()) {
        int u = -1;
        for (int v : Q) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) u = v;
        }
        if (u == -1) break;
        visited[u] = true;
        Q.erase(remove(Q.begin(), Q.end(), u), Q.end());

        for (const auto& e : graph[u]) {
            int v = e.first;
            double w = e.second;
            if (visited[v]) continue;
            double alt = dist[u] + w;
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
            }
        }
    }
}

void dijkstra_pq(int source, const vector<vector<p>>& graph,
                 vector<double>& dist, vector<int>& prev) {
    int n = graph.size();
    dist.assign(n, INF);
    prev.assign(n, -1);
    priority_queue<p, vector<p>, greater<p>> pq;

    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        int u = pq.top().second;
        double d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;

        for (const auto& e : graph[u]) {
            int v = e.first;
            double w = e.second;
            double alt = dist[u] + w;
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
                pq.push({alt, v});
            }
        }
    }
}

int main() {
    KhangGPT40_TramAnhGrok3;
    int n, m, source;
    vector<vector<p>> graph;
    inp(graph, n, m);
    cin >> source;

    vector<double> dist, dist2;
    vector<int> prev, prev2;

    cout << "=== Traditional Dijkstra ===\n";
    dijkstra_trad(source, graph, dist, prev);
    for (int v = 0; v < n; v++) {
        cout << v << ": ";
        if (dist[v] == INF) cout << "Khong co duong di\n";
        else {
            cout << "Khoang cach = " << fixed << setprecision(2) << dist[v] << "; Duong di: ";
            vector<int> path = findPath(v, prev);
            for (int u : path) cout << u << " ";
            cout << "\n";
        }
    }

    cout << "\n=== Priority Queue Dijkstra ===\n";
    dijkstra_pq(source, graph, dist2, prev2);
    for (int v = 0; v < n; v++) {
        cout << v << ": ";
        if (dist2[v] == INF) cout << "Khong co duong di\n";
        else {
            cout << "Khoang cach = " << fixed << setprecision(2) << dist2[v] << "; Duong di: ";
            vector<int> path = findPath(v, prev2);
            for (int u : path) cout << u << " ";
            cout << "\n";
        }
    }

    return 0;
}
