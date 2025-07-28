"""
Main program to demonstrate all 12 conversion functions between graph representations
for MultiGraph (supports multiple edges but NOT self-loops)
"""

from adjacency_matrix import *
from adjacency_list import *
from extended_adjacency_list import *
from adjacency_map import *


def demonstrate_graph_representation_conversions():
    """Demonstrate all 12 conversion functions between graph representations"""
    INPUT_FILE_NAME = "input.txt"
    
    print("=== Complete MultiGraph Representation Conversion Demo ===")
    print("Demonstrating all 12 possible conversions between 4 representations")
    print("Note: MultiGraphs support multiple edges but NOT self-loops")
    print()
    
    # Original representations from file
    print("--- Reading Original Data from File ---")
    adjacency_matrix = read_adjacency_matrix_from_file(INPUT_FILE_NAME)
    adjacency_list = read_adjacency_list_from_file(INPUT_FILE_NAME)
    extended_list = read_extended_adjacency_list_from_file(INPUT_FILE_NAME)
    adjacency_map = read_adjacency_map_from_file(INPUT_FILE_NAME)
    
    print("Original Adjacency Matrix:")
    display_adjacency_matrix(adjacency_matrix)
    
    print("Original Adjacency List:")
    display_adjacency_list(adjacency_list)
    
    print("Original Extended Adjacency List:")
    display_extended_adjacency_list(extended_list)
    
    print("Original Adjacency Map:")
    display_adjacency_map(adjacency_map)
    
    # Demonstrate all 12 conversions
    print("=== CONVERSION DEMONSTRATIONS ===")
    
    # Matrix conversions (3 total)
    print("--- 1. Adjacency Matrix → Adjacency List ---")
    matrix_to_list = convert_matrix_to_adjacency_list(
        adjacency_matrix.matrix_data, adjacency_matrix.number_of_vertices)
    display_adjacency_list(matrix_to_list)
    write_adjacency_list_to_file(matrix_to_list, "output_matrix_to_list.txt")
    
    print("--- 2. Adjacency Matrix → Extended Adjacency List ---")
    matrix_to_extended = convert_matrix_to_extended_adjacency_list(
        adjacency_matrix.matrix_data, adjacency_matrix.number_of_vertices)
    display_extended_adjacency_list(matrix_to_extended)
    write_extended_adjacency_list_to_file(matrix_to_extended, "output_matrix_to_extended.txt")
    
    print("--- 3. Adjacency Matrix → Adjacency Map ---")
    matrix_to_map = convert_matrix_to_adjacency_map(
        adjacency_matrix.matrix_data, adjacency_matrix.number_of_vertices)
    display_adjacency_map(matrix_to_map)
    write_adjacency_map_to_file(matrix_to_map, "output_matrix_to_map.txt")
    
    # List conversions (3 total)
    print("--- 4. Adjacency List → Adjacency Matrix ---")
    list_to_matrix = convert_adjacency_list_to_matrix(
        adjacency_list.adjacency_data, adjacency_list.number_of_vertices)
    display_adjacency_matrix(list_to_matrix)
    write_adjacency_matrix_to_file(list_to_matrix, "output_list_to_matrix.txt")
    
    print("--- 5. Adjacency List → Extended Adjacency List ---")
    list_to_extended = convert_adjacency_list_to_extended(
        adjacency_list.adjacency_data, adjacency_list.number_of_vertices)
    display_extended_adjacency_list(list_to_extended)
    write_extended_adjacency_list_to_file(list_to_extended, "output_list_to_extended.txt")
    
    print("--- 6. Adjacency List → Adjacency Map ---")
    list_to_map = convert_adjacency_list_to_map(
        adjacency_list.adjacency_data, adjacency_list.number_of_vertices)
    display_adjacency_map(list_to_map)
    write_adjacency_map_to_file(list_to_map, "output_list_to_map.txt")
    
    # Extended List conversions (3 total)
    print("--- 7. Extended Adjacency List → Adjacency Matrix ---")
    extended_to_matrix = convert_extended_adjacency_list_to_matrix(
        extended_list.edge_instances, extended_list.number_of_vertices)
    display_adjacency_matrix(extended_to_matrix)
    write_adjacency_matrix_to_file(extended_to_matrix, "output_extended_to_matrix.txt")
    
    print("--- 8. Extended Adjacency List → Adjacency List ---")
    extended_to_list = convert_extended_adjacency_list_to_list(
        extended_list.outgoing_edge_indices, extended_list.edge_instances, 
        extended_list.number_of_vertices)
    display_adjacency_list(extended_to_list)
    write_adjacency_list_to_file(extended_to_list, "output_extended_to_list.txt")
    
    print("--- 9. Extended Adjacency List → Adjacency Map ---")
    extended_to_map = convert_adjacency_map_to_extended(
        adjacency_map.outgoing_connections, adjacency_map.incoming_connections,
        adjacency_map.number_of_vertices, adjacency_map.number_of_edges)
    display_extended_adjacency_list(extended_to_map)
    write_extended_adjacency_list_to_file(extended_to_map, "output_extended_to_map.txt")
    
    # Map conversions (3 total)
    print("--- 10. Adjacency Map → Adjacency Matrix ---")
    map_to_matrix = convert_adjacency_map_to_matrix(
        adjacency_map.outgoing_connections, adjacency_map.number_of_vertices)
    display_adjacency_matrix(map_to_matrix)
    write_adjacency_matrix_to_file(map_to_matrix, "output_map_to_matrix.txt")
    
    print("--- 11. Adjacency Map → Adjacency List ---")
    map_to_list = convert_adjacency_map_to_list(
        adjacency_map.outgoing_connections, adjacency_map.number_of_vertices)
    display_adjacency_list(map_to_list)
    write_adjacency_list_to_file(map_to_list, "output_map_to_list.txt")
    
    print("--- 12. Adjacency Map → Extended Adjacency List ---")
    map_to_extended = convert_extended_list_to_map(
        extended_list.outgoing_edge_indices, extended_list.incoming_edge_indices,
        extended_list.edge_instances, extended_list.number_of_vertices, 
        extended_list.number_of_edges)
    display_adjacency_map(map_to_extended)
    write_adjacency_map_to_file(map_to_extended, "output_map_to_extended.txt")
    
    print("=== All conversions completed successfully! ===")
    print("Output files have been generated for each conversion.")


