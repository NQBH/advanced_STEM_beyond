#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class SimpleGraphDFS {
private:
    int numVertices;
    vector<vector<int>> adjList;

    // Recursive DFS helper
    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    SimpleGraphDFS(int n) : numVertices(n) {
        adjList.resize(n);
    }

    void addEdge(int u, int v) {
        if (u != v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    // DFS traversal
    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "DFS traversal starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        cout << endl;
    }

    // DFS using stack (iterative)
    void DFSIterative(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> st;
        cout << "DFS (iterative) starting from vertex " << startVertex << ": ";
        st.push(startVertex);
        while (!st.empty()) {
            int current = st.top();
            st.pop();
            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";
                // Add neighbors to stack (in reverse order for consistency)
                for (int i = adjList[current].size() - 1; i >= 0; i--) { // Fixed: i-- instead of i - -
                    int neighbor = adjList[current][i];
                    if (!visited[neighbor]) {
                        st.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }

    // Check if graph is connected
    bool isConnected() {
        vector<bool> visited(numVertices, false);
        DFSUtil(0, visited);
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }

    void printGraph() {
        cout << "Simple Graph adjacency list:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

// Test function for Simple Graph DFS
void testSimpleGraphDFS() {
    cout << "=== SIMPLE GRAPH DFS TEST ===" << endl;
    SimpleGraphDFS g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.printGraph();
    g.DFS(0);
    g.DFSIterative(0);
    cout << "Is connected: " << (g.isConnected() ? "Yes" : "No") << endl;
    cout << endl;
}

// Main function to run the test
int main() {
    testSimpleGraphDFS();
    return 0;
}
