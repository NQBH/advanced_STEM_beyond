from typing import List, Dict, Tuple
from collections import defaultdict

class GraphConverter:
    """
    Lớp chuyển đổi giữa các dạng biểu diễn đồ thị:
    - Adjacency Matrix
    - Adjacency List  
    - Extended Adjacency List
    - Adjacency Map
    """
    
    def __init__(self):
        self.n = 0
    
    # 1. Adjacency Matrix -> Adjacency List
    def matrix_to_list(self, matrix: List[List[int]]) -> List[List[int]]:
        """Chuyển ma trận kề thành danh sách kề"""
        self.n = len(matrix)
        adj_list = [[] for _ in range(self.n)]
        
        for i in range(self.n):
            for j in range(self.n):
                if matrix[i][j] == 1:
                    adj_list[i].append(j)
        
        return adj_list
    
    # 2. Adjacency List -> Adjacency Matrix
    def list_to_matrix(self, adj_list: List[List[int]]) -> List[List[int]]:
        """Chuyển danh sách kề thành ma trận kề"""
        self.n = len(adj_list)
        matrix = [[0 for _ in range(self.n)] for _ in range(self.n)]
        
        for i in range(self.n):
            for neighbor in adj_list[i]:
                matrix[i][neighbor] = 1
        
        return matrix
    
    # 3. Adjacency Matrix -> Extended Adjacency List
    def matrix_to_extended_list(self, matrix: List[List[int]]) -> List[Tuple[int, List[int]]]:
        """Chuyển ma trận kề thành danh sách kề mở rộng"""
        self.n = len(matrix)
        ext_list = []
        
        for i in range(self.n):
            neighbors = []
            for j in range(self.n):
                if matrix[i][j] == 1:
                    neighbors.append(j)
            ext_list.append((i, neighbors))
        
        return ext_list
    
    # 4. Extended Adjacency List -> Adjacency Matrix
    def extended_list_to_matrix(self, ext_list: List[Tuple[int, List[int]]]) -> List[List[int]]:
        """Chuyển danh sách kề mở rộng thành ma trận kề"""
        self.n = len(ext_list)
        matrix = [[0 for _ in range(self.n)] for _ in range(self.n)]
        
        for vertex, neighbors in ext_list:
            for neighbor in neighbors:
                matrix[vertex][neighbor] = 1
        
        return matrix
    
    # 5. Adjacency List -> Adjacency Map
    def list_to_map(self, adj_list: List[List[int]]) -> Dict[int, List[int]]:
        """Chuyển danh sách kề thành map kề"""
        adj_map = {}
        for i in range(len(adj_list)):
            adj_map[i] = adj_list[i].copy()
        return adj_map
    
    # 6. Adjacency Map -> Adjacency List
    def map_to_list(self, adj_map: Dict[int, List[int]]) -> List[List[int]]:
        """Chuyển map kề thành danh sách kề"""
        if not adj_map:
            return []
        
        max_vertex = 0
        for vertex, neighbors in adj_map.items():
            max_vertex = max(max_vertex, vertex)
            for neighbor in neighbors:
                max_vertex = max(max_vertex, neighbor)
        
        adj_list = [[] for _ in range(max_vertex + 1)]
        for vertex, neighbors in adj_map.items():
            adj_list[vertex] = neighbors.copy()
        
        return adj_list
    
    # Utility functions for printing
    def print_matrix(self, matrix: List[List[int]], title="Adjacency Matrix"):
        """In ma trận kề"""
        print(f"{title}:")
        for row in matrix:
            print(" ".join(map(str, row)))
        print()
    
    def print_list(self, adj_list: List[List[int]], title="Adjacency List"):
        """In danh sách kề"""
        print(f"{title}:")
        for i in range(len(adj_list)):
            print(f"{i}: {' '.join(map(str, adj_list[i]))}")
        print()
    
    def print_extended_list(self, ext_list: List[Tuple[int, List[int]]], title="Extended Adjacency List"):
        """In danh sách kề mở rộng"""
        print(f"{title}:")
        for vertex, neighbors in ext_list:
            print(f"Vertex {vertex}: {' '.join(map(str, neighbors))}")
        print()
    
    def print_map(self, adj_map: Dict[int, List[int]], title="Adjacency Map"):
        """In map kề"""
        print(f"{title}:")
        for vertex, neighbors in adj_map.items():
            print(f"{vertex}: {' '.join(map(str, neighbors))}")
        print()


