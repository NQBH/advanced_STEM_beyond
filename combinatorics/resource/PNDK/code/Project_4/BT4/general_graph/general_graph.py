from typing import List, Dict, Set
from collections import defaultdict

class GeneralGraphMatrix:
    """Adjacency Matrix cho General Graph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.matrix = [[0] * num_vertices for _ in range(num_vertices)]
    
    def add_edge(self, u: int, v: int, count: int = 1):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            if u == v:  # Self-loop
                self.matrix[u][v] += count  
            else:  # Normal edge
                self.matrix[u][v] += count
                self.matrix[v][u] += count  # Undirected
    
    def edge_count(self, u: int, v: int) -> int:
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            return self.matrix[u][v]
        return 0
    
    def has_self_loop(self, u: int) -> bool:
        """Kiểm tra đỉnh u có self-loop không"""
        if 0 <= u < self.num_vertices:
            return self.matrix[u][u] > 0
        return False
    
    def display(self):
        print("General Graph Matrix:")
        for i, row in enumerate(self.matrix):
            print(f"{i}: {row}")

class GeneralGraphList:
    """Adjacency List cho General Graph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
    
    def add_edge(self, u: int, v: int, count: int = 1):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            if u == v:  # Self-loop
                self.adj_list[u].extend([v] * count)  # Chỉ thêm vào 1 list
            else:  # Normal edge
                self.adj_list[u].extend([v] * count)
                self.adj_list[v].extend([u] * count)  # Undirected
    
    def edge_count(self, u: int, v: int) -> int:
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            return self.adj_list[u].count(v)
        return 0
    
    def self_loop_count(self, u: int) -> int:
        """Đếm số self-loops của đỉnh u"""
        if 0 <= u < self.num_vertices:
            return self.adj_list[u].count(u)
        return 0
    
    def display(self):
        print("General Graph List:")
        for i, neighbors in enumerate(self.adj_list):
            print(f"{i}: {neighbors}")

class Edge:
    """Edge với unique ID cho General Graph"""
    
    def __init__(self, source: int, target: int, weight: float = 1.0, edge_id: int = 0):
        self.source = source
        self.target = target
        self.weight = weight
        self.edge_id = edge_id
        self.is_self_loop = (source == target)
    
    def __repr__(self):
        loop_indicator = "↻" if self.is_self_loop else "→"
        return f"({self.source}{loop_indicator}{self.target}#{self.edge_id})"

class GeneralGraphExtendedList:
    """Extended Adjacency List cho General Graph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.outgoing = [[] for _ in range(num_vertices)]
        self.incoming = [[] for _ in range(num_vertices)]
        self.all_edges = []
        self.edge_id_counter = 0
    
    def add_edge(self, u: int, v: int, weight: float = 1.0, count: int = 1):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            for _ in range(count):
                if u == v:  # Self-loop
                    edge_self = Edge(u, v, weight, self.edge_id_counter)
                    self.edge_id_counter += 1
                    
                    self.outgoing[u].append(edge_self)
                    self.incoming[v].append(edge_self)  # u == v
                    self.all_edges.append(edge_self)
                else:  # Normal edge
                    edge_uv = Edge(u, v, weight, self.edge_id_counter)
                    self.edge_id_counter += 1
                    
                    self.outgoing[u].append(edge_uv)
                    self.incoming[v].append(edge_uv)
                    self.all_edges.append(edge_uv)
                    
                    # Undirected: tạo edge ngược
                    edge_vu = Edge(v, u, weight, self.edge_id_counter)
                    self.edge_id_counter += 1
                    
                    self.outgoing[v].append(edge_vu)
                    self.incoming[u].append(edge_vu)
                    self.all_edges.append(edge_vu)
    
    def edge_count(self, u: int, v: int) -> int:
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            count = 0
            for edge in self.outgoing[u]:
                if edge.target == v:
                    count += 1
            return count
        return 0
    
    def get_self_loop_edges(self, u: int) -> List[Edge]:
        """Lấy tất cả self-loop edges của đỉnh u"""
        if 0 <= u < self.num_vertices:
            return [edge for edge in self.outgoing[u] if edge.is_self_loop]
        return []
    
    def display(self):
        print("General Graph Extended List:")
        for i in range(self.num_vertices):
            print(f"{i}: {self.outgoing[i]}")

class GeneralGraphMap:
    """Adjacency Map cho General Graph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_map = [defaultdict(int) for _ in range(num_vertices)]
    
    def add_edge(self, u: int, v: int, count: int = 1):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            if u == v:  # Self-loop
                self.adj_map[u][v] += count  # Chỉ thêm 1 lần
            else:  # Normal edge
                self.adj_map[u][v] += count
                self.adj_map[v][u] += count  # Undirected
    
    def edge_count(self, u: int, v: int) -> int:
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            return self.adj_map[u][v]
        return 0
    
    def self_loop_count(self, u: int) -> int:
        """Đếm self-loops của đỉnh u"""
        if 0 <= u < self.num_vertices:
            return self.adj_map[u][u]
        return 0
    
    def display(self):
        print("General Graph Map:")
        for i in range(self.num_vertices):
            if self.adj_map[i]:
                print(f"{i}: {dict(self.adj_map[i])}")
            else:
                print(f"{i}: {{}}")

