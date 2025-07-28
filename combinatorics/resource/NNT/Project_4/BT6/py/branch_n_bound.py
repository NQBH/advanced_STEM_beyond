import math

# --- Global Constants and Costs ---
LAMBDA_NODE = -1  # Represents a dummy node for deletion
DEL_COST = 1      # Cost for deleting a node from T1
INS_COST = 1      # Cost for inserting a node into T2
REP_COST = 1      # Cost for relabeling

# --- Tree Node and Tree Classes (Reused from previous problem) ---

class TreeNode:
    def __init__(self, id, label):
        self.id = id
        self.label = label
        self.parent = None  # Store parent TreeNode object for easier traversal (or ID)
        self.parent_id = LAMBDA_NODE
        self.children = []  # Store child TreeNode objects (or IDs)
        self.children_ids = []
        self.depth = -1
        self.preorder_index = -1

    def __repr__(self):
        parent_repr = self.parent_id if self.parent_id != LAMBDA_NODE else "None"
        children_repr = ", ".join(map(str, self.children_ids))
        return (f"Node(ID:{self.id}, Label:'{self.label}', Parent:{parent_repr}, "
                f"Children:[{children_repr}], Depth:{self.depth}, Preorder:{self.preorder_index})")

class Tree:
    def __init__(self, name=""):
        self.name = name
        self.nodes = {}  # Dictionary to store nodes: {node_id: TreeNode_object}
        self.root_id = LAMBDA_NODE
        self._next_node_id = 0
        self._preorder_traversal_list = [] # Stores node IDs in preorder sequence

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

    def get_children(self, node_id):
        node = self.get_node(node_id)
        if node:
            return [self.get_node(child_id) for child_id in node.children_ids]
        return []

    def get_parent(self, node_id):
        node = self.get_node(node_id)
        if node and node.parent_id != LAMBDA_NODE:
            return self.get_node(node.parent_id)
        return None

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

    def compute_preorder_and_depth(self):
        if self.root_id == LAMBDA_NODE:
            return
        self._preorder_traversal_list = []
        self._dfs_preorder_and_depth(self.root_id, 0, 0)

    def get_preorder_nodes(self):
        return [self.get_node(node_id) for node_id in self._preorder_traversal_list]

# --- Tree Edit Distance Functions ---

def _calculate_partial_cost(T1, T2, M_current):
    """
    Calculates the cost of a partial mapping, only considering committed deletions and relabelings.
    Does NOT include insertions, as they depend on the final complete mapping.
    """
    current_cost = 0
    
    # Deletions: nodes in T1 mapped to LAMBDA_NODE
    for v_id, w_map in M_current.items():
        if w_map == LAMBDA_NODE:
            current_cost += DEL_COST
        else:
            # Relabelings (replacements with different labels):
            node_v = T1.get_node(v_id)
            node_w = T2.get_node(w_map)
            
            if node_v and node_w and node_v.label != node_w.label:
                current_cost += REP_COST
    return current_cost

def calculate_edit_distance(T1, T2, M):
    """
    Calculates the total edit distance for a complete mapping M.
    Includes deletions, insertions, and relabelings.
    """
    cost = 0
    num_deletions = 0
    num_insertions = 0
    num_relabelings = 0

    # Deletions: nodes in T1 mapped to LAMBDA_NODE
    for v_id, w_map in M.items():
        if w_map == LAMBDA_NODE:
            num_deletions += 1
    cost += num_deletions * DEL_COST

    # Insertions: nodes in T2 that were not mapped from T1
    mapped_nodes_T2_ids = set(w_map for w_map in M.values() if w_map != LAMBDA_NODE)
    all_nodes_T2_ids = set(T2.nodes.keys())
    
    # Filter out any potential invalid IDs from mapped_nodes_T2_ids for insertion count
    valid_mapped_nodes_T2_ids = {w_id for w_id in mapped_nodes_T2_ids if T2.get_node(w_id) is not None}
    
    num_insertions = len(all_nodes_T2_ids) - len(valid_mapped_nodes_T2_ids)
    cost += num_insertions * INS_COST

    # Relabelings (replacements with different labels):
    for v_id, w_map in M.items():
        if w_map != LAMBDA_NODE:
            node_v = T1.get_node(v_id)
            node_w = T2.get_node(w_map)
            
            # Defensive check: Ensure both nodes exist before comparing labels.
            if node_v and node_w and node_v.label != node_w.label:
                num_relabelings += 1
    cost += num_relabelings * REP_COST

    details = {
        "deletions": num_deletions,
        "insertions": num_insertions,
        "relabelings": num_relabelings
    }
    return cost, details

