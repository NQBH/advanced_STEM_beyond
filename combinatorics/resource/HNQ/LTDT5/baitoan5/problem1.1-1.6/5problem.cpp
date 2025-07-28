#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class GraphRepresentation {
private:
    int n; // number of vertices
    
public:
    // Problem 1.1: Complete graph Kn and complete bipartite graph Kp,q
    static int completeGraphSize(int n) {
        // Complete graph Kn has n vertices and n(n-1)/2 edges
        return n * (n - 1) / 2;
    }
    
    static int completeBipartiteGraphSize(int p, int q) {
        // Complete bipartite graph Kp,q has p+q vertices and p*q edges
        return p * q;
    }
    
    // Problem 1.2: Circle graph Cn bipartite condition and complete graph Kn bipartite condition
    static bool isCircleGraphBipartite(int n) {
        // Circle graph Cn is bipartite if and only if n is even
        return n % 2 == 0;
    }
    
    static bool isCompleteGraphBipartite(int n) {
        // Complete graph Kn is bipartite if and only if n <= 2
        return n <= 2;
    }
    
    // Problem 1.3: Spanning trees count (using Cayley's formula and Matrix-Tree theorem)
    static long long spanningTreesComplete(int n) {
        // For complete graph Kn, number of spanning trees = n^(n-2) (Cayley's formula)
        if (n <= 1) return 0;
        if (n == 2) return 1;
        
        long long result = 1;
        for (int i = 0; i < n - 2; i++) {
            result *= n;
        }
        return result;
    }
    
    // For spanning trees of a general graph, we would use Matrix-Tree theorem
    static int spanningTreesFromAdjMatrix(vector<vector<int>>& adjMatrix) {
        int n = adjMatrix.size();
        if (n <= 1) return 0;
        
        // Create Laplacian matrix
        vector<vector<double>> laplacian(n, vector<double>(n, 0));
        
        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && adjMatrix[i][j] == 1) {
                    laplacian[i][j] = -1;
                    degree++;
                }
            }
            laplacian[i][i] = degree;
        }
        
        // Remove last row and column, then compute determinant
        // This is a simplified version - for full implementation, use proper matrix operations
        return 1; // Placeholder - actual implementation would compute determinant
    }
};

// Problem 1.4: Extended adjacency matrix operations
class ExtendedAdjacencyMatrix {
private:
    vector<vector<int>> matrix;
    int vertices;
    
public:
    ExtendedAdjacencyMatrix(int n) : vertices(n), matrix(n, vector<int>(n, 0)) {}
    
