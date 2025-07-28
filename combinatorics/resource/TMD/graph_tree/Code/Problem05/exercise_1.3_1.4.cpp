#include <iostream>
#include <vector>
#include <string>
#include <numeric> // For std::iota (in Kp,q)

// A type alias for graph representation for better readability.
// We use an adjacency list for an undirected graph.
using GraphAdjList = std::vector<std::vector<int>>;

/**
 * @class GraphGenerator
 * @brief A class to generate various families of standard graphs.
 *
 * This class implements algorithms to construct path, cycle, wheel, complete,
 * and complete bipartite graphs. It simulates the abstract operations like
 * `new_vertex` and `new_edge` described in the textbook.
 */
class GraphGenerator {
private:
    GraphAdjList adj;
    int num_vertices = 0;

    /**
     * @brief Resets the generator to an empty state for a new graph.
     */
    void clear() {
        adj.clear();
        num_vertices = 0;
    }

    /**
     * @brief Simulates the `new_vertex` operation.
     * @return The integer index of the newly created node.
     */
    int new_vertex() {
        adj.push_back({}); // Add an empty adjacency list for the new vertex
        return num_vertices++;
    }

    /**
     * @brief Simulates the `new_edge` operation for an undirected graph.
     * @param u The index of the first vertex.
     * @param v The index of the second vertex.
     */
    void new_edge(int u, int v) {
        if (u < num_vertices && v < num_vertices) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

public:
    /**
     * @brief Exercise 1.3: Generates a Path Graph P_n.
     * A path graph consists of n vertices connected in a simple line.
     * @param n The number of vertices.
     * @return The generated graph as an adjacency list.
     */
    GraphAdjList generate_path_graph(int n) {
        clear();
        if (n <= 0) return adj;
        for (int i = 0; i < n; ++i) new_vertex();
        for (int i = 0; i < n - 1; ++i) new_edge(i, i + 1);
        return adj;
    }

    /**
     * @brief Exercise 1.3: Generates a Cycle Graph C_n.
     * A cycle graph is a path graph with an additional edge connecting the endpoints.
     * @param n The number of vertices.
     * @return The generated graph as an adjacency list.
     */
    GraphAdjList generate_cycle_graph(int n) {
        generate_path_graph(n);
        // Add the closing edge if the graph is large enough to form a cycle.
        if (n > 2) {
            new_edge(n - 1, 0);
        }
        return adj;
    }

    /**
     * @brief Exercise 1.3: Generates a Wheel Graph W_n.
     * A wheel graph W_n has n vertices, consisting of a central "hub" vertex
     * connected to all vertices of an outer cycle of n-1 vertices.
     * @param n The total number of vertices.
     * @return The generated graph as an adjacency list.
     */
    GraphAdjList generate_wheel_graph(int n) {
        clear();
        if (n <= 3) return adj; // A wheel graph needs at least 4 vertices.
        
        int center_vertex = new_vertex(); // This is node 0
        // Create the n-1 outer vertices
        for (int i = 0; i < n - 1; ++i) new_vertex();

        // Connect the center to all outer vertices (1 to n-1)
        for (int i = 1; i < n; ++i) {
            new_edge(center_vertex, i);
        }
        
        // Connect the outer vertices in a cycle
        for (int i = 1; i < n - 1; ++i) {
            new_edge(i, i + 1);
        }
        new_edge(n - 1, 1); // Close the outer cycle

        return adj;
    }
    
    /**
     * @brief Exercise 1.4: Generates a Complete Graph K_n.
     * A complete graph has an edge between every pair of distinct vertices.
     * @param n The number of vertices.
     * @return The generated graph as an adjacency list.
     */
    GraphAdjList generate_complete_graph(int n) {
        clear();
        if (n <= 0) return adj;
        for (int i = 0; i < n; ++i) new_vertex();
        // Connect every vertex i to every other vertex j where j > i
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                new_edge(i, j);
            }
        }
        return adj;
    }

    /**
     * @brief Exercise 1.4: Generates a Complete Bipartite Graph K_p,q.
     * Vertices are partitioned into two sets of size p and q. Every vertex in the
     * first set is connected to every vertex in the second set.
     * @param p The size of the first partition.
     * @param q The size of the second partition.
     * @return The generated graph as an adjacency list.
     */
    GraphAdjList generate_complete_bipartite_graph(int p, int q) {
        clear();
        if (p <= 0 || q <= 0) return adj;
        int n = p + q;
        for (int i = 0; i < n; ++i) new_vertex();
        
        // Vertices 0 to p-1 form the first partition (X).
        // Vertices p to p+q-1 form the second partition (Y).
        for (int i = 0; i < p; ++i) { // For each vertex in X
            for (int j = p; j < n; ++j) { // For each vertex in Y
                new_edge(i, j);
            }
        }
        return adj;
    }
};

/**
 * @brief Helper function to print a graph from its adjacency list representation.
 */
void print_graph(const GraphAdjList& graph, const std::string& name) {
    std::cout << "--- " << name << " ---" << std::endl;
    if (graph.empty()) {
        std::cout << "  (Empty Graph)" << std::endl;
        return;
    }
    for (size_t i = 0; i < graph.size(); ++i) {
        std::cout << "  Node " << i << " -> { ";
        for (size_t j = 0; j < graph[i].size(); ++j) {
            std::cout << graph[i][j] << (j == graph[i].size() - 1 ? "" : ", ");
        }
        std::cout << " }" << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}

// =================================================================================
// MAIN FUNCTION - DEMONSTRATION FOR EXERCISES 1.3 & 1.4
// =================================================================================
int main() {
    GraphGenerator gen;

    std::cout << "=====================================================" << std::endl;
    std::cout << "    Graph Generator Demo (Exercises 1.3 & 1.4)     " << std::endl;
    std::cout << "=====================================================" << std::endl;

    // --- Exercise 1.3 ---
    std::cout << "\n--- Exercise 1.3 ---\n" << std::endl;
    print_graph(gen.generate_path_graph(5), "Path Graph P_5");
    print_graph(gen.generate_cycle_graph(5), "Cycle Graph C_5");
    print_graph(gen.generate_wheel_graph(5), "Wheel Graph W_5");

    // --- Exercise 1.4 ---
    std::cout << "\n--- Exercise 1.4 ---\n" << std::endl;
    print_graph(gen.generate_complete_graph(5), "Complete Graph K_5");
    print_graph(gen.generate_complete_bipartite_graph(3, 2), "Complete Bipartite Graph K_3,2");

    std::cout << "=====================================================" << std::endl;

    return 0;
}