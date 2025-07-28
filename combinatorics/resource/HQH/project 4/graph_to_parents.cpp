#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Convert graph-based representation to array of parents using BFS
vector<int> graphToParents(const vector<vector<int>>& graph, int root) {
    int n = graph.size();
    vector<int> parents(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(root);
    visited[root] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parents[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    return parents;
}

void printParentArray(const vector<int>& parents) {
    cout << "Parent Array:" << endl;
    cout << "Index:  ";
    for (int i = 0; i < parents.size(); i++) {
        cout << i << " ";
    }
    cout << endl << "Parent: ";
    for (int p : parents) {
        if (p == -1) cout << "- ";
        else cout << p << " ";
    }
    cout << endl;
}

int main() {
    // Example graph representation (tree as undirected graph)
    vector<vector<int>> graph = {
        {1, 2, 3},      // node 0 connects to 1, 2, 3
        {0, 4, 5},      // node 1 connects to 0, 4, 5
        {0},            // node 2 connects to 0
        {0, 6},         // node 3 connects to 0, 6
        {1},            // node 4 connects to 1
        {1},            // node 5 connects to 1
        {3}             // node 6 connects to 3
    };
    
    cout << "Original Graph-based representation:" << endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << "Node " << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Convert to parent array with root = 0
    vector<int> parents = graphToParents(graph, 0);
    printParentArray(parents);
    
    return 0;
}
