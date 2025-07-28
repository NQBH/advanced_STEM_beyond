#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

/**
 * @brief Structure to represent extended adjacency list for multigraph
 */
struct ExtendedAdjacencyList {
    std::vector<std::pair<int, int>> edgeInstances;
    std::vector<std::vector<int>> outgoingEdgeIndices;
    std::vector<std::vector<int>> incomingEdgeIndices;
    int numberOfVertices;
    int numberOfEdges;
    
    /**
     * @brief Default constructor
     */
    ExtendedAdjacencyList() : numberOfVertices(0), numberOfEdges(0) {}
    
    /**
     * @brief Constructor with vertex count
     * @param vertexCount Number of vertices in the graph
     */
    ExtendedAdjacencyList(int vertexCount) : numberOfVertices(vertexCount), numberOfEdges(0) {
        outgoingEdgeIndices.resize(vertexCount);
        incomingEdgeIndices.resize(vertexCount);
    }
};

/**
 * @brief Read extended adjacency list from edge list file for multigraph
 * @param fileName Name of input file containing edge list
 * @return ExtendedAdjacencyList structure containing the graph data
 */
ExtendedAdjacencyList readExtendedAdjacencyListFromEdgeList(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        return ExtendedAdjacencyList();
    }
    
    int numberOfVertices, numberOfEdges;
    inputFile >> numberOfVertices >> numberOfEdges;
    
    ExtendedAdjacencyList extendedList(numberOfVertices);
    int edgeCounter = 0;
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
            
            extendedList.edgeInstances.push_back({sourceVertex, targetVertex});
            extendedList.outgoingEdgeIndices[sourceVertex].push_back(edgeCounter);
            extendedList.incomingEdgeIndices[targetVertex].push_back(edgeCounter);
            edgeCounter++;
        }
    }
    
    extendedList.numberOfEdges = edgeCounter;
    
    if (selfLoopCount > 0) {
        std::cout << "Total self-loops removed: " << selfLoopCount << std::endl;
    }
    
    inputFile.close();
    return extendedList;
}

/**
 * @brief Convert adjacency list to extended adjacency list with self-loop removal
 * @param adjacencyData The adjacency list data
 * @param numberOfVertices Number of vertices in the graph
 * @return ExtendedAdjacencyList structure containing the converted data
 */
ExtendedAdjacencyList convertAdjacencyListToExtended(const std::vector<std::vector<int>>& adjacencyData, int numberOfVertices) {
    ExtendedAdjacencyList extendedList(numberOfVertices);
    int edgeCounter = 0;
    int selfLoopCount = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex : adjacencyData[sourceVertex]) {
            // Skip self-loops
            if (sourceVertex == targetVertex) {
                selfLoopCount++;
                continue;
            }
            
            if (targetVertex >= 0 && targetVertex < numberOfVertices) {
                extendedList.edgeInstances.push_back({sourceVertex, targetVertex});
                extendedList.outgoingEdgeIndices[sourceVertex].push_back(edgeCounter);
                extendedList.incomingEdgeIndices[targetVertex].push_back(edgeCounter);
                edgeCounter++;
            }
        }
    }
    
    extendedList.numberOfEdges = edgeCounter;
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to multigraph extended list" << std::endl;
    }
    
    return extendedList;
}

/**
 * @brief Convert adjacency matrix to extended adjacency list with self-loop removal
 * @param matrixData Matrix data as 2D vector
 * @param numberOfVertices Number of vertices in the graph
 * @return ExtendedAdjacencyList structure containing the converted data
 */
ExtendedAdjacencyList convertMatrixToExtendedAdjacencyList(const std::vector<std::vector<int>>& matrixData, int numberOfVertices) {
    ExtendedAdjacencyList extendedList(numberOfVertices);
    int edgeCounter = 0;
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
                extendedList.edgeInstances.push_back({sourceVertex, targetVertex});
                extendedList.outgoingEdgeIndices[sourceVertex].push_back(edgeCounter);
                extendedList.incomingEdgeIndices[targetVertex].push_back(edgeCounter);
                edgeCounter++;
            }
        }
    }
    
    extendedList.numberOfEdges = edgeCounter;
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to multigraph extended list" << std::endl;
    }
    
    return extendedList;
}

/**
 * @brief Display extended adjacency list to console
 * @param extendedList The extended adjacency list to display
 */
