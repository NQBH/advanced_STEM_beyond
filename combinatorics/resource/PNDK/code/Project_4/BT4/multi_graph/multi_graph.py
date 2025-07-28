from typing import List, Dict, Set
from collections import defaultdict

class MultigraphMatrix:
    """Adjacency Matrix cho Multigraph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.matrix = [[0] * num_vertices for _ in range(num_vertices)]
    
    def add_edge(self, u: int, v: int, count: int = 1):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            self.matrix[u][v] += count
            self.matrix[v][u] += count  # Undirected
    
    def edge_count(self, u: int, v: int) -> int:
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            return self.matrix[u][v]
        return 0
    
    def display(self):
        print("Multigraph Matrix:")
        for i, row in enumerate(self.matrix):
            print(f"{i}: {row}")


class MultigraphList:
    """Adjacency List cho Multigraph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
    
    def add_edge(self, u: int, v: int, count: int = 1):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            self.adj_list[u].extend([v] * count)
            self.adj_list[v].extend([u] * count)  # Undirected
    
    def edge_count(self, u: int, v: int) -> int:
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            return self.adj_list[u].count(v)
        return 0
    
    def display(self):
        print("Multigraph List:")
        for i, neighbors in enumerate(self.adj_list):
            print(f"{i}: {neighbors}")


class Edge:
    """Edge với unique ID cho Multigraph"""
    
    def __init__(self, source: int, target: int, weight: float = 1.0, edge_id: int = 0):
        self.source = source
        self.target = target
        self.weight = weight
        self.edge_id = edge_id
    
    def __repr__(self):
        return f"({self.source}→{self.target}#{self.edge_id})"


class MultigraphExtendedList:
    """Extended Adjacency List cho Multigraph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.outgoing = [[] for _ in range(num_vertices)]
        self.incoming = [[] for _ in range(num_vertices)]
        self.all_edges = []
        self.edge_id_counter = 0
    
    def add_edge(self, u: int, v: int, weight: float = 1.0, count: int = 1):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            for _ in range(count):
                edge_uv = Edge(u, v, weight, self.edge_id_counter)
                self.edge_id_counter += 1
                
                self.outgoing[u].append(edge_uv)
                self.incoming[v].append(edge_uv)
                self.all_edges.append(edge_uv)
                
                if u != v:  # Not self-loop
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
    
    def display(self):
        print("Multigraph Extended List:")
        for i in range(self.num_vertices):
            print(f"{i}: {self.outgoing[i]}")


class MultigraphMap:
    """Adjacency Map cho Multigraph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_map = [defaultdict(int) for _ in range(num_vertices)]
    
    def add_edge(self, u: int, v: int, count: int = 1):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            self.adj_map[u][v] += count
            self.adj_map[v][u] += count  # Undirected
    
    def edge_count(self, u: int, v: int) -> int:
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            return self.adj_map[u][v]
        return 0
    
    def display(self):
        print("Multigraph Map:")
        for i in range(self.num_vertices):
            if self.adj_map[i]:
                print(f"{i}: {dict(self.adj_map[i])}")
            else:
                print(f"{i}: {{}}")


# =====================================================
# INPUT FILE READER
# =====================================================

def read_multigraph_from_file(filename: str) -> MultigraphMatrix:
    """Đọc multigraph từ file với format: u v count"""
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()
        
        # Dòng đầu: số đỉnh
        num_vertices = int(lines[0].strip())
        
        # Tạo multigraph
        graph = MultigraphMatrix(num_vertices)
        
        # Các dòng sau: u v count
        total_edges = 0
        for i in range(1, len(lines)):
            line = lines[i].strip()
            if line:  # Bỏ qua dòng trống
                parts = line.split()
                if len(parts) == 3:
                    u, v, count = int(parts[0]), int(parts[1]), int(parts[2])
                    graph.add_edge(u, v, count)
                    total_edges += count
                elif len(parts) == 2:  # Fallback: assume count = 1
                    u, v = int(parts[0]), int(parts[1])
                    graph.add_edge(u, v, 1)
                    total_edges += 1
        
        return graph
        
    except FileNotFoundError:
        print(f"Không tìm thấy file: {filename}")
        return MultigraphMatrix(0)
    except Exception as e:
        print(f"Lỗi đọc file: {e}")
        return MultigraphMatrix(0)

