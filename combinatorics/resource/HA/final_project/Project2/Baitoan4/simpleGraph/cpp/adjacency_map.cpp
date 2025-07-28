#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

/**
 * @brief Structure to represent adjacency map for simple graph
 */
struct AdjacencyMap {
    std::map<int, std::vector<std::pair<int, std::pair<int, int>>>> outgoingConnections;
    std::map<int, std::vector<std::pair<int, std::pair<int, int>>>> incomingConnections;
    int numberOfVertices;
    int numberOfEdges;
    
    /**
     * @brief Default constructor
     */
    AdjacencyMap() : numberOfVertices(0), numberOfEdges(0) {}
    
    /**
     * @brief Constructor with vertex count
     * @param vertexCount Number of vertices in the graph
     */
    AdjacencyMap(int vertexCount) : numberOfVertices(vertexCount), numberOfEdges(0) {
        for (int i = 0; i < vertexCount; ++i) {
            outgoingConnections[i] = std::vector<std::pair<int, std::pair<int, int>>>();
            incomingConnections[i] = std::vector<std::pair<int, std::pair<int, int>>>();
        }
    }
};

/**
 * @brief Read adjacency map from edge list file for simple graph
 * @param fileName Name of input file containing edge list
 * @return AdjacencyMap structure containing the graph data
 */
AdjacencyMap readAdjacencyMapFromEdgeList(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        return AdjacencyMap();
    }
    
    int numberOfVertices, numberOfEdges;
    inputFile >> numberOfVertices >> numberOfEdges;
    
    AdjacencyMap adjacencyMap(numberOfVertices);
    std::set<std::pair<int, int>> existingEdges;
    int validEdgeCount = 0;
    int selfLoopCount = 0;
    int duplicateEdgeCount = 0;
    
    for (int edgeIndex = 0; edgeIndex < numberOfEdges; ++edgeIndex) {
        int sourceVertex, targetVertex;
        inputFile >> sourceVertex >> targetVertex;
        
        // Check for self-loops (not allowed in simple graph)
        if (sourceVertex == targetVertex) {
            selfLoopCount++;
            std::cout << "Warning: Self-loop detected (" << sourceVertex << "," << targetVertex 
                      << ") - Removing as simple graphs do not allow self-loops" << std::endl;
            continue;
        }
        
        // Check for duplicate edges (not allowed in simple graph)
        std::pair<int, int> edge = {sourceVertex, targetVertex};
        if (existingEdges.find(edge) != existingEdges.end()) {
            duplicateEdgeCount++;
            std::cout << "Warning: Duplicate edge detected (" << sourceVertex << "," << targetVertex 
                      << ") - Removing as simple graphs do not allow multiple edges" << std::endl;
            continue;
        }
        
        if (sourceVertex >= 0 && sourceVertex < numberOfVertices && 
            targetVertex >= 0 && targetVertex < numberOfVertices) {
            
            adjacencyMap.outgoingConnections[sourceVertex].push_back({targetVertex, {sourceVertex, targetVertex}});
            adjacencyMap.incomingConnections[targetVertex].push_back({sourceVertex, {sourceVertex, targetVertex}});
            existingEdges.insert(edge);
            validEdgeCount++;
        }
    }
    
    adjacencyMap.numberOfEdges = validEdgeCount;
    
    if (selfLoopCount > 0) {
        std::cout << "Total self-loops removed: " << selfLoopCount << std::endl;
    }
    if (duplicateEdgeCount > 0) {
        std::cout << "Total duplicate edges removed: " << duplicateEdgeCount << std::endl;
    }
    
    inputFile.close();
    return adjacencyMap;
}

/**
 * @brief Convert adjacency list to adjacency map with duplicate edge and self-loop removal
 * @param adjacencyData The adjacency list data
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMap structure containing the converted data
 */
AdjacencyMap convertAdjacencyListToMap(const std::vector<std::vector<int>>& adjacencyData, int numberOfVertices) {
    AdjacencyMap adjacencyMap(numberOfVertices);
    std::set<std::pair<int, int>> existingEdges;
    int validEdgeCount = 0;
    int selfLoopCount = 0;
    int duplicateEdgeCount = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex : adjacencyData[sourceVertex]) {
            // Skip self-loops
            if (sourceVertex == targetVertex) {
                selfLoopCount++;
                continue;
            }
            
            // Skip duplicate edges
            std::pair<int, int> edge = {sourceVertex, targetVertex};
            if (existingEdges.find(edge) != existingEdges.end()) {
                duplicateEdgeCount++;
                continue;
            }
            
            if (targetVertex >= 0 && targetVertex < numberOfVertices) {
                adjacencyMap.outgoingConnections[sourceVertex].push_back({targetVertex, {sourceVertex, targetVertex}});
                adjacencyMap.incomingConnections[targetVertex].push_back({sourceVertex, {sourceVertex, targetVertex}});
                existingEdges.insert(edge);
                validEdgeCount++;
            }
        }
    }
    
    adjacencyMap.numberOfEdges = validEdgeCount;
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to simple graph map" << std::endl;
    }
    if (duplicateEdgeCount > 0) {
        std::cout << "Warning: " << duplicateEdgeCount << " duplicate edges removed during conversion to simple graph map" << std::endl;
    }
    
    return adjacencyMap;
}

