import math

# Graph representations
class AdjacencyMatrix:
    def __init__(self, n=0):
        self.n = n
        self.matrix = [[0 for _ in range(n)] for _ in range(n)] # Stores count of edges

class AdjacencyList:
    def __init__(self, n=0):
        self.n = n
        self.adj = [[] for _ in range(n)]

class ExtendedAdjacencyList:
    def __init__(self, n=0):
        self.n = n
        self.m = 0 # Total number of edge instances
        self.incoming = [[] for _ in range(n)] # Stores indices to 'edges'
        self.outgoing = [[] for _ in range(n)] # Stores indices to 'edges'
        self.edges = [] # Stores all individual edge instances (u,v)

class AdjacencyMap:
    def __init__(self, n=0):
        self.n = n
        self.m = 0 # Total number of edge instances
        # For each vertex 'u', stores a list of tuples: (neighbor_v, (canonical_u, canonical_v))
        self.outgoing = {i: [] for i in range(n)}
        self.incoming = {i: [] for i in range(n)}

# Enum for current representation
class Representation:
    ADJ_LIST = 0
    ADJ_MATRIX = 1
    EXT_ADJ_LIST = 2
    ADJ_MAP = 3

# Global variables to track current state
current_list = AdjacencyList()
current_matrix = AdjacencyMatrix()
current_extended = ExtendedAdjacencyList()
current_map = AdjacencyMap()
current_rep = Representation.ADJ_LIST

# ========== ALL 12 CONVERSION FUNCTIONS FOR MULTIGRAPH (NO LOOPS) ==========

# 1. Adjacency List ↔ Adjacency Matrix
# Converts an AdjacencyList representation to an AdjacencyMatrix.
# For multigraphs, the matrix cells store the count of edges between vertices.
def list_to_matrix(adj_list: AdjacencyList) -> AdjacencyMatrix:
    matrix = AdjacencyMatrix(adj_list.n)
    for i in range(adj_list.n):
        for j in adj_list.adj[i]:
            matrix.matrix[i][j] += 1
    return matrix

# Converts an AdjacencyMatrix representation to an AdjacencyList.
# For multigraphs, if matrix[i][j] is k, then 'j' is added k times to list.adj[i].
def matrix_to_list(matrix: AdjacencyMatrix) -> AdjacencyList:
    adj_list = AdjacencyList(matrix.n)
    for i in range(matrix.n):
        for j in range(matrix.n):
            for _ in range(matrix.matrix[i][j]):
                adj_list.adj[i].append(j)
    return adj_list

# 2. Adjacency Matrix ↔ Extended Adjacency List
# Converts an AdjacencyMatrix to an ExtendedAdjacencyList.
# Each edge instance (based on count in matrix) is added to ext.edges.
def matrix_to_extended(matrix: AdjacencyMatrix) -> ExtendedAdjacencyList:
    ext = ExtendedAdjacencyList(matrix.n)
    for i in range(matrix.n):
        for j in range(matrix.n):
            # For undirected multigraphs, we only process (i,j) where i <= j
            # to avoid double-counting the same undirected edge instance when adding to ext.edges.
            # Self-loops (i,i) are not allowed in multigraphs (no loops), so we skip them.
            if i < j: # Only process if i < j to avoid loops and double counting
                edge_count = matrix.matrix[i][j]
                for _ in range(edge_count):
                    ext.edges.append((i, j)) # Add the edge instance
                    edge_idx = len(ext.edges) - 1 # Index of the newly added edge

                    ext.outgoing[i].append(edge_idx)
                    ext.incoming[j].append(edge_idx)

                    ext.outgoing[j].append(edge_idx) # Add reverse connection
                    ext.incoming[i].append(edge_idx)
                    ext.m += 1 # Increment total edge count for each instance
            elif i == j and matrix.matrix[i][j] > 0:
                # This case should ideally not be hit if input validation is strict,
                # but as a safeguard, if a loop somehow exists, we ignore it for multigraph (no loops)
                pass
    return ext

# Converts an ExtendedAdjacencyList representation to an AdjacencyMatrix.
# Each edge in ext.edges increments the corresponding matrix cell.
def extended_to_matrix(ext: ExtendedAdjacencyList) -> AdjacencyMatrix:
    matrix = AdjacencyMatrix(ext.n)
    for u, v in ext.edges:
        matrix.matrix[u][v] += 1
        if u != v: # For undirected graph, also increment the reverse for non-loops
            matrix.matrix[v][u] += 1
    return matrix

