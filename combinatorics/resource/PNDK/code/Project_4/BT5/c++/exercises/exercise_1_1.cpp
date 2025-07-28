#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Graph {
private:
    set<int> vertices;
    set<pair<int, int>> edges;

public:
    void add_edge(int u, int v) {
        vertices.insert(u);
        vertices.insert(v);
        edges.insert({min(u, v), max(u, v)});
    }
    
    string get_dimacs_format() {
        stringstream ss;
        ss << "p edge " << vertices.size() << " " << edges.size() << "\n";
        for (const auto& edge : edges) {
            ss << "e " << edge.first << " " << edge.second << "\n";
        }
        return ss.str();
    }
    
    static Graph read_dimacs_file(const string& filename) {
        Graph graph;
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "File " << filename << " not found\n";
            return graph;
        }
        
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            
            if (line[0] == 'c') {
                // Comment line - bỏ qua
                continue;
            } else if (line[0] == 'p') {
                // Problem line
                continue;
            } else if (line[0] == 'e') {
                // Edge line
                stringstream ss(line);
                string type;
                int u, v;
                ss >> type >> u >> v;
                graph.add_edge(u, v);
            }
        }
        return graph;
    }
};

int main() {
    // Tạo đồ thị ví dụ
    Graph g;
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(1, 3);
    g.add_edge(3, 4);
    
    // Ghi ra định dạng DIMACS
    cout << "DIMACS format:\n";
    cout << g.get_dimacs_format();
    
    // Ghi vào file
    ofstream outfile("sample.dimacs");
    outfile << g.get_dimacs_format();
    outfile.close();
    
    // Đọc lại từ file
    cout << "\nReading from file:\n";
    Graph g2 = Graph::read_dimacs_file("sample.dimacs");
    cout << g2.get_dimacs_format();
    
    return 0;
}