from typing import List, Dict, Tuple, Set
from collections import defaultdict
from enum import Enum

class Representation(Enum):
    ADJ_LIST = "Adjacency List"
    ADJ_MATRIX = "Adjacency Matrix"
    EXT_ADJ_LIST = "Extended Adjacency List"
    ADJ_MAP = "Adjacency Map"

class AdjacencyMatrix:
    def __init__(self, n: int):
        self.n = n
        self.matrix = [[False] * n for _ in range(n)]
    
    def add_edge(self, u: int, v: int):
        self.matrix[u][v] = True
        self.matrix[v][u] = True  # Undirected graph
    
    def display(self):
        print("Adjacency Matrix:")
        print("  ", end="")
        for i in range(self.n):
            print(f"{i} ", end="")
        print()
        
        for i in range(self.n):
            print(f"{i} ", end="")
            for j in range(self.n):
                print("1 " if self.matrix[i][j] else "0 ", end="")
            print()

class AdjacencyList:
    def __init__(self, n: int):
        self.n = n
        self.adj = [[] for _ in range(n)]
    
    def add_edge(self, u: int, v: int):
        self.adj[u].append(v)
        self.adj[v].append(u)  # Undirected graph
    
    def display(self):
        print("Adjacency List:")
        for i in range(self.n):
            print(f"{i}: {' '.join(map(str, self.adj[i]))}")

class ExtendedAdjacencyList:
    def __init__(self, n: int):
        self.n = n
        self.incoming = [[] for _ in range(n)]
        self.outgoing = [[] for _ in range(n)]
        self.edges = []
        self.m = 0
    
    def display(self):
        print("Extended Adjacency List:")
        print("Edges:", end=" ")
        for i, (u, v) in enumerate(self.edges):
            print(f"({u},{v})", end=" ")
        print()
        
        print("Outgoing edges:")
        for i in range(self.n):
            print(f"{i}: {' '.join(map(str, self.outgoing[i]))}")
        
        print("Incoming edges:")
        for i in range(self.n):
            print(f"{i}: {' '.join(map(str, self.incoming[i]))}")

class AdjacencyMap:
    def __init__(self, n: int):
        self.n = n
        self.incoming = defaultdict(dict)
        self.outgoing = defaultdict(dict)
        self.m = 0
    
    def display(self):
        print("Adjacency Map:")
        print("Outgoing mappings:")
        for i in range(self.n):
            print(f"{i}:", end=" ")
            if i in self.outgoing:
                for target, edge in self.outgoing[i].items():
                    print(f"({target}->{edge[0]},{edge[1]})", end=" ")
            print()
        
        print("Incoming mappings:")
        for i in range(self.n):
            print(f"{i}:", end=" ")
            if i in self.incoming:
                for source, edge in self.incoming[i].items():
                    print(f"({source}->{edge[0]},{edge[1]})", end=" ")
            print()

# Global variables to track current state
current_list = None
current_matrix = None
current_extended = None
current_map = None
current_rep = Representation.ADJ_LIST

# ========== ALL 12 CONVERSION FUNCTIONS ==========

# 1. Adjacency List ↔ Adjacency Matrix
def list_to_matrix(adj_list: AdjacencyList) -> AdjacencyMatrix:
    """Chuyển đổi từ Adjacency List sang Adjacency Matrix"""
    matrix = AdjacencyMatrix(adj_list.n)
    
    for i in range(adj_list.n):
        for j in adj_list.adj[i]:
            matrix.matrix[i][j] = True
    
    return matrix

def matrix_to_list(matrix: AdjacencyMatrix) -> AdjacencyList:
    """Chuyển đổi từ Adjacency Matrix sang Adjacency List"""
    adj_list = AdjacencyList(matrix.n)
    
    for i in range(matrix.n):
        for j in range(matrix.n):
            if matrix.matrix[i][j]:
                adj_list.adj[i].append(j)
    
    return adj_list

