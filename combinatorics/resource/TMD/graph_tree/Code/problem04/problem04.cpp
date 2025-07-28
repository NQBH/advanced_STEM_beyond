#include <iostream>
#include <vector>
#include <map>
#include <optional>
#include <utility> // For std::pair
#include <algorithm> // For std::sort (for comparison)
#include <numeric>


// Run with C++ 23
// =========================================================================
// ==                      DATA STRUCTURE DEFINITIONS                     ==
// =========================================================================

// Intermediate representation: A simple struct for an edge
struct Edge {
    int u;
    int v;
    int weight = 1;

    // For sorting and comparison
    bool operator<(const Edge& other) const {
        if (u != other.u) return u < other.u;
        if (v != other.v) return v < other.v;
        return weight < other.weight;
    }
};

// 1. Adjacency Matrix
using AdjacencyMatrix = std::vector<std::vector<std::optional<int>>>;

// 2. Adjacency List
using AdjacencyList = std::vector<std::vector<std::pair<int, int>>>;

// 3. Adjacency Map
using AdjacencyMap = std::map<int, std::map<int, int>>;

// --- Tree Representations ---
// 1. Array of Parents
using ArrayOfParents = std::vector<int>;

// 2. First-Child, Next-Sibling
struct FCNS_Node { int first_child = -1; int next_sibling = -1; };
using FCNS_Representation = std::vector<FCNS_Node>;

// =========================================================================
// ==                        GRAPH CONVERTER CLASS                        ==
// =========================================================================

class GraphConverter {
public:
    // --- From Edge List (to other formats) ---
    static AdjacencyMatrix toMatrix(const std::vector<Edge>& edge_list, int num_nodes) {
        AdjacencyMatrix matrix(num_nodes, std::vector<std::optional<int>>(num_nodes, std::nullopt));
        for (const auto& edge : edge_list) {
            if (edge.u < num_nodes && edge.v < num_nodes) {
                matrix[edge.u][edge.v] = edge.weight;
            }
        }
        return matrix;
    }

    static AdjacencyList toAdjList(const std::vector<Edge>& edge_list, int num_nodes) {
        AdjacencyList adj_list(num_nodes);
        for (const auto& edge : edge_list) {
            if (edge.u < num_nodes) {
                adj_list[edge.u].push_back({edge.v, edge.weight});
            }
        }
        return adj_list;
    }

    static AdjacencyMap toAdjMap(const std::vector<Edge>& edge_list) {
        AdjacencyMap adj_map;
        for (const auto& edge : edge_list) {
            adj_map[edge.u][edge.v] = edge.weight;
        }
        return adj_map;
    }

    // --- To Edge List (from other formats) ---
    static std::vector<Edge> fromMatrix(const AdjacencyMatrix& matrix) {
        std::vector<Edge> edge_list;
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j].has_value()) {
                    edge_list.push_back({(int)i, (int)j, matrix[i][j].value()});
                }
            }
        }
        return edge_list;
    }

    static std::vector<Edge> fromAdjList(const AdjacencyList& adj_list) {
        std::vector<Edge> edge_list;
        for (size_t u = 0; u < adj_list.size(); ++u) {
            for (const auto& pair : adj_list[u]) {
                edge_list.push_back({(int)u, pair.first, pair.second});
            }
        }
        return edge_list;
    }

    static std::vector<Edge> fromAdjMap(const AdjacencyMap& adj_map) {
        std::vector<Edge> edge_list;
        for (const auto& [u, neighbors] : adj_map) {
            for (const auto& [v, weight] : neighbors) {
                edge_list.push_back({u, v, weight});
            }
        }
        return edge_list;
    }
};

// =========================================================================
// ==                           HELPER PRINTERS                           ==
// =========================================================================

void printEdgeList(const std::vector<Edge>& edges) {
    std::cout << "{ ";
    for (const auto& e : edges) {
        std::cout << "(" << e.u << "," << e.v << "," << e.weight << ") ";
    }
    std::cout << "}\n";
}

void printMatrix(const AdjacencyMatrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            if (val.has_value()) {
                std::cout << val.value() << "\t";
            } else {
                std::cout << "N\t";
            }
        }
        std::cout << "\n";
    }
}

void printAdjList(const AdjacencyList& adjList) {
    for (size_t i = 0; i < adjList.size(); ++i) {
        std::cout << i << ": ";
        for (const auto& p : adjList[i]) {
            std::cout << "->(" << p.first << "," << p.second << ") ";
        }
        std::cout << "\n";
    }
}

void printAdjMap(const AdjacencyMap& adjMap) {
    for (const auto& [u, neighbors] : adjMap) {
        std::cout << u << ": ";
        for (const auto& [v, weight] : neighbors) {
            std::cout << "->(" << v << "," << weight << ") ";
        }
        std::cout << "\n";
    }
}


// =========================================================================
// ==                            MAIN FUNCTION                            ==
// =========================================================================
int main() {
    int num_nodes = 4;
    // Our intermediate representation
    std::vector<Edge> original_edges = {{0, 1, 5}, {0, 2, 3}, {1, 2, 2}, {1, 3, 6}, {2, 3, 1}};
    
    std::cout << "=================================================" << std::endl;
    std::cout << "       GRAPH CONVERTER DEMO (Problem 4)        " << std::endl;
    std::cout << "=================================================\n" << std::endl;
    
    std::cout << "Original Edge List:" << std::endl;
    printEdgeList(original_edges);
    
    std::cout << "\n--- Edge List -> Adjacency Matrix ---" << std::endl;
    AdjacencyMatrix mat = GraphConverter::toMatrix(original_edges, num_nodes);
    printMatrix(mat);
    
    std::cout << "\n--- Adjacency Matrix -> Edge List ---" << std::endl;
    std::vector<Edge> edges_from_mat = GraphConverter::fromMatrix(mat);
    // Sort for consistent comparison
    std::sort(edges_from_mat.begin(), edges_from_mat.end());
    printEdgeList(edges_from_mat);
    
    std::cout << "\n--- Edge List -> Adjacency List ---" << std::endl;
    AdjacencyList alist = GraphConverter::toAdjList(original_edges, num_nodes);
    printAdjList(alist);
    
    std::cout << "\n--- Adjacency List -> Edge List ---" << std::endl;
    std::vector<Edge> edges_from_alist = GraphConverter::fromAdjList(alist);
    std::sort(edges_from_alist.begin(), edges_from_alist.end());
    printEdgeList(edges_from_alist);
    
    std::cout << "\n--- Edge List -> Adjacency Map ---" << std::endl;
    AdjacencyMap amap = GraphConverter::toAdjMap(original_edges);
    printAdjMap(amap);

    std::cout << "\n--- Adjacency Map -> Edge List ---" << std::endl;
    std::vector<Edge> edges_from_amap = GraphConverter::fromAdjMap(amap);
    std::sort(edges_from_amap.begin(), edges_from_amap.end());
    printEdgeList(edges_from_amap);

    std::cout << "\n=================================================" << std::endl;

    return 0;
}