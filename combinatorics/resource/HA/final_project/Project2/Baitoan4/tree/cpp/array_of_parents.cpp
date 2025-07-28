#include <vector>
#include <iostream>
#include <fstream>
#include <string>

const int NIL_VALUE = -1;

/**
 * @brief Structure to represent array of parents for tree
 */
struct ArrayOfParents {
    std::vector<int> parentArray;
    int numberOfNodes;
    int rootNode;
    
    /**
     * @brief Default constructor
     */
    ArrayOfParents() : numberOfNodes(0), rootNode(NIL_VALUE) {}
    
    /**
     * @brief Constructor with node count
     * @param nodeCount Number of nodes in the tree
     */
    ArrayOfParents(int nodeCount) : numberOfNodes(nodeCount), rootNode(NIL_VALUE) {
        parentArray.resize(nodeCount, NIL_VALUE);
    }
};

/**
 * @brief Read array of parents from input file
 * @param fileName Name of input file
 * @return ArrayOfParents structure containing the tree data
 */
ArrayOfParents readArrayOfParentsFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        return ArrayOfParents();
    }
    
    int numberOfNodes;
    inputFile >> numberOfNodes;
    
    ArrayOfParents arrayParents(numberOfNodes);
    
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        inputFile >> arrayParents.parentArray[nodeIndex];
        if (arrayParents.parentArray[nodeIndex] == NIL_VALUE) {
            arrayParents.rootNode = nodeIndex;
        }
    }
    
    inputFile.close();
    return arrayParents;
}

/**
 * @brief Display array of parents to console
 * @param arrayParents The array of parents to display
 */
void displayArrayOfParents(const ArrayOfParents& arrayParents) {
    std::cout << "=== Array of Parents ===" << std::endl;
    std::cout << "Number of nodes: " << arrayParents.numberOfNodes << std::endl;
    std::cout << "Root node: " << arrayParents.rootNode << std::endl;
    
    for (int nodeIndex = 0; nodeIndex < arrayParents.numberOfNodes; ++nodeIndex) {
        std::cout << "parent[" << nodeIndex << "] = " 
                  << (arrayParents.parentArray[nodeIndex] == NIL_VALUE ? "nil" : std::to_string(arrayParents.parentArray[nodeIndex])) 
                  << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Write array of parents to output file
 * @param arrayParents The array of parents to write
 * @param fileName Name of output file
 */
void writeArrayOfParentsToFile(const ArrayOfParents& arrayParents, const std::string& fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create file " << fileName << std::endl;
        return;
    }
    
    outputFile << "=== Array of Parents ===" << std::endl;
    outputFile << "Number of nodes: " << arrayParents.numberOfNodes << std::endl;
    outputFile << "Root node: " << arrayParents.rootNode << std::endl;
    
    for (int nodeIndex = 0; nodeIndex < arrayParents.numberOfNodes; ++nodeIndex) {
        outputFile << "parent[" << nodeIndex << "] = " 
                   << (arrayParents.parentArray[nodeIndex] == NIL_VALUE ? "nil" : std::to_string(arrayParents.parentArray[nodeIndex])) 
                   << std::endl;
    }
    
    outputFile.flush();
    outputFile.close();
}

/**
 * @brief Convert first-child next-sibling representation to array of parents
 * @param firstChildArray Array of first child pointers
 * @param nextSiblingArray Array of next sibling pointers
 * @param numberOfNodes Number of nodes in the tree
 * @return ArrayOfParents structure containing the converted data
 */
ArrayOfParents convertFirstChildNextSiblingToArrayParents(const std::vector<int>& firstChildArray, 
                                                         const std::vector<int>& nextSiblingArray, 
                                                         int numberOfNodes) {
    ArrayOfParents arrayParents(numberOfNodes);
    
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        int currentChild = firstChildArray[nodeIndex];
        while (currentChild != NIL_VALUE) {
            arrayParents.parentArray[currentChild] = nodeIndex;
            currentChild = nextSiblingArray[currentChild];
        }
    }
    
    // Find root node
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (arrayParents.parentArray[nodeIndex] == NIL_VALUE) {
            arrayParents.rootNode = nodeIndex;
            break;
        }
    }
    
    return arrayParents;
}

/**
 * @brief Convert graph-based representation to array of parents
 * @param adjacencyData Graph adjacency list representation
 * @param numberOfNodes Number of nodes in the tree
 * @return ArrayOfParents structure containing the converted data
 */
ArrayOfParents convertGraphBasedToArrayParents(const std::vector<std::vector<int>>& adjacencyData, 
                                              int numberOfNodes) {
    ArrayOfParents arrayParents(numberOfNodes);
    
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        for (int childNode : adjacencyData[nodeIndex]) {
            arrayParents.parentArray[childNode] = nodeIndex;
        }
    }
    
    // Find root node
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (arrayParents.parentArray[nodeIndex] == NIL_VALUE) {
            arrayParents.rootNode = nodeIndex;
            break;
        }
    }
    
    return arrayParents;
} 