import collections

# Tree representations
class ParentArray:
    def __init__(self, n=0, root_node=-1):
        self.n = n
        self.parents = [-1] * n  # parents[v] = parent of v, -1 if root
        self.root_node = root_node # Store the root node

class FCNS:
    def __init__(self, n=0):
        self.n = n
        self.first_child = [-1] * n  # first_child[v] = first child of v, -1 if leaf
        self.next_sibling = [-1] * n # next_sibling[v] = next sibling of v, -1 if last sibling

# Graph-based representation of trees (using Extended Adjacency List, undirected edges)
# For trees, edges are implicitly directed from parent to child. However, this EAL
# treats them as undirected connections for consistency with previous graph context.
# When converting back to a tree-specific representation, the root_node is used
# to re-establish parent-child relationships via traversal.
class TreeExtendedAdjacencyList:
    def __init__(self, n=0):
        self.n = n
        self.m = 0 # number of edges
        self.incoming = [[] for _ in range(n)] # indices to edges
        self.outgoing = [[] for _ in range(n)] # indices to edges
        self.edges = [] # Stores (u, v) for each edge, where u is parent of v OR v is parent of u

# Internal representation for easier conversions between tree structures
# This stores children for each node, which is convenient for building other representations.
class TreeChildrenList:
    def __init__(self, n=0, root_node=-1):
        self.n = n
        self.children = [[] for _ in range(n)] # children[u] = list of children of u
        self.root_node = root_node # The root of the tree

# Enum for current representation
class TreeRepresentation:
    PARENT_ARRAY = 0
    FCNS_REP = 1
    TREE_EAL = 2

# Global variables to track current state
current_parent_array = ParentArray()
current_fcns = FCNS()
current_tree_eal = TreeExtendedAdjacencyList()
current_children_list_internal = TreeChildrenList() # Used internally for conversions, always kept consistent

current_tree_rep = TreeRepresentation.PARENT_ARRAY # Initialized after input parsing

# Helper function to get representation name as a string
def get_tree_rep_name(rep: int) -> str:
    if rep == TreeRepresentation.PARENT_ARRAY: return "Array of Parents"
    elif rep == TreeRepresentation.FCNS_REP: return "First-Child Next-Sibling"
    elif rep == TreeRepresentation.TREE_EAL: return "Graph-based (Extended Adjacency List)"
    else: return "Unknown"

# ========== CONVERSION FUNCTIONS ==========

# Converts a TreeChildrenList to a ParentArray.
# Iterates through children lists to determine each node's parent.
def children_list_to_parent_array(cl: TreeChildrenList) -> ParentArray:
    pa = ParentArray(cl.n, cl.root_node)
    for u in range(cl.n):
        for v in cl.children[u]:
            pa.parents[v] = u # u is the parent of v
    return pa

# Converts a ParentArray to a TreeChildrenList.
# Iterates through the parent array to build children lists.
def parent_array_to_children_list(pa: ParentArray) -> TreeChildrenList:
    cl = TreeChildrenList(pa.n, pa.root_node)
    for v in range(pa.n):
        if pa.parents[v] != -1: # If v has a parent
            cl.children[pa.parents[v]].append(v) # Add v to its parent's children list
    # Sort children lists for consistent FCNS conversion later.
    for i in range(cl.n):
        cl.children[i].sort()
    return cl

# Converts a TreeChildrenList to a First-Child Next-Sibling (FCNS) representation.
# Assumes children lists are sorted for consistent FCNS output.
def children_list_to_fcns(cl: TreeChildrenList) -> FCNS:
    fcns = FCNS(cl.n)
    for u in range(cl.n):
        if cl.children[u]: # If u has children
            # The first child of u is the first element in its sorted children list
            fcns.first_child[u] = cl.children[u][0]
            # For other children, set next_sibling pointers
            for i in range(len(cl.children[u]) - 1):
                fcns.next_sibling[cl.children[u][i]] = cl.children[u][i+1]
    return fcns

