#include <vector>
#include <iostream>
#include <fstream>
#include <string>

extern const int NIL_VALUE; // Use the constant from array_of_parents.cpp

/**
 * @brief Structure to represent graph-based representation for tree
 */
struct GraphBasedRepresentation {
    std::vector<std::vector<int>> adjacencyData;
    int numberOfNodes;
    int rootNode;
    
    /**
     * @brief Default constructor
     */
    GraphBasedRepresentation() : numberOfNodes(0), rootNode(NIL_VALUE) {}
    
    /**
     * @brief Constructor with node count
     * @param nodeCount Number of nodes in the tree
     */
    GraphBasedRepresentation(int nodeCount) : numberOfNodes(nodeCount), rootNode(NIL_VALUE) {
        adjacencyData.resize(nodeCount);
    }
};

/**
 * @brief Read graph-based representation from input file
 * @param fileName Name of input file
 * @return GraphBasedRepresentation structure containing the tree data
 */
GraphBasedRepresentation readGraphBasedRepresentationFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        return GraphBasedRepresentation();
    }
    
    int numberOfNodes;
    inputFile >> numberOfNodes;
    
    GraphBasedRepresentation graphTree(numberOfNodes);
    
    // Find root node (node that is not a child of any other node)
    std::vector<bool> isChild(numberOfNodes, false);
    
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        int degreeCount;
        inputFile >> degreeCount;
        graphTree.adjacencyData[nodeIndex].resize(degreeCount);
        
        for (int childIndex = 0; childIndex < degreeCount; ++childIndex) {
            inputFile >> graphTree.adjacencyData[nodeIndex][childIndex];
            isChild[graphTree.adjacencyData[nodeIndex][childIndex]] = true;
        }
    }
    
    // Find root node
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (!isChild[nodeIndex]) {
            graphTree.rootNode = nodeIndex;
            break;
        }
    }
    
    inputFile.close();
    return graphTree;
}

/**
 * @brief Display graph-based representation to console
 * @param graphTree The graph-based representation to display
 */
void displayGraphBasedRepresentation(const GraphBasedRepresentation& graphTree) {
    std::cout << "=== Graph-Based Representation (Adjacency List) ===" << std::endl;
    std::cout << "Number of nodes: " << graphTree.numberOfNodes << std::endl;
    std::cout << "Root node: " << graphTree.rootNode << std::endl;
    
    for (int nodeIndex = 0; nodeIndex < graphTree.numberOfNodes; ++nodeIndex) {
        std::cout << nodeIndex << ": ";
        if (graphTree.adjacencyData[nodeIndex].empty()) {
            std::cout << "(no children)";
        } else {
            for (int childIndex = 0; childIndex < static_cast<int>(graphTree.adjacencyData[nodeIndex].size()); ++childIndex) {
                std::cout << graphTree.adjacencyData[nodeIndex][childIndex];
                if (childIndex < static_cast<int>(graphTree.adjacencyData[nodeIndex].size()) - 1) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Write graph-based representation to output file
 * @param graphTree The graph-based representation to write
 * @param fileName Name of output file
 */
void writeGraphBasedRepresentationToFile(const GraphBasedRepresentation& graphTree, const std::string& fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create file " << fileName << std::endl;
        return;
    }
    
    outputFile << "=== Graph-Based Representation (Adjacency List) ===" << std::endl;
    outputFile << "Number of nodes: " << graphTree.numberOfNodes << std::endl;
    outputFile << "Root node: " << graphTree.rootNode << std::endl;
    
    for (int nodeIndex = 0; nodeIndex < graphTree.numberOfNodes; ++nodeIndex) {
        outputFile << nodeIndex << ": ";
        if (graphTree.adjacencyData[nodeIndex].empty()) {
            outputFile << "(no children)";
        } else {
            for (int childIndex = 0; childIndex < static_cast<int>(graphTree.adjacencyData[nodeIndex].size()); ++childIndex) {
                outputFile << graphTree.adjacencyData[nodeIndex][childIndex];
                if (childIndex < static_cast<int>(graphTree.adjacencyData[nodeIndex].size()) - 1) {
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
 * @brief Convert array of parents to graph-based representation
 * @param parentArray Array of parent pointers
 * @param numberOfNodes Number of nodes in the tree
 * @return GraphBasedRepresentation structure containing the converted data
 */
GraphBasedRepresentation convertArrayParentsToGraphBased(const std::vector<int>& parentArray, 
                                                        int numberOfNodes) {
    GraphBasedRepresentation graphTree(numberOfNodes);
    
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (parentArray[nodeIndex] != NIL_VALUE) {
            graphTree.adjacencyData[parentArray[nodeIndex]].push_back(nodeIndex);
        } else {
            graphTree.rootNode = nodeIndex;
        }
    }
    
    return graphTree;
}

/**
 * @brief Convert first-child next-sibling to graph-based representation
 * @param firstChildArray Array of first child pointers
 * @param nextSiblingArray Array of next sibling pointers
 * @param numberOfNodes Number of nodes in the tree
 * @return GraphBasedRepresentation structure containing the converted data
 */
GraphBasedRepresentation convertFirstChildNextSiblingToGraphBased(const std::vector<int>& firstChildArray, 
                                                                 const std::vector<int>& nextSiblingArray, 
                                                                 int numberOfNodes) {
    GraphBasedRepresentation graphTree(numberOfNodes);
    
    // Find root node (node that is not a child of any other node)
    std::vector<bool> isChild(numberOfNodes, false);
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (firstChildArray[nodeIndex] != NIL_VALUE) {
            // Mark first child as a child
            isChild[firstChildArray[nodeIndex]] = true;
            
            // Mark all siblings in the chain as children
            int currentSibling = firstChildArray[nodeIndex];
            while (currentSibling != NIL_VALUE) {
                isChild[currentSibling] = true;
                currentSibling = nextSiblingArray[currentSibling];
            }
        }
    }
    
    // Find root node
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (!isChild[nodeIndex]) {
            graphTree.rootNode = nodeIndex;
            break;
        }
    }
    
    // Convert first-child next-sibling to adjacency list
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        int currentChild = firstChildArray[nodeIndex];
        while (currentChild != NIL_VALUE) {
            graphTree.adjacencyData[nodeIndex].push_back(currentChild);
            currentChild = nextSiblingArray[currentChild];
        }
    }
    
    return graphTree;
} 