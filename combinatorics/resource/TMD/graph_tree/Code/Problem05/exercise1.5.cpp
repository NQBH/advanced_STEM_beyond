#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::pair

// A type alias for a pair of vertices representing an edge.
using EdgePair = std::pair<int, int>;

/**
 * @class AdjacencyMatrixGraph
 * @brief Implements a directed graph using an adjacency matrix representation.
 *
 * This class encapsulates the logic for graph operations based on a matrix,
 * as specified in Problem 1.4 and required by Exercise 1.5.
 * An edge from u to v exists if matrix[u][v] is 1.
 */
class AdjacencyMatrixGraph {
private:
    int num_vertices;
    // The matrix stores 1 if an edge exists, 0 otherwise.
    std::vector<std::vector<int>> matrix;

public:
    /**
     * @brief Constructs a graph with a specified number of vertices.
     * @param n The number of vertices. The graph will have vertices 0 to n-1.
     */
    AdjacencyMatrixGraph(int n) : num_vertices(n) {
        // Initialize an n x n matrix with all zeros (no edges).
        matrix.assign(n, std::vector<int>(n, 0));
    }

    /**
     * @brief Adds a directed edge from u to v.
     * @param u The source vertex.
     * @param v The target vertex.
     */
    void add_edge(int u, int v) {
        if (0 <= u && u < num_vertices && 0 <= v && v < num_vertices) {
            matrix[u][v] = 1;
        }
    }

    /**
     * @brief (Problem 1.4) Deletes a directed edge from u to v.
     * @param u The source vertex.
     * @param v The target vertex.
     */
    void del_edge(int u, int v) {
        if (0 <= u && u < num_vertices && 0 <= v && v < num_vertices) {
            matrix[u][v] = 0;
        }
    }

    /**
     * @brief (Problem 1.4) Gets the source of an edge defined by (u, v).
     * This is a trivial operation as the source is given.
     * @param u The source vertex.
     * @param v The target vertex.
     * @return The source vertex u.
     */
    int source(int u, int v) const { return u; }
        
    /**
     * @brief (Problem 1.4) Gets the target of an edge defined by (u, v).
     * Trivial operation, returns the given target.
     * @param u The source vertex.
     * @param v The target vertex.
     * @return The target vertex v.
     */
    int target(int u, int v) const { return v; }

    /**
     * @brief (Problem 1.4) Returns a list of all edges in the graph.
     * Complexity: O(n^2), where n is the number of vertices.
     * @return A vector of pairs, where each pair represents a directed edge.
     */
    std::vector<EdgePair> edges() const {
        std::vector<EdgePair> edge_list;
        for (int i = 0; i < num_vertices; ++i) {
            for (int j = 0; j < num_vertices; ++j) {
                if (matrix[i][j] == 1) {
                    edge_list.push_back({i, j});
                }
            }
        }
        return edge_list;
    }

    /**
     * @brief (Problem 1.4) Returns a list of all outgoing edges from a vertex.
     * Complexity: O(n), where n is the number of vertices.
     * @param v The source vertex.
     * @return A vector of pairs representing outgoing edges.
     */
    std::vector<EdgePair> outgoing(int v) const {
        std::vector<EdgePair> edge_list;
        if (0 <= v && v < num_vertices) {
            for (int j = 0; j < num_vertices; ++j) {
                if (matrix[v][j] == 1) {
                    edge_list.push_back({v, j});
                }
            }
        }
        return edge_list;
    }
        
    /**
     * @brief (Problem 1.4) Returns a list of all incoming edges to a vertex.
     * Complexity: O(n), where n is the number of vertices.
     * @param v The target vertex.
     * @return A vector of pairs representing incoming edges.
     */
    std::vector<EdgePair> incoming(int v) const {
        std::vector<EdgePair> edge_list;
        if (0 <= v && v < num_vertices) {
            for (int i = 0; i < num_vertices; ++i) {
                if (matrix[i][v] == 1) {
                    edge_list.push_back({i, v});
                }
            }
        }
        return edge_list;
    }

    /**
     * @brief Helper function to print the matrix for verification.
     */
    void print_matrix() const {
        for (int i = 0; i < num_vertices; ++i) {
            std::cout << "  ";
            for (int j = 0; j < num_vertices; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// =================================================================================
// MAIN FUNCTION - DEMONSTRATION FOR EXERCISE 1.5
// =================================================================================
int main() {
    int num_nodes = 4;
    std::cout << "=====================================================" << std::endl;
    std::cout << "  Adjacency Matrix Graph Class Demo (Exercise 1.5)   " << std::endl;
    std::cout << "=====================================================" << std::endl;

    // --- 1. Create a graph instance ---
    AdjacencyMatrixGraph graph(num_nodes);
    std::cout << "\n--> Initial empty graph with " << num_nodes << " vertices:" << std::endl;
    graph.print_matrix();

    // --- 2. Add some edges ---
    std::cout << "\n--> Adding edges: (0,1), (0,2), (1,2), (2,0), (2,3), (3,3)" << std::endl;
    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(2, 0);
    graph.add_edge(2, 3);
    graph.add_edge(3, 3); // A self-loop
    std::cout << "Matrix after adding edges:" << std::endl;
    graph.print_matrix();

    // --- 3. Test the extended operations ---
    std::cout << "\n--> Testing extended operations from Problem 1.4:" << std::endl;

    // Test edges()
    std::cout << "  All edges: ";
    for (const auto& edge : graph.edges()) {
        std::cout << "(" << edge.first << "," << edge.second << ") ";
    }
    std::cout << std::endl;

    // Test outgoing()
    int node_to_test = 2;
    std::cout << "  Outgoing edges from node " << node_to_test << ": ";
    for (const auto& edge : graph.outgoing(node_to_test)) {
        std::cout << "(" << edge.first << "," << edge.second << ") ";
    }
    std::cout << std::endl;

    // Test incoming()
    std::cout << "  Incoming edges to node " << node_to_test << ": ";
    for (const auto& edge : graph.incoming(node_to_test)) {
        std::cout << "(" << edge.first << "," << edge.second << ") ";
    }
    std::cout << std::endl;

    // Test del_edge()
    std::cout << "\n--> Deleting edge (0,2)..." << std::endl;
    graph.del_edge(0, 2);
    std::cout << "Matrix after deleting edge (0,2):" << std::endl;
    graph.print_matrix();

    std::cout << "=====================================================" << std::endl;
    
    return 0;
}