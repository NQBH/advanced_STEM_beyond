#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>
#include <string>


// run with C++ 23
// A type alias for graph representation for better readability.
// We use an adjacency list, where each index represents a node,
// and the vector at that index stores its neighbors.
using Graph = std::vector<std::vector<int>>;

/**
 * @class BfsSolver
 * @brief Encapsulates the logic and results of a Breadth-First Search.
 *
 * This class is designed to run BFS on a given graph from a specified start node.
 * It stores the results, such as distances and parent pointers for path reconstruction,
 * as public members for easy access after the search is complete.
 */
class BfsSolver {
public:
    int num_nodes;
    std::vector<int> distance; // Stores shortest distance (in # of edges) from the source.
    std::vector<int> parent;   // Stores the predecessor of each node in the shortest path tree.

    /**
     * @brief Constructs the BfsSolver.
     * @param n The total number of nodes in the graph.
     */
    BfsSolver(int n) : num_nodes(n) {
        // Initialize distance for all nodes to infinity (or a large number).
        distance.resize(n, std::numeric_limits<int>::max());
        // Initialize parent for all nodes to -1 (indicating no parent).
        parent.resize(n, -1);
    }

    /**
     * @brief Executes the Breadth-First Search algorithm.
     *
     * This function systematically explores the graph layer by layer, starting from
     * the source node. It correctly finds the shortest path on unweighted graphs.
     *
     * @param adj The graph, represented as an adjacency list.
     * @param start_node The node from which to start the search.
     */
    void solve(const Graph& adj, int start_node) {
        // A queue to manage the nodes to visit, following FIFO principle.
        std::queue<int> q;
        // A boolean vector to keep track of visited nodes to avoid cycles and redundant work.
        std::vector<bool> visited(num_nodes, false);

        // --- Initialization ---
        // The start node is at distance 0 from itself and has no parent.
        if (start_node >= num_nodes) {
            std::cerr << "Error: Start node is out of bounds." << std::endl;
            return;
        }
        distance[start_node] = 0;
        visited[start_node] = true;
        q.push(start_node);

        // --- Main Loop ---
        while (!q.empty()) {
            // Dequeue a vertex 'u' to process.
            int u = q.front();
            q.pop();

            // Explore all neighbors of 'u'.
            for (int v : adj[u]) {
                // If neighbor 'v' has not been visited yet...
                if (!visited[v]) {
                    // ...mark it as visited.
                    visited[v] = true;
                    // ...set its distance.
                    distance[v] = distance[u] + 1;
                    // ...set its parent for path reconstruction.
                    parent[v] = u;
                    // ...and enqueue it to be processed later.
                    q.push(v);
                }
            }
        }
    }
};

/**
 * @brief A helper function to reconstruct and print the shortest path.
 * @param start_node The source node of the search.
 * @param end_node The destination node.
 * @param parent_map A map or vector storing the parent of each node.
 * @param node_names A map to convert node indices to human-readable names.
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
// MAIN FUNCTION - DEMONSTRATION FOR PROBLEM 8 (SIMPLE GRAPH)
// =================================================================================
int main() {
    int num_nodes = 7;
    int start_node = 0; // v1

    // Map integer indices to human-readable names for clear output.
    std::map<int, std::string> node_names = {
        {0, "v1"}, {1, "v2"}, {2, "v3"}, {3, "v4"}, 
        {4, "v5"}, {5, "v6"}, {6, "v7"}
    };

    // --- Graph Creation for a Simple Graph (from Val21, Fig 1.1) ---
    // Since it's an undirected graph, for each edge (u, v), we add both u->v and v->u.
    Graph adj(num_nodes);
    adj[0].insert(adj[0].end(), {1, 3});
    adj[1].insert(adj[1].end(), {0, 4, 3});
    adj[2].insert(adj[2].end(), {0, 3, 5});
    adj[3].insert(adj[3].end(), {0, 1, 2, 4, 5, 6});
    adj[4].insert(adj[4].end(), {1, 3, 6});
    adj[5].insert(adj[5].end(), {2, 3, 6});
    adj[6].insert(adj[6].end(), {3, 4, 5});

    // --- Execution and Output ---
    
    BfsSolver solver(num_nodes);
    solver.solve(adj, start_node);

    std::cout << "=====================================================" << std::endl;
    std::cout << "Dijkstra's Algorithm Report for Simple Graph (Problem 8)" << std::endl;
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