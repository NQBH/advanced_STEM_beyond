#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Edge {
public:
    int source;
    int target;
    double weight;
    int edge_id;
    bool is_self_loop;
    
    Edge(int src, int tgt, double w = 1.0, int id = 0) 
        : source(src), target(tgt), weight(w), edge_id(id) {
        is_self_loop = (source == target);
    }
    
    string toString() const {
        string loop_indicator = is_self_loop ? "↻" : "→";
        return "(" + to_string(source) + loop_indicator + to_string(target) + "#" + to_string(edge_id) + ")";
    }
};

class GeneralGraphMatrix {
private:
    int num_vertices;
    vector<vector<int>> matrix;
    
public:
    GeneralGraphMatrix(int n) : num_vertices(n) {
        matrix.assign(n, vector<int>(n, 0));
    }
    
    void addEdge(int u, int v, int count = 1) {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            if (u == v) {  // Self-loop
                matrix[u][v] += count;
            } else {  // Normal edge
                matrix[u][v] += count;
                matrix[v][u] += count;  // Undirected
            }
        }
    }
    
    int edgeCount(int u, int v) const {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            return matrix[u][v];
        }
        return 0;
    }
    
    bool hasSelfLoop(int u) const {
        if (u >= 0 && u < num_vertices) {
            return matrix[u][u] > 0;
        }
        return false;
    }
    
    void display() const {
        cout << "General Graph Matrix:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": [";
            for (int j = 0; j < num_vertices; j++) {
                cout << matrix[i][j];
                if (j < num_vertices - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
    
    int getNumVertices() const { return num_vertices; }
    const vector<vector<int>>& getMatrix() const { return matrix; }
    vector<vector<int>>& getMatrix() { return matrix; }
};

class GeneralGraphList {
private:
    int num_vertices;
    vector<vector<int>> adj_list;
    
public:
    GeneralGraphList(int n) : num_vertices(n) {
        adj_list.assign(n, vector<int>());
    }
    
    void addEdge(int u, int v, int count = 1) {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            if (u == v) {  // Self-loop
                for (int i = 0; i < count; i++) {
                    adj_list[u].push_back(v);
                }
            } else {  // Normal edge
                for (int i = 0; i < count; i++) {
                    adj_list[u].push_back(v);
                    adj_list[v].push_back(u);
                }
            }
        }
    }
    
    int edgeCount(int u, int v) const {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            return count(adj_list[u].begin(), adj_list[u].end(), v);
        }
        return 0;
    }
    
    int selfLoopCount(int u) const {
        if (u >= 0 && u < num_vertices) {
            return count(adj_list[u].begin(), adj_list[u].end(), u);
        }
        return 0;
    }
    
    void display() const {
        cout << "General Graph List:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": [";
            for (size_t j = 0; j < adj_list[i].size(); j++) {
                cout << adj_list[i][j];
                if (j < adj_list[i].size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
    
    int getNumVertices() const { return num_vertices; }
    const vector<vector<int>>& getAdjList() const { return adj_list; }
    vector<vector<int>>& getAdjList() { return adj_list; }
};

class GeneralGraphExtendedList {
private:
    int num_vertices;
    vector<vector<Edge>> outgoing;
    vector<vector<Edge>> incoming;
    vector<Edge> all_edges;
    int edge_id_counter;
    
public:
    GeneralGraphExtendedList(int n) : num_vertices(n), edge_id_counter(0) {
        outgoing.assign(n, vector<Edge>());
        incoming.assign(n, vector<Edge>());
    }
    
    void addEdge(int u, int v, double weight = 1.0, int count = 1) {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            for (int i = 0; i < count; i++) {
                if (u == v) {  // Self-loop
                    Edge edge_self(u, v, weight, edge_id_counter++);
                    outgoing[u].push_back(edge_self);
                    incoming[v].push_back(edge_self);
                    all_edges.push_back(edge_self);
                } else {  // Normal edge
                    Edge edge_uv(u, v, weight, edge_id_counter++);
                    outgoing[u].push_back(edge_uv);
                    incoming[v].push_back(edge_uv);
                    all_edges.push_back(edge_uv);
                    
                    // Undirected: create reverse edge
                    Edge edge_vu(v, u, weight, edge_id_counter++);
                    outgoing[v].push_back(edge_vu);
                    incoming[u].push_back(edge_vu);
                    all_edges.push_back(edge_vu);
                }
            }
        }
    }
    
    int edgeCount(int u, int v) const {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            int count = 0;
            for (const auto& edge : outgoing[u]) {
                if (edge.target == v) {
                    count++;
                }
            }
            return count;
        }
        return 0;
    }
    
    vector<Edge> getSelfLoopEdges(int u) const {
        vector<Edge> result;
        if (u >= 0 && u < num_vertices) {
            for (const auto& edge : outgoing[u]) {
                if (edge.is_self_loop) {
                    result.push_back(edge);
                }
            }
        }
        return result;
    }
    
    void display() const {
        cout << "General Graph Extended List:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": [";
            for (size_t j = 0; j < outgoing[i].size(); j++) {
                cout << outgoing[i][j].toString();
                if (j < outgoing[i].size() - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
    
    int getNumVertices() const { return num_vertices; }
    const vector<vector<Edge>>& getOutgoing() const { return outgoing; }
    const vector<vector<Edge>>& getIncoming() const { return incoming; }
    const vector<Edge>& getAllEdges() const { return all_edges; }
};

class GeneralGraphMap {
private:
    int num_vertices;
    vector<unordered_map<int, int>> adj_map;
    
public:
    GeneralGraphMap(int n) : num_vertices(n) {
        adj_map.assign(n, unordered_map<int, int>());
    }
    
    void addEdge(int u, int v, int count = 1) {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            if (u == v) {  // Self-loop
                adj_map[u][v] += count;
            } else {  // Normal edge
                adj_map[u][v] += count;
                adj_map[v][u] += count;
            }
        }
    }
    
    int edgeCount(int u, int v) const {
        if (u >= 0 && u < num_vertices && v >= 0 && v < num_vertices) {
            auto it = adj_map[u].find(v);
            return (it != adj_map[u].end()) ? it->second : 0;
        }
        return 0;
    }
    
    int selfLoopCount(int u) const {
        if (u >= 0 && u < num_vertices) {
            auto it = adj_map[u].find(u);
            return (it != adj_map[u].end()) ? it->second : 0;
        }
        return 0;
    }
    
    void display() const {
        cout << "General Graph Map:" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": {";
            bool first = true;
            for (const auto& pair : adj_map[i]) {
                if (!first) cout << ", ";
                cout << pair.first << ": " << pair.second;
                first = false;
            }
            cout << "}" << endl;
        }
    }
    
    int getNumVertices() const { return num_vertices; }
    const vector<unordered_map<int, int>>& getAdjMap() const { return adj_map; }
    vector<unordered_map<int, int>>& getAdjMap() { return adj_map; }
};

GeneralGraphMatrix readGeneralGraphFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file: " << filename << endl;
        return GeneralGraphMatrix(0);
    }
    
    string line;
    getline(file, line);
    int num_vertices = stoi(line);
    
    GeneralGraphMatrix graph(num_vertices);
    
    int total_edges = 0;
    int self_loops = 0;
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        istringstream iss(line);
        vector<string> parts;
        string part;
        while (iss >> part) {
            parts.push_back(part);
        }
        
        if (parts.size() >= 2) {
            int u = stoi(parts[0]);
            int v = stoi(parts[1]);
            int count = (parts.size() >= 3) ? stoi(parts[2]) : 1;
            
            graph.addEdge(u, v, count);
            total_edges += count;
            
            if (u == v) {
                self_loops += count;
                cout << "Added " << count << " self-loop: " << u << "↻" << u << endl;
            } else {
                cout << "Added " << count << " edge: " << u << "-" << v << endl;
            }
        }
    }
    
    file.close();
    return graph;
}

// CONVERTER 1: Matrix → List
GeneralGraphList generalMatrixToList(const GeneralGraphMatrix& matrix_graph) {
    int n = matrix_graph.getNumVertices();
    GeneralGraphList list_graph(n);
    const auto& matrix = matrix_graph.getMatrix();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count = matrix[i][j];
            if (count > 0) {
                if (i == j) {  // Self-loop
                    for (int k = 0; k < count; k++) {
                        list_graph.getAdjList()[i].push_back(j);
                    }
                } else if (i < j) {  // Normal edge (process only once)
                    for (int k = 0; k < count; k++) {
                        list_graph.getAdjList()[i].push_back(j);
                        list_graph.getAdjList()[j].push_back(i);
                    }
                }
            }
        }
    }
    
    return list_graph;
}