# 2. Adjacency Matrix ↔ Extended Adjacency List
def matrix_to_extended(matrix: AdjacencyMatrix) -> ExtendedAdjacencyList:
    """Chuyển đổi từ Adjacency Matrix sang Extended Adjacency List"""
    ext = ExtendedAdjacencyList(matrix.n)
    
    # Thu thập tất cả các cạnh
    for i in range(matrix.n):
        for j in range(matrix.n):
            if matrix.matrix[i][j] and i <= j:  # Tránh trùng lặp
                ext.edges.append((i, j))
    
    ext.m = len(ext.edges)
    
    # Xây dựng danh sách incoming và outgoing
    for edge_idx, (u, v) in enumerate(ext.edges):
        ext.outgoing[u].append(edge_idx)
        ext.incoming[v].append(edge_idx)
        
        if u != v:  # Nếu không phải self-loop
            ext.outgoing[v].append(edge_idx)
            ext.incoming[u].append(edge_idx)
    
    return ext

def extended_to_matrix(ext: ExtendedAdjacencyList) -> AdjacencyMatrix:
    """Chuyển đổi từ Extended Adjacency List sang Adjacency Matrix"""
    matrix = AdjacencyMatrix(ext.n)
    
    for u, v in ext.edges:
        matrix.matrix[u][v] = True
        matrix.matrix[v][u] = True  # Đồ thị vô hướng
    
    return matrix

# 3. Adjacency Matrix ↔ Adjacency Map
def matrix_to_map(matrix: AdjacencyMatrix) -> AdjacencyMap:
    """Chuyển đổi từ Adjacency Matrix sang Adjacency Map"""
    adj_map = AdjacencyMap(matrix.n)
    
    for i in range(matrix.n):
        for j in range(matrix.n):
            if matrix.matrix[i][j] and i <= j:  # Tránh trùng lặp
                edge = (i, j)
                adj_map.outgoing[i][j] = edge
                adj_map.incoming[j][i] = edge
                
                if i != j:
                    adj_map.outgoing[j][i] = edge
                    adj_map.incoming[i][j] = edge
    
    # Đếm số cạnh
    edge_count = 0
    for i in range(matrix.n):
        for j in range(matrix.n):
            if matrix.matrix[i][j] and i <= j:
                edge_count += 1
    adj_map.m = edge_count
    
    return adj_map

def map_to_matrix(adj_map: AdjacencyMap) -> AdjacencyMatrix:
    """Chuyển đổi từ Adjacency Map sang Adjacency Matrix"""
    matrix = AdjacencyMatrix(adj_map.n)
    
    for u in adj_map.outgoing:
        for v in adj_map.outgoing[u]:
            matrix.matrix[u][v] = True
            matrix.matrix[v][u] = True  # Đồ thị vô hướng
    
    return matrix

# 4. Adjacency List ↔ Extended Adjacency List
def list_to_extended(adj_list: AdjacencyList) -> ExtendedAdjacencyList:
    """Chuyển đổi từ Adjacency List sang Extended Adjacency List"""
    ext = ExtendedAdjacencyList(adj_list.n)
    
    # Thu thập tất cả các cạnh (tránh trùng lặp cho đồ thị vô hướng)
    edges_set = set()
    for i in range(adj_list.n):
        for j in adj_list.adj[i]:
            if i <= j:  # Chỉ lấy một chiều để tránh trùng lặp
                edges_set.add((i, j))
    
    ext.edges = list(edges_set)
    ext.m = len(ext.edges)
    
    # Xây dựng danh sách incoming và outgoing
    for edge_idx, (u, v) in enumerate(ext.edges):
        ext.outgoing[u].append(edge_idx)
        ext.incoming[v].append(edge_idx)
        
        if u != v:  # Nếu không phải self-loop
            ext.outgoing[v].append(edge_idx)
            ext.incoming[u].append(edge_idx)
    
    return ext

def extended_to_list(ext: ExtendedAdjacencyList) -> AdjacencyList:
    """Chuyển đổi từ Extended Adjacency List sang Adjacency List"""
    adj_list = AdjacencyList(ext.n)
    
    for u, v in ext.edges:
        adj_list.adj[u].append(v)
        adj_list.adj[v].append(u)  # Đồ thị vô hướng
    
    return adj_list

