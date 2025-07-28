#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

/**
 * @brief Structure to represent adjacency matrix for multigraph
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
 * @brief Read adjacency matrix from edge list file for multigraph
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
            adjacencyMatrix.matrixData[sourceVertex][targetVertex]++;
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Total self-loops removed: " << selfLoopCount << std::endl;
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
    
    for (int rowIndex = 0; rowIndex < numberOfVertices; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < numberOfVertices; ++columnIndex) {
            inputFile >> adjacencyMatrix.matrixData[rowIndex][columnIndex];
            
            // Check for self-loops on diagonal
            if (rowIndex == columnIndex && adjacencyMatrix.matrixData[rowIndex][columnIndex] > 0) {
                selfLoopCount += adjacencyMatrix.matrixData[rowIndex][columnIndex];
                std::cout << "Warning: Self-loop detected at vertex " << rowIndex 
                          << " with " << adjacencyMatrix.matrixData[rowIndex][columnIndex] 
                          << " edges - Removing as multigraphs do not allow self-loops" << std::endl;
                adjacencyMatrix.matrixData[rowIndex][columnIndex] = 0;
            }
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Total self-loops removed: " << selfLoopCount << std::endl;
    }
    
    inputFile.close();
    return adjacencyMatrix;
}

/**
 * @brief Display adjacency matrix to console
 * @param adjacencyMatrix The adjacency matrix to display
 */
void displayAdjacencyMatrix(const AdjacencyMatrix& adjacencyMatrix) {
    std::cout << "=== Adjacency Matrix (MultiGraph) ===" << std::endl;
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
    
    outputFile << "=== Adjacency Matrix (MultiGraph) ===" << std::endl;
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
 * @brief Convert adjacency list to adjacency matrix with self-loop removal
 * @param adjacencyData The adjacency list data
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMatrix structure containing the converted data
 */
AdjacencyMatrix convertAdjacencyListToMatrix(const std::vector<std::vector<int>>& adjacencyData, int numberOfVertices) {
    AdjacencyMatrix adjacencyMatrix(numberOfVertices);
    int selfLoopCount = 0;
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex : adjacencyData[sourceVertex]) {
            if (sourceVertex == targetVertex) {
                selfLoopCount++;
                continue; // Skip self-loops
            }
            if (targetVertex >= 0 && targetVertex < numberOfVertices) {
                adjacencyMatrix.matrixData[sourceVertex][targetVertex]++;
            }
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to multigraph matrix" << std::endl;
    }
    
    return adjacencyMatrix;
}

/**
 * @brief Convert extended adjacency list to adjacency matrix with self-loop removal
 * @param edgeInstances List of all edge instances as (source, target) pairs
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMatrix structure containing the converted data
 */
AdjacencyMatrix convertExtendedAdjacencyListToMatrix(const std::vector<std::pair<int, int>>& edgeInstances, int numberOfVertices) {
    AdjacencyMatrix adjacencyMatrix(numberOfVertices);
    int selfLoopCount = 0;
    
    for (const auto& edge : edgeInstances) {
        int sourceVertex = edge.first;
        int targetVertex = edge.second;
        
        if (sourceVertex == targetVertex) {
            selfLoopCount++;
            continue; // Skip self-loops
        }
        
        if (sourceVertex >= 0 && sourceVertex < numberOfVertices && 
            targetVertex >= 0 && targetVertex < numberOfVertices) {
            adjacencyMatrix.matrixData[sourceVertex][targetVertex]++;
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to multigraph matrix" << std::endl;
    }
    
    return adjacencyMatrix;
}

/**
 * @brief Convert adjacency map to adjacency matrix with self-loop removal
 * @param outgoingConnections Map of outgoing connections
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMatrix structure containing the converted data
 */
AdjacencyMatrix convertAdjacencyMapToMatrix(const std::map<int, std::vector<std::pair<int, std::pair<int, int>>>>& outgoingConnections, int numberOfVertices) {
    AdjacencyMatrix adjacencyMatrix(numberOfVertices);
    int selfLoopCount = 0;
    
    for (const auto& vertexPair : outgoingConnections) {
        int sourceVertex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        for (const auto& connection : connections) {
            int targetVertex = connection.first;
            
            if (sourceVertex == targetVertex) {
                selfLoopCount++;
                continue; // Skip self-loops
            }
            
            if (targetVertex >= 0 && targetVertex < numberOfVertices) {
                adjacencyMatrix.matrixData[sourceVertex][targetVertex]++;
            }
        }
    }
    
    if (selfLoopCount > 0) {
        std::cout << "Warning: " << selfLoopCount << " self-loops removed during conversion to multigraph matrix" << std::endl;
    }
    
    return adjacencyMatrix;
} 