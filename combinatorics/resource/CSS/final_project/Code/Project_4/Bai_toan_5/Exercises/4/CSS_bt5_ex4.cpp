#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int n;                       // so dinh
    vector<vector<int>> adj;     // danh sach ke

    Graph(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int u, int v) {
        // Them canh (u,v)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void generate_complete() {
        // Sinh do thi day du K_n
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                add_edge(i, j);
            }
        }
    }

    void generate_bipartite(int p, int q) {
        // Sinh do thi luong phan day du K_{p,q}
        for (int i = 0; i < p; ++i) {
            for (int j = p; j < p + q; ++j) {
                add_edge(i, j);
            }
        }
    }
};

int main() {
    Graph g(4);
    g.generate_complete();
    cout << "Complete graph edges: ";
    for (int u = 0; u < g.n; ++u) {
        for (int v : g.adj[u]) {
            if (u < v) cout << "(" << u << "," << v << ") ";
        }
    }
    cout << endl;
    return 0;
}