# Converts a First-Child Next-Sibling (FCNS) representation to a TreeChildrenList.
# Requires the root_node to start the traversal and reconstruct the tree structure.
def fcns_to_children_list(fcns: FCNS, root_node: int) -> TreeChildrenList:
    cl = TreeChildrenList(fcns.n, root_node)
    if cl.n == 0:
        return cl

    # Use a queue for BFS to traverse the tree and build the children list
    q = collections.deque()
    q.append(root_node)
    visited = [False] * fcns.n
    visited[root_node] = True

    while q:
        u = q.popleft()

        current_child = fcns.first_child[u]
        while current_child != -1:
            if not visited[current_child]:
                cl.children[u].append(current_child) # u is parent of current_child
                visited[current_child] = True
                q.append(current_child)
            current_child = fcns.next_sibling[current_child] # Move to the next sibling
    # Sort children lists for consistency.
    for i in range(cl.n):
        cl.children[i].sort()
    return cl

# Converts a TreeChildrenList to a TreeExtendedAdjacencyList (graph-based).
# Each parent-child relationship becomes an edge in the EAL.
# The EAL is treated as undirected for tree edges (u,v) and (v,u) point to the same edge index.
def children_list_to_tree_eal(cl: TreeChildrenList) -> TreeExtendedAdjacencyList:
    teal = TreeExtendedAdjacencyList(cl.n)

    for u in range(cl.n):
        for v in cl.children[u]:
            teal.edges.append((u, v)) # Store the edge as (parent, child)
            edge_idx = len(teal.edges) - 1

            teal.outgoing[u].append(edge_idx) # u has an outgoing edge to v
            teal.incoming[v].append(edge_idx) # v has an incoming edge from u

            # For undirected graph representation of tree edges (as per previous context):
            teal.outgoing[v].append(edge_idx) # v also has an "outgoing" connection to u
            teal.incoming[u].append(edge_idx) # u also has an "incoming" connection from v
            teal.m += 1 # Increment total edge count
    return teal

# Converts a TreeExtendedAdjacencyList (graph-based) back to a TreeChildrenList.
# Requires the root_node to start a BFS traversal to correctly identify parent-child relationships.
def tree_eal_to_children_list(teal: TreeExtendedAdjacencyList, root_node: int) -> TreeChildrenList:
    cl = TreeChildrenList(teal.n, root_node)
    if cl.n == 0:
        return cl

    # Build a temporary adjacency list from EAL for BFS traversal.
    # This handles the undirected nature of TreeExtendedAdjacencyList by creating
    # a simple adjacency list where each node points to its direct neighbors.
    temp_adj = [[] for _ in range(teal.n)]
    for u, v in teal.edges:
        temp_adj[u].append(v)
        temp_adj[v].append(u) # Undirected connection

    q = collections.deque()
    q.append(root_node)
    visited = [False] * cl.n
    visited[root_node] = True

    while q:
        u = q.popleft()

        for v in temp_adj[u]:
            if not visited[v]:
                cl.children[u].append(v) # If v is not visited, u must be its parent
                visited[v] = True
                q.append(v)
    # Sort children lists for consistency.
    for i in range(cl.n):
        cl.children[i].sort()
    return cl

# ========== DISPLAY FUNCTIONS ==========

# Displays the Array of Parents representation.
def display_parent_array(pa: ParentArray):
    print("Array of Parents:")
    print(f"Root: {pa.root_node}")
    for i in range(pa.n):
        print(f"Parent[{i}] = {pa.parents[i]}")

# Displays the First-Child Next-Sibling representation.
def display_fcns(fcns: FCNS):
    print("First-Child Next-Sibling Representation:")
    for i in range(fcns.n):
        print(f"Node {i}: ", end="")
        print(f"First Child = {fcns.first_child[i]}", end="")
        print(f", Next Sibling = {fcns.next_sibling[i]}")

# Displays the Graph-based representation (TreeExtendedAdjacencyList).
def display_tree_eal(teal: TreeExtendedAdjacencyList):
    print("Graph-based Representation (Extended Adjacency List):")
    print(f"Total Edges (m): {teal.m}")
    print("Edges (u,v) and their indices:")
    for i, (u, v) in enumerate(teal.edges):
        print(f"  Edge {i}: ({u},{v})")

    print("Outgoing edges (indices):")
    for i in range(teal.n):
        print(f"{i}: ", end="")
        for edge_idx in teal.outgoing[i]:
            print(f"{edge_idx} ", end="")
        print()

    print("Incoming edges (indices):")
    for i in range(teal.n):
        print(f"{i}: ", end="")
        for edge_idx in teal.incoming[i]:
            print(f"{edge_idx} ", end="")
        print()

