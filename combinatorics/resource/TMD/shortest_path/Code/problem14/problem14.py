import heapq

def dijkstra_simple_graph(graph: dict, start_node: str):
    """
    Implements Dijkstra's algorithm for a simple graph.

    This function calculates the shortest paths from a single source node to all other
    nodes in a simple graph with non-negative edge weights.

    :param graph: A dictionary of dictionaries representing the graph.
                  Example: {'A': {'B': 10, 'C': 3}, 'B': {'A': 10}}
    :param start_node: The starting node for the algorithm.
    :return: A tuple containing two dictionaries: (distances, predecessors).
             'distances' maps each node to its shortest distance from the source.
             'predecessors' maps each node to its preceding node in the shortest path.
    """
    # --- Initialization ---
    
    # Initialize distances for all nodes to infinity, and the start node to 0.
    distances = {node: float('inf') for node in graph}
    distances[start_node] = 0
    
    # This dictionary will store the path for reconstruction.
    predecessors = {node: None for node in graph}
    
    # The priority queue stores tuples of (distance, node).
    pq = [(0, start_node)]

    # --- Main Loop ---
    
    while pq:
        # Get the node with the smallest distance from the priority queue.
        current_distance, current_node = heapq.heappop(pq)
        
        # Optimization: If we've already found a better path, skip.
        if current_distance > distances[current_node]:
            continue
            
        # --- Relaxation Step ---
        
        # Iterate through all neighbors of the current node.
        # .items() is used as the value of each graph key is another dictionary.
        for neighbor, weight in graph[current_node].items():
            distance_through_u = current_distance + weight
            
            # If we found a new, shorter path to the neighbor...
            if distance_through_u < distances[neighbor]:
                # ...update the new shortest distance.
                distances[neighbor] = distance_through_u
                # ...record the predecessor for path reconstruction.
                predecessors[neighbor] = current_node
                # ...and push the new path information to the priority queue.
                heapq.heappush(pq, (distance_through_u, neighbor))
                
    return distances, predecessors

def reconstruct_path(predecessors: dict, start_node: str, end_node: str):
    """
    Reconstructs the shortest path from the predecessors dictionary.
    """
    path = []
    current_node = end_node
    while current_node is not None:
        path.insert(0, current_node)
        current_node = predecessors.get(current_node)
    
    if path and path[0] == start_node:
        return path
    else:
        return None


# ============================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR PROBLEM 14 (SIMPLE GRAPH)
# ============================================================
if __name__ == "__main__":
    # --- 1. Graph Creation for a Simple Graph ---
    # A dictionary of dictionaries is a natural way to represent a simple graph.
    # The keys of the inner dicts are unique, preventing parallel edges.
    simple_graph = {
        'A': {'B': 10, 'C': 3},
        'B': {'A': 10, 'C': 1, 'D': 2},
        'C': {'A': 3, 'B': 1, 'D': 8, 'E': 2},
        'D': {'B': 2, 'C': 8, 'E': 5},
        'E': {'C': 2, 'D': 5}
    }

    start_node = 'A'

    # --- 2. Execution ---
    distances, predecessors = dijkstra_simple_graph(simple_graph, start_node)

    # --- 3. Reporting Results ---
    print("=" * 60)
    print("Dijkstra's Algorithm Report for Simple Graph (Problem 14)")
    print(f"Source Node: '{start_node}'")
    print("=" * 60)

    # Sort nodes for consistent output order.
    sorted_nodes = sorted(simple_graph.keys())

    for node in sorted_nodes:
        print(f"\n--- Destination: '{node}' ---")
        dist = distances.get(node)
        
        print(f"  Shortest Distance: ", end="")
        if dist == float('inf'):
            print("UNREACHABLE")
        else:
            print(dist)
            
            path = reconstruct_path(predecessors, start_node, node)
            print("  Path: ", end="")
            if path:
                print(" -> ".join(path))
            else:
                print(f"'{node}' (Source Node)")

    print("=" * 60)