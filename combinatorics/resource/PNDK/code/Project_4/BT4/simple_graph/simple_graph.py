from typing import List, Dict, Set

class SimpleGraphMatrix:
    """Adjacency Matrix cho Simple Graph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.matrix = [[0] * num_vertices for _ in range(num_vertices)]
    
    def add_edge(self, u: int, v: int):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            self.matrix[u][v] = 1
            self.matrix[v][u] = 1  # Undirected
    
    def display(self):
        print("Matrix:")
        for i, row in enumerate(self.matrix):
            print(f"{i}: {row}")

class SimpleGraphList:
    """Adjacency List cho Simple Graph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
    
    def add_edge(self, u: int, v: int):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            if v not in self.adj_list[u]:
                self.adj_list[u].append(v)
            if u not in self.adj_list[v]:  # Undirected
                self.adj_list[v].append(u)
    
    def display(self):
        print("List:")
        for i, neighbors in enumerate(self.adj_list):
            print(f"{i}: {neighbors}")

class Edge:    
    def __init__(self, source: int, target: int, weight: float = 1.0):
        self.source = source
        self.target = target
        self.weight = weight
    
    def __repr__(self):
        return f"({self.source}→{self.target})"

class SimpleGraphExtendedList:
    """Extended Adjacency List cho Simple Graph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.outgoing = [[] for _ in range(num_vertices)]
        self.incoming = [[] for _ in range(num_vertices)]
        self.all_edges = []
    
    def display(self):
        print("Extended List:")
        for i in range(self.num_vertices):
            print(f"{i}: {self.outgoing[i]}")

class SimpleGraphMap:
    """Adjacency Map cho Simple Graph"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_map = {i: set() for i in range(num_vertices)}
    
    def add_edge(self, u: int, v: int):
        if 0 <= u < self.num_vertices and 0 <= v < self.num_vertices:
            self.adj_map[u].add(v)
            self.adj_map[v].add(u)  # Undirected
    
    def display(self):
        print("Map:")
        for vertex, neighbors in self.adj_map.items():
            print(f"{vertex}: {neighbors}")

def read_graph_from_file(filename: str) -> SimpleGraphMatrix:
        with open(filename, 'r') as file:
            lines = file.readlines()
        num_vertices = int(lines[0].strip())
        graph = SimpleGraphMatrix(num_vertices)
        edges_count = 0
        for i in range(1, len(lines)):
            line = lines[i].strip()
            if line:  
                u, v = map(int, line.split())
                graph.add_edge(u, v)
                edges_count += 1
        return graph
        
def matrix_to_list(matrix_graph: SimpleGraphMatrix) -> SimpleGraphList:
    n = matrix_graph.num_vertices
    list_graph = SimpleGraphList(n)
    
    for i in range(n):
        for j in range(i, n): 
            if matrix_graph.matrix[i][j] == 1:
                if i == j:  
                    list_graph.adj_list[i].append(j)
                else: 
                    list_graph.adj_list[i].append(j)
                    list_graph.adj_list[j].append(i)
    
    return list_graph

def list_to_matrix(list_graph: SimpleGraphList) -> SimpleGraphMatrix:
    n = list_graph.num_vertices
    matrix_graph = SimpleGraphMatrix(n)
    
    for u in range(n):
        for v in list_graph.adj_list[u]:
            matrix_graph.matrix[u][v] = 1
    
    return matrix_graph

def matrix_to_extended_list(matrix_graph: SimpleGraphMatrix) -> SimpleGraphExtendedList:
    n = matrix_graph.num_vertices
    ext_graph = SimpleGraphExtendedList(n)
    
    for i in range(n):
        for j in range(i, n):
            if matrix_graph.matrix[i][j] == 1:
                edge_ij = Edge(i, j)
                ext_graph.outgoing[i].append(edge_ij)
                ext_graph.incoming[j].append(edge_ij)
                ext_graph.all_edges.append(edge_ij)
                
                if i != j:
                    edge_ji = Edge(j, i)
                    ext_graph.outgoing[j].append(edge_ji)
                    ext_graph.incoming[i].append(edge_ji)
                    ext_graph.all_edges.append(edge_ji)
    
    return ext_graph

def extended_list_to_matrix(ext_graph: SimpleGraphExtendedList) -> SimpleGraphMatrix:
    n = ext_graph.num_vertices
    matrix_graph = SimpleGraphMatrix(n)
    
    for edge in ext_graph.all_edges:
        matrix_graph.matrix[edge.source][edge.target] = 1
    
    return matrix_graph

