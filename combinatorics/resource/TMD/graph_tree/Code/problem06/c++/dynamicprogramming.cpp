#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <unordered_map>

// --- Data Structures ---
// Using raw pointers for this version to simplify map keys.
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

// Custom hash function for pairs of Node pointers, required for unordered_map
struct NodePtrPairHash {
    std::size_t operator()(const std::pair<const Node*, const Node*>& p) const {
        auto h1 = std::hash<const Node*>{}(p.first);
        auto h2 = std::hash<const Node*>{}(p.second);
        // Combine hashes to reduce collisions
        return h1 ^ (h2 << 1);
    }
};

class DpSolver {
private:
    // Memoization table: stores the computed distance for a pair of subtrees.
    // This is the core of the dynamic programming optimization.
    std::unordered_map<std::pair<const Node*, const Node*>, int, NodePtrPairHash> memo;

public:
    /**
     * @brief Public entry point for the Dynamic Programming solver.
     * This method clears any previous memoization results and starts the recursion.
     * @param t1 The root of the first tree.
     * @param t2 The root of the second tree.
     * @return The minimum tree edit distance.
     */
    int solve(const Node* t1, const Node* t2) {
        memo.clear();
        return ted_dp(t1, t2);
    }

private:
    /**
     * @brief Helper to get the total number of nodes in a subtree.
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
     * @brief The core recursive function with memoization for calculating TED.
     *
     * This function implements the Zhang-Shasha algorithm. It's a divide-and-conquer
     * approach enhanced with a memoization table (`memo`) to store and reuse results
     * of overlapping subproblems, changing the complexity from exponential to polynomial.
     */
    int ted_dp(const Node* t1, const Node* t2) {
        // Step 1: Check memoization table first. If result exists, return it immediately.
        if (memo.count({t1, t2})) {
            return memo.at({t1, t2});
        }
            
        int res;
        // Base cases: one of the subtrees is empty.
        if (!t1) {
            res = get_subtree_size(t2);
        } else if (!t2) {
            res = get_subtree_size(t1);
        } else {
            // Recursive step: calculate costs for the three main operations.
            int cost_relabel = (t1->label == t2->label) ? 0 : 1;
            int res_sub = cost_relabel + forest_dist_dp(t1->children, t2->children);
            
            // Note: The classic Zhang-Shasha definition is used for delete/insert costs
            // which involves mapping a tree to an empty node or vice-versa.
            int res_del = 1 + ted_dp(nullptr, t2) + forest_dist_dp(t1->children, {}); // Cost to delete t1's root
            int res_ins = 1 + ted_dp(t1, nullptr) + forest_dist_dp({}, t2->children); // Cost to insert t2's root
            
            res = std::min({res_sub, res_del, res_ins});
        }
        
        // Step 2: Store the newly computed result in the memoization table before returning.
        return memo[{t1, t2}] = res;
    }

    /**
     * @brief Calculates the edit distance between two forests using a DP table.
     * This is a subproblem within the main TED calculation.
     */
    int forest_dist_dp(const std::vector<Node*>& f1, const std::vector<Node*>& f2) {
        int n = f1.size();
        int m = f2.size();
        std::vector<std::vector<int>> dp_table(n + 1, std::vector<int>(m + 1, 0));

        // Base cases for the DP table (mapping a forest to an empty one).
        for (int i = 1; i <= n; ++i) 
            dp_table[i][0] = dp_table[i-1][0] + get_subtree_size(f1[i-1]);
        for (int j = 1; j <= m; ++j) 
            dp_table[0][j] = dp_table[0][j-1] + get_subtree_size(f2[j-1]);

        // Fill the rest of the table using recursive calls to the memoized `ted_dp`.
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int cost_sub = ted_dp(f1[i-1], f2[j-1]);
                int cost_del = get_subtree_size(f1[i-1]);
                int cost_ins = get_subtree_size(f2[j-1]);
                
                dp_table[i][j] = std::min({dp_table[i-1][j-1] + cost_sub,
                                           dp_table[i-1][j] + cost_del,
                                           dp_table[i][j-1] + cost_ins});
            }
        }
        return dp_table[n][m];
    }
};

/**
 * @brief Helper function to build a tree from a parent array for testing.
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
// MAIN FUNCTION - DEMONSTRATION FOR EXERCISE 6(d)
// =================================================================================
int main() {
    std::cout << "=====================================================" << std::endl;
    std::cout << "  (d) Tree Edit Distance: Dynamic Programming        " << std::endl;
    std::cout << "=====================================================" << std::endl;
    
    DpSolver solver;
    
    // --- Test Cases ---
    
    // Test Case 1: Simple relabel
    Node* t1 = build_from_parents({-1, 0, 0}, {"a", "b", "c"});
    Node* t2 = build_from_parents({-1, 0, 0}, {"a", "d", "c"});
    std::cout << "Distance( a{b,c}, a{d,c} ) = " << solver.solve(t1, t2) << " (Expected: 1)" << std::endl;

    // Test Case 2: More complex transformation
    Node* t3 = build_from_parents({-1, 0, 2}, {"x", "y", "z"});
    std::cout << "Distance( a{b,c}, x{y,z{}} ) = " << solver.solve(t1, t3) << " (Expected: 3)" << std::endl;

    // Test Case 3: Larger trees
    Node* t4 = build_from_parents({-1, 0, 0, 1, 1, 2}, {"f", "a", "d", "b", "c", "e"});
    Node* t5 = build_from_parents({-1, 0, 0, 2, 2, 2}, {"f", "c", "d", "a", "b", "e"});
    std::cout << "Distance( f{a{b,c},d{e}}, f{c,d{a,b,e}} ) = " << solver.solve(t4, t5) << " (Expected: 2)" << std::endl;

    // --- Cleanup ---
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;

    return 0;
}