// CONVERTER 2: List → Matrix
GeneralGraphMatrix generalListToMatrix(const GeneralGraphList& list_graph) {
    int n = list_graph.getNumVertices();
    GeneralGraphMatrix matrix_graph(n);
    const auto& adj_list = list_graph.getAdjList();
    
    for (int u = 0; u < n; u++) {
        unordered_map<int, int> neighbor_count;
        for (int v : adj_list[u]) {
            neighbor_count[v]++;
        }
        
        for (const auto& pair : neighbor_count) {
            int v = pair.first;
            int count = pair.second;
            if (u == v) {  // Self-loop
                matrix_graph.getMatrix()[u][v] = count;
            } else {
                matrix_graph.getMatrix()[u][v] = count;
            }
        }
    }
    
    return matrix_graph;
}

// CONVERTER 3: Matrix → Extended List
GeneralGraphExtendedList generalMatrixToExtendedList(const GeneralGraphMatrix& matrix_graph) {
    int n = matrix_graph.getNumVertices();
    GeneralGraphExtendedList ext_graph(n);
    const auto& matrix = matrix_graph.getMatrix();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count = matrix[i][j];
            if (count > 0) {
                if (i == j) {  // Self-loop
                    ext_graph.addEdge(i, j, 1.0, count);
                } else if (i < j) {  // Normal edge (process only once)
                    ext_graph.addEdge(i, j, 1.0, count);
                }
            }
        }
    }
    
    return ext_graph;
}

