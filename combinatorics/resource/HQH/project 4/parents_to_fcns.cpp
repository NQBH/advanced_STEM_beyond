#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    int firstChild;
    int nextSibling;
    
    TreeNode(int val) : data(val), firstChild(-1), nextSibling(-1) {}
};

// Convert array of parents to first-child next-sibling representation
vector<TreeNode> parentsToFCNS(const vector<int>& parents) {
    int n = parents.size();
    vector<TreeNode> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(TreeNode(i));
    }
    
    // Build children lists for each node
    vector<vector<int>> children(n);
    for (int i = 0; i < n; i++) {
        if (parents[i] != -1) {
            children[parents[i]].push_back(i);
        }
    }
    
    // Set first child and next sibling relationships
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
    // Example: Tree with parent array
    // Tree structure:  0
    //                 /|\
    //                1 2 3
    //               /|   |
    //              4 5   6
    vector<int> parents = {-1, 0, 0, 0, 1, 1, 3};
    
    cout << "Original Parent Array:" << endl;
    cout << "Index: ";
    for (int i = 0; i < parents.size(); i++) {
        cout << i << " ";
    }
    cout << endl << "Parent: ";
    for (int p : parents) {
        if (p == -1) cout << "- ";
        else cout << p << " ";
    }
    cout << endl << endl;
    
    vector<TreeNode> fcns = parentsToFCNS(parents);
    printFCNS(fcns);
    
    return 0;
}
