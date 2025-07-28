#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Edge {
public:
    int source, target, edge_id;
    double weight;
    
    Edge(int src, int tgt, double w = 1.0, int id = 0) 
        : source(src), target(tgt), weight(w), edge_id(id) {}
    
    friend ostream& operator<<(ostream& os, const Edge& e) {
        os << "(" << e.source << "→" << e.target << "#" << e.edge_id << ")";
        return os;
    }
};

class MultigraphMatrix {
public:
    int num_vertices;
    vector<vector<int>> matrix;
    
    MultigraphMatrix(int n) : num_vertices(n) {
        matrix.resize(n, vector<int>(n, 0));
    }
    
    void add_edge(int u, int v, int count = 1) {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            matrix[u][v] += count;
            matrix[v][u] += count;
        }
    }
    
    void display() const {
        cout << "Multigraph Matrix:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": [";
            for (int j = 0; j < num_vertices; j++) {
                cout << matrix[i][j];
                if (j < num_vertices - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
};

class MultigraphList {
public:
    int num_vertices;
    vector<vector<int>> adj_list;
    
    MultigraphList(int n) : num_vertices(n) {
        adj_list.resize(n);
    }
    
    void add_edge(int u, int v, int count = 1) {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            for (int i = 0; i < count; i++) {
                adj_list[u].push_back(v);
                adj_list[v].push_back(u);  // Undirected
            }
        }
    }
    
    void display() const {
        cout << "Multigraph List:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": [";
            for (size_t j = 0; j < adj_list[i].size(); j++) {
                cout << adj_list[i][j];
                if (j < adj_list[i].size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
};

class MultigraphExtendedList {
public:
    int num_vertices, edge_id_counter;
    vector<vector<Edge>> outgoing;
    vector<vector<Edge>> incoming;
    vector<Edge> all_edges;
    
    MultigraphExtendedList(int n) : num_vertices(n), edge_id_counter(0) {
        outgoing.resize(n);
        incoming.resize(n);
    }
    
    void add_edge(int u, int v, double weight = 1.0, int count = 1) {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            for (int i = 0; i < count; i++) {
                Edge edge_uv(u, v, weight, edge_id_counter++);
                outgoing[u].push_back(edge_uv);
                incoming[v].push_back(edge_uv);
                all_edges.push_back(edge_uv);
                
                if (u != v) {
                    Edge edge_vu(v, u, weight, edge_id_counter++);
                    outgoing[v].push_back(edge_vu);
                    incoming[u].push_back(edge_vu);
                    all_edges.push_back(edge_vu);
                }
            }
        }
    }
    
    void display() const {
        cout << "Multigraph Extended List:" << endl;
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

class MultigraphMap {
public:
    int num_vertices;
    vector<unordered_map<int, int>> adj_map;
    
    MultigraphMap(int n) : num_vertices(n) {
        adj_map.resize(n);
    }
    
    void add_edge(int u, int v, int count = 1) {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            adj_map[u][v] += count;
            adj_map[v][u] += count;
        }
    }
    
    void display() const {
        cout << "Multigraph Map:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": {";
            bool first = true;
            for (const auto& p : adj_map[i]) {
                if (!first) cout << ", ";
                cout << p.first << ": " << p.second;
                first = false;
            }
            cout << "}" << endl;
        }
    }
};


MultigraphMatrix read_multigraph_from_file(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return MultigraphMatrix(0);
    }
    int num_vertices;
    file >> num_vertices;
    MultigraphMatrix graph(num_vertices);
    string line;
    getline(file, line); 
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<int> parts;
        int num;
        while (ss >> num) parts.push_back(num);
        
        if (parts.size() >= 2) {
            int u = parts[0], v = parts[1];
            int count = (parts.size() >= 3) ? parts[2] : 1;
            graph.add_edge(u, v, count);
        }
    }
    
    file.close();
    return graph;
}

MultigraphList matrix_to_list(const MultigraphMatrix& m) {
    MultigraphList result(m.num_vertices);
    for (int i = 0; i < m.num_vertices; i++) {
        for (int j = i; j < m.num_vertices; j++) {
            int count = m.matrix[i][j];
            if (count > 0) {
                if (i == j) {
                    for (int k = 0; k < count; k++) {
                        result.adj_list[i].push_back(j);
                    }
                } else {
                    for (int k = 0; k < count; k++) {
                        result.adj_list[i].push_back(j);
                        result.adj_list[j].push_back(i);
                    }
                }
            }
        }
    }
    return result;
}

MultigraphMatrix list_to_matrix(const MultigraphList& l) {
    MultigraphMatrix result(l.num_vertices);
    for (int u = 0; u < l.num_vertices; u++) {
        unordered_map<int, int> count_map;
        for (int v : l.adj_list[u]) {
            count_map[v]++;
        }
        for (const auto& p : count_map) {
            result.matrix[u][p.first] = p.second;
        }
    }
    return result;
}

MultigraphExtendedList matrix_to_extended_list(const MultigraphMatrix& m) {
    MultigraphExtendedList result(m.num_vertices);
    for (int i = 0; i < m.num_vertices; i++) {
        for (int j = i; j < m.num_vertices; j++) {
            int count = m.matrix[i][j];
            if (count > 0) {
                for (int k = 0; k < count; k++) {
                    Edge e1(i, j, 1.0, result.edge_id_counter++);
                    result.outgoing[i].push_back(e1);
                    result.incoming[j].push_back(e1);
                    result.all_edges.push_back(e1);
                    
                    if (i != j) {
                        Edge e2(j, i, 1.0, result.edge_id_counter++);
                        result.outgoing[j].push_back(e2);
                        result.incoming[i].push_back(e2);
                        result.all_edges.push_back(e2);
                    }
                }
            }
        }
    }
    return result;
}

MultigraphMatrix extended_list_to_matrix(const MultigraphExtendedList& e) {
    MultigraphMatrix result(e.num_vertices);
    map<pair<int, int>, int> edge_counts;
    
    for (const Edge& edge : e.all_edges) {
        pair<int, int> key = make_pair(edge.source, edge.target);
        edge_counts[key]++;
    }
    
    for (const auto& entry : edge_counts) {
        int u = entry.first.first;
        int v = entry.first.second;
        int count = entry.second;
        result.matrix[u][v] = count;
    }
    
    return result;
}

MultigraphExtendedList list_to_extended_list(const MultigraphList& l) {
    MultigraphExtendedList result(l.num_vertices);
    map<pair<int, int>, int> edge_counts;
    
    // Count edges in canonical form
    for (int u = 0; u < l.num_vertices; u++) {
        for (int v : l.adj_list[u]) {
            int min_v = min(u, v);
            int max_v = max(u, v);
            pair<int, int> canonical = make_pair(min_v, max_v);
            edge_counts[canonical]++;
        }
    }
    
    // Create edges
    for (const auto& entry : edge_counts) {
        int u = entry.first.first;
        int v = entry.first.second;
        int total_count = entry.second;
        int actual_count = (u == v) ? total_count : total_count / 2;
        
        for (int k = 0; k < actual_count; k++) {
            Edge e1(u, v, 1.0, result.edge_id_counter++);
            result.outgoing[u].push_back(e1);
            result.incoming[v].push_back(e1);
            result.all_edges.push_back(e1);
            
            if (u != v) {
                Edge e2(v, u, 1.0, result.edge_id_counter++);
                result.outgoing[v].push_back(e2);
                result.incoming[u].push_back(e2);
                result.all_edges.push_back(e2);
            }
        }
    }
    
    return result;
}

MultigraphList extended_list_to_list(const MultigraphExtendedList& e) {
    MultigraphList result(e.num_vertices);
    for (int u = 0; u < e.num_vertices; u++) {
        for (const Edge& edge : e.outgoing[u]) {
            result.adj_list[u].push_back(edge.target);
        }
    }
    return result;
}

MultigraphMap matrix_to_map(const MultigraphMatrix& m) {
    MultigraphMap result(m.num_vertices);
    for (int i = 0; i < m.num_vertices; i++) {
        for (int j = 0; j < m.num_vertices; j++) {
            if (m.matrix[i][j] > 0) {
                result.adj_map[i][j] = m.matrix[i][j];
            }
        }
    }
    return result;
}

MultigraphMatrix map_to_matrix(const MultigraphMap& m) {
    MultigraphMatrix result(m.num_vertices);
    for (int u = 0; u < m.num_vertices; u++) {
        for (const auto& p : m.adj_map[u]) {
            result.matrix[u][p.first] = p.second;
        }
    }
    return result;
}

MultigraphMap list_to_map(const MultigraphList& l) {
    MultigraphMap result(l.num_vertices);
    for (int u = 0; u < l.num_vertices; u++) {
        unordered_map<int, int> counts;
        for (int v : l.adj_list[u]) {
            counts[v]++;
        }
        result.adj_map[u] = counts;
    }
    return result;
}

MultigraphList map_to_list(const MultigraphMap& m) {
    MultigraphList result(m.num_vertices);
    for (int u = 0; u < m.num_vertices; u++) {
        for (const auto& p : m.adj_map[u]) {
            int v = p.first;
            int count = p.second;
            for (int k = 0; k < count; k++) {
                result.adj_list[u].push_back(v);
            }
        }
    }
    return result;
}

MultigraphMap extended_list_to_map(const MultigraphExtendedList& e) {
    MultigraphMap result(e.num_vertices);
    for (int u = 0; u < e.num_vertices; u++) {
        unordered_map<int, int> counts;
        for (const Edge& edge : e.outgoing[u]) {
            counts[edge.target]++;
        }
        result.adj_map[u] = counts;
    }
    return result;
}

MultigraphExtendedList map_to_extended_list(const MultigraphMap& m) {
    MultigraphExtendedList result(m.num_vertices);
    set<pair<int, int>> processed;
    
    for (int u = 0; u < m.num_vertices; u++) {
        for (const auto& p : m.adj_map[u]) {
            int v = p.first;
            int count = p.second;
            
            int min_v = min(u, v);
            int max_v = max(u, v);
            pair<int, int> canonical = make_pair(min_v, max_v);
            
            if (processed.find(canonical) == processed.end()) {
                processed.insert(canonical);
                
                for (int k = 0; k < count; k++) {
                    Edge e1(u, v, 1.0, result.edge_id_counter++);
                    result.outgoing[u].push_back(e1);
                    result.incoming[v].push_back(e1);
                    result.all_edges.push_back(e1);
                    
                    if (u != v) {
                        Edge e2(v, u, 1.0, result.edge_id_counter++);
                        result.outgoing[v].push_back(e2);
                        result.incoming[u].push_back(e2);
                        result.all_edges.push_back(e2);
                    }
                }
            }
        }
    }
    
    return result;
}


void test_all_converters() {
    cout << "=== MULTIGRAPH CONVERTERS TEST ===" << endl;
    
    MultigraphMatrix original = read_multigraph_from_file("../multi_graph_sample.inp");
    if (original.num_vertices == 0) return;
    
    cout << "\nOriginal:" << endl;
    original.display();
    
    cout << "\nMatrix → List:" << endl;
    MultigraphList list_result = matrix_to_list(original);
    list_result.display();
    
    cout << "\nMatrix → ExtList:" << endl;
    MultigraphExtendedList ext_result = matrix_to_extended_list(original);
    ext_result.display();
    
    cout << "\nMatrix → Map:" << endl;
    MultigraphMap map_result = matrix_to_map(original);
    map_result.display();
    
    cout << "\nList → Matrix (round-trip):" << endl;
    MultigraphMatrix back_to_matrix = list_to_matrix(list_result);
    back_to_matrix.display();
    
    cout << "\n DONE" << endl;
}

int main() {
    cout << "MULTIGRAPH C++ - FIXED VERSION" << endl;
    test_all_converters();
    return 0;
}