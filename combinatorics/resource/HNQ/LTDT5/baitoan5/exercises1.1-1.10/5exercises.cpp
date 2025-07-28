#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

// Exercise 1.1: DIMACS format reader/writer
class DIMACSGraph {
private:
    int vertices, edges;
    vector<pair<int, int>> edgeList;
    string problemType;
    
public:
    void readDIMACS(const string& input) {
        istringstream iss(input);
        string line;
        
        while (getline(iss, line)) {
            if (line.empty()) continue;
            
            istringstream lineStream(line);
            string token;
            lineStream >> token;
            
            if (token == "p") {
                lineStream >> problemType >> vertices >> edges;
                cout << "Problem: " << problemType << ", Vertices: " << vertices 
                     << ", Edges: " << edges << endl;
            }
            else if (token == "e") {
                int u, v;
                lineStream >> u >> v;
                edgeList.push_back({u-1, v-1}); // Convert to 0-based indexing
            }
            else if (token == "c") {
                // Comment line - ignore
                continue;
            }
        }
    }
    
    void writeDIMACS() {
        cout << "c DIMACS format graph" << endl;
        cout << "p " << problemType << " " << vertices << " " << edges << endl;
        
        for (const auto& edge : edgeList) {
            cout << "e " << (edge.first + 1) << " " << (edge.second + 1) << endl;
        }
    }
    
    vector<vector<int>> getAdjacencyList() {
        vector<vector<int>> adjList(vertices);
        for (const auto& edge : edgeList) {
            adjList[edge.first].push_back(edge.second);
            adjList[edge.second].push_back(edge.first);
        }
        return adjList;
    }
};

// Exercise 1.2: Stanford GraphBase (SGB) format reader/writer
class SGBGraph {
private:
    string graphType;
    vector<string> vertices;
    vector<tuple<string, string, int>> edges; // source, target, weight
    
public:
    void readSGB(const string& input) {
        istringstream iss(input);
        string line;
        
        getline(iss, line); // First line with graph type
        graphType = line;
        
        while (getline(iss, line)) {
            if (line.empty()) continue;
            
            istringstream lineStream(line);
            string source, target;
            int weight = 0;
            
            getline(lineStream, source, ',');
            getline(lineStream, target, ',');
            
            string weightStr;
            if (getline(lineStream, weightStr, ',')) {
                weight = stoi(weightStr);
            }
            
            // Remove quotes and whitespace
            source.erase(remove(source.begin(), source.end(), '"'), source.end());
            target.erase(remove(target.begin(), target.end(), '"'), target.end());
            source.erase(remove(source.begin(), source.end(), ' '), source.end());
            target.erase(remove(target.begin(), target.end(), ' '), target.end());
            
            edges.push_back({source, target, weight});
            
            // Add vertices if not already present
            if (find(vertices.begin(), vertices.end(), source) == vertices.end()) {
                vertices.push_back(source);
            }
            if (find(vertices.begin(), vertices.end(), target) == vertices.end()) {
                vertices.push_back(target);
            }
        }
    }
    
    void writeSGB() {
        cout << graphType << endl;
        for (const auto& edge : edges) {
            cout << "\"" << get<0>(edge) << "\",\"" << get<1>(edge) << "\"";
            if (get<2>(edge) != 0) {
                cout << "," << get<2>(edge);
            }
            cout << endl;
        }
    }
};

// Exercise 1.3: Path graph, Circle graph, and Wheel graph generators
class GraphGenerators {
public:
    static vector<vector<int>> generatePathGraph(int n) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n - 1; i++) {
            adjList[i].push_back(i + 1);
            adjList[i + 1].push_back(i);
        }
        return adjList;
    }
    
    static vector<vector<int>> generateCircleGraph(int n) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            adjList[i].push_back((i + 1) % n);
            adjList[(i + 1) % n].push_back(i);
        }
        return adjList;
    }
    
    static vector<vector<int>> generateWheelGraph(int n) {
        // Wheel graph has n+1 vertices: center + cycle of n vertices
        vector<vector<int>> adjList(n + 1);
        
        // Connect center (vertex 0) to all other vertices
        for (int i = 1; i <= n; i++) {
            adjList[0].push_back(i);
            adjList[i].push_back(0);
        }
        
        // Create cycle among vertices 1 to n
        for (int i = 1; i <= n; i++) {
            adjList[i].push_back((i % n) + 1);
            adjList[(i % n) + 1].push_back(i);
        }
        
        return adjList;
    }
};

