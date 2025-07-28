#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits> // For numeric_limits
#include <queue>  // For BFS in get_leaves_in_subtree
#include <memory> // For std::unique_ptr
#include <algorithm> // For std::min

// --- Global Constants and Costs ---
const int LAMBDA_NODE = -1; // Represents a dummy node for deletion
const int DEL_COST = 1;     // Cost for deleting a node from T1
const int INS_COST = 1;     // Cost for inserting a node into T2
const int REP_COST = 1;     // Cost for relabeling

// --- Tree Node Class ---
class TreeNode {
public:
    int id;
    std::string label;
    int parent_id;
    std::vector<int> children_ids;
    int depth;
    int preorder_index;

    // Not directly used in this D&C variant but kept for completeness based on Python
    int postorder_index;
    int leftmost_descendant_postorder_idx;
    int subtree_size;

    TreeNode(int id, std::string label) :
        id(id), label(std::move(label)), parent_id(LAMBDA_NODE),
        depth(-1), preorder_index(-1), postorder_index(-1),
        leftmost_descendant_postorder_idx(-1), subtree_size(0) {}

    // For debugging/printing
    std::string toString() const {
        std::string parent_repr = (parent_id != LAMBDA_NODE) ? std::to_string(parent_id) : "None";
        std::string children_repr = "";
        for (size_t i = 0; i < children_ids.size(); ++i) {
            children_repr += std::to_string(children_ids[i]);
            if (i < children_ids.size() - 1) {
                children_repr += ", ";
            }
        }
        return "Node(ID:" + std::to_string(id) + ", Label:'" + label + "', Parent:" + parent_repr +
               ", Children:[" + children_repr + "], Depth:" + std::to_string(depth) +
               ", Preorder:" + std::to_string(preorder_index) + ")";
    }
};

// --- Tree Class ---
class Tree {
public:
    std::string name;
    std::map<int, std::unique_ptr<TreeNode>> nodes; // Using unique_ptr for automatic memory management
    int root_id;
    int _next_node_id;
    std::vector<int> _preorder_traversal_list;

    Tree(std::string name = "") :
        name(std::move(name)), root_id(LAMBDA_NODE), _next_node_id(0) {}

    // Disallow copy and assignment for Tree containing unique_ptr
    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;
    // Allow move construction and assignment
    Tree(Tree&&) = default;
    Tree& operator=(Tree&&) = default;

    int add_node(std::string label, int parent_id = LAMBDA_NODE) {
        int node_id = _next_node_id++;
        auto newNode = std::make_unique<TreeNode>(node_id, std::move(label));
        
        if (parent_id != LAMBDA_NODE) {
            auto it = nodes.find(parent_id);
            if (it == nodes.end()) {
                throw std::runtime_error("Parent with ID " + std::to_string(parent_id) + " does not exist in tree '" + name + "'.");
            }
            it->second->children_ids.push_back(node_id);
            newNode->parent_id = parent_id;
        } else if (root_id == LAMBDA_NODE) {
            root_id = node_id;
        } else {
            throw std::runtime_error("Tree '" + name + "' already has a root. New nodes without parent must be the root.");
        }
        nodes[node_id] = std::move(newNode); // Transfer ownership
        return node_id;
    }

    // Get a raw pointer to a node. Be careful not to hold onto this pointer after the unique_ptr owning it is destroyed.
    TreeNode* get_node(int node_id) const {
        auto it = nodes.find(node_id);
        if (it != nodes.end()) {
            return it->second.get();
        }
        return nullptr;
    }

    std::vector<TreeNode*> get_children_nodes(int node_id) const {
        std::vector<TreeNode*> children_nodes;
        TreeNode* node = get_node(node_id);
        if (node) {
            for (int child_id : node->children_ids) {
                children_nodes.push_back(get_node(child_id));
            }
        }
        return children_nodes;
    }

