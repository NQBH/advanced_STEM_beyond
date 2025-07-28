#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

const double INF = numeric_limits<double>::infinity();

pair<vector<double>, unordered_map<string, string>> dijkstra(
    const unordered_map<string, unordered_map<string, double>>& graph, 
    const string& start) {
    
    vector<double> distances(1000, INF); 
    unordered_map<string, double> dist_map;
    for (const auto& node : graph) {
        dist_map[node.first] = INF;
    }
    dist_map[start] = 0;
    
    unordered_map<string, string> predecessors;
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<>> pq;
    pq.push({0, start});
    
    vector<bool> visited(1000, false);
    
    while (!pq.empty()) {
        double current_distance = pq.top().first;
        string current_node = pq.top().second;
        pq.pop();
        
        if (visited[current_node[0] - 'A']) continue;
        
        visited[current_node[0] - 'A'] = true;
        for (const auto& neighbor : graph.at(current_node)) {
            string next_node = neighbor.first;
            double weight = neighbor.second;
            
            if (!visited[next_node[0] - 'A']) {
                double distance = current_distance + weight;
                if (distance < dist_map[next_node]) {
                    dist_map[next_node] = distance;
                    predecessors[next_node] = current_node;
                    pq.push({distance, next_node});
                }
            }
        }
    }
    
    return {distances, predecessors};
}

vector<string> get_path(const unordered_map<string, string>& predecessors, const string& end) {
    vector<string> path;
    string current = end;
    while (predecessors.find(current) != predecessors.end() || current == end) {
        path.push_back(current);
        if (predecessors.find(current) == predecessors.end()) break;
        current = predecessors.at(current);
    }
    reverse(path.begin(), path.end());
    return path;
}

// Example usage
int main() {
    unordered_map<string, unordered_map<string, double>> graph = {
        {"A", {{"B", 4}, {"C", 2}}},
        {"B", {{"A", 4}, {"C", 1}, {"D", 5}}},
        {"C", {{"A", 2}, {"B", 1}, {"D", 8}, {"E", 10}}},
        {"D", {{"B", 5}, {"C", 8}, {"E", 2}}},
        {"E", {{"C", 10}, {"D", 2}}}
    };
    
    string start_node = "A";
    auto [distances, predecessors] = dijkstra(graph, start_node);
    
    cout << "Shortest distances from node " << start_node << endl;
    for (const auto& node : graph) {
        cout << "To " << node.first << ": " << (dist_map[node.first] == INF ? "INF" : to_string(dist_map[node.first])) << endl;
    }
    
    string end_node = "E";
    vector<string> path = get_path(predecessors, end_node);
    cout << "\nShortest path to " << end_node << ": ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;
    
    return 0;
}