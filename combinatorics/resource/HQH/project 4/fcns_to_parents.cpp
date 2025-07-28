#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    int firstChild;
    int nextSibling;
    
    TreeNode(int val) : data(val), firstChild(-1), nextSibling(-1) {}
};

// Convert first-child next-sibling to array of parents
vector<int> fcnsToParents(const vector<TreeNode>& nodes) {
    int n = nodes.size();
    vector<int> parents(n, -1);
    
    for (int i = 0; i < n; i++) {
        int child = nodes[i].firstChild;
        while (child != -1) {
            parents[child] = i;
            child = nodes[child].nextSibling;
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
    // Example first-child next-sibling representation
    vector<TreeNode> nodes = {
        TreeNode(0), TreeNode(1), TreeNode(2), 
        TreeNode(3), TreeNode(4), TreeNode(5), TreeNode(6)
    };
    
    // Set up relationships manually for demonstration
    nodes[0].firstChild = 1;    // 0's first child is 1
    nodes[1].nextSibling = 2;   // 1's next sibling is 2
    nodes[2].nextSibling = 3;   // 2's next sibling is 3
    nodes[1].firstChild = 4;    // 1's first child is 4
    nodes[4].nextSibling = 5;   // 4's next sibling is 5
    nodes[3].firstChild = 6;    // 3's first child is 6
    
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
    
    vector<int> parents = fcnsToParents(nodes);
    printParentArray(parents);
    
    return 0;
}
