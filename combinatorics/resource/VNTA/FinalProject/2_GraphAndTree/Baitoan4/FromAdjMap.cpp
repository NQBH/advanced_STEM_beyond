#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int type; cin >> type; // 0: undirected, 1: directed
    bool directed = (type == 1);

    vector<unordered_map<int, int>> ogMap(n), icMap(n);

    // Input: outgoing map
    for (int u = 0; u < n; ++u) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int v, k;
            cin >> v >> k;
            ogMap[u][v] += k;
            icMap[v][u] += k;
        }
    }

    vector<tuple<int, int, int>> edges;
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> adj(n);

    set<pair<int, int>> added;

    for (int u = 0; u < n; ++u) {
        for (auto& [v, k] : ogMap[u]) {
            adjMatrix[u][v] += k;

            if (directed) {
                edges.emplace_back(u, v, k);
                adj[u].push_back({v, k});
            } else {
                if (u == v) {
                    edges.emplace_back(u, v, k);
                    adj[u].push_back({v, k});
                } else if (u < v && !added.count({u, v})) {
                    edges.emplace_back(u, v, k);
                    adj[u].push_back({v, k});
                    adj[v].push_back({u, k});
                    added.insert({u, v});
                }
            }
        }
    }

    cout << "\nAdjacency Map (Incoming - ic):\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (auto [v, k] : icMap[u])
            cout << "{" << v << "," << k << "} ";
        cout << "\n";
    }

    cout << "\nEdge List:\n";
    for (auto [u, v, k] : edges)
        cout << u << " " << v << " " << k << "\n";

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cout << adjMatrix[i][j] << (j + 1 == n ? "\n" : " ");

    cout << "\nAdjacency List:\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (auto [v, k] : adj[u])
            cout << "{" << v << "," << k << "} ";
        cout << "\n";
    }

    return 0;
}


/*
Input 1: Directed graph
6 1
3 3 1 0 2 1 3
2 5 1 2 4
3 3 3 0 1 2 2
3 5 2 1 1 4 5
2 4 1 0 3
3 5 3 2 2 3 1

Input 2: Undirected graph
6 0
4 4 2 2 1 0 2 1 3
5 3 4 2 2 5 2 0 3 1 1
5 4 2 3 1 2 3 0 1 1 2
5 5 1 4 5 3 2 1 4 2 1
5 4 2 3 5 5 3 0 2 2 2
4 5 4 4 3 1 2 3 1
*/
