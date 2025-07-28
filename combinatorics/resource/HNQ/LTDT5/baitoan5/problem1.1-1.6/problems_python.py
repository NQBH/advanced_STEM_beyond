import numpy as np
from collections import defaultdict, deque
from typing import List, Optional, Set, Tuple
import math

class GraphRepresentation:
    """Implementation of basic graph theory problems 1.1-1.6"""
    
    @staticmethod
    def complete_graph_size(n: int) -> int:
        """Problem 1.1: Calculate number of edges in complete graph Kn"""
        return n * (n - 1) // 2
    
    @staticmethod
    def complete_bipartite_graph_size(p: int, q: int) -> int:
        """Problem 1.1: Calculate number of edges in complete bipartite graph Kp,q"""
        return p * q
    
    @staticmethod
    def is_circle_graph_bipartite(n: int) -> bool:
        """Problem 1.2: Check if circle graph Cn is bipartite"""
        return n % 2 == 0
    
    @staticmethod
    def is_complete_graph_bipartite(n: int) -> bool:
        """Problem 1.2: Check if complete graph Kn is bipartite"""
        return n <= 2
    
    @staticmethod
    def spanning_trees_complete(n: int) -> int:
        """Problem 1.3: Count spanning trees of complete graph using Cayley's formula"""
        if n <= 1:
            return 0
        if n == 2:
            return 1
        return n ** (n - 2)
    
    @staticmethod
    def spanning_trees_from_adj_matrix(adj_matrix: List[List[int]]) -> int:
        """Problem 1.3: Count spanning trees using Matrix-Tree theorem"""
        n = len(adj_matrix)
        if n <= 1:
            return 0
        
        # Create Laplacian matrix
        laplacian = [[0] * n for _ in range(n)]
        
        for i in range(n):
            degree = 0
            for j in range(n):
                if i != j and adj_matrix[i][j] == 1:
                    laplacian[i][j] = -1
                    degree += 1
            laplacian[i][i] = degree
        
        # Remove last row and column, then compute determinant
        # This is a simplified version - actual implementation would use proper matrix operations
        return 1  # Placeholder


class ExtendedAdjacencyMatrix:
    """Problem 1.4: Extended adjacency matrix representation"""
    
    def __init__(self, vertices: int):
        self.vertices = vertices
        self.matrix = [[0] * vertices for _ in range(vertices)]
    
    def add_edge(self, u: int, v: int, weight: int = 1):
        """Add edge with optional weight"""
        if 0 <= u < self.vertices and 0 <= v < self.vertices:
            self.matrix[u][v] = weight
            self.matrix[v][u] = weight  # For undirected graphs
    
    def delete_edge(self, u: int, v: int):
        """Delete edge between vertices u and v"""
        if 0 <= u < self.vertices and 0 <= v < self.vertices:
            self.matrix[u][v] = 0
            self.matrix[v][u] = 0
    
    def get_edges(self, v: int) -> List[int]:
        """Get all edges from vertex v"""
        edges = []
        if 0 <= v < self.vertices:
            for i in range(self.vertices):
                if self.matrix[v][i] != 0:
                    edges.append(i)
        return edges
    
    def get_incoming(self, v: int) -> List[int]:
        """Get incoming edges to vertex v"""
        incoming = []
        if 0 <= v < self.vertices:
            for i in range(self.vertices):
                if self.matrix[i][v] != 0:
                    incoming.append(i)
        return incoming
    
    def get_outgoing(self, v: int) -> List[int]:
        """Get outgoing edges from vertex v"""
        return self.get_edges(v)  # Same as get_edges for undirected graphs
    
    def get_source(self, u: int, v: int) -> List[int]:
        """Get source vertices of edge (u,v)"""
        sources = []
        if self.matrix[u][v] != 0:
            sources.append(u)
        return sources
    
    def get_target(self, u: int, v: int) -> List[int]:
        """Get target vertices of edge (u,v)"""
        targets = []
        if self.matrix[u][v] != 0:
            targets.append(v)
        return targets
    
    def display(self):
        """Display the extended adjacency matrix"""
        print("Extended Adjacency Matrix:")
        for row in self.matrix:
            print(" ".join(map(str, row)))


