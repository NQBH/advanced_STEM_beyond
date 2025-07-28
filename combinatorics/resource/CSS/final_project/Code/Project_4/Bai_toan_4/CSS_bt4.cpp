#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Graph representations
class Graph {
public:
    vector<vector<int>> adjMatrix; // Adjacency Matrix
    vector<vector<int>> adjList;   // Adjacency List
    vector<vector<pair<int, int>>> extAdjList; // Extended Adjacency List
    vector<map<int, int>> adjMap;  // Adjacency Map
    int n; // Number of vertices

    Graph(int vertices) : n(vertices) {
        adjMatrix.assign(n, vector<int>(n, 0));
        adjList.resize(n);
        extAdjList.resize(n);
        adjMap.resize(n);
    }

    // Adjacency Matrix to Adjacency List
    void matrixToList() {
        for (int i = 0; i < n; ++i) {
            adjList[i].clear();
            for (int j = 0; j < n; ++j) {
                if (adjMatrix[i][j]) {
                    adjList[i].push_back(j);
                }
            }
        }
    }

    // Adjacency List to Adjacency Matrix
    void listToMatrix() {
        adjMatrix.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j : adjList[i]) {
                adjMatrix[i][j] = 1;
            }
        }
    }
};

// Tree representations
struct TreeNode {
    int firstChild = -1, nextSibling = -1;
};

class Tree {
public:
    vector<int> parent; // Array of Parents
    vector<TreeNode> fcns; // First-Child Next-Sibling
    vector<vector<int>> graph; // Graph-based representation
    int n;

    Tree(int vertices) : n(vertices) {
        parent.resize(n, -1);
        fcns.resize(n);
        graph.resize(n);
    }

    // Array of Parents to First-Child Next-Sibling
    void parentToFCNS() {
        vector<vector<int>> children(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                children[parent[i]].push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!children[i].empty()) {
                fcns[i].firstChild = children[i][0];
                for (size_t j = 0; j < children[i].size() - 1; ++j) {
                    fcns[children[i][j]].nextSibling = children[i][j + 1];
                }
            }
        }
    }
};

int main() {
    // Example usage
    Graph g(4);
    g.adjMatrix = {{0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}};
    g.matrixToList();
    // Print adjList
    for (int i = 0; i < g.n; ++i) {
        cout << i << ": ";
        for (int j : g.adjList[i]) cout << j << " ";
        cout << endl;
    }

    Tree t(5);
    t.parent = {-1, 0, 0, 1, 1}; // Root is 0
    t.parentToFCNS();
    // Print FCNS
    for (int i = 0; i < t.n; ++i) {
        cout << i << ": firstChild=" << t.fcns[i].firstChild
             << ", nextSibling=" << t.fcns[i].nextSibling << endl;
    }
    return 0;
}