# 3. Adjacency Matrix ↔ Adjacency Map
# Converts an AdjacencyMatrix to an AdjacencyMap.
# The map stores the canonical edge tuple for each connection.
def matrix_to_map(matrix: AdjacencyMatrix) -> AdjacencyMap:
    adj_map = AdjacencyMap(matrix.n)
    for i in range(matrix.n):
        for j in range(matrix.n):
            if i == j: # Skip loops for multigraph (no loops)
                continue
            edge_count = matrix.matrix[i][j]
            if edge_count > 0:
                canonical_edge = (min(i, j), max(i, j))
                for _ in range(edge_count):
                    adj_map.outgoing[i].append((j, canonical_edge))
                    adj_map.incoming[j].append((i, canonical_edge)) # For undirected graph
    # Count m: Sum up the sizes of all vectors in outgoing and divide by 2.
    # This correctly counts non-loop edges.
    for entry in adj_map.outgoing.values():
        adj_map.m += len(entry)
    adj_map.m //= 2
    return adj_map

# Converts an AdjacencyMap to an AdjacencyMatrix.
# The matrix cells are populated with counts based on the map's stored edge instances.
def map_to_matrix(adj_map: AdjacencyMap) -> AdjacencyMatrix:
    matrix = AdjacencyMatrix(adj_map.n)
    for u, edge_infos in adj_map.outgoing.items():
        for v, _ in edge_infos:
            matrix.matrix[u][v] += 1
    return matrix

# 4. Adjacency List ↔ Extended Adjacency List
# Converts an AdjacencyList to an ExtendedAdjacencyList.
# Uses a temporary map to count undirected edge multiplicities (canonical form: u,v) before populating ext.edges.
def list_to_extended(adj_list: AdjacencyList) -> ExtendedAdjacencyList:
    ext = ExtendedAdjacencyList(adj_list.n)
    
    # Use a dictionary to count the multiplicity of each canonical edge (u,v)
    edge_multiplicity = {}

    for i in range(adj_list.n):
        for j in adj_list.adj[i]:
            if i == j: # Skip loops for multigraph (no loops)
                continue
            canonical_edge = tuple(sorted((i, j))) # Ensure canonical form (min, max)
            edge_multiplicity[canonical_edge] = edge_multiplicity.get(canonical_edge, 0) + 1

    # Populate ext.edges and incoming/outgoing lists based on counted multiplicities
    for (u, v), count_in_adj_list_sum in edge_multiplicity.items():
        # For non-loop edge (u,v), it appears in adj[u] and adj[v], so divide by 2
        actual_edge_count = count_in_adj_list_sum // 2

        for _ in range(actual_edge_count):
            ext.edges.append((u, v)) # Add the undirected edge instance
            edge_idx = len(ext.edges) - 1 # Index of the newly added edge

            ext.outgoing[u].append(edge_idx)
            ext.incoming[v].append(edge_idx)

            ext.outgoing[v].append(edge_idx) # Add reverse for non-loops
            ext.incoming[u].append(edge_idx)
            ext.m += 1 # Increment total edge count for each instance
    return ext

# Converts an ExtendedAdjacencyList to an AdjacencyList.
# Each edge in ext.edges is added to the adjacency list.
def extended_to_list(ext: ExtendedAdjacencyList) -> AdjacencyList:
    adj_list = AdjacencyList(ext.n)
    for u, v in ext.edges:
        adj_list.adj[u].append(v)
        if u != v: # For undirected graph, add reverse if not self-loop (which is not allowed anyway)
            adj_list.adj[v].append(u)
    return adj_list

# 5. Adjacency List ↔ Adjacency Map
# Converts an AdjacencyList to an AdjacencyMap.
# Populates the map with neighbor and canonical edge tuple for each connection.
def list_to_map(adj_list: AdjacencyList) -> AdjacencyMap:
    adj_map = AdjacencyMap(adj_list.n)
    for i in range(adj_list.n):
        for j in adj_list.adj[i]:
            if i == j: # Skip loops for multigraph (no loops)
                continue
            # Create canonical edge tuple (min, max)
            canonical_edge = (min(i, j), max(i, j))

            adj_map.outgoing[i].append((j, canonical_edge))
            adj_map.incoming[j].append((i, canonical_edge)) # For undirected graph
    # Count m: Sum up the sizes of all lists in outgoing and divide by 2.
    # This correctly counts non-loop edges.
    for entry in adj_map.outgoing.values():
        adj_map.m += len(entry)
    adj_map.m //= 2
    return adj_map

