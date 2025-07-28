#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int type; cin >> type; // 0: undirected, 1: directed
    bool directed = (type == 1);

    vector<vector<int>> adjMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adjMatrix[i][j];

    vector<tuple<int, int, int>> edges;
    vector<vector<pair<int, int>>> adj(n);
    vector<unordered_map<int, int>> ogMap(n), icMap(n);

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            int k = adjMatrix[u][v];
            if (k == 0) continue;

            if (directed) {
                edges.emplace_back(u, v, k);
                adj[u].push_back({v, k});
                ogMap[u][v] += k;
                icMap[v][u] += k;
            } else if (!directed && u <= v) {
                edges.emplace_back(u, v, k);
                if (u == v) {
                    // canh khuyen
                    adj[u].push_back({v, k});
                    ogMap[u][v] += k;
                    icMap[u][v] += k;
                } else {
                    // canh thuong
                    adj[u].push_back({v, k});
                    adj[v].push_back({u, k});
                    ogMap[u][v] += k;
                    ogMap[v][u] += k;
                    icMap[v][u] += k;
                    icMap[u][v] += k;
                }
            }
        }
    }

    // convert unordered_map to vector<pair> for printing
    vector<vector<pair<int, int>>> og(n), ic(n);
    for (int u = 0; u < n; ++u) {
        for (auto& [v, k] : ogMap[u])
            og[u].push_back({v, k});
        for (auto& [v, k] : icMap[u])
            ic[u].push_back({v, k});
    }

    cout << "\nEdge List:\n";
    for (auto [u, v, k] : edges)
        cout << u << " " << v << " " << k << "\n";

    cout << "\nAdjacency List:\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (auto [v, k] : adj[u])
            cout << "{" << v << "," << k << "} ";
        cout << "\n";
    }

    cout << "\nAdjacency Map (Incoming - ic):\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (auto [v, k] : ic[u])
            cout << "{" << v << "," << k << "} ";
        cout << "\n";
    }

    cout << "\nAdjacency Map (Outgoing - og):\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (auto [v, k] : og[u])
            cout << "{" << v << "," << k << "} ";
        cout << "\n";
    }

    return 0;
}

/*
Input 1: Directed graph
6 1
2 3 0 1 0 0
0 0 4 0 0 1
1 0 2 3 0 0
0 1 0 0 5 2
3 0 0 0 1 0
0 0 2 1 0 3

Input 2: Undirected graph
6 0
2 3 1 0 2 0
3 1 2 4 0 2
1 2 3 1 2 0
0 4 1 2 5 1
2 0 2 5 2 3
0 2 0 1 3 4
*/
