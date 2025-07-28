#include <vector>
#include <iostream>
#include <fstream>
#include <string>

extern const int NIL_VALUE; // Use the constant from array_of_parents.cpp

/**
 * @brief Structure to represent first-child next-sibling for tree
 */
struct FirstChildNextSibling {
    std::vector<int> firstChildArray;
    std::vector<int> nextSiblingArray;
    int numberOfNodes;
    int rootNode;
    
    /**
     * @brief Default constructor
     */
    FirstChildNextSibling() : numberOfNodes(0), rootNode(NIL_VALUE) {}
    
    /**
     * @brief Constructor with node count
     * @param nodeCount Number of nodes in the tree
     */
    FirstChildNextSibling(int nodeCount) : numberOfNodes(nodeCount), rootNode(NIL_VALUE) {
        firstChildArray.resize(nodeCount, NIL_VALUE);
        nextSiblingArray.resize(nodeCount, NIL_VALUE);
    }
};

/**
 * @brief Read first-child next-sibling from input file
 * @param fileName Name of input file
 * @return FirstChildNextSibling structure containing the tree data
 */
FirstChildNextSibling readFirstChildNextSiblingFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file " << fileName << std::endl;
        return FirstChildNextSibling();
    }
    
    int numberOfNodes;
    inputFile >> numberOfNodes;
    
    FirstChildNextSibling fcnsTree(numberOfNodes);
    
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        inputFile >> fcnsTree.firstChildArray[nodeIndex] >> fcnsTree.nextSiblingArray[nodeIndex];
    }
    
    // Find root node (node that is not a child or sibling of any other node)
    std::vector<bool> isChildOrSibling(numberOfNodes, false);
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (fcnsTree.firstChildArray[nodeIndex] != NIL_VALUE) {
            isChildOrSibling[fcnsTree.firstChildArray[nodeIndex]] = true;
        }
        if (fcnsTree.nextSiblingArray[nodeIndex] != NIL_VALUE) {
            isChildOrSibling[fcnsTree.nextSiblingArray[nodeIndex]] = true;
        }
    }
    
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (!isChildOrSibling[nodeIndex]) {
            fcnsTree.rootNode = nodeIndex;
            break;
        }
    }
    
    inputFile.close();
    return fcnsTree;
}

/**
 * @brief Display first-child next-sibling to console
 * @param fcnsTree The first-child next-sibling structure to display
 */
void displayFirstChildNextSibling(const FirstChildNextSibling& fcnsTree) {
    std::cout << "=== First-Child Next-Sibling Representation ===" << std::endl;
    std::cout << "Number of nodes: " << fcnsTree.numberOfNodes << std::endl;
    std::cout << "Root node: " << fcnsTree.rootNode << std::endl;
    
    for (int nodeIndex = 0; nodeIndex < fcnsTree.numberOfNodes; ++nodeIndex) {
        std::cout << "F[" << nodeIndex << "] = " 
                  << (fcnsTree.firstChildArray[nodeIndex] == NIL_VALUE ? "nil" : std::to_string(fcnsTree.firstChildArray[nodeIndex]))
                  << ", N[" << nodeIndex << "] = "
                  << (fcnsTree.nextSiblingArray[nodeIndex] == NIL_VALUE ? "nil" : std::to_string(fcnsTree.nextSiblingArray[nodeIndex]))
                  << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Write first-child next-sibling to output file
 * @param fcnsTree The first-child next-sibling structure to write
 * @param fileName Name of output file
 */
void writeFirstChildNextSiblingToFile(const FirstChildNextSibling& fcnsTree, const std::string& fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create file " << fileName << std::endl;
        return;
    }
    
    outputFile << "=== First-Child Next-Sibling Representation ===" << std::endl;
    outputFile << "Number of nodes: " << fcnsTree.numberOfNodes << std::endl;
    outputFile << "Root node: " << fcnsTree.rootNode << std::endl;
    
    for (int nodeIndex = 0; nodeIndex < fcnsTree.numberOfNodes; ++nodeIndex) {
        outputFile << "F[" << nodeIndex << "] = " 
                   << (fcnsTree.firstChildArray[nodeIndex] == NIL_VALUE ? "nil" : std::to_string(fcnsTree.firstChildArray[nodeIndex]))
                   << ", N[" << nodeIndex << "] = "
                   << (fcnsTree.nextSiblingArray[nodeIndex] == NIL_VALUE ? "nil" : std::to_string(fcnsTree.nextSiblingArray[nodeIndex]))
                   << std::endl;
    }
    
    outputFile.flush();
    outputFile.close();
}

/**
 * @brief Convert array of parents to first-child next-sibling representation
 * @param parentArray Array of parent pointers
 * @param numberOfNodes Number of nodes in the tree
 * @return FirstChildNextSibling structure containing the converted data
 */
FirstChildNextSibling convertArrayParentsToFirstChildNextSibling(const std::vector<int>& parentArray, 
                                                                int numberOfNodes) {
    FirstChildNextSibling fcnsTree(numberOfNodes);
    
    // Build children lists for each node
    std::vector<std::vector<int>> childrenLists(numberOfNodes);
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (parentArray[nodeIndex] != NIL_VALUE) {
            childrenLists[parentArray[nodeIndex]].push_back(nodeIndex);
        } else {
            fcnsTree.rootNode = nodeIndex;
        }
    }
    
    // Convert children lists to first-child next-sibling representation
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (!childrenLists[nodeIndex].empty()) {
            fcnsTree.firstChildArray[nodeIndex] = childrenLists[nodeIndex][0];
            for (int childIndex = 0; childIndex + 1 < static_cast<int>(childrenLists[nodeIndex].size()); ++childIndex) {
                fcnsTree.nextSiblingArray[childrenLists[nodeIndex][childIndex]] = childrenLists[nodeIndex][childIndex + 1];
            }
        }
    }
    
    return fcnsTree;
}

/**
 * @brief Convert graph-based representation to first-child next-sibling
 * @param adjacencyData Graph adjacency list representation
 * @param numberOfNodes Number of nodes in the tree
 * @return FirstChildNextSibling structure containing the converted data
 */
FirstChildNextSibling convertGraphBasedToFirstChildNextSibling(const std::vector<std::vector<int>>& adjacencyData, 
                                                              int numberOfNodes) {
    FirstChildNextSibling fcnsTree(numberOfNodes);
    
    // Find root node (node that is not a child of any other node)
    std::vector<bool> isChild(numberOfNodes, false);
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        for (int childNode : adjacencyData[nodeIndex]) {
            isChild[childNode] = true;
        }
    }
    
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (!isChild[nodeIndex]) {
            fcnsTree.rootNode = nodeIndex;
            break;
        }
    }
    
    // Convert adjacency list to first-child next-sibling representation
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; ++nodeIndex) {
        if (!adjacencyData[nodeIndex].empty()) {
            fcnsTree.firstChildArray[nodeIndex] = adjacencyData[nodeIndex][0];
            for (int childIndex = 0; childIndex + 1 < static_cast<int>(adjacencyData[nodeIndex].size()); ++childIndex) {
                fcnsTree.nextSiblingArray[adjacencyData[nodeIndex][childIndex]] = adjacencyData[nodeIndex][childIndex + 1];
            }
        }
    }
    
    return fcnsTree;
} 