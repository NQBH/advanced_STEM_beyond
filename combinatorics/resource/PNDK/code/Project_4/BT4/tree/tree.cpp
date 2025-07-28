#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

// =====================================================
// TREE REPRESENTATIONS
// =====================================================

// =====================================================
// 1. ARRAY OF PARENTS REPRESENTATION
// =====================================================
class ArrayOfParents {
private:
    int num_nodes;
    vector<int> parent;  // parent[v] = parent of v, or -1 if root
    int root_node;
    
public:
    ArrayOfParents(int n) : num_nodes(n), root_node(-1) {
        parent.assign(n, -1);
    }
    
    void setParent(int child, int par) {
        if (child >= 0 && child < num_nodes) {
            parent[child] = par;
        }
    }
    
    void setRoot(int r) {
        if (r >= 0 && r < num_nodes) {
            root_node = r;
            parent[r] = -1;
        }
    }
    
    int getParent(int v) const {
        if (v >= 0 && v < num_nodes) {
            return parent[v];
        }
        return -1;
    }
    
    bool isRoot(int v) const {
        return v >= 0 && v < num_nodes && parent[v] == -1;
    }
    
    int getRoot() const {
        if (root_node != -1) return root_node;
        
        // Find root by scanning array
        for (int i = 0; i < num_nodes; i++) {
            if (parent[i] == -1) {
                return i;
            }
        }
        return -1;
    }
    
    vector<int> getChildren(int v) const {
        vector<int> children;
        for (int i = 0; i < num_nodes; i++) {
            if (parent[i] == v) {
                children.push_back(i);
            }
        }
        return children;
    }
    
    void display() const {
        cout << "Array of Parents:" << endl;
        for (int i = 0; i < num_nodes; i++) {
            cout << "Node " << i << ": parent = " << parent[i] << endl;
        }
    }
    
    int getNumNodes() const { return num_nodes; }
    const vector<int>& getParentArray() const { return parent; }
};

// =====================================================
// 2. FIRST-CHILD NEXT-SIBLING REPRESENTATION
// =====================================================
class FirstChildNextSibling {
private:
    int num_nodes;
    vector<int> first_child;  // first_child[v] = first child of v, or -1 if leaf
    vector<int> next_sibling; // next_sibling[v] = next sibling of v, or -1 if last
    int root_node;
    
public:
    FirstChildNextSibling(int n) : num_nodes(n), root_node(-1) {
        first_child.assign(n, -1);
        next_sibling.assign(n, -1);
    }
    
    void setFirstChild(int parent, int child) {
        if (parent >= 0 && parent < num_nodes) {
            first_child[parent] = child;
        }
    }
    
    void setNextSibling(int current, int next) {
        if (current >= 0 && current < num_nodes) {
            next_sibling[current] = next;
        }
    }
    
    void setRoot(int r) {
        root_node = r;
    }
    
    int getFirstChild(int v) const {
        if (v >= 0 && v < num_nodes) {
            return first_child[v];
        }
        return -1;
    }
    
    int getNextSibling(int v) const {
        if (v >= 0 && v < num_nodes) {
            return next_sibling[v];
        }
        return -1;
    }
    
    bool isLeaf(int v) const {
        return v >= 0 && v < num_nodes && first_child[v] == -1;
    }
    
    bool isLastChild(int v) const {
        return v >= 0 && v < num_nodes && next_sibling[v] == -1;
    }
    
    int getRoot() const {
        return root_node;
    }
    
    vector<int> getChildren(int v) const {
        vector<int> children;
        int child = first_child[v];
        while (child != -1) {
            children.push_back(child);
            child = next_sibling[child];
        }
        return children;
    }
    
    int getParent(int v) const {
        // O(n) operation - scan to find parent
        for (int i = 0; i < num_nodes; i++) {
            int child = first_child[i];
            while (child != -1) {
                if (child == v) return i;
                child = next_sibling[child];
            }
        }
        return -1;
    }
    
    void display() const {
        cout << "First-Child Next-Sibling:" << endl;
        for (int i = 0; i < num_nodes; i++) {
            cout << "Node " << i << ": first_child = " << first_child[i] 
                 << ", next_sibling = " << next_sibling[i] << endl;
        }
    }
    
    int getNumNodes() const { return num_nodes; }
    const vector<int>& getFirstChildArray() const { return first_child; }
    const vector<int>& getNextSiblingArray() const { return next_sibling; }
};

// =====================================================
// 3. GRAPH-BASED REPRESENTATION
// =====================================================
class GraphBasedTree {
private:
    int num_nodes;
    vector<vector<int>> children;  // adjacency list for children
    vector<int> parent;            // parent[v] = parent of v, or -1 if root
    int root_node;
    
public:
    GraphBasedTree(int n) : num_nodes(n), root_node(-1) {
        children.assign(n, vector<int>());
        parent.assign(n, -1);
    }
    