def multigraph_matrix_to_list(matrix_graph: MultigraphMatrix) -> MultigraphList:
    """
    CONVERTER 1: Matrix → List (Multigraph)
    
    Thuật toán:
    1. Duyệt upper triangle của matrix
    2. Với mỗi matrix[i][j] = count > 0:
       - Thêm j vào adj_list[i] count lần
       - Nếu i ≠ j: thêm i vào adj_list[j] count lần
    
    """
    n = matrix_graph.num_vertices
    list_graph = MultigraphList(n)
    
    for i in range(n):
        for j in range(i, n):  # j >= i
            count = matrix_graph.matrix[i][j]
            if count > 0:
                if i == j:  # Self-loop
                    list_graph.adj_list[i].extend([j] * count)
                else:  # Normal edge
                    list_graph.adj_list[i].extend([j] * count)
                    list_graph.adj_list[j].extend([i] * count)
    
    return list_graph

def multigraph_list_to_matrix(list_graph: MultigraphList) -> MultigraphMatrix:
    """
    CONVERTER 2: List → Matrix (Multigraph)
    
    Thuật toán:
    1. Khởi tạo matrix toàn 0
    2. Với mỗi vertex u, đếm frequency của mỗi neighbor v
    3. Đặt matrix[u][v] = frequency
    
    """
    n = list_graph.num_vertices
    matrix_graph = MultigraphMatrix(n)
    
    # Đếm frequency thay vì chỉ đặt 1
    for u in range(n):
        neighbor_count = defaultdict(int)
        for v in list_graph.adj_list[u]:
            neighbor_count[v] += 1
        
        for v, count in neighbor_count.items():
            matrix_graph.matrix[u][v] = count
    
    return matrix_graph

def multigraph_matrix_to_extended_list(matrix_graph: MultigraphMatrix) -> MultigraphExtendedList:
    """
    CONVERTER 3: Matrix → Extended List (Multigraph)
    
    Thuật toán:
    1. Duyệt upper triangle của matrix
    2. Với mỗi matrix[i][j] = count > 0:
       - Tạo count Edge objects từ i đến j
       - Thêm vào outgoing/incoming lists
    
    """
    n = matrix_graph.num_vertices
    ext_graph = MultigraphExtendedList(n)
    
    for i in range(n):
        for j in range(i, n):  # Upper triangle
            count = matrix_graph.matrix[i][j]
            if count > 0:
                # Tạo count edge objects
                for _ in range(count):
                    edge_ij = Edge(i, j, 1.0, ext_graph.edge_id_counter)
                    ext_graph.edge_id_counter += 1
                    ext_graph.outgoing[i].append(edge_ij)
                    ext_graph.incoming[j].append(edge_ij)
                    ext_graph.all_edges.append(edge_ij)
                    
                    if i != j:  # Not self-loop
                        edge_ji = Edge(j, i, 1.0, ext_graph.edge_id_counter)
                        ext_graph.edge_id_counter += 1
                        ext_graph.outgoing[j].append(edge_ji)
                        ext_graph.incoming[i].append(edge_ji)
                        ext_graph.all_edges.append(edge_ji)
    
    return ext_graph

def multigraph_extended_list_to_matrix(ext_graph: MultigraphExtendedList) -> MultigraphMatrix:
    """
    CONVERTER 4: Extended List → Matrix (Multigraph)
    
    Thuật toán:
    1. Khởi tạo matrix toàn 0
    2. Duyệt all_edges, đếm frequency mỗi (source, target) pair
    3. Đặt matrix[source][target] = frequency

    """
    n = ext_graph.num_vertices
    matrix_graph = MultigraphMatrix(n)
    
    # Đếm frequency của mỗi edge
    edge_count = defaultdict(int)
    for edge in ext_graph.all_edges:
        edge_count[(edge.source, edge.target)] += 1
    
    # Đặt vào matrix
    for (u, v), count in edge_count.items():
        matrix_graph.matrix[u][v] = count
    
    return matrix_graph

