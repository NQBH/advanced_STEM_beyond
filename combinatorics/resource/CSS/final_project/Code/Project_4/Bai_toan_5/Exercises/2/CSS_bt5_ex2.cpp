#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class SGBGraph {
public:
    int n, m;                       // so dinh, so canh
    vector<vector<int>> adj;        // danh sach ke
    vector<string> labels;          // nhan cua cac dinh

    SGBGraph() : n(0), m(0) {}

    void read_sgb(const string& filename) {
        // Doc file SGB de xay dung do thi
        ifstream file(filename);
        string line;
        getline(file, line);
        stringstream ss(line);
        string temp;
        ss >> temp >> temp >> temp >> n >> m;  // Parse header
        adj.assign(n, {});
        labels.assign(n, "");

        bool vertex_section = false, arc_section = false;
        while (getline(file, line)) {
            if (line.find("* Vertices") != string::npos) {
                vertex_section = true;
                continue;
            }
            if (line.find("* Arcs") != string::npos) {
                vertex_section = false;
                arc_section = true;
                continue;
            }
            if (vertex_section) {
                stringstream ss2(line);
                int v;
                string label;
                ss2 >> v >> label;
                labels[v] = label;
            }
            if (arc_section) {
                stringstream ss2(line);
                int v, u_idx;
                ss2 >> v >> u_idx;
                for (int i = 0; i < n; ++i) {
                    if (labels[i] == to_string(u_idx)) {
                        adj[i].push_back(v);
                        break;
                    }
                }
            }
        }
        file.close();
    }

    void write_sgb(const string& filename) {
        // Ghi do thi ra file SGB
        ofstream file(filename);
        file << "* GraphBase graph(utiltypes..., " << n << ", " << m << ")\n";
        file << "Graph description\n";
        file << "* Vertices\n";
        for (int i = 0; i < n; ++i) {
            file << i << ", v" << i << ", 0, 0\n";
        }
        file << "* Arcs\n";
        int edge_id = 0;
        for (int u = 0; u < n; ++u) {
            for (int v : adj[u]) {
                file << v << ", " << edge_id << ", 0, 0\n";
                edge_id++;
            }
        }
        file << "* Checksum\n";
        file.close();
    }
};

int main() {
    SGBGraph g;
    // g.read_sgb("input.txt");
    // g.write_sgb("output.txt");
    return 0;
}