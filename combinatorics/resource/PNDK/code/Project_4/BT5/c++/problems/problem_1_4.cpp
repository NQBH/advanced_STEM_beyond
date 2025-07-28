#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> matrix;

public:
    Graph(int vertices) : n(vertices) {
        matrix.resize(n, vector<int>(n, 0));
    }
    
    void add_edge(int v, int w) {
        if (v >= 0 && v < n && w >= 0 && w < n) {
            matrix[v][w] = 1;
        }
    }
    
    void del_edge(int v, int w) {
        if (v >= 0 && v < n && w >= 0 && w < n) {
            matrix[v][w] = 0;
        }
    }
    
    vector<pair<int, int>> edges() {
        vector<pair<int, int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    
    vector<int> incoming(int v) {
        vector<int> result;
        if (v < 0 || v >= n) return result;
        for (int i = 0; i < n; i++) {
            if (matrix[i][v]) {
                result.push_back(i);
            }
        }
        return result;
    }
    
    vector<int> outgoing(int v) {
        vector<int> result;
        if (v < 0 || v >= n) return result;
        for (int j = 0; j < n; j++) {
            if (matrix[v][j]) {
                result.push_back(j);
            }
        }
        return result;
    }
    
    bool source(int v, int w) {
        if (v >= 0 && v < n && w >= 0 && w < n) {
            return matrix[v][w] != 0;
        }
        return false;
    }
    
    bool target(int v, int w) {
        if (v >= 0 && v < n && w >= 0 && w < n) {
            return matrix[v][w] != 0;
        }
        return false;
    }
    
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(3);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(0, 2);
    
    cout << "Graph matrix:" << endl;
    g.display();
    
    auto edge_list = g.edges();
    cout << "\nEdges: ";
    for (auto edge : edge_list) {
        cout << "(" << edge.first << "," << edge.second << ") ";
    }
    cout << endl;
    
    auto incoming = g.incoming(2);
    cout << "Incoming to 2: ";
    for (int v : incoming) {
        cout << v << " ";
    }
    cout << endl;
    
    auto outgoing = g.outgoing(0);
    cout << "Outgoing from 0: ";
    for (int v : outgoing) {
        cout << v << " ";
    }
    cout << endl;
    
    cout << "Is 0 connected to 1? " << (g.source(0, 1) ? "Yes" : "No") << endl;
    cout << "Is 1 target of 0? " << (g.target(0, 1) ? "Yes" : "No") << endl;
    
    return 0;
}