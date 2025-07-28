#include <iostream>
#include <vector>
#include <optional> // For std::optional (requires C++17)
#include <string>

/**
 * @brief Exercise 1.9: Implements the T.previous_sibling(v) operation.
 *
 * This function finds the sibling of a node `v` that appears immediately
 * before it, based on the node index ordering. It operates on the
 * array-of-parents representation of a tree.
 *
 * The algorithm is as follows:
 * 1. Find the parent `p` of the given node `v`. If `v` is the root, it has no siblings.
 * 2. Iterate from the beginning of the array up to `v-1`.
 * 3. Keep track of the last node `i` encountered such that parent[i] == p.
 * 4. This last node found is the immediate previous sibling.
 *
 * @param v The node whose previous sibling is to be found.
 * @param parent_array The tree represented as an array of parents. parent[i] is the
 *                     parent of node i. The root's parent is -1.
 * @return An std::optional<int> containing the index of the previous sibling if one
 *         exists, otherwise std::nullopt.
 */
std::optional<int> previous_sibling_cpp(int v, const std::vector<int>& parent_array) {
    // Validate input node index
    if (v < 0 || v >= parent_array.size()) {
        return std::nullopt;
    }
    
    int parent = parent_array[v];
    
    // The root has no parent, and thus no siblings.
    if (parent == -1) {
        return std::nullopt;
    }
        
    std::optional<int> prev_sibling;
    
    // Iterate through all nodes with index less than v.
    for (int i = 0; i < v; ++i) {
        // If node `i` has the same parent, it is an earlier sibling.
        if (parent_array[i] == parent) {
            // Keep updating, so we end up with the one with the largest index less than v.
            prev_sibling = i;
        }
    }
            
    return prev_sibling;
}

// =================================================================================
// MAIN FUNCTION - DEMONSTRATION FOR EXERCISE 1.9
// =================================================================================
int main() {
    std::cout << "=====================================================" << std::endl;
    std::cout << "  `previous_sibling` Demo (Exercise 1.9)             " << std::endl;
    std::cout << "=====================================================" << std::endl;

    // Tree representation: P[i] = parent of node i.
    // Node 0 is root.
    // Children of 0: {1, 2}
    // Children of 1: {3, 4}
    // Children of 2: {5, 6}
    std::vector<int> parent_array = {-1, 0, 0, 1, 1, 2, 2};
    std::cout << "Tree (Parent Array): {-1, 0, 0, 1, 1, 2, 2}\n" << std::endl;

    // Test cases
    std::vector<int> nodes_to_test = {0, 1, 2, 3, 4, 6};
    
    for (int node : nodes_to_test) {
        std::cout << "-> Finding previous sibling of node " << node << ":" << std::endl;
        std::optional<int> result = previous_sibling_cpp(node, parent_array);
        if (result.has_value()) {
            std::cout << "   Result: Node " << result.value() << std::endl;
        } else {
            std::cout << "   Result: No previous sibling exists." << std::endl;
        }
    }
    
    std::cout << "=====================================================" << std::endl;

    return 0;
}