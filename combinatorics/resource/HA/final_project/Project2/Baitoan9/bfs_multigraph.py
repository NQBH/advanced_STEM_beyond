#!/usr/bin/env python3
"""
@file bfs_multigraph.py
@brief Breadth-First Search implementation for Multi Graph
@details Supports graphs with parallel edges but NO self-loops using adjacency list representation
"""

from typing import List, Optional, Deque, Dict, Tuple
from collections import deque
import sys


class MultiGraph:
    """
    Represents a multi graph with BFS traversal capabilities
    """
    
    def __init__(self, vertex_count: int):
        """
        Constructs a multi graph with specified number of vertices
        
        Args:
            vertex_count: Number of vertices in the graph
        """
        self._adjacency_list: List[List[int]] = [[] for _ in range(vertex_count)]
        self._number_of_vertices: int = vertex_count
        self._visited_vertices: List[bool] = [False] * vertex_count
        self._traversal_order: List[int] = []
        self._distances: List[int] = [-1] * vertex_count
        self._parents: List[int] = [-1] * vertex_count
    
    def _reset_traversal_status(self) -> None:
        """
        Resets visited status and other tracking arrays
        """
        self._visited_vertices = [False] * self._number_of_vertices
        self._traversal_order.clear()
        self._distances = [-1] * self._number_of_vertices
        self._parents = [-1] * self._number_of_vertices
    
    def _is_valid_vertex(self, vertex: int) -> bool:
        """
        Validates that vertices are within valid range
        
        Args:
            vertex: Vertex to validate
            
        Returns:
            True if vertex is valid
        """
        return 0 <= vertex < self._number_of_vertices
    
    def add_edge(self, source_vertex: int, target_vertex: int) -> bool:
        """
        Adds an edge to the multi graph with validation
        
        Args:
            source_vertex: Source vertex of the edge
            target_vertex: Target vertex of the edge
            
        Returns:
            True if edge was added successfully
        """
        if not self._is_valid_vertex(source_vertex) or not self._is_valid_vertex(target_vertex):
            print(f"Warning: Invalid vertex index ({source_vertex}, {target_vertex}). "
                  f"Vertices must be in range [0, {self._number_of_vertices - 1}]", file=sys.stderr)
            return False
        
        if source_vertex == target_vertex:
            print(f"Warning: Self-loop detected ({source_vertex} -> {target_vertex}). "
                  f"Multi graphs do not support self-loops. Edge ignored.", file=sys.stderr)
            return False
        
        # Multi graphs allow parallel edges but not self-loops
        self._adjacency_list[source_vertex].append(target_vertex)
        self._adjacency_list[target_vertex].append(source_vertex)
        return True
    
    def execute_bfs(self, start_vertex: int) -> List[int]:
        """
        Executes BFS traversal using queue-based approach
        
        Args:
            start_vertex: Starting vertex for traversal
            
        Returns:
            List containing vertices in BFS order
        """
        if not self._is_valid_vertex(start_vertex):
            print(f"Error: Invalid starting vertex {start_vertex}", file=sys.stderr)
            return []
        
        self._reset_traversal_status()
        bfs_queue: Deque[int] = deque()
        
        self._visited_vertices[start_vertex] = True
        self._distances[start_vertex] = 0
        bfs_queue.append(start_vertex)
        
        while bfs_queue:
            current_vertex = bfs_queue.popleft()
            self._traversal_order.append(current_vertex)
            
            for neighbor in self._adjacency_list[current_vertex]:
                if not self._visited_vertices[neighbor]:
                    self._visited_vertices[neighbor] = True
                    self._distances[neighbor] = self._distances[current_vertex] + 1
                    self._parents[neighbor] = current_vertex
                    bfs_queue.append(neighbor)
        
        return self._traversal_order.copy()
    
    def find_connected_components(self) -> List[List[int]]:
        """
        Finds all connected components using BFS
        
        Returns:
            List of lists, each containing vertices of a connected component
        """
        components: List[List[int]] = []
        self._reset_traversal_status()
        
        for vertex in range(self._number_of_vertices):
            if not self._visited_vertices[vertex]:
                component = self._execute_bfs_component(vertex)
                if component:
                    components.append(component)
        
        return components
    
    def get_distance(self, vertex: int) -> int:
        """
        Gets the shortest distance to a vertex from last BFS start
        
        Args:
            vertex: Target vertex
            
        Returns:
            Distance to vertex, or -1 if unreachable
        """
        if not self._is_valid_vertex(vertex):
            return -1
        return self._distances[vertex]
    
    def get_parent(self, vertex: int) -> int:
        """
        Gets the parent of a vertex in BFS tree from last traversal
        
        Args:
            vertex: Target vertex
            
        Returns:
            Parent vertex, or -1 if no parent
        """
        if not self._is_valid_vertex(vertex):
            return -1
        return self._parents[vertex]
    
    def get_shortest_path(self, target_vertex: int) -> List[int]:
        """
        Gets the shortest path from last BFS start to target vertex
        
        Args:
            target_vertex: Target vertex
            
        Returns:
            List containing path vertices, empty if no path exists
        """
        if not self._is_valid_vertex(target_vertex) or self._distances[target_vertex] == -1:
            return []
        
        path: List[int] = []
        current = target_vertex
        
        while current != -1:
            path.append(current)
            current = self._parents[current]
        
        path.reverse()
        return path
    
    def get_vertex_count(self) -> int:
        """
        Gets the number of vertices in the graph
        
        Returns:
            Number of vertices
        """
        return self._number_of_vertices
    
    def get_total_edge_count(self) -> int:
        """
        Counts total number of edges including parallel edges
        
        Returns:
            Total edge count
        """
        total_edges = sum(len(neighbors) for neighbors in self._adjacency_list)
        return total_edges // 2  # Each undirected edge counted twice (no self-loops in multi graph)
    
    def display_graph(self) -> str:
        """
        Returns the adjacency list representation with parallel edge indication
        
        Returns:
            String representation of adjacency list
        """
        result = "\nMulti Graph - Adjacency List Representation:\n"
        result += "Parallel edges allowed, NO self-loops\n"
        
        for vertex in range(self._number_of_vertices):
            result += f"Vertex {vertex}: "
            if self._adjacency_list[vertex]:
                result += " -> ".join(map(str, self._adjacency_list[vertex]))
            result += "\n"
        
        result += f"Total vertices: {self._number_of_vertices}\n"
        result += f"Total edges: {self.get_total_edge_count()}\n"
        
        return result
    
    def display_parallel_edge_statistics(self) -> str:
        """
        Returns parallel edge statistics
        
        Returns:
            String with parallel edge analysis
        """
        edge_count: Dict[Tuple[int, int], int] = {}
        
        for vertex in range(self._number_of_vertices):
            for neighbor in self._adjacency_list[vertex]:
                if vertex < neighbor:  # Count each edge only once
                    edge = (vertex, neighbor)
                    edge_count[edge] = edge_count.get(edge, 0) + 1
        
        result = "\nParallel Edge Analysis:\n"
        has_parallel_edges = False
        
        for edge, count in edge_count.items():
            if count > 1:
                has_parallel_edges = True
                result += f"Edge ({edge[0]}, {edge[1]}) appears {count} times\n"
        
        if not has_parallel_edges:
            result += "No parallel edges detected in this multi graph.\n"
        
        return result
    
    def display_bfs_tree(self, start_vertex: int) -> str:
        """
        Returns BFS tree information
        
        Args:
            start_vertex: Starting vertex of last BFS
            
        Returns:
            String with BFS tree information
        """
        result = f"\nBFS Tree Information (from vertex {start_vertex}):\n"
        result += "Vertex | Distance | Parent\n"
        result += "-------|----------|-------\n"
        
        for vertex in range(self._number_of_vertices):
            result += f"{vertex:6} | "
            if self._distances[vertex] == -1:
                result += f"{'INF':8} | N/A"
            else:
                result += f"{self._distances[vertex]:8} | "
                if self._parents[vertex] == -1:
                    result += "NIL"
                else:
                    result += str(self._parents[vertex])
            result += "\n"
        
        return result
    
    def _execute_bfs_component(self, start_vertex: int) -> List[int]:
        """
        Helper function for finding connected components
        
        Args:
            start_vertex: Starting vertex for component search
            
        Returns:
            List containing vertices in the component
        """
        component: List[int] = []
        bfs_queue: Deque[int] = deque()
        
        self._visited_vertices[start_vertex] = True
        bfs_queue.append(start_vertex)
        
        while bfs_queue:
            current_vertex = bfs_queue.popleft()
            component.append(current_vertex)
            
            for neighbor in self._adjacency_list[current_vertex]:
                if not self._visited_vertices[neighbor]:
                    self._visited_vertices[neighbor] = True
                    bfs_queue.append(neighbor)
        
        return component


