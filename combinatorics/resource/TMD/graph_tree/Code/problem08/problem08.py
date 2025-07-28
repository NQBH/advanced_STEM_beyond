from collections import deque
from typing import Dict, List, Tuple, Optional

def bfs_simple_graph(graph: Dict[int, List[int]], start_node: int) -> Tuple[Dict[int, float], Dict[int, Optional[int]]]:
    """
    Performs Breadth-First Search on a simple, unweighted graph.

    This function finds the shortest path (in terms of number of edges) from a 
    start_node to all other reachable nodes. It uses a queue for FIFO processing
    and a dictionary to track visited nodes to prevent cycles.

    :param graph: Adjacency list representation of the simple graph, stored as a dictionary.
                  Example: {0: [1, 2], 1: [0, 3], ...}
    :param start_node: The integer index of the node to start the search from.
    :return: A tuple of two dictionaries: (distance, parent).
             - distance: A dict mapping each node to its shortest distance from start_node.
             - parent: A dict mapping each node to its predecessor in the shortest path tree.
    """
    # --- Initialization ---
    
    # Initialize distances for all nodes in the graph to infinity.
    distance: Dict[int, float] = {node: float('inf') for node in graph}
    # Parent pointers used for path reconstruction.
    parent: Dict[int, Optional[int]] = {node: None for node in graph}
    # The queue for managing nodes to visit.
    queue = deque()

    # --- Start the search from the start_node ---
    if start_node not in graph:
        print(f"Error: Start node {start_node} not in graph.")
        return {}, {}
    
    distance[start_node] = 0
    # We use the parent dictionary to also track visited nodes. A node is visited
    # if its parent is not None (except for the start node). An alternative is a separate 'visited' set.
    queue.append(start_node)
    
    # Use a set for O(1) average time complexity checks for visited nodes.
    visited = {start_node}

    # --- Main Loop ---
    while queue:
        # Dequeue a vertex 'u' to process its neighbors.
        u = queue.popleft()

        # Iterate through all neighbors of the current vertex 'u'.
        for v in graph.get(u, []):
            # If the neighbor 'v' has not been visited yet...
            if v not in visited:
                # ...mark it as visited.
                visited.add(v)
                # ...set its distance one more than its parent's distance.
                distance[v] = distance[u] + 1
                # ...record 'u' as its parent.
                parent[v] = u
                # ...and enqueue 'v' to be processed in the next layer.
                queue.append(v)
                
    return distance, parent

def reconstruct_path(start_node: int, end_node: int, parent_map: Dict[int, Optional[int]]) -> Optional[List[int]]:
    """
    Reconstructs the shortest path from the source to a destination using the parent map.

    :param start_node: The source node of the search.
    :param end_node: The destination node.
    :param parent_map: The dictionary mapping each node to its predecessor.
    :return: A list of nodes representing the path, or None if no path exists.
    """
    # If the end_node is unreachable, its parent will be None (unless it's the start_node).
    if parent_map.get(end_node) is None and end_node != start_node:
        return None

    path = []
    current_node: Optional[int] = end_node
    # Backtrack from the end_node to the start_node.
    while current_node is not None:
        path.insert(0, current_node) # Insert at the beginning to build path in correct order
        current_node = parent_map.get(current_node)
    
    # Ensure the reconstructed path is valid (starts with the start_node).
    if path and path[0] == start_node:
        return path
    else:
        return None

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR PROBLEM 8 (SIMPLE GRAPH)
# =================================================================================
if __name__ == '__main__':
    # --- 1. Graph Creation (from Val21, Fig 1.1, as an undirected graph) ---
    # Node indices 0-6 correspond to v1-v7.
    simple_graph = {
        0: [1, 3],
        1: [0, 4, 3],
        2: [0, 3, 5],
        3: [0, 1, 2, 4, 5, 6],
        4: [1, 3, 6],
        5: [2, 3, 6],
        6: [3, 4, 5]
    }
    node_names = {i: f"v{i+1}" for i in range(7)}
    start_node = 0

    # --- 2. Execution ---
    distances, parents = bfs_simple_graph(simple_graph, start_node)
    
    # --- 3. Reporting Results ---
    print("=" * 60)
    print("BFS Algorithm Report for Simple Graph (Problem 8)")
    print(f"Source Node: '{node_names[start_node]}'")
    print("=" * 60)

    for node in sorted(simple_graph.keys()):
        print(f"\n--- Destination: '{node_names[node]}' ---")
        
        dist = distances.get(node, float('inf'))
        print(f"  Shortest Distance: ", end="")
        if dist == float('inf'):
            print("UNREACHABLE")
        else:
            print(int(dist))
            
            path = reconstruct_path(start_node, node, parents)
            print("  Path: ", end="")
            if path:
                print(" -> ".join(node_names[p] for p in path))
            else:
                # This case handles the source node itself.
                print(f"'{node_names[node]}' (Source Node)")

    print("=" * 60)