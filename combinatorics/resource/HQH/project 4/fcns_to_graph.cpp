#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    int firstChild;
    int nextSibling;
    
    TreeNode(int val) : data(val), firstChild(-1), nextSibling(-1) {}
};

// Convert first-child next-sibling to graph representation
vector<vector<int>> fcnsToGraph(const vector<TreeNode>& nodes) {
    int n = nodes.size();
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < n; i++) {
        int child = nodes[i].firstChild;
        while (child != -1) {
            // Add bidirectional edge between parent and child
            graph[i].push_back(child);
            graph[child].push_back(i);
            child = nodes[child].nextSibling;
        }
    }
    
    return graph;
}

void printGraph(const vector<vector<int>>& graph) {
    cout << "Graph-based representation:" << endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << "Node " << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example first-child next-sibling representation
    vector<TreeNode> nodes = {
        TreeNode(0), TreeNode(1), TreeNode(2), 
        TreeNode(3), TreeNode(4), TreeNode(5), TreeNode(6)
    };
    
    // Set up relationships
    nodes[0].firstChild = 1;
    nodes[1].nextSibling = 2;
    nodes[2].nextSibling = 3;
    nodes[1].firstChild = 4;
    nodes[4].nextSibling = 5;
    nodes[3].firstChild = 6;
    
    cout << "Original First-Child Next-Sibling:" << endl;
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
    cout << endl;
    
    vector<vector<int>> graph = fcnsToGraph(nodes);
    printGraph(graph);
    
    return 0;
}
