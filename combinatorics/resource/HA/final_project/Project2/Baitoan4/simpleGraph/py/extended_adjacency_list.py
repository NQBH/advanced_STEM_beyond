"""
Extended Adjacency List implementation for Simple Graph
Does NOT support self-loops or multiple edges (maximum 1 edge between any two vertices)
"""

from typing import List, Tuple, Dict, Set
from dataclasses import dataclass


@dataclass
class ExtendedAdjacencyList:
    """Structure to represent extended adjacency list for simple graph"""
    edge_instances: List[Tuple[int, int]]
    outgoing_edge_indices: List[List[int]]
    incoming_edge_indices: List[List[int]]
    number_of_vertices: int
    number_of_edges: int
    
    def __init__(self, number_of_vertices: int = 0):
        self.number_of_vertices = number_of_vertices
        self.number_of_edges = 0
        self.edge_instances = []
        self.outgoing_edge_indices = [[] for _ in range(number_of_vertices)]
        self.incoming_edge_indices = [[] for _ in range(number_of_vertices)]


def read_extended_adjacency_list_from_file(file_name: str) -> ExtendedAdjacencyList:
    """
    Read extended adjacency list from edge list file with self-loop and duplicate edge removal
    
    Args:
        file_name: Name of input file containing edge list
        
    Returns:
        ExtendedAdjacencyList structure containing the graph data
    """
    try:
        with open(file_name, 'r') as input_file:
            number_of_vertices, number_of_edges = map(int, input_file.readline().split())
            
            extended_list = ExtendedAdjacencyList(number_of_vertices)
            existing_edges: Set[Tuple[int, int]] = set()
            edge_counter = 0
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
                    
                    extended_list.edge_instances.append((source_vertex, target_vertex))
                    extended_list.outgoing_edge_indices[source_vertex].append(edge_counter)
                    extended_list.incoming_edge_indices[target_vertex].append(edge_counter)
                    existing_edges.add(edge)
                    edge_counter += 1
            
            extended_list.number_of_edges = edge_counter
            
            if self_loop_count > 0:
                print(f"Total self-loops removed: {self_loop_count}")
            if duplicate_edge_count > 0:
                print(f"Total duplicate edges removed: {duplicate_edge_count}")
            
            return extended_list
    except FileNotFoundError:
        print(f"Error: Cannot open file {file_name}")
        return ExtendedAdjacencyList()
    except Exception as e:
        print(f"Error reading file: {e}")
        return ExtendedAdjacencyList()


def display_extended_adjacency_list(extended_list: ExtendedAdjacencyList) -> None:
    """
    Display extended adjacency list to console
    
    Args:
        extended_list: The extended adjacency list to display
    """
    print("=== Extended Adjacency List (Simple Graph) ===")
    print(f"Number of vertices: {extended_list.number_of_vertices}")
    print(f"Number of edges: {extended_list.number_of_edges}")
    
    print("\nEdge instances:")
    for edge_index, (source, target) in enumerate(extended_list.edge_instances):
        print(f"Edge {edge_index}: ({source}, {target})")
    
    print("\nOutgoing edges by vertex:")
    for vertex_index in range(extended_list.number_of_vertices):
        if extended_list.outgoing_edge_indices[vertex_index]:
            edges = " ".join(map(str, extended_list.outgoing_edge_indices[vertex_index]))
            print(f"Vertex {vertex_index} outgoing: {edges}")
        else:
            print(f"Vertex {vertex_index} outgoing: (no outgoing edges)")
    
    print("\nIncoming edges by vertex:")
    for vertex_index in range(extended_list.number_of_vertices):
        if extended_list.incoming_edge_indices[vertex_index]:
            edges = " ".join(map(str, extended_list.incoming_edge_indices[vertex_index]))
            print(f"Vertex {vertex_index} incoming: {edges}")
        else:
            print(f"Vertex {vertex_index} incoming: (no incoming edges)")
    print()


def write_extended_adjacency_list_to_file(extended_list: ExtendedAdjacencyList, file_name: str) -> None:
    """
    Write extended adjacency list to output file
    
    Args:
        extended_list: The extended adjacency list to write
        file_name: Name of output file
    """
    try:
        with open(file_name, 'w') as output_file:
            output_file.write("=== Extended Adjacency List (Simple Graph) ===\n")
            output_file.write(f"Number of vertices: {extended_list.number_of_vertices}\n")
            output_file.write(f"Number of edges: {extended_list.number_of_edges}\n")
            
            output_file.write("\nEdge instances:\n")
            for edge_index, (source, target) in enumerate(extended_list.edge_instances):
                output_file.write(f"Edge {edge_index}: ({source}, {target})\n")
            
            output_file.write("\nOutgoing edges by vertex:\n")
            for vertex_index in range(extended_list.number_of_vertices):
                if extended_list.outgoing_edge_indices[vertex_index]:
                    edges = " ".join(map(str, extended_list.outgoing_edge_indices[vertex_index]))
                    output_file.write(f"Vertex {vertex_index} outgoing: {edges}\n")
                else:
                    output_file.write(f"Vertex {vertex_index} outgoing: (no outgoing edges)\n")
            
            output_file.write("\nIncoming edges by vertex:\n")
            for vertex_index in range(extended_list.number_of_vertices):
                if extended_list.incoming_edge_indices[vertex_index]:
                    edges = " ".join(map(str, extended_list.incoming_edge_indices[vertex_index]))
                    output_file.write(f"Vertex {vertex_index} incoming: {edges}\n")
                else:
                    output_file.write(f"Vertex {vertex_index} incoming: (no incoming edges)\n")
    except Exception as e:
        print(f"Error: Cannot create file {file_name}: {e}")


