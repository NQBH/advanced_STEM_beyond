#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Nhap so dinh n: ";
    cin >> n;

    // Nhap ma tran ke
    cout << "Nhap ma tran ke:\n";
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Adjacency List: luu danh sach ke
    vector<vector<int>> adj_list(n);

    // Edge List: luu danh sach canh (u, v, k)
    struct Edge {
        int u, v, k;
    };
    vector<Edge> edge_list;

    // Adjacency Map: map moi dinh v -> (incoming, outgoing)
    // incoming[v][u] = vector cac canh tu u toi v
    // outgoing[v][w] = vector cac canh tu v toi w
    vector<unordered_map<int, vector<pair<int, int>>>> incoming(n), outgoing(n);

    // Duyet qua ma tran ke
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = matrix[i][j]; // so canh tu i den j
            if (k > 0) {
                // Them vao adjacency list (lap k lan neu co nhieu canh)
                for (int t = 0; t < k; t++) {
                    adj_list[i].push_back(j);
                }

                // Them vao edge list
                edge_list.push_back({i, j, k});

                // Cap nhat adjacency map (incoming va outgoing)
                for (int t = 0; t < k; t++) {
                    outgoing[i][j].push_back({i, j}); // canh tu i toi j
                    incoming[j][i].push_back({i, j}); // canh toi j tu i
                }
            }
        }
    }

    // In danh sach ke
    cout << "\n============ Adjacency List:\n";
    for (int u = 0; u < n; u++) {
        cout << u << ": ";
        for (auto v : adj_list[u]) cout << v << " ";
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