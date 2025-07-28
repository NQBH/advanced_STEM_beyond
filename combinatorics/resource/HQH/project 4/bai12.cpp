#include <iostream>
#include <vector>
#include <set>
using namespace std;

class MultigraphDFS {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList; // pair<neighbor, edge_id>
    int edgeCounter;

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";
        set<int> uniqueNeighbors;
        for (auto& edge : adjList[vertex]) {
            uniqueNeighbors.insert(edge.first);
        }
        for (int neighbor : uniqueNeighbors) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    MultigraphDFS(int n) : numVertices(n), edgeCounter(0) {
        adjList.resize(n);
    }

    void addEdge(int u, int v) {
        if (u != v) {
            adjList[u].push_back({v, edgeCounter});
            adjList[v].push_back({u, edgeCounter});
            edgeCounter++;
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "Multigraph DFS traversal starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        cout << endl;
    }

    void printGraph() {
        cout << "Multigraph adjacency list:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            for (auto& edge : adjList[i]) {
                cout << "(" << edge.first << ",e" << edge.second << ") ";
            }
            cout << endl;
        }
    }
};

// Test function for Multigraph DFS
void testMultigraphDFS() {
    cout << "=== MULTIGRAPH DFS TEST ===" << endl;
    MultigraphDFS mg(4);
    mg.addEdge(0, 1);
    mg.addEdge(0, 1); // Multiple edge
    mg.addEdge(1, 2);
    mg.addEdge(2, 3);
    mg.addEdge(0, 3);
    mg.printGraph();
    mg.DFS(0);
    cout << endl;
}

// Main function to run the test
int main() {
    testMultigraphDFS();
    return 0;
}
