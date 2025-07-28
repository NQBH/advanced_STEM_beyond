import sys
from typing import List, Dict, Optional, Tuple

# Increase Python's default recursion limit for potentially deep trees.
# The Zhang-Shasha algorithm is heavily recursive.
sys.setrecursionlimit(2000)

class Node:
    """
    Represents a node in a tree with a string label and a list of children nodes.
    """
    def __init__(self, label: str):
        self.label = label
        self.children: List['Node'] = []

    def __repr__(self) -> str:
        # A representation to help with debugging and printing.
        return f"Node(label='{self.label}')"

class DpSolver:
    """
    Solves the Tree Edit Distance problem using Dynamic Programming with memoization.
    This is an efficient implementation of the classic Zhang-Shasha algorithm,
    which can be seen as an optimized version of the Divide and Conquer approach.
    """

    def __init__(self):
        """
        Initializes the solver. The memoization table is the key component for the DP approach.
        It stores the computed distances for pairs of subtrees to avoid redundant calculations.
        """
        self.memo: Dict[Tuple[Optional[Node], Optional[Node]], int] = {}

    def get_subtree_size(self, node: Optional[Node]) -> int:
        """
        Helper function to calculate the total number of nodes in a subtree.
        This is used to determine the cost of inserting or deleting an entire subtree.
        """
        if not node:
            return 0
        # The size is 1 (for the node itself) plus the sizes of all its children's subtrees.
        return 1 + sum(self.get_subtree_size(child) for child in node.children)

    def solve(self, t1: Optional[Node], t2: Optional[Node]) -> int:
        """
        The main recursive function with memoization for calculating TED.
        This is the public entry point for the algorithm. For repeated calls on different
        trees, a new DpSolver instance should be created to clear the memoization table.
        """
        # Step 1: Check the memoization table first.
        # If the result for this pair of subtrees has already been computed, return it instantly.
        if (t1, t2) in self.memo:
            return self.memo[(t1, t2)]
            
        # --- Base Cases ---
        # If one tree is empty, the cost is the number of nodes in the other tree (all insertions/deletions).
        if t1 is None:
            res = self.get_subtree_size(t2)
        elif t2 is None:
            res = self.get_subtree_size(t1)
        else:
            # --- Recursive Step (Divide and Conquer with Combination) ---
            # Option 1: Relabel/substitute the roots of t1 and t2.
            # The cost is the relabeling cost plus the minimum cost to transform the children forests.
            cost_relabel = 0 if t1.label == t2.label else 1
            res_sub = cost_relabel + self._forest_dist_dp(t1.children, t2.children)
            
            # Option 2: Delete the root of t1 (and its entire subtree).
            res_del = self.get_subtree_size(t1)
            
            # Option 3: Insert the root of t2 (and its entire subtree).
            res_ins = self.get_subtree_size(t2)
            
            # The final result for this subproblem is the minimum of the three options.
            res = min(res_sub, res_del, res_ins)
        
        # Step 2: Store the newly computed result in the memoization table before returning.
        self.memo[(t1, t2)] = res
        return res

    def _forest_dist_dp(self, f1: List[Node], f2: List[Node]) -> int:
        """
        Calculates the edit distance between two forests (sequences of trees)
        using a dynamic programming table, similar to the Levenshtein distance for strings.
        """
        n, m = len(f1), len(f2)
        # Create a DP table to solve the subproblem.
        dp_table = [[0] * (m + 1) for _ in range(n + 1)]

        # Base cases for the DP table: transforming a forest to an empty one (and vice versa).
        # Cost is the sum of sizes of all trees in the forest.
        for i in range(1, n + 1):
            dp_table[i][0] = dp_table[i-1][0] + self.get_subtree_size(f1[i-1])
        for j in range(1, m + 1):
            dp_table[0][j] = dp_table[0][j-1] + self.get_subtree_size(f2[j-1])
            
        # Fill the rest of the table using the main recursive `solve` function.
        # Since `solve` is memoized, calls for the same subtrees are fast.
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                # Cost to transform tree i of f1 into tree j of f2.
                cost_sub = self.solve(f1[i-1], f2[j-1])
                # Cost to delete tree i of f1.
                cost_del = self.get_subtree_size(f1[i-1])
                # Cost to insert tree j of f2.
                cost_ins = self.get_subtree_size(f2[j-1])
                
                dp_table[i][j] = min(
                    dp_table[i-1][j-1] + cost_sub, # Substitute
                    dp_table[i-1][j] + cost_del,     # Deletion
                    dp_table[i][j-1] + cost_ins      # Insertion
                )
        return dp_table[n][m]

def build_from_parents(parents: List[int], labels: List[str]) -> Optional[Node]:
    """Helper function to build a tree from a parent array for testing."""
    if not parents:
        return None
    nodes = [Node(lbl) for lbl in labels]
    root = None
    for i, p_idx in enumerate(parents):
        if p_idx == -1:
            root = nodes[i]
        else:
            nodes[p_idx].children.append(nodes[i])
    return root

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR EXERCISE 6(d)
# =================================================================================
if __name__ == '__main__':
    print("=" * 60)
    print("  (d) Tree Edit Distance: Dynamic Programming Solver  ")
    print("=" * 60)
    
    # --- Test Cases ---
    
    # Test Case 1: Simple relabel
    # Tree 1: a -> {b, c}
    t1 = build_from_parents([-1, 0, 0], ["a", "b", "c"])
    # Tree 2: a -> {d, c}
    t2 = build_from_parents([-1, 0, 0], ["a", "d", "c"])
    solver1 = DpSolver()
    print(f"Distance( a{{b,c}}, a{{d,c}} ) = {solver1.solve(t1, t2)} (Expected: 1)")

    # Test Case 2: More complex transformation
    # Tree 3: x -> {y, z}
    t3 = build_from_parents([-1, 0, 0], ["x", "y", "z"])
    solver2 = DpSolver()
    print(f"Distance( a{{b,c}}, x{{y,z}} ) = {solver2.solve(t1, t3)} (Expected: 3)")

    # Test Case 3: Different structures
    # Tree 4: f -> {a -> {b, c}, d -> {e}}
    t4 = build_from_parents([-1, 0, 0, 1, 1, 2], ["f", "a", "d", "b", "c", "e"])
    # Tree 5: f -> {c, d -> {a, b, e}}
    t5 = build_from_parents([-1, 0, 0, 2, 2, 2], ["f", "c", "d", "a", "b", "e"])
    solver3 = DpSolver()
    print(f"Distance( T4, T5 ) = {solver3.solve(t4, t5)} (Expected: 2)")

    print("=" * 60)