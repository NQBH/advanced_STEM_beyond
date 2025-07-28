#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm> // For std::remove
#include <limits>    // For std::numeric_limits

// --- Global Constants and Costs ---
const int LAMBDA_NODE = -1; // Represents a dummy node for deletion
const int DEL_COST = 1;     // Cost for deleting a node from T1
const int INS_COST = 1;     // Cost for inserting a node into T2
const int REP_COST = 1;     // Cost for relabeling

// Forward declarations
class Tree; // Declare Tree class before TreeNode uses it (though not strictly necessary here, good practice)

// Represents a node in the tree
struct TreeNode {
    int id;
    std::string label;
    int parent_id;
    std::vector<int> children_ids;
    int depth;
    int preorder_index;

    // Constructor
    TreeNode(int id, const std::string& label)
        : id(id), label(label), parent_id(LAMBDA_NODE), depth(-1), preorder_index(-1) {}

    // For printing (like Python's __repr__)
    friend std::ostream& operator<<(std::ostream& os, const TreeNode& node) {
        os << "Node(ID:" << node.id << ", Label:'" << node.label
           << "', Parent:" << (node.parent_id == LAMBDA_NODE ? "None" : std::to_string(node.parent_id))
           << ", Children:[";
        for (size_t i = 0; i < node.children_ids.size(); ++i) {
            os << node.children_ids[i] << (i == node.children_ids.size() - 1 ? "" : ", ");
        }
        os << "], Depth:" << node.depth << ", Preorder:" << node.preorder_index << ")";
        return os;
    }
};

// Represents an ordered tree
class Tree {
public:
    std::string name;
    std::map<int, TreeNode> nodes; // Dictionary to store nodes: {node_id: TreeNode_object}
    int root_id;

private:
    int _next_node_id; // Counter for assigning unique node IDs
    std::vector<int> _preorder_traversal_list; // Stores node IDs in preorder sequence

public:
    Tree(const std::string& name = "") : name(name), root_id(LAMBDA_NODE), _next_node_id(0) {}

    int add_node(const std::string& label, int parent_id = LAMBDA_NODE) {
        int node_id = _next_node_id++;
        nodes.emplace(node_id, TreeNode(node_id, label)); // Use emplace to construct in place

        if (parent_id != LAMBDA_NODE) {
            if (nodes.find(parent_id) == nodes.end()) {
                throw std::runtime_error("Parent with ID " + std::to_string(parent_id) + " does not exist in tree '" + name + "'.");
            }
            nodes.at(parent_id).children_ids.push_back(node_id);
            nodes.at(node_id).parent_id = parent_id;
        } else if (root_id == LAMBDA_NODE) {
            root_id = node_id;
        } else {
            throw std::runtime_error("Tree '" + name + "' already has a root. New nodes without parent must be the root.");
        }
        return node_id;
    }

    // Retrieves a node by its ID. Returns nullptr if not found.
    TreeNode* get_node(int node_id) {
        auto it = nodes.find(node_id);
        if (it != nodes.end()) {
            return &(it->second);
        }
        return nullptr;
    }

    // Returns a vector of TreeNode pointers that are children of the given node_id.
    std::vector<TreeNode*> get_children(int node_id) {
        std::vector<TreeNode*> children;
        TreeNode* node = get_node(node_id);
        if (node) {
            for (int child_id : node->children_ids) {
                children.push_back(get_node(child_id));
            }
        }
        return children;
    }

    // Returns the TreeNode pointer that is the parent of the given node_id.
    TreeNode* get_parent(int node_id) {
        TreeNode* node = get_node(node_id);
        if (node && node->parent_id != LAMBDA_NODE) {
            return get_node(node->parent_id);
        }
        return nullptr;
    }

