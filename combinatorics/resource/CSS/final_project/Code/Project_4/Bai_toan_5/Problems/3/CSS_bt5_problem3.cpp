#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> all_trees;

struct Graph {
    int n;
    vector<vector<int>> adj;
    Graph(int _n): n(_n), adj(n, vector<int>(n,0)) {}
    void add_edge(int u, int v) {
        // Them canh (u,v)
        adj[u][v] = adj[v][u] = 1;
    }
    vector<pair<int,int>> edges() const {
        // Tra ve cac cap (u,v) voi u < v
        vector<pair<int,int>> E;
        for(int u = 0; u < n; ++u)
            for(int v = u+1; v < n; ++v)
                if(adj[u][v])
                    E.emplace_back(u, v);
        return E;
    }
};

struct UF {
    vector<int> parent;
    int count;
    UF(int n): parent(n), count(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        parent[b] = a;
        --count;
        return true;
    }
};

void backtrack(const vector<pair<int,int>>& E,
               int n, int idx,
               vector<pair<int,int>>& chosen) {
    if((int)chosen.size() == n - 1) {
        UF uf(n);
        for(auto &e : chosen)
            if(!uf.unite(e.first, e.second))
                return;
        if(uf.count == 1)
            all_trees.push_back(chosen);
        return;
    }
    if(idx == (int)E.size()) return;
    // Bo chon E[idx]
    backtrack(E, n, idx + 1, chosen);
    // Chon E[idx]
    chosen.push_back(E[idx]);
    backtrack(E, n, idx + 1, chosen);
    chosen.pop_back();
}

int main() {
    Graph G(7);
    vector<pair<int,int>> edges = {
        {1,2},{1,3},{3,6},{6,4},{4,1},
        {2,4},{4,7},{7,2},{2,5},{5,7},{6,7}
    };
    for(auto &e : edges)
        G.add_edge(e.first-1, e.second-1);
    auto E = G.edges();
    vector<pair<int,int>> chosen;
    backtrack(E, G.n, 0, chosen);
    cout << "So spanning trees tim duoc: "
         << all_trees.size() << "\n";
    return 0;
}