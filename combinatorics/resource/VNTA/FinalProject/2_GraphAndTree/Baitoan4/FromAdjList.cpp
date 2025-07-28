#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int type; cin >> type; // 0: undirected, 1: directed
    bool directed = (type == 1);

    vector<vector<pair<int, int>>> adj(n);
    for (int u = 0; u < n; ++u) {
        int m;
        cin >> m; // số lượng đỉnh kề với u
        for (int j = 0; j < m; ++j) {
            int v, k;
            cin >> v >> k; // đỉnh v và số cạnh từ u đến v
            adj[u].push_back({v, k});
        }
    }

    vector<tuple<int, int, int>> edges;
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    vector<unordered_map<int, int>> ogMap(n), icMap(n);

    set<pair<int, int>> addedEdge;

    for (int u = 0; u < n; ++u) {
        for (auto [v, k] : adj[u]) {
            adjMatrix[u][v] += k;
            ogMap[u][v] += k;
            icMap[v][u] += k;

            if (directed) {
                edges.emplace_back(u, v, k);
            } else {
                if (u < v && !addedEdge.count({u, v})) {
                    edges.emplace_back(u, v, k);
                    addedEdge.insert({u, v});
                } else if (u == v) {
                    edges.emplace_back(u, v, k);
                }
            }
        }
    }

    vector<vector<pair<int, int>>> og(n), ic(n);
    for (int u = 0; u < n; ++u) {
        for (auto& [v, k] : ogMap[u]) og[u].push_back({v, k});
        for (auto& [v, k] : icMap[u]) ic[u].push_back({v, k});
    }

    cout << "\nEdge List:\n";
    for (auto [u, v, k] : edges)
        cout << u << " " << v << " " << k << "\n";

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << adjMatrix[i][j] << (j + 1 == n ? "\n" : " ");

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
3 0 2 1 3 3 1
2 2 4 5 1
3 0 1 2 2 3 3
3 1 1 4 5 5 2
2 0 3 4 1
3 2 2 3 1 5 3

Input 2: Undirected graph
6 0
4 0 2 1 3 2 1 4 2
5 0 3 1 1 2 2 3 4 5 2
5 0 1 1 2 2 3 3 1 4 2
5 1 4 2 1 3 2 4 5 5 1
5 0 2 2 2 3 5 4 2 5 3
4 1 2 3 1 4 3 5 4
*/
