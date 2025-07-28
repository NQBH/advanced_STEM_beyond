#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

// run with c++ 23
// A type alias for graph representation for better readability.
// We use an adjacency list for a simple graph.
using Graph = std::vector<std::vector<int>>;

/**
 * @class DfsSolver
 * @brief Encapsulates the logic and results of a Depth-First Search.
 *
 * This class provides both recursive and iterative implementations of DFS.
 * It stores results like parent pointers and the traversal path, which are
 * reset for each new run.
 */
class DfsSolver {
public:
    int num_nodes;
    std::vector<int> parent;         // Stores the predecessor in the DFS tree.
    std::vector<bool> visited;       // Tracks visited nodes.
    std::vector<int> traversal_path; // Records the order of visiting nodes.

    /**
     * @brief Constructs the DfsSolver.
     * @param n The total number of nodes in the graph.
     */
    DfsSolver(int n) : num_nodes(n) {}

    /**
     * @brief Public method to start the recursive DFS.
     *
     * This function initializes the necessary data structures and kicks off
     * the recursive exploration process from the start_node.
     *
     * @param adj The graph as an adjacency list.
     * @param start_node The node to start from.
     */
    void solve_recursive(const Graph& adj, int start_node) {
        // Initialization for a new run
        parent.assign(num_nodes, -1);
        visited.assign(num_nodes, false);
        traversal_path.clear();

        if (start_node >= num_nodes) {
            std::cerr << "Error: Start node is out of bounds." << std::endl;
            return;
        }
        
        // Start the recursive traversal
        dfs_util(adj, start_node);
    }
    
    /**
     * @brief Public method for the iterative DFS.
     *
     * This function uses an explicit stack to mimic the behavior of the
     * recursive call stack, exploring the graph in a depth-first manner.
     *
     * @param adj The graph as an adjacency list.
     * @param start_node The node to start from.
     */
    void solve_iterative(const Graph& adj, int start_node) {
        // Initialization for a new run
        parent.assign(num_nodes, -1);
        // `visited` is not a member here to show a different style
        std::vector<bool> local_visited(num_nodes, false); 
        traversal_path.clear();

        if (start_node >= num_nodes) {
            std::cerr << "Error: Start node is out of bounds." << std::endl;
            return;
        }
        
        // The explicit stack for the iterative DFS.
        std::stack<int> s;
        s.push(start_node);

        while (!s.empty()) {
            int u = s.top();
            s.pop();

            // Only process nodes that haven't been visited yet.
            if (!local_visited[u]) {
                local_visited[u] = true;
                traversal_path.push_back(u);

                // Push unvisited neighbors onto the stack.
                // We iterate in reverse to ensure that the first neighbor in the
                // adjacency list is the first one to be popped and visited.
                for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                    int v = *it;
                    if (!local_visited[v]) {
                        parent[v] = u; // Set parent before pushing
                        s.push(v);
                    }
                }
            }
        }
    }

private:
    /**
     * @brief Recursive utility function for DFS. This is the core of the recursive approach.
     *
     * This function embodies the recursive definition of DFS: visit a node, then
     * recursively visit each of its unvisited neighbors. The system's call stack
     * implicitly manages the "backtracking".
     *
     * @param adj The graph.
     * @param u The current node to visit.
     */
    void dfs_util(const Graph& adj, int u) {
        // 1. Base Action: Mark current node as visited and process it.
        visited[u] = true;
        traversal_path.push_back(u);

        // 2. Recursive Step: Recur for all unvisited adjacent vertices.
        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                dfs_util(adj, v);
            }
        }
        // Base Case: When this loop finishes, the function returns (backtracks).
    }
};

// =================================================================================
// MAIN FUNCTION - DEMONSTRATION FOR PROBLEM 11 (SIMPLE GRAPH)
// =================================================================================
int main() {
    int num_nodes = 7;
    int start_node = 0; // v1

    std::map<int, std::string> node_names;
    for(int i = 0; i < num_nodes; ++i) {
        node_names[i] = "v" + std::to_string(i + 1);
    }
    
    // --- Graph Creation (Simple Graph from Val21, Fig 1.1) ---
    Graph adj(num_nodes);
    adj[0] = {1, 3};
    adj[1] = {0, 4, 3};
    adj[2] = {0, 3, 5};
    adj[3] = {0, 1, 2, 4, 5, 6};
    adj[4] = {1, 3, 6};
    adj[5] = {2, 3, 6};
    adj[6] = {3, 4, 5};

    // --- Execution and Output ---
    DfsSolver solver(num_nodes);

    std::cout << "=====================================================" << std::endl;
    std::cout << "DFS Algorithm Report for Simple Graph (Problem 11)" << std::endl;
    std::cout << "Source Node: '" << node_names[start_node] << "'" << std::endl;
    std::cout << "=====================================================" << std::endl;
    
    // --- Run and Print Recursive Version ---
    solver.solve_recursive(adj, start_node);
    std::cout << "\n--- Recursive DFS ---" << std::endl;
    std::cout << "  Traversal Path: ";
    for(size_t i = 0; i < solver.traversal_path.size(); ++i) {
        std::cout << node_names[solver.traversal_path[i]] << (i == solver.traversal_path.size() - 1 ? "" : " -> ");
    }
    std::cout << "\n  Parent of v7: " 
              << (solver.parent[6] != -1 ? node_names[solver.parent[6]] : "N/A") 
              << std::endl;

    // --- Run and Print Iterative Version ---
    solver.solve_iterative(adj, start_node);
    std::cout << "\n--- Iterative DFS ---" << std::endl;
    std::cout << "  Traversal Path: ";
    for(size_t i = 0; i < solver.traversal_path.size(); ++i) {
        std::cout << node_names[solver.traversal_path[i]] << (i == solver.traversal_path.size() - 1 ? "" : " -> ");
    }
    std::cout << "\n  Parent of v7: " 
              << (solver.parent[6] != -1 ? node_names[solver.parent[6]] : "N/A") 
              << std::endl;

    std::cout << "\n=====================================================" << std::endl;

    return 0;
}