// Exercise 1.4: Complete graph and Complete bipartite graph generators
class CompleteGraphGenerators {
public:
    static vector<vector<int>> generateCompleteGraph(int n) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    adjList[i].push_back(j);
                }
            }
        }
        return adjList;
    }
    
    static vector<vector<int>> generateCompleteBipartiteGraph(int p, int q) {
        vector<vector<int>> adjList(p + q);
        
        // Connect all vertices in first partition to all vertices in second partition
        for (int i = 0; i < p; i++) {
            for (int j = p; j < p + q; j++) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
        
        return adjList;
    }
};

// Exercise 1.5: Extended adjacency matrix with Python class wrapper
class ExtendedAdjacencyMatrixPython {
private:
    vector<vector<int>> matrix;
    int vertices;
    
public:
    ExtendedAdjacencyMatrixPython(int n) : vertices(n), matrix(n, vector<int>(n, 0)) {}
    
    void addEdge(int u, int v, int weight = 1) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            matrix[u][v] = weight;
            matrix[v][u] = weight;
        }
    }
    
    void removeEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            matrix[u][v] = 0;
            matrix[v][u] = 0;
        }
    }
    
    vector<int> getNeighbors(int v) {
        vector<int> neighbors;
        if (v >= 0 && v < vertices) {
            for (int i = 0; i < vertices; i++) {
                if (matrix[v][i] != 0) {
                    neighbors.push_back(i);
                }
            }
        }
        return neighbors;
    }
    
    bool hasEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            return matrix[u][v] != 0;
        }
        return false;
    }
    
    int getWeight(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            return matrix[u][v];
        }
        return 0;
    }
    
    void display() {
        cout << "Extended Adjacency Matrix (Python-style):" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "[";
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j];
                if (j < vertices - 1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }
};

// Exercise 1.6: Perfect matching enumeration in complete bipartite graph
class PerfectMatchingEnumerator {
private:
    int p, q;
    vector<vector<int>> matchings;
    
public:
    PerfectMatchingEnumerator(int p_val, int q_val) : p(p_val), q(q_val) {}
    
    void enumerateAllPerfectMatchings() {
        if (p != q) {
            cout << "Perfect matching only exists when p = q" << endl;
            return;
        }
        
        vector<int> permutation(p);
        for (int i = 0; i < p; i++) {
            permutation[i] = i;
        }
        
        cout << "All perfect matchings in K" << p << "," << q << ":" << endl;
        int count = 0;
        do {
            cout << "Matching " << ++count << ": ";
            for (int i = 0; i < p; i++) {
                cout << "(" << i << "," << (p + permutation[i]) << ") ";
            }
            cout << endl;
        } while (next_permutation(permutation.begin(), permutation.end()));
        
        cout << "Total perfect matchings: " << count << endl;
    }
};

