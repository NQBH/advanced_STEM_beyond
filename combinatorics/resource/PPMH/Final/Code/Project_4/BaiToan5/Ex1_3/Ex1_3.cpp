#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    vector<pair<int, int>> edge_list;

public:
    int add_vertex() {
        adj.push_back({});
        return adj.size() - 1;
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // đồ thị vô hướng
        edge_list.emplace_back(u, v);
    }

    vector<int> vertices() {
        vector<int> verts;
        for (int i = 0; i < adj.size(); ++i)
            verts.push_back(i);
        return verts;
    }

    vector<pair<int, int>> edges() {
        return edge_list;
    }

    void print_graph() {
        for (int i = 0; i < adj.size(); ++i) {
            cout << i << ": ";
            for (int v : adj[i])
                cout << v << " ";
            cout << "\n";
        }
    }
};

Graph generate_path_graph(int n) {
    Graph G;
    vector<int> verts(n);
    for (int i = 0; i < n; ++i)
        verts[i] = G.add_vertex();
    for (int i = 0; i < n - 1; ++i)
        G.add_edge(verts[i], verts[i + 1]);
    return G;
}

Graph generate_circle_graph(int n) {
    Graph G = generate_path_graph(n);
    G.add_edge(0, n - 1);
    return G;
}

Graph generate_wheel_graph(int n) {
    if (n < 4)
        throw invalid_argument("Wheel graph requires at least 4 vertices.");
    Graph G;
    vector<int> cycle(n - 1);
    for (int i = 0; i < n - 1; ++i)
        cycle[i] = G.add_vertex();
    int center = G.add_vertex();
    for (int i = 0; i < n - 1; ++i) {
        G.add_edge(cycle[i], cycle[(i + 1) % (n - 1)]);
        G.add_edge(center, cycle[i]);
    }
    return G;
}

int main() {
    int n;
    cout << "Nhập n: ";
    cin >> n;

    cout << "\nĐồ thị P_n (đường đi):\n";
    Graph G1 = generate_path_graph(n);
    G1.print_graph();

    cout << "\nĐồ thị C_n (chu trình):\n";
    Graph G2 = generate_circle_graph(n);
    G2.print_graph();

    if (n >= 4) {
        cout << "\nĐồ thị W_n (bánh xe):\n";
        Graph G3 = generate_wheel_graph(n);
        G3.print_graph();
    } else {
        cout << "\nKhông thể tạo W_n với n < 4.\n";
    }

    return 0;
}
