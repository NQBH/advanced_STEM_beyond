from typing import List, Optional
from collections import defaultdict

class ArrayOfParents:
    """Array of Parents representation của tree"""
    
    def __init__(self, num_nodes: int):
        self.num_nodes = num_nodes
        self.parent = [-1] * num_nodes  # parent[v] = parent của v, hoặc -1 nếu root
        self.root_node = -1
    
    def set_parent(self, child: int, parent: int):
        if 0 <= child < self.num_nodes:
            self.parent[child] = parent
    
    def set_root(self, root: int):
        if 0 <= root < self.num_nodes:
            self.root_node = root
            self.parent[root] = -1
    
    def get_parent(self, v: int) -> int:
        if 0 <= v < self.num_nodes:
            return self.parent[v]
        return -1
    
    def is_root(self, v: int) -> bool:
        return 0 <= v < self.num_nodes and self.parent[v] == -1
    
    def get_root(self) -> int:
        if self.root_node != -1:
            return self.root_node
        
        # Tìm root bằng cách scan array
        for i in range(self.num_nodes):
            if self.parent[i] == -1:
                return i
        return -1
    
    def get_children(self, v: int) -> List[int]:
        children = []
        for i in range(self.num_nodes):
            if self.parent[i] == v:
                children.append(i)
        return children
    
    def display(self):
        print("Array of Parents:")
        for i in range(self.num_nodes):
            print(f"Node {i}: parent = {self.parent[i]}")


class FirstChildNextSibling:
    """First-Child Next-Sibling representation của tree"""
    
    def __init__(self, num_nodes: int):
        self.num_nodes = num_nodes
        self.first_child = [-1] * num_nodes   
        self.next_sibling = [-1] * num_nodes 
        self.root_node = -1
    
    def set_first_child(self, parent: int, child: int):
        if 0 <= parent < self.num_nodes:
            self.first_child[parent] = child
    
    def set_next_sibling(self, current: int, next_node: int):
        if 0 <= current < self.num_nodes:
            self.next_sibling[current] = next_node
    
    def set_root(self, root: int):
        self.root_node = root
    
    def get_first_child(self, v: int) -> int:
        if 0 <= v < self.num_nodes:
            return self.first_child[v]
        return -1
    
    def get_next_sibling(self, v: int) -> int:
        if 0 <= v < self.num_nodes:
            return self.next_sibling[v]
        return -1
    
    def is_leaf(self, v: int) -> bool:
        return 0 <= v < self.num_nodes and self.first_child[v] == -1
    
    def is_last_child(self, v: int) -> bool:
        return 0 <= v < self.num_nodes and self.next_sibling[v] == -1
    
    def get_root(self) -> int:
        return self.root_node
    
    def get_children(self, v: int) -> List[int]:
        children = []
        child = self.first_child[v]
        while child != -1:
            children.append(child)
            child = self.next_sibling[child]
        return children
    
    def get_parent(self, v: int) -> int:
        """O(n) operation - scan để tìm parent"""
        for i in range(self.num_nodes):
            child = self.first_child[i]
            while child != -1:
                if child == v:
                    return i
                child = self.next_sibling[child]
        return -1
    
    def display(self):
        print("First-Child Next-Sibling:")
        for i in range(self.num_nodes):
            print(f"Node {i}: first_child = {self.first_child[i]}, next_sibling = {self.next_sibling[i]}")


