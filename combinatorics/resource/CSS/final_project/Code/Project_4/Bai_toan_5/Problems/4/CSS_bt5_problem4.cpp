#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int n;                           // so dinh
    vector<vector<int>> adj_matrix;  // ma tran ke

    Graph(int vertices) : n(vertices) {
        adj_matrix.assign(n, vector<int>(n, 0));
    }

    void add_edge(int v, int w) {
        // Them canh (v,w)
        adj_matrix[v][w] = 1;
        adj_matrix[w][v] = 1;
    }

    void del_edge(int v, int w) {
        // Xoa canh (v,w)
        adj_matrix[v][w] = 0;
        adj_matrix[w][v] = 0;
    }

    vector<pair<int,int>> edges() {
        // Tra ve danh sach cac cap (u,v) dai dien cho canh
        vector<pair<int,int>> result;
        for(int u=0; u<n; ++u)
            for(int v=u+1; v<n; ++v)
                if(adj_matrix[u][v])
                    result.emplace_back(u,v);
        return result;
    }

    vector<int> incoming(int v) {
        // Tra ve cac dinh u co canh den v
        vector<int> r;
        for(int u=0; u<n; ++u)
            if(adj_matrix[u][v]) r.push_back(u);
        return r;
    }

    vector<int> outgoing(int v) {
        // Tra ve cac dinh w ma v co canh den
        vector<int> r;
        for(int w=0; w<n; ++w)
            if(adj_matrix[v][w]) r.push_back(w);
        return r;
    }

    int source(int v, int w) {
        // Tra ve dinh nguon cua canh (v,w)
        return adj_matrix[v][w] ? v : -1;
    }

    int target(int v, int w) {
        // Tra ve dinh dich cua canh (v,w)
        return adj_matrix[v][w] ? w : -1;
    }
};

int main() {
    Graph g(4);
    g.add_edge(0,1);
    g.add_edge(1,2);
    auto edges = g.edges();
    cout << "Edges: ";
    for(auto [u,v]: edges) cout << "("<<u<<","<<v<<") ";
    cout << endl;
    auto inc = g.incoming(1);
    cout << "Incoming to 1: ";
    for(int u: inc) cout << u<<" ";
    cout << endl;
    auto out = g.outgoing(1);
    cout << "Outgoing from 1: ";
    for(int w: out) cout << w<<" ";
    cout << endl;
    cout << "Source (0,1): "<<g.source(0,1)<<endl;
    cout << "Target (0,1): "<<g.target(0,1)<<endl;
    return 0;
}