#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int type; cin >> type; // 0: undirected, 1: directed
    bool directed = (type == 1);

    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        edges[i] = {u, v, k};
    }

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> adj(n);
    vector<unordered_map<int, int>> ogMap(n), icMap(n);

    for (auto [u, v, k] : edges) {
        // adjacency matrix
        adjMatrix[u][v] += k;
        if (!directed && u != v) adjMatrix[v][u] += k;

        // adjacency list
        adj[u].push_back({v, k});
        if (!directed && u != v) adj[v].push_back({u, k});

        // adjacency map
        ogMap[u][v] += k;
        icMap[v][u] += k;
        if (!directed && u!=v) {
            ogMap[v][u] += k;
            icMap[u][v] += k;
        }
    }

    vector<vector<pair<int, int>>> og(n), ic(n);
    for (int u = 0; u < n; ++u) {
        for (auto& [v, k] : ogMap[u])
            og[u].push_back({v, k});
        for (auto& [v, k] : icMap[u])
            ic[u].push_back({v, k});
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }

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
6 16 1
0 0 2
0 1 3
0 3 1
1 2 4
1 5 1
2 0 1
2 2 2
2 3 3
3 1 1
3 4 5
3 5 2
4 0 3
4 4 1
5 2 2
5 3 1
5 5 3

Input 2: Undirected graph
6 17 0
0 0 2
0 1 3
0 2 1
0 4 2
1 1 1
1 2 2
1 3 4
1 5 2
2 2 3
2 3 1
2 4 2
3 3 2
3 4 5
3 5 1
4 4 2
4 5 3
5 5 4
*/