class GraphBasedTree:
    """Graph-Based representation của tree"""
    
    def __init__(self, num_nodes: int):
        self.num_nodes = num_nodes
        self.children = [[] for _ in range(num_nodes)]  # adjacency list cho children
        self.parent = [-1] * num_nodes                  # parent[v] = parent của v, hoặc -1 nếu root
        self.root_node = -1
    
    def add_edge(self, parent: int, child: int):
        if 0 <= parent < self.num_nodes and 0 <= child < self.num_nodes:
            self.children[parent].append(child)
            self.parent[child] = parent
    
    def set_root(self, root: int):
        if 0 <= root < self.num_nodes:
            self.root_node = root
            self.parent[root] = -1
    
    def get_parent(self, v: int) -> int:
        if 0 <= v < self.num_nodes:
            return self.parent[v]
        return -1
    
    def get_children(self, v: int) -> List[int]:
        if 0 <= v < self.num_nodes:
            return self.children[v].copy()
        return []
    
    def is_root(self, v: int) -> bool:
        return 0 <= v < self.num_nodes and self.parent[v] == -1
    
    def is_leaf(self, v: int) -> bool:
        return 0 <= v < self.num_nodes and len(self.children[v]) == 0
    
    def get_root(self) -> int:
        if self.root_node != -1:
            return self.root_node
        
        # Tìm root
        for i in range(self.num_nodes):
            if self.parent[i] == -1:
                return i
        return -1
    
    def get_first_child(self, v: int) -> int:
        if 0 <= v < self.num_nodes and len(self.children[v]) > 0:
            return self.children[v][0]
        return -1
    
    def display(self):
        print("Graph-Based Tree:")
        for i in range(self.num_nodes):
            print(f"Node {i}: children = {self.children[i]}, parent = {self.parent[i]}")


# =====================================================
# 6 TREE CONVERTERS
# =====================================================

def array_of_parents_to_first_child_next_sibling(ap: ArrayOfParents) -> FirstChildNextSibling:
    """CONVERTER 1: Array of Parents → First-Child Next-Sibling"""
    n = ap.num_nodes
    fcns = FirstChildNextSibling(n)
    
    # Build children lists cho mỗi node
    children_lists = [[] for _ in range(n)]
    for i in range(n):
        parent = ap.get_parent(i)
        if parent != -1:
            children_lists[parent].append(i)
    
    # Set root
    fcns.set_root(ap.get_root())
    
    # Build first-child và next-sibling links
    for u in range(n):
        if children_lists[u]:
            # Sort children cho consistent ordering
            children_lists[u].sort()
            
            # Set first child
            fcns.set_first_child(u, children_lists[u][0])
            
            # Set next-sibling links
            for i in range(len(children_lists[u]) - 1):
                fcns.set_next_sibling(children_lists[u][i], children_lists[u][i + 1])
            # Last child's next_sibling remains -1
    
    return fcns


def first_child_next_sibling_to_array_of_parents(fcns: FirstChildNextSibling) -> ArrayOfParents:
    """CONVERTER 2: First-Child Next-Sibling → Array of Parents"""
    n = fcns.num_nodes
    ap = ArrayOfParents(n)
    
    # Set root
    root = fcns.get_root()
    if root != -1:
        ap.set_root(root)
    
    # DFS để set parent relationships
    def dfs(node: int, parent: int):
        ap.set_parent(node, parent)
        
        # Visit all children
        child = fcns.get_first_child(node)
        while child != -1:
            dfs(child, node)
            child = fcns.get_next_sibling(child)
    
    if root != -1:
        dfs(root, -1)
    
    return ap


def array_of_parents_to_graph_based(ap: ArrayOfParents) -> GraphBasedTree:
    """CONVERTER 3: Array of Parents → Graph-Based"""
    n = ap.num_nodes
    gt = GraphBasedTree(n)
    
    # Set root
    root = ap.get_root()
    if root != -1:
        gt.set_root(root)
    
    # Add edges từ parent đến children
    for i in range(n):
        parent = ap.get_parent(i)
        if parent != -1:
            gt.add_edge(parent, i)
    
    return gt


def graph_based_to_array_of_parents(gt: GraphBasedTree) -> ArrayOfParents:
    """CONVERTER 4: Graph-Based → Array of Parents"""
    n = gt.num_nodes
    ap = ArrayOfParents(n)
    
    # Set root
    root = gt.get_root()
    if root != -1:
        ap.set_root(root)
    
    # Extract parent relationships
    for i in range(n):
        parent = gt.get_parent(i)
        ap.set_parent(i, parent)
    
    return ap


