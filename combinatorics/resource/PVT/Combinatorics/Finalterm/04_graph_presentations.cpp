#include <bits/stdc++.h>
#include "Graph_Tree.h"
using namespace std;

map<Graph::Vertex*, int> get_vertex_to_idx_map(const Graph* g);
void printMatrix(const vector<vector<int>>& matrix, const string& title);
void printList(const vector<vector<int>>& list, const string& title);
void printGraphObj(const Graph* g, const string& title);
bool areListsEqual(vector<vector<int>> list1, vector<vector<int>> list2);

vector<vector<int>> matrixToList(const vector<vector<int>>& m);
vector<vector<int>> listToMatrix(const vector<vector<int>>& l);
Graph* matrixToGraph(const vector<vector<int>>& matrix, bool is_undirected);
vector<vector<int>> graphToMatrix(const Graph* graph);
Graph* listToGraph(const vector<vector<int>>& l, bool u);
vector<vector<int>> graphToList(const Graph* g);

struct TestGraphInfo { 
    string name; 
    vector<vector<int>> matrix; 
    bool is_undirected; 
};
void read_graphs_from_input(vector<TestGraphInfo>& test_cases);
void run_all_tests(const TestGraphInfo& test);

int main() {    
    freopen("graph_input.txt", "r", stdin);
    vector<TestGraphInfo> test_cases;
    read_graphs_from_input(test_cases);

    for (auto& test : test_cases) { 
        run_all_tests(test);
    }

    return 0;
}

void read_graphs_from_input(vector<TestGraphInfo>& test_cases) {
    string line;
    int graph_count = 1;

    while (true) {
        if (!getline(cin, line) || line.empty()) {
            break; 
        }

        stringstream ss(line);
        int n, m;
        char type_char;
        if (!(ss >> n >> m >> type_char)) {
            cerr << "Invalid format.\n";
            continue;
        }

        bool is_undirected = (type_char == 'U' || type_char == 'u');
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        bool input_error = false;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            if (!(cin >> u >> v >> w)) {
                cerr << "Invalid edge format.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                input_error = true;
                break; 
            }
            if (u >= n || v >= n || u < 0 || v < 0) {
                 cerr << "Out of bound.\n";
                 continue;
            }
            matrix[u][v]++;
            if (is_undirected && u != v) {
                matrix[v][u]++;
            }
        }
        
        if (input_error) continue; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        string name = "Graph #" + to_string(graph_count) + " (" + (is_undirected ? "Undirected" : "Directed") + ")";
        test_cases.push_back({name, matrix, is_undirected});
        graph_count++;
    }
}

map<Graph::Vertex*, int> get_vertex_to_idx_map(const Graph* g) {
    map<Graph::Vertex*, int> v_to_idx;
    vector<Graph::Vertex*> sorted_verts = g->vertices();
    sort(sorted_verts.begin(), sorted_verts.end(), [](Graph::Vertex* a, Graph::Vertex* b){
        return a->id() < b->id();
    });
    for(size_t i = 0; i < sorted_verts.size(); ++i) {
        v_to_idx[sorted_verts[i]] = i;
    }
    return v_to_idx;
}
void printMatrix(const vector<vector<int>>& matrix, const string& title) { 
    cout << "--- " << title << " ---\n"; 
    for (const auto& row : matrix) { 
        for (int val : row) { 
            cout << val << " "; 
        } 
        cout << endl; 
    } 
    cout << "---------------------\n\n"; 
}

void printList(const vector<vector<int>>& list, const string& title) { 
    cout << "--- " << title << " ---\n"; 
    for (size_t i = 0; i < list.size(); ++i) { 
        cout << i << ": "; vector<int> sorted_neighbors = list[i]; sort(sorted_neighbors.begin(), sorted_neighbors.end());
        for (int neighbor : sorted_neighbors) { 
            cout << neighbor << " "; 
        } 
        cout << endl; 
    } 
    cout << "---------------------\n\n"; 
}

