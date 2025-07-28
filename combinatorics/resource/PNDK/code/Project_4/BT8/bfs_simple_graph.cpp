#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

void read_graph_from_file(const string& filename, int& n, vector<vector<int>>& adj) {
    ifstream fin(filename);
    int m;
    fin >> n >> m;
    adj.assign(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    for (int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
    fin.close();
}

vector<int> bfs(int n, const vector<vector<int>>& adj, int start) {
    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    vector<int> parent(n, -1);
    vector<int> visit_order;
    queue<int> q;
    
    visited[start] = true;
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        visit_order.push_back(vertex);
        for (int neighbor : adj[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[vertex] + 1;
                parent[neighbor] = vertex;
                q.push(neighbor);
            }
        }
    }
    
    cout << "Visit order: ";
    for (int v : visit_order) cout << v << " ";
    cout << endl;
    
    cout << "Distances from source: ";
    for (int d : distance) cout << d << " ";
    cout << endl;
    
    cout << "Parent array (BFS tree): ";
    for (int p : parent) cout << p << " ";
    cout << endl;
    
    return visit_order;
}

int main() {
    string filename = "simple_graph.inp";
    int n;
    vector<vector<int>> adj;
    read_graph_from_file(filename, n, adj);
    bfs(n, adj, 0);
    return 0;
}