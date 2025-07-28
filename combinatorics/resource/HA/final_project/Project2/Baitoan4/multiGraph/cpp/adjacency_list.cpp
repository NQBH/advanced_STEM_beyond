#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

/**
 * @brief Structure to represent adjacency list for multigraph
 */
struct AdjacencyList {
    std::vector<std::vector<int>> adjacencyData;
    int numberOfVertices;
    
    /**
     * @brief Default constructor
     */
    AdjacencyList() : numberOfVertices(0) {}
    
    /**
     * @brief Constructor with vertex count
     * @param vertexCount Number of vertices in the graph
     */
    AdjacencyList(int vertexCount) : numberOfVertices(vertexCount) {
        adjacencyData.resize(vertexCount);
    }
};

/**
 * @brief Read adjacency list from edge list file for multigraph
 * @param fileName Name of input file containing edge list
 * @return AdjacencyList structure containing the graph data
 */
AdjacencyList readAdjacencyListFromEdgeList(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        return AdjacencyList();
    }
    
    int numberOfVertices, numberOfEdges;
    inputFile >> numberOfVertices >> numberOfEdges;
    
    AdjacencyList adjacencyList(numberOfVertices);
    int selfLoopCount = 0;
    
    for (int edgeIndex = 0; edgeIndex < numberOfEdges; ++edgeIndex) {
        int sourceVertex, targetVertex;
        inputFile >> sourceVertex >> targetVertex;
        
        // Check for self-loops (not allowed in multigraph)
        if (sourceVertex == targetVertex) {
            selfLoopCount++;
            std::cout << "Warning: Self-loop detected (" << sourceVertex << "," << targetVertex 
                      << ") - Removing as multigraphs do not allow self-loops" << std::endl;
            continue;
        }
        
        if (sourceVertex >= 0 && sourceVertex < numberOfVertices && 
            targetVertex >= 0 && targetVertex < numberOfVertices) {
            adjacencyList.adjacencyData[sourceVertex].push_back(targetVertex);
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Total self-loops removed: " << selfLoopCount << std::endl;
    }
    
    inputFile.close();
    return adjacencyList;
}

/**
 * @brief Convert adjacency matrix to adjacency list with self-loop removal
 * @param matrixData Matrix data as 2D vector
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyList structure containing the converted data
 */
AdjacencyList convertMatrixToAdjacencyList(const std::vector<std::vector<int>>& matrixData, int numberOfVertices) {
    AdjacencyList adjacencyList(numberOfVertices);
    int selfLoopCount = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex = 0; targetVertex < numberOfVertices; ++targetVertex) {
            int edgeCount = matrixData[sourceVertex][targetVertex];
            
            // Skip self-loops
            if (sourceVertex == targetVertex && edgeCount > 0) {
                selfLoopCount += edgeCount;
                continue;
            }
            
            for (int edgeIndex = 0; edgeIndex < edgeCount; ++edgeIndex) {
                adjacencyList.adjacencyData[sourceVertex].push_back(targetVertex);
            }
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to multigraph list" << std::endl;
    }
    
    return adjacencyList;
}

/**
 * @brief Display adjacency list to console
 * @param adjacencyList The adjacency list to display
 */