# Function to display the current tree representation based on global state.
def display_current_tree_representation():
    print("\n=== CAY HIEN TAI ===")
    if current_tree_rep == TreeRepresentation.PARENT_ARRAY:
        print(" (Array of Parents)")
        display_parent_array(current_parent_array)
    elif current_tree_rep == TreeRepresentation.FCNS_REP:
        print(" (First-Child Next-Sibling)")
        display_fcns(current_fcns)
    elif current_tree_rep == TreeRepresentation.TREE_EAL:
        print(" (Graph-based (Extended Adjacency List))")
        display_tree_eal(current_tree_eal)
    print("\n")

# Function to validate if the chosen conversion is valid from the current representation.
def is_valid_tree_conversion(choice: int) -> bool:
    if choice == 1: # Display current
        return True
    elif choice == 2: # PA -> FCNS
        return current_tree_rep == TreeRepresentation.PARENT_ARRAY
    elif choice == 3: # PA -> EAL
        return current_tree_rep == TreeRepresentation.PARENT_ARRAY
    elif choice == 4: # FCNS -> PA
        return current_tree_rep == TreeRepresentation.FCNS_REP
    elif choice == 5: # FCNS -> EAL
        return current_tree_rep == TreeRepresentation.FCNS_REP
    elif choice == 6: # EAL -> PA
        return current_tree_rep == TreeRepresentation.TREE_EAL
    elif choice == 7: # EAL -> FCNS
        return current_tree_rep == TreeRepresentation.TREE_EAL
    elif choice == 8: # Exit
        return True
    else:
        return False

