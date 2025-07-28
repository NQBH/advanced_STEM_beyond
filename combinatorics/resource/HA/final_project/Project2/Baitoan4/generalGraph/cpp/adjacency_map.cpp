#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>

/**
 * @brief Structure to represent adjacency map for general graph
 */
struct AdjacencyMap {
    std::map<int, std::vector<std::pair<int, std::pair<int, int>>>> outgoingConnections;
    std::map<int, std::vector<std::pair<int, std::pair<int, int>>>> incomingConnections;
    int numberOfVertices;
    int numberOfEdges;
};

/**
 * @brief Read adjacency map from edge list format
 * @param fileName Name of input file containing edge list
 * @return AdjacencyMap structure containing the graph data
 */
AdjacencyMap readAdjacencyMapFromEdgeList(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        exit(1);
    }
    
    int numberOfVertices, numberOfEdges;
    inputFile >> numberOfVertices >> numberOfEdges;
    
    AdjacencyMap adjacencyMap;
    adjacencyMap.numberOfVertices = numberOfVertices;
    adjacencyMap.numberOfEdges = numberOfEdges;
    
    for (int edgeIndex = 0; edgeIndex < numberOfEdges; ++edgeIndex) {
        int sourceVertex, targetVertex;
        inputFile >> sourceVertex >> targetVertex;
        
        int canonicalMin = std::min(sourceVertex, targetVertex);
        int canonicalMax = std::max(sourceVertex, targetVertex);
        std::pair<int, int> canonicalEdge = {canonicalMin, canonicalMax};
        
        adjacencyMap.outgoingConnections[sourceVertex].push_back({targetVertex, canonicalEdge});
        adjacencyMap.incomingConnections[targetVertex].push_back({sourceVertex, canonicalEdge});
    }
    
    inputFile.close();
    return adjacencyMap;
}

/**
 * @brief Convert adjacency list to adjacency map
 * @param adjacencyData Adjacency list data
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMap structure containing the converted data
 */
AdjacencyMap convertAdjacencyListToMap(const std::vector<std::vector<int>>& adjacencyData, 
                                      int numberOfVertices) {
    AdjacencyMap adjacencyMap;
    adjacencyMap.numberOfVertices = numberOfVertices;
    
    int edgeCounter = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex : adjacencyData[sourceVertex]) {
            int canonicalMin = std::min(sourceVertex, targetVertex);
            int canonicalMax = std::max(sourceVertex, targetVertex);
            std::pair<int, int> canonicalEdge = {canonicalMin, canonicalMax};
            
            adjacencyMap.outgoingConnections[sourceVertex].push_back({targetVertex, canonicalEdge});
            adjacencyMap.incomingConnections[targetVertex].push_back({sourceVertex, canonicalEdge});
            ++edgeCounter;
        }
    }
    
    adjacencyMap.numberOfEdges = edgeCounter;
    return adjacencyMap;
}

/**
 * @brief Convert extended adjacency list to adjacency map
 * @param extendedList Extended adjacency list data
 * @return AdjacencyMap structure containing the converted data
 */