class GraphExamples:
    """Các ví dụ về các loại đồ thị"""
    
    @staticmethod
    def get_parent_array() -> List[int]:
        """Array of parents (cây) - ví dụ: [1, 2, -1, 2] với đỉnh 2 là root"""
        return [1, 2, -1, 2]
    
    @staticmethod
    def get_graph_matrix() -> List[List[int]]:
        """Ma trận kề của đồ thị mẫu"""
        return [
            [0, 1, 1, 0],
            [1, 0, 0, 1],
            [1, 0, 0, 1],
            [0, 1, 1, 0]
        ]
    
    @staticmethod
    def parent_array_to_tree_list(parent_array: List[int]) -> List[List[int]]:
        """Chuyển parent array thành adjacency list của cây"""
        n = len(parent_array)
        tree_list = [[] for _ in range(n)]
        
        for i in range(n):
            if parent_array[i] != -1:
                # Thêm cạnh từ parent đến child và ngược lại (cây vô hướng)
                tree_list[parent_array[i]].append(i)
                tree_list[i].append(parent_array[i])
        
        return tree_list


class TreeNode:
    """Node cho biểu diễn First-child next-sibling"""
    def __init__(self, data: int):
        self.data = data
        self.first_child = None
        self.next_sibling = None


class TreeRepresentation:
    """Các phương pháp biểu diễn cây"""
    
    @staticmethod
    def create_fcns_tree() -> TreeNode:
        """Tạo cây theo biểu diễn First-child next-sibling"""
        # Tạo cây mẫu: root(0) có con là 1,2; node 1 có con là 3
        root = TreeNode(0)
        child1 = TreeNode(1)
        child2 = TreeNode(2)
        child3 = TreeNode(3)
        
        root.first_child = child1
        child1.next_sibling = child2
        child1.first_child = child3
        
        return root
    
    @staticmethod
    def print_fcns_tree(root: TreeNode, level=0):
        """In cây First-child next-sibling"""
        if not root:
            return
        
        print("  " * level + f"Node {root.data}")
        
        # In tất cả con
        child = root.first_child
        while child:
            TreeRepresentation.print_fcns_tree(child, level + 1)
            child = child.next_sibling
    
    @staticmethod
    def fcns_to_adjacency_list(root: TreeNode) -> List[List[int]]:
        """Chuyển cây FCNS thành adjacency list"""
        adj_list = defaultdict(list)
        
        def traverse(node):
            if not node:
                return
            
            # Thêm các con vào danh sách kề
            child = node.first_child
            while child:
                adj_list[node.data].append(child.data)
                adj_list[child.data].append(node.data)  # Cây vô hướng
                traverse(child)
                child = child.next_sibling
        
        traverse(root)
        
        # Chuyển về list thông thường
        max_node = max(adj_list.keys()) if adj_list else 0
        result = [[] for _ in range(max_node + 1)]
        for node, neighbors in adj_list.items():
            result[node] = neighbors
        
        return result


def main():
    converter = GraphConverter()
    
    print("=== GRAPH CONVERTER DEMO ===\n")
    
    # Ví dụ với đồ thị
    original_matrix = GraphExamples.get_graph_matrix()
    
    print("1. Original Graph:")
    converter.print_matrix(original_matrix)
    
    # Chuyển đổi qua lại giữa các dạng biểu diễn
    print("2. Matrix -> Adjacency List:")
    adj_list = converter.matrix_to_list(original_matrix)
    converter.print_list(adj_list)
    
    print("3. List -> Matrix (verify):")
    verify_matrix = converter.list_to_matrix(adj_list)
    converter.print_matrix(verify_matrix, "Verified Matrix")
    
    print("4. Matrix -> Extended Adjacency List:")
    ext_list = converter.matrix_to_extended_list(original_matrix)
    converter.print_extended_list(ext_list)
    
    print("5. List -> Adjacency Map:")
    adj_map = converter.list_to_map(adj_list)
    converter.print_map(adj_map)
    
    print("6. Map -> List (verify):")
    verify_list = converter.map_to_list(adj_map)
    converter.print_list(verify_list, "Verified Adjacency List")
    
    print("=== PARENT ARRAY EXAMPLE ===")
    parent_array = GraphExamples.get_parent_array()
    print(f"Parent Array: {parent_array}")
    
    # Chuyển parent array thành adjacency list
    print("\nParent Array -> Tree Adjacency List:")
    tree_list = GraphExamples.parent_array_to_tree_list(parent_array)
    converter.print_list(tree_list, "Tree Adjacency List")
    
    print("=== FIRST-CHILD NEXT-SIBLING EXAMPLE ===")
    fcns_tree = TreeRepresentation.create_fcns_tree()
    print("First-Child Next-Sibling Tree:")
    TreeRepresentation.print_fcns_tree(fcns_tree)
    
    print("\nFCNS Tree -> Adjacency List:")
    fcns_adj_list = TreeRepresentation.fcns_to_adjacency_list(fcns_tree)
    converter.print_list(fcns_adj_list, "FCNS Tree Adjacency List")
    
    print("=== CONVERSION VERIFICATION ===")
    print("Total conversions available: 3A₁³ + A₄² = 3×4 + 12 = 24 converter programs")
    print("- 4 basic representations: Matrix, List, Extended List, Map")
    print("- 3 special tree representations: Parent Array, FCNS, General Tree")
    print("- Each can convert to others, giving multiple conversion paths")


if __name__ == "__main__":
    main()