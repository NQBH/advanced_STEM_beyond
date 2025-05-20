#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool dfs_path(const vector<vector<int>>& graph, int current, int goal, vector<bool>& visited, vector<int>& path) {
    visited[current] = true;
    path.push_back(current);

    if (current == goal) {
        return true;
    }

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            if (dfs_path(graph, neighbor, goal, visited, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

int main() {
    int n, Vs, Vt;
    cin >> n >> Vs >> Vt;
    cin.ignore();

    vector<vector<int>> graph(n + 1);

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int neighbor;
        while (ss >> neighbor) {
            graph[i].push_back(neighbor);
        }
    }

    vector<bool> visited(n + 1, false);
    vector<int> path;

    if (dfs_path(graph, Vs, Vt, visited, path)) {
        for (size_t i = 0; i < path.size(); ++i) {
            if (i > 0) cout << " -> ";
            cout << path[i];
        }
        cout << endl;
    } else {
        cout << "No path found from " << Vs << " to " << Vt << endl;
    }

    return 0;
}