class MultiGraphInputHandler:
    """
    Handles input operations for multi graph construction
    """
    
    def __init__(self, input_source):
        """
        Constructs input handler with specified source
        
        Args:
            input_source: Input source to read from (file object or similar)
        """
        self._input_source = input_source
    
    def read_graph_data(self) -> MultiGraph:
        """
        Reads graph data and constructs MultiGraph
        
        Returns:
            Constructed MultiGraph instance
        """
        line = self._input_source.readline().strip()
        vertex_count, edge_count = map(int, line.split())
        
        graph = MultiGraph(vertex_count)
        successful_edges = 0
        
        for _ in range(edge_count):
            line = self._input_source.readline().strip()
            source_vertex, target_vertex = map(int, line.split())
            if graph.add_edge(source_vertex, target_vertex):
                successful_edges += 1
        
        print(f"Successfully added {successful_edges} out of {edge_count} edges to multi graph.")
        
        return graph
    
    def read_starting_vertex(self) -> int:
        """
        Reads starting vertex for BFS traversal
        
        Returns:
            Starting vertex index
        """
        line = self._input_source.readline().strip()
        return int(line)


class MultiGraphOutputHandler:
    """
    Handles output operations for BFS results
    """
    
    def __init__(self, output_target=sys.stdout):
        """
        Constructs output handler with specified target
        
        Args:
            output_target: Output target to write to
        """
        self._output_target = output_target
    
    def display_traversal_result(self, traversal_result: List[int], start_vertex: int) -> None:
        """
        Displays BFS traversal results
        
        Args:
            traversal_result: List containing vertices in BFS order
            start_vertex: Starting vertex
        """
        if not traversal_result:
            self._output_target.write("BFS traversal: No traversal performed (invalid input)\n")
            return
        
        result_str = " -> ".join(map(str, traversal_result))
        self._output_target.write(f"BFS traversal from vertex {start_vertex}: {result_str}\n")
    
    def display_connected_components(self, components: List[List[int]]) -> None:
        """
        Displays connected components
        
        Args:
            components: List of connected components
        """
        self._output_target.write("\nConnected Components Analysis:\n")
        for i, component in enumerate(components, 1):
            component_str = " ".join(map(str, component))
            self._output_target.write(f"Component {i}: {component_str}\n")
        self._output_target.write(f"Total connected components: {len(components)}\n")
    
    def display_shortest_path(self, graph: MultiGraph, start_vertex: int, target_vertex: int) -> None:
        """
        Displays shortest path information
        
        Args:
            graph: Reference to the graph
            start_vertex: Starting vertex
            target_vertex: Target vertex
        """
        path = graph.get_shortest_path(target_vertex)
        
        if not path:
            self._output_target.write(f"No path exists from vertex {start_vertex} to vertex {target_vertex}\n")
            else:
            path_str = " -> ".join(map(str, path))
            distance = graph.get_distance(target_vertex)
            self._output_target.write(f"Shortest path from {start_vertex} to {target_vertex}: {path_str} (distance: {distance})\n")
    
    def display_program_header(self) -> None:
        """
        Displays program header information
        """
        self._output_target.write("=== Breadth-First Search for Multi Graph ===\n")
        self._output_target.write("Supporting parallel edges, NO self-loops\n")