AdjacencyMap convertExtendedListToMap(const std::vector<std::vector<int>>& outgoingEdgeIndices,
                                     const std::vector<std::vector<int>>& incomingEdgeIndices,
                                     const std::vector<std::pair<int, int>>& edgeInstances,
                                     int numberOfVertices,
                                     int numberOfEdges) {
    AdjacencyMap adjacencyMap;
    adjacencyMap.numberOfVertices = numberOfVertices;
    adjacencyMap.numberOfEdges = numberOfEdges;
    
    for (int vertexIndex = 0; vertexIndex < numberOfVertices; ++vertexIndex) {
        for (int edgeIndex : outgoingEdgeIndices[vertexIndex]) {
            int sourceVertex = edgeInstances[edgeIndex].first;
            int targetVertex = edgeInstances[edgeIndex].second;
            
            int canonicalMin = std::min(sourceVertex, targetVertex);
            int canonicalMax = std::max(sourceVertex, targetVertex);
            std::pair<int, int> canonicalEdge = {canonicalMin, canonicalMax};
            
            adjacencyMap.outgoingConnections[sourceVertex].push_back({targetVertex, canonicalEdge});
        }
        
        for (int edgeIndex : incomingEdgeIndices[vertexIndex]) {
            int sourceVertex = edgeInstances[edgeIndex].first;
            int targetVertex = edgeInstances[edgeIndex].second;
            
            int canonicalMin = std::min(sourceVertex, targetVertex);
            int canonicalMax = std::max(sourceVertex, targetVertex);
            std::pair<int, int> canonicalEdge = {canonicalMin, canonicalMax};
            
            adjacencyMap.incomingConnections[targetVertex].push_back({sourceVertex, canonicalEdge});
        }
    }
    
    return adjacencyMap;
}

/**
 * @brief Display adjacency map to console
 * @param adjacencyMap The adjacency map to display
 */
