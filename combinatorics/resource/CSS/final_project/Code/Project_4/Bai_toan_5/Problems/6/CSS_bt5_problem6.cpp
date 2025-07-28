#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Tree {
public:
    int n;                       // so dinh
    vector<vector<int>> adj;     // danh sach ke

    Tree(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int u, int v) {
        // Them canh (u,v)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool is_tree() {
        // Kiem tra xem do thi co phai la cay
        // visited: trang thai tham
        // parent: cha cua moi dinh trong BFS
        int edge_count = 0;
        for (int v = 0; v < n; ++v) edge_count += adj[v].size();
        if (edge_count / 2 != n - 1) return false;

        vector<bool> visited(n, false);
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                } else if (v != parent[u]) {
                    return false;
                }
            }
        }
        for (bool v : visited) if (!v) return false;
        return true;
    }
};

int main() {
    Tree t(4);
    t.add_edge(0, 1);
    t.add_edge(0, 2);
    t.add_edge(2, 3);
    cout << "Is tree: " << t.is_tree() << endl; // 1
    return 0;
}