    void _dfs_preorder_and_depth(int node_id, int current_depth, int& current_preorder_index) {
        TreeNode* node = get_node(node_id);
        if (!node) {
            return;
        }

        node->depth = current_depth;
        node->preorder_index = current_preorder_index++;
        _preorder_traversal_list.push_back(node_id);

        for (int child_id : node->children_ids) {
            _dfs_preorder_and_depth(child_id, current_depth + 1, current_preorder_index);
        }
    }
    
    void compute_traversals_and_metadata() {
        if (root_id == LAMBDA_NODE) {
            return;
        }
        _preorder_traversal_list.clear();
        int current_preorder_index = 0;
        _dfs_preorder_and_depth(root_id, 0, current_preorder_index);
    }
};

// --- Divide and Conquer (Constrained to Leaf Operations) for Tree Edit Distance ---

// Helper to get all leaf nodes in a given subtree
std::vector<TreeNode*> get_leaves_in_subtree(TreeNode* node, const Tree& tree_obj) {
    std::vector<TreeNode*> leaves;
    if (!node) return leaves;

    std::queue<TreeNode*> q;
    q.push(node);

    while (!q.empty()) {
        TreeNode* curr_node = q.front();
        q.pop();

        if (tree_obj.get_children_nodes(curr_node->id).empty()) { // It's a leaf
            leaves.push_back(curr_node);
        } else {
            for (TreeNode* child_node : tree_obj.get_children_nodes(curr_node->id)) {
                q.push(child_node);
            }
        }
    }
    return leaves;
}

// Helper to calculate the cost of an operation (delete/insert) on an entire subtree
// based on the "leaves only" constraint.
int get_constrained_subtree_op_cost(TreeNode* node, const Tree& tree_obj, const std::string& operation_type) {
    if (!node) return 0;
    std::vector<TreeNode*> leaves = get_leaves_in_subtree(node, tree_obj);
    int cost_per_leaf = (operation_type == "delete") ? DEL_COST : INS_COST;
    return static_cast<int>(leaves.size()) * cost_per_leaf;
}

// Memoization cache for (node1_id, node2_id) -> cost
std::map<std::pair<int, int>, int> memo;

// Main recursive function
int constrained_ted_recursive(TreeNode* node1, TreeNode* node2, const Tree& T1, const Tree& T2) {
    // Use node IDs for memoization key, handle nullptr nodes for root of empty trees
    std::pair<int, int> key = {node1 ? node1->id : LAMBDA_NODE, node2 ? node2->id : LAMBDA_NODE};
    if (memo.count(key)) {
        return memo[key];
    }

    // Base Cases
    if (node1 == nullptr && node2 == nullptr) {
        return 0;
    }
    if (node1 == nullptr) { // T1 exhausted, insert remaining T2 subtree (all its leaves)
        return get_constrained_subtree_op_cost(node2, T2, "insert");
    }
    if (node2 == nullptr) { // T2 exhausted, delete remaining T1 subtree (all its leaves)
        return get_constrained_subtree_op_cost(node1, T1, "delete");
    }

    // Recursive Step: Consider matching node1 and node2
    // Relabel cost for the current nodes
    int relabel_cost = (node1->label != node2->label) ? REP_COST : 0;
    
    // Divide: Recursively solve for children's forests
    std::vector<TreeNode*> children1 = T1.get_children_nodes(node1->id);
    std::vector<TreeNode*> children2 = T2.get_children_nodes(node2->id);
    
    // Conquer: Compute forest edit distance (using a nested DP similar to Wagner-Fischer for sequences)
    // forest_dp_table[i][j] stores edit distance between first `i` children of node1 and first `j` children of node2
    std::vector<std::vector<int>> forest_dp_table(children1.size() + 1, std::vector<int>(children2.size() + 1));

    // Initialize first row (deleting children from T1's forest)
    for (size_t i = 1; i <= children1.size(); ++i) {
        forest_dp_table[i][0] = forest_dp_table[i-1][0] + get_constrained_subtree_op_cost(children1[i-1], T1, "delete");
    }
    // Initialize first column (inserting children into T2's forest)
    for (size_t j = 1; j <= children2.size(); ++j) {
        forest_dp_table[0][j] = forest_dp_table[0][j-1] + get_constrained_subtree_op_cost(children2[j-1], T2, "insert");
    }

    // Fill the forest DP table
    for (size_t i = 1; i <= children1.size(); ++i) {
        for (size_t j = 1; j <= children2.size(); ++j) {
            // Cost if we match current children (recursive call to main TED function for subtrees)
            int match_current_children_cost = constrained_ted_recursive(children1[i-1], children2[j-1], T1, T2);
            
            // Fix: Use nested std::min calls instead of initializer list for broader compiler compatibility
            int option1 = forest_dp_table[i-1][j] + get_constrained_subtree_op_cost(children1[i-1], T1, "delete");
            int option2 = forest_dp_table[i][j-1] + get_constrained_subtree_op_cost(children2[j-1], T2, "insert");
            int option3 = forest_dp_table[i-1][j-1] + match_current_children_cost;

            forest_dp_table[i][j] = std::min(option1, std::min(option2, option3));
        }
    }
            
    // The total cost for matching node1 and node2 is their relabel cost + the cost of transforming their children forests
    int match_option_cost = relabel_cost + forest_dp_table[children1.size()][children2.size()];

    // Store result in memo and return
    memo[key] = match_option_cost;
    return match_option_cost;
}