def multigraph_list_to_extended_list(list_graph: MultigraphList) -> MultigraphExtendedList:
    """
    CONVERTER 5: List → Extended List (Multigraph)
    
    Thuật toán:
    1. Duyệt adjacency list
    2. Đếm frequency mỗi (u,v) pair
    3. Tạo Edge objects cho mỗi occurrence
    4. Sử dụng canonical form để tránh duplicate

    """
    n = list_graph.num_vertices
    ext_graph = MultigraphExtendedList(n)
    
    # Đếm edges theo canonical form
    edge_count = defaultdict(int)
    for u in range(n):
        for v in list_graph.adj_list[u]:
            canonical_key = (min(u, v), max(u, v))
            edge_count[canonical_key] += 1
    
    # Chia đôi vì mỗi undirected edge được đếm 2 lần
    for (u, v), total_count in edge_count.items():
        if u == v:  # Self-loop
            count = total_count
        else:  # Normal edge
            count = total_count // 2
        
        # Tạo count edge objects
        for _ in range(count):
            edge_uv = Edge(u, v, 1.0, ext_graph.edge_id_counter)
            ext_graph.edge_id_counter += 1
            ext_graph.outgoing[u].append(edge_uv)
            ext_graph.incoming[v].append(edge_uv)
            ext_graph.all_edges.append(edge_uv)
            
            if u != v:  # Not self-loop
                edge_vu = Edge(v, u, 1.0, ext_graph.edge_id_counter)
                ext_graph.edge_id_counter += 1
                ext_graph.outgoing[v].append(edge_vu)
                ext_graph.incoming[u].append(edge_vu)
                ext_graph.all_edges.append(edge_vu)
    
    return ext_graph

def multigraph_extended_list_to_list(ext_graph: MultigraphExtendedList) -> MultigraphList:
    """
    CONVERTER 6: Extended List → List (Multigraph)
    
    Thuật toán:
    1. Duyệt outgoing edges của mỗi vertex
    2. Thêm target của mỗi edge vào adjacency list

    """
    n = ext_graph.num_vertices
    list_graph = MultigraphList(n)
    
    for u in range(n):
        for edge in ext_graph.outgoing[u]:
            list_graph.adj_list[u].append(edge.target)
    
    return list_graph

def multigraph_matrix_to_map(matrix_graph: MultigraphMatrix) -> MultigraphMap:
    """
    CONVERTER 7: Matrix → Map (Multigraph)
    
    Thuật toán:
    1. Duyệt matrix
    2. Với mỗi matrix[i][j] = count > 0:
       - Đặt adj_map[i][j] = count
    

    """
    n = matrix_graph.num_vertices
    map_graph = MultigraphMap(n)
    
    for i in range(n):
        for j in range(n):
            count = matrix_graph.matrix[i][j]
            if count > 0:
                map_graph.adj_map[i][j] = count
    
    return map_graph

def multigraph_map_to_matrix(map_graph: MultigraphMap) -> MultigraphMatrix:
    """
    CONVERTER 8: Map → Matrix (Multigraph)
    
    Thuật toán:
    1. Khởi tạo matrix toàn 0
    2. Duyệt adj_map, với mỗi (v, count) đặt matrix[u][v] = count

    """
    n = map_graph.num_vertices
    matrix_graph = MultigraphMatrix(n)
    
    for u in range(n):
        for v, count in map_graph.adj_map[u].items():
            matrix_graph.matrix[u][v] = count
    
    return matrix_graph

def multigraph_list_to_map(list_graph: MultigraphList) -> MultigraphMap:
    """
    CONVERTER 9: List → Map (Multigraph)
    
    Thuật toán:
    1. Duyệt adjacency list
    2. Đếm frequency mỗi neighbor
    3. Lưu vào adj_map
    
    """
    n = list_graph.num_vertices
    map_graph = MultigraphMap(n)
    
    for u in range(n):
        neighbor_count = defaultdict(int)
        for v in list_graph.adj_list[u]:
            neighbor_count[v] += 1
        
        map_graph.adj_map[u] = neighbor_count
    
    return map_graph

def multigraph_map_to_list(map_graph: MultigraphMap) -> MultigraphList:
    """
    CONVERTER 10: Map → List (Multigraph)
    
    Thuật toán:
    1. Duyệt adj_map
    2. Với mỗi (v, count), thêm v vào list count lần
    
    """
    n = map_graph.num_vertices
    list_graph = MultigraphList(n)
    
    for u in range(n):
        for v, count in map_graph.adj_map[u].items():
            list_graph.adj_list[u].extend([v] * count)
    
    return list_graph

