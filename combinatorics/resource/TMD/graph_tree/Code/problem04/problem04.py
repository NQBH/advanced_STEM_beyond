from typing import List, Tuple, Dict, Optional

# =========================================================================
# ==                      DATA STRUCTURE DEFINITIONS                     ==
# =========================================================================

# Intermediate representation: A list of tuples [(u, v, weight), ...]
EdgeList = List[Tuple[int, int, int]]

# 1. Adjacency Matrix
AdjacencyMatrix = List[List[Optional[int]]]

# 2. Adjacency List (for multigraphs/general graphs)
AdjacencyList = Dict[int, List[Tuple[int, int]]]

# 3. Adjacency Map (for simple graphs)
AdjacencyMap = Dict[int, Dict[int, int]]

# --- Tree Representations ---
# 1. Array of Parents
ArrayOfParents = List[int]

# 2. First-Child, Next-Sibling
FCNS_Representation = List[Dict[str, int]]


# =========================================================================
# ==                   GRAPH & TREE CONVERTER FUNCTIONS                  ==
# =========================================================================

# --- Graph Converters ---

def edge_list_to_adj_matrix(edge_list: EdgeList, num_nodes: int) -> AdjacencyMatrix:
    matrix = [[None] * num_nodes for _ in range(num_nodes)]
    for u, v, weight in edge_list:
        if u < num_nodes and v < num_nodes:
            matrix[u][v] = weight
    return matrix

def adj_matrix_to_edge_list(matrix: AdjacencyMatrix) -> EdgeList:
    edge_list = []
    num_nodes = len(matrix)
    for i in range(num_nodes):
        for j in range(num_nodes):
            if matrix[i][j] is not None:
                edge_list.append((i, j, matrix[i][j]))
    return edge_list

def edge_list_to_adj_list(edge_list: EdgeList, num_nodes: int) -> AdjacencyList:
    adj_list = {i: [] for i in range(num_nodes)}
    for u, v, weight in edge_list:
        if u in adj_list:
            adj_list[u].append((v, weight))
    return adj_list

def adj_list_to_edge_list(adj_list: AdjacencyList) -> EdgeList:
    edge_list = []
    for u, neighbors in adj_list.items():
        for v, weight in neighbors:
            edge_list.append((u, v, weight))
    return edge_list

def edge_list_to_adj_map(edge_list: EdgeList) -> AdjacencyMap:
    adj_map = {}
    for u, v, weight in edge_list:
        if u not in adj_map:
            adj_map[u] = {}
        adj_map[u][v] = weight
    return adj_map
    
def adj_map_to_edge_list(adj_map: AdjacencyMap) -> EdgeList:
    edge_list = []
    for u, neighbors in adj_map.items():
        for v, weight in neighbors.items():
            edge_list.append((u, v, weight))
    return edge_list

# --- Tree Converters ---

def array_of_parents_to_tree_edges(parents: ArrayOfParents) -> Tuple[EdgeList, int]:
    edges = []
    root = -1
    for i, p in enumerate(parents):
        if p != -1:
            edges.append((p, i, 1))  # Assuming unweighted tree
        else:
            root = i
    return edges, root

def tree_edges_to_array_of_parents(edges: EdgeList, num_nodes: int) -> ArrayOfParents:
    parents = [-1] * num_nodes
    for p, c, _ in edges:
        parents[c] = p
    return parents

def tree_edges_to_fcns(edges: EdgeList, num_nodes: int) -> FCNS_Representation:
    children_list = [[] for _ in range(num_nodes)]
    for p, c, _ in edges:
        children_list[p].append(c)

    fcns = [{'first_child': -1, 'next_sibling': -1} for _ in range(num_nodes)]
    for i in range(num_nodes):
        if children_list[i]:
            fcns[i]['first_child'] = children_list[i][0]
            for j in range(len(children_list[i]) - 1):
                current_child = children_list[i][j]
                next_child = children_list[i][j + 1]
                fcns[current_child]['next_sibling'] = next_child
    return fcns