// Exercise 1.7: Complete binary tree generator
class BinaryTreeGenerator {
public:
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    };
    
    static TreeNode* generateCompleteBinaryTree(int n) {
        if (n == 0) return nullptr;
        
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(1);
        q.push(root);
        
        int nodeCount = 1;
        
        while (nodeCount < n && !q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            // Add left child
            if (nodeCount < n) {
                current->left = new TreeNode(++nodeCount);
                q.push(current->left);
            }
            
            // Add right child
            if (nodeCount < n) {
                current->right = new TreeNode(++nodeCount);
                q.push(current->right);
            }
        }
        
        return root;
    }
    
    static void inorderTraversal(TreeNode* root) {
        if (root) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }
    
    static void levelOrderTraversal(TreeNode* root) {
        if (!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->data << " ";
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
};

// Exercise 1.8: Random tree generator
class RandomTreeGenerator {
public:
    static vector<vector<int>> generateRandomTree(int n) {
        if (n <= 1) return vector<vector<int>>(max(1, n));
        
        vector<vector<int>> adjList(n);
        vector<int> vertices;
        
        // Start with vertex 0
        vertices.push_back(0);
        
        // Add remaining vertices one by one
        for (int i = 1; i < n; i++) {
            // Choose random vertex from existing tree
            int randomParent = vertices[rand() % vertices.size()];
            
            // Connect new vertex to random parent
            adjList[i].push_back(randomParent);
            adjList[randomParent].push_back(i);
            
            vertices.push_back(i);
        }
        
        return adjList;
    }
    
    static void analyzeComplexity() {
        cout << "Random Tree Generation Complexity Analysis:" << endl;
        cout << "Time Complexity: O(n) - each vertex added once" << endl;
        cout << "Space Complexity: O(n) - adjacency list storage" << endl;
    }
};

// Exercise 1.9: T.previous_sibling() operation using array-of-parents
class ArrayOfParentsTree {
private:
    vector<int> parent;
    vector<vector<int>> children;
    int n;
    
public:
    ArrayOfParentsTree(int size) : n(size), parent(size, -1), children(size) {}
    
    void setParent(int child, int par) {
        if (child >= 0 && child < n && par >= -1 && par < n) {
            parent[child] = par;
            if (par != -1) {
                children[par].push_back(child);
            }
        }
    }
    
    int previousSibling(int v) {
        if (v < 0 || v >= n || parent[v] == -1) {
            return -1; // No parent or invalid vertex
        }
        
        int par = parent[v];
        const vector<int>& siblings = children[par];
        
        for (int i = 0; i < siblings.size(); i++) {
            if (siblings[i] == v) {
                return (i > 0) ? siblings[i-1] : -1;
            }
        }
        
        return -1;
    }
    
    void display() {
        cout << "Array-of-parents representation:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << ": parent = " << parent[i] << endl;
        }
    }
};

// Exercise 1.10: Extended first-child, next-sibling tree with Python class
class ExtendedFirstChildNextSiblingTree {
public:
    struct TreeNode {
        int data;
        TreeNode* firstChild;
        TreeNode* nextSibling;
        TreeNode* parent;
        
        TreeNode(int val) : data(val), firstChild(nullptr), nextSibling(nullptr), parent(nullptr) {}
    };
    
private:
    TreeNode* root;
    vector<int> internalNumbers;
    
public:
    ExtendedFirstChildNextSiblingTree() : root(nullptr) {}
    
    TreeNode* createNode(int data) {
        TreeNode* node = new TreeNode(data);
        internalNumbers.push_back(data);
        return node;
    }
    
    void setRoot(TreeNode* node) {
        root = node;
    }
    
