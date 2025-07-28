#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void bfs(const unordered_map<char, vector<char>>& graph, char start) {
    unordered_set<char> visited;
    queue<char> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        char vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (char neighbor : graph.at(vertex)) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };

    char start_vertex = 'A';
    cout << "BFS Order: ";
    bfs(graph, start_vertex);
    cout << endl;

    return 0;
}