void displayAdjacencyList(const AdjacencyList& adjacencyList) {
    std::cout << "=== Adjacency List (MultiGraph) ===" << std::endl;
    std::cout << "Number of vertices: " << adjacencyList.numberOfVertices << std::endl;
    
    for (int vertexIndex = 0; vertexIndex < adjacencyList.numberOfVertices; ++vertexIndex) {
        std::cout << "Vertex " << vertexIndex << ": ";
        if (adjacencyList.adjacencyData[vertexIndex].empty()) {
            std::cout << "(no outgoing edges)";
        } else {
            for (int edgeIndex = 0; edgeIndex < static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size()); ++edgeIndex) {
                std::cout << adjacencyList.adjacencyData[vertexIndex][edgeIndex];
                if (edgeIndex < static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size()) - 1) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Write adjacency list to output file
 * @param adjacencyList The adjacency list to write
 * @param fileName Name of output file
 */
void writeAdjacencyListToFile(const AdjacencyList& adjacencyList, const std::string& fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create file " << fileName << std::endl;
        return;
    }
    
    outputFile << "=== Adjacency List (MultiGraph) ===" << std::endl;
    outputFile << "Number of vertices: " << adjacencyList.numberOfVertices << std::endl;
    
    for (int vertexIndex = 0; vertexIndex < adjacencyList.numberOfVertices; ++vertexIndex) {
        outputFile << "Vertex " << vertexIndex << ": ";
        if (adjacencyList.adjacencyData[vertexIndex].empty()) {
            outputFile << "(no outgoing edges)";
        } else {
            for (int edgeIndex = 0; edgeIndex < static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size()); ++edgeIndex) {
                outputFile << adjacencyList.adjacencyData[vertexIndex][edgeIndex];
                if (edgeIndex < static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size()) - 1) {
                    outputFile << " ";
                }
            }
        }
        outputFile << std::endl;
    }
    
    outputFile.flush();
    outputFile.close();
}

/**
 * @brief Count total edges in adjacency list
 * @param adjacencyList The adjacency list to count edges from
 * @return Total number of edges
 */
int countTotalEdgesInAdjacencyList(const AdjacencyList& adjacencyList) {
    int totalEdges = 0;
    for (int vertexIndex = 0; vertexIndex < adjacencyList.numberOfVertices; ++vertexIndex) {
        totalEdges += static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size());
    }
    return totalEdges;
}

/**
 * @brief Convert extended adjacency list to adjacency list with self-loop removal
 * @param outgoingEdgeIndices Outgoing edge indices per vertex
 * @param edgeInstances All edge instances as (source, target) pairs
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyList structure containing the converted data
 */
AdjacencyList convertExtendedAdjacencyListToList(const std::vector<std::vector<int>>& outgoingEdgeIndices, 
                                                const std::vector<std::pair<int, int>>& edgeInstances, 
                                                int numberOfVertices) {
    AdjacencyList adjacencyList(numberOfVertices);
    int selfLoopCount = 0;
    
    for (int vertexIndex = 0; vertexIndex < numberOfVertices; ++vertexIndex) {
        for (int edgeIndex : outgoingEdgeIndices[vertexIndex]) {
            if (edgeIndex >= 0 && edgeIndex < static_cast<int>(edgeInstances.size())) {
                int sourceVertex = edgeInstances[edgeIndex].first;
                int targetVertex = edgeInstances[edgeIndex].second;
                
                // Skip self-loops
                if (sourceVertex == targetVertex) {
                    selfLoopCount++;
                    continue;
                }
                
                adjacencyList.adjacencyData[sourceVertex].push_back(targetVertex);
            }
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to multigraph list" << std::endl;
    }
    
    return adjacencyList;
}

/**
 * @brief Convert adjacency map to adjacency list with self-loop removal
 * @param outgoingConnections Map of outgoing connections
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyList structure containing the converted data
 */
AdjacencyList convertAdjacencyMapToList(const std::map<int, std::vector<std::pair<int, std::pair<int, int>>>>& outgoingConnections, 
                                       int numberOfVertices) {
    AdjacencyList adjacencyList(numberOfVertices);
    int selfLoopCount = 0;
    
    for (const auto& vertexPair : outgoingConnections) {
        int sourceVertex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        for (const auto& connection : connections) {
            int targetVertex = connection.first;
            
            // Skip self-loops
            if (sourceVertex == targetVertex) {
                selfLoopCount++;
                continue;
            }
            
            if (targetVertex >= 0 && targetVertex < numberOfVertices) {
                adjacencyList.adjacencyData[sourceVertex].push_back(targetVertex);
            }
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to multigraph list" << std::endl;
    }
    
    return adjacencyList;
} 