    void addChild(TreeNode* parent, TreeNode* child) {
        if (!parent || !child) return;
        
        child->parent = parent;
        
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
    
    TreeNode* getParent(TreeNode* node) {
        return node ? node->parent : nullptr;
    }
    
    TreeNode* getFirstChild(TreeNode* node) {
        return node ? node->firstChild : nullptr;
    }
    
    TreeNode* getNextSibling(TreeNode* node) {
        return node ? node->nextSibling : nullptr;
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
    
    int getDepth(TreeNode* node) {
        if (!node) return -1;
        
        int depth = 0;
        TreeNode* current = node->parent;
        while (current) {
            depth++;
            current = current->parent;
        }
        return depth;
    }
    
    void displayWithInternalNumbers() {
        cout << "Extended First-Child Next-Sibling Tree:" << endl;
        cout << "Internal numbering: ";
        for (int num : internalNumbers) {
            cout << num << " ";
        }
        cout << endl;
        
        if (root) {
            displayNodeInfo(root, 0);
        }
    }
    
private:
    void displayNodeInfo(TreeNode* node, int level) {
        if (!node) return;
        
        for (int i = 0; i < level; i++) cout << "  ";
        cout << "Node " << node->data << " (level " << level << ")" << endl;
        
        TreeNode* child = node->firstChild;
        while (child) {
            displayNodeInfo(child, level + 1);
            child = child->nextSibling;
        }
    }
};

// Utility function to display adjacency list
void displayAdjacencyList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "=== Graph Theory Exercises 1.1-1.10 Implementation ===" << endl << endl;
    
    // Exercise 1.1: DIMACS format
    cout << "Exercise 1.1: DIMACS format" << endl;
    DIMACSGraph dimacs;
    string dimacsInput = "c Sample graph\np edge 4 4\ne 1 2\ne 2 3\ne 3 4\ne 1 4\n";
    dimacs.readDIMACS(dimacsInput);
    dimacs.writeDIMACS();
    cout << endl;
    
    // Exercise 1.2: SGB format
    cout << "Exercise 1.2: Stanford GraphBase format" << endl;
    SGBGraph sgb;
    string sgbInput = "* GraphBase\n\"A\",\"B\",1\n\"B\",\"C\",2\n\"C\",\"D\",3\n";
    sgb.readSGB(sgbInput);
    sgb.writeSGB();
    cout << endl;
    
    // Exercise 1.3: Graph generators
    cout << "Exercise 1.3: Path, Circle, and Wheel graphs" << endl;
    cout << "Path graph P4:" << endl;
    displayAdjacencyList(GraphGenerators::generatePathGraph(4));
    cout << "Circle graph C4:" << endl;
    displayAdjacencyList(GraphGenerators::generateCircleGraph(4));
    cout << "Wheel graph W4:" << endl;
    displayAdjacencyList(GraphGenerators::generateWheelGraph(4));
    cout << endl;
    
    // Exercise 1.4: Complete graphs
    cout << "Exercise 1.4: Complete and Complete Bipartite graphs" << endl;
    cout << "Complete graph K4:" << endl;
    displayAdjacencyList(CompleteGraphGenerators::generateCompleteGraph(4));
    cout << "Complete bipartite graph K2,3:" << endl;
    displayAdjacencyList(CompleteGraphGenerators::generateCompleteBipartiteGraph(2, 3));
    cout << endl;
    
    // Exercise 1.5: Extended adjacency matrix
    cout << "Exercise 1.5: Extended adjacency matrix (Python-style)" << endl;
    ExtendedAdjacencyMatrixPython extAdj(4);
    extAdj.addEdge(0, 1, 2);
    extAdj.addEdge(1, 2, 3);
    extAdj.addEdge(2, 3, 1);
    extAdj.display();
    cout << endl;
    
    // Exercise 1.6: Perfect matchings
    cout << "Exercise 1.6: Perfect matchings in complete bipartite graph" << endl;
    PerfectMatchingEnumerator pme(3, 3);
    pme.enumerateAllPerfectMatchings();
    cout << endl;
    
    // Exercise 1.7: Complete binary tree
    cout << "Exercise 1.7: Complete binary tree with 7 nodes" << endl;
    auto binaryTree = BinaryTreeGenerator::generateCompleteBinaryTree(7);
    cout << "Inorder traversal: ";
    BinaryTreeGenerator::inorderTraversal(binaryTree);
    cout << endl;
    cout << "Level order traversal: ";
    BinaryTreeGenerator::levelOrderTraversal(binaryTree);
    cout << endl << endl;
    
    // Exercise 1.8: Random tree
    cout << "Exercise 1.8: Random tree generation" << endl;
    srand(42); // Fixed seed for reproducible results
    auto randomTree = RandomTreeGenerator::generateRandomTree(6);
    cout << "Random tree with 6 nodes:" << endl;
    displayAdjacencyList(randomTree);
    RandomTreeGenerator::analyzeComplexity();
    cout << endl;
    
    // Exercise 1.9: Array-of-parents with previous sibling
    cout << "Exercise 1.9: Array-of-parents with previous_sibling operation" << endl;
    ArrayOfParentsTree apt(6);
    apt.setParent(1, 0);
    apt.setParent(2, 0);
    apt.setParent(3, 0);
    apt.setParent(4, 1);
    apt.setParent(5, 1);
    apt.display();
    cout << "Previous sibling of node 2: " << apt.previousSibling(2) << endl;
    cout << "Previous sibling of node 5: " << apt.previousSibling(5) << endl;
    cout << endl;
    
    // Exercise 1.10: Extended first-child next-sibling
    cout << "Exercise 1.10: Extended first-child next-sibling tree" << endl;
    ExtendedFirstChildNextSiblingTree extTree;
    auto rootNode = extTree.createNode(1);
    auto child1 = extTree.createNode(2);
    auto child2 = extTree.createNode(3);
    auto grandchild = extTree.createNode(4);
    
    extTree.setRoot(rootNode);
    extTree.addChild(rootNode, child1);
    extTree.addChild(rootNode, child2);
    extTree.addChild(child1, grandchild);
    
    extTree.displayWithInternalNumbers();
    cout << "Depth of grandchild: " << extTree.getDepth(grandchild) << endl;
    
    return 0;
}