"""
Adjacency Matrix implementation for Simple Graph
Does NOT support self-loops or multiple edges (maximum 1 edge between any two vertices)
"""

from typing import List, Tuple, Set
from dataclasses import dataclass


@dataclass
class AdjacencyMatrix:
    """Structure to represent adjacency matrix for simple graph"""
    matrix_data: List[List[int]]
    number_of_vertices: int
    
    def __init__(self, number_of_vertices: int = 0):
        self.number_of_vertices = number_of_vertices
        self.matrix_data = [[0 for _ in range(number_of_vertices)] 
                           for _ in range(number_of_vertices)]


def read_adjacency_matrix_from_file(file_name: str) -> AdjacencyMatrix:
    """
    Read adjacency matrix from input file with self-loop and duplicate edge removal
    
    Args:
        file_name: Name of input file containing edge list
        
    Returns:
        AdjacencyMatrix structure containing the graph data
    """
    try:
        with open(file_name, 'r') as input_file:
            number_of_vertices, number_of_edges = map(int, input_file.readline().split())
            
            adjacency_matrix = AdjacencyMatrix(number_of_vertices)
            existing_edges: Set[Tuple[int, int]] = set()
            self_loop_count = 0
            duplicate_edge_count = 0
            
            for _ in range(number_of_edges):
                source_vertex, target_vertex = map(int, input_file.readline().split())
                
                # Check for self-loops (not allowed in simple graph)
                if source_vertex == target_vertex:
                    self_loop_count += 1
                    print(f"Warning: Self-loop detected ({source_vertex},{target_vertex}) "
                          f"- Removing as simple graphs do not allow self-loops")
                    continue
                
                # Check for duplicate edges (not allowed in simple graph)
                edge = (source_vertex, target_vertex)
                if edge in existing_edges:
                    duplicate_edge_count += 1
                    print(f"Warning: Duplicate edge detected ({source_vertex},{target_vertex}) "
                          f"- Removing as simple graphs do not allow multiple edges")
                    continue
                
                if (0 <= source_vertex < number_of_vertices and 
                    0 <= target_vertex < number_of_vertices):
                    adjacency_matrix.matrix_data[source_vertex][target_vertex] = 1
                    existing_edges.add(edge)
            
            if self_loop_count > 0:
                print(f"Total self-loops removed: {self_loop_count}")
            if duplicate_edge_count > 0:
                print(f"Total duplicate edges removed: {duplicate_edge_count}")
            
            return adjacency_matrix
    except FileNotFoundError:
        print(f"Error: Cannot open file {file_name}")
        return AdjacencyMatrix()
    except Exception as e:
        print(f"Error reading file: {e}")
        return AdjacencyMatrix()


