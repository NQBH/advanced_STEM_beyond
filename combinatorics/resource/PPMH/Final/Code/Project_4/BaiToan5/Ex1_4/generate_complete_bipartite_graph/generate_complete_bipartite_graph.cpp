#include <vector>
#include <iostream>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph() : V(0) {}

    int add_vertex() {
        adj.push_back(vector<int>());
        return V++;
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display() {
        for (int i = 0; i < V; ++i) {
            cout << "Đỉnh " << i << " nối với: ";
            for (int j : adj[i])
                cout << j << " ";
            cout << endl;
        }
    }
};

Graph generate_complete_bipartite_graph(int p, int q) {
    Graph G;
    vector<int> left, right;

    for (int i = 0; i < p; ++i)
        left.push_back(G.add_vertex());

    for (int i = 0; i < q; ++i)
        right.push_back(G.add_vertex());

    for (int u : left)
        for (int v : right)
            G.add_edge(u, v);

    return G;
}

int main() {
    int p, q;
    cout << "Nhập số đỉnh (p): ";
    cin >> p;
    cout << "Nhập số đỉnh (q): ";
    cin >> q;

    Graph G = generate_complete_bipartite_graph(p, q);
    G.display();

    return 0;
}