"""
Adjacency List implementation for MultiGraph
Supports multiple edges but NOT self-loops
"""

from typing import List, Tuple
from dataclasses import dataclass


@dataclass
class AdjacencyList:
    """Structure to represent adjacency list for multigraph"""
    adjacency_data: List[List[int]]
    number_of_vertices: int
    
    def __init__(self, number_of_vertices: int = 0):
        self.number_of_vertices = number_of_vertices
        self.adjacency_data = [[] for _ in range(number_of_vertices)]


def read_adjacency_list_from_file(file_name: str) -> AdjacencyList:
    """
    Read adjacency list from edge list file with self-loop removal
    
    Args:
        file_name: Name of input file containing edge list
        
    Returns:
        AdjacencyList structure containing the graph data
    """
    try:
        with open(file_name, 'r') as input_file:
            number_of_vertices, number_of_edges = map(int, input_file.readline().split())
            
            adjacency_list = AdjacencyList(number_of_vertices)
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
                    adjacency_list.adjacency_data[source_vertex].append(target_vertex)
            
            if self_loop_count > 0:
                print(f"Total self-loops removed: {self_loop_count}")
            
            return adjacency_list
    except FileNotFoundError:
        print(f"Error: Cannot open file {file_name}")
        return AdjacencyList()
    except Exception as e:
        print(f"Error reading file: {e}")
        return AdjacencyList()


def display_adjacency_list(adjacency_list: AdjacencyList) -> None:
    """
    Display adjacency list to console
    
    Args:
        adjacency_list: The adjacency list to display
    """
    print("=== Adjacency List (MultiGraph) ===")
    print(f"Number of vertices: {adjacency_list.number_of_vertices}")
    
    for vertex_index in range(adjacency_list.number_of_vertices):
        if adjacency_list.adjacency_data[vertex_index]:
            edges = " ".join(map(str, adjacency_list.adjacency_data[vertex_index]))
            print(f"Vertex {vertex_index}: {edges}")
        else:
            print(f"Vertex {vertex_index}: (no outgoing edges)")
    print()


def write_adjacency_list_to_file(adjacency_list: AdjacencyList, file_name: str) -> None:
    """
    Write adjacency list to output file
    
    Args:
        adjacency_list: The adjacency list to write
        file_name: Name of output file
    """
    try:
        with open(file_name, 'w') as output_file:
            output_file.write("=== Adjacency List (MultiGraph) ===\n")
            output_file.write(f"Number of vertices: {adjacency_list.number_of_vertices}\n")
            
            for vertex_index in range(adjacency_list.number_of_vertices):
                if adjacency_list.adjacency_data[vertex_index]:
                    edges = " ".join(map(str, adjacency_list.adjacency_data[vertex_index]))
                    output_file.write(f"Vertex {vertex_index}: {edges}\n")
                else:
                    output_file.write(f"Vertex {vertex_index}: (no outgoing edges)\n")
    except Exception as e:
        print(f"Error: Cannot create file {file_name}: {e}")


def count_total_edges_in_adjacency_list(adjacency_list: AdjacencyList) -> int:
    """
    Count total edges in adjacency list
    
    Args:
        adjacency_list: The adjacency list to count edges from
        
    Returns:
        Total number of edges
    """
    total_edges = 0
    for vertex_edges in adjacency_list.adjacency_data:
        total_edges += len(vertex_edges)
    return total_edges


def convert_matrix_to_adjacency_list(matrix_data: List[List[int]], 
                                   number_of_vertices: int) -> AdjacencyList:
    """
    Convert adjacency matrix to adjacency list with self-loop removal
    
    Args:
        matrix_data: Matrix data as 2D list
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyList structure containing the converted data
    """
    adjacency_list = AdjacencyList(number_of_vertices)
    self_loop_count = 0
    
    for source_vertex in range(number_of_vertices):
        for target_vertex in range(number_of_vertices):
            edge_count = matrix_data[source_vertex][target_vertex]
            
            # Skip self-loops
            if source_vertex == target_vertex and edge_count > 0:
                self_loop_count += edge_count
                continue
            
            for _ in range(edge_count):
                adjacency_list.adjacency_data[source_vertex].append(target_vertex)
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to multigraph list")
    
    return adjacency_list


def convert_extended_adjacency_list_to_list(outgoing_edge_indices: List[List[int]], 
                                          edge_instances: List[Tuple[int, int]], 
                                          number_of_vertices: int) -> AdjacencyList:
    """
    Convert extended adjacency list to adjacency list with self-loop removal
    
    Args:
        outgoing_edge_indices: Outgoing edge indices per vertex
        edge_instances: All edge instances as (source, target) pairs
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyList structure containing the converted data
    """
    adjacency_list = AdjacencyList(number_of_vertices)
    self_loop_count = 0
    
    for vertex_index in range(number_of_vertices):
        for edge_index in outgoing_edge_indices[vertex_index]:
            if 0 <= edge_index < len(edge_instances):
                source_vertex, target_vertex = edge_instances[edge_index]
                
                # Skip self-loops
                if source_vertex == target_vertex:
                    self_loop_count += 1
                    continue
                
                adjacency_list.adjacency_data[source_vertex].append(target_vertex)
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to multigraph list")
    
    return adjacency_list


def convert_adjacency_map_to_list(outgoing_connections: dict, 
                                number_of_vertices: int) -> AdjacencyList:
    """
    Convert adjacency map to adjacency list with self-loop removal
    
    Args:
        outgoing_connections: Map of outgoing connections
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyList structure containing the converted data
    """
    adjacency_list = AdjacencyList(number_of_vertices)
    self_loop_count = 0
    
    for source_vertex, connections in outgoing_connections.items():
        for target_vertex, _ in connections:
            # Skip self-loops
            if source_vertex == target_vertex:
                self_loop_count += 1
                continue
            
            if 0 <= target_vertex < number_of_vertices:
                adjacency_list.adjacency_data[source_vertex].append(target_vertex)
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to multigraph list")
    
    return adjacency_list 