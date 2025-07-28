import heapq
from collections import defaultdict
from typing import List, Tuple, Dict, Set
import sys

class Graph:
    """Base class for all graph types implementing Dijkstra's algorithm"""
    
    def __init__(self, vertices: int, graph_type: str):
        self.vertices = vertices
        self.graph_type = graph_type
        self.adj = defaultdict(list)  # Adjacency list
        
    def add_edge(self, from_vertex: int, to_vertex: int, weight: int):
        """Abstract method to be implemented by subclasses"""
        raise NotImplementedError("Subclasses must implement add_edge method")
    
    def print_graph(self):
        """Print the graph structure"""
        print(f"\n=== {self.graph_type} Structure ===")
        for vertex in range(self.vertices):
            edges = self.adj[vertex]
            print(f"Vertex {vertex}: {edges}")
    
    def dijkstra(self, source: int) -> Tuple[List[int], List[int]]:
        """
        Dijkstra's algorithm implementation
        Returns: (distances, parents) where distances[i] is shortest distance to vertex i
                 and parents[i] is parent of vertex i in shortest path tree
        """
        # Initialize distances and parents
        distances = [float('inf')] * self.vertices
        parents = [-1] * self.vertices
        distances[source] = 0
        
        # Priority queue: (distance, vertex)
        pq = [(0, source)]
        visited = set()
        
        print(f"\n=== Dijkstra's Algorithm Execution for {self.graph_type} ===")
        print(f"Source vertex: {source}")
        
        while pq:
            current_dist, u = heapq.heappop(pq)
            
            # Skip if already processed with better distance
            if u in visited:
                continue
                
            visited.add(u)
            print(f"\nProcessing vertex {u} (distance: {distances[u]})")
            
            # Examine all neighbors
            for edge_info in self.adj[u]:
                # Handle different edge formats for different graph types
                if isinstance(edge_info, dict):
                    v = edge_info['to']
                    weight = edge_info['weight']
                    edge_id = edge_info.get('id', '')
                else:
                    # Simple tuple format (to, weight)
                    v, weight = edge_info
                    edge_id = ''
                
                # Relaxation step
                if distances[u] + weight < distances[v]:
                    old_dist = distances[v]
                    distances[v] = distances[u] + weight
                    parents[v] = u
                    heapq.heappush(pq, (distances[v], v))
                    
                    id_str = f" (ID: {edge_id})" if edge_id else ""
                    print(f"  Relaxing edge {u} -> {v} (weight: {weight}{id_str}, "
                          f"old distance: {old_dist if old_dist != float('inf') else 'INF'}, "
                          f"new distance: {distances[v]})")
        
        return distances, parents
    
    def print_shortest_paths(self, source: int, distances: List[int], parents: List[int]):
        """Print shortest paths from source to all vertices"""
        print(f"\n=== Shortest Paths from vertex {source} ===")
        print("Vertex\tDistance\tPath")
        print("------\t--------\t----")
        
        for vertex in range(self.vertices):
            print(f"{vertex}\t", end="")
            if distances[vertex] == float('inf'):
                print("INF\t\tNo path")
            else:
                print(f"{distances[vertex]}\t\t", end="")
                path = self._construct_path(parents, vertex)
                print(" -> ".join(map(str, path)))
    
    def _construct_path(self, parents: List[int], vertex: int) -> List[int]:
        """Construct path from source to given vertex using parent array"""
        path = []
        current = vertex
        while current != -1:
            path.append(current)
            current = parents[current]
        return path[::-1]


class SimpleGraph(Graph):
    """Simple Graph: No loops, no multiple edges"""
    
    def __init__(self, vertices: int):
        super().__init__(vertices, "Simple Graph")
        self.edge_set = set()  # To track existing edges
    
    def add_edge(self, from_vertex: int, to_vertex: int, weight: int):
        """Add edge with simple graph constraints"""
        # Check for self-loops
        if from_vertex == to_vertex:
            print(f"Error: Cannot add self-loop ({from_vertex},{to_vertex}) in simple graph!")
            return
        
        # Check for existing edges (undirected)
        edge1 = (from_vertex, to_vertex)
        edge2 = (to_vertex, from_vertex)
        
        if edge1 in self.edge_set or edge2 in self.edge_set:
            print(f"Error: Edge ({from_vertex},{to_vertex}) already exists in simple graph!")
            return
        
        # Add edge to adjacency list (undirected)
        self.adj[from_vertex].append((to_vertex, weight))
        self.adj[to_vertex].append((from_vertex, weight))
        self.edge_set.add(edge1)
        
        print(f"Added edge {from_vertex} <-> {to_vertex} with weight {weight}")


