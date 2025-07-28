from typing import Dict, List, Optional, Set, Tuple

class DfsSolverPython:
    """
    Encapsulates DFS implementations. This class works for simple graphs,
    multigraphs, and general graphs because the core logic is robust.
    """
    
    def __init__(self, graph: Dict[int, List[int]]):
        """
        Initializes the solver with a graph.

        :param graph: Adjacency list representation. For a multigraph, a neighbor
                      can appear multiple times in the list, representing parallel edges.
                      Example: {0: [1, 1, 2]}
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

        This function works correctly on multigraphs. When iterating through
        neighbors of 'u', if it encounters neighbor 'v' via one parallel edge,
        it will recurse. When it later encounters 'v' via another parallel edge,
        the `if v not in self.visited` check will be false, and the redundant
        path is correctly ignored.
        
        :param u: The current node to visit.
        :param path: The list to record the traversal order.
        """
        self.visited.add(u)
        path.append(u)

        # Iterate through all neighbors, including duplicates from parallel edges.
        for v in self.graph.get(u, []):
            if v not in self.visited:
                self.parent[v] = u
                self._dfs_recursive_util(v, path)

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR PROBLEM 12 (MULTIGRAPH)
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

    # --- 2. Execution & Reporting ---
    solver = DfsSolverPython(multigraph)
    
    print("=" * 60)
    print("DFS Algorithm Report for Multigraph (Problem 12)")
    print(f"Source Node: '{node_names[start_node]}'")
    print("=" * 60)
    
    # --- Run and Print Recursive Version ---
    print("\n--- Recursive DFS ---")
    parents_rec, path_rec = solver.solve_recursive(start_node)
    path_str_rec = " -> ".join(node_names[n] for n in path_rec)
    print(f"  Traversal Path: {path_str_rec}")
    parent_of_v7_rec = parents_rec.get(6)
    print(f"  Parent of v7 ({node_names[6]}): {node_names[parent_of_v7_rec] if parent_of_v7_rec is not None else 'N/A'}")

    print("=" * 60)