from typing import Dict, List, Optional, Set, Tuple

class DfsSolverPython:
    """
    Encapsulates DFS implementations. This class works for simple graphs,
    multigraphs, and general graphs because the core logic is robust.
    """
    
    def __init__(self, graph: Dict[int, List[int]]):
        """
        Initializes the solver with a graph.

        :param graph: Adjacency list representation. Can contain parallel edges
                      (e.g., {0: [1, 1]}) and self-loops (e.g., {2: [2]}).
        """
        self.graph = graph
        # Determine all unique nodes present in the graph
        self.nodes = set(graph.keys())
        for neighbors in graph.values():
            for neighbor in neighbors:
                self.nodes.add(neighbor)
        
        # These will be reset for each run
        self.parent: Dict[int, Optional[int]] = {}
        self.visited: Set[int] = set()

    def solve_recursive(self, start_node: int) -> Tuple[Dict[int, Optional[int]], List[int]]:
        """
        Public method to start the recursive Depth-First Search.

        This function initializes the state (parent map, visited set) and then
        calls the private utility function to perform the actual recursion.
        
        :param start_node: The node to start the search from.
        :return: A tuple containing the parent map for path reconstruction and
                 the list of nodes in the order they were visited.
        """
        self.parent = {node: None for node in self.nodes}
        self.visited = set()
        traversal_path = []

        if start_node in self.nodes:
            self._dfs_recursive_util(start_node, traversal_path)
            
        return self.parent, traversal_path

    def _dfs_recursive_util(self, u: int, path: List[int]):
        """
        Recursive helper function that embodies the DFS logic.

        This function works correctly on general graphs:
        - Self-Loops (u,u): When the loop encounters 'u' as a neighbor of itself,
          the check `if u not in self.visited` will be false, because 'u' was
          added to the visited set at the beginning of this function call.
          This prevents infinite recursion.
        - Parallel Edges: Handled correctly as explained in the multigraph problem.
        
        :param u: The current node to visit.
        :param path: The list to record the traversal order.
        """
        self.visited.add(u)
        path.append(u)

        # Iterate through all neighbors, including duplicates and self.
        for v in self.graph.get(u, []):
            if v not in self.visited:
                self.parent[v] = u
                self._dfs_recursive_util(v, path)

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR PROBLEM 13 (GENERAL GRAPH)
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

    # --- 2. Execution & Reporting ---
    solver = DfsSolverPython(general_graph)
    
    print("=" * 60)
    print("DFS Algorithm Report for General Graph (Problem 13)")
    print(f"Source Node: '{node_names[start_node]}'")
    print("=" * 60)
    
    # --- Run and Print Recursive Version ---
    print("\n--- Recursive DFS ---")
    parents_rec, path_rec = solver.solve_recursive(start_node)
    path_str_rec = " -> ".join(node_names[n] for n in path_rec)
    print(f"  Traversal Path: {path_str_rec}")
    parent_of_v6_rec = parents_rec.get(5)
    print(f"  Parent of v6 ({node_names[5]}): {node_names[parent_of_v6_rec] if parent_of_v6_rec is not None else 'N/A'}")

    print("=" * 60)