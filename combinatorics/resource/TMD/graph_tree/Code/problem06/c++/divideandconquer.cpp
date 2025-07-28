#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory> // For std::unique_ptr

// --- Data Structures ---
// Using raw pointers for this version to simplify passing subtrees in recursion
// without dealing with complex ownership semantics of unique_ptr.
// Memory management must be done manually.
struct Node {
    std::string label;
    std::vector<Node*> children;
    Node(std::string lbl) : label(std::move(lbl)) {}
    ~Node() {
        for(Node* child : children) {
            delete child;
        }
    }
};

class DivideAndConquerSolver {
public:
    /**
     * @brief Public entry point for the Divide and Conquer solver.
     *
     * This is a "naive" or "pure" implementation that does not use memoization.
     * It correctly implements the divide-and-conquer logic but will be very
     * inefficient due to the re-computation of overlapping subproblems.
     * Its primary purpose is to illustrate the D&C principle.
     */
    int solve(const Node* t1, const Node* t2) {
        return ted_dac(t1, t2);
    }

private:
    /**
     * @brief Helper to get the total number of nodes in a subtree.
     * This is used to calculate the cost of deleting or inserting an entire subtree.
     */
    int get_subtree_size(const Node* node) {
        if (!node) return 0;
        int size = 1;
        for (const auto* child : node->children) {
            size += get_subtree_size(child);
        }
        return size;
    }

    /**
     * @brief (Conquer) Recursively calculates TED between two nodes/subtrees.
     *
     * This function breaks the problem of transforming T1(rooted at t1) to
     * T2(rooted at t2) into smaller subproblems on their children forests.
     * It embodies the "divide" and "combine" steps.
     */
    int ted_dac(const Node* t1, const Node* t2) {
        // Base cases: one of the subtrees is empty. The problem is trivial:
        // the cost is inserting all nodes of the non-empty tree.
        if (!t1) return get_subtree_size(t2);
        if (!t2) return get_subtree_size(t1);

        // --- Divide & Combine Step ---

        // Option 1: Relabel roots and solve the subproblem on their forests.
        // This is the core recursive step.
        int cost_relabel = (t1->label == t2->label) ? 0 : 1;
        int res_sub = cost_relabel + forest_dist_dac(t1->children, t2->children);
        
        // Option 2 & 3: Delete the entire t1 subtree, or insert the entire t2 subtree.
        // This represents an alternative edit script.
        int res_del = get_subtree_size(t1);
        int res_ins = get_subtree_size(t2);

        // The result is the minimum cost among all possible first operations.
        return std::min({res_sub, res_del, res_ins});
    }

    /**
     * @brief (Conquer) Finds the min cost to map forest f1 to f2 using a DP-like approach.
     *
     * This function solves the subproblem of transforming a sequence of trees (a forest)
     * into another. It uses a temporary 2D table, similar to dynamic programming,
     * but each cell's calculation involves a new recursive call to `ted_dac`,
     * which leads to exponential complexity without memoization.
     */
    int forest_dist_dac(const std::vector<Node*>& f1, const std::vector<Node*>& f2) {
        int n = f1.size();
        int m = f2.size();
        
        // A temporary DP table to solve the forest-to-forest subproblem.
        std::vector<std::vector<int>> sub_dp(n + 1, std::vector<int>(m + 1, 0));

        // Base cases for the DP table: transforming a forest to an empty one (and vice versa).
        for (int i = 1; i <= n; ++i) 
            sub_dp[i][0] = sub_dp[i-1][0] + get_subtree_size(f1[i-1]);
        for (int j = 1; j <= m; ++j) 
            sub_dp[0][j] = sub_dp[0][j-1] + get_subtree_size(f2[j-1]);

        // Fill the rest of the table using recursive calls.
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                // Recursive calls to the main TED function for subtrees.
                // These calls will be repeated many times for the same subtrees.
                int cost_sub = ted_dac(f1[i-1], f2[j-1]); // Cost to transform tree i of f1 to tree j of f2
                int cost_del = get_subtree_size(f1[i-1]); // Cost to delete tree i of f1
                int cost_ins = get_subtree_size(f2[j-1]); // Cost to insert tree j of f2
                
                sub_dp[i][j] = std::min({sub_dp[i-1][j-1] + cost_sub,
                                         sub_dp[i-1][j] + cost_del,
                                         sub_dp[i][j-1] + cost_ins});
            }
        }
        return sub_dp[n][m];
    }
};

/**
 * @brief Helper function to build a tree from a parent array for testing.
 *
 * This function creates a tree structure in memory from a simple array format.
 * It uses raw pointers, so the caller is responsible for deleting the root node
 * to free all allocated memory.
 *
 * @param parents A vector where parents[i] is the parent of node i. Root's parent is -1.
 * @param labels A vector containing the string label for each node.
 * @return A raw pointer to the root of the newly created tree.
 */
Node* build_from_parents(const std::vector<int>& parents, const std::vector<std::string>& labels) {
    int n = parents.size();
    if (n == 0) return nullptr;
    
    std::vector<Node*> nodes;
    for(int i = 0; i < n; ++i) {
        nodes.push_back(new Node(labels[i]));
    }
    
    Node* root = nullptr;
    for(int i = 0; i < n; ++i) {
        if(parents[i] != -1) {
            nodes[parents[i]]->children.push_back(nodes[i]);
        } else {
            root = nodes[i];
        }
    }
    return root;
}

// =================================================================================
// MAIN FUNCTION - DEMONSTRATION FOR EXERCISE 6(c)
// =================================================================================
int main() {
    std::cout << "=====================================================" << std::endl;
    std::cout << "  (c) Tree Edit Distance: Pure Divide and Conquer    " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "WARNING: This naive version is very slow due to re-computing subproblems.\n" << std::endl;
    
    DivideAndConquerSolver solver;

    // --- Test Cases (must be small to run in a reasonable time) ---
    
    // Test Case 1: Simple relabel
    Node* t1 = build_from_parents({-1, 0, 0}, {"a", "b", "c"});
    Node* t2 = build_from_parents({-1, 0, 0}, {"a", "d", "c"});
    std::cout << "Distance( a{b,c}, a{d,c} ) = " << solver.solve(t1, t2) << " (Expected: 1)" << std::endl;

    // Test Case 2: More complex transformation
    Node* t3 = build_from_parents({-1, 0}, {"x", "y"});
    std::cout << "Distance( a{b,c}, x{y} ) = " << solver.solve(t1, t3) << " (Expected: 2)" << std::endl;

    // --- Cleanup ---
    // Manually delete the root, which will recursively delete all children.
    delete t1;
    delete t2;
    delete t3;

    return 0;
}