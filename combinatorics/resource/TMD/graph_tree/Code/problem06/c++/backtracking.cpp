#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

// --- Data Structures ---
struct Node {
    std::string label;
    std::vector<std::unique_ptr<Node>> children;
    Node(std::string lbl) : label(std::move(lbl)) {}
    void add_child(std::unique_ptr<Node> child) {
        children.push_back(std::move(child));
    }
};

class BacktrackingSolver {
public:
    /**
     * @brief Public entry point for the backtracking solver.
     */
    int solve(const Node* t1, const Node* t2) {
        return ted_backtracking(t1, t2);
    }

private:
    /**
     * @brief Helper to get the total number of nodes in a subtree.
     */
    int get_subtree_size(const Node* node) {
        if (!node) return 0;
        int size = 1;
        for (const auto& child : node->children) {
            size += get_subtree_size(child.get());
        }
        return size;
    }

    /**
     * @brief Recursively calculates TED between two nodes/subtrees.
     */
    int ted_backtracking(const Node* t1, const Node* t2) {
        if (!t1) return get_subtree_size(t2); // Cost is inserting all of t2
        if (!t2) return get_subtree_size(t1); // Cost is deleting all of t1

        // Case 1: Relabel roots and map forests
        int cost_relabel = (t1->label == t2->label) ? 0 : 1;
        int res_sub = cost_relabel + forest_dist_backtracking(t1->children, t2->children);
        
        // Case 2: Delete entire tree t1 and insert entire tree t2
        // This is a simplified definition, often used. More complex ones exist.
        int res_del_ins = get_subtree_size(t1) + get_subtree_size(t2);

        return std::min(res_sub, res_del_ins);
    }

    /**
     * @brief Recursively finds the minimum cost to map forest f1 to forest f2.
     * This is the core of the combinatorial explosion.
     */
    int forest_dist_backtracking(const std::vector<std::unique_ptr<Node>>& f1, const std::vector<std::unique_ptr<Node>>& f2) {
        if (f1.empty()) return sum_forest_size(f2);
        if (f2.empty()) return sum_forest_size(f1);

        // For simplicity with unique_ptr, convert to raw pointers for recursion
        std::vector<const Node*> f1_ptr, f2_ptr;
        for(const auto& n : f1) f1_ptr.push_back(n.get());
        for(const auto& n : f2) f2_ptr.push_back(n.get());
        
        return _forest_dist_recursive_util(f1_ptr, f2_ptr);
    }
    
    int _forest_dist_recursive_util(const std::vector<const Node*>& f1, const std::vector<const Node*>& f2) {
        if (f1.empty()) return sum_forest_size_ptr(f2);
        if (f2.empty()) return sum_forest_size_ptr(f1);

        const Node* t1_head = f1.front();
        std::vector<const Node*> f1_tail(f1.begin() + 1, f1.end());

        // Option A: Delete t1_head
        int cost_del = get_subtree_size(t1_head) + _forest_dist_recursive_util(f1_tail, f2);

        // Option B: Match t1_head with each tree t2_j in f2
        int min_match_cost = 1e9; // A large number
        for (size_t j = 0; j < f2.size(); ++j) {
            std::vector<const Node*> f2_remaining;
            for(size_t k = 0; k < f2.size(); ++k) if (k != j) f2_remaining.push_back(f2[k]);
            
            int cost_match = ted_backtracking(t1_head, f2[j]) + _forest_dist_recursive_util(f1_tail, f2_remaining);
            min_match_cost = std::min(min_match_cost, cost_match);
        }
        
        return std::min(cost_del, min_match_cost);
    }

    // Helper to sum sizes of forests
    int sum_forest_size(const std::vector<std::unique_ptr<Node>>& f) {
        int size = 0; for (const auto& t : f) size += get_subtree_size(t.get()); return size;
    }
    int sum_forest_size_ptr(const std::vector<const Node*>& f) {
        int size = 0; for (const auto* t : f) size += get_subtree_size(t); return size;
    }
};

// Helper to build trees for testing
std::unique_ptr<Node> build_from_parents(const std::vector<int>& parents, const std::vector<std::string>& labels);

int main() {
    std::cout << "=============================================" << std::endl;
    std::cout << "     (a) Tree Edit Distance: Backtracking    " << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "WARNING: This method is extremely slow and only works for tiny trees.\n" << std::endl;
    
    BacktrackingSolver solver;

    auto t1 = build_from_parents({-1, 0}, {"a", "b"});
    auto t2 = build_from_parents({-1, 0}, {"a", "c"});
    auto t3 = build_from_parents({-1}, {"x"});

    std::cout << "Distance( a{b}, a{c} ) = " << solver.solve(t1.get(), t2.get()) << " (Expected: 1)" << std::endl;
    std::cout << "Distance( a{b}, x ) = " << solver.solve(t1.get(), t3.get()) << " (Expected: 2)" << std::endl;

    return 0;
}

std::unique_ptr<Node> build_from_parents(const std::vector<int>& parents, const std::vector<std::string>& labels) {
    int n = parents.size();
    if (n == 0) return nullptr;
    std::vector<std::unique_ptr<Node>> nodes;
    for(int i = 0; i < n; ++i) nodes.push_back(std::make_unique<Node>(labels[i]));
    
    Node* root_ptr = nullptr;
    int root_idx = -1;
    for(int i = 0; i < n; ++i) {
        if(parents[i] != -1) {
            nodes[parents[i]]->add_child(std::move(nodes[i]));
        } else {
            root_ptr = nodes[i].get();
            root_idx = i;
        }
    }
    if (root_idx != -1) return std::move(nodes[root_idx]);
    return nullptr;
}