def set_up_candidate_nodes(T1, T2):
    """
    Initializes the candidate set C for all nodes in T1.
    C[v_id] contains LAMBDA_NODE and all nodes w in T2 with the same depth as v_id.
    """
    C = {}
    # Group T2 nodes by depth for efficient lookup
    t2_nodes_by_depth = {}
    for node_id, node in T2.nodes.items():
        if node.depth not in t2_nodes_by_depth:
            t2_nodes_by_depth[node.depth] = []
        t2_nodes_by_depth[node.depth].append(node_id)

    # For each node v in T1, populate its candidate list
    for v_node in T1.get_preorder_nodes():
        candidates = [LAMBDA_NODE] # Always a candidate for deletion
        if v_node.depth in t2_nodes_by_depth:
            candidates.extend(t2_nodes_by_depth[v_node.depth])
        C[v_node.id] = candidates
    return C

def refine_candidate_nodes(T1, T2, C_copy, v_id, w_id):
    """
    Refines the candidate set C_copy based on the new mapping (v_id -> w_id)
    and the structural constraints.
    C_copy is modified in place.
    """
    # Constraint 1: Bijection - If w is a non-dummy node, it cannot be mapped by any other T1 node.
    if w_id != LAMBDA_NODE:
        v_node_t1 = T1.get_node(v_id)
        if not v_node_t1: return # Should not happen if v_id is valid

        # Remove w_id from candidate lists of all nodes in T1 that appear after v_id in preorder
        for x_node in T1.get_preorder_nodes():
            if x_node.preorder_index > v_node_t1.preorder_index:
                if x_node.id in C_copy:
                    C_copy[x_node.id] = [cand for cand in C_copy[x_node.id] if cand != w_id]

    # Constraint 2: Parent-Child Preservation
    # If v maps to w (non-dummy), children of v must map to children of w (or LAMBDA_NODE).
    for x_child_node in T1.get_children(v_id):
        if x_child_node.id in C_copy:
            new_candidates_for_x = []
            for y_candidate_id in C_copy[x_child_node.id]:
                if y_candidate_id == LAMBDA_NODE:
                    new_candidates_for_x.append(LAMBDA_NODE)
                else: # y_candidate_id is supposed to be a T2 node ID
                    node_y_in_T2 = T2.get_node(y_candidate_id)
                    if node_y_in_T2 is None: # Invalid ID, skip
                        continue
                    
                    if w_id != LAMBDA_NODE: # Constraint applies only if w is a real node
                        # y_candidate_id must be a child of w_id in T2
                        if node_y_in_T2.parent_id == w_id:
                            new_candidates_for_x.append(y_candidate_id)
                    else: # If w_id is LAMBDA_NODE, no parent-child constraint from (v,w) is imposed on children from T2
                        new_candidates_for_x.append(y_candidate_id)
            C_copy[x_child_node.id] = new_candidates_for_x

    # Constraint 3: Sibling Order Preservation
    # If v maps to w (non-dummy), any right sibling x of v must map to a right sibling y of w (or LAMBDA_NODE).
    v_node = T1.get_node(v_id)
    if not v_node: return # Should not happen if v_id is valid

    if v_node.parent_id != LAMBDA_NODE and w_id != LAMBDA_NODE: # v is not root of T1, and w is not dummy
        parent_v_node = T1.get_node(v_node.parent_id)
        if not parent_v_node: return # Should not happen

        # Identify right siblings of v in T1 based on preorder index
        v_preorder_index = v_node.preorder_index
        right_siblings_of_v_ids = [
            child_node.id for child_node in T1.get_children(parent_v_node.id)
            if child_node and child_node.preorder_index > v_preorder_index
        ]
        
        w_node_t2 = T2.get_node(w_id)
        if not w_node_t2: return # Should not happen if w_id is valid and not LAMBDA_NODE
        w_preorder_index = w_node_t2.preorder_index

        for x_right_sibling_id in right_siblings_of_v_ids:
            if x_right_sibling_id in C_copy:
                new_candidates_for_x = []
                for y_candidate_id in C_copy[x_right_sibling_id]:
                    if y_candidate_id == LAMBDA_NODE:
                        new_candidates_for_x.append(LAMBDA_NODE)
                    else:
                        node_y_in_T2 = T2.get_node(y_candidate_id)
                        if node_y_in_T2 is None:
                            continue # Skip invalid T2 node ID in candidates
                        
                        # y must be a right sibling of w (i.e., its preorder index must be greater than w's)
                        # and have the same parent as w
                        if (node_y_in_T2.preorder_index > w_preorder_index and
                            node_y_in_T2.parent_id == w_node_t2.parent_id):
                            new_candidates_for_x.append(y_candidate_id)
                C_copy[x_right_sibling_id] = new_candidates_for_x