def convert_adjacency_list_to_extended(adjacency_data: List[List[int]], 
                                     number_of_vertices: int) -> ExtendedAdjacencyList:
    """
    Convert adjacency list to extended adjacency list with self-loop and duplicate edge removal
    
    Args:
        adjacency_data: The adjacency list data
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        ExtendedAdjacencyList structure containing the converted data
    """
    extended_list = ExtendedAdjacencyList(number_of_vertices)
    existing_edges: Set[Tuple[int, int]] = set()
    edge_counter = 0
    self_loop_count = 0
    duplicate_edge_count = 0
    
    for source_vertex in range(number_of_vertices):
        for target_vertex in adjacency_data[source_vertex]:
            # Skip self-loops
            if source_vertex == target_vertex:
                self_loop_count += 1
                continue
            
            # Skip duplicate edges
            edge = (source_vertex, target_vertex)
            if edge in existing_edges:
                duplicate_edge_count += 1
                continue
            
            if 0 <= target_vertex < number_of_vertices:
                extended_list.edge_instances.append((source_vertex, target_vertex))
                extended_list.outgoing_edge_indices[source_vertex].append(edge_counter)
                extended_list.incoming_edge_indices[target_vertex].append(edge_counter)
                existing_edges.add(edge)
                edge_counter += 1
    
    extended_list.number_of_edges = edge_counter
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to simple graph extended list")
    if duplicate_edge_count > 0:
        print(f"Warning: {duplicate_edge_count} duplicate edges removed during conversion to simple graph extended list")
    
    return extended_list


def convert_matrix_to_extended_adjacency_list(matrix_data: List[List[int]], 
                                            number_of_vertices: int) -> ExtendedAdjacencyList:
    """
    Convert adjacency matrix to extended adjacency list with simple graph validation
    
    Args:
        matrix_data: Matrix data as 2D list
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        ExtendedAdjacencyList structure containing the converted data
    """
    extended_list = ExtendedAdjacencyList(number_of_vertices)
    edge_counter = 0
    self_loop_count = 0
    multiple_edge_count = 0
    
    for source_vertex in range(number_of_vertices):
        for target_vertex in range(number_of_vertices):
            edge_count = matrix_data[source_vertex][target_vertex]
            
            # Skip self-loops
            if source_vertex == target_vertex and edge_count > 0:
                self_loop_count += edge_count
                continue
            
            # Convert multiple edges to single edge
            if edge_count > 1:
                multiple_edge_count += (edge_count - 1)
                extended_list.edge_instances.append((source_vertex, target_vertex))
                extended_list.outgoing_edge_indices[source_vertex].append(edge_counter)
                extended_list.incoming_edge_indices[target_vertex].append(edge_counter)
                edge_counter += 1
            elif edge_count == 1:
                extended_list.edge_instances.append((source_vertex, target_vertex))
                extended_list.outgoing_edge_indices[source_vertex].append(edge_counter)
                extended_list.incoming_edge_indices[target_vertex].append(edge_counter)
                edge_counter += 1
    
    extended_list.number_of_edges = edge_counter
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to simple graph extended list")
    if multiple_edge_count > 0:
        print(f"Warning: {multiple_edge_count} multiple edges converted during conversion to simple graph extended list")
    
    return extended_list


def convert_adjacency_map_to_extended(outgoing_connections: Dict, 
                                    incoming_connections: Dict,
                                    number_of_vertices: int, 
                                    number_of_edges: int) -> ExtendedAdjacencyList:
    """
    Convert adjacency map to extended adjacency list with self-loop and duplicate edge removal
    
    Args:
        outgoing_connections: Map of outgoing connections
        incoming_connections: Map of incoming connections
        number_of_vertices: Number of vertices in the graph
        number_of_edges: Total number of edges
        
    Returns:
        ExtendedAdjacencyList structure containing the converted data
    """
    extended_list = ExtendedAdjacencyList(number_of_vertices)
    existing_edges: Set[Tuple[int, int]] = set()
    edge_counter = 0
    self_loop_count = 0
    duplicate_edge_count = 0
    
    for source_vertex, connections in outgoing_connections.items():
        for target_vertex, edge_data in connections:
            # Skip self-loops
            if source_vertex == target_vertex:
                self_loop_count += 1
                continue
            
            # Skip duplicate edges
            edge = (source_vertex, target_vertex)
            if edge in existing_edges:
                duplicate_edge_count += 1
                continue
            
            if 0 <= target_vertex < number_of_vertices:
                original_source, original_target = edge_data
                extended_list.edge_instances.append((original_source, original_target))
                extended_list.outgoing_edge_indices[source_vertex].append(edge_counter)
                extended_list.incoming_edge_indices[target_vertex].append(edge_counter)
                existing_edges.add(edge)
                edge_counter += 1
    
    extended_list.number_of_edges = edge_counter
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to simple graph extended list")
    if duplicate_edge_count > 0:
        print(f"Warning: {duplicate_edge_count} duplicate edges removed during conversion to simple graph extended list")
    
    return extended_list 