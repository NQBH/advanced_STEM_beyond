#!/usr/bin/env python3
"""
@file dfs_simplegraph.py
@brief Depth-First Search implementation for Simple Graph
@details Supports graphs with NO self-loops and NO parallel edges using adjacency list representation
"""

from typing import List, Optional, Set, Tuple
import sys


class SimpleGraph:
    """
    Represents a simple graph with DFS traversal capabilities
    """
    
    def __init__(self, vertex_count: int):
        """
        Constructs a simple graph with specified number of vertices
        
        Args:
            vertex_count: Number of vertices in the graph
        """
        self._adjacency_list: List[List[int]] = [[] for _ in range(vertex_count)]
        self._number_of_vertices: int = vertex_count
        self._visited_vertices: List[bool] = [False] * vertex_count
        self._traversal_order: List[int] = []
        self._existing_edges: Set[Tuple[int, int]] = set()  # Track edges to prevent duplicates
    
    def _perform_recursive_dfs(self, current_vertex: int) -> None:
        """
        Performs recursive DFS from given vertex
        
        Args:
            current_vertex: Starting vertex for DFS
        """
        self._visited_vertices[current_vertex] = True
        self._traversal_order.append(current_vertex)
        
        for neighbor in self._adjacency_list[current_vertex]:
            if not self._visited_vertices[neighbor]:
                self._perform_recursive_dfs(neighbor)
    
    def _reset_visited_status(self) -> None:
        """
        Resets visited status for all vertices
        """
        self._visited_vertices = [False] * self._number_of_vertices
        self._traversal_order.clear()
    
    def _is_valid_vertex(self, vertex: int) -> bool:
        """
        Validates that vertices are within valid range
        
        Args:
            vertex: Vertex to validate
            
        Returns:
            True if vertex is valid
        """
        return 0 <= vertex < self._number_of_vertices
    
    def _edge_exists(self, source_vertex: int, target_vertex: int) -> bool:
        """
        Checks if edge already exists in the simple graph
        
        Args:
            source_vertex: Source vertex
            target_vertex: Target vertex
            
        Returns:
            True if edge already exists
        """
        edge = (min(source_vertex, target_vertex), max(source_vertex, target_vertex))
        return edge in self._existing_edges
    
    def add_edge(self, source_vertex: int, target_vertex: int) -> bool:
        """
        Adds an edge to the simple graph with validation
        
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
                  f"Simple graphs do not support self-loops. Edge ignored.", file=sys.stderr)
            return False
        
        if self._edge_exists(source_vertex, target_vertex):
            print(f"Warning: Parallel edge detected ({source_vertex} <-> {target_vertex}). "
                  f"Simple graphs do not support parallel edges. Edge ignored.", file=sys.stderr)
            return False
        
        # Add edge to adjacency list
        self._adjacency_list[source_vertex].append(target_vertex)
        self._adjacency_list[target_vertex].append(source_vertex)
        
        # Record edge in set to prevent duplicates
        edge = (min(source_vertex, target_vertex), max(source_vertex, target_vertex))
        self._existing_edges.add(edge)
        
        return True
    
    def execute_recursive_dfs(self, start_vertex: int) -> List[int]:
        """
        Executes DFS traversal using recursive approach
        
        Args:
            start_vertex: Starting vertex for traversal
            
        Returns:
            List containing vertices in DFS order
        """
        if not self._is_valid_vertex(start_vertex):
            print(f"Error: Invalid starting vertex {start_vertex}", file=sys.stderr)
            return []
        
        self._reset_visited_status()
        self._perform_recursive_dfs(start_vertex)
        return self._traversal_order.copy()
    
    def execute_iterative_dfs(self, start_vertex: int) -> List[int]:
        """
        Executes DFS traversal using iterative approach with stack
        
        Args:
            start_vertex: Starting vertex for traversal
            
        Returns:
            List containing vertices in DFS order
        """
        if not self._is_valid_vertex(start_vertex):
            print(f"Error: Invalid starting vertex {start_vertex}", file=sys.stderr)
            return []
        
        self._reset_visited_status()
        dfs_stack = [start_vertex]
        
        while dfs_stack:
            current_vertex = dfs_stack.pop()
            if not self._visited_vertices[current_vertex]:
                self._visited_vertices[current_vertex] = True
                self._traversal_order.append(current_vertex)
                
                # Add neighbors in reverse order to maintain same traversal order as C++
                for neighbor in reversed(self._adjacency_list[current_vertex]):
                    if not self._visited_vertices[neighbor]:
                        dfs_stack.append(neighbor)
        
        return self._traversal_order.copy()
    
    def get_vertex_count(self) -> int:
        """
        Gets the number of vertices in the graph
        
        Returns:
            Number of vertices
        """
        return self._number_of_vertices
    
    def get_edge_count(self) -> int:
        """
        Gets the number of edges in the simple graph
        
        Returns:
            Number of edges
        """
        return len(self._existing_edges)
    
    def display_graph(self) -> str:
        """
        Returns the adjacency list representation
        
        Returns:
            String representation of adjacency list
        """
        result = "\nSimple Graph - Adjacency List Representation:\n"
        result += "No self-loops, no parallel edges\n"
        
        for vertex in range(self._number_of_vertices):
            result += f"Vertex {vertex}: "
            if self._adjacency_list[vertex]:
                result += " -> ".join(map(str, self._adjacency_list[vertex]))
            result += "\n"
        
        result += f"Total vertices: {self._number_of_vertices}\n"
        result += f"Total edges: {self.get_edge_count()}\n"
        
        return result
    
    def display_graph_validation(self) -> str:
        """
        Returns simple graph validation statistics
        
        Returns:
            String with validation information
        """
        max_edges = (self._number_of_vertices * (self._number_of_vertices - 1)) // 2
        current_edges = self.get_edge_count()
        
        result = "\nSimple Graph Validation:\n"
        result += "* No self-loops allowed\n"
        result += "* No parallel edges allowed\n"
        result += f"* Maximum possible edges: {max_edges}\n"
        result += f"* Current edges: {current_edges}\n"
        
        if current_edges == max_edges:
            result += "* This is a complete simple graph!\n"
        
        return result


class SimpleGraphInputHandler:
    """
    Handles input operations for simple graph construction
    """
    
    def __init__(self, input_source):
        """
        Constructs input handler with specified source
        
        Args:
            input_source: Input source to read from (file object or similar)
        """
        self._input_source = input_source
    
    def read_graph_data(self) -> SimpleGraph:
        """
        Reads graph data and constructs SimpleGraph
        
        Returns:
            Constructed SimpleGraph instance
        """
        line = self._input_source.readline().strip()
        vertex_count, edge_count = map(int, line.split())
        
        graph = SimpleGraph(vertex_count)
        successful_edges = 0
        
        for _ in range(edge_count):
            line = self._input_source.readline().strip()
            source_vertex, target_vertex = map(int, line.split())
            if graph.add_edge(source_vertex, target_vertex):
                successful_edges += 1
        
        print(f"Successfully added {successful_edges} out of {edge_count} edges to simple graph.")
        
        return graph
    
    def read_starting_vertex(self) -> int:
        """
        Reads starting vertex for DFS traversal
        
        Returns:
            Starting vertex index
        """
        line = self._input_source.readline().strip()
        return int(line)


class SimpleGraphOutputHandler:
    """
    Handles output operations for DFS results
    """
    
    def __init__(self, output_target=sys.stdout):
        """
        Constructs output handler with specified target
        
        Args:
            output_target: Output target to write to
        """
        self._output_target = output_target
    
    def display_traversal_result(self, traversal_result: List[int], traversal_type: str) -> None:
        """
        Displays DFS traversal results
        
        Args:
            traversal_result: List containing vertices in DFS order
            traversal_type: Description of traversal method
        """
        if not traversal_result:
            self._output_target.write(f"DFS {traversal_type}: No traversal performed (invalid input)\n")
            return
        
        result_str = " ".join(map(str, traversal_result))
        self._output_target.write(f"DFS {traversal_type}: {result_str}\n")
    
    def display_program_header(self) -> None:
        """
        Displays program header information
        """
        self._output_target.write("=== Depth-First Search for Simple Graph ===\n")
        self._output_target.write("NO self-loops, NO parallel edges\n")


class SimpleGraphDFSApplication:
    """
    Coordinates the Simple Graph DFS application workflow
    """
    
    def __init__(self, input_source, output_target=sys.stdout):
        """
        Constructs DFS application with I/O sources
        
        Args:
            input_source: Input source for reading data
            output_target: Output target for displaying results
        """
        self._graph_instance: Optional[SimpleGraph] = None
        self._input_handler = SimpleGraphInputHandler(input_source)
        self._output_handler = SimpleGraphOutputHandler(output_target)
    
    def execute_application(self) -> None:
        """
        Executes the complete Simple Graph DFS application workflow
        """
        self._output_handler.display_program_header()
        self._graph_instance = self._input_handler.read_graph_data()
        starting_vertex = self._input_handler.read_starting_vertex()
        self._perform_dfs_analysis(starting_vertex)
    
    def _perform_dfs_analysis(self, start_vertex: int) -> None:
        """
        Performs DFS analysis using both recursive and iterative methods
        
        Args:
            start_vertex: Starting vertex for analysis
        """
        if self._graph_instance is None:
            raise ValueError("Graph instance not initialized")
        
        # Display graph structure
        print(self._graph_instance.display_graph())
        print(self._graph_instance.display_graph_validation())
        
        # Execute both DFS approaches
        recursive_result = self._graph_instance.execute_recursive_dfs(start_vertex)
        self._output_handler.display_traversal_result(recursive_result, "using recursion")
        
        iterative_result = self._graph_instance.execute_iterative_dfs(start_vertex)
        self._output_handler.display_traversal_result(iterative_result, "using iteration")


def main() -> int:
    """
    Main program entry point
    
    Returns:
        Program exit status
    """
    try:
        with open("input.txt", "r", encoding="utf-8") as input_file:
            application = SimpleGraphDFSApplication(input_file)
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