def main():
    global current_parent_array, current_fcns, current_tree_eal, current_children_list_internal, current_tree_rep

    print("=== CHUONG TRINH CHUYEN DOI BIEU DIEN CAY ===\n")

    try:
        n = int(input("Nhap so dinh: "))
    except ValueError:
        print("Loi: So dinh khong hop le. Vui long nhap mot so nguyen.")
        return

    current_children_list_internal = TreeChildrenList(n)

    in_degree = [0] * n # Used to find the root (node with in-degree 0)

    print("Nhap danh sach con cho tung dinh (vd: <so_con> <con_1> <con_2> ...):")
    print("Luu y: Dinh con phai nam trong khoang [0, n-1].")
    for i in range(n):
        while True:
            try:
                line_input = input(f"Dinh {i}: ").split()
                num_children = int(line_input[0])
                children_nodes = [int(x) for x in line_input[1:]]

                if len(children_nodes) != num_children:
                    print("Loi: So luong con khong khop voi so con da khai bao. Vui long nhap lai.")
                    continue

                valid_input = True
                for child_node in children_nodes:
                    if not (0 <= child_node < n):
                        print(f"Loi: Dinh con {child_node} khong hop le. Vui long nhap lai dinh con nay.")
                        valid_input = False
                        break
                    if child_node == i: # Trees do not allow self-loops
                        print("Loi: Cay khong co khuyen. Dinh con khong the la chinh no. Vui long nhap lai dinh con nay.")
                        valid_input = False
                        break
                
                if not valid_input:
                    continue # Re-ask for this node's children

                current_children_list_internal.children[i].extend(children_nodes)
                for child_node in children_nodes:
                    in_degree[child_node] += 1
                
                # Sort children for consistent FCNS conversion later.
                # This is crucial because FCNS relies on a defined order of siblings.
                current_children_list_internal.children[i].sort()
                break # Exit inner loop if input is valid
            except ValueError:
                print("Loi: Dau vao khong hop le. Vui long nhap so nguyen.")
            except IndexError:
                print("Loi: Dau vao khong du. Vui long nhap so con va cac dinh con.")

    # Find the root of the tree
    root = -1
    root_count = 0
    for i in range(n):
        if in_degree[i] == 0:
            root = i
            root_count += 1
    
    # Validate if the input forms a valid tree (exactly one root for n > 0)
    if n > 0 and root_count != 1:
        print("Loi: Do thi khong phai la cay (phai co dung mot goc).")
        return # Exit if not a valid tree
    
    current_children_list_internal.root_node = root

    # Initialize current_parent_array from the initial children list
    current_parent_array = children_list_to_parent_array(current_children_list_internal)
    current_tree_rep = TreeRepresentation.PARENT_ARRAY # Set initial representation to Array of Parents

    while True:
        print("\n=== MENU CHUYEN DOI CAY ===")
        print("1. Hien thi cay hien tai")
        print("=== CHUYEN DOI TU ARRAY OF PARENTS ===")
        print("2. Array of Parents -> First-Child Next-Sibling")
        print("3. Array of Parents -> Graph-based (Extended Adjacency List)")
        print("\n=== CHUYEN DOI TU FIRST-CHILD NEXT-SIBLING ===")
        print("4. First-Child Next-Sibling -> Array of Parents")
        print("5. First-Child Next-Sibling -> Graph-based (Extended Adjacency List)")
        print("\n=== CHUYEN DOI TU GRAPH-BASED (EXTENDED ADJACENCY LIST) ===\n")
        print("6. Graph-based (Extended Adjacency List) -> Array of Parents")
        print("7. Graph-based (Extended Adjacency List) -> First-Child Next-Sibling")
        print("\n8. Thoat")
        
        try:
            choice = int(input("Chon: "))
        except ValueError:
            print("LOI: Lua chon khong hop le! Vui long nhap mot so nguyen.")
            continue

        # Validate user's choice based on current representation
        if not is_valid_tree_conversion(choice):
            print(f"\nLOI: Khong the chuyen doi! Cay hien tai dang o dang {get_tree_rep_name(current_tree_rep)} nhung ban chon chuyen doi tu dang khac.")
            print("Vui long chon lai!\n")
            continue

        # Perform the chosen conversion
        if choice == 1:
            display_current_tree_representation()
        elif choice == 2: # PA -> FCNS
            # Convert PA to ChildrenList (internal) then to FCNS
            current_children_list_internal = parent_array_to_children_list(current_parent_array)
            current_fcns = children_list_to_fcns(current_children_list_internal)
            current_tree_rep = TreeRepresentation.FCNS_REP
            print("\nDa chuyen doi thanh cong: Array of Parents -> First-Child Next-Sibling\n")
            display_current_tree_representation()
        elif choice == 3: # PA -> EAL
            # Convert PA to ChildrenList (internal) then to EAL
            current_children_list_internal = parent_array_to_children_list(current_parent_array)
            current_tree_eal = children_list_to_tree_eal(current_children_list_internal)
            current_tree_rep = TreeRepresentation.TREE_EAL
            print("\nDa chuyen doi thanh cong: Array of Parents -> Graph-based (Extended Adjacency List)\n")
            display_current_tree_representation()
        elif choice == 4: # FCNS -> PA
            # Convert FCNS to ChildrenList (internal) then to PA
            current_children_list_internal = fcns_to_children_list(current_fcns, current_children_list_internal.root_node)
            current_parent_array = children_list_to_parent_array(current_children_list_internal)
            current_tree_rep = TreeRepresentation.PARENT_ARRAY
            print("\nDa chuyen doi thanh cong: First-Child Next-Sibling -> Array of Parents\n")
            display_current_tree_representation()
        elif choice == 5: # FCNS -> EAL
            # Convert FCNS to ChildrenList (internal) then to EAL
            current_children_list_internal = fcns_to_children_list(current_fcns, current_children_list_internal.root_node)
            current_tree_eal = children_list_to_tree_eal(current_children_list_internal)
            current_tree_rep = TreeRepresentation.TREE_EAL
            print("\nDa chuyen doi thanh cong: First-Child Next-Sibling -> Graph-based (Extended Adjacency List)\n")
            display_current_tree_representation()
        elif choice == 6: # EAL -> PA
            # Convert EAL to ChildrenList (internal) then to PA
            current_children_list_internal = tree_eal_to_children_list(current_tree_eal, current_children_list_internal.root_node)
            current_parent_array = children_list_to_parent_array(current_children_list_internal)
            current_tree_rep = TreeRepresentation.PARENT_ARRAY
            print("\nDa chuyen doi thanh cong: Graph-based (Extended Adjacency List) -> Array of Parents\n")
            display_current_tree_representation()
        elif choice == 7: # EAL -> FCNS
            # Convert EAL to ChildrenList (internal) then to FCNS
            current_children_list_internal = tree_eal_to_children_list(current_tree_eal, current_children_list_internal.root_node)
            current_fcns = children_list_to_fcns(current_children_list_internal)
            current_tree_rep = TreeRepresentation.FCNS_REP
            print("\nDa chuyen doi thanh cong: Graph-based (Extended Adjacency List) -> First-Child Next-Sibling\n")
            display_current_tree_representation()
        elif choice == 8:
            print("Tam biet!")
            break
        else:
            print("Lua chon khong hop le!")

if __name__ == "__main__":
    main()
