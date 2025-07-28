#include <bits/stdc++.h>
using namespace std;

const int NIL = -1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; ++u) {
        int deg;
        cin >> deg;
        adj[u].resize(deg);
        for (int i = 0; i < deg; ++i) {
            cin >> adj[u][i];
        }
    }

    vector<int> parent(n, NIL);
    for (int u = 0; u < n; ++u) {
        for (int c : adj[u]) {
            parent[c] = u;
        }
    }
    int root = NIL;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == NIL) {
            root = i;
            break;
        }
    }

    vector<int> F(n, NIL), N(n, NIL);
    for (int u = 0; u < n; ++u) {
        if (!adj[u].empty()) {
            F[u] = adj[u][0];
            for (int i = 0; i + 1 < (int)adj[u].size(); ++i) {
                N[adj[u][i]] = adj[u][i + 1];
            }
        }
    }

    cout << "=== Array of Parents ===\n";
    for (int i = 0; i < n; ++i) {
        cout << "parent[" << i << "] = " << (parent[i] == NIL ? -1 : parent[i]) << "\n";
    }

    cout << "\n=== First-Child, Next-Sibling Representation ===\n";
    for (int i = 0; i < n; ++i) {
        cout << "F[" << i << "] = " << (F[i] == NIL ? "nil" : to_string(F[i])) << ", "
             << "N[" << i << "] = " << (N[i] == NIL ? "nil" : to_string(N[i])) << "\n";
    }

    return 0;
}

/*
15
3 1 2 3
3 4 5 6
2 7 8
2 9 10
2 11 12
0
2 13 14
0
0
0
0
0
0
0
0
*/