bool areListsEqual(vector<vector<int>> list1, vector<vector<int>> list2) { 
    if (list1.size() != list2.size()) return false; 
    for (size_t i = 0; i < list1.size(); ++i) { 
        sort(list1[i].begin(), list1[i].end()); sort(list2[i].begin(), list2[i].end()); 
        if (list1[i] != list2[i]) return false; 
    } 
    return true; 
}

void printGraphObj(const Graph* g, const string& title) {
    cout << "--- " << title << " ---\n";
    if (!g || g->vertices().empty()) { cout << "(empty)\n---------------------\n\n"; return; }
    
    auto v_to_idx = get_vertex_to_idx_map(g);
    vector<Graph::Vertex*> sorted_vertices = g->vertices();
    sort(sorted_vertices.begin(), sorted_vertices.end(), [](Graph::Vertex* a, Graph::Vertex* b){
        return a->id() < b->id();
    });

    for (auto const& v : sorted_vertices) {
        cout << "Vertex " << v_to_idx.at(v) << " (ID: " << v->id() << "):" << endl;
        
        cout << "  - incoming: [ ";
        for (auto const& [source_v, edges] : g->get_incoming_map(v)) {
            for (const auto& edge : edges) {
                cout << v_to_idx.at(source_v) << " to e" << edge->id() << " | ";
            }
        }
        cout << "]" << endl;
        cout << "  - outgoing: [ ";
        for (auto const& [target_v, edges] : g->get_outgoing_map(v)) {
            for (const auto& edge : edges) {
                cout << v_to_idx.at(v) << " to e" << edge->id() << " | ";
            }
        }
        cout << "]" << endl;
    }

    cout << "Edge List:" << endl;
    vector<Graph::Edge*> sorted_edges = g->edges();
    sort(sorted_edges.begin(), sorted_edges.end(), [](Graph::Edge* a, Graph::Edge* b){
        return a->id() < b->id();
    });
    for(auto const& edge : sorted_edges) {
        cout << "e" << edge->id() << ": " << v_to_idx.at(edge->source()) << " " << v_to_idx.at(edge->target()) << endl;
    }
    cout << "---------------------\n\n";
}

vector<vector<int>> matrixToList(const vector<vector<int>>& m) { 
    int n = m.size(); 
    vector<vector<int>> l(n); 
    for (int i=0; i<n; ++i) 
        for(int j=0; j<n; ++j) 
            for(int k=0; k<m[i][j]; ++k) 
                l[i].push_back(j); 
    return l; 
}

vector<vector<int>> listToMatrix(const vector<vector<int>>& l) {
    int n = l.size(); 
    vector<vector<int>> m(n, vector<int>(n, 0)); 
    for (size_t i=0; i<n; ++i) 
        for (int neighbor : l[i]) m[i][neighbor]++; 
    return m; 
}

Graph* matrixToGraph(const vector<vector<int>>& matrix, bool is_undirected) {
    auto* g = new Graph(is_undirected);
    vector<Graph::Vertex*> vertices;
    for(size_t i = 0; i < matrix.size(); ++i) vertices.push_back(g->new_vertex(0));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = (is_undirected ? i : 0); j < matrix.size(); ++j) {
            for (int k = 0; k < matrix[i][j]; ++k) {
                g->new_edge(vertices[i], vertices[j]);
            }
        }
    }
    return g;
}

vector<vector<int>> graphToMatrix(const Graph* graph) {
    auto v_to_idx = get_vertex_to_idx_map(graph); int n = v_to_idx.size();
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (auto const& e : graph->edges()) {
        int u = v_to_idx.at(e->source()); int v = v_to_idx.at(e->target());
        m[u][v]++;
        if (graph->is_undirected() && u != v) m[v][u]++;
    }
    return m;
}

Graph* listToGraph(const vector<vector<int>>& l, bool u) { return matrixToGraph(listToMatrix(l), u); }

vector<vector<int>> graphToList(const Graph* g) { return matrixToList(graphToMatrix(g)); }

