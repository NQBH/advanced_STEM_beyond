#include <bits/stdc++.h>
#include "Graph_Tree.h"
using namespace std;

const double INF = numeric_limits<double>::infinity();

// Dijkstra
pair<map<Graph::Vertex*, double>, map<Graph::Vertex*, Graph::Edge*>> 
dijkstra(const Graph* graph, Graph::Vertex* start_node) {
    map<Graph::Vertex*, double> distances;
    map<Graph::Vertex*, Graph::Edge*> shortest_path_tree;
    for (Graph::Vertex* v : graph->vertices()) { distances[v] = INF; }
    if (start_node) distances[start_node] = 0;
    using P = pair<double, Graph::Vertex*>;
    priority_queue<P, vector<P>, greater<P>> pq;
    if (start_node) pq.push({0.0, start_node});
    while(!pq.empty()) {
        double d = pq.top().first; Graph::Vertex* u = pq.top().second; pq.pop();
        if (d > distances[u]) continue;
        for (auto const& [v, edges_to_v] : graph->get_outgoing_map(u)) {
            for (Graph::Edge* edge : edges_to_v) {
                if (distances[u] + edge->weight() < distances[v]) {
                    distances[v] = distances[u] + edge->weight();
                    shortest_path_tree[v] = edge;
                    pq.push({distances[v], v});
                }
            }
        }
    }
    return {distances, shortest_path_tree};
}

// Reconstruct Path 
vector<Graph::Vertex*> reconstruct_path(Graph::Vertex* start, Graph::Vertex* end, const map<Graph::Vertex*, Graph::Edge*>& tree) {
    vector<Graph::Vertex*> path;
    if (tree.find(end) == tree.end() && start != end) return path;
    Graph::Vertex* curr = end;
    while(curr != start) {
        path.push_back(curr);
        if (tree.find(curr) == tree.end()) return {};
        curr = tree.at(curr)->source();
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

// Tree Edit Graph
void preorder_tree_traversal(Tree* T);
void preorder_tree_depth(Tree* T);

Graph* tree_edit_graph(Tree* T1, Tree* T2, double del_cost, double sub_cost, double ins_cost) {
    Graph* G = new Graph(false); 
    int n1 = T1->number_of_nodes();
    int n2 = T2->number_of_nodes();

    preorder_tree_traversal(T1); preorder_tree_depth(T1);
    preorder_tree_traversal(T2); preorder_tree_depth(T2);

    vector<int> d1(n1 + 1);
    for (auto v : T1->vertices()) d1[v->order] = v->depth;
    vector<int> d2(n2 + 1);
    for (auto w : T2->vertices()) d2[w->order] = w->depth;
    
    vector<vector<Graph::Vertex*>> A(n1 + 1, vector<Graph::Vertex*>(n2 + 1));
    for (int i = 0; i <= n1; ++i) for (int j = 0; j <= n2; ++j) A[i][j] = G->new_vertex(i * (n2 + 1) + j);

    for (int i = 0; i < n1; ++i) G->new_edge(A[i][n2], A[i + 1][n2], del_cost);
    for (int j = 0; j < n2; ++j) G->new_edge(A[n1][j], A[n1][j + 1], ins_cost);

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (d1[i + 1] >= d2[j + 1]) G->new_edge(A[i][j], A[i + 1][j], del_cost);
            if (d1[i + 1] == d2[j + 1]) G->new_edge(A[i][j], A[i + 1][j + 1], sub_cost);
            if (d1[i + 1] <= d2[j + 1]) G->new_edge(A[i][j], A[i][j + 1], ins_cost);
        }
    }
    return G;
}

