#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>
#include <string>
#include <algorithm>
#include <functional>


// run with c++ 23
// A type alias for a general graph.
// The adjacency list can represent parallel edges (duplicate entries)
// and self-loops (an edge from a node to itself, e.g., adj[2].push_back(2)).
using Graph = std::vector<std::vector<int>>;

/**
 * @class BfsSolver
 * @brief Encapsulates the logic and results of a Breadth-First Search.
 *
 * This class is robust enough to run on general graphs. The core logic of using
 * a 'visited' array correctly handles parallel edges and self-loops without
 * any modification.
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
     * This function works correctly on general graphs because:
     * 1. Self-loops (u,u): When processing node 'u', it's already marked as
     *    'visited', so the edge to itself is ignored.
     * 2. Parallel edges: The 'visited' check ensures that once a node 'v' is
     *    reached, it won't be processed again via another parallel edge.
     *
     * @param adj The general graph, represented as an adjacency list.
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

            for (int v : adj[u]) {
                // This single condition correctly handles all cases.
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
// MAIN FUNCTION - DEMONSTRATION FOR PROBLEM 10 (GENERAL GRAPH)
// =================================================================================
int main() {
    int num_nodes = 6;
    int start_node = 0; // v1

    std::map<int, std::string> node_names = {
        {0, "v1"}, {1, "v2"}, {2, "v3"}, {3, "v4"}, {4, "v5"}, {5, "v6"}
    };

    // --- Graph Creation for a General Graph ---
    // This graph includes parallel edges and a self-loop.
    Graph adj(num_nodes);
    adj[0] = {1, 1, 3};          // v1 -> v2 (parallel edge), v4
    adj[1] = {0, 4};             // v2 -> v1, v5
    adj[2] = {0, 2, 5};          // v3 -> v1, v3 (self-loop), v6
    adj[3] = {0, 1, 4};          // v4 -> v1, v2, v5
    adj[4] = {1, 3};             // v5 -> v2, v4
    adj[5] = {2};                // v6 -> v3

    // --- Execution and Output ---
    
    BfsSolver solver(num_nodes);
    solver.solve(adj, start_node);

    std::cout << "=====================================================" << std::endl;
    std::cout << "BFS Algorithm Report for General Graph (Problem 10)" << std::endl;
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