    // Helper for computing preorder indices and depths using DFS.
    int _dfs_preorder_and_depth(int node_id, int current_depth, int current_preorder_index) {
        TreeNode* node = get_node(node_id);
        if (!node) {
            return current_preorder_index;
        }

        node->depth = current_depth;
        node->preorder_index = current_preorder_index;
        _preorder_traversal_list.push_back(node_id);
        current_preorder_index++;

        for (int child_id : node->children_ids) {
            current_preorder_index = _dfs_preorder_and_depth(child_id, current_depth + 1, current_preorder_index);
        }
        return current_preorder_index;
    }

    // Computes and assigns preorder indices and depths for all nodes in the tree.
    void compute_preorder_and_depth() {
        if (root_id == LAMBDA_NODE) {
            return;
        }
        _preorder_traversal_list.clear();
        _dfs_preorder_and_depth(root_id, 0, 0);
    }

    // Returns a vector of TreeNode pointers in preorder traversal order.
    std::vector<TreeNode*> get_preorder_nodes() {
        std::vector<TreeNode*> preorder_nodes;
        for (int node_id : _preorder_traversal_list) {
            preorder_nodes.push_back(get_node(node_id));
        }
        return preorder_nodes;
    }
};

// --- Solution Struct to store results ---
struct Solution {
    std::map<int, int> mapping;
    int cost;
    std::map<std::string, int> details; // Stores deletions, insertions, relabelings
};

// --- Tree Edit Distance Backtracking Algorithm Functions ---

std::pair<int, std::map<std::string, int>> calculate_edit_distance(Tree& T1, Tree& T2, const std::map<int, int>& M) {
    int cost = 0;
    int num_deletions = 0;
    int num_insertions = 0;
    int num_relabelings = 0;

    // Deletions: nodes in T1 mapped to LAMBDA_NODE
    for (const auto& pair : M) {
        int v_id = pair.first;
        int w_map = pair.second;
        if (w_map == LAMBDA_NODE) {
            num_deletions++;
        }
    }
    cost += num_deletions * DEL_COST;

    // Insertions: nodes in T2 that were not mapped from T1
    std::set<int> mapped_nodes_T2_ids;
    for (const auto& pair : M) {
        int w_map = pair.second;
        if (w_map != LAMBDA_NODE) {
            mapped_nodes_T2_ids.insert(w_map);
        }
    }

    std::set<int> all_nodes_T2_ids;
    for (const auto& pair : T2.nodes) {
        all_nodes_T2_ids.insert(pair.first);
    }
    
    // Filter out any potential invalid IDs from mapped_nodes_T2_ids for insertion count
    std::set<int> valid_mapped_nodes_T2_ids;
    for (int w_id : mapped_nodes_T2_ids) {
        if (T2.get_node(w_id) != nullptr) {
            valid_mapped_nodes_T2_ids.insert(w_id);
        }
    }

    num_insertions = all_nodes_T2_ids.size() - valid_mapped_nodes_T2_ids.size();
    cost += num_insertions * INS_COST;

    // Relabelings (replacements with different labels):
    for (const auto& pair : M) {
        int v_id = pair.first;
        int w_map = pair.second;
        if (w_map != LAMBDA_NODE) {
            TreeNode* node_v = T1.get_node(v_id);
            TreeNode* node_w = T2.get_node(w_map);
            
            // Defensive check: Ensure both nodes exist before comparing labels.
            if (node_v == nullptr || node_w == nullptr) {
                continue;
            }

            if (node_v->label != node_w->label) {
                num_relabelings++;
            }
        }
    }
    cost += num_relabelings * REP_COST;

    std::map<std::string, int> details;
    details["deletions"] = num_deletions;
    details["insertions"] = num_insertions;
    details["relabelings"] = num_relabelings;

    return {cost, details};
}

std::map<int, std::vector<int>> set_up_candidate_nodes(Tree& T1, Tree& T2) {
    std::map<int, std::vector<int>> C;
    // Group T2 nodes by depth for efficient lookup
    std::map<int, std::vector<int>> t2_nodes_by_depth;
    for (const auto& pair : T2.nodes) {
        t2_nodes_by_depth[pair.second.depth].push_back(pair.first);
    }

    // For each node v in T1, populate its candidate list
    for (TreeNode* v_node : T1.get_preorder_nodes()) {
        std::vector<int> candidates = {LAMBDA_NODE}; // Always a candidate for deletion
        if (t2_nodes_by_depth.count(v_node->depth)) {
            // Add nodes from T2 with the same depth as v
            candidates.insert(candidates.end(), t2_nodes_by_depth[v_node->depth].begin(), t2_nodes_by_depth[v_node->depth].end());
        }
        C[v_node->id] = candidates;
    }
    return C;
}

