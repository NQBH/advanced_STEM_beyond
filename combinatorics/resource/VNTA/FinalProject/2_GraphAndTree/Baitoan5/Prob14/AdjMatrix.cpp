#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>>adj;

public:
    Graph(int n) : n(n), adj(n, vector<int>(n, 0)) {}

    void add_edge(int v, int w) {
        adj[v][w]=1;
    }

    void del_edge(int v, int w) {
        adj[v][w]=0;
    }

    vector<pair<int,int>> edges() {
        vector<pair<int,int>> res;
        for (int v=0; v<n; ++v) {
            for (int w=0; w<n; ++w) {
                if (adj[v][w]==1) {
                    res.emplace_back(v, w);
                }
            }
        }
        return res;
    }

    vector<pair<int,int>> incoming(int v) {
        vector<pair<int,int>> res;
        for (int u=0; u<n; ++u) {
            if (adj[u][v]==1) {
                res.emplace_back(u, v);
            }
        }
        return res;
    }

    vector<pair<int,int>> outgoing(int v) {
        vector<pair<int,int>> res;
        for (int w=0; w<n; ++w) {
            if (adj[v][w]==1) {
                res.emplace_back(v, w);
            }
        }
        return res;
    }

    // Trả về đỉnh nguồn của cạnh (v,w) nếu tồn tại, -1 nếu không
    int source(int v, int w) {
        if (adj[v][w]==1) return v;
        return -1;
    }

    // Trả về đỉnh đích của cạnh (v,w) nếu tồn tại, -1 nếu không
    int target(int v, int w) {
        if (adj[v][w]==1) return w;
        return -1;
    }

    void print() {
        cout << "Adjacency Matrix:\n";
        for (const auto& row : adj) {
            for (int val : row) {
                cout<<val<<" ";
            }
            cout<<"\n";
        }
    }
};

// Hàm hỗ trợ in vector các cặp (edges)
void print_edges(const vector<pair<int,int>>& edges) {
    cout<<"[";
    for (size_t i=0; i<edges.size(); ++i) {
        cout<<"("<<edges[i].first<<","<<edges[i].second<<")";
        if (i+1<edges.size()) cout<< ", ";
    }
    cout<<"]\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Graph G(5);
    G.add_edge(0, 1);
    G.add_edge(1, 2);
    G.add_edge(2, 3);
    G.add_edge(3, 4);
    G.add_edge(4, 0);

    G.print();

    cout<<"\nEdges: ";
    print_edges(G.edges());

    cout<<"\nIncoming to 3: ";
    print_edges(G.incoming(3));

    cout<<"\nOutgoing from 1: ";
    print_edges(G.outgoing(1));

    cout<<"\nSource of edge (2,3): "<<G.source(2, 3)<<"\n";
    cout<<"\nTarget of edge (2,3): "<<G.target(2, 3)<<"\n";

    G.del_edge(2, 3);
    cout<<"\nAfter deleting edge (2,3):"<<"\n";
    G.print();

    return 0;
}