    void addEdge(int par, int child) {
        if (par >= 0 && par < num_nodes && child >= 0 && child < num_nodes) {
            children[par].push_back(child);
            parent[child] = par;
        }
    }
    
    void setRoot(int r) {
        if (r >= 0 && r < num_nodes) {
            root_node = r;
            parent[r] = -1;
        }
    }
    
    int getParent(int v) const {
        if (v >= 0 && v < num_nodes) {
            return parent[v];
        }
        return -1;
    }
    
    vector<int> getChildren(int v) const {
        if (v >= 0 && v < num_nodes) {
            return children[v];
        }
        return vector<int>();
    }
    
    bool isRoot(int v) const {
        return v >= 0 && v < num_nodes && parent[v] == -1;
    }
    
    bool isLeaf(int v) const {
        return v >= 0 && v < num_nodes && children[v].empty();
    }
    
    int getRoot() const {
        if (root_node != -1) return root_node;
        
        // Find root
        for (int i = 0; i < num_nodes; i++) {
            if (parent[i] == -1) {
                return i;
            }
        }
        return -1;
    }
    
    int getFirstChild(int v) const {
        if (v >= 0 && v < num_nodes && !children[v].empty()) {
            return children[v][0];
        }
        return -1;
    }
    
    void display() const {
        cout << "Graph-Based Tree:" << endl;
        for (int i = 0; i < num_nodes; i++) {
            cout << "Node " << i << ": children = [";
            for (size_t j = 0; j < children[i].size(); j++) {
                cout << children[i][j];
                if (j < children[i].size() - 1) cout << ", ";
            }
            cout << "], parent = " << parent[i] << endl;
        }
    }
    
    int getNumNodes() const { return num_nodes; }
    const vector<vector<int>>& getChildrenList() const { return children; }
    const vector<int>& getParentArray() const { return parent; }
};


// CONVERTER 1: Array of Parents → First-Child Next-Sibling
FirstChildNextSibling arrayOfParentsToFirstChildNextSibling(const ArrayOfParents& ap) {
    int n = ap.getNumNodes();
    FirstChildNextSibling fcns(n);
    
    // Build children lists for each node
    vector<vector<int>> children_lists(n);
    for (int i = 0; i < n; i++) {
        int parent = ap.getParent(i);
        if (parent != -1) {
            children_lists[parent].push_back(i);
        }
    }
    
    // Set root
    fcns.setRoot(ap.getRoot());
    
    // Build first-child and next-sibling links
    for (int u = 0; u < n; u++) {
        if (!children_lists[u].empty()) {
            // Sort children for consistent ordering
            sort(children_lists[u].begin(), children_lists[u].end());
            
            // Set first child
            fcns.setFirstChild(u, children_lists[u][0]);
            
            // Set next-sibling links
            for (size_t i = 0; i < children_lists[u].size() - 1; i++) {
                fcns.setNextSibling(children_lists[u][i], children_lists[u][i + 1]);
            }
            // Last child's next_sibling remains -1 (already initialized)
        }
    }
    
    return fcns;
}

// CONVERTER 2: First-Child Next-Sibling → Array of Parents
void dfsSetParents(const FirstChildNextSibling& fcns, ArrayOfParents& ap, int node, int parent) {
    ap.setParent(node, parent);
    
    // Visit all children
    int child = fcns.getFirstChild(node);
    while (child != -1) {
        dfsSetParents(fcns, ap, child, node);
        child = fcns.getNextSibling(child);
    }
}

ArrayOfParents firstChildNextSiblingToArrayOfParents(const FirstChildNextSibling& fcns) {
    int n = fcns.getNumNodes();
    ArrayOfParents ap(n);
    
    // Set root
    int root = fcns.getRoot();
    if (root != -1) {
        ap.setRoot(root);
        dfsSetParents(fcns, ap, root, -1);
    }
    
    return ap;
}

// CONVERTER 3: Array of Parents → Graph-Based
GraphBasedTree arrayOfParentsToGraphBased(const ArrayOfParents& ap) {
    int n = ap.getNumNodes();
    GraphBasedTree gt(n);
    
    // Set root
    int root = ap.getRoot();
    if (root != -1) {
        gt.setRoot(root);
    }
    
    // Add edges from parent to children
    for (int i = 0; i < n; i++) {
        int parent = ap.getParent(i);
        if (parent != -1) {
            gt.addEdge(parent, i);
        }
    }
    
    return gt;
}

// CONVERTER 4: Graph-Based → Array of Parents
ArrayOfParents graphBasedToArrayOfParents(const GraphBasedTree& gt) {
    int n = gt.getNumNodes();
    ArrayOfParents ap(n);
    
    // Set root
    int root = gt.getRoot();
    if (root != -1) {
        ap.setRoot(root);
    }
    
    // Extract parent relationships
    for (int i = 0; i < n; i++) {
        int parent = gt.getParent(i);
        ap.setParent(i, parent);
    }
    
    return ap;
}

