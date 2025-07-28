import sys
from typing import List, Optional

sys.setrecursionlimit(2000)

class Node:
    """Represents a node in a tree with a label and a list of children."""
    def __init__(self, label: str):
        self.label = label
        self.children: List['Node'] = []
    def __repr__(self): return f"Node({self.label})"

class BranchAndBoundSolver:
    """
    Solves the Tree Edit Distance problem using a Branch and Bound algorithm.
    It improves upon backtracking by pruning search branches that are guaranteed
    to not yield a better solution than the best one found so far.
    """

    def __init__(self):
        self.min_cost = float('inf')

    def get_subtree_size(self, node: Optional[Node]) -> int:
        """Helper to get the total number of nodes in a subtree."""
        if not node: return 0
        return 1 + sum(self.get_subtree_size(child) for child in node.children)

    def solve(self, t1: Optional[Node], t2: Optional[Node]) -> int:
        """
        Public entry point for the Branch and Bound solver.
        Initializes the best cost with a simple upper bound and starts the search.
        """
        # An initial upper bound: cost of deleting all nodes in t1 and inserting all in t2.
        self.min_cost = self.get_subtree_size(t1) + self.get_subtree_size(t2)
        self._ted_bnb(t1, t2, 0)
        return self.min_cost if self.min_cost != float('inf') else 0
    
    def _lower_bound(self, f1: List[Node], f2: List[Node]) -> int:
        """
        A simple lower bound function for forest distance.
        The cost must be at least the difference in the number of trees.
        A better heuristic would improve performance.
        """
        return abs(len(f1) - len(f2))

    def _ted_bnb(self, t1: Optional[Node], t2: Optional[Node], current_cost: int):
        """
        The core recursive function for Branch and Bound on trees.
        """
        # --- Pruning Step ---
        if current_cost + abs(self.get_subtree_size(t1) - self.get_subtree_size(t2)) >= self.min_cost:
            return

        # Base cases: If one tree is None, calculate cost and update min_cost if better.
        if t1 is None:
            final_cost = current_cost + self.get_subtree_size(t2)
            self.min_cost = min(self.min_cost, final_cost)
            return
        if t2 is None:
            final_cost = current_cost + self.get_subtree_size(t1)
            self.min_cost = min(self.min_cost, final_cost)
            return

        # --- Branching on Root Operations ---
        cost_relabel = 0 if t1.label == t2.label else 1
        self._forest_dist_bnb(t1.children, t2.children, current_cost + cost_relabel)

    def _forest_dist_bnb(self, f1: List[Node], f2: List[Node], current_cost: int):
        """
        Recursive B&B for finding the minimum cost to map forest f1 to forest f2.
        """
        # --- Pruning Step for Forests ---
        if current_cost + self._lower_bound(f1, f2) >= self.min_cost:
            return

        # Base cases: if one forest is empty, calculate final cost and update min.
        if not f1 and not f2:
            self.min_cost = min(self.min_cost, current_cost)
            return
        if not f1:
            self.min_cost = min(self.min_cost, current_cost + sum(self.get_subtree_size(t) for t in f2))
            return
        if not f2:
            self.min_cost = min(self.min_cost, current_cost + sum(self.get_subtree_size(t) for t in f1))
            return
        
        t1_head, f1_tail = f1[0], f1[1:]

        # Branch 1: Delete t1_head.
        self._forest_dist_bnb(f1_tail, f2, current_cost + self.get_subtree_size(t1_head))
        
        # Branch 2: Match t1_head with each tree t2_j in f2.
        for j in range(len(f2)):
            t2_match = f2[j]
            f2_remaining = f2[:j] + f2[j+1:]
            
            # Create a sub-problem solver for the match
            sub_solver = BranchAndBoundSolver()
            cost_match = sub_solver.solve(t1_head, t2_match)
            
            # Recurse on the rest of the forests
            self._forest_dist_bnb(f1_tail, f2_remaining, current_cost + cost_match)

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
    print("     (b) Tree Edit Distance: Branch and Bound Solver      ")
    print("=" * 60)
    print("NOTE: Still slow, but prunes some search paths vs. pure backtracking.\n")

    # --- Test Cases ---
    t1 = build_from_parents([-1, 0, 0], ["a", "b", "c"])
    t2 = build_from_parents([-1, 0, 0], ["a", "d", "c"])
    solver1 = BranchAndBoundSolver()
    print(f"Distance( a{{b,c}}, a{{d,c}} ) = {solver1.solve(t1, t2)} (Expected: 1)")

    t3 = build_from_parents([-1], ["x"])
    solver2 = BranchAndBoundSolver()
    print(f"Distance( a{{b,c}}, x ) = {solver2.solve(t1, t3)} (Expected: 3)")