// CONVERTER 4: Extended List → Matrix
GeneralGraphMatrix generalExtendedListToMatrix(const GeneralGraphExtendedList& ext_graph) {
    int n = ext_graph.getNumVertices();
    GeneralGraphMatrix matrix_graph(n);
    
    unordered_map<string, int> edge_count;
    for (const auto& edge : ext_graph.getAllEdges()) {
        string key = to_string(edge.source) + "," + to_string(edge.target);
        edge_count[key]++;
    }
    
    for (const auto& pair : edge_count) {
        size_t comma_pos = pair.first.find(',');
        int u = stoi(pair.first.substr(0, comma_pos));
        int v = stoi(pair.first.substr(comma_pos + 1));
        matrix_graph.getMatrix()[u][v] = pair.second;
    }
    
    return matrix_graph;
}

// CONVERTER 5: List → Extended List
GeneralGraphExtendedList generalListToExtendedList(const GeneralGraphList& list_graph) {
    int n = list_graph.getNumVertices();
    GeneralGraphExtendedList ext_graph(n);
    const auto& adj_list = list_graph.getAdjList();
    
    // Handle self-loops first
    for (int u = 0; u < n; u++) {
        int self_loop_count = count(adj_list[u].begin(), adj_list[u].end(), u);
        if (self_loop_count > 0) {
            ext_graph.addEdge(u, u, 1.0, self_loop_count);
        }
    }
    
    // Handle normal edges with canonical form
    unordered_map<string, int> edge_count;
    for (int u = 0; u < n; u++) {
        for (int v : adj_list[u]) {
            if (u != v) {  // Skip self-loops (already processed)
                string canonical_key = to_string(min(u, v)) + "," + to_string(max(u, v));
                edge_count[canonical_key]++;
            }
        }
    }
    
    // Divide by 2 and create edges
    for (const auto& pair : edge_count) {
        size_t comma_pos = pair.first.find(',');
        int u = stoi(pair.first.substr(0, comma_pos));
        int v = stoi(pair.first.substr(comma_pos + 1));
        int actual_count = pair.second / 2;  // Undirected edges are counted twice
        
        if (actual_count > 0) {
            ext_graph.addEdge(u, v, 1.0, actual_count);
        }
    }
    
    return ext_graph;
}