class MultiGraphBFSApplication:
    """
    Coordinates the Multi Graph BFS application workflow
    """
    
    def __init__(self, input_source, output_target=sys.stdout):
        """
        Constructs BFS application with I/O sources
        
        Args:
            input_source: Input source for reading data
            output_target: Output target for displaying results
        """
        self._graph_instance: Optional[MultiGraph] = None
        self._input_handler = MultiGraphInputHandler(input_source)
        self._output_handler = MultiGraphOutputHandler(output_target)
    
    def execute_application(self) -> None:
        """
        Executes the complete Multi Graph BFS application workflow
        """
        self._output_handler.display_program_header()
        self._graph_instance = self._input_handler.read_graph_data()
        starting_vertex = self._input_handler.read_starting_vertex()
        self._perform_bfs_analysis(starting_vertex)
    
    def _perform_bfs_analysis(self, start_vertex: int) -> None:
        """
        Performs comprehensive BFS analysis
        
        Args:
            start_vertex: Starting vertex for analysis
        """
        if self._graph_instance is None:
            raise ValueError("Graph instance not initialized")
        
        # Display graph structure
        print(self._graph_instance.display_graph())
        print(self._graph_instance.display_parallel_edge_statistics())
        
        # Perform BFS traversal
        bfs_result = self._graph_instance.execute_bfs(start_vertex)
        self._output_handler.display_traversal_result(bfs_result, start_vertex)
        
        # Display BFS tree information
        print(self._graph_instance.display_bfs_tree(start_vertex))
        
        # Find and display connected components
        components = self._graph_instance.find_connected_components()
        self._output_handler.display_connected_components(components)
        
        # Display shortest path examples to all reachable vertices
        print(f"\nShortest Paths from vertex {start_vertex}:")
        for target in range(self._graph_instance.get_vertex_count()):
            if target != start_vertex and self._graph_instance.get_distance(target) != -1:
                self._output_handler.display_shortest_path(self._graph_instance, start_vertex, target)


def main() -> int:
    """
    Main program entry point
    
    Returns:
        Program exit status
    """
    try:
        with open("input.txt", "r", encoding="utf-8") as input_file:
            application = MultiGraphBFSApplication(input_file)
            application.execute_application()
    except FileNotFoundError:
        print("Error: Cannot open input.txt file", file=sys.stderr)
        return 1
    except Exception as error:
        print(f"Error occurred: {error}", file=sys.stderr)
        return 1
    
    return 0


if __name__ == "__main__":
    sys.exit(main()) 