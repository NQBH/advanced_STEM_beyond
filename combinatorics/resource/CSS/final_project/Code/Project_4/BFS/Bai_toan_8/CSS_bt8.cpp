#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class SimpleGraph {
public:
    int n;
    vector<vector<int>> adj;

    SimpleGraph(int vertices) : n(vertices) {
        adj.resize(n);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected
    }

    void bfs(int s) {
        vector<bool> visited(n, false);
        vector<int> distance(n, -1);
        queue<int> Q;

        visited[s] = true;
        distance[s] = 0;
        Q.push(s);

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    Q.push(v);
                }
            }
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            if (distance[i] != -1) {
                cout << "Distance to " << i << ": " << distance[i] << endl;
            }
        }
    }
};

int main() {
    SimpleGraph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    cout << "BFS on Simple Graph: ";
    g.bfs(0);
    return 0;
}