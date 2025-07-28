import collections

# Define a global placeholder for lambda_node (representing a deleted node)
lambda_node = "λ"

class Node:
    def __init__(self, label, node_id, parent_id=None):
        self.label = label
        self.node_id = node_id
        self.parent_id = parent_id
        self.children_ids = []
        self.depth = -1 # Will be computed
        self.preorder_index = -1 # Will be computed

    def __repr__(self):
        return f"Node(ID:{self.node_id}, Label:{self.label}, Parent:{self.parent_id if self.parent_id is not None else 'None'}, Depth:{self.depth})"

class Tree:
    def __init__(self, name):
        self.name = name
        self.nodes = {}
        self.root_id = None
        self._next_node_id = 0
        self._preorder_nodes = [] # To store nodes in preorder traversal

    def add_node(self, label, parent_id=None):
        node_id = self._next_node_id
        new_node = Node(label, node_id, parent_id)
        self.nodes[node_id] = new_node
        if parent_id is None:
            if self.root_id is not None:
                # In a well-formed tree, there's only one root. For simplicity,
                # we'll assume the first node added without a parent is the root.
                pass
            self.root_id = node_id
        else:
            if parent_id in self.nodes:
                self.nodes[parent_id].children_ids.append(node_id)
        self._next_node_id += 1
        return node_id

    def get_node(self, node_id):
        return self.nodes.get(node_id)

    def compute_preorder_and_depth(self):
        self._preorder_nodes = []
        if self.root_id is None:
            return

        stack = [(self.root_id, 0)] # (node_id, depth)
        preorder_counter = 0

        # Using a stack to simulate recursion for preorder traversal
        # The stack will be processed Last-In, First-Out.
        # To get a Left-to-Right preorder, children must be pushed in reverse order.
        
        # We need a temporary stack to process children
        traversal_stack = [(self.root_id, 0)]
        
        # List to store nodes as we visit them in preorder
        temp_preorder_list = []

        while traversal_stack:
            current_node_id, current_depth = traversal_stack.pop()
            current_node = self.nodes[current_node_id]

            current_node.depth = current_depth
            current_node.preorder_index = preorder_counter
            temp_preorder_list.append(current_node)
            preorder_counter += 1

            # Push children onto stack in reverse order to ensure left-to-right processing
            # assuming children_ids are already stored in left-to-right order
            for child_id in reversed(current_node.children_ids):
                traversal_stack.append((child_id, current_depth + 1))
        
        # Sort by preorder_index to ensure correct order if `pop` order doesn't align
        self._preorder_nodes = sorted(temp_preorder_list, key=lambda node: node.preorder_index)


    def get_preorder_nodes(self):
        return self._preorder_nodes

# --- Dynamic Programming Algorithm for Tree Edit Distance ---
def tree_edit_distance_dp(T1: Tree, T2: Tree):
    """
    Calculates the Tree Edit Distance between two trees using a dynamic programming approach
    with memoization. Costs are: 1 for deletion, 1 for insertion, 1 for relabeling (0 if same).
    """
    
    memo = {} # Stores (n1_id, n2_id) -> cost to avoid redundant calculations

    # Recursive function to calculate the edit distance between two subtrees
    def calculate_distance_recursive(n1_id, n2_id):
        # Check memoization table
        if (n1_id, n2_id) in memo:
            return memo[(n1_id, n2_id)]

        node1 = T1.get_node(n1_id)
        node2 = T2.get_node(n2_id)

        # Base Cases:
        if node1 is None and node2 is None:
            return 0 # Both subtrees are empty, no cost

        if node1 is None:
            # Subtree 1 is empty, cost is to insert all nodes in subtree 2
            cost = 0
            q = collections.deque([n2_id])
            visited = set()
            while q:
                curr_id = q.popleft()
                if curr_id not in visited:
                    visited.add(curr_id)
                    cost += 1 # Cost for inserting this node
                    curr_node = T2.get_node(curr_id)
                    if curr_node:
                        for child_id in curr_node.children_ids:
                            q.append(child_id)
            memo[(n1_id, n2_id)] = cost
            return cost
        
        if node2 is None:
            # Subtree 2 is empty, cost is to delete all nodes in subtree 1
            cost = 0
            q = collections.deque([n1_id])
            visited = set()
            while q:
                curr_id = q.popleft()
                if curr_id not in visited:
                    visited.add(curr_id)
                    cost += 1 # Cost for deleting this node
                    curr_node = T1.get_node(curr_id)
                    if curr_node:
                        for child_id in curr_node.children_ids:
                            q.append(child_id)
            memo[(n1_id, n2_id)] = cost
            return cost

        # Main Recursive Step: Calculate minimum of three operations
        
        # 1. Relabel/Match operation: Relabel current nodes (cost 0 if same, 1 if different)
        #    Then, recursively find the edit distance between their children's forests.
        relabel_cost = 0 if node1.label == node2.label else 1

        children1_ids = node1.children_ids
        children2_ids = node2.children_ids

        # Calculate Forest Edit Distance (FED) between children sequences (another DP subproblem)
        m = len(children1_ids)
        k = len(children2_ids)
        
        dp_forest = [[0] * (k + 1) for _ in range(m + 1)] # dp_forest[i][j] for first i children of T1, first j of T2
        
        # Base cases for forest DP: cost to delete/insert remaining children in the forest
        for x in range(1, m + 1):
            dp_forest[x][0] = dp_forest[x-1][0] + calculate_distance_recursive(children1_ids[x-1], None)
        for y in range(1, k + 1):
            dp_forest[0][y] = dp_forest[0][y-1] + calculate_distance_recursive(None, children2_ids[y-1])

        # Fill the forest DP table
        for x in range(1, m + 1):
            for y in range(1, k + 1):
                child1_id = children1_ids[x-1]
                child2_id = children2_ids[y-1]
                
                # Option A: Match/Relabel current children (recursive TED call)
                cost_match_children = calculate_distance_recursive(child1_id, child2_id)
                
                dp_forest[x][y] = min(
                    dp_forest[x-1][y] + calculate_distance_recursive(child1_id, None), # Option B: Delete child1
                    dp_forest[x][y-1] + calculate_distance_recursive(None, child2_id), # Option C: Insert child2
                    dp_forest[x-1][y-1] + cost_match_children # Option A: Match/Relabel child1 to child2
                )
        
        # Total cost for the "relabel/match roots" option
        cost_match_current_roots = relabel_cost + dp_forest[m][k]
        
        # Store result in memoization table and return
        memo[(n1_id, n2_id)] = cost_match_current_roots
        return cost_match_current_roots

    # Start the recursive calculation from the roots of the input trees
    if T1.root_id is None and T2.root_id is None:
        return 0
    elif T1.root_id is None:
        return calculate_distance_recursive(None, T2.root_id)
    elif T2.root_id is None:
        return calculate_distance_recursive(T1.root_id, None)
    else:
        return calculate_distance_recursive(T1.root_id, T2.root_id)

# --- Example Usage ---
if __name__ == "__main__":
    print("--- Example Tree Edit Distance Problem (Dynamic Programming) ---")

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

    # Solve the tree edit distance problem using dynamic programming
    print("\n--- Running Dynamic Programming Algorithm ---")
    
    min_cost = tree_edit_distance_dp(T1, T2)

    print("\n--- Minimum Edit Distance Found ---")
    print(f"Minimum Cost: {min_cost}")

    # For the given example, the transformation is:
    # A -> A (match)
    # B -> X (relabel, cost 1)
    # C -> Y (relabel, cost 1)
    # D -> D (match)
    # Total minimum cost = 2