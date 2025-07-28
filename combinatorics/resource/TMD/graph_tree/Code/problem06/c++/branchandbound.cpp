#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <climits> // For INT_MAX

// --- Data Structures ---
struct Node {
    std::string label;
    std::vector<Node*> children; // Using raw pointers for simplicity in this recursive algorithm
    Node(std::string lbl) : label(std::move(lbl)) {}
    ~Node() {
        for(Node* child : children) {
            delete child;
        }
    }
};

class BranchAndBoundSolver {
private:
    int min_cost_so_far; // Stores the best (minimum) cost found globally for a single solve() call.

public:
    /**
     * @brief Public entry point for the Branch and Bound solver.
     * It initializes the best-known cost to an upper bound and starts the search.
     * @param t1 The root of the first tree.
     * @param t2 The root of the second tree.
     * @return The minimum tree edit distance.
     */
    int solve(const Node* t1, const Node* t2) {
        // Initialize min_cost with a simple upper bound: delete all nodes in t1, insert all in t2.
        min_cost_so_far = get_subtree_size(t1) + get_subtree_size(t2);
        
        _ted_bnb(t1, t2, 0);
        return min_cost_so_far;
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
     * @brief The core recursive function for Branch and Bound between two subtrees.
     * @param t1 Current node from tree 1.
     * @param t2 Current node from tree 2.
     * @param current_cost The cost accumulated to reach this state.
     */
    void _ted_bnb(const Node* t1, const Node* t2, int current_cost) {
        // --- Pruning Step 1: Check against global minimum ---
        if (current_cost >= min_cost_so_far) {
            return; // This path is already worse than a known solution.
        }

        // --- Pruning Step 2: Use a lower bound heuristic ---
        // A simple lower bound is the difference in subtree sizes.
        int lower_bound = std::abs(get_subtree_size(t1) - get_subtree_size(t2));
        if (current_cost + lower_bound >= min_cost_so_far) {
            return; // Prune this branch as it cannot lead to a better solution.
        }

        // --- Base Cases ---
        if (!t1) {
            min_cost_so_far = std::min(min_cost_so_far, current_cost + get_subtree_size(t2));
            return;
        }
        if (!t2) {
            min_cost_so_far = std::min(min_cost_so_far, current_cost + get_subtree_size(t1));
            return;
        }

        // --- Branching Step on Root Nodes ---
        int cost_relabel = (t1->label == t2->label) ? 0 : 1;
        _forest_dist_bnb(t1->children, t2->children, current_cost + cost_relabel);
    }
    
    /**
     * @brief Recursive B&B to find the min cost to map forest f1 to forest f2.
     */
    void _forest_dist_bnb(const std::vector<Node*>& f1, const std::vector<Node*>& f2, int current_cost) {
        // --- Pruning Step for Forests ---
        if (current_cost >= min_cost_so_far) {
            return;
        }

        // --- Base Cases ---
        if (f1.empty() && f2.empty()) {
            min_cost_so_far = std::min(min_cost_so_far, current_cost);
            return;
        }
        if (f1.empty()) {
            min_cost_so_far = std::min(min_cost_so_far, current_cost + sum_forest_size(f2));
            return;
        }
        if (f2.empty()) {
            min_cost_so_far = std::min(min_cost_so_far, current_cost + sum_forest_size(f1));
            return;
        }
        
        const Node* t1_head = f1.front();
        std::vector<Node*> f1_tail(f1.begin() + 1, f1.end());

        // --- Branching on Forest Mappings ---
        
        // Branch 1: Delete t1_head from f1 and map the rest of f1 to f2.
        _forest_dist_bnb(f1_tail, f2, current_cost + get_subtree_size(t1_head));

        // Branch 2: Match t1_head with each tree t2_j in f2.
        for (size_t j = 0; j < f2.size(); ++j) {
            const Node* t2_match = f2[j];
            std::vector<Node*> f2_remaining;
            for(size_t k = 0; k < f2.size(); ++k) {
                if (k != j) f2_remaining.push_back(f2[k]);
            }
            
            // To solve the subproblem ted(t1_head, t2_match), we need a new B&B instance
            // since it has its own min_cost context.
            BranchAndBoundSolver sub_solver;
            int cost_match_subproblem = sub_solver.solve(t1_head, t2_match);
            
            // Recurse on the rest of the forests with the new accumulated cost.
            _forest_dist_bnb(f1_tail, f2_remaining, current_cost + cost_match_subproblem);
        }
    }

    // Helper to sum sizes of forests.
    int sum_forest_size(const std::vector<Node*>& f) {
        int size = 0;
        for (const auto* t : f) {
            size += get_subtree_size(t);
        }
        return size;
    }
};

// Helper to build trees from parent array using raw pointers for this example
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
// MAIN FUNCTION - DEMONSTRATION FOR EXERCISE 6(b)
// =================================================================================
int main() {
    std::cout << "=====================================================" << std::endl;
    std::cout << "     (b) Tree Edit Distance: Branch and Bound        " << std::endl;
    std::cout << "=====================================================" << std::endl;
    std::cout << "NOTE: Still slow, but prunes search paths vs. pure backtracking.\n" << std::endl;
    
    // --- Test Cases ---
    
    // Test Case 1: Simple relabel
    Node* t1 = build_from_parents({-1, 0, 0}, {"a", "b", "c"});
    Node* t2 = build_from_parents({-1, 0, 0}, {"a", "d", "c"});
    BranchAndBoundSolver solver1;
    std::cout << "Distance( a{b,c}, a{d,c} ) = " << solver1.solve(t1, t2) << " (Expected: 1)" << std::endl;

    // Test Case 2: More complex transformation
    Node* t3 = build_from_parents({-1}, {"x"});
    BranchAndBoundSolver solver2;
    std::cout << "Distance( a{b,c}, x ) = " << solver2.solve(t1, t3) << " (Expected: 3)" << std::endl;

    // Test Case 3: A slightly larger example
    Node* t4 = build_from_parents({-1, 0, 0, 1}, {"a", "b", "c", "d"});
    Node* t5 = build_from_parents({-1, 0, 0}, {"a", "b", "x"});
    BranchAndBoundSolver solver3;
    std::cout << "Distance( a{b{d},c}, a{b,x} ) = " << solver3.solve(t4, t5) << " (Expected: 2, del d, relabel c->x)" << std::endl;

    // --- Cleanup ---
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;

    std::cout << "=====================================================" << std::endl;

    return 0;
}