def read_adjacency_matrix_from_matrix_file(file_name: str) -> AdjacencyMatrix:
    """
    Read adjacency matrix from matrix format file with simple graph validation
    
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
            multiple_edge_count = 0
            
            for row_index in range(number_of_vertices):
                row_data = list(map(int, input_file.readline().split()))
                for column_index in range(number_of_vertices):
                    value = row_data[column_index]
                    
                    if row_index == column_index and value > 0:
                        # Remove self-loops on diagonal
                        self_loop_count += value
                        print(f"Warning: Self-loop detected at vertex {row_index} "
                              f"- Removing as simple graphs do not allow self-loops")
                        adjacency_matrix.matrix_data[row_index][column_index] = 0
                    elif value > 1:
                        # Convert multiple edges to single edge
                        multiple_edge_count += (value - 1)
                        print(f"Warning: Multiple edges detected ({row_index},{column_index}) "
                              f"with count {value} - Converting to single edge for simple graph")
                        adjacency_matrix.matrix_data[row_index][column_index] = 1
                    else:
                        adjacency_matrix.matrix_data[row_index][column_index] = value
            
            if self_loop_count > 0:
                print(f"Total self-loops removed: {self_loop_count}")
            if multiple_edge_count > 0:
                print(f"Total multiple edges converted: {multiple_edge_count}")
            
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
    print("=== Adjacency Matrix (Simple Graph) ===")
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
            output_file.write("=== Adjacency Matrix (Simple Graph) ===\n")
            output_file.write(f"Number of vertices: {adjacency_matrix.number_of_vertices}\n")
            
            for row in adjacency_matrix.matrix_data:
                output_file.write(" ".join(map(str, row)) + "\n")
    except Exception as e:
        print(f"Error: Cannot create file {file_name}: {e}")


def convert_adjacency_list_to_matrix(adjacency_data: List[List[int]], 
                                   number_of_vertices: int) -> AdjacencyMatrix:
    """
    Convert adjacency list to adjacency matrix with self-loop and duplicate edge removal
    
    Args:
        adjacency_data: The adjacency list data
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyMatrix structure containing the converted data
    """
    adjacency_matrix = AdjacencyMatrix(number_of_vertices)
    self_loop_count = 0
    duplicate_edge_count = 0
    
    for source_vertex in range(number_of_vertices):
        connected_vertices: Set[int] = set()
        
        for target_vertex in adjacency_data[source_vertex]:
            if source_vertex == target_vertex:
                self_loop_count += 1
                continue  # Skip self-loops
            
            if target_vertex in connected_vertices:
                duplicate_edge_count += 1
                continue  # Skip duplicate edges
            
            if 0 <= target_vertex < number_of_vertices:
                adjacency_matrix.matrix_data[source_vertex][target_vertex] = 1
                connected_vertices.add(target_vertex)
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to simple graph matrix")
    if duplicate_edge_count > 0:
        print(f"Warning: {duplicate_edge_count} duplicate edges removed during conversion to simple graph matrix")
    
    return adjacency_matrix


def convert_extended_adjacency_list_to_matrix(edge_instances: List[Tuple[int, int]], 
                                            number_of_vertices: int) -> AdjacencyMatrix:
    """
    Convert extended adjacency list to adjacency matrix with self-loop and duplicate edge removal
    
    Args:
        edge_instances: List of all edge instances as (source, target) pairs
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyMatrix structure containing the converted data
    """
    adjacency_matrix = AdjacencyMatrix(number_of_vertices)
    existing_edges: Set[Tuple[int, int]] = set()
    self_loop_count = 0
    duplicate_edge_count = 0
    
    for source_vertex, target_vertex in edge_instances:
        if source_vertex == target_vertex:
            self_loop_count += 1
            continue  # Skip self-loops
        
        edge = (source_vertex, target_vertex)
        if edge in existing_edges:
            duplicate_edge_count += 1
            continue  # Skip duplicate edges
        
        if (0 <= source_vertex < number_of_vertices and 
            0 <= target_vertex < number_of_vertices):
            adjacency_matrix.matrix_data[source_vertex][target_vertex] = 1
            existing_edges.add(edge)
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to simple graph matrix")
    if duplicate_edge_count > 0:
        print(f"Warning: {duplicate_edge_count} duplicate edges removed during conversion to simple graph matrix")
    
    return adjacency_matrix


def convert_adjacency_map_to_matrix(outgoing_connections: dict, 
                                  number_of_vertices: int) -> AdjacencyMatrix:
    """
    Convert adjacency map to adjacency matrix with self-loop and duplicate edge removal
    
    Args:
        outgoing_connections: Map of outgoing connections
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyMatrix structure containing the converted data
    """
    adjacency_matrix = AdjacencyMatrix(number_of_vertices)
    existing_edges: Set[Tuple[int, int]] = set()
    self_loop_count = 0
    duplicate_edge_count = 0
    
    for source_vertex, connections in outgoing_connections.items():
        for target_vertex, _ in connections:
            if source_vertex == target_vertex:
                self_loop_count += 1
                continue  # Skip self-loops
            
            edge = (source_vertex, target_vertex)
            if edge in existing_edges:
                duplicate_edge_count += 1
                continue  # Skip duplicate edges
            
            if 0 <= target_vertex < number_of_vertices:
                adjacency_matrix.matrix_data[source_vertex][target_vertex] = 1
                existing_edges.add(edge)
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to simple graph matrix")
    if duplicate_edge_count > 0:
        print(f"Warning: {duplicate_edge_count} duplicate edges removed during conversion to simple graph matrix")
    
    return adjacency_matrix 