# Converts an AdjacencyMap to an AdjacencyList.
# Each edge (u,v) in the map results in 'v' being added to list.adj[u].
def map_to_list(adj_map: AdjacencyMap) -> AdjacencyList:
    adj_list = AdjacencyList(adj_map.n)
    for u, edge_infos in adj_map.outgoing.items():
        for v, _ in edge_infos:
            adj_list.adj[u].append(v)
    return adj_list

# 6. Extended Adjacency List ↔ Adjacency Map
# Converts an ExtendedAdjacencyList to an AdjacencyMap.
# Populates the map with neighbor and canonical edge tuple for each connection.
def extended_to_map(ext: ExtendedAdjacencyList) -> AdjacencyMap:
    adj_map = AdjacencyMap(ext.n)
    adj_map.m = ext.m # m is already correctly counted in ExtendedAdjacencyList

    for u, v in ext.edges:
        # Ensure no loops are processed if they somehow got into ext.edges
        if u == v:
            continue
        canonical_edge = (min(u, v), max(u, v))
        adj_map.outgoing[u].append((v, canonical_edge))
        adj_map.incoming[v].append((u, canonical_edge)) # For undirected graph
    return adj_map

# Converts an AdjacencyMap to an ExtendedAdjacencyList.
# Expands the map's stored edge instances into ext.edges.
def map_to_extended(adj_map: AdjacencyMap) -> ExtendedAdjacencyList:
    ext = ExtendedAdjacencyList(adj_map.n)
    
    # Use a temporary dictionary to count occurrences of each canonical edge (u,v)
    canonical_edge_counts = {}

    for vertex_pair_list in adj_map.outgoing.values():
        for _, canonical_edge in vertex_pair_list:
            canonical_edge_counts[canonical_edge] = canonical_edge_counts.get(canonical_edge, 0) + 1

    # Now, populate ext.edges and incoming/outgoing lists
    for (u_canonical, v_canonical), count_in_map_outgoing_sum in canonical_edge_counts.items():
        # For multigraph (no loops), u_canonical == v_canonical should not happen
        # as loops are excluded from the map.
        actual_edge_count = count_in_map_outgoing_sum // 2

        for _ in range(actual_edge_count):
            ext.edges.append((u_canonical, v_canonical))
            edge_idx = len(ext.edges) - 1

            ext.outgoing[u_canonical].append(edge_idx)
            ext.incoming[v_canonical].append(edge_idx)

            ext.outgoing[v_canonical].append(edge_idx)
            ext.incoming[u_canonical].append(edge_idx)
            ext.m += 1
    return ext

# Display functions
def display_matrix(matrix: AdjacencyMatrix):
    print("Adjacency Matrix:")
    print("   ", end="")
    for i in range(matrix.n):
        print(f"{i} ", end="")
    print()

    for i in range(matrix.n):
        print(f"{i}  ", end="")
        for j in range(matrix.n):
            print(f"{matrix.matrix[i][j]} ", end="")
        print()

def display_list(adj_list: AdjacencyList):
    print("Adjacency List:")
    for i in range(adj_list.n):
        print(f"{i}: ", end="")
        for j in adj_list.adj[i]:
            print(f"{j} ", end="")
        print()

def display_extended(ext: ExtendedAdjacencyList):
    print("Extended Adjacency List:")
    print(f"Total Edges (m): {ext.m}")
    print("Edges (u,v) and their indices:")
    for i, (u, v) in enumerate(ext.edges):
        print(f"  Edge {i}: ({u},{v})")

    print("Outgoing edges (indices):")
    for i in range(ext.n):
        print(f"{i}: ", end="")
        for edge_idx in ext.outgoing[i]:
            print(f"{edge_idx} ", end="")
        print()

    print("Incoming edges (indices):")
    for i in range(ext.n):
        print(f"{i}: ", end="")
        for edge_idx in ext.incoming[i]:
            print(f"{edge_idx} ", end="")
        print()

def display_map(adj_map: AdjacencyMap):
    print("Adjacency Map:")
    print(f"Total Edges (m): {adj_map.m}")
    print("Outgoing mappings:")
    for i in range(adj_map.n):
        print(f"{i}: ", end="")
        if i in adj_map.outgoing:
            # Sorting for consistent output, optional but good for readability
            sorted_edges = sorted(adj_map.outgoing[i], key=lambda x: (x[0], x[1][0], x[1][1]))
            for neighbor, canonical_edge in sorted_edges:
                print(f"({neighbor}->{canonical_edge[0]},{canonical_edge[1]}) ", end="")
        print()

    print("Incoming mappings:")
    for i in range(adj_map.n):
        print(f"{i}: ", end="")
        if i in adj_map.incoming:
            # Sorting for consistent output, optional but good for readability
            sorted_edges = sorted(adj_map.incoming[i], key=lambda x: (x[0], x[1][0], x[1][1]))
            for neighbor, canonical_edge in sorted_edges:
                print(f"({neighbor}->{canonical_edge[0]},{canonical_edge[1]}) ", end="")
        print()

