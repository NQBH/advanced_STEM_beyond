#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

typedef pair<int, int> pii;

bool check_negative_weights(vector<vector<pii>>& adj_list, int& neg_u, int& neg_v, int& neg_w) {
    for (int u = 0; u < adj_list.size(); u++) {
        for (auto& edge : adj_list[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (weight < 0) {
                neg_u = u; neg_v = v; neg_w = weight;
                return true;
            }
        }
    }
    return false;
}

pair<vector<int>, vector<int>> dijkstra_general(vector<vector<pii>>& adj_list, int start) {
    int n = adj_list.size();
    
    // Kiểm tra trọng số âm
    int neg_u, neg_v, neg_w;
    if (check_negative_weights(adj_list, neg_u, neg_v, neg_w)) {
        cout << "Phát hiện trọng số âm tại cạnh " << neg_u << "→" << neg_v 
             << " (trọng số: " << neg_w << ")" << endl;

        return {{}, {}};
    }
    
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
        
        // Duyệt tất cả cạnh đi ra từ u (directed)
        for (auto& edge : adj_list[u]) {
            int v = edge.first;
            int weight = edge.second;
            
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

pair<vector<vector<pii>>, string> read_general_graph(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Không thể mở file " + filename);
    }
    
    string first_line;
    getline(file, first_line);
    
    string graph_type = "directed";  // mặc định
    int n, m;
    
    if (first_line[0] == '#') {
        // Đọc loại đồ thị từ header
        stringstream ss(first_line);
        string hash, type;
        ss >> hash >> type;
        graph_type = type;
        
        // Đọc n, m từ dòng tiếp theo
        file >> n >> m;
    } else {
        // Format mặc định
        stringstream ss(first_line);
        ss >> n >> m;
    }
    
    vector<vector<pii>> adj_list(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        file >> u >> v >> w;
        adj_list[u].push_back({v, w});
        
        // Nếu undirected thì thêm cạnh ngược
        if (graph_type == "undirected") {
            adj_list[v].push_back({u, w});
        }
    }
    
    file.close();
    return {adj_list, graph_type};
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

void print_result(vector<int>& dist, vector<int>& parent, int start, string graph_type) {
    cout << "Khoang cach ngan nhat tu dinh " << start << " (" << graph_type << "):" << endl;
    
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
    try {
        auto [adj_list, graph_type] = read_general_graph("general_graph.inp");

        //auto [adj_list, graph_type] = read_general_graph("negative_graph.inp");
        
        int start_vertex = 0;
        auto [distances, parents] = dijkstra_general(adj_list, start_vertex);
        
        if (!distances.empty()) { 
            print_result(distances, parents, start_vertex, graph_type);
        }
        
    } catch (const exception& e) {
        cout << "❌ Lỗi: " << e.what() << endl;
    }
    
    return 0;
}