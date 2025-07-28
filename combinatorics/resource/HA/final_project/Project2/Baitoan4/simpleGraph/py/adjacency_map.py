"""
Adjacency Map implementation for Simple Graph
Does NOT support self-loops or multiple edges (maximum 1 edge between any two vertices)
"""

from typing import List, Tuple, Dict, Set
from dataclasses import dataclass


@dataclass
class AdjacencyMap:
    """Structure to represent adjacency map for simple graph"""
    outgoing_connections: Dict[int, List[Tuple[int, Tuple[int, int]]]]
    incoming_connections: Dict[int, List[Tuple[int, Tuple[int, int]]]]
    number_of_vertices: int
    number_of_edges: int
    
    def __init__(self, number_of_vertices: int = 0):
        self.number_of_vertices = number_of_vertices
        self.number_of_edges = 0
        self.outgoing_connections = {i: [] for i in range(number_of_vertices)}
        self.incoming_connections = {i: [] for i in range(number_of_vertices)}


def read_adjacency_map_from_file(file_name: str) -> AdjacencyMap:
    """
    Read adjacency map from edge list file with self-loop and duplicate edge removal
    
    Args:
        file_name: Name of input file containing edge list
        
    Returns:
        AdjacencyMap structure containing the graph data
    """
    try:
        with open(file_name, 'r') as input_file:
            number_of_vertices, number_of_edges = map(int, input_file.readline().split())
            
            adjacency_map = AdjacencyMap(number_of_vertices)
            existing_edges: Set[Tuple[int, int]] = set()
            valid_edge_count = 0
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
                    
                    adjacency_map.outgoing_connections[source_vertex].append(
                        (target_vertex, (source_vertex, target_vertex)))
                    adjacency_map.incoming_connections[target_vertex].append(
                        (source_vertex, (source_vertex, target_vertex)))
                    existing_edges.add(edge)
                    valid_edge_count += 1
            
            adjacency_map.number_of_edges = valid_edge_count
            
            if self_loop_count > 0:
                print(f"Total self-loops removed: {self_loop_count}")
            if duplicate_edge_count > 0:
                print(f"Total duplicate edges removed: {duplicate_edge_count}")
            
            return adjacency_map
    except FileNotFoundError:
        print(f"Error: Cannot open file {file_name}")
        return AdjacencyMap()
    except Exception as e:
        print(f"Error reading file: {e}")
        return AdjacencyMap()


def display_adjacency_map(adjacency_map: AdjacencyMap) -> None:
    """
    Display adjacency map to console
    
    Args:
        adjacency_map: The adjacency map to display
    """
    print("=== Adjacency Map (Simple Graph) ===")
    print(f"Number of vertices: {adjacency_map.number_of_vertices}")
    print(f"Number of edges: {adjacency_map.number_of_edges}")
    
    print("\nOutgoing connections:")
    for vertex_index in range(adjacency_map.number_of_vertices):
        connections = adjacency_map.outgoing_connections[vertex_index]
        print(f"Vertex {vertex_index} -> ", end="")
        if not connections:
            print("(no outgoing connections)")
        else:
            connection_strs = []
            for target_vertex, (orig_source, orig_target) in connections:
                connection_strs.append(f"{target_vertex} [edge({orig_source},{orig_target})]")
            print(", ".join(connection_strs))
    
    print("\nIncoming connections:")
    for vertex_index in range(adjacency_map.number_of_vertices):
        connections = adjacency_map.incoming_connections[vertex_index]
        print(f"Vertex {vertex_index} <- ", end="")
        if not connections:
            print("(no incoming connections)")
        else:
            connection_strs = []
            for source_vertex, (orig_source, orig_target) in connections:
                connection_strs.append(f"{source_vertex} [edge({orig_source},{orig_target})]")
            print(", ".join(connection_strs))
    print()


def write_adjacency_map_to_file(adjacency_map: AdjacencyMap, file_name: str) -> None:
    """
    Write adjacency map to output file
    
    Args:
        adjacency_map: The adjacency map to write
        file_name: Name of output file
    """
    try:
        with open(file_name, 'w') as output_file:
            output_file.write("=== Adjacency Map (Simple Graph) ===\n")
            output_file.write(f"Number of vertices: {adjacency_map.number_of_vertices}\n")
            output_file.write(f"Number of edges: {adjacency_map.number_of_edges}\n")
            
            output_file.write("\nOutgoing connections:\n")
            for vertex_index in range(adjacency_map.number_of_vertices):
                connections = adjacency_map.outgoing_connections[vertex_index]
                output_file.write(f"Vertex {vertex_index} -> ")
                if not connections:
                    output_file.write("(no outgoing connections)\n")
                else:
                    connection_strs = []
                    for target_vertex, (orig_source, orig_target) in connections:
                        connection_strs.append(f"{target_vertex} [edge({orig_source},{orig_target})]")
                    output_file.write(", ".join(connection_strs) + "\n")
            
            output_file.write("\nIncoming connections:\n")
            for vertex_index in range(adjacency_map.number_of_vertices):
                connections = adjacency_map.incoming_connections[vertex_index]
                output_file.write(f"Vertex {vertex_index} <- ")
                if not connections:
                    output_file.write("(no incoming connections)\n")
                else:
                    connection_strs = []
                    for source_vertex, (orig_source, orig_target) in connections:
                        connection_strs.append(f"{source_vertex} [edge({orig_source},{orig_target})]")
                    output_file.write(", ".join(connection_strs) + "\n")
    except Exception as e:
        print(f"Error: Cannot create file {file_name}: {e}")


