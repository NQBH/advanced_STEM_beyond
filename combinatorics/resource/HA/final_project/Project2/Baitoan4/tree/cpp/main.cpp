#include "array_of_parents.cpp"
#include "first_child_next_sibling.cpp"
#include "graph_based_representation.cpp"
#include <iostream>
#include <fstream>

/**
 * @brief Demonstrate all tree representation conversions using input.txt
 */
void demonstrateTreeRepresentationConversions() {
    std::cout << "=== Tree Representation Conversions Demo ===" << std::endl;
    std::cout << "Testing all 6 conversion types for tree representations" << std::endl;
    std::cout << "Using input.txt for Array of Parents format" << std::endl << std::endl;
    
    // Read array of parents from input.txt
    ArrayOfParents arrayParents = readArrayOfParentsFromFile("input.txt");
    if (arrayParents.numberOfNodes == 0) {
        std::cerr << "Error: Failed to read input.txt" << std::endl;
        return;
    }
    
    std::cout << "--- Original Array of Parents ---" << std::endl;
    displayArrayOfParents(arrayParents);
    
    std::cout << "--- Conversion 1: Array of Parents to First-Child Next-Sibling ---" << std::endl;
    FirstChildNextSibling convertedFCNS1 = convertArrayParentsToFirstChildNextSibling(arrayParents.parentArray, arrayParents.numberOfNodes);
    displayFirstChildNextSibling(convertedFCNS1);
    writeFirstChildNextSiblingToFile(convertedFCNS1, "output_array_to_fcns.txt");
    
    std::cout << "--- Conversion 2: Array of Parents to Graph-Based ---" << std::endl;
    GraphBasedRepresentation convertedGraph1 = convertArrayParentsToGraphBased(arrayParents.parentArray, arrayParents.numberOfNodes);
    displayGraphBasedRepresentation(convertedGraph1);
    writeGraphBasedRepresentationToFile(convertedGraph1, "output_array_to_graph.txt");
    
    std::cout << "--- Conversion 3: First-Child Next-Sibling to Array of Parents ---" << std::endl;
    ArrayOfParents convertedArray1 = convertFirstChildNextSiblingToArrayParents(convertedFCNS1.firstChildArray, convertedFCNS1.nextSiblingArray, convertedFCNS1.numberOfNodes);
    displayArrayOfParents(convertedArray1);
    writeArrayOfParentsToFile(convertedArray1, "output_fcns_to_array.txt");
    
    std::cout << "--- Conversion 4: First-Child Next-Sibling to Graph-Based ---" << std::endl;
    GraphBasedRepresentation convertedGraph2 = convertFirstChildNextSiblingToGraphBased(convertedFCNS1.firstChildArray, convertedFCNS1.nextSiblingArray, convertedFCNS1.numberOfNodes);
    displayGraphBasedRepresentation(convertedGraph2);
    writeGraphBasedRepresentationToFile(convertedGraph2, "output_fcns_to_graph.txt");
    
    std::cout << "--- Conversion 5: Graph-Based to Array of Parents ---" << std::endl;
    ArrayOfParents convertedArray2 = convertGraphBasedToArrayParents(convertedGraph1.adjacencyData, convertedGraph1.numberOfNodes);
    displayArrayOfParents(convertedArray2);
    writeArrayOfParentsToFile(convertedArray2, "output_graph_to_array.txt");
    
    std::cout << "--- Conversion 6: Graph-Based to First-Child Next-Sibling ---" << std::endl;
    FirstChildNextSibling convertedFCNS2 = convertGraphBasedToFirstChildNextSibling(convertedGraph1.adjacencyData, convertedGraph1.numberOfNodes);
    displayFirstChildNextSibling(convertedFCNS2);
    writeFirstChildNextSiblingToFile(convertedFCNS2, "output_graph_to_fcns.txt");
    
    std::cout << "All conversions completed successfully!" << std::endl;
    std::cout << "Output files have been generated for each conversion." << std::endl;
}

/**
 * @brief Test tree conversion functions using input.txt
 */
void executeTreeConversionTests() {
    std::cout << "=== Testing Tree Conversion Functions ===" << std::endl;
    
    // Test Array of Parents input format from input.txt
    std::cout << "\n--- Test: Array of Parents Format (from input.txt) ---" << std::endl;
    ArrayOfParents testArray = readArrayOfParentsFromFile("input.txt");
    if (testArray.numberOfNodes > 0) {
        std::cout << "Successfully loaded tree with " << testArray.numberOfNodes << " nodes" << std::endl;
        std::cout << "Root node: " << testArray.rootNode << std::endl;
        
        // Test conversion to other formats
        FirstChildNextSibling testFCNS = convertArrayParentsToFirstChildNextSibling(testArray.parentArray, testArray.numberOfNodes);
        GraphBasedRepresentation testGraph = convertArrayParentsToGraphBased(testArray.parentArray, testArray.numberOfNodes);
        
        std::cout << "Conversions successful - FCNS root: " << testFCNS.rootNode 
                  << ", Graph root: " << testGraph.rootNode << std::endl;
        
        // Verify consistency by converting back
        ArrayOfParents backToArray = convertFirstChildNextSiblingToArrayParents(testFCNS.firstChildArray, testFCNS.nextSiblingArray, testFCNS.numberOfNodes);
        ArrayOfParents backToArray2 = convertGraphBasedToArrayParents(testGraph.adjacencyData, testGraph.numberOfNodes);
        
        std::cout << "Round-trip verification: Original root = " << testArray.rootNode 
                  << ", FCNS->Array root = " << backToArray.rootNode 
                  << ", Graph->Array root = " << backToArray2.rootNode << std::endl;
    } else {
        std::cout << "Failed to load tree from input.txt" << std::endl;
    }
}

/**
 * @brief Main function to demonstrate tree representation conversions
 * @return Exit status
 */
int main() {
    std::cout << "Tree Representation Conversion Program" << std::endl;
    std::cout << "Supporting: Array of Parents, First-Child Next-Sibling, Graph-Based" << std::endl;
    std::cout << "Total conversions: 6 types" << std::endl;
    std::cout << "Input file: input.txt (Array of Parents format)" << std::endl << std::endl;
    
    try {
        // Run conversion tests
        executeTreeConversionTests();
        std::cout << std::endl;
        
        // Demonstrate all conversions
        demonstrateTreeRepresentationConversions();
        
    } catch (const std::exception& error) {
        std::cerr << "Error occurred during execution: " << error.what() << std::endl;
        return 1;
    }
    
    return 0;
} 