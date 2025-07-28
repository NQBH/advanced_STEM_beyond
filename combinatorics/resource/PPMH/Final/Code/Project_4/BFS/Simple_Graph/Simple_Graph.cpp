#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void bfs(unordered_map<char, vector<char>> &graph, char start) {
    unordered_set<char> visited;
    queue<char> q;

    visited.insert(start);
    q.push(start);

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
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };

    cout << "BFS traversal từ đỉnh A: ";
    bfs(graph, 'A');
    cout << endl;

    return 0;
}
