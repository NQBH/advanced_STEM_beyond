#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <map>
#include <algorithm>
#include <functional> // For std::greater

// Use long long to avoid overflow with long paths.
using ll = long long;
// Use type aliases for better readability.
using Edge = std::pair<int, int>; // {weight, neighbor_node}
using Graph = std::vector<std::vector<Edge>>;

/**
 * @class DijkstraSolver
 * @brief A class to compute shortest paths from a single source using Dijkstra's algorithm.
 *
 * This implementation is suitable for graphs with non-negative edge weights.
 * It can handle parallel edges and self-loops as long as their weights are not negative.
 */
class DijkstraSolver {
public:
    std::vector<ll> distances;
    std::vector<int> predecessors;
    int num_nodes;

    /**
     * @brief Constructs a DijkstraSolver for a graph with a given number of nodes.
     * @param n The number of nodes in the graph.
     */
    DijkstraSolver(int n) : num_nodes(n) {
        distances.resize(n, std::numeric_limits<ll>::max());
        predecessors.resize(n, -1); // -1 indicates no predecessor
    }

    /**
     * @brief Executes Dijkstra's algorithm.
     * @warning This method is ONLY correct for graphs with non-negative edge weights.
     * @param adj The graph, represented as an adjacency list.
     * @param start_node The index of the source node.
     */
    void solve(const Graph& adj, int start_node) {
        distances[start_node] = 0;
        
        std::priority_queue<std::pair<ll, int>, 
                            std::vector<std::pair<ll, int>>, 
                            std::greater<std::pair<ll, int>>> pq;
        pq.push({0, start_node});

        while (!pq.empty()) {
            ll d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > distances[u]) {
                continue;
            }

            for (const auto& edge : adj[u]) {
                int weight = edge.first;
                int v = edge.second;

                // The core logic of Dijkstra's algorithm.
                // Assumes 'weight' is non-negative.
                if (distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    predecessors[v] = u;
                    pq.push({distances[v], v});
                }
            }
        }
    }

    /**
     * @brief Reconstructs the shortest path to a given end node.
     * @param end_node The destination node.
     * @return A vector of integers representing the path.
     */
    std::vector<int> reconstruct_path(int end_node) {
        std::vector<int> path;
        for (int at = end_node; at != -1; at = predecessors[at]) {
            path.push_back(at);
        }
        std::reverse(path.begin(), path.end());
        
        if (!path.empty() && path[0] == 0) { // Assuming start_node is always 0
             return path;
        }
        return {};
    }
};

// ==============================================================
// MAIN FUNCTION - DEMONSTRATION FOR PROBLEM 16 (GENERAL GRAPH)
// =================================================================
int main() {
    int num_nodes = 5;
    int start_node = 0;

    std::map<int, std::string> node_names = {{0,"A"}, {1,"B"}, {2,"C"}, {3,"D"}, {4,"E"}};
    
    // --- Graph Creation for a General Graph ---
    // This graph includes parallel edges and a self-loop.
    // CRITICAL ASSUMPTION: All weights are non-negative.
    Graph adj(num_nodes);
    
    // Node A (0)
    adj[0].push_back({10, 1}); // A -> B
    adj[0].push_back({3, 2});  // A -> C
    // Node B (1)
    adj[1].push_back({2, 3});  // B -> D (edge 1)
    adj[1].push_back({1, 3});  // B -> D (parallel edge with better weight)
    // Node C (2)
    adj[2].push_back({3, 0});
    adj[2].push_back({8, 3});
    adj[2].push_back({2, 4});
    // Node D (3)
    adj[3].push_back({5, 4});
    // Node E (4)
    adj[4].push_back({1, 2});
    adj[4].push_back({4, 4});  // E -> E (self-loop with non-negative weight)
    
    // --- Execution and Output ---
    
    DijkstraSolver solver(num_nodes);
    solver.solve(adj, start_node);

    std::cout << "================================================================" << std::endl;
    std::cout << "Dijkstra's Algorithm Report for General Graph (Problem 16)" << std::endl;
    std::cout << "Source Node: '" << node_names[start_node] << "'" << std::endl;
    std::cout << "WARNING: Results are correct ONLY under the assumption that" << std::endl;
    std::cout << "         all edge weights are non-negative." << std::endl;
    std::cout << "================================================================" << std::endl;

    for (int i = 0; i < num_nodes; ++i) {
        std::cout << "\n--- Destination: '" << node_names[i] << "' ---" << std::endl;
        std::cout << "  Shortest Distance: ";
        if (solver.distances[i] == std::numeric_limits<ll>::max()) {
            std::cout << "UNREACHABLE" << std::endl;
        } else {
            std::cout << solver.distances[i] << std::endl;
            std::vector<int> path = solver.reconstruct_path(i);
            std::cout << "  Path: ";
            if (path.empty()) {
                std::cout << "N/A" << std::endl;
            } else {
                for (size_t j = 0; j < path.size(); ++j) {
                    std::cout << node_names[path[j]] << (j == path.size() - 1 ? "" : " -> ");
                }
                std::cout << std::endl;
            }
        }
    }
    std::cout << "================================================================" << std::endl;
    
    return 0;
}