def read_general_graph_from_file(filename: str) -> GeneralGraphMatrix:
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()
        num_vertices = int(lines[0].strip())
        
        graph = GeneralGraphMatrix(num_vertices)
        
        total_edges = 0
        self_loops = 0
        for i in range(1, len(lines)):
            line = lines[i].strip()
            if line:  # Bỏ qua dòng trống
                parts = line.split()
                if len(parts) >= 2:
                    u, v = int(parts[0]), int(parts[1])
                    count = int(parts[2]) if len(parts) >= 3 else 1
                    
                    graph.add_edge(u, v, count)
                    total_edges += count
                    
                    if u == v:
                        self_loops += count
                        print(f"Thêm {count} self-loop: {u}↻{u}")
                    else:
                        print(f"Thêm {count} cạnh: {u}-{v}")
                return graph
        
    except FileNotFoundError:
        print(f"Không tìm thấy file: {filename}")
        return GeneralGraphMatrix(0)
    except Exception as e:
        print(f"Lỗi đọc file: {e}")
        return GeneralGraphMatrix(0)


# =====================================================
# 12 GENERAL GRAPH CONVERTERS
# =====================================================

def general_matrix_to_list(matrix_graph: GeneralGraphMatrix) -> GeneralGraphList:
    """
    CONVERTER 1: Matrix → List (General Graph)
    
    Thuật toán:
    1. Duyệt toàn bộ matrix (không chỉ upper triangle vì có self-loops)
    2. Xử lý self-loops riêng biệt (chỉ thêm 1 lần)
    3. Xử lý normal edges (thêm 2 chiều)
    
    Time: O(V²)
    """
    n = matrix_graph.num_vertices
    list_graph = GeneralGraphList(n)
    
    for i in range(n):
        for j in range(n):
            count = matrix_graph.matrix[i][j]
            if count > 0:
                if i == j:  # Self-loop
                    list_graph.adj_list[i].extend([j] * count)
                elif i < j:  # Normal edge (chỉ xử lý 1 lần để tránh duplicate)
                    list_graph.adj_list[i].extend([j] * count)
                    list_graph.adj_list[j].extend([i] * count)
                # Skip i > j để tránh xử lý duplicate normal edges
    
    return list_graph

def general_list_to_matrix(list_graph: GeneralGraphList) -> GeneralGraphMatrix:
    """
    CONVERTER 2: List → Matrix (General Graph)
    
    Thuật toán: Tương tự Multigraph nhưng cần xử lý self-loops
    Time: O(V + E)
    """
    n = list_graph.num_vertices
    matrix_graph = GeneralGraphMatrix(n)
    
    for u in range(n):
        neighbor_count = defaultdict(int)
        for v in list_graph.adj_list[u]:
            neighbor_count[v] += 1
        
        for v, count in neighbor_count.items():
            matrix_graph.matrix[u][v] = count
    
    return matrix_graph

def general_matrix_to_extended_list(matrix_graph: GeneralGraphMatrix) -> GeneralGraphExtendedList:
    """
    CONVERTER 3: Matrix → Extended List (General Graph)
    
    Thuật toán: Xử lý self-loops và normal edges riêng biệt
    Time: O(V² + E)
    """
    n = matrix_graph.num_vertices
    ext_graph = GeneralGraphExtendedList(n)
    
    for i in range(n):
        for j in range(n):
            count = matrix_graph.matrix[i][j]
            if count > 0:
                if i == j:  # Self-loop
                    for _ in range(count):
                        edge_self = Edge(i, j, 1.0, ext_graph.edge_id_counter)
                        ext_graph.edge_id_counter += 1
                        ext_graph.outgoing[i].append(edge_self)
                        ext_graph.incoming[j].append(edge_self)
                        ext_graph.all_edges.append(edge_self)
                elif i < j:  # Normal edge (chỉ xử lý 1 lần)
                    for _ in range(count):
                        edge_ij = Edge(i, j, 1.0, ext_graph.edge_id_counter)
                        ext_graph.edge_id_counter += 1
                        ext_graph.outgoing[i].append(edge_ij)
                        ext_graph.incoming[j].append(edge_ij)
                        ext_graph.all_edges.append(edge_ij)
                        
                        # Undirected
                        edge_ji = Edge(j, i, 1.0, ext_graph.edge_id_counter)
                        ext_graph.edge_id_counter += 1
                        ext_graph.outgoing[j].append(edge_ji)
                        ext_graph.incoming[i].append(edge_ji)
                        ext_graph.all_edges.append(edge_ji)
    
    return ext_graph

