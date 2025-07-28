#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>
#include <string>
#include <algorithm>
#include <functional>


// run with c++ 23
// A type alias for a multigraph.
// The adjacency list std::vector<std::vector<int>> can naturally represent
// parallel edges by storing duplicate entries for the same neighbor.
using Graph = std::vector<std::vector<int>>;

/**
 * @class BfsSolver
 * @brief Encapsulates the logic and results of a Breadth-First Search.
 *
 * This class is designed to run BFS on graphs that can be simple, multi, or general.
 * The core logic remains the same as the 'visited' check correctly handles
 * parallel edges and self-loops.
 */
class BfsSolver {
public:
    int num_nodes;
    std::vector<int> distance;
    std::vector<int> parent;

    /**
     * @brief Constructs the BfsSolver.
     * @param n The total number of nodes in the graph.
     */
    BfsSolver(int n) : num_nodes(n) {
        distance.resize(n, std::numeric_limits<int>::max());
        parent.resize(n, -1);
    }

    /**
     * @brief Executes the Breadth-First Search algorithm.
     *
     * This function works correctly on multigraphs because the 'visited' array
     * ensures that once a node is reached via one of the parallel edges,
     * it won't be processed again through another parallel edge.
     *
     * @param adj The multigraph, represented as an adjacency list.
     * @param start_node The node from which to start the search.
     */
    void solve(const Graph& adj, int start_node) {
        std::queue<int> q;
        std::vector<bool> visited(num_nodes, false);

        if (start_node >= num_nodes) {
            std::cerr << "Error: Start node is out of bounds." << std::endl;
            return;
        }
        
        distance[start_node] = 0;
        visited[start_node] = true;
        q.push(start_node);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // Iterate through all neighbors, including duplicates from parallel edges.
            for (int v : adj[u]) {
                // The 'if (!visited[v])' check is the key. It ensures we only process
                // a neighbor the first time we see it, regardless of how many edges lead to it.
                if (!visited[v]) {
                    visited[v] = true;
                    distance[v] = distance[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
    }
};

/**
 * @brief Helper function to reconstruct and print the shortest path.
 */
void print_path(int start_node, int end_node, const std::vector<int>& parent_map, const std::map<int, std::string>& node_names) {
    if (parent_map[end_node] == -1 && end_node != start_node) {
        std::cout << "No path exists.";
        return;
    }
    std::vector<int> path;
    for (int at = end_node; at != -1; at = parent_map[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << node_names.at(path[i]) << (i == path.size() - 1 ? "" : " -> ");
    }
}

// =================================================================================
// MAIN FUNCTION - DEMONSTRATION FOR PROBLEM 9 (MULTIGRAPH)
// =================================================================================
int main() {
    int num_nodes = 7;
    int start_node = 0; // v1

    std::map<int, std::string> node_names = {
        {0, "v1"}, {1, "v2"}, {2, "v3"}, {3, "v4"}, 
        {4, "v5"}, {5, "v6"}, {6, "v7"}
    };

    // --- Graph Creation for a Multigraph ---
    // Parallel edges are represented by adding the same neighbor multiple times.
    Graph adj(num_nodes);
    adj[0] = {1, 1, 3};          // v1 -> v2 (twice), v4
    adj[1] = {0, 0, 4, 3};       // v2 -> v1 (twice), v5, v4
    adj[2] = {0, 3, 5};
    adj[3] = {0, 1, 2, 4, 5, 6, 6}; // v4 -> v7 (twice)
    adj[4] = {1, 3, 6};
    adj[5] = {2, 3, 6};
    adj[6] = {3, 4, 5, 3};       // v7 -> v4 (twice)

    // --- Execution and Output ---
    
    BfsSolver solver(num_nodes);
    solver.solve(adj, start_node);

    std::cout << "=====================================================" << std::endl;
    std::cout << "BFS Algorithm Report for Multigraph (Problem 9)" << std::endl;
    std::cout << "Source Node: '" << node_names[start_node] << "'" << std::endl;
    std::cout << "=====================================================" << std::endl;

    for (int i = 0; i < num_nodes; ++i) {
        std::cout << "\n--- Destination: '" << node_names[i] << "' ---" << std::endl;
        std::cout << "  Shortest Distance: ";
        if (solver.distance[i] == std::numeric_limits<int>::max()) {
            std::cout << "UNREACHABLE" << std::endl;
        } else {
            std::cout << solver.distance[i] << std::endl;
            std::cout << "  Path: ";
            print_path(start_node, i, solver.parent, node_names);
            std::cout << std::endl;
        }
    }
    std::cout << "=====================================================" << std::endl;

    return 0;
}