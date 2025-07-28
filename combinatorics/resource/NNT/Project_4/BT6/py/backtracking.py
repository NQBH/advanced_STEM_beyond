import copy

# Represents a node in the tree
class TreeNode:
    def __init__(self, id, label):
        self.id = id
        self.label = label
        self.parent_id = None
        self.children_ids = []
        self.depth = -1 # Depth in the tree
        self.preorder_index = -1 # Index in preorder traversal

    def __repr__(self):
        return f"Node(ID:{self.id}, Label:'{self.label}', Parent:{self.parent_id}, Children:{self.children_ids}, Depth:{self.depth}, Preorder:{self.preorder_index})"

# Represents an ordered tree
class Tree:
    def __init__(self, name=""):
        self.name = name
        self.nodes = {}  # Dictionary to store nodes: {node_id: TreeNode_object}
        self.root_id = None
        self._next_node_id = 0 # Counter for assigning unique node IDs

        # Ensure that -1 is never used as a valid node ID
        # Since _next_node_id starts at 0, this is naturally handled.

        self._preorder_traversal_list = [] # Stores node IDs in preorder sequence

    def add_node(self, label, parent_id=None):
        """
        Adds a new node to the tree.
        If parent_id is None, it sets the node as the root if no root exists.
        """
        node_id = self._next_node_id
        self._next_node_id += 1
        new_node = TreeNode(node_id, label)
        self.nodes[node_id] = new_node

        if parent_id is not None:
            if parent_id not in self.nodes:
                raise ValueError(f"Parent with ID {parent_id} does not exist in tree '{self.name}'.")
            self.nodes[parent_id].children_ids.append(node_id)
            new_node.parent_id = parent_id
        elif self.root_id is None:
            self.root_id = node_id
        else:
            raise ValueError(f"Tree '{self.name}' already has a root. New nodes without parent must be the root.")
        return node_id

    def get_node(self, node_id):
        """Retrieves a node by its ID."""
        return self.nodes.get(node_id)

    def get_children(self, node_id):
        """Returns a list of TreeNode objects that are children of the given node_id."""
        node = self.get_node(node_id)
        return [self.get_node(child_id) for child_id in node.children_ids] if node else []

    def get_parent(self, node_id):
        """Returns the TreeNode object that is the parent of the given node_id."""
        node = self.get_node(node_id)
        return self.get_node(node.parent_id) if node and node.parent_id is not None else None

    def _dfs_preorder_and_depth(self, node_id, current_depth, current_preorder_index):
        """
        Helper for computing preorder indices and depths using DFS.
        """
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

    def compute_preorder_and_depth(self):
        """
        Computes and assigns preorder indices and depths for all nodes in the tree.
        """
        if self.root_id is None:
            return
        self._preorder_traversal_list = []
        self._dfs_preorder_and_depth(self.root_id, 0, 0)

    def get_preorder_nodes(self):
        """Returns a list of TreeNode objects in preorder traversal order."""
        return [self.get_node(node_id) for node_id in self._preorder_traversal_list]

# --- Tree Edit Distance Backtracking Algorithm ---

# Define a unique dummy node to represent deletion
lambda_node = -1 # Changed from object() to a unique integer

# Define costs for edit operations
DEL_COST = 1 # Cost for deleting a node from T1
INS_COST = 1 # Cost for inserting a node into T2 (a node in T2 not mapped from T1)
REP_COST = 1 # Cost for relabeling (replacing T1 node with T2 node of different label)