def general_extended_list_to_matrix(ext_graph: GeneralGraphExtendedList) -> GeneralGraphMatrix:
    """
    CONVERTER 4: Extended List → Matrix (General Graph)
    
    Thuật toán: Tương tự Multigraph
    Time: O(E)
    """
    n = ext_graph.num_vertices
    matrix_graph = GeneralGraphMatrix(n)
    
    edge_count = defaultdict(int)
    for edge in ext_graph.all_edges:
        edge_count[(edge.source, edge.target)] += 1
    
    for (u, v), count in edge_count.items():
        matrix_graph.matrix[u][v] = count
    
    return matrix_graph

def general_list_to_extended_list(list_graph: GeneralGraphList) -> GeneralGraphExtendedList:
    """
    CONVERTER 5: List → Extended List (General Graph)
    
    Thuật toán: Cần xử lý self-loops riêng biệt
    Time: O(V + E)
    """
    n = list_graph.num_vertices
    ext_graph = GeneralGraphExtendedList(n)
    
    # Xử lý self-loops trước
    for u in range(n):
        self_loop_count = list_graph.adj_list[u].count(u)
        if self_loop_count > 0:
            for _ in range(self_loop_count):
                edge_self = Edge(u, u, 1.0, ext_graph.edge_id_counter)
                ext_graph.edge_id_counter += 1
                ext_graph.outgoing[u].append(edge_self)
                ext_graph.incoming[u].append(edge_self)
                ext_graph.all_edges.append(edge_self)
    
    # Xử lý normal edges với canonical form
    edge_count = defaultdict(int)
    for u in range(n):
        for v in list_graph.adj_list[u]:
            if u != v:  # Bỏ qua self-loops (đã xử lý)
                canonical_key = (min(u, v), max(u, v))
                edge_count[canonical_key] += 1
    
    # Chia đôi và tạo edges
    for (u, v), total_count in edge_count.items():
        actual_count = total_count // 2  # Undirected edges được đếm 2 lần
        
        for _ in range(actual_count):
            edge_uv = Edge(u, v, 1.0, ext_graph.edge_id_counter)
            ext_graph.edge_id_counter += 1
            ext_graph.outgoing[u].append(edge_uv)
            ext_graph.incoming[v].append(edge_uv)
            ext_graph.all_edges.append(edge_uv)
            
            edge_vu = Edge(v, u, 1.0, ext_graph.edge_id_counter)
            ext_graph.edge_id_counter += 1
            ext_graph.outgoing[v].append(edge_vu)
            ext_graph.incoming[u].append(edge_vu)
            ext_graph.all_edges.append(edge_vu)
    
    return ext_graph

def general_extended_list_to_list(ext_graph: GeneralGraphExtendedList) -> GeneralGraphList:
    """
    CONVERTER 6: Extended List → List (General Graph)
    
    Thuật toán: Tương tự Multigraph
    Time: O(E)
    """
    n = ext_graph.num_vertices
    list_graph = GeneralGraphList(n)
    
    for u in range(n):
        for edge in ext_graph.outgoing[u]:
            list_graph.adj_list[u].append(edge.target)
    
    return list_graph

def general_matrix_to_map(matrix_graph: GeneralGraphMatrix) -> GeneralGraphMap:
    """
    CONVERTER 7: Matrix → Map (General Graph)
    
    Thuật toán: Tương tự Multigraph
    Time: O(V²)
    """
    n = matrix_graph.num_vertices
    map_graph = GeneralGraphMap(n)
    
    for i in range(n):
        for j in range(n):
            count = matrix_graph.matrix[i][j]
            if count > 0:
                map_graph.adj_map[i][j] = count
    
    return map_graph

def general_map_to_matrix(map_graph: GeneralGraphMap) -> GeneralGraphMatrix:
    """
    CONVERTER 8: Map → Matrix (General Graph)
    
    Thuật toán: Tương tự Multigraph
    Time: O(V + E)
    """
    n = map_graph.num_vertices
    matrix_graph = GeneralGraphMatrix(n)
    
    for u in range(n):
        for v, count in map_graph.adj_map[u].items():
            matrix_graph.matrix[u][v] = count
    
    return matrix_graph

def general_list_to_map(list_graph: GeneralGraphList) -> GeneralGraphMap:
    """
    CONVERTER 9: List → Map (General Graph)
    
    Thuật toán: Tương tự Multigraph
    Time: O(V + E)
    """
    n = list_graph.num_vertices
    map_graph = GeneralGraphMap(n)
    
    for u in range(n):
        neighbor_count = defaultdict(int)
        for v in list_graph.adj_list[u]:
            neighbor_count[v] += 1
        
        map_graph.adj_map[u] = neighbor_count
    
    return map_graph