def branch_and_bound_extend_tree_edit(T1, T2, M_current, C_current, current_v_idx,
                                      best_solution):
    """
    Recursive function for Branch-and-Bound tree edit distance.
    `best_solution` is a dictionary with 'cost' and 'mapping' keys, passed by reference.
    """
    t1_preorder_nodes = T1.get_preorder_nodes()

    # Pruning step (Upper Bounding)
    # Calculate the current cost based on committed operations in M_current.
    # This is a lower bound for any complete solution extending M_current.
    lower_bound_cost = _calculate_partial_cost(T1, T2, M_current)
    
    if lower_bound_cost >= best_solution['cost']:
        # If the current partial path already exceeds or matches the best known cost, prune this branch.
        return

    if current_v_idx == len(t1_preorder_nodes):
        # Base case: All nodes from T1 have been mapped, a complete valid transformation is found.
        final_cost, details = calculate_edit_distance(T1, T2, M_current)
        
        if final_cost < best_solution['cost']:
            best_solution['cost'] = final_cost
            best_solution['mapping'] = M_current.copy() # Store a copy of the mapping
            best_solution['details'] = details
        return

    v_node_to_map = t1_preorder_nodes[current_v_idx]
    v_id = v_node_to_map.id

    # Iterate through possible mappings (candidates) for the current T1 node (v_id)
    if v_id in C_current: # Check if v_id still has candidates after pruning
        for w_id_candidate in list(C_current[v_id]): # Iterate over a copy as C_current might be refined
            
            # Tentatively assign v_id to w_id_candidate
            M_current[v_id] = w_id_candidate 

            # Create a deep copy of the candidate set C for the next recursive call.
            C_next = {k: v[:] for k, v in C_current.items()} # Deep copy lists within dict
            refine_candidate_nodes(T1, T2, C_next, v_id, w_id_candidate)

            # Recursive call: proceed to map the next node in T1's preorder traversal
            branch_and_bound_extend_tree_edit(T1, T2, M_current, C_next, current_v_idx + 1, best_solution)
            
            # Backtrack: Remove the current assignment to allow other paths
            # This is implicitly handled by overwriting or not using the value
            # M_current.pop(v_id) # Explicit pop can be added for clarity, but not strictly needed for correctness if always overwritten.
    else:
        # If no candidates left for v_id, this branch cannot lead to a solution for all nodes.
        # This effectively prunes the branch if initial setup or refinement leads to empty candidate lists.
        pass


def branch_and_bound_tree_edit(T1, T2):
    """
    Main function for Branch-and-Bound Tree Edit Distance.
    """
    # Pre-process trees to compute depths and preorder indices
    T1.compute_preorder_and_depth()
    T2.compute_preorder_and_depth()

    # Use a dictionary to pass mutable state (best cost and mapping) by "reference"
    best_solution = {
        'cost': math.inf,
        'mapping': {},
        'details': {}
    }
    
    M = {} # Current partial mapping {T1_node_id: T2_node_id or LAMBDA_NODE}

    # Initialize the candidate set for all nodes in T1
    C = set_up_candidate_nodes(T1, T2)

    # Start the recursive branch-and-bound process from the first node of T1 (index 0 in preorder list)
    branch_and_bound_extend_tree_edit(T1, T2, M, C, 0, best_solution)

    return best_solution


# --- Main Example Usage (Same as Part A) ---
if __name__ == "__main__":
    print("--- Example Tree Edit Distance Problem (Branch-and-Bound) ---")

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
    nxX = T2.add_node("X", nxA)
    nxY = T2.add_node("Y", nxA)
    nxD = T2.add_node("D", nxX)

    print("\nTree T2:")
    T2.compute_preorder_and_depth()
    for node in T2.get_preorder_nodes():
        print(node)

    # Solve the tree edit distance problem using Branch-and-Bound
    print("\n--- Running Branch-and-Bound Algorithm ---")
    
    min_cost_solution = branch_and_bound_tree_edit(T1, T2)

    print("\n--- Minimum Edit Distance Found (Branch-and-Bound) ---")
    if min_cost_solution['cost'] != math.inf:
        print(f"Minimum Cost: {min_cost_solution['cost']}")
        print(f"Details: Deletions: {min_cost_solution['details']['deletions']}, "
              f"Insertions: {min_cost_solution['details']['insertions']}, "
              f"Relabelings: {min_cost_solution['details']['relabelings']}")
        print("Mapping:")
        # Sort mapping by T1 node ID for consistent output
        sorted_mapping = sorted(min_cost_solution['mapping'].items(), key=lambda item: item[0])
        for t1_id, t2_mapped_id in sorted_mapping:
            t1_node = T1.get_node(t1_id)
            
            t2_node_str = ""
            t2_node_id_str = ""

            if t2_mapped_id != LAMBDA_NODE:
                node_w_for_print = T2.get_node(t2_mapped_id)
                if node_w_for_print:
                    t2_node_str = node_w_for_print.label
                    t2_node_id_str = str(t2_mapped_id)
                else:
                    t2_node_str = "INVALID_NODE_ID" # Should not happen with correct logic
                    t2_node_id_str = str(t2_mapped_id)
            else:
                t2_node_str = "λ"
                t2_node_id_str = "λ"
            print(f"    {t1_node.label}(ID:{t1_id}) -> {t2_node_str}(ID:{t2_node_id_str})")
    else:
        print("No solution found (This should not happen for a well-formed problem).")