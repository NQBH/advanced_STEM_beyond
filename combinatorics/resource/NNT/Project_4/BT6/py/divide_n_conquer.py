import math

# --- Global Constants and Costs ---
LAMBDA_NODE = -1  # Represents a dummy node for deletion
DEL_COST = 1      # Cost for deleting a node from T1
INS_COST = 1      # Cost for inserting a node into T2
REP_COST = 1      # Cost for relabeling

# --- Tree Node and Tree Classes ---

class TreeNode:
    def __init__(self, id, label):
        self.id = id
        self.label = label
        self.parent_id = LAMBDA_NODE
        self.children_ids = []
        self.depth = -1
        self.preorder_index = -1
        # Postorder/LMD/subtree_size are not directly used in this specific D&C variant
        self.postorder_index = -1 
        self.leftmost_descendant_postorder_idx = -1 
        self.subtree_size = 0 

    def __repr__(self):
        parent_repr = self.parent_id if self.parent_id != LAMBDA_NODE else "None"
        children_repr = ", ".join(map(str, self.children_ids))
        return (f"Node(ID:{self.id}, Label:'{self.label}', Parent:{parent_repr}, "
                f"Children:[{children_repr}], Depth:{self.depth}, "
                f"Preorder:{self.preorder_index})")

class Tree:
    def __init__(self, name=""):
        self.name = name
        self.nodes = {}  # Dictionary to store nodes: {node_id: TreeNode_object}
        self.root_id = LAMBDA_NODE
        self._next_node_id = 0
        self._preorder_traversal_list = []

    def add_node(self, label, parent_id=LAMBDA_NODE):
        node_id = self._next_node_id
        self._next_node_id += 1
        new_node = TreeNode(node_id, label)
        self.nodes[node_id] = new_node

        if parent_id != LAMBDA_NODE:
            if parent_id not in self.nodes:
                raise ValueError(f"Parent with ID {parent_id} does not exist in tree '{self.name}'.")
            parent_node = self.nodes[parent_id]
            parent_node.children_ids.append(node_id)
            new_node.parent_id = parent_id
        elif self.root_id == LAMBDA_NODE:
            self.root_id = node_id
        else:
            raise ValueError(f"Tree '{self.name}' already has a root. New nodes without parent must be the root.")
        return node_id

    def get_node(self, node_id):
        return self.nodes.get(node_id)

    def get_children_nodes(self, node_id):
        node = self.get_node(node_id)
        if node:
            return [self.get_node(child_id) for child_id in node.children_ids]
        return []

    def _dfs_preorder_and_depth(self, node_id, current_depth, current_preorder_index):
        node = self.get_node(node_id)
        if not node:
            return current_preorder_index

        node.depth = current_depth
        node.preorder_index = current_preorder_index
        self._preorder_traversal_list.append(node_id)
        current_preorder_index += 1

        for child_id in node.children_ids:
            current_preorder_index = self._dfs_preorder_and_depth(child_id, current_depth + 1, current_preorder_index)
        return current_preorder_index
    
    def compute_traversals_and_metadata(self):
        if self.root_id == LAMBDA_NODE:
            return
        self._preorder_traversal_list = []
        self._dfs_preorder_and_depth(self.root_id, 0, 0)


# --- Divide and Conquer (Constrained to Leaf Operations) for Tree Edit Distance ---