// CONVERTER 5: First-Child Next-Sibling → Graph-Based
void dfsAddEdges(const FirstChildNextSibling& fcns, GraphBasedTree& gt, int node, int parent) {
    if (parent != -1) {
        gt.addEdge(parent, node);
    }
    
    // Visit all children
    int child = fcns.getFirstChild(node);
    while (child != -1) {
        dfsAddEdges(fcns, gt, child, node);
        child = fcns.getNextSibling(child);
    }
}

GraphBasedTree firstChildNextSiblingToGraphBased(const FirstChildNextSibling& fcns) {
    int n = fcns.getNumNodes();
    GraphBasedTree gt(n);
    
    // Set root
    int root = fcns.getRoot();
    if (root != -1) {
        gt.setRoot(root);
        dfsAddEdges(fcns, gt, root, -1);
    }
    
    return gt;
}

// CONVERTER 6: Graph-Based → First-Child Next-Sibling
FirstChildNextSibling graphBasedToFirstChildNextSibling(const GraphBasedTree& gt) {
    int n = gt.getNumNodes();
    FirstChildNextSibling fcns(n);
    
    // Set root
    int root = gt.getRoot();
    if (root != -1) {
        fcns.setRoot(root);
    }
    
    // Build first-child and next-sibling links
    for (int u = 0; u < n; u++) {
        vector<int> children = gt.getChildren(u);
        
        if (!children.empty()) {
            // Sort children for consistent ordering
            sort(children.begin(), children.end());
            
            // Set first child
            fcns.setFirstChild(u, children[0]);
            
            // Set next-sibling links
            for (size_t i = 0; i < children.size() - 1; i++) {
                fcns.setNextSibling(children[i], children[i + 1]);
            }
            // Last child's next_sibling remains -1
        }
    }
    
    return fcns;
}

// =====================================================
// FILE READER FOR TREES
// =====================================================
ArrayOfParents readTreeFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file: " << filename << endl;
        return ArrayOfParents(0);
    }
    
    string line;
    getline(file, line);
    int num_nodes = stoi(line);
    
    ArrayOfParents tree(num_nodes);
    
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        istringstream iss(line);
        string type;
        iss >> type;
        
        if (type == "root") {
            int root;
            iss >> root;
            tree.setRoot(root);
            cout << "Set root: " << root << endl;
        } else if (type == "edge") {
            int parent, child;
            iss >> parent >> child;
            tree.setParent(child, parent);
            cout << "Added edge: " << parent << " -> " << child << endl;
        }
    }
    
    file.close();
    return tree;
}

// =====================================================
// TEST FUNCTION
// =====================================================
void testAllTreeConverters() {
    cout << "TEST: All 6 Tree Representation Converters" << endl;
    cout << "===========================================" << endl;
    
    // Try to read from file, otherwise create sample tree
    ArrayOfParents original = readTreeFromFile("tree_sample.inp");
    
    if (original.getNumNodes() == 0) {
        cout << "Failed to read tree from file. Using sample data instead." << endl;

        ArrayOfParents sample(7);
        sample.setRoot(0);
        sample.setParent(1, 0);
        sample.setParent(2, 0);
        sample.setParent(3, 0);
        sample.setParent(4, 1);
        sample.setParent(5, 1);
        sample.setParent(6, 2);
        original = sample;
    }
    
    cout << "\nOriginal Array of Parents:" << endl;
    original.display();
    
    // Test from Array of Parents
    cout << "\n=== 1. FROM ARRAY OF PARENTS ===" << endl;
    auto fcns_result = arrayOfParentsToFirstChildNextSibling(original);
    auto gt_result = arrayOfParentsToGraphBased(original);
    
    cout << "1.1. ArrayOfParents → FirstChildNextSibling:" << endl;
    fcns_result.display();
    cout << "1.2. ArrayOfParents → GraphBased:" << endl;
    gt_result.display();
    
    // Test from First-Child Next-Sibling
    cout << "\n=== 2. FROM FIRST-CHILD NEXT-SIBLING ===" << endl;
    cout << "2.1. FirstChildNextSibling → ArrayOfParents:" << endl;
    firstChildNextSiblingToArrayOfParents(fcns_result).display();
    cout << "2.2. FirstChildNextSibling → GraphBased:" << endl;
    firstChildNextSiblingToGraphBased(fcns_result).display();
    
    // Test from Graph-Based
    cout << "\n=== 3. FROM GRAPH-BASED ===" << endl;
    cout << "3.1. GraphBased → ArrayOfParents:" << endl;
    graphBasedToArrayOfParents(gt_result).display();
    cout << "3.2. GraphBased → FirstChildNextSibling:" << endl;
    graphBasedToFirstChildNextSibling(gt_result).display();
    
    cout << "\nDONE" << endl;
}


int main() {
    testAllTreeConverters();
    return 0;
}