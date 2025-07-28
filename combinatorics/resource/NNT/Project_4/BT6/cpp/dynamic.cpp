#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm> // For std::min

// Define a global placeholder for lambda_node (representing a deleted node)
const std::string lambda_node = "λ";

class Node {
public:
    std::string label;
    int node_id;
    int parent_id; // -1 if no parent
    std::vector<int> children_ids;
    int depth; // Will be computed
    int preorder_index; // Will be computed

    Node(std::string label, int node_id, int parent_id = -1)
        : label(std::move(label)), node_id(node_id), parent_id(parent_id), depth(-1), preorder_index(-1) {}

    // Method to print Node information, similar to Python's __repr__
    friend std::ostream& operator<<(std::ostream& os, const Node& node) {
        os << "Node(ID:" << node.node_id
           << ", Label:" << node.label
           << ", Parent:" << (node.parent_id != -1 ? std::to_string(node.parent_id) : "None")
           << ", Depth:" << node.depth << ")";
        return os;
    }
};

class Tree {
public:
    std::string name;
    std::map<int, Node> nodes; // Map node_id to Node object
    int root_id; // Stores the ID of the root node
    int _next_node_id;
    std::vector<Node*> _preorder_nodes; // To store pointers to nodes in preorder traversal

    Tree(std::string name)
        : name(std::move(name)), root_id(-1), _next_node_id(0) {}

    // Prevent copying of Tree objects to manage Node pointers simply.
    // Or, implement deep copy if necessary. For this problem, passing by reference is fine.
    Tree(const Tree&) = delete; 
    Tree& operator=(const Tree&) = delete;

    // Destructor to clean up Node pointers if _preorder_nodes stored new Node*
    // However, nodes are stored by value in `nodes` map, so no explicit delete for Node* in this case.
    // _preorder_nodes stores pointers to elements *within* the map, which are valid until map is destroyed.
    ~Tree() {
        // No explicit memory management needed for Node* in _preorder_nodes
        // as they point to elements owned by `nodes` map.
    }

    int add_node(const std::string& label, int parent_id = -1) {
        int node_id = _next_node_id++;
        nodes.emplace(node_id, Node(label, node_id, parent_id)); // Insert by constructing in place

        if (parent_id == -1) {
            if (root_id != -1) {
                // Handle cases where multiple roots might be added, though typically a tree has one root
            }
            root_id = node_id;
        } else {
            auto it = nodes.find(parent_id);
            if (it != nodes.end()) {
                it->second.children_ids.push_back(node_id);
            }
        }
        return node_id;
    }

    Node* get_node(int node_id) {
        auto it = nodes.find(node_id);
        if (it != nodes.end()) {
            return &(it->second); // Return pointer to the Node object
        }
        return nullptr; // Node not found
    }

    void compute_preorder_and_depth() {
        _preorder_nodes.clear();
        if (root_id == -1) {
            return;
        }

        std::vector<std::pair<int, int>> traversal_stack; // (node_id, depth)
        traversal_stack.push_back({root_id, 0});
        
        int preorder_counter = 0;

        while (!traversal_stack.empty()) {
            std::pair<int, int> current_pair = traversal_stack.back();
            traversal_stack.pop_back();

            int current_node_id = current_pair.first;
            int current_depth = current_pair.second;

            Node* current_node = get_node(current_node_id);
            if (current_node) {
                current_node->depth = current_depth;
                current_node->preorder_index = preorder_counter++;
                _preorder_nodes.push_back(current_node);

                // Push children onto stack in reverse order to ensure left-to-right processing
                // assuming children_ids are already stored in left-to-right order
                for (auto it = current_node->children_ids.rbegin(); it != current_node->children_ids.rend(); ++it) {
                    traversal_stack.push_back({*it, current_depth + 1});
                }
            }
        }
        
        // Sort _preorder_nodes by preorder_index to ensure correct order
        std::sort(_preorder_nodes.begin(), _preorder_nodes.end(), 
                  [](Node* a, Node* b) {
                      return a->preorder_index < b->preorder_index;
                  });
    }

    const std::vector<Node*>& get_preorder_nodes() const {
        return _preorder_nodes;
    }
};

// --- Dynamic Programming Algorithm for Tree Edit Distance ---
// This uses a recursive approach with memoization for simplicity.
// A full, optimized Zhang-Shasha algorithm is more extensive.
// Costs are: 1 for deletion, 1 for insertion, 1 for relabeling (0 if same).

// Memoization table: map from (node1_id, node2_id) pair to calculated cost
std::map<std::pair<int, int>, int> memo;

