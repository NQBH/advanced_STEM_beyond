#include <iostream>
#include <vector>
#include <fstream>
#include <map>

/**
 * @brief Structure to represent adjacency matrix for general graph
 */
struct AdjacencyMatrix {
    std::vector<std::vector<int>> matrixData;
    int numberOfVertices;
};

/**
 * @brief Read adjacency matrix from input file
 * @param fileName Name of input file
 * @return AdjacencyMatrix structure containing the graph data
 */
AdjacencyMatrix readAdjacencyMatrixFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        exit(1);
    }
    
    AdjacencyMatrix adjacencyMatrix;
    inputFile >> adjacencyMatrix.numberOfVertices;
    
    adjacencyMatrix.matrixData.resize(adjacencyMatrix.numberOfVertices, 
                                     std::vector<int>(adjacencyMatrix.numberOfVertices, 0));
    
    for (int rowIndex = 0; rowIndex < adjacencyMatrix.numberOfVertices; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < adjacencyMatrix.numberOfVertices; ++columnIndex) {
            inputFile >> adjacencyMatrix.matrixData[rowIndex][columnIndex];
        }
    }
    
    inputFile.close();
    return adjacencyMatrix;
}

/**
 * @brief Read adjacency matrix from edge list format
 * @param fileName Name of input file containing edge list
 * @return AdjacencyMatrix structure containing the graph data
 */
AdjacencyMatrix readAdjacencyMatrixFromEdgeList(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        exit(1);
    }
    
    int numberOfVertices, numberOfEdges;
    inputFile >> numberOfVertices >> numberOfEdges;
    
    AdjacencyMatrix adjacencyMatrix;
    adjacencyMatrix.numberOfVertices = numberOfVertices;
    adjacencyMatrix.matrixData.resize(numberOfVertices, std::vector<int>(numberOfVertices, 0));
    
    for (int edgeIndex = 0; edgeIndex < numberOfEdges; ++edgeIndex) {
        int sourceVertex, targetVertex;
        inputFile >> sourceVertex >> targetVertex;
        ++adjacencyMatrix.matrixData[sourceVertex][targetVertex];
    }
    
    inputFile.close();
    return adjacencyMatrix;
}

/**
 * @brief Display adjacency matrix to console
 * @param adjacencyMatrix The adjacency matrix to display
 */
void displayAdjacencyMatrix(const AdjacencyMatrix& adjacencyMatrix) {
    std::cout << "=== Adjacency Matrix ===" << std::endl;
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
    
    outputFile << "=== Adjacency Matrix ===" << std::endl;
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
 * @brief Convert adjacency list to adjacency matrix
 * @param adjacencyData Adjacency list data
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMatrix structure containing the converted data
 */
AdjacencyMatrix convertAdjacencyListToMatrix(const std::vector<std::vector<int>>& adjacencyData,
                                            int numberOfVertices) {
    AdjacencyMatrix adjacencyMatrix;
    adjacencyMatrix.numberOfVertices = numberOfVertices;
    adjacencyMatrix.matrixData.resize(numberOfVertices, std::vector<int>(numberOfVertices, 0));
    
    for (int sourceVertex = 0; sourceVertex < numberOfVertices; ++sourceVertex) {
        for (int targetVertex : adjacencyData[sourceVertex]) {
            ++adjacencyMatrix.matrixData[sourceVertex][targetVertex];
        }
    }
    
    return adjacencyMatrix;
}

/**
 * @brief Convert extended adjacency list to adjacency matrix
 * @param edgeInstances Edge instances from extended list
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMatrix structure containing the converted data
 */
AdjacencyMatrix convertExtendedAdjacencyListToMatrix(const std::vector<std::pair<int, int>>& edgeInstances,
                                                    int numberOfVertices) {
    AdjacencyMatrix adjacencyMatrix;
    adjacencyMatrix.numberOfVertices = numberOfVertices;
    adjacencyMatrix.matrixData.resize(numberOfVertices, std::vector<int>(numberOfVertices, 0));
    
    for (const auto& edge : edgeInstances) {
        int sourceVertex = edge.first;
        int targetVertex = edge.second;
        ++adjacencyMatrix.matrixData[sourceVertex][targetVertex];
    }
    
    return adjacencyMatrix;
}

/**
 * @brief Convert adjacency map to adjacency matrix
 * @param outgoingConnections Outgoing connections from adjacency map
 * @param numberOfVertices Number of vertices in the graph
 * @return AdjacencyMatrix structure containing the converted data
 */
AdjacencyMatrix convertAdjacencyMapToMatrix(const std::map<int, std::vector<std::pair<int, std::pair<int, int>>>>& outgoingConnections,
                                           int numberOfVertices) {
    AdjacencyMatrix adjacencyMatrix;
    adjacencyMatrix.numberOfVertices = numberOfVertices;
    adjacencyMatrix.matrixData.resize(numberOfVertices, std::vector<int>(numberOfVertices, 0));
    
    for (const auto& vertexPair : outgoingConnections) {
        int sourceVertex = vertexPair.first;
        const auto& connections = vertexPair.second;
        
        for (const auto& connection : connections) {
            int targetVertex = connection.first;
            ++adjacencyMatrix.matrixData[sourceVertex][targetVertex];
        }
    }
    
    return adjacencyMatrix;
} 