#include <iostream>
#include <vector>
#include <set>
using namespace std;

class GeneralGraphDFS {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList; // pair<neighbor, edge_id>
    int edgeCounter;
    vector<bool> hasSelfLoop;

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";
        if (hasSelfLoop[vertex]) {
            cout << "[self-loop] ";
        }
        set<int> uniqueNeighbors;
        for (auto& edge : adjList[vertex]) {
            int neighbor = edge.first;
            if (neighbor != vertex) {
                uniqueNeighbors.insert(neighbor);
            }
        }
        for (int neighbor : uniqueNeighbors) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    GeneralGraphDFS(int n) : numVertices(n), edgeCounter(0) {
        adjList.resize(n);
        hasSelfLoop.resize(n, false);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back({v, edgeCounter});
        if (u != v) {
            adjList[v].push_back({u, edgeCounter});
        } else {
            hasSelfLoop[u] = true;
        }
        edgeCounter++;
    }

    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "General Graph DFS traversal starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
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

// Test function for General Graph DFS
void testGeneralGraphDFS() {
    cout << "=== GENERAL GRAPH DFS TEST ===" << endl;
    GeneralGraphDFS gg(4);
    gg.addEdge(0, 0); // Self-loop
    gg.addEdge(0, 1);
    gg.addEdge(1, 1); // Self-loop
    gg.addEdge(1, 2);
    gg.addEdge(2, 3);
    gg.addEdge(0, 3);
    gg.printGraph();
    gg.DFS(0);
    cout << endl;
}

// Main function to run the test
int main() {
    testGeneralGraphDFS();
    return 0;
}
