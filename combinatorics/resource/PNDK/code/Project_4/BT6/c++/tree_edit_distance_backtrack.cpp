#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* read_tree(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        return nullptr;
    }
    
    int n;
    infile >> n;
    if (n == 0) return nullptr;
    
    map<int, TreeNode*> nodes;
    set<int> children;
    
    for (int i = 0; i < n; i++) {
        int parent, left, right;
        infile >> parent >> left >> right;
        
        if (nodes.find(parent) == nodes.end())
            nodes[parent] = new TreeNode(parent);
            
        if (left != -1) {
            if (nodes.find(left) == nodes.end())
                nodes[left] = new TreeNode(left);
            nodes[parent]->left = nodes[left];
            children.insert(left);
        }
        
        if (right != -1) {
            if (nodes.find(right) == nodes.end())
                nodes[right] = new TreeNode(right);
            nodes[parent]->right = nodes[right];
            children.insert(right);
        }
    }
    
    // Find root
    for (auto& pair : nodes) {
        if (children.find(pair.first) == children.end()) {
            return pair.second;
        }
    }
    return nullptr;
}

int tree_size(TreeNode* node) {
    if (!node) return 0;
    return 1 + tree_size(node->left) + tree_size(node->right);
}

int min_cost = INT_MAX;

void ted_backtrack(TreeNode* T1, TreeNode* T2, int current_cost) {
    if (current_cost >= min_cost) return; // Pruning
    
    if (!T1 && !T2) {
        min_cost = min(min_cost, current_cost);
        return;
    }
    if (!T1) {
        min_cost = min(min_cost, current_cost + tree_size(T2));
        return;
    }
    if (!T2) {
        min_cost = min(min_cost, current_cost + tree_size(T1));
        return;
    }
    
    // Relabel operation
    int relabel_cost = (T1->val == T2->val) ? 0 : 1;
    ted_backtrack(T1->left, T2->left, current_cost + relabel_cost);
    ted_backtrack(T1->right, T2->right, current_cost + relabel_cost);
    
    // Delete operation
    ted_backtrack(T1->left, T2, current_cost + 1);
    ted_backtrack(T1->right, T2, current_cost + 1);
    
    // Insert operation
    ted_backtrack(T1, T2->left, current_cost + 1);
    ted_backtrack(T1, T2->right, current_cost + 1);
}

int main() {
    TreeNode* T1 = read_tree("../tree1.inp");
    TreeNode* T2 = read_tree("../tree2.inp");
    
    min_cost = INT_MAX;
    ted_backtrack(T1, T2, 0);
    
    cout << "Backtracking - Tree Edit Distance: " << min_cost << endl;
    cout << "Done" << endl;
    
    return 0;
}