/**
 * @brief Convert extended adjacency list to adjacency map with duplicate edge and self-loop removal
 * @param outgoingEdgeIndices Outgoing edge indices per vertex
 * @param incomingEdgeIndices Incoming edge indices per vertex
 * @param edgeInstances All edge instances as (source, target) pairs
 * @param numberOfVertices Number of vertices in the graph
 * @param numberOfEdges Total number of edges
 * @return AdjacencyMap structure containing the converted data
 */
AdjacencyMap convertExtendedListToMap(const std::vector<std::vector<int>>& outgoingEdgeIndices,
                                     const std::vector<std::vector<int>>& incomingEdgeIndices,
                                     const std::vector<std::pair<int, int>>& edgeInstances,
                                     int numberOfVertices,
                                     int numberOfEdges) {
    AdjacencyMap adjacencyMap(numberOfVertices);
    std::set<std::pair<int, int>> existingEdges;
    int validEdgeCount = 0;
    int selfLoopCount = 0;
    int duplicateEdgeCount = 0;
    
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
                
                // Skip duplicate edges
                std::pair<int, int> edge = {sourceVertex, targetVertex};
                if (existingEdges.find(edge) != existingEdges.end()) {
                    duplicateEdgeCount++;
                    continue;
                }
                
                adjacencyMap.outgoingConnections[sourceVertex].push_back({targetVertex, {sourceVertex, targetVertex}});
                existingEdges.insert(edge);
                validEdgeCount++;
            }
        }
    }
    
    // Build incoming connections based on valid outgoing edges
    for (const auto& vertexPair : adjacencyMap.outgoingConnections) {
        int sourceVertex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        for (const auto& connection : connections) {
            int targetVertex = connection.first;
            adjacencyMap.incomingConnections[targetVertex].push_back({sourceVertex, {sourceVertex, targetVertex}});
        }
    }
    
    adjacencyMap.numberOfEdges = validEdgeCount;
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to simple graph map" << std::endl;
    }
    if (duplicateEdgeCount > 0) {
        std::cout << "Warning: " << duplicateEdgeCount << " duplicate edges removed during conversion to simple graph map" << std::endl;
    }
    
    return adjacencyMap;
}

/**
 * @brief Display adjacency map to console
 * @param adjacencyMap The adjacency map to display
 */
void displayAdjacencyMap(const AdjacencyMap& adjacencyMap) {
    std::cout << "=== Adjacency Map (SimpleGraph) ===" << std::endl;
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
    
    outputFile << "=== Adjacency Map (SimpleGraph) ===" << std::endl;
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
 * @brief Convert adjacency matrix to adjacency map with duplicate edge and self-loop removal
 * @param matrixData Matrix data as 2D vector
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMap structure containing the converted data
 */
AdjacencyMap convertMatrixToAdjacencyMap(const std::vector<std::vector<int>>& matrixData, int numberOfVertices) {
    AdjacencyMap adjacencyMap(numberOfVertices);
    int validEdgeCount = 0;
    int selfLoopCount = 0;
    int multipleEdgeCount = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex = 0; targetVertex < numberOfVertices; ++targetVertex) {
            int edgeCount = matrixData[sourceVertex][targetVertex];
            
            // Skip self-loops
            if (sourceVertex == targetVertex && edgeCount > 0) {
                selfLoopCount += edgeCount;
                continue;
            }
            
            // For simple graph, convert multiple edges to single edge
            if (edgeCount > 1) {
                multipleEdgeCount += (edgeCount - 1);
                adjacencyMap.outgoingConnections[sourceVertex].push_back({targetVertex, {sourceVertex, targetVertex}});
                adjacencyMap.incomingConnections[targetVertex].push_back({sourceVertex, {sourceVertex, targetVertex}});
                validEdgeCount++;
            } else if (edgeCount == 1) {
                adjacencyMap.outgoingConnections[sourceVertex].push_back({targetVertex, {sourceVertex, targetVertex}});
                adjacencyMap.incomingConnections[targetVertex].push_back({sourceVertex, {sourceVertex, targetVertex}});
                validEdgeCount++;
            }
        }
    }
    
    adjacencyMap.numberOfEdges = validEdgeCount;
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to simple graph map" << std::endl;
    }
    if (multipleEdgeCount > 0) {
        std::cout << "Warning: " << multipleEdgeCount << " multiple edges converted to single edges during conversion to simple graph map" << std::endl;
    }
    
    return adjacencyMap;
} 