#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* build_tree(int edges[][3], int n) {
    if (n == 0) return nullptr;
    
    map<int, Node*> nodes;
    set<int> children;
    
    for (int i = 0; i < n; i++) {
        int parent = edges[i][0];
        int left = edges[i][1];
        int right = edges[i][2];
        
        if (nodes.find(parent) == nodes.end())
            nodes[parent] = new Node(parent);
            
        if (left != -1) {
            if (nodes.find(left) == nodes.end())
                nodes[left] = new Node(left);
            nodes[parent]->left = nodes[left];
            children.insert(left);
        }
        
        if (right != -1) {
            if (nodes.find(right) == nodes.end())
                nodes[right] = new Node(right);
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

void bottomup(Node* root) {
    if (!root) return;
    queue<Node*> q;
    stack<int> s;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        s.push(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    ifstream infile("../tree_sample.inp");
    if (!infile.is_open()) {
        cout << "Error: tree_sample.inp not found\n";
        return 1;
    }
    
    int n;
    infile >> n;
    int edges[1000][3];
    
    for (int i = 0; i < n; i++) {
        infile >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    
    Node* root = build_tree(edges, n);
    
    cout << "Bottom-up:\n";
    bottomup(root);
    cout << "\nDone\n";
    
    return 0;
}