class TreeNode:
    """Node for first-child, next-sibling tree representation"""
    
    def __init__(self, data: int):
        self.data = data
        self.first_child: Optional['TreeNode'] = None
        self.next_sibling: Optional['TreeNode'] = None


class FirstChildNextSiblingTree:
    """Problem 1.5: First-child, next-sibling tree representation"""
    
    def __init__(self):
        self.root: Optional[TreeNode] = None
    
    def create_node(self, data: int) -> TreeNode:
        """Create a new tree node"""
        return TreeNode(data)
    
    def set_root(self, node: TreeNode):
        """Set the root of the tree"""
        self.root = node
    
    def add_child(self, parent: TreeNode, child: TreeNode):
        """Add child to parent node"""
        if not parent:
            return
        
        if not parent.first_child:
            parent.first_child = child
        else:
            sibling = parent.first_child
            while sibling.next_sibling:
                sibling = sibling.next_sibling
            sibling.next_sibling = child
    
    def get_root(self) -> Optional[TreeNode]:
        """Get the root node"""
        return self.root
    
    def get_number_of_children(self, node: TreeNode) -> int:
        """Get number of children of a node"""
        if not node or not node.first_child:
            return 0
        
        count = 0
        child = node.first_child
        while child:
            count += 1
            child = child.next_sibling
        return count
    
    def get_children(self, node: TreeNode) -> List[TreeNode]:
        """Get all children of a node"""
        children = []
        if not node or not node.first_child:
            return children
        
        child = node.first_child
        while child:
            children.append(child)
            child = child.next_sibling
        return children
    
    def preorder_traversal(self, node: Optional[TreeNode]) -> List[int]:
        """Perform preorder traversal"""
        if not node:
            return []
        
        result = [node.data]
        child = node.first_child
        while child:
            result.extend(self.preorder_traversal(child))
            child = child.next_sibling
        return result
    
    def display_tree(self):
        """Display the tree in preorder"""
        traversal = self.preorder_traversal(self.root)
        print(f"First-Child Next-Sibling Tree (Preorder): {' '.join(map(str, traversal))}")


class GraphBasedTree:
    """Problem 1.6: Graph-based tree representation verification"""
    
    def __init__(self, vertices: int):
        self.vertices = vertices
        self.adj_list = defaultdict(list)
    
    def add_edge(self, u: int, v: int):
        """Add edge between vertices u and v"""
        if 0 <= u < self.vertices and 0 <= v < self.vertices:
            self.adj_list[u].append(v)
            self.adj_list[v].append(u)
    
    def is_tree(self) -> bool:
        """Check if the graph is a tree"""
        if self.vertices <= 1:
            return True
        
        # A graph is a tree if:
        # 1. It's connected
        # 2. It has exactly n-1 edges
        # 3. It has no cycles
        
        visited = [False] * self.vertices
        edge_count = 0
        
        # DFS to check connectivity and count edges
        self._dfs_count_edges(0, visited, edge_count)
        
        # Check if all vertices are visited (connected)
        if not all(visited):
            return False
        
        # Count total edges (each edge counted twice in adjacency list)
        total_edges = sum(len(neighbors) for neighbors in self.adj_list.values()) // 2
        
        return total_edges == (self.vertices - 1)
    
    def has_cycle(self) -> bool:
        """Check if the graph has a cycle"""
        visited = [False] * self.vertices
        
        for i in range(self.vertices):
            if not visited[i]:
                if self._has_cycle_dfs(i, -1, visited):
                    return True
        return False
    
    def _dfs_count_edges(self, v: int, visited: List[bool], edge_count: int):
        """DFS helper for connectivity check"""
        visited[v] = True
        
        for neighbor in self.adj_list[v]:
            if not visited[neighbor]:
                self._dfs_count_edges(neighbor, visited, edge_count)
    
    def _has_cycle_dfs(self, v: int, parent: int, visited: List[bool]) -> bool:
        """DFS helper for cycle detection"""
        visited[v] = True
        
        for neighbor in self.adj_list[v]:
            if not visited[neighbor]:
                if self._has_cycle_dfs(neighbor, v, visited):
                    return True
            elif neighbor != parent:
                return True  # Back edge found
        return False
    
    def display(self):
        """Display the graph representation"""
        print("Graph representation:")
        for vertex in range(self.vertices):
            neighbors = self.adj_list.get(vertex, [])
            print(f"{vertex}: {' '.join(map(str, neighbors))}")