void refine_candidate_nodes(Tree& T1, Tree& T2, std::map<int, std::vector<int>>& C_copy, int v_id, int w_id) {
    // Constraint 1: Bijection - If w is a non-dummy node, it cannot be mapped by any other T1 node.
    if (w_id != LAMBDA_NODE) {
        // Remove w_id from candidate lists of all nodes in T1 that appear after v_id in preorder
        TreeNode* v_node_t1 = T1.get_node(v_id);
        if (!v_node_t1) return; // Should not happen if v_id is valid

        for (TreeNode* x_node : T1.get_preorder_nodes()) {
            if (x_node->preorder_index > v_node_t1->preorder_index) {
                if (C_copy.count(x_node->id)) {
                    auto& candidates = C_copy.at(x_node->id);
                    candidates.erase(std::remove(candidates.begin(), candidates.end(), w_id), candidates.end());
                }
            }
        }
    }

    // Constraint 2: Parent-Child Preservation
    // If v maps to w (non-dummy), children of v must map to children of w (or LAMBDA_NODE).
    for (TreeNode* x_child_node : T1.get_children(v_id)) {
        if (C_copy.count(x_child_node->id)) {
            std::vector<int>& candidates_for_x = C_copy.at(x_child_node->id);
            std::vector<int> new_candidates_for_x;
            for (int y_candidate_id : candidates_for_x) {
                if (y_candidate_id == LAMBDA_NODE) {
                    new_candidates_for_x.push_back(LAMBDA_NODE);
                } else { // y_candidate_id is supposed to be a T2 node ID
                    TreeNode* node_y_in_T2 = T2.get_node(y_candidate_id);
                    // Defensive check: if node_y_in_T2 is nullptr, it's an invalid ID, skip.
                    if (node_y_in_T2 == nullptr) {
                        continue;
                    }
                    
                    if (w_id != LAMBDA_NODE) { // Constraint applies only if w is a real node
                        if (node_y_in_T2->parent_id == w_id) {
                            new_candidates_for_x.push_back(y_candidate_id);
                        }
                    } else { // If w_id is LAMBDA_NODE, no parent-child constraint from (v,w) is imposed on children
                        new_candidates_for_x.push_back(y_candidate_id);
                    }
                }
            }
            C_copy[x_child_node->id] = new_candidates_for_x; // Assign the filtered list back
        }
    }

    // Constraint 3: Sibling Order Preservation
    // If v maps to w (non-dummy), any right sibling x of v must map to a right sibling y of w (or LAMBDA_NODE).
    TreeNode* v_node = T1.get_node(v_id);
    if (!v_node) return; // Should not happen if v_id is valid

    if (v_node->parent_id != LAMBDA_NODE && w_id != LAMBDA_NODE) { // v is not root of T1, and w is not dummy
        TreeNode* parent_v_node = T1.get_node(v_node->parent_id);
        if (!parent_v_node) return; // Should not happen

        // Identify right siblings of v in T1 based on preorder index
        int v_preorder_index = v_node->preorder_index;
        std::vector<int> right_siblings_of_v_ids;
        for (int child_id : parent_v_node->children_ids) {
            TreeNode* child_node = T1.get_node(child_id);
            if (child_node && child_node->preorder_index > v_preorder_index) {
                right_siblings_of_v_ids.push_back(child_id);
            }
        }
        
        TreeNode* w_node_t2 = T2.get_node(w_id);
        if (!w_node_t2) return; // Should not happen if w_id is valid and not LAMBDA_NODE
        int w_preorder_index = w_node_t2->preorder_index;

        for (int x_right_sibling_id : right_siblings_of_v_ids) {
            if (C_copy.count(x_right_sibling_id)) {
                std::vector<int>& candidates_for_x = C_copy.at(x_right_sibling_id);
                std::vector<int> new_candidates_for_x;
                for (int y_candidate_id : candidates_for_x) {
                    if (y_candidate_id == LAMBDA_NODE) {
                        new_candidates_for_x.push_back(LAMBDA_NODE);
                    } else {
                        TreeNode* node_y_in_T2 = T2.get_node(y_candidate_id);
                        if (node_y_in_T2 == nullptr) {
                            continue; // Skip invalid T2 node ID in candidates
                        }
                        
                        // y must be a right sibling of w (i.e., its preorder index must be greater than w's)
                        // and have the same parent as w
                        if (node_y_in_T2->preorder_index > w_preorder_index && node_y_in_T2->parent_id == w_node_t2->parent_id) {
                            new_candidates_for_x.push_back(y_candidate_id);
                        }
                    }
                }
                C_copy[x_right_sibling_id] = new_candidates_for_x; // Assign the filtered list back
            }
        }
    }
}