def fcns_to_tree_edges(fcns: FCNS_Representation) -> Tuple[EdgeList, int]:
    edges = []
    num_nodes = len(fcns)
    is_child = [False] * num_nodes
    for parent_idx, node_data in enumerate(fcns):
        child = node_data['first_child']
        while child != -1:
            edges.append((parent_idx, child, 1))
            if 0 <= child < num_nodes:
                is_child[child] = True
            child = fcns[child]['next_sibling']
    
    root = -1
    for i in range(num_nodes):
        if not is_child[i]:
            root = i
            break
            
    return edges, root

# =========================================================================
# ==                           HELPER PRINTERS                           ==
# =========================================================================

def print_edge_list(name: str, edges: EdgeList):
    print(f"{name}: {sorted(edges)}")

def print_matrix(name: str, matrix: AdjacencyMatrix):
    print(f"{name}:")
    for row in matrix:
        print(f"  {[str(v) if v is not None else 'N' for v in row]}")

def print_adj_list(name: str, adj_list: AdjacencyList):
    print(f"{name}:")
    for u, neighbors in sorted(adj_list.items()):
        print(f"  {u}: {neighbors}")
        
def print_adj_map(name: str, adj_map: AdjacencyMap):
    print(f"{name}:")
    for u, neighbors in sorted(adj_map.items()):
        print(f"  {u}: {neighbors}")

# =========================================================================
# ==                            MAIN FUNCTION                            ==
# =========================================================================

if __name__ == "__main__":
    # --- GRAPH DEMO ---
    num_graph_nodes = 4
    graph_edges = [(0, 1, 5), (0, 2, 3), (1, 2, 2), (1, 3, 6), (2, 3, 1)]

    print("=" * 60)
    print("       GRAPH CONVERTER DEMONSTRATION (Problem 4)        ")
    print("=" * 60)
    
    print_edge_list("Original Edge List", graph_edges)
    
    print("\n--- Testing Matrix Conversions ---")
    matrix = edge_list_to_adj_matrix(graph_edges, num_graph_nodes)
    print_matrix("To Adjacency Matrix", matrix)
    edges_from_matrix = adj_matrix_to_edge_list(matrix)
    print_edge_list("Back to Edge List", edges_from_matrix)

    print("\n--- Testing Adjacency List Conversions ---")
    adj_list = edge_list_to_adj_list(graph_edges, num_graph_nodes)
    print_adj_list("To Adjacency List", adj_list)
    edges_from_adj_list = adj_list_to_edge_list(adj_list)
    print_edge_list("Back to Edge List", edges_from_adj_list)
    
    print("\n--- Testing Adjacency Map Conversions ---")
    adj_map = edge_list_to_adj_map(graph_edges)
    print_adj_map("To Adjacency Map", adj_map)
    edges_from_adj_map = adj_map_to_edge_list(adj_map)
    print_edge_list("Back to Edge List", edges_from_adj_map)

    # --- TREE DEMO ---
    num_tree_nodes = 7
    # 0 is root, 1 and 2 are its children, 3 and 4 are children of 1, etc.
    parents_array = [-1, 0, 0, 1, 1, 2, 2]

    print("\n" + "=" * 60)
    print("        TREE CONVERTER DEMONSTRATION (Problem 4)        ")
    print("=" * 60)
    
    print(f"Original Array of Parents: {parents_array}")

    print("\n--- Testing Array of Parents <-> Edge List ---")
    tree_edges, root = array_of_parents_to_tree_edges(parents_array)
    print_edge_list("To Edge List", tree_edges)
    print(f"Detected Root: {root}")
    parents_from_edges = tree_edges_to_array_of_parents(tree_edges, num_tree_nodes)
    print(f"Back to Array of Parents: {parents_from_edges}")

    print("\n--- Testing Edge List -> FCNS ---")
    fcns_repr = tree_edges_to_fcns(tree_edges, num_tree_nodes)
    print("To First-Child Next-Sibling Representation:")
    for i, node in enumerate(fcns_repr):
        print(f"  Node {i}: {node}")

    print("\n--- Testing FCNS -> Edge List ---")
    edges_from_fcns, root_from_fcns = fcns_to_tree_edges(fcns_repr)
    print_edge_list("Back to Edge List", edges_from_fcns)
    print(f"Detected Root: {root_from_fcns}")
    
    print("\n" + "=" * 60)