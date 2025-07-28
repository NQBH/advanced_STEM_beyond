from collections import deque
from typing import Dict, List, Tuple, Optional, Set

def bfs_general_graph(graph: Dict[int, List[int]], start_node: int) -> Tuple[Dict[int, float], Dict[int, Optional[int]]]:
    """
    Performs Breadth-First Search on a general graph.

    This function is robust enough to handle various graph features without changes:
    - Parallel Edges: The 'visited' set ensures a neighbor is processed only once.
    - Self-Loops: A self-loop from a node 'u' to 'u' is ignored because 'u' is
      already in the 'visited' set when its neighbors are being explored.

    :param graph: Adjacency list representation of the general graph.
                  Example: {0: [0, 1, 1]} contains a self-loop on 0 and parallel edges to 1.
    :param start_node: The integer index of the node to start the search from.
    :return: A tuple of two dictionaries: (distance, parent).
    """
    # --- Initialization ---
    
    # Find all unique nodes to correctly initialize data structures.
    all_nodes: Set[int] = set(graph.keys())
    for neighbors in graph.values():
        for neighbor in neighbors:
            all_nodes.add(neighbor)
    
    if not all_nodes:
        return {}, {}

    distance: Dict[int, float] = {node: float('inf') for node in all_nodes}
    parent: Dict[int, Optional[int]] = {node: None for node in all_nodes}
    queue = deque()
    
    # --- Start the search from the start_node ---
    if start_node not in all_nodes:
        print(f"Error: Start node {start_node} not found in the graph.")
        return {}, {}
        
    distance[start_node] = 0
    queue.append(start_node)
    visited = {start_node}

    # --- Main Loop ---
    while queue:
        u = queue.popleft()

        # Iterate through all neighbors from the adjacency list.
        for v in graph.get(u, []):
            # This single condition correctly handles all general graph features.
            if v not in visited:
                visited.add(v)
                distance[v] = distance[u] + 1
                parent[v] = u
                queue.append(v)
                
    return distance, parent

def reconstruct_path(start_node: int, end_node: int, parent_map: Dict[int, Optional[int]]) -> Optional[List[int]]:
    """
    Reconstructs the shortest path from the source to a destination using the parent map.
    """
    if parent_map.get(end_node) is None and end_node != start_node:
        return None
    path = []
    current_node: Optional[int] = end_node
    while current_node is not None:
        path.insert(0, current_node)
        current_node = parent_map.get(current_node)
    if path and path[0] == start_node:
        return path
    else:
        return None

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR PROBLEM 10 (GENERAL GRAPH)
# =================================================================================
if __name__ == '__main__':
    # --- 1. Graph Creation (General Graph) ---
    # Node indices 0-5 correspond to v1-v6.
    # This graph includes parallel edges (0->1) and a self-loop (2->2).
    general_graph = {
        0: [1, 1, 3],       # v1 -> v2 (twice), v4
        1: [0, 4],          # v2 -> v1, v5
        2: [0, 2, 5],       # v3 -> v1, v3 (self-loop), v6
        3: [0, 1, 4],       # v4 -> v1, v2, v5
        4: [1, 3],          # v5 -> v2, v4
        5: [2]              # v6 -> v3
    }
    node_names = {i: f"v{i+1}" for i in range(6)}
    start_node = 0

    # --- 2. Execution ---
    distances, parents = bfs_general_graph(general_graph, start_node)
    
    # --- 3. Reporting Results ---
    print("=" * 60)
    print("BFS Algorithm Report for General Graph (Problem 10)")
    print(f"Source Node: '{node_names[start_node]}'")
    print("=" * 60)

    sorted_nodes = sorted(list(distances.keys()))
    for node in sorted_nodes:
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
                print(f"'{node_names[node]}' (Source Node)")

    print("=" * 60)