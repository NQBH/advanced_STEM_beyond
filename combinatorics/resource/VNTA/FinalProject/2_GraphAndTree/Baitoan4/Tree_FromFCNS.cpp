#include <bits/stdc++.h>
using namespace std;

const int NIL = -1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> F(n), N(n);
    for (int i = 0; i < n; ++i) cin >> F[i] >> N[i];

    vector<int> parent(n, NIL);
    for (int u = 0; u < n; ++u) {
        int child = F[u];
        while (child != NIL) {
            parent[child] = u;
            child = N[child];
        }
    }
    int root = NIL;
    for (int i = 0; i < n; ++i)
        if (parent[i] == NIL) root = i;\
    vector<vector<int>> adj(n);
    for (int v = 0; v < n; ++v) {
        if (parent[v] != NIL) {
            adj[parent[v]].push_back(v);
        }
    }

    cout << "=== Array of Parents ===\n";
    for (int i = 0; i < n; ++i) {
        cout << "parent[" << i << "] = " << (parent[i] == NIL ? -1 : parent[i]) << "\n";
    }

    cout << "\n=== Graph-Based Representation (Adjacency List) ===\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (auto v : adj[u]) cout << v << " ";
        cout << "\n";
    }

    return 0;
}

/*
15
1 -1
4 2
7 3
9 -1
11 5
-1 6
13 -1
-1 8
-1 -1
-1 10
-1 -1
-1 12
-1 -1
-1 14
-1 -1
*/