def multigraph_extended_list_to_map(ext_graph: MultigraphExtendedList) -> MultigraphMap:
    """
    CONVERTER 11: Extended List → Map (Multigraph)
    
    Thuật toán:
    1. Duyệt outgoing edges của mỗi vertex
    2. Đếm frequency mỗi target
    3. Lưu vào adj_map
    
    """
    n = ext_graph.num_vertices
    map_graph = MultigraphMap(n)
    
    for u in range(n):
        target_count = defaultdict(int)
        for edge in ext_graph.outgoing[u]:
            target_count[edge.target] += 1
        
        map_graph.adj_map[u] = target_count
    
    return map_graph

def multigraph_map_to_extended_list(map_graph: MultigraphMap) -> MultigraphExtendedList:
    """
    CONVERTER 12: Map → Extended List (Multigraph)
    
    Thuật toán:
    1. Duyệt adj_map
    2. Với mỗi (v, count), tạo count Edge objects
    3. Sử dụng canonical form để tránh duplicate
    
    """
    n = map_graph.num_vertices
    ext_graph = MultigraphExtendedList(n)
    
    # Track processed edges với canonical form
    processed_edges = set()
    
    for u in range(n):
        for v, count in map_graph.adj_map[u].items():
            canonical_key = (min(u, v), max(u, v))
            if canonical_key not in processed_edges:
                processed_edges.add(canonical_key)
                
                # Tạo count edge objects
                for _ in range(count):
                    edge_uv = Edge(u, v, 1.0, ext_graph.edge_id_counter)
                    ext_graph.edge_id_counter += 1
                    ext_graph.outgoing[u].append(edge_uv)
                    ext_graph.incoming[v].append(edge_uv)
                    ext_graph.all_edges.append(edge_uv)
                    
                    if u != v:  # Not self-loop
                        edge_vu = Edge(v, u, 1.0, ext_graph.edge_id_counter)
                        ext_graph.edge_id_counter += 1
                        ext_graph.outgoing[v].append(edge_vu)
                        ext_graph.incoming[u].append(edge_vu)
                        ext_graph.all_edges.append(edge_vu)
    
    return ext_graph

def test_all_multigraph_converters():
    print("TEST: All 12 Multigraph Converters (Đọc từ file)")
    print("=" * 60)
    
    original = read_multigraph_from_file("../multi_graph_sample.inp")
    if original.num_vertices == 0:
        return
    original.display()
    
    print("\n=== 1. FROM MATRIX ===")
    list_result = multigraph_matrix_to_list(original)
    ext_result = multigraph_matrix_to_extended_list(original)
    map_result = multigraph_matrix_to_map(original)
    
    print("1.1. Matrix → List:")
    list_result.display()
    print("1.2. Matrix → ExtList:")
    ext_result.display()
    print("1.3. Matrix → Map:")
    map_result.display()
    
    # Test từ List
    print("\n=== 2. FROM LIST ===")
    print("2.1. List → Matrix:")
    multigraph_list_to_matrix(list_result).display()
    print("2.2. List → ExtList:")
    multigraph_list_to_extended_list(list_result).display()
    print("2.3. List → Map:")
    multigraph_list_to_map(list_result).display()
    
    # Test từ ExtList
    print("\n=== 3. FROM EXTENDED LIST ===")
    print("3.1. ExtList → Matrix:")
    multigraph_extended_list_to_matrix(ext_result).display()
    print("3.2. ExtList → List:")
    multigraph_extended_list_to_list(ext_result).display()
    print("3.3. ExtList → Map:")
    multigraph_extended_list_to_map(ext_result).display()
    
    # Test từ Map
    print("\n=== 4. FROM MAP ===")
    print("4.1. Map → Matrix:")
    multigraph_map_to_matrix(map_result).display()
    print("4.2. Map → List:")
    multigraph_map_to_list(map_result).display()
    print("4.3. Map → ExtList:")
    multigraph_map_to_extended_list(map_result).display()
    
    print("\n DONE")
    
    back_to_matrix = multigraph_list_to_matrix(list_result)
    is_correct = True
    for i in range(original.num_vertices):
        for j in range(original.num_vertices):
            if original.matrix[i][j] != back_to_matrix.matrix[i][j]:
                is_correct = False
                print(f"Mismatch at [{i}][{j}]: {original.matrix[i][j]} vs {back_to_matrix.matrix[i][j]}")


if __name__ == "__main__":
    test_all_multigraph_converters()