def calculate_edit_distance(T1, T2, M):
    """
    Calculates the total edit distance for a given valid mapping M.
    The cost is the sum of deletions, insertions, and relabelings.
    """
    cost = 0
    num_deletions = 0
    num_insertions = 0
    num_relabelings = 0

    # Deletions: nodes in T1 mapped to lambda_node
    for v_id, w_map in M.items():
        if w_map == lambda_node: # Changed 'is' to '=='
            num_deletions += 1
    cost += num_deletions * DEL_COST

    # Insertions: nodes in T2 that were not mapped from T1
    mapped_nodes_T2_ids = {w_map for w_map in M.values() if w_map != lambda_node} # Changed 'is not' to '!='
    all_nodes_T2_ids = set(T2.nodes.keys())
    
    # Filter out any potential invalid IDs from mapped_nodes_T2_ids
    valid_mapped_nodes_T2_ids = {w_id for w_id in mapped_nodes_T2_ids if T2.get_node(w_id) is not None}

    num_insertions = len(all_nodes_T2_ids) - len(valid_mapped_nodes_T2_ids)
    cost += num_insertions * INS_COST

    # Relabelings (replacements with different labels):
    # Nodes in T1 mapped to non-lambda in T2, but their labels differ.
    for v_id, w_map in M.items():
        if w_map != lambda_node: # Changed 'is not' to '!='
            node_v = T1.get_node(v_id)
            node_w = T2.get_node(w_map)
            
            # Defensive check: Ensure both nodes exist before comparing labels.
            if node_v is None or node_w is None:
                continue

            if node_v.label != node_w.label:
                num_relabelings += 1
    cost += num_relabelings * REP_COST

    return cost, {
        "deletions": num_deletions,
        "insertions": num_insertions,
        "relabelings": num_relabelings
    }

def set_up_candidate_nodes(T1, T2):
    """
    Initializes the candidate set C. For each node v in T1, C[v] contains
    lambda_node and all nodes w in T2 that have the same depth as v.
    """
    C = {}
    # Group T2 nodes by depth for efficient lookup
    t2_nodes_by_depth = {}
    for w_id, w_node in T2.nodes.items():
        if w_node.depth not in t2_nodes_by_depth:
            t2_nodes_by_depth[w_node.depth] = []
        t2_nodes_by_depth[w_node.depth].append(w_id)

    # For each node v in T1, populate its candidate list
    for v_node in T1.get_preorder_nodes():
        candidates = [lambda_node] # Always a candidate for deletion
        if v_node.depth in t2_nodes_by_depth:
            # Add nodes from T2 with the same depth as v
            candidates.extend(t2_nodes_by_depth[v_node.depth])
        C[v_node.id] = candidates
    return C

