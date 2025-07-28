#include <bits/stdc++.h>
using namespace std;

const int NIL = -1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> parent(n);
    int root = NIL;
    for (int i = 0; i < n; ++i) {
        cin >> parent[i];
        if (parent[i] == NIL) root = i;
    }

    // First-Child, Next-Sibling
    vector<int> F(n, NIL);
    vector<int> N(n, NIL);
    vector<vector<int>> children(n);

    for (int v = 0; v < n; ++v) {
        if (parent[v] != NIL)
            children[parent[v]].push_back(v);
    }

    for (int v = 0; v < n; ++v) {
        if (!children[v].empty()) {
            F[v] = children[v][0];
            for (int i = 0; i + 1 < (int)children[v].size(); ++i)
                N[children[v][i]] = children[v][i + 1]; // N[v] = next[v]
        }
    }

    // Graph-Based Representation
    vector<vector<int>> adj(n);
    for (int v = 0; v < n; ++v) {
        if (parent[v] != NIL) {
            adj[parent[v]].push_back(v);
        }
    }

    cout << "\n=== First-Child, Next-Sibling Representation ===\n";
    for (int i = 0; i < n; ++i)
        cout << "F[" << i << "] = " << (F[i] == NIL ? "nil" : to_string(F[i])) << ", "
             << "N[" << i << "] = " << (N[i] == NIL ? "nil" : to_string(N[i])) << "\n";

    cout << "\n=== Graph-Based Representation (Adjacency List) ===\n";
    for (int u = 0; u < n; ++u) {
        cout << u << ": ";
        for (int v : adj[u]) cout << v << " ";
        cout << "\n";
    }

    return 0;
}

/*
15
-1 0 0 0 1 1 1 2 2 3 3 4 4 6 6
*/
