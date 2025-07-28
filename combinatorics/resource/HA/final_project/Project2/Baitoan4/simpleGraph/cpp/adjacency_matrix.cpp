#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

/**
 * @brief Structure to represent adjacency matrix for simple graph
 */
struct AdjacencyMatrix {
    std::vector<std::vector<int>> matrixData;
    int numberOfVertices;
    
    /**
     * @brief Default constructor
     */
    AdjacencyMatrix() : numberOfVertices(0) {}
    
    /**
     * @brief Constructor with vertex count
     * @param vertexCount Number of vertices in the graph
     */
    AdjacencyMatrix(int vertexCount) : numberOfVertices(vertexCount) {
        matrixData.resize(vertexCount, std::vector<int>(vertexCount, 0));
    }
};

/**
 * @brief Read adjacency matrix from edge list file for simple graph
 * @param fileName Name of input file containing edge list
 * @return AdjacencyMatrix structure containing the graph data
 */
AdjacencyMatrix readAdjacencyMatrixFromEdgeList(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        return AdjacencyMatrix();
    }
    
    int numberOfVertices, numberOfEdges;
    inputFile >> numberOfVertices >> numberOfEdges;
    
    AdjacencyMatrix adjacencyMatrix(numberOfVertices);
    std::set<std::pair<int, int>> existingEdges;
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
            adjacencyMatrix.matrixData[sourceVertex][targetVertex] = 1;
            existingEdges.insert(edge);
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Total self-loops removed: " << selfLoopCount << std::endl;
    }
    if (duplicateEdgeCount > 0) {
        std::cout << "Total duplicate edges removed: " << duplicateEdgeCount << std::endl;
    }
    
    inputFile.close();
    return adjacencyMatrix;
}

/**
 * @brief Read adjacency matrix from matrix format file
 * @param fileName Name of input file containing matrix format
 * @return AdjacencyMatrix structure containing the graph data
 */
AdjacencyMatrix readAdjacencyMatrixFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        return AdjacencyMatrix();
    }
    
    int numberOfVertices;
    inputFile >> numberOfVertices;
    
    AdjacencyMatrix adjacencyMatrix(numberOfVertices);
    int selfLoopCount = 0;
    int multipleEdgeCount = 0;
    
    for (int rowIndex = 0; rowIndex < numberOfVertices; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < numberOfVertices; ++columnIndex) {
            int edgeValue;
            inputFile >> edgeValue;
            
            // Check for self-loops on diagonal
            if (rowIndex == columnIndex && edgeValue > 0) {
                selfLoopCount += edgeValue;
                std::cout << "Warning: Self-loop detected at vertex " << rowIndex 
                          << " - Removing as simple graphs do not allow self-loops" << std::endl;
                adjacencyMatrix.matrixData[rowIndex][columnIndex] = 0;
                continue;
            }
            
            // Check for multiple edges (value > 1)
            if (edgeValue > 1) {
                multipleEdgeCount += (edgeValue - 1);
                std::cout << "Warning: Multiple edges detected between (" << rowIndex << "," << columnIndex 
                          << ") with count " << edgeValue << " - Converting to single edge for simple graph" << std::endl;
                adjacencyMatrix.matrixData[rowIndex][columnIndex] = 1;
            } else {
                adjacencyMatrix.matrixData[rowIndex][columnIndex] = edgeValue;
            }
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Total self-loops removed: " << selfLoopCount << std::endl;
    }
    if (multipleEdgeCount > 0) {
        std::cout << "Total multiple edges converted to single edges: " << multipleEdgeCount << std::endl;
    }
    
    inputFile.close();
    return adjacencyMatrix;
}

/**
 * @brief Display adjacency matrix to console
 * @param adjacencyMatrix The adjacency matrix to display
 */
