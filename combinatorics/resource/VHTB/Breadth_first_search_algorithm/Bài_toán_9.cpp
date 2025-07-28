#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs_multigraph(const vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1,1,2},
        {0,0,2},
        {0,1,3},
        {2}
    };

    cout << "BFS traversal: ";
    bfs_multigraph(graph, 0);
    cout << endl;

    return 0;
}
