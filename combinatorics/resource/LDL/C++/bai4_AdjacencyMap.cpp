#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Nhap so dinh n: ";
    cin >> n;

    // Dung map de dam bao thu tu tang dan cua key
    vector<map<int, vector<pair<int,int>>>> incoming(n), outgoing(n);

    cout << "Nhap canh incoming theo dang: to_dinh from_dinh\n";
    cout << "Nhap x khi ket thuc\n";

    while (true) {
        cout << "Incoming: ";
        string s;
        cin >> s;
        if (s == "x" || s == "X") break;
        int v = stoi(s);
        int u;
        cin >> u;
        incoming[v][u].push_back({u, v});
        outgoing[u][v].push_back({u, v});
    }

    // Tao danh sach canh
    vector<Edge> edge_list;
    for (int u = 0; u < n; u++) {
        for (auto &kv : outgoing[u]) {
            int v = kv.first;
            int k = kv.second.size();
            if (k > 0) {
                edge_list.push_back({u, v, k});
            }
        }
    }

    // Sap xep edge_list theo u roi v (giong Python)
    sort(edge_list.begin(), edge_list.end(), [](const Edge &a, const Edge &b) {
        if (a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    });

    // Tao danh sach ke tu edge_list (theo thu tu da sap xep)
    vector<vector<int>> adj_list(n);
    for (auto &e : edge_list) {
        for (int i = 0; i < e.k; i++) {
            adj_list[e.u].push_back(e.v);
        }
    }

    // Tao ma tran ke
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
    for (auto &e : edge_list) {
        adj_matrix[e.u][e.v] = e.k;
    }

    // In danh sach canh
    cout << "\n============ Edge List:\n";
    for (auto &e : edge_list) {
        cout << e.u << " " << e.v << " " << e.k << "\n";
    }

    // In danh sach ke
    cout << "\n============ Adjacency List:\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (auto v : adj_list[u]) cout << v << " ";
        cout << "\n";
    }

    // In ma tran ke
    cout << "\n============ Ma tran ke:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}