void displayAdjacencyMatrix(const AdjacencyMatrix& adjacencyMatrix) {
    std::cout << "=== Adjacency Matrix (SimpleGraph) ===" << std::endl;
    std::cout << "Number of vertices: " << adjacencyMatrix.numberOfVertices << std::endl;
    
    for (int rowIndex = 0; rowIndex < adjacencyMatrix.numberOfVertices; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < adjacencyMatrix.numberOfVertices; ++columnIndex) {
            std::cout << adjacencyMatrix.matrixData[rowIndex][columnIndex];
            if (columnIndex < adjacencyMatrix.numberOfVertices - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Write adjacency matrix to output file
 * @param adjacencyMatrix The adjacency matrix to write
 * @param fileName Name of output file
 */
void writeAdjacencyMatrixToFile(const AdjacencyMatrix& adjacencyMatrix, const std::string& fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create file " << fileName << std::endl;
        return;
    }
    
    outputFile << "=== Adjacency Matrix (SimpleGraph) ===" << std::endl;
    outputFile << "Number of vertices: " << adjacencyMatrix.numberOfVertices << std::endl;
    
    for (int rowIndex = 0; rowIndex < adjacencyMatrix.numberOfVertices; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < adjacencyMatrix.numberOfVertices; ++columnIndex) {
            outputFile << adjacencyMatrix.matrixData[rowIndex][columnIndex];
            if (columnIndex < adjacencyMatrix.numberOfVertices - 1) {
                outputFile << " ";
            }
        }
        outputFile << std::endl;
    }
    
    outputFile.flush();
    outputFile.close();
}

/**
 * @brief Convert adjacency list to adjacency matrix with duplicate edge and self-loop removal
 * @param adjacencyData The adjacency list data
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMatrix structure containing the converted data
 */
AdjacencyMatrix convertAdjacencyListToMatrix(const std::vector<std::vector<int>>& adjacencyData, int numberOfVertices) {
    AdjacencyMatrix adjacencyMatrix(numberOfVertices);
    int selfLoopCount = 0;
    int duplicateEdgeCount = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        std::set<int> connectedVertices;
        
        for (int targetVertex : adjacencyData[sourceVertex]) {
            if (sourceVertex == targetVertex) {
                selfLoopCount++;
                continue; // Skip self-loops
            }
            
            if (connectedVertices.find(targetVertex) != connectedVertices.end()) {
                duplicateEdgeCount++;
                continue; // Skip duplicate edges
            }
            
            if (targetVertex >= 0 && targetVertex < numberOfVertices) {
                adjacencyMatrix.matrixData[sourceVertex][targetVertex] = 1;
                connectedVertices.insert(targetVertex);
            }
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to simple graph matrix" << std::endl;
    }
    if (duplicateEdgeCount > 0) {
        std::cout << "Warning: " << duplicateEdgeCount << " duplicate edges removed during conversion to simple graph matrix" << std::endl;
    }
    
    return adjacencyMatrix;
}

/**
 * @brief Convert extended adjacency list to adjacency matrix with duplicate edge and self-loop removal
 * @param edgeInstances List of all edge instances as (source, target) pairs
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMatrix structure containing the converted data
 */
AdjacencyMatrix convertExtendedAdjacencyListToMatrix(const std::vector<std::pair<int, int>>& edgeInstances, int numberOfVertices) {
    AdjacencyMatrix adjacencyMatrix(numberOfVertices);
    std::set<std::pair<int, int>> existingEdges;
    int selfLoopCount = 0;
    int duplicateEdgeCount = 0;
    
    for (const auto& edge : edgeInstances) {
        int sourceVertex = edge.first;
        int targetVertex = edge.second;
        
        if (sourceVertex == targetVertex) {
            selfLoopCount++;
            continue; // Skip self-loops
        }
        
        if (existingEdges.find(edge) != existingEdges.end()) {
            duplicateEdgeCount++;
            continue; // Skip duplicate edges
        }
        
        if (sourceVertex >= 0 && sourceVertex < numberOfVertices && 
            targetVertex >= 0 && targetVertex < numberOfVertices) {
            adjacencyMatrix.matrixData[sourceVertex][targetVertex] = 1;
            existingEdges.insert(edge);
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to simple graph matrix" << std::endl;
    }
    if (duplicateEdgeCount > 0) {
        std::cout << "Warning: " << duplicateEdgeCount << " duplicate edges removed during conversion to simple graph matrix" << std::endl;
    }
    
    return adjacencyMatrix;
}

/**
 * @brief Convert adjacency map to adjacency matrix with duplicate edge and self-loop removal
 * @param outgoingConnections Map of outgoing connections
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMatrix structure containing the converted data
 */
AdjacencyMatrix convertAdjacencyMapToMatrix(const std::map<int, std::vector<std::pair<int, std::pair<int, int>>>>& outgoingConnections, int numberOfVertices) {
    AdjacencyMatrix adjacencyMatrix(numberOfVertices);
    std::set<std::pair<int, int>> existingEdges;
    int selfLoopCount = 0;
    int duplicateEdgeCount = 0;
    
    for (const auto& vertexPair : outgoingConnections) {
        int sourceVertex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        for (const auto& connection : connections) {
            int targetVertex = connection.first;
            
            if (sourceVertex == targetVertex) {
                selfLoopCount++;
                continue; // Skip self-loops
            }
            
            std::pair<int, int> edge = {sourceVertex, targetVertex};
            if (existingEdges.find(edge) != existingEdges.end()) {
                duplicateEdgeCount++;
                continue; // Skip duplicate edges
            }
            
            if (targetVertex >= 0 && targetVertex < numberOfVertices) {
                adjacencyMatrix.matrixData[sourceVertex][targetVertex] = 1;
                existingEdges.insert(edge);
            }
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to simple graph matrix" << std::endl;
    }
    if (duplicateEdgeCount > 0) {
        std::cout << "Warning: " << duplicateEdgeCount << " duplicate edges removed during conversion to simple graph matrix" << std::endl;
    }
    
    return adjacencyMatrix;
} 