void displayExtendedAdjacencyList(const ExtendedAdjacencyList& extendedList) {
    std::cout << "=== Extended Adjacency List (MultiGraph) ===" << std::endl;
    std::cout << "Number of vertices: " << extendedList.numberOfVertices << std::endl;
    std::cout << "Number of edges: " << extendedList.numberOfEdges << std::endl;
    
    std::cout << "\nEdge instances:" << std::endl;
    for (int edgeIndex = 0; edgeIndex < extendedList.numberOfEdges; ++edgeIndex) {
        std::cout << "Edge " << edgeIndex << ": (" << extendedList.edgeInstances[edgeIndex].first 
                  << ", " << extendedList.edgeInstances[edgeIndex].second << ")" << std::endl;
    }
    
    std::cout << "\nOutgoing edges by vertex:" << std::endl;
    for (int vertexIndex = 0; vertexIndex < extendedList.numberOfVertices; ++vertexIndex) {
        std::cout << "Vertex " << vertexIndex << " outgoing: ";
        if (extendedList.outgoingEdgeIndices[vertexIndex].empty()) {
            std::cout << "(no outgoing edges)";
        } else {
            for (int edgeIndex = 0; edgeIndex < static_cast<int>(extendedList.outgoingEdgeIndices[vertexIndex].size()); ++edgeIndex) {
                std::cout << extendedList.outgoingEdgeIndices[vertexIndex][edgeIndex];
                if (edgeIndex < static_cast<int>(extendedList.outgoingEdgeIndices[vertexIndex].size()) - 1) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nIncoming edges by vertex:" << std::endl;
    for (int vertexIndex = 0; vertexIndex < extendedList.numberOfVertices; ++vertexIndex) {
        std::cout << "Vertex " << vertexIndex << " incoming: ";
        if (extendedList.incomingEdgeIndices[vertexIndex].empty()) {
            std::cout << "(no incoming edges)";
        } else {
            for (int edgeIndex = 0; edgeIndex < static_cast<int>(extendedList.incomingEdgeIndices[vertexIndex].size()); ++edgeIndex) {
                std::cout << extendedList.incomingEdgeIndices[vertexIndex][edgeIndex];
                if (edgeIndex < static_cast<int>(extendedList.incomingEdgeIndices[vertexIndex].size()) - 1) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Write extended adjacency list to output file
 * @param extendedList The extended adjacency list to write
 * @param fileName Name of output file
 */
void writeExtendedAdjacencyListToFile(const ExtendedAdjacencyList& extendedList, const std::string& fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create file " << fileName << std::endl;
        return;
    }
    
    outputFile << "=== Extended Adjacency List (MultiGraph) ===" << std::endl;
    outputFile << "Number of vertices: " << extendedList.numberOfVertices << std::endl;
    outputFile << "Number of edges: " << extendedList.numberOfEdges << std::endl;
    
    outputFile << "\nEdge instances:" << std::endl;
    for (int edgeIndex = 0; edgeIndex < extendedList.numberOfEdges; ++edgeIndex) {
        outputFile << "Edge " << edgeIndex << ": (" << extendedList.edgeInstances[edgeIndex].first 
                   << ", " << extendedList.edgeInstances[edgeIndex].second << ")" << std::endl;
    }
    
    outputFile << "\nOutgoing edges by vertex:" << std::endl;
    for (int vertexIndex = 0; vertexIndex < extendedList.numberOfVertices; ++vertexIndex) {
        outputFile << "Vertex " << vertexIndex << " outgoing: ";
        if (extendedList.outgoingEdgeIndices[vertexIndex].empty()) {
            outputFile << "(no outgoing edges)";
        } else {
            for (int edgeIndex = 0; edgeIndex < static_cast<int>(extendedList.outgoingEdgeIndices[vertexIndex].size()); ++edgeIndex) {
                outputFile << extendedList.outgoingEdgeIndices[vertexIndex][edgeIndex];
                if (edgeIndex < static_cast<int>(extendedList.outgoingEdgeIndices[vertexIndex].size()) - 1) {
                    outputFile << " ";
                }
            }
        }
        outputFile << std::endl;
    }
    
    outputFile << "\nIncoming edges by vertex:" << std::endl;
    for (int vertexIndex = 0; vertexIndex < extendedList.numberOfVertices; ++vertexIndex) {
        outputFile << "Vertex " << vertexIndex << " incoming: ";
        if (extendedList.incomingEdgeIndices[vertexIndex].empty()) {
            outputFile << "(no incoming edges)";
        } else {
            for (int edgeIndex = 0; edgeIndex < static_cast<int>(extendedList.incomingEdgeIndices[vertexIndex].size()); ++edgeIndex) {
                outputFile << extendedList.incomingEdgeIndices[vertexIndex][edgeIndex];
                if (edgeIndex < static_cast<int>(extendedList.incomingEdgeIndices[vertexIndex].size()) - 1) {
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
 * @brief Convert adjacency map to extended adjacency list with self-loop removal
 * @param outgoingConnections Map of outgoing connections
 * @param incomingConnections Map of incoming connections
 * @param numberOfVertices Number of vertices in the graph
 * @param numberOfEdges Total number of edges
 * @return ExtendedAdjacencyList structure containing the converted data
 */
ExtendedAdjacencyList convertAdjacencyMapToExtended(const std::map<int, std::vector<std::pair<int, std::pair<int, int>>>>& outgoingConnections,
                                                   const std::map<int, std::vector<std::pair<int, std::pair<int, int>>>>& incomingConnections,
                                                   int numberOfVertices,
                                                   int numberOfEdges) {
    ExtendedAdjacencyList extendedList(numberOfVertices);
    int edgeCounter = 0;
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
                extendedList.edgeInstances.push_back({sourceVertex, targetVertex});
                extendedList.outgoingEdgeIndices[sourceVertex].push_back(edgeCounter);
                extendedList.incomingEdgeIndices[targetVertex].push_back(edgeCounter);
                edgeCounter++;
            }
        }
    }
    
    extendedList.numberOfEdges = edgeCounter;
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to multigraph extended list" << std::endl;
    }
    
    return extendedList;
} 