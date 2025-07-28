#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

class Multigraph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList; // pair<neighbor, edge_id>
    int edgeCounter;

public:
    Multigraph(int n) : numVertices(n), edgeCounter(0) {
        adjList.resize(n);
    }

    // Add edge with unique ID
    void addEdge(int u, int v) {
        if (u != v) { // No self-loops in multigraph
            adjList[u].push_back({v, edgeCounter});
            adjList[v].push_back({u, edgeCounter});
            edgeCounter++;
        }
    }

    // BFS traversal for multigraph
    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        cout << "Multigraph BFS traversal starting from vertex " << startVertex << ": ";
        visited[startVertex] = true;
        q.push(startVertex);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            // Use set to avoid visiting same neighbor multiple times
            set<int> uniqueNeighbors;
            for (auto& edge : adjList[current]) {
                uniqueNeighbors.insert(edge.first);
            }
            for (int neighbor : uniqueNeighbors) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // BFS that considers all edges (including multiple edges)
    void BFSAllEdges(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<pair<int, int>> q; // pair<vertex, parent>
        cout << "Multigraph BFS considering all edges from vertex " << startVertex << ":" << endl;
        visited[startVertex] = true;
        q.push({startVertex, -1});
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int vertex = current.first;
            int parent = current.second;
            cout << "Visiting vertex " << vertex;
            if (parent != -1) {
                cout << " (from " << parent << ")";
            }
            cout << endl;
            for (auto& edge : adjList[vertex]) {
                int neighbor = edge.first;
                int edgeId = edge.second;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, vertex});
                    cout << "Using edge " << edgeId << " to reach vertex " << neighbor << endl;
                }
            }
        }
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

// Test function for Multigraph BFS
void testMultigraphBFS() {
    cout << "=== MULTIGRAPH BFS TEST ===" << endl;
    Multigraph mg(4);
    mg.addEdge(0, 1);
    mg.addEdge(0, 1); // Multiple edge
    mg.addEdge(1, 2);
    mg.addEdge(2, 3);
    mg.addEdge(0, 3);
    mg.printGraph();
    mg.BFS(0);
    mg.BFSAllEdges(0);
    cout << endl;
}

// Main function to run the test
int main() {
    testMultigraphBFS();
    return 0;
}