// CONVERTER 6: Extended List → List
GeneralGraphList generalExtendedListToList(const GeneralGraphExtendedList& ext_graph) {
    int n = ext_graph.getNumVertices();
    GeneralGraphList list_graph(n);
    const auto& outgoing = ext_graph.getOutgoing();
    
    for (int u = 0; u < n; u++) {
        for (const auto& edge : outgoing[u]) {
            list_graph.getAdjList()[u].push_back(edge.target);
        }
    }
    
    return list_graph;
}

// CONVERTER 7: Matrix → Map
GeneralGraphMap generalMatrixToMap(const GeneralGraphMatrix& matrix_graph) {
    int n = matrix_graph.getNumVertices();
    GeneralGraphMap map_graph(n);
    const auto& matrix = matrix_graph.getMatrix();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count = matrix[i][j];
            if (count > 0) {
                map_graph.addEdge(i, j, count);
            }
        }
    }
    
    return map_graph;
}

// CONVERTER 8: Map → Matrix
GeneralGraphMatrix generalMapToMatrix(const GeneralGraphMap& map_graph) {
    int n = map_graph.getNumVertices();
    GeneralGraphMatrix matrix_graph(n);
    const auto& adj_map = map_graph.getAdjMap();
    
    for (int u = 0; u < n; u++) {
        for (const auto& pair : adj_map[u]) {
            int v = pair.first;
            int count = pair.second;
            matrix_graph.getMatrix()[u][v] = count;
        }
    }
    
    return matrix_graph;
}

// CONVERTER 9: List → Map
GeneralGraphMap generalListToMap(const GeneralGraphList& list_graph) {
    int n = list_graph.getNumVertices();
    GeneralGraphMap map_graph(n);
    const auto& adj_list = list_graph.getAdjList();
    
    for (int u = 0; u < n; u++) {
        unordered_map<int, int> neighbor_count;
        for (int v : adj_list[u]) {
            neighbor_count[v]++;
        }
        
        // Copy the neighbor counts to the map graph
        auto& map_u = const_cast<unordered_map<int, int>&>(map_graph.getAdjMap()[u]);
        map_u = neighbor_count;
    }
    
    return map_graph;
}

// CONVERTER 10: Map → List
GeneralGraphList generalMapToList(const GeneralGraphMap& map_graph) {
    int n = map_graph.getNumVertices();
    GeneralGraphList list_graph(n);
    const auto& adj_map = map_graph.getAdjMap();
    
    for (int u = 0; u < n; u++) {
        for (const auto& pair : adj_map[u]) {
            int v = pair.first;
            int count = pair.second;
            for (int i = 0; i < count; i++) {
                list_graph.getAdjList()[u].push_back(v);
            }
        }
    }
    
    return list_graph;
}

// CONVERTER 11: Extended List → Map
GeneralGraphMap generalExtendedListToMap(const GeneralGraphExtendedList& ext_graph) {
    int n = ext_graph.getNumVertices();
    GeneralGraphMap map_graph(n);
    const auto& outgoing = ext_graph.getOutgoing();
    
    for (int u = 0; u < n; u++) {
        unordered_map<int, int> target_count;
        for (const auto& edge : outgoing[u]) {
            target_count[edge.target]++;
        }
        
        // Copy the target counts to the map graph
        auto& map_u = const_cast<unordered_map<int, int>&>(map_graph.getAdjMap()[u]);
        map_u = target_count;
    }
    
    return map_graph;
}