# 5. Adjacency List ↔ Adjacency Map
def list_to_map(adj_list: AdjacencyList) -> AdjacencyMap:
    """Chuyển đổi từ Adjacency List sang Adjacency Map"""
    adj_map = AdjacencyMap(adj_list.n)
    
    for i in range(adj_list.n):
        for j in adj_list.adj[i]:
            if i <= j:  # Tránh trùng lặp cho đồ thị vô hướng
                edge = (i, j)
                adj_map.outgoing[i][j] = edge
                adj_map.incoming[j][i] = edge
                
                if i != j:
                    adj_map.outgoing[j][i] = edge
                    adj_map.incoming[i][j] = edge
    
    # Đếm số cạnh
    edge_count = 0
    for i in range(adj_list.n):
        for j in adj_list.adj[i]:
            if i <= j:
                edge_count += 1
    adj_map.m = edge_count
    
    return adj_map

def map_to_list(adj_map: AdjacencyMap) -> AdjacencyList:
    """Chuyển đổi từ Adjacency Map sang Adjacency List"""
    adj_list = AdjacencyList(adj_map.n)
    
    for u in adj_map.outgoing:
        for v in adj_map.outgoing[u]:
            adj_list.adj[u].append(v)
    
    return adj_list

# 6. Extended Adjacency List ↔ Adjacency Map
def extended_to_map(ext: ExtendedAdjacencyList) -> AdjacencyMap:
    """Chuyển đổi từ Extended Adjacency List sang Adjacency Map"""
    adj_map = AdjacencyMap(ext.n)
    adj_map.m = ext.m
    
    for edge_idx, (u, v) in enumerate(ext.edges):
        edge = (u, v)
        adj_map.outgoing[u][v] = edge
        adj_map.incoming[v][u] = edge
        
        if u != v:
            adj_map.outgoing[v][u] = edge
            adj_map.incoming[u][v] = edge
    
    return adj_map

def map_to_extended(adj_map: AdjacencyMap) -> ExtendedAdjacencyList:
    """Chuyển đổi từ Adjacency Map sang Extended Adjacency List"""
    ext = ExtendedAdjacencyList(adj_map.n)
    ext.m = adj_map.m
    
    # Thu thập các cạnh duy nhất
    unique_edges = set()
    for u in adj_map.outgoing:
        for v in adj_map.outgoing[u]:
            if u <= v:
                unique_edges.add((u, v))
    
    ext.edges = list(unique_edges)
    
    # Xây dựng danh sách incoming và outgoing
    for edge_idx, (u, v) in enumerate(ext.edges):
        ext.outgoing[u].append(edge_idx)
        ext.incoming[v].append(edge_idx)
        
        if u != v:
            ext.outgoing[v].append(edge_idx)
            ext.incoming[u].append(edge_idx)
    
    return ext

# Function to display current representation
def display_current_representation():
    print(f"\n=== DO THI HIEN TAI === ({current_rep.value})")
    if current_rep == Representation.ADJ_LIST:
        current_list.display()
    elif current_rep == Representation.ADJ_MATRIX:
        current_matrix.display()
    elif current_rep == Representation.EXT_ADJ_LIST:
        current_extended.display()
    elif current_rep == Representation.ADJ_MAP:
        current_map.display()
    print()

# Function to validate conversion choice
def is_valid_conversion(choice: int) -> bool:
    if choice == 1:  # Display current
        return True
    elif choice in [2, 3, 4]:  # AL conversions
        return current_rep == Representation.ADJ_LIST
    elif choice in [5, 6, 7]:  # AM conversions
        return current_rep == Representation.ADJ_MATRIX
    elif choice in [8, 9, 10]:  # EAL conversions
        return current_rep == Representation.EXT_ADJ_LIST
    elif choice in [11, 12, 13]:  # AMap conversions
        return current_rep == Representation.ADJ_MAP
    elif choice == 14:  # Exit
        return True
    else:
        return False

