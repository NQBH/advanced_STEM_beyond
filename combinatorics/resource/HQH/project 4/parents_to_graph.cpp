#include <iostream>
#include <vector>
using namespace std;

// Convert array of parents to graph-based representation (adjacency list)
vector<vector<int>> parentsToGraph(const vector<int>& parents) {
    int n = parents.size();
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < n; i++) {
        if (parents[i] != -1) {
            // Add bidirectional edge between parent and child
            graph[parents[i]].push_back(i);
            graph[i].push_back(parents[i]);
        }
    }
    
    return graph;
}

void printGraph(const vector<vector<int>>& graph) {
    cout << "Graph-based representation (adjacency list):" << endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << "Node " << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example parent array
    vector<int> parents = {-1, 0, 0, 0, 1, 1, 3};
    
    cout << "Original Parent Array:" << endl;
    cout << "Index:  ";
    for (int i = 0; i < parents.size(); i++) {
        cout << i << " ";
    }
    cout << endl << "Parent: ";
    for (int p : parents) {
        if (p == -1) cout << "- ";
        else cout << p << " ";
    }
    cout << endl << endl;
    
    vector<vector<int>> graph = parentsToGraph(parents);
    printGraph(graph);
    
    return 0;
}
