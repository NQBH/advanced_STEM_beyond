#include <bits/stdc++.h>
#define SantaHouse ios_base::sync_with_stdio(0)
using namespace std;

map<int, vector<int>> adj;
set<pair<int, int>> usedEdges;
vector<int> path;
vector<string> allPaths;

void dfs(int u) {
    path.push_back(u);
    if (path.size() == 9) { // 8 edges -> 9 nodes
        allPaths.push_back("");
        for (int v : path) allPaths.back() += to_string(v);
    } else {
        for (int v : adj[u]) {
            pair<int, int> e = minmax(u, v);
            if (usedEdges.find(e) == usedEdges.end()) {
                usedEdges.insert(e);
                dfs(v);
                usedEdges.erase(e);
            }
        }
    }
    path.pop_back();
}

int main() {
    SantaHouse;

    // Undirected edges of the House of Santa Claus
    vector<pair<int, int>> edges = {
        {1, 2}, {2, 3}, {3, 5}, {5, 1},
        {1, 3}, {2, 5}, {3, 4}, {4, 5}
    };

    for (auto &[u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Start from odd-degree vertices: 1 and 3
    for (int start : {1, 3}) {
        dfs(start);
    }

    sort(allPaths.begin(), allPaths.end());
    cout << allPaths.size() << "\n";
    for (string &s : allPaths)
        cout << s << "\n";

    return 0;
}