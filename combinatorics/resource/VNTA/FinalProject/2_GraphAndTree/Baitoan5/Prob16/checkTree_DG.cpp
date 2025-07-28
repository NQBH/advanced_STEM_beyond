#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Graph {
    int n, m;
    vector<pair<int,int>>edges;
};

Graph readGraph() {
    Graph g;
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        if (line[0] == 'c') continue; // dòng comment
        else if (line[0] == 'p') {
            string tmp;
            stringstream ss(line);
            ss >> tmp >> tmp >> g.n >> g.m;
        } else if (line[0] == 'e') {
            int u, v;
            stringstream ss(line);
            char e;
            ss >> e >> u >> v;
            g.edges.emplace_back(u, v);
        }
    }
    return g;
}

void printGraph(const Graph& g) {
    cout << "p edge " << g.n << " " << g.m << "\n";
    for (auto& [u, v] : g.edges) {
        cout << "e " << u << " " << v << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Graph g = readGraph();
    printGraph(g);
    return 0;
}
