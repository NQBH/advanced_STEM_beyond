#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    int firstChild;
    int nextSibling;
    
    TreeNode(int val) : data(val), firstChild(-1), nextSibling(-1) {}
};

// Convert graph to first-child next-sibling using BFS to establish parent-child relationships
vector<TreeNode> graphToFCNS(const vector<vector<int>>& graph, int root) {
    int n = graph.size();
    vector<TreeNode> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(TreeNode(i));
    }
    
    vector<bool> visited(n, false);
    vector<vector<int>> children(n);
    queue<int> q;
    
    q.push(root);
    visited[root] = true;
    
    // Build parent-child relationships using BFS
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                children[current].push_back(neighbor);
                q.push(neighbor);
            }
        }
    }
    
    // Convert to first-child next-sibling
    for (int i = 0; i < n; i++) {
        if (!children[i].empty()) {
            nodes[i].firstChild = children[i][0];
            
            // Link siblings
            for (int j = 0; j < children[i].size() - 1; j++) {
                int child = children[i][j];
                int nextChild = children[i][j + 1];
                nodes[child].nextSibling = nextChild;
            }
        }
    }
    
    return nodes;
}

void printFCNS(const vector<TreeNode>& nodes) {
    cout << "First-Child Next-Sibling representation:" << endl;
    cout << "Node | FirstChild | NextSibling" << endl;
    cout << "-----|------------|------------" << endl;
    for (const TreeNode& node : nodes) {
        cout << "  " << node.data << "  |";
        if (node.firstChild != -1) {
            cout << "     " << node.firstChild << "      |";
        } else {
            cout << "    null     |";
        }
        if (node.nextSibling != -1) {
            cout << "     " << node.nextSibling;
        } else {
            cout << "    null";
        }
        cout << endl;
    }
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
    
    // Convert to FCNS with root = 0
    vector<TreeNode> fcns = graphToFCNS(graph, 0);
    printFCNS(fcns);
    
    return 0;
}
