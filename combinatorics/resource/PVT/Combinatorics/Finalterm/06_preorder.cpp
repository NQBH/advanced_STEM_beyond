#include <bits/stdc++.h>
#include "Graph_Tree.h"
using namespace std;

vector<int> root_tree(const vector<vector<int>>& adjList, int root_id) {
    int n = adjList.size(); 
    vector<int> parent(n, -1); 
    queue<int> q; q.push(root_id); 
    set<int> visited; visited.insert(root_id);
    while(!q.empty()){ 
        int p_idx = q.front(); q.pop(); 
        for(int child_idx : adjList[p_idx]){ 
            if(visited.find(child_idx) == visited.end()){ 
                visited.insert(child_idx); parent[child_idx] = p_idx; q.push(child_idx); 
            } 
        } 
    }
    return parent;
}
Tree* build_tree_from_parent_array(const vector<int>& parent) {
    Tree* tree = new Tree(); vector<Tree::Vertex*> nodes;
    for(size_t i = 0; i < parent.size(); ++i) { nodes.push_back(tree->new_node(i)); }
    for(size_t i = 0; i < parent.size(); ++i) { if (parent[i] != -1) { tree->new_edge(nodes[parent[i]], nodes[i]); } }
    return tree;
}


// 1. Recursive
void preorder_recursive_helper(Tree* T, Tree::Vertex* v) {
    T->num++;
    v->order = T->num;
    for (Tree::Vertex* w : T->get_children(v)) {
        preorder_recursive_helper(T, w);
    }
}
void preorder_tree_traversal_recursive(Tree* T) {
    if (T->get_root() == nullptr) return;
    T->num = 0; // Reset counter
    for(auto v : T->vertices()) v->order = -1; // Reset orders
    preorder_recursive_helper(T, T->get_root());
}

// 2. Iterative 
void preorder_tree_traversal_iterative_mutate(Tree* T) {
    Tree::Vertex* root = T->get_root();
    if (root == nullptr) return;

    for(auto v : T->vertices()) v->order = -1; // Reset orders
    stack<Tree::Vertex*> S;
    S.push(root);
    int num = 0;
    while (!S.empty()) {
        Tree::Vertex* v = S.top();
        S.pop();
        num++;
        v->order = num;
        
        vector<Tree::Vertex*> children = T->get_children(v);
        // Đảo ngược danh sách con trước khi đẩy vào stack
        reverse(children.begin(), children.end());
        for (Tree::Vertex* w : children) {
            S.push(w);
        }
    }
}

// 3. Iterative (returns list)
vector<Tree::Vertex*> preorder_tree_traversal_iterative_list(Tree* T) {
    vector<Tree::Vertex*> L;
    Tree::Vertex* root = T->get_root();
    if (root == nullptr) return L;

    stack<Tree::Vertex*> S;
    S.push(root);
    while (!S.empty()) {
        Tree::Vertex* v = S.top();
        S.pop();
        L.push_back(v);
        
        vector<Tree::Vertex*> children = T->get_children(v);
        reverse(children.begin(), children.end());
        for (Tree::Vertex* w : children) {
            S.push(w);
        }
    }
    return L;
}

int main() {
    vector<vector<int>> free_tree_adj_list = {
        {1, 5}, {0, 2, 3, 4}, {1}, {1}, {1}, 
        {0, 6, 9, 10}, {5, 7, 8}, {6}, {6}, {5, 11, 12}, 
        {5}, {9}, {9}
    };
    
    cout << "--- Root at node 0 ---\n";
    vector<int> parent_array = root_tree(free_tree_adj_list, 0);
    Tree* my_tree = build_tree_from_parent_array(parent_array);

    // Test 1: Recursive
    cout << "--- 1. Recursive Traversal (updates node.order) ---\n";
    preorder_tree_traversal_recursive(my_tree);
    cout << "Node Label -> Preorder Index:\n";
    auto vertices_sorted = my_tree->vertices();
    sort(vertices_sorted.begin(), vertices_sorted.end(), [](Tree::Vertex* a, Tree::Vertex* b){ return a->label() < b->label(); });
    for(auto v : vertices_sorted) {
        cout << "  - Node " << v->label() << " -> order: " << v->order << endl;
    }

    // Test 2: Iterative Mutate
    cout << "--- 2. Iterative Traversal (updates node.order) ---\n";
    preorder_tree_traversal_iterative_mutate(my_tree);
    cout << "Node Label -> Preorder Index:\n";
    for(auto v : vertices_sorted) {
        cout << "  - Node " << v->label() << " -> order: " << v->order << endl;
    }

    // Test 3: Iterative List
    cout << "--- 3. Iterative Traversal (returns a list) ---\n";
    vector<Tree::Vertex*> preorder_list = preorder_tree_traversal_iterative_list(my_tree);
    cout << "Preorder traversal list (by node label): ";
    for(auto v : preorder_list) {
        cout << v->label() << " ";
    }

    delete my_tree; 
    return 0;
}