def list_to_extended_list(list_graph: SimpleGraphList) -> SimpleGraphExtendedList:
    n = list_graph.num_vertices
    ext_graph = SimpleGraphExtendedList(n)
    
    processed_edges = set()
    
    for u in range(n):
        for v in list_graph.adj_list[u]:
            edge_key = (min(u, v), max(u, v))
            if edge_key not in processed_edges:
                processed_edges.add(edge_key)
                
                edge_uv = Edge(u, v)
                ext_graph.outgoing[u].append(edge_uv)
                ext_graph.incoming[v].append(edge_uv)
                ext_graph.all_edges.append(edge_uv)
                
                if u != v:
                    edge_vu = Edge(v, u)
                    ext_graph.outgoing[v].append(edge_vu)
                    ext_graph.incoming[u].append(edge_vu)
                    ext_graph.all_edges.append(edge_vu)
    
    return ext_graph

def extended_list_to_list(ext_graph: SimpleGraphExtendedList) -> SimpleGraphList:
    n = ext_graph.num_vertices
    list_graph = SimpleGraphList(n)
    
    for u in range(n):
        for edge in ext_graph.outgoing[u]:
            v = edge.target
            if v not in list_graph.adj_list[u]:
                list_graph.adj_list[u].append(v)
    
    return list_graph

def matrix_to_map(matrix_graph: SimpleGraphMatrix) -> SimpleGraphMap:
    n = matrix_graph.num_vertices
    map_graph = SimpleGraphMap(n)
    
    for i in range(n):
        for j in range(n):
            if matrix_graph.matrix[i][j] == 1:
                map_graph.adj_map[i].add(j)
    
    return map_graph

def map_to_matrix(map_graph: SimpleGraphMap) -> SimpleGraphMatrix:
    n = map_graph.num_vertices
    matrix_graph = SimpleGraphMatrix(n)
    
    for u in range(n):
        for v in map_graph.adj_map[u]:
            matrix_graph.matrix[u][v] = 1
    
    return matrix_graph

def list_to_map(list_graph: SimpleGraphList) -> SimpleGraphMap:
    n = list_graph.num_vertices
    map_graph = SimpleGraphMap(n)
    
    for u in range(n):
        map_graph.adj_map[u] = set(list_graph.adj_list[u])
    
    return map_graph

def map_to_list(map_graph: SimpleGraphMap) -> SimpleGraphList:
    n = map_graph.num_vertices
    list_graph = SimpleGraphList(n)
    
    for u in range(n):
        list_graph.adj_list[u] = list(map_graph.adj_map[u])
    
    return list_graph

def extended_list_to_map(ext_graph: SimpleGraphExtendedList) -> SimpleGraphMap:
    n = ext_graph.num_vertices
    map_graph = SimpleGraphMap(n)
    
    for u in range(n):
        for edge in ext_graph.outgoing[u]:
            map_graph.adj_map[u].add(edge.target)
    
    return map_graph

def map_to_extended_list(map_graph: SimpleGraphMap) -> SimpleGraphExtendedList:
    list_graph = map_to_list(map_graph)
    return list_to_extended_list(list_graph)

def test_all_converters_with_file():
    """Test tất cả 12 converters với data từ file"""
    
    original = read_graph_from_file("../simple_graph_sample.inp")

    if original.num_vertices == 0:
        return
    original.display()
    
    print("\n=== 1. FROM MATRIX ===")
    list_result = matrix_to_list(original)
    ext_result = matrix_to_extended_list(original)
    map_result = matrix_to_map(original)
    
    print("1.1. Matrix → List:")
    list_result.display()
    print("1.2. Matrix → ExtList:")
    ext_result.display()
    print("1.3. Matrix → Map:")
    map_result.display()
    
    # Test từ List
    print("\n=== 2. FROM LIST ===")
    print("2.1. List → Matrix:")
    list_to_matrix(list_result).display()
    print("2.2. List → ExtList:")
    list_to_extended_list(list_result).display()
    print("2.3. List → Map:")
    list_to_map(list_result).display()
    
    # Test từ ExtList
    print("\n=== 3. FROM EXTENDED LIST ===")
    print("3.1. ExtList → Matrix:")
    extended_list_to_matrix(ext_result).display()
    print("3.2. ExtList → List:")
    extended_list_to_list(ext_result).display()
    print("3.3. ExtList → Map:")
    extended_list_to_map(ext_result).display()
    
    # Test từ Map
    print("\n=== 4. FROM MAP ===")
    print("4.1. Map → Matrix:")
    map_to_matrix(map_result).display()
    print("4.2. Map → List:")
    map_to_list(map_result).display()
    print("4.3. Map → ExtList:")
    map_to_extended_list(map_result).display()
    
    print("\n DONE")

if __name__ == "__main__":
    test_all_converters_with_file()