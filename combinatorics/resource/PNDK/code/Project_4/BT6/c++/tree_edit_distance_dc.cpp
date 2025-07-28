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

int ted_divide_conquer(TreeNode* T1, TreeNode* T2) {
    if (!T1 && !T2) return 0;
    if (!T1) return tree_size(T2);
    if (!T2) return tree_size(T1);
    

    int relabel_cost = (T1->val == T2->val) ? 0 : 1;
    int left_cost = ted_divide_conquer(T1->left, T2->left);
    int right_cost = ted_divide_conquer(T1->right, T2->right);
    int cost1 = relabel_cost + left_cost + right_cost;
    
    int delete_cost = 1 + tree_size(T1->left) + tree_size(T1->right);
    int cost2 = delete_cost + ted_divide_conquer(nullptr, T2);
    
    int insert_cost = 1 + tree_size(T2->left) + tree_size(T2->right);
    int cost3 = insert_cost + ted_divide_conquer(T1, nullptr);
    
    return min({cost1, cost2, cost3});
}

int main() {
    TreeNode* T1 = read_tree("../tree1.inp");
    TreeNode* T2 = read_tree("../tree2.inp");
    
    int distance = ted_divide_conquer(T1, T2);
    cout << "Divide & Conquer - Tree Edit Distance: " << distance << endl;
    cout << "Done" << endl;
    
    return 0;
}