# Function to display current representation
def display_current_representation():
    print("\n=== ĐỒ THỊ HIỆN TẠI ===")
    if current_rep == Representation.ADJ_LIST:
        print(" (Adjacency List)")
        display_list(current_list)
    elif current_rep == Representation.ADJ_MATRIX:
        print(" (Adjacency Matrix)")
        display_matrix(current_matrix)
    elif current_rep == Representation.EXT_ADJ_LIST:
        print(" (Extended Adjacency List)")
        display_extended(current_extended)
    elif current_rep == Representation.ADJ_MAP:
        print(" (Adjacency Map)")
        display_map(current_map)
    print("\n")

# Function to validate conversion choice
def is_valid_conversion(choice: int) -> bool:
    if choice == 1: # Display current
        return True
    elif choice == 2: # AL -> AM
        return current_rep == Representation.ADJ_LIST
    elif choice == 3: # AL -> EAL
        return current_rep == Representation.ADJ_LIST
    elif choice == 4: # AL -> AMap
        return current_rep == Representation.ADJ_LIST
    elif choice == 5: # AM -> AL
        return current_rep == Representation.ADJ_MATRIX
    elif choice == 6: # AM -> EAL
        return current_rep == Representation.ADJ_MATRIX
    elif choice == 7: # AM -> AMap
        return current_rep == Representation.ADJ_MATRIX
    elif choice == 8: # EAL -> AL
        return current_rep == Representation.EXT_ADJ_LIST
    elif choice == 9: # EAL -> AM
        return current_rep == Representation.EXT_ADJ_LIST
    elif choice == 10: # EAL -> AMap
        return current_rep == Representation.EXT_ADJ_LIST
    elif choice == 11: # AMap -> AL
        return current_rep == Representation.ADJ_MAP
    elif choice == 12: # AMap -> AM
        return current_rep == Representation.ADJ_MAP
    elif choice == 13: # AMap -> EAL
        return current_rep == Representation.ADJ_MAP
    elif choice == 14: # Exit
        return True
    else:
        return False

# Function to get representation name
def get_rep_name(rep: int) -> str:
    if rep == Representation.ADJ_LIST: return "Adjacency List"
    elif rep == Representation.ADJ_MATRIX: return "Adjacency Matrix"
    elif rep == Representation.EXT_ADJ_LIST: return "Extended Adjacency List"
    elif rep == Representation.ADJ_MAP: return "Adjacency Map"
    else: return "Unknown"

