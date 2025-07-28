from typing import List, Tuple, Iterator

# A type alias for a matching. It's a list of tuples, where each
# tuple is a matched pair (x_vertex, y_vertex).
Matching = List[Tuple[int, int]]

def enumerate_perfect_matchings(p: int, q: int) -> Iterator[Matching]:
    """
    Exercise 1.6: Enumerates all perfect matchings in a complete bipartite graph K_p,q.

    A perfect matching pairs every vertex from the smaller partition with a unique
    vertex from the larger one. For a true "perfect matching" covering ALL vertices
    of the graph, we must have p == q. This function handles the general definition
    and will only yield results if p == q.

    This implementation uses a recursive backtracking algorithm to generate all
    permutations of pairings.

    :param p: The size of the first partition (X).
    :param q: The size of the second partition (Y).
    :return: A generator that yields each perfect matching as a list of tuples.
    """
    # A perfect matching that covers all vertices can only exist if p == q.
    if p != q or p <= 0:
        return
        yield # An empty generator

    # Vertices in partition Y that are still available to be matched.
    available_y = list(range(p))
    
    def find_matchings_recursive(current_matching: Matching, remaining_y: List[int]):
        """
        A recursive helper function to find matchings via backtracking.

        :param current_matching: The list of pairs matched so far.
        :param remaining_y: The list of vertices in partition Y still available.
        """
        # Base case: if no vertices are left in Y, we have found a complete matching.
        if not remaining_y:
            yield current_matching
            return

        # Determine the next vertex from partition X to match.
        # Its index is simply the number of pairs we've already matched.
        x_vertex_idx = len(current_matching)

        # Try matching x_vertex_idx with each available vertex in Y.
        for i in range(len(remaining_y)):
            y_vertex = remaining_y[i]
            
            # Create a new list of remaining Y vertices for the recursive call.
            next_remaining_y = remaining_y[:i] + remaining_y[i+1:]
            
            # Recurse: add the new pair and pass the smaller list of available vertices.
            yield from find_matchings_recursive(
                current_matching + [(x_vertex_idx, y_vertex)],
                next_remaining_y
            )

    # Start the recursion with an empty matching and all Y vertices available.
    yield from find_matchings_recursive([], available_y)

def print_matchings(matchings_generator: Iterator[Matching], p: int, q: int):
    """Helper function to print the list of matchings."""
    matchings = list(matchings_generator)
    print(f"--- Found {len(matchings)} perfect matchings for K_{p},{q} ---")
    if not matchings and p != q:
        print("  (As expected, no perfect matching exists since p != q)")
    elif not matchings and p == 0:
        print("  (An empty matching for an empty graph)")
    else:
        for i, matching in enumerate(matchings, 1):
            edges_str = ", ".join([f"(x{x}, y{y})" for x, y in matching])
            print(f"  Matching {i}: {{ {edges_str} }}")
    print("------------------------------------------")

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR EXERCISE 1.6
# =================================================================================
if __name__ == "__main__":
    print("=" * 60)
    print(" Perfect Matching Enumeration Demo (Exercise 1.6)    ")
    print("=" * 60)

    # --- Case 1: p = q, perfect matchings exist ---
    p1, q1 = 3, 3
    # The number of matchings should be 3! = 6
    matchings1 = enumerate_perfect_matchings(p1, q1)
    print_matchings(matchings1, p1, q1)

    # --- Case 2: p != q, no perfect matchings ---
    p2, q2 = 3, 2
    matchings2 = enumerate_perfect_matchings(p2, q2)
    print_matchings(matchings2, p2, q2)
    
    # --- Case 3: p = q = 4 ---
    p3, q3 = 4, 4
    # The number of matchings should be 4! = 24
    matchings3 = enumerate_perfect_matchings(p3, q3)
    print_matchings(matchings3, p3, q3)

    print("=" * 60)