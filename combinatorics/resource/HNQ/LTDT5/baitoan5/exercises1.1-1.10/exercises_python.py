import random
import itertools
from collections import deque, defaultdict
from typing import List, Optional, Tuple, Dict, Set
import re

class DIMACSGraph:
    """Exercise 1.1: DIMACS format reader/writer"""
    
    def __init__(self):
        self.vertices = 0
        self.edges = 0
        self.edge_list = []
        self.problem_type = ""
    
    def read_dimacs(self, input_text: str):
        """Read graph from DIMACS format"""
        lines = input_text.strip().split('\n')
        
        for line in lines:
            line = line.strip()
            if not line:
                continue
                
            tokens = line.split()
            
            if tokens[0] == 'p':
                self.problem_type = tokens[1]
                self.vertices = int(tokens[2])
                self.edges = int(tokens[3])
                print(f"Problem: {self.problem_type}, Vertices: {self.vertices}, Edges: {self.edges}")
            
            elif tokens[0] == 'e':
                u, v = int(tokens[1]) - 1, int(tokens[2]) - 1  # Convert to 0-based
                self.edge_list.append((u, v))
            
            elif tokens[0] == 'c':
                # Comment line - ignore
                continue
    
    def write_dimacs(self):
        """Write graph to DIMACS format"""
        print("c DIMACS format graph")
        print(f"p {self.problem_type} {self.vertices} {self.edges}")
        
        for u, v in self.edge_list:
            print(f"e {u + 1} {v + 1}")  # Convert back to 1-based
    
    def get_adjacency_list(self) -> List[List[int]]:
        """Convert to adjacency list representation"""
        adj_list = [[] for _ in range(self.vertices)]
        for u, v in self.edge_list:
            adj_list[u].append(v)
            adj_list[v].append(u)
        return adj_list


class SGBGraph:
    """Exercise 1.2: Stanford GraphBase format reader/writer"""
    
    def __init__(self):
        self.graph_type = ""
        self.vertices = []
        self.edges = []  # (source, target, weight)
    
    def read_sgb(self, input_text: str):
        """Read graph from SGB format"""
        lines = input_text.strip().split('\n')
        
        if lines:
            self.graph_type = lines[0]
        
        for line in lines[1:]:
            if not line.strip():
                continue
            
            # Parse CSV-like format
            parts = [part.strip().strip('"') for part in line.split(',')]
            
            if len(parts) >= 2:
                source, target = parts[0], parts[1]
                weight = int(parts[2]) if len(parts) > 2 and parts[2].isdigit() else 0
                
                self.edges.append((source, target, weight))
                
                # Add vertices if not already present
                if source not in self.vertices:
                    self.vertices.append(source)
                if target not in self.vertices:
                    self.vertices.append(target)
    
    def write_sgb(self):
        """Write graph to SGB format"""
        print(self.graph_type)
        for source, target, weight in self.edges:
            if weight != 0:
                print(f'"{source}","{target}",{weight}')
            else:
                print(f'"{source}","{target}"')


class GraphGenerators:
    """Exercise 1.3: Path graph, Circle graph, and Wheel graph generators"""
    
    @staticmethod
    def generate_path_graph(n: int) -> List[List[int]]:
        """Generate path graph Pn"""
        adj_list = [[] for _ in range(n)]
        for i in range(n - 1):
            adj_list[i].append(i + 1)
            adj_list[i + 1].append(i)
        return adj_list
    
    @staticmethod
    def generate_circle_graph(n: int) -> List[List[int]]:
        """Generate circle graph Cn"""
        adj_list = [[] for _ in range(n)]
        for i in range(n):
            next_vertex = (i + 1) % n
            adj_list[i].append(next_vertex)
            adj_list[next_vertex].append(i)
        return adj_list
    
    @staticmethod
    def generate_wheel_graph(n: int) -> List[List[int]]:
        """Generate wheel graph Wn (center + cycle of n vertices)"""
        adj_list = [[] for _ in range(n + 1)]
        
        # Connect center (vertex 0) to all other vertices
        for i in range(1, n + 1):
            adj_list[0].append(i)
            adj_list[i].append(0)
        
        # Create cycle among vertices 1 to n
        for i in range(1, n + 1):
            next_vertex = (i % n) + 1
            adj_list[i].append(next_vertex)
            adj_list[next_vertex].append(i)
        
        return adj_list