void extend_tree_edit(Tree& T1, Tree& T2, 
                      std::map<int, int>& M_current, // Current partial mapping
                      std::vector<Solution>& L_solutions, // List to store complete solutions
                      std::map<int, std::vector<int>> C_current, // Candidate set (passed by value for deep copy)
                      int current_v_idx) { // Index of the T1 node to map next

    std::vector<TreeNode*> t1_preorder_nodes = T1.get_preorder_nodes();

    if (current_v_idx == t1_preorder_nodes.size()) {
        // Base case: All nodes from T1 have been mapped, a complete valid transformation is found.
        Solution current_solution;
        current_solution.mapping = M_current; // std::map copy constructor performs deep copy
        
        auto cost_details = calculate_edit_distance(T1, T2, current_solution.mapping);
        current_solution.cost = cost_details.first;
        current_solution.details = cost_details.second;
        
        L_solutions.push_back(current_solution);
        return;
    }

    TreeNode* v_node_to_map = t1_preorder_nodes[current_v_idx];
    int v_id = v_node_to_map->id;

    // Iterate through possible mappings (candidates) for the current T1 node (v_id)
    if (C_current.count(v_id)) { // Check if v_id still has candidates after pruning
        for (int w_id_candidate : C_current.at(v_id)) {
            M_current[v_id] = w_id_candidate; // Assign v_id to w_id_candidate

            // Create a deep copy of the candidate set C for the next recursive call.
            // This is done implicitly by passing C_current by value to the next call.
            
            // Refine the candidate set for subsequent nodes based on this new assignment
            std::map<int, std::vector<int>> C_next = C_current; // Explicit copy for modification
            refine_candidate_nodes(T1, T2, C_next, v_id, w_id_candidate);

            // Recursive call: proceed to map the next node in T1's preorder traversal
            extend_tree_edit(T1, T2, M_current, L_solutions, C_next, current_v_idx + 1);
            
            // Backtrack: M_current[v_id] will be overwritten by the next iteration,
            // or implicitly removed if this branch finishes.
        }
    }
}

std::vector<Solution> backtracking_tree_edit(Tree& T1, Tree& T2) {
    // Pre-process trees to compute depths and preorder indices
    T1.compute_preorder_and_depth();
    T2.compute_preorder_and_depth();

    std::map<int, int> M; // Current partial mapping {T1_node_id: T2_node_id or LAMBDA_NODE}
    std::vector<Solution> L; // List to store all complete valid transformations

    // Initialize the candidate set for all nodes in T1
    std::map<int, std::vector<int>> C = set_up_candidate_nodes(T1, T2);

    // Start the recursive backtracking process from the first node of T1 (index 0 in preorder list)
    extend_tree_edit(T1, T2, M, L, C, 0);

    return L;
}