def general_map_to_list(map_graph: GeneralGraphMap) -> GeneralGraphList:
    """
    CONVERTER 10: Map → List (General Graph)
    
    Thuật toán: Tương tự Multigraph
    Time: O(V + E)
    """
    n = map_graph.num_vertices
    list_graph = GeneralGraphList(n)
    
    for u in range(n):
        for v, count in map_graph.adj_map[u].items():
            list_graph.adj_list[u].extend([v] * count)
    
    return list_graph

def general_extended_list_to_map(ext_graph: GeneralGraphExtendedList) -> GeneralGraphMap:
    """
    CONVERTER 11: Extended List → Map (General Graph)
    
    Thuật toán: Tương tự Multigraph
    Time: O(E)
    """
    n = ext_graph.num_vertices
    map_graph = GeneralGraphMap(n)
    
    for u in range(n):
        target_count = defaultdict(int)
        for edge in ext_graph.outgoing[u]:
            target_count[edge.target] += 1
        
        map_graph.adj_map[u] = target_count
    
    return map_graph

def general_map_to_extended_list(map_graph: GeneralGraphMap) -> GeneralGraphExtendedList:
    """
    CONVERTER 12: Map → Extended List (General Graph)
    
    Thuật toán: Xử lý self-loops và normal edges riêng biệt
    Time: O(V + E)
    """
    n = map_graph.num_vertices
    ext_graph = GeneralGraphExtendedList(n)
    
    processed_edges = set()
    
    for u in range(n):
        for v, count in map_graph.adj_map[u].items():
            if u == v:  # Self-loop
                for _ in range(count):
                    edge_self = Edge(u, v, 1.0, ext_graph.edge_id_counter)
                    ext_graph.edge_id_counter += 1
                    ext_graph.outgoing[u].append(edge_self)
                    ext_graph.incoming[v].append(edge_self)
                    ext_graph.all_edges.append(edge_self)
            else:  # Normal edge
                canonical_key = (min(u, v), max(u, v))
                if canonical_key not in processed_edges:
                    processed_edges.add(canonical_key)
                    
                    for _ in range(count):
                        edge_uv = Edge(u, v, 1.0, ext_graph.edge_id_counter)
                        ext_graph.edge_id_counter += 1
                        ext_graph.outgoing[u].append(edge_uv)
                        ext_graph.incoming[v].append(edge_uv)
                        ext_graph.all_edges.append(edge_uv)
                        
                        edge_vu = Edge(v, u, 1.0, ext_graph.edge_id_counter)
                        ext_graph.edge_id_counter += 1
                        ext_graph.outgoing[v].append(edge_vu)
                        ext_graph.incoming[u].append(edge_vu)
                        ext_graph.all_edges.append(edge_vu)
    
    return ext_graph


def test_all_general_graph_converters():
    """Test tất cả 12 general graph converters với data từ file"""
    print("TEST: All 12 General Graph Converters (Đọc từ file)")
    print("=" * 60)
    
    # Đọc general graph từ file
    original = read_general_graph_from_file("../general_graph_sample.inp")
    
    if original.num_vertices == 0:
        return
    original.display()
    
    # Test từ Matrix
    print("\n=== 1. FROM MATRIX ===")
    list_result = general_matrix_to_list(original)
    ext_result = general_matrix_to_extended_list(original)
    map_result = general_matrix_to_map(original)
    
    print("1.1. Matrix → List:")
    list_result.display()
    print("1.2. Matrix → ExtList:")
    ext_result.display()
    print("1.3. Matrix → Map:")
    map_result.display()
    
    # Test từ List
    print("\n=== 2. FROM LIST ===")
    print("2.1. List → Matrix:")
    general_list_to_matrix(list_result).display()
    print("2.2. List → ExtList:")
    general_list_to_extended_list(list_result).display()
    print("2.3. List → Map:")
    general_list_to_map(list_result).display()
    
    # Test từ ExtList
    print("\n=== 3. FROM EXTENDED LIST ===")
    print("3.1. ExtList → Matrix:")
    general_extended_list_to_matrix(ext_result).display()
    print("3.2. ExtList → List:")
    general_extended_list_to_list(ext_result).display()
    print("3.3. ExtList → Map:")
    general_extended_list_to_map(ext_result).display()
    
    # Test từ Map
    print("\n=== 4. FROM MAP ===")
    print("4.1. Map → Matrix:")
    general_map_to_matrix(map_result).display()
    print("4.2. Map → List:")
    general_map_to_list(map_result).display()
    print("4.3. Map → ExtList:")
    general_map_to_extended_list(map_result).display()
    
    print("\n DONE")
    


if __name__ == "__main__":
    test_all_general_graph_converters()