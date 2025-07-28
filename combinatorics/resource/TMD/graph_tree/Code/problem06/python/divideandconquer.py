import sys
from typing import List, Optional

sys.setrecursionlimit(2000)

class Node:
    """Represents a node in a tree with a label and a list of children."""
    def __init__(self, label: str):
        self.label = label
        self.children: List['Node'] = []
    def __repr__(self): return f"Node({self.label})"

class DivideAndConquerSolver:
    """
    Solves the Tree Edit Distance problem using a pure Divide and Conquer approach.
    This implementation does NOT use memoization, which means it will re-calculate
    the distance for the same pairs of subtrees multiple times, leading to
    exponential time complexity. Its purpose is to illustrate the D&C principle.
    """
    def get_subtree_size(self, node: Optional[Node]) -> int:
        """Helper to get the total number of nodes in a subtree."""
        if not node: return 0
        return 1 + sum(self.get_subtree_size(child) for child in node.children)

    def solve(self, t1: Optional[Node], t2: Optional[Node]) -> int:
        """
        (Conquer) The main recursive function that calculates TED.
        It divides the problem of T1->T2 into subproblems on their children forests.
        """
        # Base cases: If one tree is empty, the problem is trivial.
        if t1 is None: return self.get_subtree_size(t2)
        if t2 is None: return self.get_subtree_size(t1)

        # --- Divide & Combine Step ---
        
        # Option 1: Relabel/substitute the roots of t1 and t2. The cost is the
        # relabeling cost plus the cost of transforming the forest of children.
        cost_relabel = 0 if t1.label == t2.label else 1
        res_sub = cost_relabel + self._forest_dist(t1.children, t2.children)

        # Options 2 & 3: A simplified definition involves deleting the entire t1 subtree
        # and inserting the t2 subtree, or vice versa.
        res_del = 1 + self._forest_dist(t1.children, []) + self.solve(None, t2)
        res_ins = 1 + self._forest_dist([], t2.children) + self.solve(t1, None)
        
        # The final result is the minimum of these options.
        return min(res_sub, res_del, res_ins)

    def _forest_dist(self, f1: List[Node], f2: List[Node]) -> int:
        """
        (Conquer) Calculates the edit distance between two forests using a
        DP-like table construction. Each cell fill is a recursive call.
        """
        n, m = len(f1), len(f2)
        # Create a DP table to solve the subproblem of mapping one prefix of a forest
        # to a prefix of another forest.
        dp_table = [[0] * (m + 1) for _ in range(n + 1)]

        # Base cases for the DP table (mapping a forest to an empty forest).
        for i in range(1, n + 1):
            dp_table[i][0] = dp_table[i-1][0] + self.get_subtree_size(f1[i-1])
        for j in range(1, m + 1):
            dp_table[0][j] = dp_table[0][j-1] + self.get_subtree_size(f2[j-1])
            
        # Fill the table using the main recursive `solve` function.
        # This is where the overlapping subproblems are re-computed.
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                cost_sub = self.solve(f1[i-1], f2[j-1])
                cost_del = self.get_subtree_size(f1[i-1])
                cost_ins = self.get_subtree_size(f2[j-1])
                dp_table[i][j] = min(
                    dp_table[i-1][j-1] + cost_sub, # Substitute tree f1[i-1] with f2[j-1]
                    dp_table[i-1][j] + cost_del,     # Delete tree f1[i-1]
                    dp_table[i][j-1] + cost_ins      # Insert tree f2[j-1]
                )
        return dp_table[n][m]

def build_from_parents(parents: List[int], labels: List[str]) -> Optional[Node]:
    """Helper to build a tree from a parent array for testing."""
    if not parents: return None
    nodes = [Node(lbl) for lbl in labels]
    root = None
    for i, p_idx in enumerate(parents):
        if p_idx == -1: root = nodes[i]
        else: nodes[p_idx].children.append(nodes[i])
    return root

if __name__ == '__main__':
    print("=" * 60)
    print("  (c) Tree Edit Distance: Pure Divide and Conquer Solver ")
    print("=" * 60)
    print("WARNING: This naive version is very slow due to re-computing subproblems.\n")
    
    solver = DivideAndConquerSolver()
    
    # --- Test Cases (must be small to run in a reasonable time) ---
    t1 = build_from_parents([-1, 0, 0], ["a", "b", "c"])
    t2 = build_from_parents([-1, 0, 0], ["a", "d", "c"])
    t3 = build_from_parents([-1, 0], ["x", "y"])

    print(f"Distance( a{{b,c}}, a{{d,c}} ) = {solver.solve(t1, t2)} (Expected: 1)")
    print(f"Distance( a{{b,c}}, x{{y}} ) = {solver.solve(t1, t3)} (Expected: 2)")