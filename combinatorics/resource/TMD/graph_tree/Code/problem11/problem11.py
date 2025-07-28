from typing import Dict, List, Optional, Set, Tuple

class DfsSolverPython:
    """
    Encapsulates both recursive and iterative DFS implementations in Python.

    This class provides a structured way to run DFS on a graph. It holds the graph
    and the results of the traversal. Each call to a `solve_` method resets the
    state, allowing for multiple runs on the same graph instance.
    """
    
    def __init__(self, graph: Dict[int, List[int]]):
        """
        Initializes the solver with a graph.

        :param graph: Adjacency list representation of the simple graph.
                      Example: {0: [1, 2], 1: [0, 3], ...}
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

        This function sets up the necessary data structures (parent map, visited set)
        and then calls the private utility function to perform the actual recursion.
        
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

        This is the direct implementation of the recursive formula:
        1. Mark and process the current node `u`.
        2. For each unvisited neighbor `v`, set its parent and recurse on `v`.
        The system's call stack handles the LIFO (Last-In, First-Out) behavior.
        
        :param u: The current node to visit.
        :param path: The list to record the traversal order.
        """
        # Mark the current node as visited and add to the traversal path.
        self.visited.add(u)
        path.append(u)

        # Recur for all unvisited vertices adjacent to this vertex.
        for v in self.graph.get(u, []):
            if v not in self.visited:
                self.parent[v] = u
                self._dfs_recursive_util(v, path)

    def solve_iterative(self, start_node: int) -> Tuple[Dict[int, Optional[int]], List[int]]:
        """
        Iterative implementation of DFS using an explicit stack.

        This method avoids deep recursion, which can cause a stack overflow on very
        large or deep graphs. It manually manages the nodes to visit using a stack.
        
        :param start_node: The node to start the search from.
        :return: A tuple containing the parent map and the traversal path.
        """
        parent_map: Dict[int, Optional[int]] = {node: None for node in self.nodes}
        visited: Set[int] = set()
        traversal_path = []
        
        if start_node not in self.nodes:
            return {}, []
            
        # The stack for DFS, initialized with the start node.
        stack: List[int] = [start_node]

        while stack:
            # Pop a vertex from the top of the stack.
            u = stack.pop()
            
            # If the node has already been visited (e.g., added to stack multiple times
            # before being processed), skip it.
            if u not in visited:
                visited.add(u)
                traversal_path.append(u)

                # Push unvisited neighbors onto the stack.
                # We iterate through neighbors in reverse order to ensure that the
                # first neighbor (e.g., adj[0][0]) is processed first,
                # mimicking the typical recursive behavior.
                for v in reversed(self.graph.get(u, [])):
                    if v not in visited:
                        parent_map[v] = u # Parent is set when we decide to visit it
                        stack.append(v)

        return parent_map, traversal_path

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR PROBLEM 11 (SIMPLE GRAPH)
# =================================================================================
if __name__ == '__main__':
    # --- 1. Graph Creation (Simple Graph from Val21, Fig 1.1) ---
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

    # --- 2. Execution & Reporting ---
    solver = DfsSolverPython(simple_graph)
    
    print("=" * 60)
    print("DFS Algorithm Report for Simple Graph (Problem 11)")
    print(f"Source Node: '{node_names[start_node]}'")
    print("=" * 60)
    
    # --- Run and Print Recursive Version ---
    print("\n--- Recursive DFS ---")
    parents_rec, path_rec = solver.solve_recursive(start_node)
    path_str_rec = " -> ".join(node_names[n] for n in path_rec)
    print(f"  Traversal Path: {path_str_rec}")
    parent_of_v7_rec = parents_rec.get(6)
    print(f"  Parent of v7 ({node_names[6]}): {node_names[parent_of_v7_rec] if parent_of_v7_rec is not None else 'N/A'}")

    # --- Run and Print Iterative Version ---
    print("\n--- Iterative DFS ---")
    parents_iter, path_iter = solver.solve_iterative(start_node)
    path_str_iter = " -> ".join(node_names[n] for n in path_iter)
    print(f"  Traversal Path: {path_str_iter}")
    parent_of_v7_iter = parents_iter.get(6)
    print(f"  Parent of v7 ({node_names[6]}): {node_names[parent_of_v7_iter] if parent_of_v7_iter is not None else 'N/A'}")
    
    print("=" * 60)