def refine_candidate_nodes(T1, T2, C_copy, v_id, w_id):
    """
    Refines candidate lists (C_copy) for subsequent nodes based on the current mapping (v_id, w_id).
    This function enforces the bijection, parent-child, and sibling order constraints.
    """
    # Constraint 1: Bijection - If w is a non-dummy node, it cannot be mapped by any other T1 node.
    if w_id != lambda_node: # Changed 'is not' to '!='
        # Remove w_id from candidate lists of all nodes in T1 that appear after v_id in preorder
        for x_node in T1.get_preorder_nodes():
            if x_node.preorder_index > T1.get_node(v_id).preorder_index:
                 if w_id in C_copy.get(x_node.id, []):
                     C_copy[x_node.id].remove(w_id)

    # Constraint 2: Parent-Child Preservation
    # If v maps to w (non-dummy), children of v must map to children of w (or lambda).
    for x_child_node in T1.get_children(v_id):
        candidates_for_x = C_copy.get(x_child_node.id, [])
        new_candidates_for_x = []
        for y_candidate_id in candidates_for_x:
            if y_candidate_id == lambda_node: # Changed 'is' to '=='
                new_candidates_for_x.append(lambda_node)
            else: # y_candidate_id is supposed to be a T2 node ID
                node_y_in_T2 = T2.get_node(y_candidate_id)
                # Defensive check: if node_y_in_T2 is None, it's an invalid ID, skip.
                if node_y_in_T2 is None:
                    continue
                
                if w_id != lambda_node: # Changed 'is not' to '!=' # Constraint applies only if w is a real node
                    if node_y_in_T2.parent_id == w_id:
                        new_candidates_for_x.append(y_candidate_id)
                else: # If w_id is lambda_node, no parent-child constraint from (v,w) is imposed on children
                    new_candidates_for_x.append(y_candidate_id)
        C_copy[x_child_node.id] = new_candidates_for_x

    # Constraint 3: Sibling Order Preservation
    # If v maps to w (non-dummy), any right sibling x of v must map to a right sibling y of w (or lambda).
    v_node = T1.get_node(v_id)
    if v_node.parent_id is not None and w_id != lambda_node: # Changed 'is not' to '!=' # v is not root of T1, and w is not dummy
        parent_v_node = T1.get_node(v_node.parent_id)
        
        # Identify right siblings of v in T1 based on preorder index
        v_preorder_index = v_node.preorder_index
        right_siblings_of_v_ids = []
        for child_id in parent_v_node.children_ids:
            if T1.get_node(child_id).preorder_index > v_preorder_index:
                right_siblings_of_v_ids.append(child_id)
        
        w_preorder_index = T2.get_node(w_id).preorder_index

        for x_right_sibling_id in right_siblings_of_v_ids:
            candidates_for_x = C_copy.get(x_right_sibling_id, [])
            new_candidates_for_x = []
            for y_candidate_id in candidates_for_x:
                if y_candidate_id == lambda_node: # Changed 'is' to '=='
                    new_candidates_for_x.append(lambda_node)
                else:
                    node_y_in_T2 = T2.get_node(y_candidate_id)
                    if node_y_in_T2 is None:
                        continue # Skip invalid T2 node ID in candidates
                    
                    # y must be a right sibling of w (i.e., its preorder index must be greater than w's)
                    if node_y_in_T2.preorder_index > w_preorder_index:
                        new_candidates_for_x.append(y_candidate_id)
            C_copy[x_right_sibling_id] = new_candidates_for_x
    return C_copy


def extend_tree_edit(T1, T2, M_current, L_solutions, C_current, current_v_idx):
    """
    Recursive backtracking function to build and extend partial mappings.
    """
    t1_preorder_nodes = T1.get_preorder_nodes()

    if current_v_idx == len(t1_preorder_nodes):
        # Base case: All nodes from T1 have been mapped, a complete valid transformation is found.
        M_solution_copy = copy.deepcopy(M_current) # Store a deep copy of the mapping
        cost, details = calculate_edit_distance(T1, T2, M_solution_copy)
        L_solutions.append({"mapping": M_solution_copy, "cost": cost, "details": details})
        return

    v_node_to_map = t1_preorder_nodes[current_v_idx]
    v_id = v_node_to_map.id

    # Iterate through possible mappings (candidates) for the current T1 node (v_id)
    # The .get(v_id, []) handles cases where pruning might leave no candidates for v_id
    for w_id_candidate in C_current.get(v_id, []):
        M_current[v_id] = w_id_candidate # Assign v_id to w_id_candidate

        # Create a deep copy of the candidate set C for the next recursive call.
        # This ensures that changes made during refinement are localized to the current branch.
        C_next = copy.deepcopy(C_current)
        
        # Refine the candidate set for subsequent nodes based on this new assignment
        refine_candidate_nodes(T1, T2, C_next, v_id, w_id_candidate)

        # Recursive call: proceed to map the next node in T1's preorder traversal
        extend_tree_edit(T1, T2, M_current, L_solutions, C_next, current_v_idx + 1)
        
        # Backtrack: When the recursive call returns, M_current[v_id] will be implicitly
        # overwritten by the next iteration of the loop, effectively "un-assigning" it for the next branch.

def backtracking_tree_edit(T1, T2):
    """
    Main function for the backtracking algorithm to find all valid tree transformations
    from T1 to T2.
    """
    # Pre-process trees to compute depths and preorder indices
    T1.compute_preorder_and_depth()
    T2.compute_preorder_and_depth()

    M = {} # Current partial mapping {T1_node_id: T2_node_id or lambda_node}
    L = [] # List to store all complete valid transformations

    # Initialize the candidate set for all nodes in T1
    C = set_up_candidate_nodes(T1, T2)

    # Start the recursive backtracking process from the first node of T1 (index 0 in preorder list)
    extend_tree_edit(T1, T2, M, L, C, 0)

    return L

