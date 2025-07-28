#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct State {
    int cost;
    TreeNode* t1;
    TreeNode* t2;
    
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
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

int lower_bound(TreeNode* T1, TreeNode* T2) {
    int size1 = tree_size(T1);
    int size2 = tree_size(T2);
    return abs(size1 - size2);
}

int ted_branch_bound(TreeNode* T1, TreeNode* T2) {
    if (!T1 && !T2) return 0;
    if (!T1) return tree_size(T2);
    if (!T2) return tree_size(T1);
    
    priority_queue<State, vector<State>, greater<State>> pq;
    int best_cost = INT_MAX;
    
    pq.push({0, T1, T2});
    
    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        
        if (current.cost >= best_cost) continue;
        
        TreeNode* t1 = current.t1;
        TreeNode* t2 = current.t2;
        
        if (!t1 && !t2) {
            best_cost = min(best_cost, current.cost);
            continue;
        }
        if (!t1) {
            best_cost = min(best_cost, current.cost + tree_size(t2));
            continue;
        }
        if (!t2) {
            best_cost = min(best_cost, current.cost + tree_size(t1));
            continue;
        }
        
        // Three operations
        int relabel_cost = (t1->val == t2->val) ? 0 : 1;
        pq.push({current.cost + relabel_cost, t1->left, t2->left});
        pq.push({current.cost + relabel_cost, t1->right, t2->right});
        
        pq.push({current.cost + 1, t1->left, t2});
        pq.push({current.cost + 1, t1->right, t2});
        
        pq.push({current.cost + 1, t1, t2->left});
        pq.push({current.cost + 1, t1, t2->right});
    }
    
    return best_cost;
}

int main() {
    TreeNode* T1 = read_tree("../tree1.inp");
    TreeNode* T2 = read_tree("../tree2.inp");
    
    int distance = ted_branch_bound(T1, T2);
    cout << "Branch & Bound - Tree Edit Distance: " << distance << endl;
    cout << "Done" << endl;
    
    return 0;
}