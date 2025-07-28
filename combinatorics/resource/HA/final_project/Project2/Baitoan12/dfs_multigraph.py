#!/usr/bin/env python3
"""
@file dfs_multigraph.py
@brief Depth-First Search implementation for Multi Graph
@details Supports graphs with parallel edges but NO self-loops using adjacency list representation
"""

from typing import List, Optional, Dict, Tuple
import sys


class MultiGraph:
    """
    Represents a multi graph with DFS traversal capabilities
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
        
        self._adjacency_list[source_vertex].append(target_vertex)
        self._adjacency_list[target_vertex].append(source_vertex)
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
    
    def get_total_edge_count(self) -> int:
        """
        Counts total number of edges including parallel edges
        
        Returns:
            Total edge count
        """
        total_edges = sum(len(neighbors) for neighbors in self._adjacency_list)
        return total_edges // 2  # Each undirected edge counted twice
    
    def display_graph(self) -> str:
        """
        Returns the adjacency list representation with parallel edge indication
        
        Returns:
            String representation of adjacency list
        """
        result = "\nMulti Graph - Adjacency List Representation:\n"
        result += "Parallel edges are shown as repeated connections\n"
        
        for vertex in range(self._number_of_vertices):
            result += f"Vertex {vertex}: "
            if self._adjacency_list[vertex]:
                result += " -> ".join(map(str, self._adjacency_list[vertex]))
            result += "\n"
        
        result += f"Total vertices: {self._number_of_vertices}\n"
        result += f"Total edges (including parallel): {self.get_total_edge_count()}\n"
        
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
        
        print(f"Successfully added {successful_edges} out of {edge_count} edges.")
            
            return graph
    
    def read_starting_vertex(self) -> int:
        """
        Reads starting vertex for DFS traversal
        
        Returns:
            Starting vertex index
        """
        line = self._input_source.readline().strip()
        return int(line)


class MultiGraphOutputHandler:
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
        self._output_target.write("=== Depth-First Search for Multi Graph ===\n")
        self._output_target.write("Supporting parallel edges, NO self-loops\n")


class MultiGraphDFSApplication:
    """
    Coordinates the Multi Graph DFS application workflow
    """
    
    def __init__(self, input_source, output_target=sys.stdout):
        """
        Constructs DFS application with I/O sources
        
        Args:
            input_source: Input source for reading data
            output_target: Output target for displaying results
        """
        self._graph_instance: Optional[MultiGraph] = None
        self._input_handler = MultiGraphInputHandler(input_source)
        self._output_handler = MultiGraphOutputHandler(output_target)
    
    def execute_application(self) -> None:
        """
        Executes the complete Multi Graph DFS application workflow
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
        print(self._graph_instance.display_parallel_edge_statistics())
        
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
            application = MultiGraphDFSApplication(input_file)
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
