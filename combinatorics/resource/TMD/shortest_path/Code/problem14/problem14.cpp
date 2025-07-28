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
 * This class is designed for simple graphs and encapsulates the data and logic for the algorithm.
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
        // Initialize distances to infinity.
        distances.resize(n, std::numeric_limits<ll>::max());
        // Initialize predecessors to -1 (indicating no predecessor).
        predecessors.resize(n, -1);
    }

    /**
     * @brief Executes Dijkstra's algorithm on the given graph from a start node.
     * @param adj The graph, represented as an adjacency list.
     * @param start_node The index of the source node.
     */
    void solve(const Graph& adj, int start_node) {
        // The distance from the start node to itself is 0.
        distances[start_node] = 0;
        
        // Min-heap: stores {distance, node}.
        // std::greater is used to make the priority_queue a min-heap.
        std::priority_queue<std::pair<ll, int>, 
                            std::vector<std::pair<ll, int>>, 
                            std::greater<std::pair<ll, int>>> pq;
        pq.push({0, start_node});

        while (!pq.empty()) {
            ll d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Optimization: if we've found a better path already, skip this one.
            if (d > distances[u]) {
                continue;
            }

            // Iterate through all outgoing edges of node u.
            for (const auto& edge : adj[u]) {
                int weight = edge.first;
                int v = edge.second;

                // Relaxation step: if we found a shorter path to v through u...
                if (distances[u] + weight < distances[v]) {
                    // ...update the distance and predecessor...
                    distances[v] = distances[u] + weight;
                    predecessors[v] = u;
                    // ...and push the new, better path to the priority queue.
                    pq.push({distances[v], v});
                }
            }
        }
    }

    /**
     * @brief Reconstructs the shortest path to a given end node.
     * @param end_node The destination node.
     * @return A vector of integers representing the path from the start node to the end node.
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
        return {}; // Return an empty path if no path was found.
    }
};

// ============================================================
// MAIN FUNCTION - DEMONSTRATION FOR PROBLEM 14 (SIMPLE GRAPH)
// ============================================================
int main() {
    int num_nodes = 5;
    int start_node = 0; // Starting from node 'A' (index 0)

    std::map<int, std::string> node_names = {{0,"A"}, {1,"B"}, {2,"C"}, {3,"D"}, {4,"E"}};
    
    // --- Graph Creation for a Simple Graph ---
    // Since it's a simple, undirected graph, for each edge (u, v), we add both
    // u -> v and v -> u to the adjacency list.
    Graph adj(num_nodes);
    
    // Node A (0)
    adj[0].push_back({10, 1}); // A -> B (weight 10)
    adj[0].push_back({3, 2});  // A -> C (weight 3)
    // Node B (1)
    adj[1].push_back({10, 0}); // B -> A
    adj[1].push_back({1, 2});  // B -> C
    adj[1].push_back({2, 3});  // B -> D
    // Node C (2)
    adj[2].push_back({3, 0});  // C -> A
    adj[2].push_back({1, 1});  // C -> B
    adj[2].push_back({8, 3});  // C -> D
    adj[2].push_back({2, 4});  // C -> E
    // Node D (3)
    adj[3].push_back({2, 1});  // D -> B
    adj[3].push_back({8, 2});  // D -> C
    adj[3].push_back({5, 4});  // D -> E
    // Node E (4)
    adj[4].push_back({2, 2});  // E -> C
    adj[4].push_back({5, 3});  // E -> D
    
    // --- Execution and Output ---
    
    DijkstraSolver solver(num_nodes);
    solver.solve(adj, start_node);

    std::cout << "=====================================================" << std::endl;
    std::cout << "Dijkstra's Algorithm Report for Simple Graph (Problem 14)" << std::endl;
    std::cout << "Source Node: '" << node_names[start_node] << "'" << std::endl;
    std::cout << "=====================================================" << std::endl;

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
    std::cout << "=====================================================" << std::endl;

    return 0;
}