class Multigraph(Graph):
    """Multigraph: No loops, but multiple edges allowed"""
    
    def __init__(self, vertices: int):
        super().__init__(vertices, "Multigraph")
        self.edge_counter = 0
    
    def add_edge(self, from_vertex: int, to_vertex: int, weight: int):
        """Add edge with multigraph constraints"""
        # Check for self-loops
        if from_vertex == to_vertex:
            print(f"Error: Cannot add self-loop ({from_vertex},{to_vertex}) in multigraph!")
            return
        
        # Multiple edges are allowed, assign unique IDs
        edge_info = {'to': to_vertex, 'weight': weight, 'id': self.edge_counter}
        reverse_edge_info = {'to': from_vertex, 'weight': weight, 'id': self.edge_counter}
        
        self.adj[from_vertex].append(edge_info)
        self.adj[to_vertex].append(reverse_edge_info)
        
        print(f"Added edge {from_vertex} <-> {to_vertex} with weight {weight} (ID: {self.edge_counter})")
        self.edge_counter += 1


class GeneralGraph(Graph):
    """General Graph: Both loops and multiple edges allowed"""
    
    def __init__(self, vertices: int):
        super().__init__(vertices, "General Graph")
        self.edge_counter = 0
    
    def add_edge(self, from_vertex: int, to_vertex: int, weight: int):
        """Add edge with no constraints (general graph)"""
        edge_info = {'to': to_vertex, 'weight': weight, 'id': self.edge_counter}
        self.adj[from_vertex].append(edge_info)
        
        # For loops, don't add reverse edge
        if from_vertex != to_vertex:
            reverse_edge_info = {'to': from_vertex, 'weight': weight, 'id': self.edge_counter}
            self.adj[to_vertex].append(reverse_edge_info)
            print(f"Added edge {from_vertex} <-> {to_vertex} with weight {weight} (ID: {self.edge_counter})")
        else:
            print(f"Added self-loop at vertex {from_vertex} with weight {weight} (ID: {self.edge_counter})")
        
        self.edge_counter += 1


def demonstrate_graph(graph: Graph, title: str):
    """Demonstrate Dijkstra's algorithm on a graph"""
    print("\n" + "=" * 60)
    print(title)
    print("=" * 60)
    
    graph.print_graph()
    
    # Run Dijkstra from vertex 0
    distances, parents = graph.dijkstra(0)
    graph.print_shortest_paths(0, distances, parents)


