"""
Main program to demonstrate all 6 conversion functions between tree representations
Supports: Array of Parents, First-Child Next-Sibling, Graph-Based Representation
"""

from array_of_parents import *
from first_child_next_sibling import *
from graph_based_representation import *


def demonstrate_tree_representation_conversions():
    """Demonstrate all 6 conversion functions between tree representations"""
    INPUT_FILE_NAME = "input.txt"
    
    print("=== Tree Representation Conversions Demo ===")
    print("Testing all 6 conversion types for tree representations")
    print("Using input.txt for Array of Parents format")
    print()
    
    # Read array of parents from input.txt
    array_parents = read_array_of_parents_from_file(INPUT_FILE_NAME)
    if array_parents.number_of_nodes == 0:
        print("Error: Failed to read input.txt")
        return
    
    print("--- Original Array of Parents ---")
    display_array_of_parents(array_parents)
    
    print("--- Conversion 1: Array of Parents → First-Child Next-Sibling ---")
    converted_fcns1 = convert_array_parents_to_first_child_next_sibling(
        array_parents.parent_array, array_parents.number_of_nodes)
    display_first_child_next_sibling(converted_fcns1)
    write_first_child_next_sibling_to_file(converted_fcns1, "output_array_to_fcns.txt")
    
    print("--- Conversion 2: Array of Parents → Graph-Based ---")
    converted_graph1 = convert_array_parents_to_graph_based(
        array_parents.parent_array, array_parents.number_of_nodes)
    display_graph_based_representation(converted_graph1)
    write_graph_based_representation_to_file(converted_graph1, "output_array_to_graph.txt")
    
    print("--- Conversion 3: First-Child Next-Sibling → Array of Parents ---")
    converted_array1 = convert_first_child_next_sibling_to_array_parents(
        converted_fcns1.first_child_array, converted_fcns1.next_sibling_array, 
        converted_fcns1.number_of_nodes)
    display_array_of_parents(converted_array1)
    write_array_of_parents_to_file(converted_array1, "output_fcns_to_array.txt")
    
    print("--- Conversion 4: First-Child Next-Sibling → Graph-Based ---")
    converted_graph2 = convert_first_child_next_sibling_to_graph_based(
        converted_fcns1.first_child_array, converted_fcns1.next_sibling_array, 
        converted_fcns1.number_of_nodes)
    display_graph_based_representation(converted_graph2)
    write_graph_based_representation_to_file(converted_graph2, "output_fcns_to_graph.txt")
    
    print("--- Conversion 5: Graph-Based → Array of Parents ---")
    converted_array2 = convert_graph_based_to_array_parents(
        converted_graph1.adjacency_data, converted_graph1.number_of_nodes)
    display_array_of_parents(converted_array2)
    write_array_of_parents_to_file(converted_array2, "output_graph_to_array.txt")
    
    print("--- Conversion 6: Graph-Based → First-Child Next-Sibling ---")
    converted_fcns2 = convert_graph_based_to_first_child_next_sibling(
        converted_graph1.adjacency_data, converted_graph1.number_of_nodes)
    display_first_child_next_sibling(converted_fcns2)
    write_first_child_next_sibling_to_file(converted_fcns2, "output_graph_to_fcns.txt")
    
    print("All conversions completed successfully!")
    print("Output files have been generated for each conversion.")


def execute_tree_conversion_tests():
    """Test tree conversion functions using input.txt"""
    INPUT_FILE_NAME = "input.txt"
    
    print("=== Testing Tree Conversion Functions ===")
    
    # Test Array of Parents input format from input.txt
    print("\n--- Test: Array of Parents Format (from input.txt) ---")
    test_array = read_array_of_parents_from_file(INPUT_FILE_NAME)
    if test_array.number_of_nodes > 0:
        print(f"Successfully loaded tree with {test_array.number_of_nodes} nodes")
        print(f"Root node: {test_array.root_node}")
        
        # Test conversion to other formats
        test_fcns = convert_array_parents_to_first_child_next_sibling(
            test_array.parent_array, test_array.number_of_nodes)
        test_graph = convert_array_parents_to_graph_based(
            test_array.parent_array, test_array.number_of_nodes)
        
        print(f"Conversions successful - FCNS root: {test_fcns.root_node}, "
              f"Graph root: {test_graph.root_node}")
        
        # Verify consistency by converting back
        back_to_array = convert_first_child_next_sibling_to_array_parents(
            test_fcns.first_child_array, test_fcns.next_sibling_array, test_fcns.number_of_nodes)
        back_to_array2 = convert_graph_based_to_array_parents(
            test_graph.adjacency_data, test_graph.number_of_nodes)
        
        print(f"Round-trip verification: Original root = {test_array.root_node}, "
              f"FCNS->Array root = {back_to_array.root_node}, "
              f"Graph->Array root = {back_to_array2.root_node}")
    else:
        print("Failed to load tree from input.txt")


def test_tree_structure_validation():
    """Test the tree structure validation and consistency"""
    INPUT_FILE_NAME = "input.txt"
    
    print("=== Testing Tree Structure Validation ===")
    
    # Read original tree
    original_tree = read_array_of_parents_from_file(INPUT_FILE_NAME)
    if original_tree.number_of_nodes == 0:
        print("Could not load tree for validation")
        return
    
    print(f"\n--- Tree Structure Analysis ---")
    print(f"Total nodes: {original_tree.number_of_nodes}")
    print(f"Root node: {original_tree.root_node}")
    
    # Count nodes with no parent (should be exactly 1 - the root)
    root_count = 0
    for node_index in range(original_tree.number_of_nodes):
        if original_tree.parent_array[node_index] == NIL_VALUE:
            root_count += 1
    
    print(f"Nodes with no parent (roots): {root_count}")
    
    if root_count == 1:
        print("✓ Valid tree structure - exactly one root node")
    else:
        print("✗ Invalid tree structure - should have exactly one root")
    
    # Verify no cycles (each node should have a path to root)
    print("\n--- Cycle Detection ---")
    has_cycle = False
    for start_node in range(original_tree.number_of_nodes):
        visited = set()
        current = start_node
        
        while current != NIL_VALUE and current not in visited:
            visited.add(current)
            current = original_tree.parent_array[current]
        
        if current != NIL_VALUE and current in visited:
            has_cycle = True
            break
    
    if not has_cycle:
        print("✓ No cycles detected - valid tree structure")
    else:
        print("✗ Cycle detected - invalid tree structure")


def main():
    """Main function to demonstrate tree representation conversions"""
    print("Tree Representation Conversion Program")
    print("Supporting: Array of Parents, First-Child Next-Sibling, Graph-Based")
    print("Total conversions: 6 types")
    print("Input file: input.txt (Array of Parents format)")
    print()
    
    try:
        # Run conversion tests
        execute_tree_conversion_tests()
        print()
        
        # Test tree structure validation
        test_tree_structure_validation()
        print()
        
        # Demonstrate all conversions
        demonstrate_tree_representation_conversions()
        
    except Exception as error:
        print(f"Error occurred during execution: {error}")
        return 1
    
    return 0


if __name__ == "__main__":
    main() 