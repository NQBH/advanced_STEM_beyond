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

int cost_relabel(TreeNode* n1, TreeNode* n2) {
    return (n1->val == n2->val) ? 0 : 1;
}

int ted_dp(TreeNode* T1, TreeNode* T2) {
    if (!T1 && !T2) return 0;
    if (!T1) return tree_size(T2);
    if (!T2) return tree_size(T1);
    
    // Three operations:
    // 1. Relabel
    int cost1 = cost_relabel(T1, T2) + ted_dp(T1->left, T2->left) + ted_dp(T1->right, T2->right);
    
    // 2. Delete T1
    int cost2 = 1 + ted_dp(T1->left, T2) + ted_dp(T1->right, T2);
    
    // 3. Insert T2
    int cost3 = 1 + ted_dp(T1, T2->left) + ted_dp(T1, T2->right);
    
    return min({cost1, cost2, cost3});
}

int main() {
    TreeNode* T1 = read_tree("../tree1.inp");
    TreeNode* T2 = read_tree("../tree2.inp");
    
    int distance = ted_dp(T1, T2);
    cout << "Dynamic Programming - Tree Edit Distance: " << distance << endl;
    cout << "Done" << endl;
    
    return 0;
}