def first_child_next_sibling_to_graph_based(fcns: FirstChildNextSibling) -> GraphBasedTree:
    """CONVERTER 5: First-Child Next-Sibling → Graph-Based"""
    n = fcns.num_nodes
    gt = GraphBasedTree(n)
    
    # Set root
    root = fcns.get_root()
    if root != -1:
        gt.set_root(root)
    
    # DFS để build edges
    def dfs(node: int, parent: int):
        if parent != -1:
            gt.add_edge(parent, node)
        
        # Visit all children
        child = fcns.get_first_child(node)
        while child != -1:
            dfs(child, node)
            child = fcns.get_next_sibling(child)
    
    if root != -1:
        dfs(root, -1)
    
    return gt


def graph_based_to_first_child_next_sibling(gt: GraphBasedTree) -> FirstChildNextSibling:
    """CONVERTER 6: Graph-Based → First-Child Next-Sibling"""
    n = gt.num_nodes
    fcns = FirstChildNextSibling(n)
    
    # Set root
    root = gt.get_root()
    if root != -1:
        fcns.set_root(root)
    
    # Build first-child và next-sibling links
    for u in range(n):
        children = gt.get_children(u)
        
        if children:
            # Sort children cho consistent ordering
            children.sort()
            
            # Set first child
            fcns.set_first_child(u, children[0])
            
            # Set next-sibling links
            for i in range(len(children) - 1):
                fcns.set_next_sibling(children[i], children[i + 1])
            # Last child's next_sibling remains -1
    
    return fcns


# =====================================================
# FILE READER FOR TREES
# =====================================================
def read_tree_from_file(filename: str) -> ArrayOfParents:
    try:
        with open(filename, 'r') as file:
            lines = file.readlines()
        
        num_nodes = int(lines[0].strip())
        tree = ArrayOfParents(num_nodes)
        
        for i in range(1, len(lines)):
            line = lines[i].strip()
            if not line:
                continue
            
            parts = line.split()
            if len(parts) >= 2:
                if parts[0] == "root":
                    root = int(parts[1])
                    tree.set_root(root)
                    print(f"Set root: {root}")
                elif parts[0] == "edge" and len(parts) >= 3:
                    parent = int(parts[1])
                    child = int(parts[2])
                    tree.set_parent(child, parent)
                    print(f"Added edge: {parent} -> {child}")
        
        return tree
        
    except FileNotFoundError:
        print(f"Cannot open file: {filename}")
        return ArrayOfParents(0)
    except Exception as e:
        print(f"Error reading file: {e}")
        return ArrayOfParents(0)


def test_all_tree_converters():
    print("TEST: All 6 Tree Representation Converters")
    print("===========================================")
    
    original = read_tree_from_file("..\tree_sample.inp")

    original.display()
    
    # Test from Array of Parents
    print("\n=== 1. FROM ARRAY OF PARENTS ===")
    fcns_result = array_of_parents_to_first_child_next_sibling(original)
    gt_result = array_of_parents_to_graph_based(original)
    
    print("1.1. ArrayOfParents → FirstChildNextSibling:")
    fcns_result.display()
    print("1.2. ArrayOfParents → GraphBased:")
    gt_result.display()
    
    # Test from First-Child Next-Sibling
    print("\n=== 2. FROM FIRST-CHILD NEXT-SIBLING ===")
    print("2.1. FirstChildNextSibling → ArrayOfParents:")
    first_child_next_sibling_to_array_of_parents(fcns_result).display()
    print("2.2. FirstChildNextSibling → GraphBased:")
    first_child_next_sibling_to_graph_based(fcns_result).display()
    
    # Test from Graph-Based
    print("\n=== 3. FROM GRAPH-BASED ===")
    print("3.1. GraphBased → ArrayOfParents:")
    graph_based_to_array_of_parents(gt_result).display()
    print("3.2. GraphBased → FirstChildNextSibling:")
    graph_based_to_first_child_next_sibling(gt_result).display()
    
    print("\nDONE")


if __name__ == "__main__":
    test_all_tree_converters()