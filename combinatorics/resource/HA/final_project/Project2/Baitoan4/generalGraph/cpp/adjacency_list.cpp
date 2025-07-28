#include <iostream>
#include <vector>
#include <fstream>
#include <map>

/**
 * @brief Structure to represent adjacency list for general graph
 */
struct AdjacencyList {
    std::vector<std::vector<int>> adjacencyData;
    int numberOfVertices;
};

/**
 * @brief Read adjacency list from edge list format
 * @param fileName Name of input file containing edge list
 * @return AdjacencyList structure containing the graph data
 */
AdjacencyList readAdjacencyListFromEdgeList(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        exit(1);
    }
    
    int numberOfVertices, numberOfEdges;
    inputFile >> numberOfVertices >> numberOfEdges;
    
    AdjacencyList adjacencyList;
    adjacencyList.numberOfVertices = numberOfVertices;
    adjacencyList.adjacencyData.resize(numberOfVertices);
    
    for (int edgeIndex = 0; edgeIndex < numberOfEdges; ++edgeIndex) {
        int sourceVertex, targetVertex;
        inputFile >> sourceVertex >> targetVertex;
        adjacencyList.adjacencyData[sourceVertex].push_back(targetVertex);
    }
    
    inputFile.close();
    return adjacencyList;
}

/**
 * @brief Convert adjacency matrix to adjacency list
 * @param matrixData Matrix data as 2D vector
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyList structure containing the converted data
 */
AdjacencyList convertMatrixToAdjacencyList(const std::vector<std::vector<int>>& matrixData, 
                                          int numberOfVertices) {
    AdjacencyList adjacencyList;
    adjacencyList.numberOfVertices = numberOfVertices;
    adjacencyList.adjacencyData.resize(numberOfVertices);
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex = 0; targetVertex < numberOfVertices; ++targetVertex) {
            int edgeCount = matrixData[sourceVertex][targetVertex];
            for (int edgeInstance = 0; edgeInstance < edgeCount; ++edgeInstance) {
                adjacencyList.adjacencyData[sourceVertex].push_back(targetVertex);
            }
        }
    }
    
    return adjacencyList;
}

/**
 * @brief Display adjacency list to console
 * @param adjacencyList The adjacency list to display
 */
void displayAdjacencyList(const AdjacencyList& adjacencyList) {
    std::cout << "=== Adjacency List ===" << std::endl;
    std::cout << "Number of vertices: " << adjacencyList.numberOfVertices << std::endl;
    
    for (int vertexIndex = 0; vertexIndex < adjacencyList.numberOfVertices; ++vertexIndex) {
        std::cout << "Vertex " << vertexIndex << ": ";
        if (adjacencyList.adjacencyData[vertexIndex].empty()) {
            std::cout << "(no outgoing edges)";
        } else {
            for (int neighborIndex = 0; neighborIndex < static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size()); ++neighborIndex) {
                std::cout << adjacencyList.adjacencyData[vertexIndex][neighborIndex];
                if (neighborIndex < static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size()) - 1) {
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
    
    outputFile << "=== Adjacency List ===" << std::endl;
    outputFile << "Number of vertices: " << adjacencyList.numberOfVertices << std::endl;
    
    for (int vertexIndex = 0; vertexIndex < adjacencyList.numberOfVertices; ++vertexIndex) {
        outputFile << "Vertex " << vertexIndex << ": ";
        if (adjacencyList.adjacencyData[vertexIndex].empty()) {
            outputFile << "(no outgoing edges)";
        } else {
            for (int neighborIndex = 0; neighborIndex < static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size()); ++neighborIndex) {
                outputFile << adjacencyList.adjacencyData[vertexIndex][neighborIndex];
                if (neighborIndex < static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size()) - 1) {
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
 * @brief Convert extended adjacency list to adjacency list
 * @param outgoingEdgeIndices Outgoing edge indices from extended list
 * @param edgeInstances Edge instances from extended list
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyList structure containing the converted data
 */
AdjacencyList convertExtendedAdjacencyListToList(const std::vector<std::vector<int>>& outgoingEdgeIndices,
                                                const std::vector<std::pair<int, int>>& edgeInstances,
                                                int numberOfVertices) {
    AdjacencyList adjacencyList;
    adjacencyList.numberOfVertices = numberOfVertices;
    adjacencyList.adjacencyData.resize(numberOfVertices);
    
    for (int vertexIndex = 0; vertexIndex < numberOfVertices; ++vertexIndex) {
        for (int edgeIndex : outgoingEdgeIndices[vertexIndex]) {
            int targetVertex = edgeInstances[edgeIndex].second;
            adjacencyList.adjacencyData[vertexIndex].push_back(targetVertex);
        }
    }
    
    return adjacencyList;
}

/**
 * @brief Convert adjacency map to adjacency list
 * @param outgoingConnections Outgoing connections from adjacency map
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyList structure containing the converted data
 */
AdjacencyList convertAdjacencyMapToList(const std::map<int, std::vector<std::pair<int, std::pair<int, int>>>>& outgoingConnections,
                                       int numberOfVertices) {
    AdjacencyList adjacencyList;
    adjacencyList.numberOfVertices = numberOfVertices;
    adjacencyList.adjacencyData.resize(numberOfVertices);
    
    for (const auto& vertexPair : outgoingConnections) {
        int sourceVertex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        for (const auto& connection : connections) {
            int targetVertex = connection.first;
            adjacencyList.adjacencyData[sourceVertex].push_back(targetVertex);
        }
    }
    
    return adjacencyList;
}

/**
 * @brief Count total number of edges in adjacency list
 * @param adjacencyList The adjacency list to analyze
 * @return Total number of edge instances
 */
int countTotalEdgesInAdjacencyList(const AdjacencyList& adjacencyList) {
    int totalEdges = 0;
    for (int vertexIndex = 0; vertexIndex < adjacencyList.numberOfVertices; ++vertexIndex) {
        totalEdges += static_cast<int>(adjacencyList.adjacencyData[vertexIndex].size());
    }
    return totalEdges;
} 