void print_edit_graph_grid(const Graph* edit_graph, int n1, int n2, const vector<Graph::Vertex*>& path) {
    cout << "\nTree Edit Graph\n";
    set<Graph::Vertex*> path_nodes(path.begin(), path.end());
    set<pair<Graph::Vertex*, Graph::Vertex*>> path_edges;
    for(size_t i = 0; i < path.size() - 1; ++i) path_edges.insert({path[i], path[i+1]});

    int rows = n1 * 2 + 1; int cols = n2 * 4 + 1;
    vector<vector<char>> grid(rows, vector<char>(cols, ' '));
    auto vertices = edit_graph->vertices();
    
    map<Graph::Vertex*, pair<int, int>> v_to_coord;
    for(int i = 0; i <= n1; ++i) for(int j = 0; j <= n2; ++j) {
        Graph::Vertex* v = vertices[i * (n2 + 1) + j];
        int r = i * 2, c = j * 4;
        grid[r][c] = path_nodes.count(v) ? '#' : '*';
        v_to_coord[v] = {r, c};
    }
    
    for(const auto& edge : edit_graph->edges()) {
        auto coord1 = v_to_coord.at(edge->source()); auto coord2 = v_to_coord.at(edge->target());
        int r1 = coord1.first, c1 = coord1.second, r2 = coord2.first, c2 = coord2.second;
        bool on_path = path_edges.count({edge->source(), edge->target()});
        
        if (r1 == r2 && c1 != c2) { // Ngang
             for(int c=min(c1,c2)+1; c<max(c1,c2); ++c) grid[r1][c] = on_path ? '=' : '-';
        } else if (c1 == c2 && r1 != r2) { // Dọc
            grid[r1 + 1][c1] = on_path ? 'H' : '|';
        } else { // Chéo
            grid[r1 + 1][c1 + 2] = on_path ? 'X' : '\\';
        }
    }
    
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) cout << grid[i][j];
        cout << endl;
    }
     cout << "-------------------------------------\n\n";
}


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

    double del_cost, sub_cost, ins_cost;
    cout << "Del-Sub-Ins (e.g., 1 2 1): ";
    cin >> del_cost >> sub_cost >> ins_cost;

    Graph* edit_graph = tree_edit_graph(&T1, &T2, del_cost, sub_cost, ins_cost);
    
    // Shortest path: top-left đến bottom-right
    auto vertices = edit_graph->vertices();
    Graph::Vertex* start_node = vertices.front();
    Graph::Vertex* end_node = vertices.back();

    auto [distances, tree] = dijkstra(edit_graph, start_node);
    
    if (distances.at(end_node) == INF) {
        cout << "\nNo path.\n";
    } else {
        cout << "\nShortest path: " << distances.at(end_node) << endl;
        vector<Graph::Vertex*> shortest_path = reconstruct_path(start_node, end_node, tree);
        print_edit_graph_grid(edit_graph, T1.number_of_nodes(), T2.number_of_nodes(), shortest_path);
    }

    delete edit_graph;
    return 0;
}


void preorder_tree_traversal(Tree* T) { 
    if (T->get_root() == nullptr) return; int num = 0; 
    for(auto v : T->vertices()) v->order = -1; stack<Tree::Vertex*> S; 
    S.push(T->get_root()); 
    while (!S.empty()) { 
        Tree::Vertex* v = S.top(); 
        S.pop(); num++; 
        v->order = num; 
        vector<Tree::Vertex*> children = T->get_children(v);
        reverse(children.begin(), children.end()); 
        for (Tree::Vertex* w : children) S.push(w); 
    } 
}
void preorder_tree_depth(Tree* T) { 
    Tree::Vertex* root = T->get_root(); 
    if (root == nullptr) return; 
    for(auto v : T->vertices()) v->depth = -1; 
    stack<Tree::Vertex*> S; 
    S.push(root); 
    while (!S.empty()) { 
        Tree::Vertex* v = S.top(); 
        S.pop(); 
        if (T->is_root(v)) v->depth = 0; 
        else v->depth = T->get_parent(v)->depth + 1;vector<Tree::Vertex*> children = T->get_children(v);reverse(children.begin(), children.end());
        for (Tree::Vertex* w : children) S.push(w);  
    } 
}