#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void bfs(unordered_map<char, vector<char>>& graph, char start) {
    unordered_set<char> visited;
    queue<char> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        cout << node << " ";

        for (char neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph;
    graph['A'] = {'B', 'C'};
    graph['B'] = {'D', 'E'};
    graph['C'] = {'F'};
    graph['D'] = {};
    graph['E'] = {'F'};
    graph['F'] = {};

    cout << "Thứ tự duyệt BFS: ";
    bfs(graph, 'A');
    cout << endl;

    return 0;
}