def divide_and_conquer_constrained_tree_edit_distance(T1, T2):
    """
    Computes the Tree Edit Distance between two ordered trees using a recursive
    divide-and-conquer strategy, specifically constrained to allowing insertions
    and deletions of leaves only. Internal nodes can only be relabeled.
    The cost of deleting/inserting an internal node's subtree is the sum of
    deleting/inserting its leaf descendants.

    Args:
        T1 (Tree): The first tree.
        T2 (Tree): The second tree.

    Returns:
        tuple: (min_cost, details) where min_cost is the integer edit distance
               and details is a dictionary of placeholder operation counts.
    """
    # Memoization cache for (node1_id, node2_id) -> cost to avoid redundant calculations
    memo = {}

    # Helper to get all leaf nodes in a given subtree
    def get_leaves_in_subtree(node, tree_obj):
        leaves = []
        q = [node]
        while q:
            curr_node = q.pop(0)
            if not tree_obj.get_children_nodes(curr_node.id): # It's a leaf
                leaves.append(curr_node)
            else:
                for child_id in curr_node.children_ids:
                    q.append(tree_obj.get_node(child_id))
        return leaves

    # Helper to calculate the cost of an operation (delete/insert) on an entire subtree
    # based on the "leaves only" constraint.
    def get_constrained_subtree_op_cost(node, tree_obj, operation_type):
        leaves = get_leaves_in_subtree(node, tree_obj)
        cost_per_leaf = DEL_COST if operation_type == 'delete' else INS_COST
        return len(leaves) * cost_per_leaf

    # Main recursive function
    def constrained_ted_recursive(node1, node2):
        # Use node IDs for memoization key, handle None nodes for root of empty trees
        key = (node1.id if node1 else None, node2.id if node2 else None)
        if key in memo:
            return memo[key]

        # Base Cases
        if node1 is None and node2 is None:
            return 0
        if node1 is None: # T1 exhausted, insert remaining T2 subtree (all its leaves)
            return get_constrained_subtree_op_cost(node2, T2, 'insert')
        if node2 is None: # T2 exhausted, delete remaining T1 subtree (all its leaves)
            return get_constrained_subtree_op_cost(node1, T1, 'delete')

        # Recursive Step: Consider matching node1 and node2
        # Relabel cost for the current nodes
        relabel_cost = REP_COST if node1.label != node2.label else 0
        
        # Divide: Recursively solve for children's forests
        children1 = T1.get_children_nodes(node1.id)
        children2 = T2.get_children_nodes(node2.id)
        
        # Conquer: Compute forest edit distance (using a nested DP similar to Wagner-Fischer for sequences)
        # f[i][j] stores edit distance between first `i` children of node1 and first `j` children of node2
        forest_dp_table = [[0 for _ in range(len(children2) + 1)] for _ in range(len(children1) + 1)]

        # Initialize first row (deleting children from T1's forest)
        for i in range(1, len(children1) + 1):
            forest_dp_table[i][0] = forest_dp_table[i-1][0] + get_constrained_subtree_op_cost(children1[i-1], T1, 'delete')
        # Initialize first column (inserting children into T2's forest)
        for j in range(1, len(children2) + 1):
            forest_dp_table[0][j] = forest_dp_table[0][j-1] + get_constrained_subtree_op_cost(children2[j-1], T2, 'insert')

        # Fill the forest DP table
        for i in range(1, len(children1) + 1):
            for j in range(1, len(children2) + 1):
                # Cost if we match current children (recursive call to main TED function for subtrees)
                match_current_children_cost = constrained_ted_recursive(children1[i-1], children2[j-1])
                
                forest_dp_table[i][j] = min(
                    forest_dp_table[i-1][j] + get_constrained_subtree_op_cost(children1[i-1], T1, 'delete'),  # Delete current child from T1's forest
                    forest_dp_table[i][j-1] + get_constrained_subtree_op_cost(children2[j-1], T2, 'insert'),  # Insert current child into T2's forest
                    forest_dp_table[i-1][j-1] + match_current_children_cost                                  # Match current children (recursive call)
                )
            
        # The total cost for matching node1 and node2 is their relabel cost + the cost of transforming their children forests
        match_option_cost = relabel_cost + forest_dp_table[len(children1)][len(children2)]

        # Store result in memo and return
        memo[key] = match_option_cost
        return match_option_cost

    # Pre-compute basic traversals (like depth and preorder) for Tree objects.
    # While not directly used by this specific D&C logic, it's good practice for tree classes.
    T1.compute_traversals_and_metadata()
    T2.compute_traversals_and_metadata()

    # Start the recursive process from the roots of the trees
    min_cost = constrained_ted_recursive(T1.get_node(T1.root_id), T2.get_node(T2.root_id))

    # Details (exact operation counts) are complex to reconstruct from this DP/recursion
    # and typically require additional backtracking.
    details = {
        "deletions": -1,
        "insertions": -1,
        "relabelings": -1
    }
    return min_cost, details


# --- Main Example Usage (Same as Part A and B) ---
if __name__ == "__main__":
    print("--- Example Tree Edit Distance Problem (c) Divide-and-Conquer (Leaves-Only Operations) ---")

    # Define Tree T1
    #       A
    #      / \
    #     B   C
    #    /
    #   D
    T1 = Tree("T1")
    nA = T1.add_node("A")
    nB = T1.add_node("B", nA)
    nC = T1.add_node("C", nA)
    nD = T1.add_node("D", nB)

    print("\nTree T1:")
    T1.compute_traversals_and_metadata()
    # No need to print all nodes for this D&C as structure is accessed recursively
    print(f"Root: {T1.get_node(T1.root_id).label}, Nodes: {len(T1.nodes)}")

    # Define Tree T2
    #       A
    #      / \
    #     X   Y
    #    /
    #   D
    T2 = Tree("T2")
    nxA = T2.add_node("A")
    nxX = T2.add_node("X", nxA)
    nxY = T2.add_node("Y", nxA)
    nxD = T2.add_node("D", nxX)

    print("\nTree T2:")
    T2.compute_traversals_and_metadata()
    print(f"Root: {T2.get_node(T2.root_id).label}, Nodes: {len(T2.nodes)}")

    # Solve the tree edit distance problem using Divide-and-Conquer (Constrained)
    print("\n--- Running Divide-and-Conquer (Leaves-Only Operations) Algorithm ---")
    
    min_cost, details = divide_and_conquer_constrained_tree_edit_distance(T1, T2)

    print("\n--- Minimum Edit Distance Found (Divide-and-Conquer - Constrained) ---")
    print(f"Minimum Cost: {min_cost}")
    print("Details (exact operation counts) not directly available from this implementation.")