# --- Example Usage ---
if __name__ == "__main__":
    print("--- Example Tree Edit Distance Problem (Backtracking) ---")

    # Define Tree T1
    #       A
    #      / \
    #     B   C
    #    /
    #   D
    T1 = Tree("T1")
    nA = T1.add_node("A")
    nB = T1.add_node("B", parent_id=nA)
    nC = T1.add_node("C", parent_id=nA)
    nD = T1.add_node("D", parent_id=nB)

    print("\nTree T1:")
    T1.compute_preorder_and_depth()
    for node in T1.get_preorder_nodes():
        print(node)

    # Define Tree T2
    #       A
    #      / \
    #     X   Y
    #    /
    #   D
    T2 = Tree("T2")
    nxA = T2.add_node("A")
    nxX = T2.add_node("X", parent_id=nxA)
    nxY = T2.add_node("Y", parent_id=nxA)
    nxD = T2.add_node("D", parent_id=nxX)

    print("\nTree T2:")
    T2.compute_preorder_and_depth()
    for node in T2.get_preorder_nodes():
        print(node)

    # Solve the tree edit distance problem using backtracking
    print("\n--- Running Backtracking Algorithm ---")
    solutions = backtracking_tree_edit(T1, T2)

    print(f"\nFound {len(solutions)} valid transformation(s):")
    if solutions:
        min_cost = float('inf')
        min_cost_solution = None
        
        for i, sol in enumerate(solutions):
            mapping = sol["mapping"]
            cost = sol["cost"]
            details = sol["details"]

            print(f"\nSolution {i+1}: Cost = {cost} (Deletions: {details['deletions']}, Insertions: {details['insertions']}, Relabelings: {details['relabelings']})")
            print("  Mapping (T1_ID -> T2_ID or lambda):")
            for t1_id, t2_mapped_id in mapping.items():
                t1_node = T1.get_node(t1_id)
                # Defensive check for printing
                if t2_mapped_id != lambda_node: # Changed 'is not' to '!='
                    node_w_for_print = T2.get_node(t2_mapped_id)
                    t2_node_str = node_w_for_print.label if node_w_for_print else f"INVALID_NODE_ID:{t2_mapped_id}"
                    t2_node_id_str = t2_mapped_id
                else:
                    t2_node_str = "λ"
                    t2_node_id_str = "λ"
                print(f"    {t1_node.label}(ID:{t1_id}) -> {t2_node_str}(ID:{t2_node_id_str})")
            
            if cost < min_cost:
                min_cost = cost
                min_cost_solution = sol
        
        if min_cost_solution:
            print(f"\n--- Minimum Edit Distance Found ---")
            print(f"Minimum Cost: {min_cost}")
            print(f"Details: Deletions: {min_cost_solution['details']['deletions']}, "
                  f"Insertions: {min_cost_solution['details']['insertions']}, "
                  f"Relabelings: {min_cost_solution['details']['relabelings']}")
            print("Mapping:")
            for t1_id, t2_mapped_id in min_cost_solution["mapping"].items():
                t1_node = T1.get_node(t1_id)
                # Defensive check for printing
                if t2_mapped_id != lambda_node: # Changed 'is not' to '!='
                    node_w_for_print = T2.get_node(t2_mapped_id)
                    t2_node_str = node_w_for_print.label if node_w_for_print else f"INVALID_NODE_ID:{t2_mapped_id}"
                    t2_node_id_str = t2_mapped_id
                else:
                    t2_node_str = "λ"
                    t2_node_id_str = "λ"
                print(f"    {t1_node.label}(ID:{t1_id}) -> {t2_node_str}(ID:{t2_node_id_str})")
    else:
        print("No valid transformations found.")