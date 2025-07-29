#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cout << "Nhap so dinh va so cap dinh co canh noi (n m): ";
    cin >> n >> m;

    cout << "Nhap m dong: u v k (co k canh tu u den v):\n";
    struct Edge { int u, v, k; };
    vector<Edge> edge_list;

    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        edge_list.push_back({u, v, k});
    }

    // Adjacency list: vector<int> cho moi dinh
    vector<vector<int>> adj_list(n);

    // Adjacency matrix: khoi tao n x n voi gia tri 0
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));

    // Adjacency map: su dung 2 map cho moi dinh (incoming va outgoing)
    // incoming[v][u] = danh sach cac cap (u,v)
    // outgoing[u][v] = danh sach cac cap (u,v)
    vector<unordered_map<int, vector<pair<int,int>>>> incoming(n), outgoing(n);

    // Xu ly edge list
    for (auto &e : edge_list) {
        int u = e.u, v = e.v, k = e.k;

        // Cap nhat danh sach ke
        for (int i = 0; i < k; i++) {
            adj_list[u].push_back(v);
        }

        // Cap nhat ma tran ke
        adj_matrix[u][v] += k;

        // Cap nhat adjacency map
        for (int i = 0; i < k; i++) {
            outgoing[u][v].push_back({u, v});
            incoming[v][u].push_back({u, v});
        }
    }

    // In danh sach ke
    cout << "\n============ Adjacency List:\n";
    for (int u = 0; u < n; u++) {
        cout << u << ": ";
        for (auto v : adj_list[u]) cout << v << " ";
        cout << "\n";
    }

    // In ma tran ke
    cout << "\n============ Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // In adjacency map
    cout << "\n============ Adjacency Map:\n";
    for (int v = 0; v < n; v++) {
        cout << "Dinh " << v << ":\n";
        // Incoming
        cout << "  Incoming:\n";
        for (auto &kv : incoming[v]) {
            cout << "    " << kv.first << ": ";
            for (auto &edge : kv.second) {
                cout << "(" << edge.first << "," << edge.second << ") ";
            }
            cout << "\n";
        }
        // Outgoing
        cout << "  Outgoing:\n";
        for (auto &kv : outgoing[v]) {
            cout << "    " << kv.first << ": ";
            for (auto &edge : kv.second) {
                cout << "(" << edge.first << "," << edge.second << ") ";
            }
            cout << "\n";
        }
    }
    return 0;
}