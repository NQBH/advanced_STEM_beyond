#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Tree {
public:
    int n;                   // so nut
    vector<vector<int>> adj; // danh sach ke

    Tree(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int u, int v) {
        // Them canh (u,v)
        adj[u].push_back(v);
    }

    void generate_complete_binary() {
        // Sinh cay nhi phan day du
        if (n == 0) return;
        queue<int> q;
        q.push(0);
        int i = 1;
        while (!q.empty() && i < n) {
            int u = q.front(); q.pop();
            if (i < n) {
                add_edge(u, i);
                q.push(i);
                i++;
            }
            if (i < n) {
                add_edge(u, i);
                q.push(i);
                i++;
            }
        }
    }
};

int main() {
    Tree t(7);
    t.generate_complete_binary();
    cout << "Complete binary tree edges: ";
    for (int u = 0; u < t.n; ++u) {
        for (int v : t.adj[u]) {
            cout << "(" << u << "," << v << ") ";
        }
    }
    cout << endl;
    return 0;
}