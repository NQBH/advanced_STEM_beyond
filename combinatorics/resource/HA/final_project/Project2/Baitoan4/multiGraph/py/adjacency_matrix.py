"""
Adjacency Matrix implementation for MultiGraph
Supports multiple edges but NOT self-loops
"""

from typing import List, Tuple
from dataclasses import dataclass


@dataclass
class AdjacencyMatrix:
    """Structure to represent adjacency matrix for multigraph"""
    matrix_data: List[List[int]]
    number_of_vertices: int
    
    def __init__(self, number_of_vertices: int = 0):
        self.number_of_vertices = number_of_vertices
        self.matrix_data = [[0 for _ in range(number_of_vertices)] 
                           for _ in range(number_of_vertices)]


def read_adjacency_matrix_from_file(file_name: str) -> AdjacencyMatrix:
    """
    Read adjacency matrix from input file with self-loop removal
    
    Args:
        file_name: Name of input file containing edge list
        
    Returns:
        AdjacencyMatrix structure containing the graph data
    """
    try:
        with open(file_name, 'r') as input_file:
            number_of_vertices, number_of_edges = map(int, input_file.readline().split())
            
            adjacency_matrix = AdjacencyMatrix(number_of_vertices)
            self_loop_count = 0
            
            for _ in range(number_of_edges):
                source_vertex, target_vertex = map(int, input_file.readline().split())
                
                # Check for self-loops (not allowed in multigraph)
                if source_vertex == target_vertex:
                    self_loop_count += 1
                    print(f"Warning: Self-loop detected ({source_vertex},{target_vertex}) "
                          f"- Removing as multigraphs do not allow self-loops")
                    continue
                
                if (0 <= source_vertex < number_of_vertices and 
                    0 <= target_vertex < number_of_vertices):
                    adjacency_matrix.matrix_data[source_vertex][target_vertex] += 1
            
            if self_loop_count > 0:
                print(f"Total self-loops removed: {self_loop_count}")
            
            return adjacency_matrix
    except FileNotFoundError:
        print(f"Error: Cannot open file {file_name}")
        return AdjacencyMatrix()
    except Exception as e:
        print(f"Error reading file: {e}")
        return AdjacencyMatrix()


def read_adjacency_matrix_from_matrix_file(file_name: str) -> AdjacencyMatrix:
    """
    Read adjacency matrix from matrix format file with self-loop removal
    
    Args:
        file_name: Name of input file containing matrix format
        
    Returns:
        AdjacencyMatrix structure containing the graph data
    """
    try:
        with open(file_name, 'r') as input_file:
            number_of_vertices = int(input_file.readline())
            
            adjacency_matrix = AdjacencyMatrix(number_of_vertices)
            self_loop_count = 0
            
            for row_index in range(number_of_vertices):
                row_data = list(map(int, input_file.readline().split()))
                for column_index in range(number_of_vertices):
                    if row_index == column_index and row_data[column_index] > 0:
                        # Remove self-loops on diagonal
                        self_loop_count += row_data[column_index]
                        print(f"Warning: Self-loop detected at vertex {row_index} "
                              f"with {row_data[column_index]} edges - Removing as multigraphs do not allow self-loops")
                        adjacency_matrix.matrix_data[row_index][column_index] = 0
                    else:
                        adjacency_matrix.matrix_data[row_index][column_index] = row_data[column_index]
            
            if self_loop_count > 0:
                print(f"Total self-loops removed: {self_loop_count}")
            
            return adjacency_matrix
    except FileNotFoundError:
        print(f"Error: Cannot open file {file_name}")
        return AdjacencyMatrix()
    except Exception as e:
        print(f"Error reading file: {e}")
        return AdjacencyMatrix()


def display_adjacency_matrix(adjacency_matrix: AdjacencyMatrix) -> None:
    """
    Display adjacency matrix to console
    
    Args:
        adjacency_matrix: The adjacency matrix to display
    """
    print("=== Adjacency Matrix (MultiGraph) ===")
    print(f"Number of vertices: {adjacency_matrix.number_of_vertices}")
    
    for row in adjacency_matrix.matrix_data:
        print(" ".join(map(str, row)))
    print()


def write_adjacency_matrix_to_file(adjacency_matrix: AdjacencyMatrix, file_name: str) -> None:
    """
    Write adjacency matrix to output file
    
    Args:
        adjacency_matrix: The adjacency matrix to write
        file_name: Name of output file
    """
    try:
        with open(file_name, 'w') as output_file:
            output_file.write("=== Adjacency Matrix (MultiGraph) ===\n")
            output_file.write(f"Number of vertices: {adjacency_matrix.number_of_vertices}\n")
            
            for row in adjacency_matrix.matrix_data:
                output_file.write(" ".join(map(str, row)) + "\n")
    except Exception as e:
        print(f"Error: Cannot create file {file_name}: {e}")


def convert_adjacency_list_to_matrix(adjacency_data: List[List[int]], 
                                   number_of_vertices: int) -> AdjacencyMatrix:
    """
    Convert adjacency list to adjacency matrix with self-loop removal
    
    Args:
        adjacency_data: The adjacency list data
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyMatrix structure containing the converted data
    """
    adjacency_matrix = AdjacencyMatrix(number_of_vertices)
    self_loop_count = 0
    
    for source_vertex in range(number_of_vertices):
        for target_vertex in adjacency_data[source_vertex]:
            if source_vertex == target_vertex:
                self_loop_count += 1
                continue  # Skip self-loops
            if 0 <= target_vertex < number_of_vertices:
                adjacency_matrix.matrix_data[source_vertex][target_vertex] += 1
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to multigraph matrix")
    
    return adjacency_matrix


def convert_extended_adjacency_list_to_matrix(edge_instances: List[Tuple[int, int]], 
                                            number_of_vertices: int) -> AdjacencyMatrix:
    """
    Convert extended adjacency list to adjacency matrix with self-loop removal
    
    Args:
        edge_instances: List of all edge instances as (source, target) pairs
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyMatrix structure containing the converted data
    """
    adjacency_matrix = AdjacencyMatrix(number_of_vertices)
    self_loop_count = 0
    
    for source_vertex, target_vertex in edge_instances:
        if source_vertex == target_vertex:
            self_loop_count += 1
            continue  # Skip self-loops
        
        if (0 <= source_vertex < number_of_vertices and 
            0 <= target_vertex < number_of_vertices):
            adjacency_matrix.matrix_data[source_vertex][target_vertex] += 1
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to multigraph matrix")
    
    return adjacency_matrix


def convert_adjacency_map_to_matrix(outgoing_connections: dict, 
                                  number_of_vertices: int) -> AdjacencyMatrix:
    """
    Convert adjacency map to adjacency matrix with self-loop removal
    
    Args:
        outgoing_connections: Map of outgoing connections
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyMatrix structure containing the converted data
    """
    adjacency_matrix = AdjacencyMatrix(number_of_vertices)
    self_loop_count = 0
    
    for source_vertex, connections in outgoing_connections.items():
        for target_vertex, _ in connections:
            if source_vertex == target_vertex:
                self_loop_count += 1
                continue  # Skip self-loops
            
            if 0 <= target_vertex < number_of_vertices:
                adjacency_matrix.matrix_data[source_vertex][target_vertex] += 1
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to multigraph matrix")
    
    return adjacency_matrix 