#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Nhap so dinh n: ";
    cin >> n;
    cin.ignore(); // bo qua ky tu xuong dong sau khi nhap n

    // Danh sach ke
    vector<vector<int>> adj_list(n);
    cout << "Nhap danh sach ke (moi dong la cac dinh ke cua dinh u, enter neu rong):\n";
    for (int u = 0; u < n; u++) {
        cout << u << ": ";
        string line;
        getline(cin, line);
        if (!line.empty()) {
            stringstream ss(line);
            int v;
            while (ss >> v) {
                adj_list[u].push_back(v);
            }
        }
    }

    // Ma tran ke khoi tao toan 0
    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));

    // Danh sach canh (edge list)
    struct Edge { int u, v, k; };
    vector<Edge> edge_list;

    // Adjacency map: incoming[v][u] va outgoing[u][v]
    vector<unordered_map<int, vector<pair<int,int>>>> incoming(n), outgoing(n);

    // Buoc 1: cap nhat ma tran ke
    for (int u = 0; u < n; u++) {
        for (int v : adj_list[u]) {
            adj_matrix[u][v] += 1;
        }
    }

    // Buoc 2: tao danh sach canh va cap nhat adjacency map
    for (int u = 0; u < n; u++) {
        // dung set de tranh lap khi dem
        set<int> neighbors(adj_list[u].begin(), adj_list[u].end());
        for (int v : neighbors) {
            int k = count(adj_list[u].begin(), adj_list[u].end(), v); // dem so canh tu u den v
            edge_list.push_back({u, v, k});
            for (int i = 0; i < k; i++) {
                outgoing[u][v].push_back({u, v}); // Outgoing
                incoming[v][u].push_back({u, v}); // Incoming
            }
        }
    }

    // In ma tran ke
    cout << "\n============ Ma tran ke:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }

    // In danh sach canh
    cout << "\n============ Edge List:\n";
    for (auto &e : edge_list) {
        cout << e.u << " " << e.v << " " << e.k << "\n";
    }

    // In adjacency map
    cout << "\n============ Adjacency Map:\n";
    for (int v = 0; v < n; v++) {
        cout << "Dinh " << v << ":\n";
        cout << "  Incoming:\n";
        for (auto &kv : incoming[v]) {
            cout << "    " << kv.first << ": ";
            for (auto &edge : kv.second) {
                cout << "(" << edge.first << "," << edge.second << ") ";
            }
            cout << "\n";
        }
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