def test_multigraph_self_loop_removal():
    """Test self-loop removal functionality specific to multigraphs"""
    INPUT_FILE_NAME = "input.txt"
    
    print("=== Testing MultiGraph Self-Loop Removal ===")
    
    # Read original data
    original_matrix = read_adjacency_matrix_from_file(INPUT_FILE_NAME)
    
    # Count edges before and after processing
    print("\n--- Edge Count Analysis ---")
    
    # Count total edges in original input file
    try:
        with open(INPUT_FILE_NAME, 'r') as f:
            _, original_edge_count = map(int, f.readline().split())
            self_loops_in_input = 0
            valid_edges_in_input = 0
            
            for _ in range(original_edge_count):
                source, target = map(int, f.readline().split())
                if source == target:
                    self_loops_in_input += 1
                else:
                    valid_edges_in_input += 1
            
            print(f"Original input file edges: {original_edge_count}")
            print(f"Self-loops in input: {self_loops_in_input}")
            print(f"Valid edges (non-self-loops): {valid_edges_in_input}")
    except:
        print("Could not analyze input file")
    
    # Count edges in processed matrix
    total_edges_in_matrix = sum(sum(row) for row in original_matrix.matrix_data)
    print(f"Edges in processed matrix: {total_edges_in_matrix}")
    
    # Verify self-loop removal
    self_loops_in_matrix = sum(original_matrix.matrix_data[i][i] 
                              for i in range(original_matrix.number_of_vertices))
    print(f"Self-loops in processed matrix: {self_loops_in_matrix}")
    
    if self_loops_in_matrix == 0:
        print("✓ Self-loop removal successful - MultiGraph constraint satisfied!")
    else:
        print("✗ Self-loops still present - MultiGraph constraint violated!")


def test_graph_representation_consistency():
    """Test the consistency of graph representation conversions"""
    INPUT_FILE_NAME = "input.txt"
    
    print("=== Testing MultiGraph Representation Consistency ===")
    
    # Read original data
    original_matrix = read_adjacency_matrix_from_file(INPUT_FILE_NAME)
    
    # Test round-trip conversions
    print("\n--- Round-trip Test 1: Matrix → List → Matrix ---")
    matrix_to_list = convert_matrix_to_adjacency_list(
        original_matrix.matrix_data, original_matrix.number_of_vertices)
    list_back_to_matrix = convert_adjacency_list_to_matrix(
        matrix_to_list.adjacency_data, matrix_to_list.number_of_vertices)
    
    print(f"Original matrix vertices: {original_matrix.number_of_vertices}")
    print(f"Round-trip matrix vertices: {list_back_to_matrix.number_of_vertices}")
    
    print("\n--- Round-trip Test 2: Matrix → Extended → Matrix ---")
    matrix_to_extended = convert_matrix_to_extended_adjacency_list(
        original_matrix.matrix_data, original_matrix.number_of_vertices)
    extended_back_to_matrix = convert_extended_adjacency_list_to_matrix(
        matrix_to_extended.edge_instances, matrix_to_extended.number_of_vertices)
    
    print(f"Original matrix vertices: {original_matrix.number_of_vertices}")
    print(f"Round-trip matrix vertices: {extended_back_to_matrix.number_of_vertices}")
    
    print("\n--- Statistics ---")
    total_edges_original = sum(sum(row) for row in original_matrix.matrix_data)
    total_edges_round_trip_1 = sum(sum(row) for row in list_back_to_matrix.matrix_data)
    total_edges_round_trip_2 = sum(sum(row) for row in extended_back_to_matrix.matrix_data)
    
    print(f"Original total edges: {total_edges_original}")
    print(f"Round-trip 1 total edges: {total_edges_round_trip_1}")
    print(f"Round-trip 2 total edges: {total_edges_round_trip_2}")
    
    if (total_edges_original == total_edges_round_trip_1 == total_edges_round_trip_2):
        print("✓ All round-trip conversions preserve edge count!")
    else:
        print("✗ Edge count mismatch detected!")


def main():
    """Main function to demonstrate multigraph representation conversions"""
    print("MultiGraph Representation Conversion Program")
    print("Supporting: Multiple edges but NOT self-loops")
    print("Total representations: 4 types")
    print("Total conversions: 12 types")
    print()
    
    try:
        # Test self-loop removal
        test_multigraph_self_loop_removal()
        print()
        
        # Run consistency tests
        test_graph_representation_consistency()
        print()
        
        # Demonstrate all conversions
        demonstrate_graph_representation_conversions()
        
    except Exception as error:
        print(f"Error occurred during execution: {error}")
        return 1
    
    return 0


if __name__ == "__main__":
    main() 