void run_all_tests(const TestGraphInfo& test) {
    cout << "\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
    cout << "     TESTING: " << test.name << "\n";
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n" << endl;
    
    // Cycle 1: Matrix -> List -> Matrix
    cout << "===== Cycle 1: Matrix -> List -> Matrix =====\n";
    printMatrix(test.matrix, "Initial Matrix");
    auto list1 = matrixToList(test.matrix); printList(list1, "Intermediate List");
    auto matrix1 = listToMatrix(list1); printMatrix(matrix1, "Final Matrix");
    // cout << "Verification: " << (test.matrix == matrix1 ? "SUCCESS" : "FAILURE") << "\n";

    // Cycle 2: Matrix -> ExtList (Graph Obj) -> Matrix
    cout << "\n===== Cycle 2: Matrix -> ExtList -> Matrix =====\n";
    printMatrix(test.matrix, "Initial Matrix");
    auto extList2 = matrixToGraph(test.matrix, test.is_undirected); printGraphObj(extList2, "Intermediate ExtList");
    auto matrix2 = graphToMatrix(extList2); printMatrix(matrix2, "Final Matrix");
    // cout << "Verification: " << (test.matrix == matrix2 ? "SUCCESS" : "FAILURE") << "\n";
    delete extList2;

    // Cycle 3: Matrix -> AdjMap (Graph Obj) -> Matrix
    cout << "\n===== Cycle 3: Matrix -> AdjMap -> Matrix =====\n";
    printMatrix(test.matrix, "Initial Matrix");
    auto adjMap3 = matrixToGraph(test.matrix, test.is_undirected); printGraphObj(adjMap3, "Intermediate AdjMap");
    auto matrix3 = graphToMatrix(adjMap3); printMatrix(matrix3, "Final Matrix");
    // cout << "Verification: " << (test.matrix == matrix3 ? "SUCCESS" : "FAILURE") << "\n";
    delete adjMap3;

    auto initialList = matrixToList(test.matrix);

    // Cycle 4: List -> ExtList (Graph Obj) -> List
    cout << "\n===== Cycle 4: List -> ExtList -> List =====\n";
    printList(initialList, "Initial List");
    auto extList4 = listToGraph(initialList, test.is_undirected); printGraphObj(extList4, "Intermediate ExtList");
    auto finalList4 = graphToList(extList4); printList(finalList4, "Final List");
    // cout << "Verification: " << (areListsEqual(initialList, finalList4) ? "SUCCESS" : "FAILURE") << "\n";
    delete extList4;
    
    // Cycle 5: List -> AdjMap (Graph Obj) -> List
    cout << "\n===== Cycle 5: List -> AdjMap -> List =====\n";
    printList(initialList, "Initial List");
    auto adjMap5 = listToGraph(initialList, test.is_undirected); printGraphObj(adjMap5, "Intermediate AdjMap");
    auto finalList5 = graphToList(adjMap5); printList(finalList5, "Final List");
    // cout << "Verification: " << (areListsEqual(initialList, finalList5) ? "SUCCESS" : "FAILURE") << "\n";
    delete adjMap5;

    // Cycle 6: ExtList -> AdjMap -> ExtList
    cout << "\n===== Cycle 6: ExtList -> AdjMap -> ExtList =====\n";
    auto initialGraph6 = matrixToGraph(test.matrix, test.is_undirected);
    printGraphObj(initialGraph6, "Initial ExtList/AdjMap");
    // Since ExtList and AdjMap are the same class, "conversion" is a deep copy.
    // We simulate by converting to an intermediate form and back.
    auto tempList = graphToList(initialGraph6);
    auto finalGraph6 = listToGraph(tempList, test.is_undirected);
    printGraphObj(finalGraph6, "Final ExtList/AdjMap");
    // cout << "Verification: " << (initialGraph6->edges().size() == finalGraph6->edges().size() ? "SUCCESS" : "FAILURE") << " (Edge count check)\n";
    delete initialGraph6;
    delete finalGraph6;
}