#include <iostream>
#include <vector>
#include <fstream>

/**
 * @brief Structure to represent extended adjacency list for general graph
 */
struct ExtendedAdjacencyList {
    std::vector<std::vector<int>> incomingEdgeIndices;
    std::vector<std::vector<int>> outgoingEdgeIndices;
    std::vector<std::pair<int, int>> edgeInstances;
    int numberOfVertices;
    int numberOfEdges;
};

/**
 * @brief Read extended adjacency list from edge list format
 * @param fileName Name of input file containing edge list
 * @return ExtendedAdjacencyList structure containing the graph data
 */
ExtendedAdjacencyList readExtendedAdjacencyListFromEdgeList(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        exit(1);
    }
    
    int numberOfVertices, numberOfEdges;
    inputFile >> numberOfVertices >> numberOfEdges;
    
    ExtendedAdjacencyList extendedList;
    extendedList.numberOfVertices = numberOfVertices;
    extendedList.numberOfEdges = numberOfEdges;
    extendedList.incomingEdgeIndices.resize(numberOfVertices);
    extendedList.outgoingEdgeIndices.resize(numberOfVertices);
    extendedList.edgeInstances.reserve(numberOfEdges);
    
    for (int edgeIndex = 0; edgeIndex < numberOfEdges; ++edgeIndex) {
        int sourceVertex, targetVertex;
        inputFile >> sourceVertex >> targetVertex;
        
        extendedList.edgeInstances.push_back({sourceVertex, targetVertex});
        extendedList.outgoingEdgeIndices[sourceVertex].push_back(edgeIndex);
        extendedList.incomingEdgeIndices[targetVertex].push_back(edgeIndex);
    }
    
    inputFile.close();
    return extendedList;
}

/**
 * @brief Convert adjacency list to extended adjacency list
 * @param adjacencyData Adjacency list data
 * @param numberOfVertices Number of vertices in the graph
 * @return ExtendedAdjacencyList structure containing the converted data
 */
ExtendedAdjacencyList convertAdjacencyListToExtended(const std::vector<std::vector<int>>& adjacencyData, 
                                                    int numberOfVertices) {
    ExtendedAdjacencyList extendedList;
    extendedList.numberOfVertices = numberOfVertices;
    extendedList.incomingEdgeIndices.resize(numberOfVertices);
    extendedList.outgoingEdgeIndices.resize(numberOfVertices);
    
    int edgeCounter = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex : adjacencyData[sourceVertex]) {
            extendedList.edgeInstances.push_back({sourceVertex, targetVertex});
            extendedList.outgoingEdgeIndices[sourceVertex].push_back(edgeCounter);
            extendedList.incomingEdgeIndices[targetVertex].push_back(edgeCounter);
            ++edgeCounter;
        }
    }
    
    extendedList.numberOfEdges = edgeCounter;
    return extendedList;
}

/**
 * @brief Convert adjacency matrix to extended adjacency list
 * @param matrixData Matrix data as 2D vector
 * @param numberOfVertices Number of vertices in the graph
 * @return ExtendedAdjacencyList structure containing the converted data
 */
ExtendedAdjacencyList convertMatrixToExtendedAdjacencyList(const std::vector<std::vector<int>>& matrixData, 
                                                          int numberOfVertices) {
    ExtendedAdjacencyList extendedList;
    extendedList.numberOfVertices = numberOfVertices;
    extendedList.incomingEdgeIndices.resize(numberOfVertices);
    extendedList.outgoingEdgeIndices.resize(numberOfVertices);
    
    int edgeCounter = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex = 0; targetVertex < numberOfVertices; ++targetVertex) {
            int edgeCount = matrixData[sourceVertex][targetVertex];
            for (int edgeInstance = 0; edgeInstance < edgeCount; ++edgeInstance) {
                extendedList.edgeInstances.push_back({sourceVertex, targetVertex});
                extendedList.outgoingEdgeIndices[sourceVertex].push_back(edgeCounter);
                extendedList.incomingEdgeIndices[targetVertex].push_back(edgeCounter);
                ++edgeCounter;
            }
        }
    }
    
    extendedList.numberOfEdges = edgeCounter;
    return extendedList;
}

/**
 * @brief Display extended adjacency list to console
 * @param extendedList The extended adjacency list to display
 */
void displayExtendedAdjacencyList(const ExtendedAdjacencyList& extendedList) {
    std::cout << "=== Extended Adjacency List ===" << std::endl;
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
            std::cout << "(none)";
        } else {
            for (int edgeIndexPosition = 0; edgeIndexPosition < static_cast<int>(extendedList.outgoingEdgeIndices[vertexIndex].size()); ++edgeIndexPosition) {
                std::cout << extendedList.outgoingEdgeIndices[vertexIndex][edgeIndexPosition];
                if (edgeIndexPosition < static_cast<int>(extendedList.outgoingEdgeIndices[vertexIndex].size()) - 1) {
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
            std::cout << "(none)";
        } else {
            for (int edgeIndexPosition = 0; edgeIndexPosition < static_cast<int>(extendedList.incomingEdgeIndices[vertexIndex].size()); ++edgeIndexPosition) {
                std::cout << extendedList.incomingEdgeIndices[vertexIndex][edgeIndexPosition];
                if (edgeIndexPosition < static_cast<int>(extendedList.incomingEdgeIndices[vertexIndex].size()) - 1) {
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
    
    outputFile << "=== Extended Adjacency List ===" << std::endl;
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
            outputFile << "(none)";
        } else {
            for (int edgeIndexPosition = 0; edgeIndexPosition < static_cast<int>(extendedList.outgoingEdgeIndices[vertexIndex].size()); ++edgeIndexPosition) {
                outputFile << extendedList.outgoingEdgeIndices[vertexIndex][edgeIndexPosition];
                if (edgeIndexPosition < static_cast<int>(extendedList.outgoingEdgeIndices[vertexIndex].size()) - 1) {
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
            outputFile << "(none)";
        } else {
            for (int edgeIndexPosition = 0; edgeIndexPosition < static_cast<int>(extendedList.incomingEdgeIndices[vertexIndex].size()); ++edgeIndexPosition) {
                outputFile << extendedList.incomingEdgeIndices[vertexIndex][edgeIndexPosition];
                if (edgeIndexPosition < static_cast<int>(extendedList.incomingEdgeIndices[vertexIndex].size()) - 1) {
                    outputFile << " ";
                }
            }
        }
        outputFile << std::endl;
    }
    
    outputFile.flush();
    outputFile.close();
} 