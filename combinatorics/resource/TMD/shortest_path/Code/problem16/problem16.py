import heapq

def dijkstra_general_graph(graph: dict, all_nodes: set, start_node: str):
    """
    Implements Dijkstra's algorithm.

    WARNING: This implementation is ONLY correct if all edge weights in the
    'general graph' are non-negative. It can handle parallel edges and
    non-negative self-loops, but it will fail with negative weights.

    :param graph: A dict mapping a node to a list of (neighbor, weight) tuples.
    :param all_nodes: A set containing all unique nodes in the graph.
    :param start_node: The starting node for the algorithm.
    :return: A tuple containing two dictionaries: (distances, predecessors).
    """
    # --- Initialization ---
    distances = {node: float('inf') for node in all_nodes}
    distances[start_node] = 0
    predecessors = {node: None for node in all_nodes}
    pq = [(0, start_node)]

    # --- Main Loop ---
    while pq:
        current_distance, current_node = heapq.heappop(pq)
        
        if current_distance > distances[current_node]:
            continue
            
        # --- Relaxation Step ---
        # The loop structure naturally handles parallel edges and self-loops.
        if current_node in graph:
            for neighbor, weight in graph[current_node]:
                # Critical assumption: weight >= 0.
                # If weight were negative, this greedy logic would be flawed.
                distance_through_u = current_distance + weight
                
                if distance_through_u < distances[neighbor]:
                    distances[neighbor] = distance_through_u
                    predecessors[neighbor] = current_node
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

# ===============================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR PROBLEM 16 (GENERAL GRAPH)
# =================================================================
if __name__ == "__main__":
    # --- 1. Graph Creation for a General Graph ---
    # This graph includes parallel edges and a self-loop.
    # CRITICAL ASSUMPTION: All weights are non-negative for Dijkstra to be valid.
    general_graph = {
        'A': [('B', 10), ('C', 3)],
        'B': [('D', 2), ('D', 1)],  # Parallel edge B->D
        'C': [('A', 3), ('D', 8), ('E', 2)],
        'D': [('E', 5)],
        'E': [('C', 1), ('E', 4)]   # Self-loop E->E with non-negative weight
    }

    start_node = 'A'

    # --- 2. Pre-processing: Get all unique nodes ---
    all_nodes = set(general_graph.keys())
    for node in general_graph:
        for neighbor, weight in general_graph[node]:
            all_nodes.add(neighbor)

    # --- 3. Execution ---
    distances, predecessors = dijkstra_general_graph(general_graph, all_nodes, start_node)

    # --- 4. Reporting Results ---
    print("=" * 70)
    print("Dijkstra's Algorithm Report for General Graph (Problem 16)")
    print(f"Source Node: '{start_node}'")
    print("-" * 70)
    print("WARNING: These results are correct ONLY under the assumption that")
    print("         all edge weights in the graph are non-negative.")
    print("         Dijkstra's algorithm fails with negative edge weights.")
    print("=" * 70)

    sorted_nodes = sorted(list(all_nodes))

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

    print("=" * 70)