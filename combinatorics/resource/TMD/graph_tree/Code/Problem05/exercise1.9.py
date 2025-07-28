from typing import List, Optional

def previous_sibling(v: int, parent_array: List[int]) -> Optional[int]:
    """
    Exercise 1.9: Implements the T.previous_sibling(v) operation.

    This function finds the sibling of a node `v` that appears immediately
    before it, based on the node index ordering. It operates on the
    array-of-parents representation of a tree.

    The algorithm is as follows:
    1. Find the parent `p` of the given node `v`. If `v` is the root, it has no siblings.
    2. Iterate from the beginning of the array up to `v-1`.
    3. Keep track of the last node `i` encountered such that parent[i] == p.
    4. This last node found is the immediate previous sibling.

    :param v: The node whose previous sibling is to be found.
    :param parent_array: The tree represented as a list of parents. parent_array[i] is the
                         parent of node i. The root's parent is -1.
    :return: The index of the previous sibling if one exists, otherwise None.
    """
    # Validate input node index
    if not (0 <= v < len(parent_array)):
        return None
    
    parent = parent_array[v]
    
    # The root has no parent, and thus no siblings.
    if parent == -1:
        return None
        
    prev_sibling = None
    
    # Iterate through all nodes with index less than v.
    for i in range(v):
        # If node `i` has the same parent, it is an earlier sibling.
        if parent_array[i] == parent:
            # Keep updating, so we end up with the one with the largest index less than v.
            prev_sibling = i
            
    return prev_sibling

# =================================================================================
# MAIN EXECUTION BLOCK - DEMONSTRATION FOR EXERCISE 1.9
# =================================================================================
if __name__ == "__main__":
    print("=" * 60)
    print("  `previous_sibling` Demo (Exercise 1.9)             ")
    print("=" * 60)

    # Tree representation: P[i] = parent of node i.
    # Node 0 is root.
    # Children of 0: {1, 2}
    # Children of 1: {3, 4}
    # Children of 2: {5, 6}
    parent_array = [-1, 0, 0, 1, 1, 2, 2]
    print(f"Tree (Parent Array): {parent_array}\n")

    # Test cases
    nodes_to_test = [0, 1, 2, 3, 4, 6]
    
    for node in nodes_to_test:
        result = previous_sibling(node, parent_array)
        print(f"-> Finding previous sibling of node {node}:")
        if result is not None:
            print(f"   Result: Node {result}")
        else:
            print("   Result: No previous sibling exists.")
    
    print("=" * 60)