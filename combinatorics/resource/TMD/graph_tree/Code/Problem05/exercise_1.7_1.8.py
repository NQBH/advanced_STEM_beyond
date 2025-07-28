import random
from typing import Dict, List

# A type alias for graph/tree representation for better readability.
TreeAdjList = Dict[int, List[int]]

class TreeGenerator:
    """
    A class to generate various types of trees.

    This class provides methods to programmatically construct trees based on
    specific rules, such as complete binary trees or random trees.
    It simulates the abstract operations like `new_node` and `new_edge`.
    """
    def __init__(self):
        """Initializes the generator with an empty tree."""
        self.adj: TreeAdjList = {}
        self.num_nodes: int = 0

    def _clear(self):
        """Resets the generator to an empty state for a new tree."""
        self.adj = {}
        self.num_nodes = 0

    def _new_node(self) -> int:
        """
        Simulates the `new_node` operation.
        Adds a new node to the tree and returns its index.
        :return: The integer index of the newly created node.
        """
        node_id = self.num_nodes
        self.adj[node_id] = []  # A new node has no children initially
        self.num_nodes += 1
        return node_id

    def _new_edge(self, parent: int, child: int):
        """
        Simulates the `new_edge` operation for a directed tree.
        Adds a directed edge from a parent to a child.
        :param parent: The index of the parent node.
        :param child: The index of the child node.
        """
        if parent in self.adj and child in self.adj:
            self.adj[parent].append(child)

    def generate_complete_binary_tree(self, n: int) -> TreeAdjList:
        """
        Exercise 1.7: Generates a complete binary tree.

        A complete binary tree is filled level by level, left to right.
        This property allows a simple generation algorithm based on the relationship
        between a child's index `i` and its parent's index `(i-1)//2`.

        :param n: The total number of nodes in the tree.
        :return: The generated tree as an adjacency list (parent -> list of children).
        """
        self._clear()
        if n <= 0:
            return self.adj

        # Create all n nodes first
        nodes = [self._new_node() for _ in range(n)]

        # Connect each child to its parent.
        # Node 0 is the root and has no parent, so the loop starts from 1.
        for i in range(1, n):
            parent_idx = (i - 1) // 2
            self._new_edge(nodes[parent_idx], nodes[i])
        
        return self.adj

    def generate_random_tree(self, n: int) -> TreeAdjList:
        """
        Exercise 1.8: Generates a random tree on n vertices.

        This algorithm (a variant of Prüfer sequence generation) works by
        iteratively adding a new node and connecting it to a randomly chosen
        existing node. This guarantees connectivity and n-1 edges.

        :param n: The total number of nodes in the tree.
        :return: The generated random tree as an adjacency list.
        """
        self._clear()
        if n <= 0:
            return self.adj
        
        # Create the first node
        self._new_node()

        # Iteratively add the remaining n-1 nodes
        for i in range(1, n):
            self._new_node()
            # Choose a random node from the already existing set {0, 1, ..., i-1}
            j = random.randint(0, i - 1)
            
            # Add an edge from the existing node `j` to the new node `i`.
            self._new_edge(j, i)
        
        return self.adj

def print_tree(tree: TreeAdjList, name: str):
    """Helper function to print a tree for verification."""
    print(f"--- {name} ---")
    if not tree:
        print("  (Empty Tree)")
        return
    for node in sorted(tree.keys()):
        print(f"  Node {node} -> {sorted(tree[node])}")
    print("--------------------")


# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR EXERCISES 1.7 & 1.8
# =================================================================================
if __name__ == "__main__":
    gen = TreeGenerator()
    num_nodes = 10

    print("=" * 60)
    print("      Tree Generator Demo (Exercises 1.7 & 1.8)      ")
    print("=" * 60)

    # --- Exercise 1.7 ---
    print(f"\nGenerating a Complete Binary Tree with {num_nodes} nodes (Exercise 1.7):\n")
    complete_binary_tree = gen.generate_complete_binary_tree(num_nodes)
    print_tree(complete_binary_tree, "Complete Binary Tree")
    
    # --- Exercise 1.8 ---
    print(f"\nGenerating a Random Tree with {num_nodes} nodes (Exercise 1.8):\n")
    print("(Note: The structure will be different each time you run the program)\n")
    random_tree = gen.generate_random_tree(num_nodes)
    print_tree(random_tree, "Random Tree")

    print("=" * 60)