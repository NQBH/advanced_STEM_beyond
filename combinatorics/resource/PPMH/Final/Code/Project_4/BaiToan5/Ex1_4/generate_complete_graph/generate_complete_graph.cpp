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

Graph generate_complete_graph(int n) {
    Graph G;
    vector<int> vertices;
    for (int i = 0; i < n; ++i)
        vertices.push_back(G.add_vertex());

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            G.add_edge(vertices[i], vertices[j]);

    return G;
}

int main() {
    int n;
    cout << "Nhập số đỉnh n: ";
    cin >> n;

    Graph G = generate_complete_graph(n);
    G.display();

    return 0;
}