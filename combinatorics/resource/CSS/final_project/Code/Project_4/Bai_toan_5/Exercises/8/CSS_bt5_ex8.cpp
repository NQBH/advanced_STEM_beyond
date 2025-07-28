#include <iostream>
#include <vector>
#include <random>
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
        adj[v].push_back(u);
    }

    void generate_random_tree() {
        // Sinh cay ngau nhien bang ma Prufer
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, n - 1);
        vector<int> prufer(n - 2);
        for (int i = 0; i < n - 2; ++i) {
            prufer[i] = dis(gen);
        }
        vector<int> degree(n, 1);
        for (int x : prufer) {
            degree[x]++;
        }
        vector<int> queue;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) queue.push_back(i);
        }
        for (int x : prufer) {
            int u = queue.front();
            queue.erase(queue.begin());
            add_edge(u, x);
            degree[x]--;
            degree[u]--;
            if (degree[x] == 1) queue.push_back(x);
        }
        int u = -1, v = -1;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                if (u == -1) u = i;
                else v = i;
            }
        }
        add_edge(u, v);
    }
};

int main() {
    Tree t(5);
    t.generate_random_tree();
    cout << "Random tree edges: ";
    for (int u = 0; u < t.n; ++u) {
        for (int v : t.adj[u]) {
            if (u < v) cout << "(" << u << "," << v << ") ";
        }
    }
    cout << endl;
    return 0;
}