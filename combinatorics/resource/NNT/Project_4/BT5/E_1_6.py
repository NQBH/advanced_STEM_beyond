def enumerate_perfect_matchings_kpq(p, q):
    """
    Enumerate all perfect matchings in a complete bipartite graph K_p,q.
    A perfect matching exists only if p == q.

    Args:
        p (int): Number of vertices in the first partition.
        q (int): Number of vertices in the second partition.

    Returns:
        list[list[tuple[int, int]]]: A list of all perfect matchings.
                                     Each matching is a list of (source, target) edge tuples.
                                     Left vertices are 0 to p-1.
                                     Right vertices are p to p+q-1.
    """
    all_matchings = []

    # Perfect matching requires equal partition sizes
    if p != q:
        return all_matchings

    n = p  # Since p == q, n represents the size of each partition

    current_matching = []  # Stores edges for the current matching being built
    # used_right_vertices tracks if a vertex in the RIGHT partition (relative index 0 to n-1) is used
    used_right_vertices = [False] * n

    def find_matchings_recursive(l_idx):
        """
        Recursive helper function to find perfect matchings.
        l_idx: The current vertex index in the left partition (absolute ID) to match.
        """
        # Base case: If all left vertices have been matched, a perfect matching is found
        if l_idx == n:
            all_matchings.append(list(current_matching)) # Add a copy of the current matching
            return

        # Iterate through all vertices in the right partition to find a match for L[l_idx]
        for r_relative_idx in range(n):
            # If the current right vertex is not yet used
            if not used_right_vertices[r_relative_idx]:
                used_right_vertices[r_relative_idx] = True  # Mark as used
                
                # Form the edge using absolute vertex IDs
                # Left vertex ID is l_idx
                # Right vertex ID is n + r_relative_idx (since right partition starts after left)
                edge = (l_idx, n + r_relative_idx)
                current_matching.append(edge)

                # Recursively call for the next left vertex
                find_matchings_recursive(l_idx + 1)

                # Backtrack: Undo the choice for the current L[l_idx]
                current_matching.pop()
                used_right_vertices[r_relative_idx] = False

    # Start the recursive process from the first vertex in the left partition (index 0)
    find_matchings_recursive(0)
    return all_matchings

if __name__ == "__main__":
    # Example 1: K_3,3 (expect 3! = 6 perfect matchings)
    p1, q1 = 3, 3
    print(f"Enumerating perfect matchings for K_{p1},{q1}:")
    matchings1 = enumerate_perfect_matchings_kpq(p1, q1)
    if not matchings1:
        print("No perfect matchings found.")
    else:
        for i, matching in enumerate(matchings1):
            print(f"  Matching {i+1}: {matching}")
        print(f"Total perfect matchings: {len(matchings1)}\n")

    # Example 2: K_2,2 (expect 2! = 2 perfect matchings)
    p2, q2 = 2, 2
    print(f"Enumerating perfect matchings for K_{p2},{q2}:")
    matchings2 = enumerate_perfect_matchings_kpq(p2, q2)
    if not matchings2:
        print("No perfect matchings found.")
    else:
        for i, matching in enumerate(matchings2):
            print(f"  Matching {i+1}: {matching}")
        print(f"Total perfect matchings: {len(matchings2)}\n")

    # Example 3: K_2,3 (expect 0 perfect matchings)
    p3, q3 = 2, 3
    print(f"Enumerating perfect matchings for K_{p3},{q3}:")
    matchings3 = enumerate_perfect_matchings_kpq(p3, q3)
    if not matchings3:
        print("No perfect matchings found.")
    else:
        for i, matching in enumerate(matchings3):
            print(f"  Matching {i+1}: {matching}")
        print(f"Total perfect matchings: {len(matchings3)}\n")

    # Example 4: K_0,0 (expect 1 perfect matching - empty set)
    p4, q4 = 0, 0
    print(f"Enumerating perfect matchings for K_{p4},{q4}:")
    matchings4 = enumerate_perfect_matchings_kpq(p4, q4)
    if not matchings4:
        print("No perfect matchings found.")
    else:
        for i, matching in enumerate(matchings4):
            print(f"  Matching {i+1}: {matching}")
        print(f"Total perfect matchings: {len(matchings4)}\n")