    void addEdge(int u, int v, int weight = 1) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            matrix[u][v] = weight;
            matrix[v][u] = weight; // For undirected graphs
        }
    }
    
    void deleteEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            matrix[u][v] = 0;
            matrix[v][u] = 0;
        }
    }
    
    vector<int> getEdges(int v) {
        vector<int> edges;
        if (v >= 0 && v < vertices) {
            for (int i = 0; i < vertices; i++) {
                if (matrix[v][i] != 0) {
                    edges.push_back(i);
                }
            }
        }
        return edges;
    }
    
    vector<int> getIncoming(int v) {
        vector<int> incoming;
        if (v >= 0 && v < vertices) {
            for (int i = 0; i < vertices; i++) {
                if (matrix[i][v] != 0) {
                    incoming.push_back(i);
                }
            }
        }
        return incoming;
    }
    
    vector<int> getOutgoing(int v) {
        return getEdges(v); // Same as getEdges for undirected graphs
    }
    
    vector<int> getSource(int u, int v) {
        vector<int> sources;
        if (matrix[u][v] != 0) {
            sources.push_back(u);
        }
        return sources;
    }
    
    vector<int> getTarget(int u, int v) {
        vector<int> targets;
        if (matrix[u][v] != 0) {
            targets.push_back(v);
        }
        return targets;
    }
    
    void display() {
        cout << "Extended Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Problem 1.5: First-child, next-sibling tree representation
class TreeNode {
public:
    int data;
    TreeNode* firstChild;
    TreeNode* nextSibling;
    
    TreeNode(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

class FirstChildNextSiblingTree {
private:
    TreeNode* root;
    
public:
    FirstChildNextSiblingTree() : root(nullptr) {}
    
    TreeNode* createNode(int data) {
        return new TreeNode(data);
    }
    
    void setRoot(TreeNode* node) {
        root = node;
    }
    
    void addChild(TreeNode* parent, TreeNode* child) {
        if (!parent) return;
        
        if (!parent->firstChild) {
            parent->firstChild = child;
        } else {
            TreeNode* sibling = parent->firstChild;
            while (sibling->nextSibling) {
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = child;
        }
    }
    
    TreeNode* getRoot() {
        return root;
    }
    
    int getNumberOfChildren(TreeNode* node) {
        if (!node || !node->firstChild) return 0;
        
        int count = 0;
        TreeNode* child = node->firstChild;
        while (child) {
            count++;
            child = child->nextSibling;
        }
        return count;
    }
    
    vector<TreeNode*> getChildren(TreeNode* node) {
        vector<TreeNode*> children;
        if (!node || !node->firstChild) return children;
        
        TreeNode* child = node->firstChild;
        while (child) {
            children.push_back(child);
            child = child->nextSibling;
        }
        return children;
    }
    
    void preorderTraversal(TreeNode* node) {
        if (!node) return;
        
        cout << node->data << " ";
        
        TreeNode* child = node->firstChild;
        while (child) {
            preorderTraversal(child);
            child = child->nextSibling;
        }
    }
    
    void displayTree() {
        cout << "First-Child Next-Sibling Tree (Preorder): ";
        preorderTraversal(root);
        cout << endl;
    }
};

// Problem 1.6: Graph-based tree representation verification
class GraphBasedTree {
private:
    vector<vector<int>> adjList;
    int vertices;
    
public:
    GraphBasedTree(int n) : vertices(n), adjList(n) {}
    
    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    
    bool isTree() {
        // A graph is a tree if:
        // 1. It's connected
        // 2. It has exactly n-1 edges (where n is number of vertices)
        // 3. It has no cycles
        
        if (vertices <= 1) return true;
        
        // Check if connected and count edges
        vector<bool> visited(vertices, false);
        int edgeCount = 0;
        
        if (!isConnectedDFS(0, visited, edgeCount)) {
            return false;
        }
        
        // Check if all vertices are visited (connected)
        for (bool v : visited) {
            if (!v) return false;
        }
        
        // Check edge count (each edge counted twice in adjacency list)
        return (edgeCount / 2) == (vertices - 1);
    }
    
    bool hasCycle() {
        vector<bool> visited(vertices, false);
        
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                if (hasCycleDFS(i, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool isConnectedDFS(int v, vector<bool>& visited, int& edgeCount) {
        visited[v] = true;
        
        for (int neighbor : adjList[v]) {
            edgeCount++;
            if (!visited[neighbor]) {
                isConnectedDFS(neighbor, visited, edgeCount);
            }
        }
        return true;
    }
    
    bool hasCycleDFS(int v, int parent, vector<bool>& visited) {
        visited[v] = true;
        
        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                if (hasCycleDFS(neighbor, v, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true; // Back edge found
            }
        }
        return false;
    }
    
public:
    void display() {
        cout << "Graph representation:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

// Main function to demonstrate all problems
int main() {
    cout << "=== Graph Theory Problems 1.1-1.6 Implementation ===" << endl << endl;
    
    // Problem 1.1
    cout << "Problem 1.1: Complete graphs and bipartite graphs" << endl;
    cout << "K5 has " << GraphRepresentation::completeGraphSize(5) << " edges" << endl;
    cout << "K3,4 has " << GraphRepresentation::completeBipartiteGraphSize(3, 4) << " edges" << endl;
    cout << endl;
    
    // Problem 1.2
    cout << "Problem 1.2: Bipartite conditions" << endl;
    cout << "C6 is bipartite: " << (GraphRepresentation::isCircleGraphBipartite(6) ? "Yes" : "No") << endl;
    cout << "C5 is bipartite: " << (GraphRepresentation::isCircleGraphBipartite(5) ? "Yes" : "No") << endl;
    cout << "K3 is bipartite: " << (GraphRepresentation::isCompleteGraphBipartite(3) ? "Yes" : "No") << endl;
    cout << "K2 is bipartite: " << (GraphRepresentation::isCompleteGraphBipartite(2) ? "Yes" : "No") << endl;
    cout << endl;
    
    // Problem 1.3
    cout << "Problem 1.3: Spanning trees" << endl;
    cout << "K4 has " << GraphRepresentation::spanningTreesComplete(4) << " spanning trees" << endl;
    cout << "K5 has " << GraphRepresentation::spanningTreesComplete(5) << " spanning trees" << endl;
    cout << endl;
    
    // Problem 1.4
    cout << "Problem 1.4: Extended adjacency matrix operations" << endl;
    ExtendedAdjacencyMatrix extMatrix(4);
    extMatrix.addEdge(0, 1, 1);
    extMatrix.addEdge(1, 2, 1);
    extMatrix.addEdge(2, 3, 1);
    extMatrix.addEdge(0, 3, 1);
    extMatrix.display();
    
    vector<int> edges = extMatrix.getEdges(0);
    cout << "Edges from vertex 0: ";
    for (int e : edges) cout << e << " ";
    cout << endl << endl;
    
    // Problem 1.5
    cout << "Problem 1.5: First-child, next-sibling tree" << endl;
    FirstChildNextSiblingTree fcnsTree;
    TreeNode* rootNode = fcnsTree.createNode(1);
    TreeNode* child1 = fcnsTree.createNode(2);
    TreeNode* child2 = fcnsTree.createNode(3);
    TreeNode* child3 = fcnsTree.createNode(4);
    TreeNode* grandchild1 = fcnsTree.createNode(5);
    
    fcnsTree.setRoot(rootNode);
    fcnsTree.addChild(rootNode, child1);
    fcnsTree.addChild(rootNode, child2);
    fcnsTree.addChild(rootNode, child3);
    fcnsTree.addChild(child1, grandchild1);
    
    fcnsTree.displayTree();
    cout << "Number of children of root: " << fcnsTree.getNumberOfChildren(rootNode) << endl;
    cout << endl;
    
    // Problem 1.6
    cout << "Problem 1.6: Graph-based tree verification" << endl;
    GraphBasedTree gbTree(4);
    gbTree.addEdge(0, 1);
    gbTree.addEdge(1, 2);
    gbTree.addEdge(2, 3);
    
    gbTree.display();
    cout << "Is tree: " << (gbTree.isTree() ? "Yes" : "No") << endl;
    cout << "Has cycle: " << (gbTree.hasCycle() ? "Yes" : "No") << endl;
    
    // Add one more edge to create a cycle
    gbTree.addEdge(0, 3);
    cout << "After adding edge (0,3):" << endl;
    cout << "Is tree: " << (gbTree.isTree() ? "Yes" : "No") << endl;
    cout << "Has cycle: " << (gbTree.hasCycle() ? "Yes" : "No") << endl;
    
    return 0;
}