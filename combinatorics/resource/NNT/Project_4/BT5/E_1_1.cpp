#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

using Edge = pair<int, int>;

// Reads DIMACS format graph from file
bool read_dimacs(const string& file_path, int& n, int& m, vector<Edge>& edges) {
    ifstream infile(file_path);
    if (!infile.is_open()) return false;

    string line;
    edges.clear();

    while (getline(infile, line)) {
        if (line.empty() || line[0] == 'c') continue;

        istringstream iss(line);
        if (line[0] == 'p') {
            string p, format;
            iss >> p >> format >> n >> m;
        } else if (line[0] == 'e') {
            char e;
            int u, v;
            iss >> e >> u >> v;
            edges.emplace_back(u, v);
        }
    }

    infile.close();
    return true;
}

// Writes DIMACS format graph to file
bool write_dimacs(int n, const vector<Edge>& edges, const string& file_path) {
    ofstream outfile(file_path);
    if (!outfile.is_open()) return false;

    outfile << "p edge " << n << " " << edges.size() << "\n";
    for (const auto& [u, v] : edges) {
        outfile << "e " << u << " " << v << "\n";
    }

    outfile.close();
    return true;
}
