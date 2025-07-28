#!/usr/bin/env python3
"""
@file dfs_generalgraph.py
@brief Depth-First Search implementation for General Graph
@details Supports graphs with self-loops and parallel edges using adjacency list representation
"""

from typing import List, Optional
import sys


class GeneralGraph:
    """
    Represents a general graph with DFS traversal capabilities
    """
    
    def __init__(self, vertex_count: int):
        """
        Constructs a general graph with specified number of vertices
        
        Args:
            vertex_count: Number of vertices in the graph
        """
        self._adjacency_list: List[List[int]] = [[] for _ in range(vertex_count)]
        self._number_of_vertices: int = vertex_count
        self._visited_vertices: List[bool] = [False] * vertex_count
        self._traversal_order: List[int] = []
    
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
    
    def add_edge(self, source_vertex: int, target_vertex: int) -> None:
        """
        Adds an edge to the graph
        
        Args:
            source_vertex: Source vertex of the edge
            target_vertex: Target vertex of the edge
        """
        self._adjacency_list[source_vertex].append(target_vertex)
        self._adjacency_list[target_vertex].append(source_vertex)
    
    def execute_recursive_dfs(self, start_vertex: int) -> List[int]:
        """
        Executes DFS traversal using recursive approach
        
        Args:
            start_vertex: Starting vertex for traversal
            
        Returns:
            List containing vertices in DFS order
        """
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
    
    def display_graph(self) -> str:
        """
        Returns the adjacency list representation as string
        
        Returns:
            String representation of adjacency list
        """
        result = "\nAdjacency List Representation:\n"
        for vertex in range(self._number_of_vertices):
            result += f"Vertex {vertex}: "
            if self._adjacency_list[vertex]:
                result += " -> ".join(map(str, self._adjacency_list[vertex]))
            result += "\n"
        return result


class GraphInputHandler:
    """
    Handles input operations for graph construction
    """
    
    def __init__(self, input_source):
        """
        Constructs input handler with specified source
        
        Args:
            input_source: Input source to read from (file object or similar)
        """
        self._input_source = input_source
    
    def read_graph_data(self) -> GeneralGraph:
        """
        Reads graph data and constructs GeneralGraph
        
        Returns:
            Constructed GeneralGraph instance
        """
        line = self._input_source.readline().strip()
        vertex_count, edge_count = map(int, line.split())
        
        graph = GeneralGraph(vertex_count)
        
        for _ in range(edge_count):
            line = self._input_source.readline().strip()
            source_vertex, target_vertex = map(int, line.split())
            graph.add_edge(source_vertex, target_vertex)
        
        return graph
    
    def read_starting_vertex(self) -> int:
        """
        Reads starting vertex for DFS traversal
        
        Returns:
            Starting vertex index
        """
        line = self._input_source.readline().strip()
        return int(line)


class DFSOutputHandler:
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
        result_str = " ".join(map(str, traversal_result))
        self._output_target.write(f"DFS {traversal_type}: {result_str}\n")
    
    def display_program_header(self) -> None:
        """
        Displays program header information
        """
        self._output_target.write("=== Depth-First Search for General Graph ===\n")
        self._output_target.write("Supporting self-loops and parallel edges\n")


class DFSApplication:
    """
    Coordinates the DFS application workflow
    """
    
    def __init__(self, input_source, output_target=sys.stdout):
        """
        Constructs DFS application with I/O sources
        
        Args:
            input_source: Input source for reading data
            output_target: Output target for displaying results
        """
        self._graph_instance: Optional[GeneralGraph] = None
        self._input_handler = GraphInputHandler(input_source)
        self._output_handler = DFSOutputHandler(output_target)
    
    def execute_application(self) -> None:
        """
        Executes the complete DFS application workflow
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
            application = DFSApplication(input_file)
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