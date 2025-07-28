from typing import List, Dict

class ExtendedFCNSTree:
    """
    Exercise 1.10: Implements the extended first-child, next-sibling tree representation.

    This class is designed to support several key operations (`root`, `parent`, 
    `number_of_children`) in O(1) time, as requested by Problem 1.5.
    It achieves this by pre-computing and storing extra information (parent array,
    children counts, and root index) during its construction from a simple parent array.
    """
    
    def __init__(self, parent_array: List[int]):
        """
        Constructs the tree from a parent array.
        :param parent_array: The tree represented as a list where parent_array[i] is the parent of node i.
        """
        self.num_nodes: int = len(parent_array)
        self.root_node: int = -1
        
        # O(1) lookup structures
        self.parent_array: List[int] = parent_array
        self.children_count: List[int] = [0] * self.num_nodes
        
        # The core FCNS representation
        self.fcns_nodes: List[Dict[str, int]] = [
            {'first_child': -1, 'next_sibling': -1} for _ in range(self.num_nodes)
        ]
        
        # Build the extended representation
        self._build_representation()

    def _build_representation(self):
        """
        Private helper to build the extended representation.
        This pre-computation step makes later queries fast.
        """
        # 1. Build a temporary adjacency list (parent -> list of children) for easier processing.
        adj: List[List[int]] = [[] for _ in range(self.num_nodes)]
        for i, p in enumerate(self.parent_array):
            if p != -1:
                adj[p].append(i)
            else:
                self.root_node = i
        
        # 2. Populate the FCNS structure and children_count from the adjacency list.
        for i in range(self.num_nodes):
            self.children_count[i] = len(adj[i])
            if self.children_count[i] > 0:
                # Set the first child.
                self.fcns_nodes[i]['first_child'] = adj[i][0]
                # Link the siblings together.
                for j in range(self.children_count[i] - 1):
                    current_child = adj[i][j]
                    next_child = adj[i][j+1]
                    self.fcns_nodes[current_child]['next_sibling'] = next_child

    def root(self) -> int:
        """Returns the root of the tree in O(1) time."""
        return self.root_node
        
    def parent(self, v: int) -> int:
        """Returns the parent of node v in O(1) time."""
        return self.parent_array[v]

    def number_of_children(self, v: int) -> int:
        """Returns the number of children of node v in O(1) time."""
        return self.children_count[v]

    def children(self, v: int) -> List[int]:
        """
        Returns a list of all children of a node.
        
        Note: This operation is O(k) where k is the number of children, because it
        has to construct and return a new list by traversing the sibling chain.
        Achieving true O(1) would require pre-storing these lists, which would
        increase memory usage and the complexity of the build step.
        
        :param v: The parent node.
        :return: A list containing the indices of all children.
        """
        child_list = []
        if 0 <= v < self.num_nodes:
            child = self.fcns_nodes[v]['first_child']
            while child != -1:
                child_list.append(child)
                child = self.fcns_nodes[child]['next_sibling']
        return child_list

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR EXERCISE 1.10
# =================================================================================
if __name__ == "__main__":
    print("=" * 60)
    print("  Extended FCNS Tree Class Demo (Exercise 1.10)      ")
    print("=" * 60)

    # Tree with 8 nodes. Node 0 is root.
    parent_array = [-1, 0, 0, 1, 1, 2, 2, 0]
    print(f"Initializing tree from parent array: {parent_array}\n")

    tree = ExtendedFCNSTree(parent_array)

    print("--- Testing O(1) operations ---")
    print(f"  Root of the tree: {tree.root()}")
    
    test_node_0 = 0
    print(f"  Number of children of node {test_node_0}: {tree.number_of_children(test_node_0)}")
    
    test_node_1 = 1
    print(f"  Number of children of node {test_node_1}: {tree.number_of_children(test_node_1)}")
    
    test_node_3 = 3
    print(f"  Number of children of node {test_node_3}: {tree.number_of_children(test_node_3)}")

    print("\n--- Testing O(k) children list retrieval ---")
    print(f"  Children of node 0: {tree.children(0)}")
    print(f"  Children of node 1: {tree.children(1)}")
    print(f"  Children of node 2: {tree.children(2)}")
    print(f"  Children of node 3 (a leaf): {tree.children(3)}")

    print("=" * 60)