"""
Main program to demonstrate all 12 conversion functions between graph representations
for Simple Graph (does NOT support self-loops or multiple edges)
"""

from adjacency_matrix import *
from adjacency_list import *
from extended_adjacency_list import *
from adjacency_map import *


def demonstrate_graph_representation_conversions():
    """Demonstrate all 12 conversion functions between graph representations"""
    INPUT_FILE_NAME = "input.txt"
    
    print("=== Complete Simple Graph Representation Conversion Demo ===")
    print("Demonstrating all 12 possible conversions between 4 representations")
    print("Note: Simple Graphs do NOT support self-loops or multiple edges")
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
    extended_to_map = convert_extended_list_to_map(
        extended_list.outgoing_edge_indices, extended_list.incoming_edge_indices,
        extended_list.edge_instances, extended_list.number_of_vertices, 
        extended_list.number_of_edges)
    display_adjacency_map(extended_to_map)
    write_adjacency_map_to_file(extended_to_map, "output_extended_to_map.txt")
    
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
    map_to_extended = convert_adjacency_map_to_extended(
        adjacency_map.outgoing_connections, adjacency_map.incoming_connections,
        adjacency_map.number_of_vertices, adjacency_map.number_of_edges)
    display_extended_adjacency_list(map_to_extended)
    write_extended_adjacency_list_to_file(map_to_extended, "output_map_to_extended.txt")
    
    print("=== All conversions completed successfully! ===")
    print("Output files have been generated for each conversion.")


def analyze_simple_graph_constraints():
    """Analyze how simple graph constraints are enforced"""
    INPUT_FILE_NAME = "input.txt"
    
    print("=== Simple Graph Constraint Analysis ===")
    print("Input file contains edges with potential violations:")
    
    with open(INPUT_FILE_NAME, 'r') as f:
        lines = f.readlines()
        vertices, edges = map(int, lines[0].split())
        print(f"Declared: {vertices} vertices, {edges} edges")
        
        print("\nEdge list analysis:")
        edge_list = []
        for i in range(1, edges + 1):
            if i < len(lines):
                u, v = map(int, lines[i].split())
                edge_list.append((u, v))
                
                # Check for violations
                if u == v:
                    print(f"  Edge ({u},{v}): SELF-LOOP detected")
                elif (u, v) in edge_list[:-1]:
                    print(f"  Edge ({u},{v}): DUPLICATE edge detected")
                else:
                    print(f"  Edge ({u},{v}): Valid")
    
    print("\n--- Edge Count Analysis ---")
    
    # Read processed graphs
    matrix = read_adjacency_matrix_from_file(INPUT_FILE_NAME)
    list_graph = read_adjacency_list_from_file(INPUT_FILE_NAME)
    extended = read_extended_adjacency_list_from_file(INPUT_FILE_NAME)
    map_graph = read_adjacency_map_from_file(INPUT_FILE_NAME)
    
    # Count edges in each representation
    matrix_edges = sum(sum(row) for row in matrix.matrix_data)
    list_edges = sum(len(adj) for adj in list_graph.adjacency_data)
    extended_edges = extended.number_of_edges
    map_edges = map_graph.number_of_edges
    
    print(f"Original input edges: {edges}")
    print(f"Matrix edges (after constraint enforcement): {matrix_edges}")
    print(f"List edges (after constraint enforcement): {list_edges}")
    print(f"Extended edges (after constraint enforcement): {extended_edges}")
    print(f"Map edges (after constraint enforcement): {map_edges}")
    
    if matrix_edges == list_edges == extended_edges == map_edges:
        print("✓ All representations have consistent edge counts after constraint enforcement")
    else:
        print("✗ Edge count mismatch detected between representations")


def test_graph_representation_consistency():
    """Test the consistency of graph representation conversions"""
    INPUT_FILE_NAME = "input.txt"
    
    print("=== Testing Simple Graph Representation Consistency ===")
    
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
    
    # Test constraint preservation
    print("\n--- Constraint Preservation Test ---")
    has_self_loops = any(original_matrix.matrix_data[i][i] > 0 
                        for i in range(original_matrix.number_of_vertices))
    has_multiple_edges = any(original_matrix.matrix_data[i][j] > 1 
                            for i in range(original_matrix.number_of_vertices) 
                            for j in range(original_matrix.number_of_vertices))
    
    print(f"Self-loops in final matrix: {has_self_loops}")
    print(f"Multiple edges in final matrix: {has_multiple_edges}")
    
    if not has_self_loops and not has_multiple_edges:
        print("✓ Simple graph constraints successfully maintained!")
    else:
        print("✗ Simple graph constraints violated!")


def main():
    """Main function to demonstrate simple graph representation conversions"""
    print("Simple Graph Representation Conversion Program")
    print("Supporting: NO self-loops, NO multiple edges")
    print("Total representations: 4 types")
    print("Total conversions: 12 types")
    print()
    
    try:
        # Analyze constraint enforcement
        analyze_simple_graph_constraints()
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