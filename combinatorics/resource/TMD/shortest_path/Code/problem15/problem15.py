import heapq

def dijkstra_multigraph_python(graph: dict, all_nodes: set, start_node: str):
    """
    Implements Dijkstra's algorithm for a multigraph.

    This function calculates the shortest paths from a single source node to all other
    nodes in a graph that may contain parallel edges.

    :param graph: A dictionary representing the multigraph.
                  Keys are source nodes, and values are lists of (neighbor, weight) tuples.
                  Example: {'A': [('B', 10), ('B', 12)]}
    :param all_nodes: A set containing all unique nodes in the graph. This is necessary
                      to initialize distances for nodes that may only be destinations.
    :param start_node: The starting node for the algorithm.
    :return: A tuple containing two dictionaries: (distances, predecessors).
             'distances' maps each node to its shortest distance from the source.
             'predecessors' maps each node to its preceding node in the shortest path.
    """
    # --- Initialization ---
    
    # Initialize distances for all nodes to infinity, and the start node to 0.
    distances = {node: float('inf') for node in all_nodes}
    distances[start_node] = 0
    
    # This dictionary will store the path.
    predecessors = {node: None for node in all_nodes}
    
    # The priority queue stores tuples of (distance, node).
    # heapq implements a min-heap, so it will always give us the item with the smallest distance.
    pq = [(0, start_node)]

    # --- Main Loop ---
    
    while pq:
        # Get the node with the smallest distance from the priority queue.
        current_distance, current_node = heapq.heappop(pq)
        
        # Optimization: If we have already found a shorter path to this node, skip.
        if current_distance > distances[current_node]:
            continue
            
        # --- Relaxation Step ---
        
        # This is the key part for multigraphs. We iterate through the list of edges.
        # If there are parallel edges, this loop will process all of them.
        if current_node in graph:
            for neighbor, weight in graph[current_node]:
                distance_through_u = current_distance + weight
                
                # If we found a new, shorter path to the neighbor...
                if distance_through_u < distances[neighbor]:
                    # ...update the new shortest distance.
                    distances[neighbor] = distance_through_u
                    # ...record that we reached this neighbor via the current node.
                    predecessors[neighbor] = current_node
                    # ...and push the new path information to the priority queue.
                    heapq.heappush(pq, (distance_through_u, neighbor))
                
    return distances, predecessors

def reconstruct_path(predecessors: dict, start_node: str, end_node: str):
    """
    Reconstructs the shortest path from the predecessors dictionary.

    :param predecessors: The dictionary mapping each node to its predecessor.
    :param start_node: The starting node of the path.
    :param end_node: The ending node of the path.
    :return: A list of nodes representing the path, or None if no path exists.
    """
    path = []
    current_node = end_node
    # Backtrack from the end node to the start node.
    while current_node is not None:
        path.insert(0, current_node) # Insert at the beginning to build the path in correct order
        current_node = predecessors.get(current_node) # Use .get for safety
    
    # If the path starts with the start_node, it's a valid path.
    if path and path[0] == start_node:
        return path
    else:
        return None


# ============================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR PROBLEM 15 (MULTIGRAPH)
# ============================================================
if __name__ == "__main__":
    # --- 1. Graph Creation for a Multigraph ---
    # The data structure is a dictionary where keys are nodes and values are
    # lists of (neighbor, weight) tuples. This allows for parallel edges.
    multigraph = {
        'A': [('B', 10), ('C', 3), ('C', 8)],  # Parallel edge A->C
        'B': [('A', 10), ('C', 1), ('D', 2), ('D', 1)], # Parallel edge B->D
        'C': [('A', 3), ('A', 8), ('B', 1), ('D', 8), ('E', 2)],
        'D': [('B', 2), ('B', 1), ('C', 8), ('E', 5)],
        'E': [('C', 2), ('D', 5)]
    }

    start_node = 'A'

    # --- 2. Pre-processing: Get all unique nodes ---
    # This is important for multigraphs where a node might only be a destination.
    all_nodes = set(multigraph.keys())
    for node in multigraph:
        for neighbor, weight in multigraph[node]:
            all_nodes.add(neighbor)

    # --- 3. Execution ---
    # Run the Dijkstra algorithm on the defined graph.
    distances, predecessors = dijkstra_multigraph_python(multigraph, all_nodes, start_node)

    # --- 4. Reporting Results ---
    print("=" * 60)
    print("Dijkstra's Algorithm Report for Multigraph (Problem 15)")
    print(f"Source Node: '{start_node}'")
    print("=" * 60)

    # Sort nodes for consistent output order.
    sorted_nodes = sorted(list(all_nodes))

    for node in sorted_nodes:
        print(f"\n--- Destination: '{node}' ---")
        dist = distances.get(node)
        
        print(f"  Shortest Distance: ", end="")
        if dist == float('inf'):
            print("UNREACHABLE")
        else:
            print(dist)
            
            # Reconstruct and print the path
            path = reconstruct_path(predecessors, start_node, node)
            print("  Path: ", end="")
            if path:
                print(" -> ".join(path))
            else:
                # This case handles the source node itself, which has no path to reconstruct.
                print(f"'{node}' (Source Node)")

    print("=" * 60)