def main():
    """Main function to demonstrate all problems"""
    print("=== Graph Theory Problems 1.1-1.6 Implementation ===\n")
    
    # Problem 1.1
    print("Problem 1.1: Complete graphs and bipartite graphs")
    print(f"K5 has {GraphRepresentation.complete_graph_size(5)} edges")
    print(f"K3,4 has {GraphRepresentation.complete_bipartite_graph_size(3, 4)} edges")
    print()
    
    # Problem 1.2
    print("Problem 1.2: Bipartite conditions")
    print(f"C6 is bipartite: {'Yes' if GraphRepresentation.is_circle_graph_bipartite(6) else 'No'}")
    print(f"C5 is bipartite: {'Yes' if GraphRepresentation.is_circle_graph_bipartite(5) else 'No'}")
    print(f"K3 is bipartite: {'Yes' if GraphRepresentation.is_complete_graph_bipartite(3) else 'No'}")
    print(f"K2 is bipartite: {'Yes' if GraphRepresentation.is_complete_graph_bipartite(2) else 'No'}")
    print()
    
    # Problem 1.3
    print("Problem 1.3: Spanning trees")
    print(f"K4 has {GraphRepresentation.spanning_trees_complete(4)} spanning trees")
    print(f"K5 has {GraphRepresentation.spanning_trees_complete(5)} spanning trees")
    print()
    
    # Problem 1.4
    print("Problem 1.4: Extended adjacency matrix operations")
    ext_matrix = ExtendedAdjacencyMatrix(4)
    ext_matrix.add_edge(0, 1, 1)
    ext_matrix.add_edge(1, 2, 1)
    ext_matrix.add_edge(2, 3, 1)
    ext_matrix.add_edge(0, 3, 1)
    ext_matrix.display()
    
    edges = ext_matrix.get_edges(0)
    print(f"Edges from vertex 0: {' '.join(map(str, edges))}")
    print()
    
    # Problem 1.5
    print("Problem 1.5: First-child, next-sibling tree")
    fcns_tree = FirstChildNextSiblingTree()
    root_node = fcns_tree.create_node(1)
    child1 = fcns_tree.create_node(2)
    child2 = fcns_tree.create_node(3)
    child3 = fcns_tree.create_node(4)
    grandchild1 = fcns_tree.create_node(5)
    
    fcns_tree.set_root(root_node)
    fcns_tree.add_child(root_node, child1)
    fcns_tree.add_child(root_node, child2)
    fcns_tree.add_child(root_node, child3)
    fcns_tree.add_child(child1, grandchild1)
    
    fcns_tree.display_tree()
    print(f"Number of children of root: {fcns_tree.get_number_of_children(root_node)}")
    print()
    
    # Problem 1.6
    print("Problem 1.6: Graph-based tree verification")
    gb_tree = GraphBasedTree(4)
    gb_tree.add_edge(0, 1)
    gb_tree.add_edge(1, 2)
    gb_tree.add_edge(2, 3)
    
    gb_tree.display()
    print(f"Is tree: {'Yes' if gb_tree.is_tree() else 'No'}")
    print(f"Has cycle: {'Yes' if gb_tree.has_cycle() else 'No'}")
    
    # Add one more edge to create a cycle
    gb_tree.add_edge(0, 3)
    print("After adding edge (0,3):")
    print(f"Is tree: {'Yes' if gb_tree.is_tree() else 'No'}")
    print(f"Has cycle: {'Yes' if gb_tree.has_cycle() else 'No'}")


if __name__ == "__main__":
    main()