def main():
    global current_list, current_matrix, current_extended, current_map, current_rep

    print("=== CHƯƠNG TRÌNH CHUYỂN ĐỔI BIỂU DIỄN ĐA ĐỒ THỊ (KHÔNG CÓ KHUYÊN) ===\n")

    n = int(input("Nhập số đỉnh: "))
    m_input = int(input("Nhập số cạnh: "))

    current_list = AdjacencyList(n)

    print(f"Nhập {m_input} cạnh (đỉnh đầu đỉnh cuối):")
    i = 0
    while i < m_input:
        try:
            u, v = map(int, input().split())
            if not (0 <= u < n and 0 <= v < n):
                print(f"Cạnh ({u},{v}) không hợp lệ. Đỉnh phải nằm trong khoảng [0, {n-1}]. Bỏ qua cạnh này.")
                continue # Re-ask for this edge
            
            if u == v: # Loops are NOT allowed for multigraphs (no loops)
                print(f"Cạnh ({u},{v}) là một khuyên. Đồ thị đa bộ không cho phép khuyên. Bỏ qua cạnh này.")
                continue # Re-ask for this edge

            current_list.adj[u].append(v)
            current_list.adj[v].append(u) # Undirected graph
            i += 1
        except ValueError:
            print("Đầu vào không hợp lệ. Vui lòng nhập hai số nguyên cách nhau bằng dấu cách.")
            continue

    while True:
        print("\n=== MENU CHUYỂN ĐỔI ===")
        print("1. Hiển thị đồ thị hiện tại")
        print("=== ADJACENCY LIST CONVERSIONS ===")
        print("2. AL -> Adjacency Matrix")
        print("3. AL -> Extended Adjacency List")
        print("4. AL -> Adjacency Map")
        print("\n=== ADJACENCY MATRIX CONVERSIONS ===")
        print("5. AM -> Adjacency List")
        print("6. AM -> Extended Adjacency List")
        print("7. AM -> Adjacency Map")
        print("\n=== EXTENDED ADJACENCY LIST CONVERSIONS ===")
        print("8. EAL -> Adjacency List")
        print("9. EAL -> Adjacency Matrix")
        print("10. EAL -> Adjacency Map")
        print("\n=== ADJACENCY MAP CONVERSIONS ===")
        print("11. AMap -> Adjacency List")
        print("12. AMap -> Adjacency Matrix")
        print("13. AMap -> Extended Adjacency List")
        print("\n14. Thoát")
        
        try:
            choice = int(input("Chọn: "))
        except ValueError:
            print("LỖI: Lựa chọn không hợp lệ! Vui lòng nhập một số nguyên.")
            continue

        if not is_valid_conversion(choice):
            print(f"\nLỖI: Không thể chuyển đổi! Đồ thị hiện tại đang ở dạng {get_rep_name(current_rep)} nhưng bạn chọn chuyển đổi từ dạng khác.")
            print("Vui lòng chọn lại!\n")
            continue

        if choice == 1:
            display_current_representation()
        elif choice == 2:
            current_matrix = list_to_matrix(current_list)
            current_rep = Representation.ADJ_MATRIX
            print("\nĐã chuyển đổi thành công: Adjacency List -> Adjacency Matrix\n")
            display_current_representation()
        elif choice == 3:
            current_extended = list_to_extended(current_list)
            current_rep = Representation.EXT_ADJ_LIST
            print("\nĐã chuyển đổi thành công: Adjacency List -> Extended Adjacency List\n")
            display_current_representation()
        elif choice == 4:
            current_map = list_to_map(current_list)
            current_rep = Representation.ADJ_MAP
            print("\nĐã chuyển đổi thành công: Adjacency List -> Adjacency Map\n")
            display_current_representation()
        elif choice == 5:
            current_list = matrix_to_list(current_matrix)
            current_rep = Representation.ADJ_LIST
            print("\nĐã chuyển đổi thành công: Adjacency Matrix -> Adjacency List\n")
            display_current_representation()
        elif choice == 6:
            current_extended = matrix_to_extended(current_matrix)
            current_rep = Representation.EXT_ADJ_LIST
            print("\nĐã chuyển đổi thành công: Adjacency Matrix -> Extended Adjacency List\n")
            display_current_representation()
        elif choice == 7:
            current_map = matrix_to_map(current_matrix)
            current_rep = Representation.ADJ_MAP
            print("\nĐã chuyển đổi thành công: Adjacency Matrix -> Adjacency Map\n")
            display_current_representation()
        elif choice == 8:
            current_list = extended_to_list(current_extended)
            current_rep = Representation.ADJ_LIST
            print("\nĐã chuyển đổi thành công: Extended Adjacency List -> Adjacency List\n")
            display_current_representation()
        elif choice == 9:
            current_matrix = extended_to_matrix(current_extended)
            current_rep = Representation.ADJ_MATRIX
            print("\nĐã chuyển đổi thành công: Extended Adjacency List -> Adjacency Matrix\n")
            display_current_representation()
        elif choice == 10:
            current_map = extended_to_map(current_extended)
            current_rep = Representation.ADJ_MAP
            print("\nĐã chuyển đổi thành công: Extended Adjacency List -> Adjacency Map\n")
            display_current_representation()
        elif choice == 11:
            current_list = map_to_list(current_map)
            current_rep = Representation.ADJ_LIST
            print("\nĐã chuyển đổi thành công: Adjacency Map -> Adjacency List\n")
            display_current_representation()
        elif choice == 12:
            current_matrix = map_to_matrix(current_map)
            current_rep = Representation.ADJ_MATRIX
            print("\nĐã chuyển đổi thành công: Adjacency Map -> Adjacency Matrix\n")
            display_current_representation()
        elif choice == 13:
            current_extended = map_to_extended(current_map)
            current_rep = Representation.ADJ_MAP
            print("\nĐã chuyển đổi thành công: Adjacency Map -> Extended Adjacency List\n")
            display_current_representation()
        elif choice == 14:
            print("Tạm biệt!")
            break
        else:
            print("Lựa chọn không hợp lệ!")

if __name__ == "__main__":
    main()