// Wrapper function for the Divide and Conquer algorithm
std::pair<int, std::map<std::string, int>> divide_and_conquer_constrained_tree_edit_distance(Tree& T1, Tree& T2) {
    // Clear memoization cache for a fresh run
    memo.clear();

    // Pre-compute basic traversals (like depth and preorder) for Tree objects.
    T1.compute_traversals_and_metadata();
    T2.compute_traversals_and_metadata();

    // Start the recursive process from the roots of the trees
    int min_cost = constrained_ted_recursive(T1.get_node(T1.root_id), T2.get_node(T2.root_id), T1, T2);

    // Details (exact operation counts) are complex to reconstruct from this DP/recursion
    // and typically require additional backtracking.
    std::map<std::string, int> details;
    details["deletions"] = -1;
    details["insertions"] = -1;
    details["relabelings"] = -1;

    return {min_cost, details};
}


// --- Main Example Usage ---
int main() {
    std::cout << "--- Example Tree Edit Distance Problem (c) Divide-and-Conquer (Leaves-Only Operations) ---" << std::endl;

    // Define Tree T1
    //       A
    //      / \
    //     B   C
    //    /
    //   D
    Tree T1("T1");
    int nA = T1.add_node("A");
    int nB = T1.add_node("B", nA);
    int nC = T1.add_node("C", nA);
    int nD = T1.add_node("D", nB);

    std::cout << "\nTree T1:" << std::endl;
    T1.compute_traversals_and_metadata();
    std::cout << "Root: " << T1.get_node(T1.root_id)->label << ", Nodes: " << T1.nodes.size() << std::endl;

    // Define Tree T2
    //       A
    //      / \
    //     X   Y
    //    /
    //   D
    Tree T2("T2");
    int nxA = T2.add_node("A");
    int nxX = T2.add_node("X", nxA);
    int nxY = T2.add_node("Y", nxA);
    int nxD = T2.add_node("D", nxX);

    std::cout << "\nTree T2:" << std::endl;
    T2.compute_traversals_and_metadata();
    std::cout << "Root: " << T2.get_node(T2.root_id)->label << ", Nodes: " << T2.nodes.size() << std::endl;

    // Solve the tree edit distance problem using Divide-and-Conquer (Constrained)
    std::cout << "\n--- Running Divide-and-Conquer (Leaves-Only Operations) Algorithm ---" << std::endl;
    
    std::pair<int, std::map<std::string, int>> result = divide_and_conquer_constrained_tree_edit_distance(T1, T2);
    int min_cost = result.first;

    std::cout << "\n--- Minimum Edit Distance Found (Divide-and-Conquer - Constrained) ---" << std::endl;
    std::cout << "Minimum Cost: " << min_cost << std::endl;
    std::cout << "Details (exact operation counts) not directly available from this implementation." << std::endl;

    return 0;
}