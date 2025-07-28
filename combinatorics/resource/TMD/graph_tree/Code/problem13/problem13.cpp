#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <algorithm>

// run with c++ 23
// A type alias for a general graph.
// The adjacency list can represent parallel edges (duplicate entries)
// and self-loops (an edge from a node to itself, e.g., adj[2].push_back(2)).
using Graph = std::vector<std::vector<int>>;

/**
 * @class DfsSolver
 * @brief Encapsulates the logic for Depth-First Search on various graph types.
 *
 * This class is robust enough to handle general graphs. The 'visited' check is
 * the key mechanism that correctly prevents infinite loops from self-loops and
 * redundant exploration via parallel edges.
 */
class DfsSolver {
public:
    int num_nodes;
    std::vector<int> parent;
    std::vector<bool> visited;
    std::vector<int> traversal_path;

    /**
     * @brief Constructs the DfsSolver.
     * @param n The total number of nodes in the graph.
     */
    DfsSolver(int n) : num_nodes(n) {}

    /**
     * @brief Public method to start the recursive DFS.
     * @param adj The general graph as an adjacency list.
     * @param start_node The node to start from.
     */
    void solve_recursive(const Graph& adj, int start_node) {
        parent.assign(num_nodes, -1);
        visited.assign(num_nodes, false);
        traversal_path.clear();

        if (start_node >= num_nodes) return;
        
        dfs_util(adj, start_node);
    }

private:
    /**
     * @brief Recursive helper function for DFS.
     *
     * This function works correctly on general graphs.
     * 1. Parallel Edges: When it encounters a neighbor 'v' via one parallel edge, it
     *    will recurse. When it later encounters 'v' via another parallel edge,
     *    the `!visited[v]` check will be false, and the path is ignored.
     * 2. Self-Loops (u,u): When processing 'u', it is immediately marked as 'visited'.
     *    When the loop checks the neighbor 'u', the `!visited[u]` check is false,
     *    preventing an infinite recursive call.
     *
     * @param adj The graph.
     * @param u The current node to visit.
     */
    void dfs_util(const Graph& adj, int u) {
        visited[u] = true;
        traversal_path.push_back(u);
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                dfs_util(adj, v);
            }
        }
    }
};

// =================================================================================
// MAIN FUNCTION - DEMONSTRATION FOR PROBLEM 13 (GENERAL GRAPH)
// =================================================================================
int main() {
    int num_nodes = 6;
    int start_node = 0; // v1

    std::map<int, std::string> node_names;
    for(int i = 0; i < num_nodes; ++i) {
        node_names[i] = "v" + std::to_string(i + 1);
    }
    
    // --- Graph Creation (General Graph) ---
    // This graph includes parallel edges and a self-loop.
    Graph adj(num_nodes);
    adj[0] = {1, 1, 3};          // v1 -> v2 (parallel edge), v4
    adj[1] = {0, 4};             // v2 -> v1, v5
    adj[2] = {0, 2, 5};          // v3 -> v1, v3 (self-loop), v6
    adj[3] = {0, 1, 4};          // v4 -> v1, v2, v5
    adj[4] = {1, 3};             // v5 -> v2, v4
    adj[5] = {2};                // v6 -> v3

    // --- Execution and Output ---
    DfsSolver solver(num_nodes);

    std::cout << "=====================================================" << std::endl;
    std::cout << "DFS Algorithm Report for General Graph (Problem 13)" << std::endl;
    std::cout << "Source Node: '" << node_names[start_node] << "'" << std::endl;
    std::cout << "=====================================================" << std::endl;
    
    // --- Run and Print Recursive Version ---
    solver.solve_recursive(adj, start_node);
    std::cout << "\n--- Recursive DFS ---" << std::endl;
    std::cout << "  Traversal Path: ";
    for(size_t i = 0; i < solver.traversal_path.size(); ++i) {
        std::cout << node_names[solver.traversal_path[i]] << (i == solver.traversal_path.size() - 1 ? "" : " -> ");
    }
    std::cout << "\n  Parent of v6: " 
              << (solver.parent[5] != -1 ? node_names[solver.parent[5]] : "N/A") 
              << std::endl;

    std::cout << "\n=====================================================" << std::endl;

    return 0;
}