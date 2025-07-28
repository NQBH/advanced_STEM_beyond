import sys
from typing import List, Optional

# Increase recursion limit for potentially deep but narrow search paths
sys.setrecursionlimit(2000)

class Node:
    """Represents a node in a tree with a label and a list of children."""
    def __init__(self, label: str):
        self.label = label
        self.children: List['Node'] = []
    def __repr__(self): return f"Node({self.label})"

class BacktrackingSolver:
    """
    Solves the Tree Edit Distance problem using a pure, unoptimized backtracking algorithm.
    It explores the entire search space of possible edit mappings.
    """
    def get_subtree_size(self, node: Optional[Node]) -> int:
        """Helper to get the total number of nodes in a subtree (cost of insert/delete)."""
        if not node: return 0
        return 1 + sum(self.get_subtree_size(child) for child in node.children)

    def solve(self, t1: Optional[Node], t2: Optional[Node]) -> int:
        """
        Public entry point. Recursively calculates TED between two nodes/subtrees.
        This is the main recursive function for edit distance between two trees.
        """
        if t1 is None: return self.get_subtree_size(t2)
        if t2 is None: return self.get_subtree_size(t1)

        # Case 1: Relabel/substitute the roots of t1 and t2, then find the
        # minimum cost to transform the forest of children of t1 to that of t2.
        cost_relabel = 0 if t1.label == t2.label else 1
        res_sub = cost_relabel + self._forest_dist(t1.children, t2.children)

        # Case 2: A simple but valid upper bound is deleting all nodes in t1
        # and inserting all nodes in t2.
        res_del_ins = self.get_subtree_size(t1) + self.get_subtree_size(t2)

        # The true TED is the minimum of these options.
        return min(res_sub, res_del_ins)

    def _forest_dist(self, f1: List[Node], f2: List[Node]) -> int:
        """
        Recursively finds the minimum cost to map forest f1 to forest f2.
        This is the core of the combinatorial explosion, as it tries all mappings.
        """
        # Base case: if one forest is empty, the cost is to insert/delete the other.
        if not f1: return sum(self.get_subtree_size(t) for t in f2)
        if not f2: return sum(self.get_subtree_size(t) for t in f1)

        t1_head, f1_tail = f1[0], f1[1:]
        
        # Branch 1: Delete the first tree (t1_head) from forest f1.
        # The cost is the size of that tree plus the cost of mapping the rest of f1 to f2.
        cost_del = self.get_subtree_size(t1_head) + self._forest_dist(f1_tail, f2)

        # Branch 2: Match t1_head with each possible tree t2_j in forest f2.
        min_match_cost = float('inf')
        for j in range(len(f2)):
            t2_match = f2[j]
            # The remaining trees in f2 to be mapped against the rest of f1.
            f2_remaining = f2[:j] + f2[j+1:]
            
            cost_match = self.solve(t1_head, t2_match) + self._forest_dist(f1_tail, f2_remaining)
            min_match_cost = min(min_match_cost, cost_match)
            
        return min(cost_del, min_match_cost)

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
    print("     (a) Tree Edit Distance: Backtracking Solver      ")
    print("=" * 60)
    print("WARNING: This method is extremely slow and only works for tiny trees.\n")
    
    solver = BacktrackingSolver()
    
    # --- Test Cases (must be very small) ---
    t1 = build_from_parents([-1, 0], ["a", "b"])
    t2 = build_from_parents([-1, 0], ["a", "c"])
    t3 = build_from_parents([-1], ["x"])

    print(f"Distance( a{{b}}, a{{c}} ) = {solver.solve(t1, t2)} (Expected: 1)")
    print(f"Distance( a{{b}}, x ) = {solver.solve(t1, t3)} (Expected: 2)")

    # This will be slow: a{b,c} vs d{e}
    t4 = build_from_parents([-1, 0, 0], ["a", "b", "c"])
    t5 = build_from_parents([-1, 0], ["d", "e"])
    print(f"Distance( a{{b,c}}, d{{e}} ) = {solver.solve(t4, t5)} (Expected: 3)")