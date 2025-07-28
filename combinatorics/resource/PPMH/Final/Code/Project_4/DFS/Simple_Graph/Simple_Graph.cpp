// dùng đệ quy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs_recursive(const unordered_map<char, vector<char>>& graph, char node, unordered_set<char>& visited) {
    cout << node << " ";
    visited.insert(node);

    for (char neighbor : graph.at(node)) {
        if (visited.find(neighbor) == visited.end()) {
            dfs_recursive(graph, neighbor, visited);
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

    unordered_set<char> visited;
    cout << "DFS bắt đầu từ đỉnh A:\n";
    dfs_recursive(graph, 'A', visited);

    return 0;
}