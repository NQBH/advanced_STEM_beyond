// problem7.cpp
// Full implementation for various tree traversal algorithms on a binary tree.

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

// A node in a binary tree.
struct TreeNode {
    string value;
    TreeNode *left;
    TreeNode *right;
    
    // Constructor for convenience.
    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

// --- (a) Pre-order Traversal (DFS: Root -> Left -> Right) ---
void preorder_traversal(TreeNode* node, vector<string>& result) {
    if (node == nullptr) return;
    result.push_back(node->value);       // Visit root
    preorder_traversal(node->left, result);  // Traverse left subtree
    preorder_traversal(node->right, result); // Traverse right subtree
}

// --- (b) Post-order Traversal (DFS: Left -> Right -> Root) ---
void postorder_traversal(TreeNode* node, vector<string>& result) {
    if (node == nullptr) return;
    postorder_traversal(node->left, result);  // Traverse left subtree
    postorder_traversal(node->right, result); // Traverse right subtree
    result.push_back(node->value);       // Visit root
}

// --- (c) Top-down Traversal (BFS / Level-order) ---
vector<string> top_down_traversal(TreeNode* root) {
    if (root == nullptr) return {};
    
    vector<string> result;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        result.push_back(current->value);
        
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return result;
}

// --- (d) Bottom-up Traversal (Reverse Level-order) ---
// This implementation uses a queue and a stack. It's a common and efficient method.
vector<string> bottom_up_traversal(TreeNode* root) {
    if (root == nullptr) return {};
    
    vector<string> result;
    queue<TreeNode*> q;
    stack<string> s;

    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        s.push(current->value); // Instead of printing, push to stack
        
        // IMPORTANT: Enqueue right child before left child.
        // This makes the stack contain the correct reverse level order.
        if (current->right) q.push(current->right);
        if (current->left) q.push(current->left);
    }
    
    // Pop from the stack to get the final bottom-up order.
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

/**
 * @brief Helper function to print a vector of strings in a formatted way.
 * @param vec The vector to print.
 */
void print_vector(const vector<string>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "'" << vec[i] << "'" << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

/**
 * @brief Main function to build the example tree and demonstrate the traversals.
 */
int main() {
    // Constructing the example tree using dynamic allocation:
    //         F
    //        / \
    //       B   G
    //      / \   \
    //     A   D   I
    //        / \ /
    //       C  E H
    TreeNode* root = new TreeNode("F");
    root->left = new TreeNode("B");
    root->right = new TreeNode("G");
    root->left->left = new TreeNode("A");
    root->left->right = new TreeNode("D");
    root->left->right->left = new TreeNode("C");
    root->left->right->right = new TreeNode("E");
    root->right->right = new TreeNode("I");
    root->right->right->left = new TreeNode("H");

    cout << "--- Problem 7: Tree Traversals ---" << endl;
    cout << "For the following tree structure:" << endl;
    cout << "        F\n       / \\\n      B   G\n     / \\   \\\n    A   D   I\n       / \\ /\n      C  E H\n" << endl;

    // (a) Pre-order
    vector<string> preorder_res;
    preorder_traversal(root, preorder_res);
    cout << "(a) Pre-order Traversal:  ";
    print_vector(preorder_res);

    // (b) Post-order
    vector<string> postorder_res;
    postorder_traversal(root, postorder_res);
    cout << "(b) Post-order Traversal: ";
    print_vector(postorder_res);

    // (c) Top-down
    vector<string> top_down_res = top_down_traversal(root);
    cout << "(c) Top-down Traversal:   ";
    print_vector(top_down_res);

    // (d) Bottom-up
    vector<string> bottom_up_res = bottom_up_traversal(root);
    cout << "(d) Bottom-up Traversal:  ";
    print_vector(bottom_up_res);

    // In a real-world application, you would need to deallocate the memory
    // for each node to avoid memory leaks. For this simple example, we omit it.
    // e.g., via a post-order deletion function.
    // delete root->left->left; ... etc.
    
    return 0;
}