def main():
    print("DIJKSTRA'S ALGORITHM IMPLEMENTATION")
    print("Problems 14, 15, 16: Simple Graph, Multigraph, General Graph")
    print("=" * 70)
    
    # Problem 14: Simple Graph
    print("\n>>> PROBLEM 14: SIMPLE GRAPH <<<")
    simple_graph = SimpleGraph(5)
    
    # Add edges to simple graph
    edges_simple = [
        (0, 1, 10), (0, 4, 5), (1, 2, 1), (1, 4, 2),
        (2, 3, 4), (3, 2, 6),  # This will be rejected (duplicate)
        (3, 4, 2), (4, 1, 3),  # This will be rejected (duplicate)  
        (4, 2, 9), (4, 3, 2)   # This will be rejected (duplicate)
    ]
    
    for from_v, to_v, weight in edges_simple:
        simple_graph.add_edge(from_v, to_v, weight)
    
    demonstrate_graph(simple_graph, "SIMPLE GRAPH ANALYSIS")
    
    # Problem 15: Multigraph  
    print("\n\n>>> PROBLEM 15: MULTIGRAPH <<<")
    multigraph = Multigraph(4)
    
    # Add edges including multiple edges between same vertices
    edges_multi = [
        (0, 1, 5), (0, 1, 3),   # Multiple edge - allowed
        (0, 2, 4), (1, 2, 2), (1, 2, 6),   # Multiple edge - allowed
        (1, 3, 1), (2, 3, 3), (2, 3, 7),   # Multiple edge - allowed
        (1, 1, 2)   # Self-loop - not allowed in multigraph
    ]
    
    for from_v, to_v, weight in edges_multi:
        multigraph.add_edge(from_v, to_v, weight)
    
    demonstrate_graph(multigraph, "MULTIGRAPH ANALYSIS")
    
    # Problem 16: General Graph
    print("\n\n>>> PROBLEM 16: GENERAL GRAPH <<<")
    general_graph = GeneralGraph(4)
    
    # Add edges including self-loops and multiple edges
    edges_general = [
        (0, 1, 7), (0, 1, 4),   # Multiple edge - allowed
        (0, 2, 3), (0, 0, 2),   # Self-loop - allowed
        (1, 2, 5), (1, 2, 8),   # Multiple edge - allowed
        (1, 3, 6), (2, 2, 1),   # Self-loop - allowed
        (2, 3, 2), (3, 3, 4)    # Self-loop - allowed
    ]
    
    for from_v, to_v, weight in edges_general:
        general_graph.add_edge(from_v, to_v, weight)
    
    demonstrate_graph(general_graph, "GENERAL GRAPH ANALYSIS")
    
    # Summary and analysis
    print("\n" + "=" * 70)
    print("SUMMARY OF DIJKSTRA'S ALGORITHM ON DIFFERENT GRAPH TYPES")
    print("=" * 70)
    
    summary = """
1. SIMPLE GRAPH: No loops, no multiple edges
   - Dijkstra works optimally with clean edge relationships
   - Each pair of vertices has at most one edge
   - Time Complexity: O((V + E) log V) using binary heap
   - Space Complexity: O(V + E)

2. MULTIGRAPH: No loops, but multiple edges allowed  
   - Dijkstra considers all parallel edges automatically
   - The algorithm naturally chooses minimum weight edges during relaxation
   - Multiple edges don't affect correctness, only increase edge count
   - Time Complexity: O((V + E) log V) where E includes all parallel edges

3. GENERAL GRAPH: Both loops and multiple edges allowed
   - Dijkstra handles self-loops by processing them like normal edges
   - Self-loops with positive weights don't improve shortest paths
   - Multiple edges are evaluated, minimum weight is automatically chosen
   - Most flexible representation but requires careful edge management
   - Time Complexity: O((V + E) log V) where E includes all edges and loops

Key Algorithmic Insights:
- Dijkstra's greedy approach works for all non-negative weight graphs
- The priority queue ensures vertices are processed in order of distance
- Relaxation technique naturally handles multiple edges by keeping minimum
- Self-loops with positive weights are processed but don't affect optimality
- The algorithm's correctness doesn't depend on graph type, only non-negative weights

Practical Applications:
- Simple graphs: Road networks, social networks
- Multigraphs: Transportation systems with multiple routes  
- General graphs: Network flows with self-connections, recursive relationships
"""
    
    print(summary)
    
    # Mathematical analysis
    print("\n" + "=" * 70)
    print("MATHEMATICAL ANALYSIS")
    print("=" * 70)
    
    analysis = """
Dijkstra's Algorithm Invariant:
At each step, for all processed vertices u, dist[u] represents the actual shortest 
path distance from source to u.

Proof Sketch for All Graph Types:
1. Initialization: dist[source] = 0 is correct
2. Inductive step: When processing vertex u with minimum dist[u], any shorter path 
   to u would require going through an unprocessed vertex v with dist[v] > dist[u],
   contradicting the non-negative weight assumption
3. This holds regardless of multiple edges (we keep minimum) or loops (positive weight)

Graph Type Specific Considerations:
- Simple Graph: Standard implementation, O(E) = O(V²) in worst case
- Multigraph: Edge count increases, but algorithm unchanged, O(E) can be much larger
- General Graph: Self-loops add edges but don't change shortest paths (if positive weights)

The beauty of Dijkstra's algorithm is its robustness across all graph types!
"""
    
    print(analysis)


if __name__ == "__main__":
    main()