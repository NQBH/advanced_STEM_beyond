from collections import deque
from typing import Dict, List, Tuple, Optional, Set

def bfs_multigraph(graph: Dict[int, List[int]], start_node: int) -> Tuple[Dict[int, float], Dict[int, Optional[int]]]:
    """
    Performs Breadth-First Search on a multigraph.

    This function finds the shortest path (in terms of number of edges) from a
    start_node to all other reachable nodes. The logic is identical to the simple
    graph version because the `visited` set correctly handles parallel edges,
    ensuring each node is processed only once.

    :param graph: Adjacency list representation of the multigraph. A dictionary where
                  keys are nodes and values are lists of neighbors. Parallel edges
                  are represented by duplicate entries in the list.
                  Example: {0: [1, 1, 2]} means two edges from 0 to 1.
    :param start_node: The integer index of the node to start the search from.
    :return: A tuple of two dictionaries: (distance, parent).
    """
    # --- Initialization ---
    
    # In a multigraph, some nodes might only be destinations. We need to find all unique nodes first.
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

        # Iterate through all neighbors. The loop will process all parallel edges.
        for v in graph.get(u, []):
            # The 'if v not in visited' check is the key:
            # The first time we see 'v' (via any parallel edge), we process it.
            # All subsequent times (via other parallel edges), this condition will be false.
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
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR PROBLEM 9 (MULTIGRAPH)
# =================================================================================
if __name__ == '__main__':
    # --- 1. Graph Creation (Multigraph) ---
    # Node indices 0-6 correspond to v1-v7.
    # Parallel edges are represented by duplicate entries in the adjacency list.
    multigraph = {
        0: [1, 1, 3],       # v1 -> v2 (twice), v4
        1: [0, 0, 4, 3],    # v2 -> v1 (twice), v5, v4
        2: [0, 3, 5],
        3: [0, 1, 2, 4, 5, 6, 6], # v4 -> v7 (twice)
        4: [1, 3, 6],
        5: [2, 3, 6],
        6: [3, 4, 5, 3]     # v7 -> v4 (twice)
    }
    node_names = {i: f"v{i+1}" for i in range(7)}
    start_node = 0

    # --- 2. Execution ---
    distances, parents = bfs_multigraph(multigraph, start_node)
    
    # --- 3. Reporting Results ---
    print("=" * 60)
    print("BFS Algorithm Report for Multigraph (Problem 9)")
    print(f"Source Node: '{node_names[start_node]}'")
    print("=" * 60)

    # Sort nodes for consistent output order.
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