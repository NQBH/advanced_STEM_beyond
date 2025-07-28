#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

pair<vector<int>, vector<int>> dijkstra_multigraph(vector<vector<pii>>& adj_list, int start) {
    int n = adj_list.size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto& edge : adj_list[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (u == v) continue;  // Skip self-loops
            
            if (!visited[v]) {
                int new_dist = dist[u] + weight;
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    parent[v] = u;
                    pq.push({new_dist, v});
                }
            }
        }
    }
    
    return {dist, parent};
}

vector<vector<pii>> read_multigraph(string filename) {
    ifstream file(filename);
    int n, m;
    file >> n >> m;
    
    vector<vector<pii>> adj_list(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        file >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    
    file.close();
    return adj_list;
}

vector<int> reconstruct_path(vector<int>& parent, int start, int end) {
    if (parent[end] == -1 && start != end) {
        return {};
    }
    
    vector<int> path;
    int current = end;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    
    reverse(path.begin(), path.end());
    return path;
}

void print_result(vector<int>& dist, vector<int>& parent, int start) {
    cout << "Khoang cach ngan nhat tu dinh " << start << ":" << endl;
    
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == INT_MAX) {
            cout << "Dinh " << i << ": Khong the den" << endl;
        } else {
            vector<int> path = reconstruct_path(parent, start, i);
            cout << "Dinh " << i << ": " << dist[i] << " | Duong di: ";
            
            for (int j = 0; j < path.size(); j++) {
                cout << path[j];
                if (j < path.size() - 1) cout << " -> ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<vector<pii>> adj_list = read_multigraph("multigraph.inp");
    int start_vertex = 0;
    auto result = dijkstra_multigraph(adj_list, start_vertex);
    vector<int> distances = result.first;
    vector<int> parents = result.second;
    
    print_result(distances, parents, start_vertex);
    
    return 0;
}