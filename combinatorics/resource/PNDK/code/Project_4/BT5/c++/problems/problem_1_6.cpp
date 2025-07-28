#include <iostream>
#include <vector>
#include <stack>
using namespace std;

pair<bool, string> is_tree(vector<vector<int>>& graph, int n_vertices) {
    // Đếm số cạnh
    int edge_count = 0;
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            if (graph[i][j]) {
                edge_count++;
            }
        }
    }
    
    // Kiểm tra điều kiện cơ bản
    if (edge_count != n_vertices - 1) {
        return {false, "Edge count != vertex count - 1"};
    }
    
    // Kiểm tra liên thông bằng DFS
    vector<bool> visited(n_vertices, false);
    stack<int> stk;
    stk.push(0);
    int visited_count = 0;
    
    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();
        if (!visited[v]) {
            visited[v] = true;
            visited_count++;
            for (int w = 0; w < n_vertices; w++) {
                if (graph[v][w] && !visited[w]) {
                    stk.push(w);
                }
            }
        }
    }
    
    if (visited_count != n_vertices) {
        return {false, "Not connected"};
    }
    
    return {true, "Valid tree"};
}

int main() {
    // Test case 1: Cây hợp lệ
    vector<vector<int>> tree1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    auto result = is_tree(tree1, 3);
    cout << "Test 1 - Linear tree: " << (result.first ? "true" : "false") 
         << " (" << result.second << ")" << endl;
    
    // Test case 2: Có chu trình
    vector<vector<int>> cycle = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    result = is_tree(cycle, 3);
    cout << "Test 2 - Cycle: " << (result.first ? "true" : "false") 
         << " (" << result.second << ")" << endl;
    
    return 0;
}