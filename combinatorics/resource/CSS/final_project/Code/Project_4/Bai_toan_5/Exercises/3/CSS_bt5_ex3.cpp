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

    void generate_path() {
        // Sinh do thi duong Pn
        for (int i = 0; i < n - 1; ++i) {
            add_edge(i, i + 1);
        }
    }

    void generate_circle() {
        // Sinh do thi vong Cn
        generate_path();
        if (n > 2) {
            add_edge(0, n - 1);
        }
    }

    void generate_wheel() {
        // Sinh do thi banh xe Wn
        generate_circle();
        for (int i = 0; i < n - 1; ++i) {
            add_edge(n - 1, i);
        }
    }
};

int main() {
    Graph g(5);
    g.generate_path();
    cout << "Path graph edges: ";
    for (int u = 0; u < g.n; ++u) {
        for (int v : g.adj[u]) {
            if (u < v) cout << "(" << u << "," << v << ") ";
        }
    }
    cout << endl;
    return 0;
}