def convert_adjacency_list_to_map(adjacency_data: List[List[int]], 
                                number_of_vertices: int) -> AdjacencyMap:
    """
    Convert adjacency list to adjacency map with self-loop and duplicate edge removal
    
    Args:
        adjacency_data: The adjacency list data
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyMap structure containing the converted data
    """
    adjacency_map = AdjacencyMap(number_of_vertices)
    existing_edges: Set[Tuple[int, int]] = set()
    valid_edge_count = 0
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
                adjacency_map.outgoing_connections[source_vertex].append(
                    (target_vertex, (source_vertex, target_vertex)))
                adjacency_map.incoming_connections[target_vertex].append(
                    (source_vertex, (source_vertex, target_vertex)))
                existing_edges.add(edge)
                valid_edge_count += 1
    
    adjacency_map.number_of_edges = valid_edge_count
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to simple graph map")
    if duplicate_edge_count > 0:
        print(f"Warning: {duplicate_edge_count} duplicate edges removed during conversion to simple graph map")
    
    return adjacency_map


def convert_extended_list_to_map(outgoing_edge_indices: List[List[int]],
                               incoming_edge_indices: List[List[int]],
                               edge_instances: List[Tuple[int, int]],
                               number_of_vertices: int,
                               number_of_edges: int) -> AdjacencyMap:
    """
    Convert extended adjacency list to adjacency map with self-loop and duplicate edge removal
    
    Args:
        outgoing_edge_indices: Outgoing edge indices per vertex
        incoming_edge_indices: Incoming edge indices per vertex
        edge_instances: All edge instances as (source, target) pairs
        number_of_vertices: Number of vertices in the graph
        number_of_edges: Total number of edges
        
    Returns:
        AdjacencyMap structure containing the converted data
    """
    adjacency_map = AdjacencyMap(number_of_vertices)
    existing_edges: Set[Tuple[int, int]] = set()
    valid_edge_count = 0
    self_loop_count = 0
    duplicate_edge_count = 0
    
    for vertex_index in range(number_of_vertices):
        for edge_index in outgoing_edge_indices[vertex_index]:
            if 0 <= edge_index < len(edge_instances):
                source_vertex, target_vertex = edge_instances[edge_index]
                
                # Skip self-loops
                if source_vertex == target_vertex:
                    self_loop_count += 1
                    continue
                
                # Skip duplicate edges
                edge = (source_vertex, target_vertex)
                if edge in existing_edges:
                    duplicate_edge_count += 1
                    continue
                
                adjacency_map.outgoing_connections[source_vertex].append(
                    (target_vertex, (source_vertex, target_vertex)))
                existing_edges.add(edge)
                valid_edge_count += 1
    
    # Build incoming connections based on valid outgoing edges
    for vertex_pair in adjacency_map.outgoing_connections.items():
        source_vertex = vertex_pair[0]
        connections = vertex_pair[1]
        
        for connection in connections:
            target_vertex = connection[0]
            adjacency_map.incoming_connections[target_vertex].append(
                (source_vertex, (source_vertex, target_vertex)))
    
    adjacency_map.number_of_edges = valid_edge_count
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to simple graph map")
    if duplicate_edge_count > 0:
        print(f"Warning: {duplicate_edge_count} duplicate edges removed during conversion to simple graph map")
    
    return adjacency_map


def convert_matrix_to_adjacency_map(matrix_data: List[List[int]], 
                                  number_of_vertices: int) -> AdjacencyMap:
    """
    Convert adjacency matrix to adjacency map with simple graph validation
    
    Args:
        matrix_data: Matrix data as 2D list
        number_of_vertices: Number of vertices in the graph
        
    Returns:
        AdjacencyMap structure containing the converted data
    """
    adjacency_map = AdjacencyMap(number_of_vertices)
    valid_edge_count = 0
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
                adjacency_map.outgoing_connections[source_vertex].append(
                    (target_vertex, (source_vertex, target_vertex)))
                adjacency_map.incoming_connections[target_vertex].append(
                    (source_vertex, (source_vertex, target_vertex)))
                valid_edge_count += 1
            elif edge_count == 1:
                adjacency_map.outgoing_connections[source_vertex].append(
                    (target_vertex, (source_vertex, target_vertex)))
                adjacency_map.incoming_connections[target_vertex].append(
                    (source_vertex, (source_vertex, target_vertex)))
                valid_edge_count += 1
    
    adjacency_map.number_of_edges = valid_edge_count
    
    if self_loop_count > 0:
        print(f"Warning: {self_loop_count} self-loops removed during conversion to simple graph map")
    if multiple_edge_count > 0:
        print(f"Warning: {multiple_edge_count} multiple edges converted during conversion to simple graph map")
    
    return adjacency_map 