// --- Main Example Usage ---
int main() {
    std::cout << "--- Example Tree Edit Distance Problem (Backtracking) ---" << std::endl;

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
    T1.compute_preorder_and_depth();
    for (TreeNode* node : T1.get_preorder_nodes()) {
        std::cout << *node << std::endl;
    }

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
    T2.compute_preorder_and_depth();
    for (TreeNode* node : T2.get_preorder_nodes()) {
        std::cout << *node << std::endl;
    }

    // Solve the tree edit distance problem using backtracking
    std::cout << "\n--- Running Backtracking Algorithm ---" << std::endl;
    std::vector<Solution> solutions = backtracking_tree_edit(T1, T2);

    std::cout << "\nFound " << solutions.size() << " valid transformation(s):" << std::endl;
    if (!solutions.empty()) {
        int min_cost = std::numeric_limits<int>::max();
        Solution min_cost_solution;
        
        for (size_t i = 0; i < solutions.size(); ++i) {
            const Solution& sol = solutions[i];

            std::cout << "\nSolution " << i + 1 << ": Cost = " << sol.cost
                      << " (Deletions: " << sol.details.at("deletions")
                      << ", Insertions: " << sol.details.at("insertions")
                      << ", Relabelings: " << sol.details.at("relabelings") << ")" << std::endl;
            std::cout << "  Mapping (T1_ID -> T2_ID or lambda):" << std::endl;
            for (const auto& pair : sol.mapping) {
                int t1_id = pair.first;
                int t2_mapped_id = pair.second;
                TreeNode* t1_node = T1.get_node(t1_id);

                std::string t2_node_str;
                std::string t2_node_id_str;

                if (t2_mapped_id != LAMBDA_NODE) {
                    TreeNode* node_w_for_print = T2.get_node(t2_mapped_id);
                    if (node_w_for_print) {
                        t2_node_str = node_w_for_print->label;
                        t2_node_id_str = std::to_string(t2_mapped_id);
                    } else {
                        t2_node_str = "INVALID_NODE_ID";
                        t2_node_id_str = std::to_string(t2_mapped_id);
                    }
                } else {
                    t2_node_str = "λ";
                    t2_node_id_str = "λ";
                }
                std::cout << "    " << t1_node->label << "(ID:" << t1_id << ") -> "
                          << t2_node_str << "(ID:" << t2_node_id_str << ")" << std::endl;
            }
            
            if (sol.cost < min_cost) {
                min_cost = sol.cost;
                min_cost_solution = sol;
            }
        }
        
        std::cout << "\n--- Minimum Edit Distance Found ---" << std::endl;
        std::cout << "Minimum Cost: " << min_cost_solution.cost << std::endl;
        std::cout << "Details: Deletions: " << min_cost_solution.details.at("deletions")
                  << ", Insertions: " << min_cost_solution.details.at("insertions")
                  << ", Relabelings: " << min_cost_solution.details.at("relabelings") << std::endl;
        std::cout << "Mapping:" << std::endl;
        for (const auto& pair : min_cost_solution.mapping) {
            int t1_id = pair.first;
            int t2_mapped_id = pair.second;
            TreeNode* t1_node = T1.get_node(t1_id);

            std::string t2_node_str;
            std::string t2_node_id_str;

            if (t2_mapped_id != LAMBDA_NODE) {
                TreeNode* node_w_for_print = T2.get_node(t2_mapped_id);
                if (node_w_for_print) {
                    t2_node_str = node_w_for_print->label;
                    t2_node_id_str = std::to_string(t2_mapped_id);
                } else {
                    t2_node_str = "INVALID_NODE_ID";
                    t2_node_id_str = std::to_string(t2_mapped_id);
                }
            } else {
                t2_node_str = "λ";
                t2_node_id_str = "λ";
            }
            std::cout << "    " << t1_node->label << "(ID:" << t1_id << ") -> "
                      << t2_node_str << "(ID:" << t2_node_id_str << ")" << std::endl;
        }
    } else {
        std::cout << "No valid transformations found." << std::endl;
    }

    return 0;
}