#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class SimpleGraphMatrix;
class SimpleGraphList;
class SimpleGraphExtendedList;
class SimpleGraphMap;

class Edge {
public:
    int source;
    int target;
    double weight;
    
    Edge(int src, int tgt, double w = 1.0) 
        : source(src), target(tgt), weight(w) {}
    
    friend ostream& operator<<(ostream& os, const Edge& e) {
        os << "(" << e.source << "→" << e.target << ")";
        return os;
    }
};

class SimpleGraphMatrix {
public:
    int num_vertices;
    vector<vector<int>> matrix;
    
    SimpleGraphMatrix(int n) : num_vertices(n) {
        matrix.resize(n, vector<int>(n, 0));
    }
    
    void add_edge(int u, int v) {
        if (is_valid_vertex(u) && is_valid_vertex(v)) {
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
    }
    
    void display() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": [";
            for (int j = 0; j < num_vertices; j++) {
                cout << matrix[i][j];
                if (j < num_vertices - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
    
private:
    bool is_valid_vertex(int v) const {
        return v >= 0 && v < num_vertices;
    }
};

class SimpleGraphList {
public:
    int num_vertices;
    vector<vector<int>> adj_list;
    
    SimpleGraphList(int n) : num_vertices(n) {
        adj_list.resize(n);
    }
    
    void add_edge(int u, int v) {
        if (is_valid_vertex(u) && is_valid_vertex(v)) {
            if (find(adj_list[u].begin(), adj_list[u].end(), v) == adj_list[u].end()) {
                adj_list[u].push_back(v);
            }
            if (find(adj_list[v].begin(), adj_list[v].end(), u) == adj_list[v].end()) {
                adj_list[v].push_back(u);
            }
        }
    }
    
    void display() const {
        cout << "List:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": [";
            for (size_t j = 0; j < adj_list[i].size(); j++) {
                cout << adj_list[i][j];
                if (j < adj_list[i].size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
    
private:
    bool is_valid_vertex(int v) const {
        return v >= 0 && v < num_vertices;
    }
};

class SimpleGraphExtendedList {
public:
    int num_vertices;
    vector<vector<Edge>> outgoing;
    vector<vector<Edge>> incoming;
    vector<Edge> all_edges;
    
    SimpleGraphExtendedList(int n) : num_vertices(n) {
        outgoing.resize(n);
        incoming.resize(n);
    }
    
    void display() const {
        cout << "Extended List:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": [";
            for (size_t j = 0; j < outgoing[i].size(); j++) {
                cout << outgoing[i][j];
                if (j < outgoing[i].size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
};

class SimpleGraphMap {
public:
    int num_vertices;
    vector<unordered_set<int>> adj_map;
    
    SimpleGraphMap(int n) : num_vertices(n) {
        adj_map.resize(n);
    }
    
    void add_edge(int u, int v) {
        if (is_valid_vertex(u) && is_valid_vertex(v)) {
            adj_map[u].insert(v);
            adj_map[v].insert(u);
        }
    }
    
    void display() const {
        cout << "Map:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": {";
            bool first = true;
            for (int v : adj_map[i]) {
                if (!first) cout << ", ";
                cout << v;
                first = false;
            }
            cout << "}" << endl;
        }
    }
    
private:
    bool is_valid_vertex(int v) const {
        return v >= 0 && v < num_vertices;
    }
};

SimpleGraphMatrix read_graph_from_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return SimpleGraphMatrix(0);
    }
    int num_vertices;
    file >> num_vertices;
    SimpleGraphMatrix graph(num_vertices);
    int u, v;
    int edges_count = 0;
    while (file >> u >> v) {
        graph.add_edge(u, v);
        edges_count++;
    }
    file.close();
    return graph;
}

SimpleGraphList matrix_to_list(const SimpleGraphMatrix& matrix_graph) {
    int n = matrix_graph.num_vertices;
    SimpleGraphList list_graph(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (matrix_graph.matrix[i][j] == 1) {
                if (i == j) {
                    list_graph.adj_list[i].push_back(j);
                } else {
                    list_graph.adj_list[i].push_back(j);
                    list_graph.adj_list[j].push_back(i);
                }
            }
        }
    }
    
    return list_graph;
}

SimpleGraphMatrix list_to_matrix(const SimpleGraphList& list_graph) {
    int n = list_graph.num_vertices;
    SimpleGraphMatrix matrix_graph(n);
    
    for (int u = 0; u < n; u++) {
        for (int v : list_graph.adj_list[u]) {
            matrix_graph.matrix[u][v] = 1;
        }
    }
    
    return matrix_graph;
}

SimpleGraphExtendedList matrix_to_extended_list(const SimpleGraphMatrix& matrix_graph) {
    int n = matrix_graph.num_vertices;
    SimpleGraphExtendedList ext_graph(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (matrix_graph.matrix[i][j] == 1) {
                Edge edge_ij(i, j);
                ext_graph.outgoing[i].push_back(edge_ij);
                ext_graph.incoming[j].push_back(edge_ij);
                ext_graph.all_edges.push_back(edge_ij);
                
                if (i != j) {
                    Edge edge_ji(j, i);
                    ext_graph.outgoing[j].push_back(edge_ji);
                    ext_graph.incoming[i].push_back(edge_ji);
                    ext_graph.all_edges.push_back(edge_ji);
                }
            }
        }
    }
    
    return ext_graph;
}

SimpleGraphMatrix extended_list_to_matrix(const SimpleGraphExtendedList& ext_graph) {
    int n = ext_graph.num_vertices;
    SimpleGraphMatrix matrix_graph(n);
    
    for (const Edge& edge : ext_graph.all_edges) {
        matrix_graph.matrix[edge.source][edge.target] = 1;
    }
    
    return matrix_graph;
}

SimpleGraphExtendedList list_to_extended_list(const SimpleGraphList& list_graph) {
    int n = list_graph.num_vertices;
    SimpleGraphExtendedList ext_graph(n);
    
    set<pair<int, int>> processed_edges;
    
    for (int u = 0; u < n; u++) {
        for (int v : list_graph.adj_list[u]) {
            pair<int, int> edge_key = make_pair(min(u, v), max(u, v));
            if (processed_edges.find(edge_key) == processed_edges.end()) {
                processed_edges.insert(edge_key);
                
                Edge edge_uv(u, v);
                ext_graph.outgoing[u].push_back(edge_uv);
                ext_graph.incoming[v].push_back(edge_uv);
                ext_graph.all_edges.push_back(edge_uv);
                
                if (u != v) {
                    Edge edge_vu(v, u);
                    ext_graph.outgoing[v].push_back(edge_vu);
                    ext_graph.incoming[u].push_back(edge_vu);
                    ext_graph.all_edges.push_back(edge_vu);
                }
            }
        }
    }
    
    return ext_graph;
}

SimpleGraphList extended_list_to_list(const SimpleGraphExtendedList& ext_graph) {
    int n = ext_graph.num_vertices;
    SimpleGraphList list_graph(n);
    
    for (int u = 0; u < n; u++) {
        for (const Edge& edge : ext_graph.outgoing[u]) {
            int v = edge.target;
            if (find(list_graph.adj_list[u].begin(), list_graph.adj_list[u].end(), v) 
                == list_graph.adj_list[u].end()) {
                list_graph.adj_list[u].push_back(v);
            }
        }
    }
    
    return list_graph;
}

SimpleGraphMap matrix_to_map(const SimpleGraphMatrix& matrix_graph) {
    int n = matrix_graph.num_vertices;
    SimpleGraphMap map_graph(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix_graph.matrix[i][j] == 1) {
                map_graph.adj_map[i].insert(j);
            }
        }
    }
    
    return map_graph;
}

SimpleGraphMatrix map_to_matrix(const SimpleGraphMap& map_graph) {
    int n = map_graph.num_vertices;
    SimpleGraphMatrix matrix_graph(n);
    
    for (int u = 0; u < n; u++) {
        for (int v : map_graph.adj_map[u]) {
            matrix_graph.matrix[u][v] = 1;
        }
    }
    
    return matrix_graph;
}

SimpleGraphMap list_to_map(const SimpleGraphList& list_graph) {
    int n = list_graph.num_vertices;
    SimpleGraphMap map_graph(n);
    
    for (int u = 0; u < n; u++) {
        for (int v : list_graph.adj_list[u]) {
            map_graph.adj_map[u].insert(v);
        }
    }
    
    return map_graph;
}

SimpleGraphList map_to_list(const SimpleGraphMap& map_graph) {
    int n = map_graph.num_vertices;
    SimpleGraphList list_graph(n);
    
    for (int u = 0; u < n; u++) {
        for (int v : map_graph.adj_map[u]) {
            list_graph.adj_list[u].push_back(v);
        }
    }
    
    return list_graph;
}

SimpleGraphMap extended_list_to_map(const SimpleGraphExtendedList& ext_graph) {
    int n = ext_graph.num_vertices;
    SimpleGraphMap map_graph(n);
    
    for (int u = 0; u < n; u++) {
        for (const Edge& edge : ext_graph.outgoing[u]) {
            map_graph.adj_map[u].insert(edge.target);
        }
    }
    
    return map_graph;
}

SimpleGraphExtendedList map_to_extended_list(const SimpleGraphMap& map_graph) {
    SimpleGraphList list_graph = map_to_list(map_graph);
    return list_to_extended_list(list_graph);
}

void test_all_converters_with_file() {
    cout << "TEST: All 12 Simple Graph Converters (Đọc từ file)" << endl;
    cout << string(60, '=') << endl;
    
    SimpleGraphMatrix original = read_graph_from_file("../simple_graph_sample.inp");
    if (original.num_vertices == 0) {
        return;
    }
    original.display();
    
    cout << "\n=== 1. FROM MATRIX ===" << endl;
    SimpleGraphList list_result = matrix_to_list(original);
    SimpleGraphExtendedList ext_result = matrix_to_extended_list(original);
    SimpleGraphMap map_result = matrix_to_map(original);
    
    cout << "1.1. Matrix → List:" << endl;
    list_result.display();
    cout << "1.2. Matrix → ExtList:" << endl;
    ext_result.display();
    cout << "1.3. Matrix → Map:" << endl;
    map_result.display();
    
    // Test từ List
    cout << "\n=== 2. FROM LIST ===" << endl;
    cout << "2.1. List → Matrix:" << endl;
    list_to_matrix(list_result).display();
    cout << "2.2. List → ExtList:" << endl;
    list_to_extended_list(list_result).display();
    cout << "2.3. List → Map:" << endl;
    list_to_map(list_result).display();
    
    // Test từ ExtList
    cout << "\n=== 3. FROM EXTENDED LIST ===" << endl;
    cout << "3.1. ExtList → Matrix:" << endl;
    extended_list_to_matrix(ext_result).display();
    cout << "3.2. ExtList → List:" << endl;
    extended_list_to_list(ext_result).display();
    cout << "3.3. ExtList → Map:" << endl;
    extended_list_to_map(ext_result).display();
    
    // Test từ Map
    cout << "\n=== 4. FROM MAP ===" << endl;
    cout << "4.1. Map → Matrix:" << endl;
    map_to_matrix(map_result).display();
    cout << "4.2. Map → List:" << endl;
    map_to_list(map_result).display();
    cout << "4.3. Map → ExtList:" << endl;
    map_to_extended_list(map_result).display();
    
    cout << "\n DONE" << endl;
}

int main() {
    cout << "🎯 BÀI TOÁN 4: SIMPLE GRAPH CONVERTERS - C++ VERSION" << endl;
    test_all_converters_with_file();
    return 0;
}