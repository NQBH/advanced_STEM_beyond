#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> bfs_all_paths(const vector<vector<int>>& graph, int start, int target) {
    vector<vector<int>> all_paths;
    queue<pair<int, vector<int>>> q;
    q.emplace(start, vector<int>{start});
    
    while (!q.empty()) {
        auto [cur, path] = q.front(); q.pop();
        
        if (cur == target) {
            all_paths.push_back(path);
            continue;
        }
        
        for (int next : graph[cur]) {
            if (find(path.begin(), path.end(), next) == path.end()) {
                auto new_path = path;
                new_path.push_back(next);
                q.emplace(next, move(new_path));
            }
        }
    }
    
    return all_paths;
}

int main() {
    int n = 8, v_s = 1, v_t = 5;
    vector<vector<int>> graph(n + 1), neighbors = {
        {}, {2, 3}, {3, 4}, {1, 5}, {6}, {}, {2}, {8}, {}
    };
    
    for (int i = 1; i <= n; ++i) graph[i] = neighbors[i];
    
    auto paths = bfs_all_paths(graph, v_s, v_t);
    
    if (paths.empty()) {
        cout << "No path found from " << v_s << " to " << v_t << ".\n";
        return 0;
    }
    
    cout << "All paths from " << v_s << " to " << v_t << ":\n";
    for (const auto& path : paths) {
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");
    }
    
    return 0;
}