// CONVERTER 12: Map → Extended List
GeneralGraphExtendedList generalMapToExtendedList(const GeneralGraphMap& map_graph) {
    int n = map_graph.getNumVertices();
    GeneralGraphExtendedList ext_graph(n);
    const auto& adj_map = map_graph.getAdjMap();
    
    unordered_set<string> processed_edges;
    
    for (int u = 0; u < n; u++) {
        for (const auto& pair : adj_map[u]) {
            int v = pair.first;
            int count = pair.second;
            
            if (u == v) {  // Self-loop
                ext_graph.addEdge(u, v, 1.0, count);
            } else {  // Normal edge
                string canonical_key = to_string(min(u, v)) + "," + to_string(max(u, v));
                if (processed_edges.find(canonical_key) == processed_edges.end()) {
                    processed_edges.insert(canonical_key);
                    ext_graph.addEdge(u, v, 1.0, count);
                }
            }
        }
    }
    
    return ext_graph;
}


void testAllGeneralGraphConverters() {
    cout << "TEST: All 12 General Graph Converters (Read from file)" << endl;
    cout << "==========================================================" << endl;
    
    GeneralGraphMatrix original = readGeneralGraphFromFile("../general_graph_sample.inp");
    
    if (original.getNumVertices() == 0) {
        cout << "Failed to read graph from file. Using sample data instead." << endl;
        GeneralGraphMatrix sample(4);
        sample.addEdge(0, 1, 2);  // 2 parallel edges
        sample.addEdge(1, 2, 1);  // 1 edge
        sample.addEdge(2, 2, 1);  // 1 self-loop
        sample.addEdge(0, 3, 1);  // 1 edge
        original = sample;
    }
    
    cout << "Original Matrix:" << endl;
    original.display();
    
    // Test from Matrix
    cout << "\n=== 1. FROM MATRIX ===" << endl;
    auto list_result = generalMatrixToList(original);
    auto ext_result = generalMatrixToExtendedList(original);
    auto map_result = generalMatrixToMap(original);
    
    cout << "1.1. Matrix → List:" << endl;
    list_result.display();
    cout << "1.2. Matrix → ExtList:" << endl;
    ext_result.display();
    cout << "1.3. Matrix → Map:" << endl;
    map_result.display();
    
    // Test from List
    cout << "\n=== 2. FROM LIST ===" << endl;
    cout << "2.1. List → Matrix:" << endl;
    generalListToMatrix(list_result).display();
    cout << "2.2. List → ExtList:" << endl;
    generalListToExtendedList(list_result).display();
    cout << "2.3. List → Map:" << endl;
    generalListToMap(list_result).display();
    
    // Test from ExtList
    cout << "\n=== 3. FROM EXTENDED LIST ===" << endl;
    cout << "3.1. ExtList → Matrix:" << endl;
    generalExtendedListToMatrix(ext_result).display();
    cout << "3.2. ExtList → List:" << endl;
    generalExtendedListToList(ext_result).display();
    cout << "3.3. ExtList → Map:" << endl;
    generalExtendedListToMap(ext_result).display();
    
    // Test from Map
    cout << "\n=== 4. FROM MAP ===" << endl;
    cout << "4.1. Map → Matrix:" << endl;
    generalMapToMatrix(map_result).display();
    cout << "4.2. Map → List:" << endl;
    generalMapToList(map_result).display();
    cout << "4.3. Map → ExtList:" << endl;
    generalMapToExtendedList(map_result).display();
    
    cout << "\nDONE" << endl;
}

int main() {
    testAllGeneralGraphConverters();
    return 0;
}