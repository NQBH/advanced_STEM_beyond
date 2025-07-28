#include <bits/stdc++.h>
#include "Graph_Tree.h"
using namespace std;

void preorder_tree_traversal(Tree* T);
void preorder_tree_depth(Tree* T);
Graph* tree_edit_graph(Tree* T1, Tree* T2);
void print_edit_graph_grid(const Graph* edit_graph, int n1, int n2);
Tree* read_tree_from_input(const string& tree_name);

int main() {
    freopen("tree_input.txt", "r", stdin);

    Tree T1; int n1; cin >> n1;
    vector<Graph::Vertex*> v1;
    for(int i=0; i<n1; ++i) v1.push_back(T1.new_node(i));
    for(int i = 0; i < n1-1; ++i) {
        int u, v; cin >> u >> v;
        T1.new_edge(v1[u], v1[v]);
    }

    Tree T2; int n2; cin >> n2;
    vector<Graph::Vertex*> v2;
    for(int i=0; i<n2; ++i) v2.push_back(T2.new_node(i));
    for(int i = 0; i < n2-1; ++i) {
        int u, v; cin >> u >> v;
        T2.new_edge(v2[u], v2[v]);
    }

    Graph* edit_graph = tree_edit_graph(&T1, &T2);
    print_edit_graph_grid(edit_graph, T1.number_of_nodes(), T2.number_of_nodes());
    
    delete edit_graph;
    return 0;
}

void preorder_tree_traversal(Tree* T) {
    if (T->get_root() == nullptr) return; int num = 0;
    for(auto v : T->vertices()) v->order = -1;
    stack<Tree::Vertex*> S; S.push(T->get_root());
    while (!S.empty()) {
        Tree::Vertex* v = S.top(); S.pop(); num++; v->order = num;
        vector<Tree::Vertex*> children = T->get_children(v);
        reverse(children.begin(), children.end());
        for (Tree::Vertex* w : children) { S.push(w); }
    }
}
void preorder_tree_depth(Tree* T) {
    Tree::Vertex* root = T->get_root(); if (root == nullptr) return;
    for(auto v : T->vertices()) v->depth = -1;
    stack<Tree::Vertex*> S; S.push(root);
    while (!S.empty()) {
        Tree::Vertex* v = S.top(); S.pop();
        if (T->is_root(v)) { v->depth = 0; }
        else { v->depth = T->get_parent(v)->depth + 1; }
        vector<Tree::Vertex*> children = T->get_children(v);
        reverse(children.begin(), children.end());
        for (Tree::Vertex* w : children) { S.push(w); }
    }
}
Graph* tree_edit_graph(Tree* T1, Tree* T2) {
    Graph* G = new Graph(true); 
    int n1 = T1->number_of_nodes();
    int n2 = T2->number_of_nodes();

    preorder_tree_traversal(T1);
    preorder_tree_traversal(T2);
    preorder_tree_depth(T1);
    preorder_tree_depth(T2);

    vector<int> d1(n1 + 1);
    for (auto v : T1->vertices()) d1[v->order] = v->depth;
    vector<int> d2(n2 + 1);
    for (auto w : T2->vertices()) d2[w->order] = w->depth;
    
    vector<vector<Graph::Vertex*>> A(n1 + 1, vector<Graph::Vertex*>(n2 + 1));
    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            A[i][j] = G->new_vertex(i * (n2 + 1) + j);
        }
    }

    for (int i = 0; i < n1; ++i) G->new_edge(A[i][n2], A[i + 1][n2]);
    for (int j = 0; j < n2; ++j) G->new_edge(A[n1][j], A[n1][j + 1]);

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (d1[i + 1] >= d2[j + 1]) G->new_edge(A[i][j], A[i + 1][j]);
            if (d1[i + 1] == d2[j + 1]) G->new_edge(A[i][j], A[i + 1][j + 1]);
            if (d1[i + 1] <= d2[j + 1]) G->new_edge(A[i][j], A[i][j + 1]);
        }
    }
    return G;
}
void print_edit_graph_grid(const Graph* edit_graph, int n1, int n2) {
    int rows = n1 * 2 + 1;
    int cols = n2 * 4 + 1;
    vector<vector<char>> grid(rows, vector<char>(cols, ' '));
    auto vertices = edit_graph->vertices();
    
    map<Graph::Vertex*, pair<int, int>> v_to_coord;
    for(int i = 0; i <= n1; ++i) {
        for(int j = 0; j <= n2; ++j) {
            Graph::Vertex* v = vertices[i * (n2 + 1) + j];
            int r = i * 2;
            int c = j * 4;
            grid[r][c] = '*';
            v_to_coord[v] = {r, c};
        }
    }
    
    for(const auto& edge : edit_graph->edges()) {
        auto coord1 = v_to_coord.at(edge->source());
        auto coord2 = v_to_coord.at(edge->target());
        int r1 = coord1.first, c1 = coord1.second;
        int r2 = coord2.first, c2 = coord2.second;
        
        if (r1 == r2 && c1 != c2) { // Horizontal
             for(int c=min(c1,c2)+1; c<max(c1,c2); ++c) grid[r1][c] = '-';
        } else if (c1 == c2 && r1 != r2) { // Vertical
            grid[r1 + 1][c1] = '|';
        } else { // Diagonal
            grid[r1 + 1][c1 + 2] = '\\';
        }
    }
    
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) { cout << grid[i][j]; }
        cout << endl;
    }
}