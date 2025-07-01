#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

struct Edge {
    string neighbor;
    int cost;
};

unordered_map<string, vector<Edge>> graph;
unordered_map<string, int> heuristic;

void taiFileGraph(const string& filename) {
    ifstream file(filename);
    string city1, city2;
    int cost;

    while (file >> city1 >> city2 >> cost) {
        graph[city1].push_back({city2, cost});
        graph[city2].push_back({city1, cost});
    }
}

void taiFileHeuristic(const string& filename) {
    ifstream file(filename);
    string city;
    int h;

    while (file >> city >> h)
        heuristic[city] = h;
}
struct Node {
    string city;
    int cost;
    int totalCost;

    bool operator>(const Node& other) const {
        return totalCost > other.totalCost;
    }
};

void a_start(string start, string goal) {
    priority_queue<Node, vector<Node>, greater<Node>> openSet;
    unordered_map<string, int> gScore;
    unordered_map<string, string>cameFrom;
    set<string> visited;

    for (const auto& node : graph) {
        gScore[node.first] = INT_MAX;
    }
    gScore[start] = 0;
    openSet.push({start, 0, heuristic[start]});

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.city == goal) {
            vector<string> path;
            for (string at = goal; !at.empty(); at = cameFrom[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());

            cout << "\n A* Path from " << start << "to " << goal << ":\n";
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1)cout << " -> ";
            }
            cout << "\n Total cost: " << gScore[goal] << "\n";
            return;
        }
        if (visited.count(current.city)) continue;
        visited.insert(current.city);

        for (const Edge& edge : graph[current.city]) {
            int tentative_g = gScore[current.city] + edge.cost;
            if (tentative_g < gScore[edge.neighbor]) {
                cameFrom[edge.neighbor] = current.city;
                gScore[edge.neighbor] = tentative_g;
                int f = tentative_g + heuristic[edge.neighbor];
                openSet.push({edge.neighbor, tentative_g, f});
            }
        }
    }
    cout << "No path found.\n";
}
int main() {
    taiFileGraph("graph.txt");
    taiFileHeuristic("heuristic.txt");

    string start = "Arad";
    string goal = "Bucharest";

    a_start(start, goal);
    return 0;
}