def main():
    global current_list, current_matrix, current_extended, current_map, current_rep
    
    print("=== CHUONG TRINH CHUYEN DOI BIEU DIEN DO THI DON ===\n")
    
    # Đọc input
    n, m = map(int, input("Nhap so dinh va so canh: ").split())
    
    current_list = AdjacencyList(n)
    
    print(f"Nhap {m} canh (dinh dau dinh cuoi):")
    for _ in range(m):
        u, v = map(int, input().split())
        current_list.add_edge(u, v)
    
    while True:
        print("\n=== MENU CHUYEN DOI ===")
        print("1. Hien thi do thi hien tai")
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
        print("\n14. Thoat")
        
        choice = input("Chon: ")
        
        try:
            choice = int(choice)
        except ValueError:
            print("Lua chon khong hop le! Vui long nhap so.")
            continue
        
        if not is_valid_conversion(choice):
            print(f"\nLOI: Khong the chuyen doi! Do thi hien tai dang o dang {current_rep.value} "
                  f"nhung ban chon chuyen doi tu dang khac.")
            print("Vui long chon lai!")
            continue
        
        if choice == 1:
            display_current_representation()
        
        elif choice == 2:
            current_matrix = list_to_matrix(current_list)
            current_rep = Representation.ADJ_MATRIX
            print("\nDa chuyen doi thanh cong: Adjacency List -> Adjacency Matrix")
            display_current_representation()
        
        elif choice == 3:
            current_extended = list_to_extended(current_list)
            current_rep = Representation.EXT_ADJ_LIST
            print("\nDa chuyen doi thanh cong: Adjacency List -> Extended Adjacency List")
            display_current_representation()
        
        elif choice == 4:
            current_map = list_to_map(current_list)
            current_rep = Representation.ADJ_MAP
            print("\nDa chuyen doi thanh cong: Adjacency List -> Adjacency Map")
            display_current_representation()
        
        elif choice == 5:
            current_list = matrix_to_list(current_matrix)
            current_rep = Representation.ADJ_LIST
            print("\nDa chuyen doi thanh cong: Adjacency Matrix -> Adjacency List")
            display_current_representation()
        
        elif choice == 6:
            current_extended = matrix_to_extended(current_matrix)
            current_rep = Representation.EXT_ADJ_LIST
            print("\nDa chuyen doi thanh cong: Adjacency Matrix -> Extended Adjacency List")
            display_current_representation()
        
        elif choice == 7:
            current_map = matrix_to_map(current_matrix)
            current_rep = Representation.ADJ_MAP
            print("\nDa chuyen doi thanh cong: Adjacency Matrix -> Adjacency Map")
            display_current_representation()
        
        elif choice == 8:
            current_list = extended_to_list(current_extended)
            current_rep = Representation.ADJ_LIST
            print("\nDa chuyen doi thanh cong: Extended Adjacency List -> Adjacency List")
            display_current_representation()
        
        elif choice == 9:
            current_matrix = extended_to_matrix(current_extended)
            current_rep = Representation.ADJ_MATRIX
            print("\nDa chuyen doi thanh cong: Extended Adjacency List -> Adjacency Matrix")
            display_current_representation()
        
        elif choice == 10:
            current_map = extended_to_map(current_extended)
            current_rep = Representation.ADJ_MAP
            print("\nDa chuyen doi thanh cong: Extended Adjacency List -> Adjacency Map")
            display_current_representation()
        
        elif choice == 11:
            current_list = map_to_list(current_map)
            current_rep = Representation.ADJ_LIST
            print("\nDa chuyen doi thanh cong: Adjacency Map -> Adjacency List")
            display_current_representation()
        
        elif choice == 12:
            current_matrix = map_to_matrix(current_map)
            current_rep = Representation.ADJ_MATRIX
            print("\nDa chuyen doi thanh cong: Adjacency Map -> Adjacency Matrix")
            display_current_representation()
        
        elif choice == 13:
            current_extended = map_to_extended(current_map)
            current_rep = Representation.EXT_ADJ_LIST
            print("\nDa chuyen doi thanh cong: Adjacency Map -> Extended Adjacency List")
            display_current_representation()
        
        elif choice == 14:
            print("Tam biet!")
            break
        
        else:
            print("Lua chon khong hop le!")

if __name__ == "__main__":
    main()
