#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<pair<int, int>> edges = {
    {1, 2}, {1, 3}, {1, 5},
    {2, 3}, {2, 5},
    {3, 4}, {3, 5},
    {4, 5}
};

map<int, vector<int>> graph;

map<pair<int, int>, bool> used;

int totalPaths = 0;

void prepareGraph() {
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
        used[{min(u, v), max(u, v)}] = false;
    }

    for (auto &entry : graph) {
        sort(entry.second.begin(), entry.second.end());
    }
}

void dfs(vector<int>& path, int usedEdges) {
    if (usedEdges == 8) {
        for (int v : path) cout << v;
        cout << endl;
        totalPaths++;
        return;
    }

    int u = path.back();
    for (int v : graph[u]) {
        pair<int, int> edge = {min(u, v), max(u, v)};
        if (!used[edge]) {
            used[edge] = true;
            path.push_back(v);
            dfs(path, usedEdges + 1);
            path.pop_back();
            used[edge] = false;
        }
    }
}

int main() {
    prepareGraph();
    vector<int> path = {1};
    dfs(path, 0);
    cout << "Total valid paths: " << totalPaths << endl;
    return 0;
}