// Helper recursive function to calculate the edit distance between two subtrees
int calculate_distance_recursive(Tree& T1, Tree& T2, int n1_id, int n2_id) {
    // Check memoization table
    std::pair<int, int> current_key = {n1_id, n2_id};
    if (memo.count(current_key)) {
        return memo[current_key];
    }

    Node* node1 = T1.get_node(n1_id);
    Node* node2 = T2.get_node(n2_id);

    // Base Cases:
    if (node1 == nullptr && node2 == nullptr) {
        return 0; // Both subtrees are empty, no cost
    }

    if (node1 == nullptr) {
        // Subtree 1 is empty, cost is to insert all nodes in subtree 2
        int cost = 0;
        std::queue<int> q;
        q.push(n2_id);
        std::map<int, bool> visited; // Use map as a set
        visited[n2_id] = true;

        while (!q.empty()) {
            int curr_id = q.front();
            q.pop();
            cost += 1; // Cost for inserting this node
            
            Node* curr_node = T2.get_node(curr_id);
            if (curr_node) {
                for (int child_id : curr_node->children_ids) {
                    if (!visited[child_id]) {
                        visited[child_id] = true;
                        q.push(child_id);
                    }
                }
            }
        }
        memo[current_key] = cost;
        return cost;
    }
    
    if (node2 == nullptr) {
        // Subtree 2 is empty, cost is to delete all nodes in subtree 1
        int cost = 0;
        std::queue<int> q;
        q.push(n1_id);
        std::map<int, bool> visited; // Use map as a set
        visited[n1_id] = true;

        while (!q.empty()) {
            int curr_id = q.front();
            q.pop();
            cost += 1; // Cost for deleting this node
            
            Node* curr_node = T1.get_node(curr_id);
            if (curr_node) {
                for (int child_id : curr_node->children_ids) {
                    if (!visited[child_id]) {
                        visited[child_id] = true;
                        q.push(child_id);
                    }
                }
            }
        }
        memo[current_key] = cost;
        return cost;
    }

    // Main Recursive Step: Calculate minimum of operations
    
    // 1. Relabel/Match operation: Relabel current roots (cost 0 if same, 1 if different)
    //    Then, recursively find the edit distance between their children's forests.
    int relabel_cost = (node1->label == node2->label) ? 0 : 1;

    const std::vector<int>& children1_ids = node1->children_ids;
    const std::vector<int>& children2_ids = node2->children_ids;

    // Calculate Forest Edit Distance (FED) between children sequences (another DP subproblem)
    int m = children1_ids.size();
    int k = children2_ids.size();
    
    // dp_forest[i][j] for first i children of T1, first j of T2
    std::vector<std::vector<int>> dp_forest(m + 1, std::vector<int>(k + 1, 0));
    
    // Base cases for forest DP: cost to delete/insert remaining children in the forest
    for (int x = 1; x <= m; ++x) {
        dp_forest[x][0] = dp_forest[x-1][0] + calculate_distance_recursive(T1, T2, children1_ids[x-1], -1); // Deleting subtree
    }
    for (int y = 1; y <= k; ++y) {
        dp_forest[0][y] = dp_forest[0][y-1] + calculate_distance_recursive(T1, T2, -1, children2_ids[y-1]); // Inserting subtree
    }

    // Fill the forest DP table
    for (int x = 1; x <= m; ++x) {
        for (int y = 1; y <= k; ++y) {
            int child1_id = children1_ids[x-1];
            int child2_id = children2_ids[y-1];
            
            // Option A: Match/Relabel current children (recursive TED call)
            int cost_match_children = calculate_distance_recursive(T1, T2, child1_id, child2_id);
            
            dp_forest[x][y] = std::min({
                dp_forest[x-1][y] + calculate_distance_recursive(T1, T2, child1_id, -1), // Option B: Delete child1's subtree
                dp_forest[x][y-1] + calculate_distance_recursive(T1, T2, -1, child2_id), // Option C: Insert child2's subtree
                dp_forest[x-1][y-1] + cost_match_children // Option A: Match/Relabel child1 to child2
            });
        }
    }
    
    // Total cost for the "relabel/match roots" option
    int cost_match_current_roots = relabel_cost + dp_forest[m][k];
    
    // Store result in memoization table and return
    memo[current_key] = cost_match_current_roots;
    return cost_match_current_roots;
}

// Main function to initiate the Tree Edit Distance calculation
int tree_edit_distance_dp(Tree& T1, Tree& T2) {
    memo.clear(); // Clear memoization table for a new calculation
    
    if (T1.root_id == -1 && T2.root_id == -1) {
        return 0;
    } else if (T1.root_id == -1) {
        return calculate_distance_recursive(T1, T2, -1, T2.root_id);
    } else if (T2.root_id == -1) {
        return calculate_distance_recursive(T1, T2, T1.root_id, -1);
    } else {
        return calculate_distance_recursive(T1, T2, T1.root_id, T2.root_id);
    }
}


// --- Main Example Usage ---
int main() {
    std::cout << "--- Example Tree Edit Distance Problem (Dynamic Programming) ---" << std::endl;

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
    for (Node* node : T1.get_preorder_nodes()) {
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
    for (Node* node : T2.get_preorder_nodes()) {
        std::cout << *node << std::endl;
    }

    // Solve the tree edit distance problem using dynamic programming
    std::cout << "\n--- Running Dynamic Programming Algorithm ---" << std::endl;
    
    int min_cost = tree_edit_distance_dp(T1, T2);

    std::cout << "\n--- Minimum Edit Distance Found ---" << std::endl;
    std::cout << "Minimum Cost: " << min_cost << std::endl;

    return 0;
}