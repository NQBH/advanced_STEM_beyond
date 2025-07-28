#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class GeneralGraph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList; // pair<neighbor, edge_id>
    int edgeCounter;
    vector<bool> hasSelfLoop;

public:
    GeneralGraph(int n) : numVertices(n), edgeCounter(0) {
        adjList.resize(n);
        hasSelfLoop.resize(n, false);
    }

    // Add edge (can be self-loop)
    void addEdge(int u, int v) {
        adjList[u].push_back({v, edgeCounter});
        if (u != v) {
            adjList[v].push_back({u, edgeCounter});
        } else {
            hasSelfLoop[u] = true;
        }
        edgeCounter++;
    }

    // BFS for general graph
    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        cout << "General Graph BFS traversal starting from vertex " << startVertex << ": ";
        visited[startVertex] = true;
        q.push(startVertex);
        // Handle self-loop at start vertex
        if (hasSelfLoop[startVertex]) {
            cout << "[" << startVertex << " has self-loop] ";
        }
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            set<int> uniqueNeighbors;
            for (auto& edge : adjList[current]) {
                int neighbor = edge.first;
                if (neighbor != current) { // Skip self-loops for traversal
                    uniqueNeighbors.insert(neighbor);
                }
            }
            for (int neighbor : uniqueNeighbors) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    // Check for self-loop at neighbor
                    if (hasSelfLoop[neighbor]) {
                        cout << "[" << neighbor << " has self-loop] ";
                    }
                }
            }
        }
        cout << endl;
    }

    void printGraph() {
        cout << "General Graph adjacency list:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            for (auto& edge : adjList[i]) {
                cout << "(" << edge.first << ",e" << edge.second << ") ";
            }
            if (hasSelfLoop[i]) {
                cout << "[SELF-LOOP]";
            }
            cout << endl;
        }
    }
};

// Test function for General Graph BFS
void testGeneralGraphBFS() {
    cout << "=== GENERAL GRAPH BFS TEST ===" << endl;
    GeneralGraph gg(4);
    gg.addEdge(0, 0); // Self-loop
    gg.addEdge(0, 1);
    gg.addEdge(1, 1); // Self-loop
    gg.addEdge(1, 2);
    gg.addEdge(2, 3);
    gg.addEdge(0, 3);
    gg.printGraph();
    gg.BFS(0);
    cout << endl;
}

// Main function to run the test
int main() {
    testGeneralGraphBFS();
    return 0;
}
