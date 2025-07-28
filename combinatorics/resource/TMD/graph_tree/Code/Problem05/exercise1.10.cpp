#include <iostream>
#include <vector>
#include <string>

/**
 * @class ExtendedFCNSTree
 * @brief Exercise 1.10: Implements the extended first-child, next-sibling representation.
 *
 * This class is designed to support several key operations (`root`, `parent`, 
 * `number_of_children`) in O(1) time, as requested by Problem 1.5.
 * It achieves this by pre-computing and storing extra information (parent array,
 * children counts, and root index) during its construction.
 */
class ExtendedFCNSTree {
private:
    struct Node {
        int first_child = -1;
        int next_sibling = -1;
    };

    int num_nodes;
    int root_node = -1;
    std::vector<int> parent_array;      // O(1) parent lookup
    std::vector<int> children_count;    // O(1) children count lookup
    std::vector<Node> fcns_nodes;       // The core FCNS representation

    /**
     * @brief Private helper to build the extended representation from a parent array.
     * This is the pre-computation step that makes later queries fast.
     */
    void _build_representation() {
        // 1. Build a temporary adjacency list (parent -> list of children)
        std::vector<std::vector<int>> adj(num_nodes);
        for (int i = 0; i < num_nodes; ++i) {
            int p = parent_array[i];
            if (p != -1) {
                adj[p].push_back(i);
            } else {
                root_node = i;
            }
        }
        
        // 2. Populate the FCNS structure and children_count from the adjacency list
        for (int i = 0; i < num_nodes; ++i) {
            children_count[i] = adj[i].size();
            if (!adj[i].empty()) {
                fcns_nodes[i].first_child = adj[i][0];
                for (size_t j = 0; j < adj[i].size() - 1; ++j) {
                    int current_child = adj[i][j];
                    int next_child = adj[i][j+1];
                    fcns_nodes[current_child].next_sibling = next_child;
                }
            }
        }
    }

public:
    /**
     * @brief Constructs the tree from a parent array.
     * @param parents The tree represented as an array of parents.
     */
    ExtendedFCNSTree(const std::vector<int>& parents) {
        num_nodes = parents.size();
        parent_array = parents;
        children_count.resize(num_nodes, 0);
        fcns_nodes.resize(num_nodes);
        
        _build_representation();
    }
    
    // --- O(1) Operations ---
    
    int root() const { return root_node; }
    int parent(int v) const { return (v < num_nodes) ? parent_array[v] : -1; }
    int number_of_children(int v) const { return (v < num_nodes) ? children_count[v] : 0; }
    
    /**
     * @brief Returns a list of all children of a node.
     * @note This operation is O(k) where k is the number of children, because it
     *       has to construct and return a new list. Achieving true O(1) would
     *       require returning a reference to a pre-stored list, which adds more
     *       memory overhead.
     * @param v The parent node.
     * @return A vector containing the indices of all children.
     */
    std::vector<int> children(int v) const {
        std::vector<int> child_list;
        if (v < num_nodes) {
            int child = fcns_nodes[v].first_child;
            while(child != -1) {
                child_list.push_back(child);
                child = fcns_nodes[child].next_sibling;
            }
        }
        return child_list;
    }
};

// =================================================================================
// MAIN FUNCTION - DEMONSTRATION FOR EXERCISE 1.10
// =================================================================================
int main() {
    std::cout << "=====================================================" << std::endl;
    std::cout << "  Extended FCNS Tree Class Demo (Exercise 1.10)      " << std::endl;
    std::cout << "=====================================================" << std::endl;

    std::vector<int> parent_array = {-1, 0, 0, 1, 1, 2, 2, 0};
    std::cout << "Initializing tree from parent array: {-1, 0, 0, 1, 1, 2, 2, 0}\n" << std::endl;

    ExtendedFCNSTree tree(parent_array);

    std::cout << "--- Testing O(1) operations ---" << std::endl;
    std::cout << "  Root of the tree: " << tree.root() << std::endl;
    int test_node_0 = 0;
    std::cout << "  Number of children of node " << test_node_0 << ": " << tree.number_of_children(test_node_0) << std::endl;
    int test_node_1 = 1;
    std::cout << "  Number of children of node " << test_node_1 << ": " << tree.number_of_children(test_node_1) << std::endl;
    int test_node_3 = 3;
    std::cout << "  Number of children of node " << test_node_3 << ": " << tree.number_of_children(test_node_3) << std::endl;

    std::cout << "\n--- Testing O(k) children list retrieval ---" << std::endl;
    std::cout << "  Children of node 0: ";
    for (int child : tree.children(0)) { std::cout << child << " "; }
    std::cout << std::endl;
    
    std::cout << "  Children of node 1: ";
    for (int child : tree.children(1)) { std::cout << child << " "; }
    std::cout << std::endl;

    std::cout << "=====================================================" << std::endl;

    return 0;
}