void displayAdjacencyMap(const AdjacencyMap& adjacencyMap) {
    std::cout << "=== Adjacency Map ===" << std::endl;
    std::cout << "Number of vertices: " << adjacencyMap.numberOfVertices << std::endl;
    std::cout << "Number of edges: " << adjacencyMap.numberOfEdges << std::endl;
    
    std::cout << "\nOutgoing connections:" << std::endl;
    for (const auto& vertexPair : adjacencyMap.outgoingConnections) {
        int vertexIndex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        std::cout << "Vertex " << vertexIndex << " -> ";
        if (connections.empty()) {
            std::cout << "(no outgoing connections)";
        } else {
            for (int connectionIndex = 0; connectionIndex < static_cast<int>(connections.size()); ++connectionIndex) {
                const auto& connection = connections[connectionIndex];
                std::cout << connection.first << " [edge(" << connection.second.first 
                          << "," << connection.second.second << ")]";
                if (connectionIndex < static_cast<int>(connections.size()) - 1) {
                    std::cout << ", ";
                }
            }
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nIncoming connections:" << std::endl;
    for (const auto& vertexPair : adjacencyMap.incomingConnections) {
        int vertexIndex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        std::cout << "Vertex " << vertexIndex << " <- ";
        if (connections.empty()) {
            std::cout << "(no incoming connections)";
        } else {
            for (int connectionIndex = 0; connectionIndex < static_cast<int>(connections.size()); ++connectionIndex) {
                const auto& connection = connections[connectionIndex];
                std::cout << connection.first << " [edge(" << connection.second.first 
                          << "," << connection.second.second << ")]";
                if (connectionIndex < static_cast<int>(connections.size()) - 1) {
                    std::cout << ", ";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Write adjacency map to output file
 * @param adjacencyMap The adjacency map to write
 * @param fileName Name of output file
 */
void writeAdjacencyMapToFile(const AdjacencyMap& adjacencyMap, const std::string& fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create file " << fileName << std::endl;
        return;
    }
    
    outputFile << "=== Adjacency Map ===" << std::endl;
    outputFile << "Number of vertices: " << adjacencyMap.numberOfVertices << std::endl;
    outputFile << "Number of edges: " << adjacencyMap.numberOfEdges << std::endl;
    
    outputFile << "\nOutgoing connections:" << std::endl;
    for (const auto& vertexPair : adjacencyMap.outgoingConnections) {
        int vertexIndex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        outputFile << "Vertex " << vertexIndex << " -> ";
        if (connections.empty()) {
            outputFile << "(no outgoing connections)";
        } else {
            for (int connectionIndex = 0; connectionIndex < static_cast<int>(connections.size()); ++connectionIndex) {
                const auto& connection = connections[connectionIndex];
                outputFile << connection.first << " [edge(" << connection.second.first 
                           << "," << connection.second.second << ")]";
                if (connectionIndex < static_cast<int>(connections.size()) - 1) {
                    outputFile << ", ";
                }
            }
        }
        outputFile << std::endl;
    }
    
    outputFile << "\nIncoming connections:" << std::endl;
    for (const auto& vertexPair : adjacencyMap.incomingConnections) {
        int vertexIndex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        outputFile << "Vertex " << vertexIndex << " <- ";
        if (connections.empty()) {
            outputFile << "(no incoming connections)";
        } else {
            for (int connectionIndex = 0; connectionIndex < static_cast<int>(connections.size()); ++connectionIndex) {
                const auto& connection = connections[connectionIndex];
                outputFile << connection.first << " [edge(" << connection.second.first 
                           << "," << connection.second.second << ")]";
                if (connectionIndex < static_cast<int>(connections.size()) - 1) {
                    outputFile << ", ";
                }
            }
        }
        outputFile << std::endl;
    }
    
    outputFile.flush();
    outputFile.close();
}

/**
 * @brief Convert adjacency matrix to adjacency map
 * @param matrixData Matrix data as 2D vector
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMap structure containing the converted data
 */
AdjacencyMap convertMatrixToAdjacencyMap(const std::vector<std::vector<int>>& matrixData, 
                                        int numberOfVertices) {
    AdjacencyMap adjacencyMap;
    adjacencyMap.numberOfVertices = numberOfVertices;
    
    int edgeCounter = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex = 0; targetVertex < numberOfVertices; ++targetVertex) {
            int edgeCount = matrixData[sourceVertex][targetVertex];
            for (int edgeInstance = 0; edgeInstance < edgeCount; ++edgeInstance) {
                int canonicalMin = std::min(sourceVertex, targetVertex);
                int canonicalMax = std::max(sourceVertex, targetVertex);
                std::pair<int, int> canonicalEdge = {canonicalMin, canonicalMax};
                
                adjacencyMap.outgoingConnections[sourceVertex].push_back({targetVertex, canonicalEdge});
                adjacencyMap.incomingConnections[targetVertex].push_back({sourceVertex, canonicalEdge});
                ++edgeCounter;
            }
        }
    }
    
    adjacencyMap.numberOfEdges = edgeCounter;
    return adjacencyMap;
}

/**
 * @brief Convert adjacency map to extended adjacency list
 * @param outgoingConnections Outgoing connections from adjacency map
 * @param incomingConnections Incoming connections from adjacency map
 * @param numberOfVertices Number of vertices in the graph
 * @param numberOfEdges Number of edges in the graph
 * @return ExtendedAdjacencyList structure containing the converted data
 */
ExtendedAdjacencyList convertAdjacencyMapToExtended(const std::map<int, std::vector<std::pair<int, std::pair<int, int>>>>& outgoingConnections,
                                                   const std::map<int, std::vector<std::pair<int, std::pair<int, int>>>>& incomingConnections,
                                                   int numberOfVertices,
                                                   int numberOfEdges) {
    ExtendedAdjacencyList extendedList;
    extendedList.numberOfVertices = numberOfVertices;
    extendedList.numberOfEdges = numberOfEdges;
    extendedList.incomingEdgeIndices.resize(numberOfVertices);
    extendedList.outgoingEdgeIndices.resize(numberOfVertices);
    
    int edgeCounter = 0;
    
    // Build edge instances and indices from outgoing connections
    for (const auto& vertexPair : outgoingConnections) {
        int sourceVertex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        for (const auto& connection : connections) {
            int targetVertex = connection.first;
            extendedList.edgeInstances.push_back({sourceVertex, targetVertex});
            extendedList.outgoingEdgeIndices[sourceVertex].push_back(edgeCounter);
            extendedList.incomingEdgeIndices[targetVertex].push_back(edgeCounter);
            ++edgeCounter;
        }
    }
    
    return extendedList;
}