class CompleteGraphGenerators:
    """Exercise 1.4: Complete graph and Complete bipartite graph generators"""
    
    @staticmethod
    def generate_complete_graph(n: int) -> List[List[int]]:
        """Generate complete graph Kn"""
        adj_list = [[] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i != j:
                    adj_list[i].append(j)
        return adj_list
    
    @staticmethod
    def generate_complete_bipartite_graph(p: int, q: int) -> List[List[int]]:
        """Generate complete bipartite graph Kp,q"""
        adj_list = [[] for _ in range(p + q)]
        
        # Connect all vertices in first partition to all vertices in second partition
        for i in range(p):
            for j in range(p, p + q):
                adj_list[i].append(j)
                adj_list[j].append(i)
        
        return adj_list


class ExtendedAdjacencyMatrixPython:
    """Exercise 1.5: Extended adjacency matrix with Python class wrapper"""
    
    def __init__(self, vertices: int):
        self.vertices = vertices
        self.matrix = [[0] * vertices for _ in range(vertices)]
    
    def add_edge(self, u: int, v: int, weight: int = 1):
        """Add edge with optional weight"""
        if 0 <= u < self.vertices and 0 <= v < self.vertices:
            self.matrix[u][v] = weight
            self.matrix[v][u] = weight
    
    def remove_edge(self, u: int, v: int):
        """Remove edge between vertices u and v"""
        if 0 <= u < self.vertices and 0 <= v < self.vertices:
            self.matrix[u][v] = 0
            self.matrix[v][u] = 0
    
    def get_neighbors(self, v: int) -> List[int]:
        """Get all neighbors of vertex v"""
        neighbors = []
        if 0 <= v < self.vertices:
            for i in range(self.vertices):
                if self.matrix[v][i] != 0:
                    neighbors.append(i)
        return neighbors
    
    def has_edge(self, u: int, v: int) -> bool:
        """Check if edge exists between u and v"""
        if 0 <= u < self.vertices and 0 <= v < self.vertices:
            return self.matrix[u][v] != 0
        return False
    
    def get_weight(self, u: int, v: int) -> int:
        """Get weight of edge between u and v"""
        if 0 <= u < self.vertices and 0 <= v < self.vertices:
            return self.matrix[u][v]
        return 0
    
    def display(self):
        """Display the matrix in Python list format"""
        print("Extended Adjacency Matrix (Python-style):")
        for row in self.matrix:
            print(row)


class PerfectMatchingEnumerator:
    """Exercise 1.6: Perfect matching enumeration in complete bipartite graph"""
    
    def __init__(self, p: int, q: int):
        self.p = p
        self.q = q
    
    def enumerate_all_perfect_matchings(self):
        """Enumerate all perfect matchings in Kp,q"""
        if self.p != self.q:
            print("Perfect matching only exists when p = q")
            return
        
        # Generate all permutations of second partition
        second_partition = list(range(self.p, self.p + self.q))
        
        print(f"All perfect matchings in K{self.p},{self.q}:")
        count = 0
        
        for perm in itertools.permutations(range(self.q)):
            count += 1
            matching = []
            for i in range(self.p):
                matching.append((i, self.p + perm[i]))
            
            print(f"Matching {count}: {matching}")
        
        print(f"Total perfect matchings: {count}")


class BinaryTreeGenerator:
    """Exercise 1.7: Complete binary tree generator"""
    
    class TreeNode:
        def __init__(self, data: int):
            self.data = data
            self.left: Optional['BinaryTreeGenerator.TreeNode'] = None
            self.right: Optional['BinaryTreeGenerator.TreeNode'] = None
    
    @staticmethod
    def generate_complete_binary_tree(n: int) -> Optional['BinaryTreeGenerator.TreeNode']:
        """Generate complete binary tree with n nodes"""
        if n == 0:
            return None
        
        root = BinaryTreeGenerator.TreeNode(1)
        queue = deque([root])
        node_count = 1
        
        while node_count < n and queue:
            current = queue.popleft()
            
            # Add left child
            if node_count < n:
                node_count += 1
                current.left = BinaryTreeGenerator.TreeNode(node_count)
                queue.append(current.left)
            
            # Add right child
            if node_count < n:
                node_count += 1
                current.right = BinaryTreeGenerator.TreeNode(node_count)
                queue.append(current.right)
        
        return root
    
    @staticmethod
    def inorder_traversal(root: Optional['BinaryTreeGenerator.TreeNode']) -> List[int]:
        """Perform inorder traversal"""
        if not root:
            return []
        
        result = []
        result.extend(BinaryTreeGenerator.inorder_traversal(root.left))
        result.append(root.data)
        result.extend(BinaryTreeGenerator.inorder_traversal(root.right))
        return result
    
    @staticmethod
    def level_order_traversal(root: Optional['BinaryTreeGenerator.TreeNode']) -> List[int]:
        """Perform level order traversal"""
        if not root:
            return []
        
        result = []
        queue = deque([root])
        
        while queue:
            current = queue.popleft()
            result.append(current.data)
            
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        
        return result


class RandomTreeGenerator:
    """Exercise 1.8: Random tree generator"""
    
    @staticmethod
    def generate_random_tree(n: int) -> List[List[int]]:
        """Generate random tree with n nodes"""
        if n <= 1:
            return [[] for _ in range(max(1, n))]
        
        adj_list = [[] for _ in range(n)]
        vertices = [0]  # Start with vertex 0
        
        # Add remaining vertices one by one
        for i in range(1, n):
            # Choose random vertex from existing tree
            random_parent = random.choice(vertices)
            
            # Connect new vertex to random parent
            adj_list[i].append(random_parent)
            adj_list[random_parent].append(i)
            
            vertices.append(i)
        
        return adj_list
    
    @staticmethod
    def analyze_complexity():
        """Analyze time and space complexity"""
        print("Random Tree Generation Complexity Analysis:")
        print("Time Complexity: O(n) - each vertex added once")
        print("Space Complexity: O(n) - adjacency list storage")


class ArrayOfParentsTree:
    """Exercise 1.9: T.previous_sibling() operation using array-of-parents"""
    
    def __init__(self, size: int):
        self.n = size
        self.parent = [-1] * size
        self.children = [[] for _ in range(size)]
    
    def set_parent(self, child: int, par: int):
        """Set parent of child node"""
        if 0 <= child < self.n and -1 <= par < self.n:
            self.parent[child] = par
            if par != -1:
                self.children[par].append(child)
    
    def previous_sibling(self, v: int) -> int:
        """Get previous sibling of vertex v"""
        if v < 0 or v >= self.n or self.parent[v] == -1:
            return -1  # No parent or invalid vertex
        
        par = self.parent[v]
        siblings = self.children[par]
        
        try:
            index = siblings.index(v)
            return siblings[index - 1] if index > 0 else -1
        except ValueError:
            return -1
    
    def display(self):
        """Display the array-of-parents representation"""
        print("Array-of-parents representation:")
        for i in range(self.n):
            print(f"Node {i}: parent = {self.parent[i]}")


class ExtendedFirstChildNextSiblingTree:
    """Exercise 1.10: Extended first-child, next-sibling tree with Python class"""
    
    class TreeNode:
        def __init__(self, data: int):
            self.data = data
            self.first_child: Optional['ExtendedFirstChildNextSiblingTree.TreeNode'] = None
            self.next_sibling: Optional['ExtendedFirstChildNextSiblingTree.TreeNode'] = None
            self.parent: Optional['ExtendedFirstChildNextSiblingTree.TreeNode'] = None
    
    def __init__(self):
        self.root: Optional[ExtendedFirstChildNextSiblingTree.TreeNode] = None
        self.internal_numbers: List[int] = []
    
    def create_node(self, data: int) -> 'ExtendedFirstChildNextSiblingTree.TreeNode':
        """Create a new tree node"""
        node = ExtendedFirstChildNextSiblingTree.TreeNode(data)
        self.internal_numbers.append(data)
        return node
    
    def set_root(self, node: 'ExtendedFirstChildNextSiblingTree.TreeNode'):
        """Set the root of the tree"""
        self.root = node
    
    def add_child(self, parent: 'ExtendedFirstChildNextSiblingTree.TreeNode', 
                  child: 'ExtendedFirstChildNextSiblingTree.TreeNode'):
        """Add child to parent node"""
        if not parent or not child:
            return
        
        child.parent = parent
        
        if not parent.first_child:
            parent.first_child = child
        else:
            sibling = parent.first_child
            while sibling.next_sibling:
                sibling = sibling.next_sibling
            sibling.next_sibling = child
    
    def get_parent(self, node: 'ExtendedFirstChildNextSiblingTree.TreeNode') -> Optional['ExtendedFirstChildNextSiblingTree.TreeNode']:
        """Get parent of node"""
        return node.parent if node else None
    
    def get_first_child(self, node: 'ExtendedFirstChildNextSiblingTree.TreeNode') -> Optional['ExtendedFirstChildNextSiblingTree.TreeNode']:
        """Get first child of node"""
        return node.first_child if node else None
    
    def get_next_sibling(self, node: 'ExtendedFirstChildNextSiblingTree.TreeNode') -> Optional['ExtendedFirstChildNextSiblingTree.TreeNode']:
        """Get next sibling of node"""
        return node.next_sibling if node else None
    
    def get_children(self, node: 'ExtendedFirstChildNextSiblingTree.TreeNode') -> List['ExtendedFirstChildNextSiblingTree.TreeNode']:
        """Get all children of node"""
        children = []
        if not node or not node.first_child:
            return children
        
        child = node.first_child
        while child:
            children.append(child)
            child = child.next_sibling
        return children
    
    def get_depth(self, node: 'ExtendedFirstChildNextSiblingTree.TreeNode') -> int:
        """Get depth of node in tree"""
        if not node:
            return -1
        
        depth = 0
        current = node.parent
        while current:
            depth += 1
            current = current.parent
        return depth
    
    def display_with_internal_numbers(self):
        """Display tree with internal numbering"""
        print("Extended First-Child Next-Sibling Tree:")
        print(f"Internal numbering: {' '.join(map(str, self.internal_numbers))}")
        
        if self.root:
            self._display_node_info(self.root, 0)
    
    def _display_node_info(self, node: 'ExtendedFirstChildNextSiblingTree.TreeNode', level: int):
        """Helper method to display node information"""
        if not node:
            return
        
        print("  " * level + f"Node {node.data} (level {level})")
        
        child = node.first_child
        while child:
            self._display_node_info(child, level + 1)
            child = child.next_sibling


def display_adjacency_list(adj_list: List[List[int]]):
    """Utility function to display adjacency list"""
    for i, neighbors in enumerate(adj_list):
        print(f"{i}: {' '.join(map(str, neighbors))}")


def main():
    """Main function to demonstrate all exercises"""
    print("=== Graph Theory Exercises 1.1-1.10 Implementation ===\n")
    
    # Exercise 1.1: DIMACS format
    print("Exercise 1.1: DIMACS format")
    dimacs = DIMACSGraph()
    dimacs_input = "c Sample graph\np edge 4 4\ne 1 2\ne 2 3\ne 3 4\ne 1 4\n"
    dimacs.read_dimacs(dimacs_input)
    dimacs.write_dimacs()
    print()
    
    # Exercise 1.2: SGB format
    print("Exercise 1.2: Stanford GraphBase format")
    sgb = SGBGraph()
    sgb_input = "* GraphBase\n\"A\",\"B\",1\n\"B\",\"C\",2\n\"C\",\"D\",3\n"
    sgb.read_sgb(sgb_input)
    sgb.write_sgb()
    print()
    
    # Exercise 1.3: Graph generators
    print("Exercise 1.3: Path, Circle, and Wheel graphs")
    print("Path graph P4:")
    display_adjacency_list(GraphGenerators.generate_path_graph(4))
    print("Circle graph C4:")
    display_adjacency_list(GraphGenerators.generate_circle_graph(4))
    print("Wheel graph W4:")
    display_adjacency_list(GraphGenerators.generate_wheel_graph(4))
    print()
    
    # Exercise 1.4: Complete graphs
    print("Exercise 1.4: Complete and Complete Bipartite graphs")
    print("Complete graph K4:")
    display_adjacency_list(CompleteGraphGenerators.generate_complete_graph(4))
    print("Complete bipartite graph K2,3:")
    display_adjacency_list(CompleteGraphGenerators.generate_complete_bipartite_graph(2, 3))
    print()
    
    # Exercise 1.5: Extended adjacency matrix
    print("Exercise 1.5: Extended adjacency matrix (Python-style)")
    ext_adj = ExtendedAdjacencyMatrixPython(4)
    ext_adj.add_edge(0, 1, 2)
    ext_adj.add_edge(1, 2, 3)
    ext_adj.add_edge(2, 3, 1)
    ext_adj.display()
    print()
    
    # Exercise 1.6: Perfect matchings
    print("Exercise 1.6: Perfect matchings in complete bipartite graph")
    pme = PerfectMatchingEnumerator(3, 3)
    pme.enumerate_all_perfect_matchings()
    print()
    
    # Exercise 1.7: Complete binary tree
    print("Exercise 1.7: Complete binary tree with 7 nodes")
    binary_tree = BinaryTreeGenerator.generate_complete_binary_tree(7)
    inorder = BinaryTreeGenerator.inorder_traversal(binary_tree)
    level_order = BinaryTreeGenerator.level_order_traversal(binary_tree)
    print(f"Inorder traversal: {' '.join(map(str, inorder))}")
    print(f"Level order traversal: {' '.join(map(str, level_order))}")
    print()
    
    # Exercise 1.8: Random tree
    print("Exercise 1.8: Random tree generation")
    random.seed(42)  # Fixed seed for reproducible results
    random_tree = RandomTreeGenerator.generate_random_tree(6)
    print("Random tree with 6 nodes:")
    display_adjacency_list(random_tree)
    RandomTreeGenerator.analyze_complexity()
    print()
    
    # Exercise 1.9: Array-of-parents with previous sibling
    print("Exercise 1.9: Array-of-parents with previous_sibling operation")
    apt = ArrayOfParentsTree(6)
    apt.set_parent(1, 0)
    apt.set_parent(2, 0)
    apt.set_parent(3, 0)
    apt.set_parent(4, 1)
    apt.set_parent(5, 1)
    apt.display()
    print(f"Previous sibling of node 2: {apt.previous_sibling(2)}")
    print(f"Previous sibling of node 5: {apt.previous_sibling(5)}")
    print()
    
    # Exercise 1.10: Extended first-child next-sibling
    print("Exercise 1.10: Extended first-child next-sibling tree")
    ext_tree = ExtendedFirstChildNextSiblingTree()
    root_node = ext_tree.create_node(1)
    child1 = ext_tree.create_node(2)
    child2 = ext_tree.create_node(3)
    grandchild = ext_tree.create_node(4)
    
    ext_tree.set_root(root_node)
    ext_tree.add_child(root_node, child1)
    ext_tree.add_child(root_node, child2)
    ext_tree.add_child(child1, grandchild)
    
    ext_tree.display_with_internal_numbers()
    print(f"Depth of grandchild: {ext_tree.get_depth(grandchild)}")


if __name__ == "__main__":
    main()