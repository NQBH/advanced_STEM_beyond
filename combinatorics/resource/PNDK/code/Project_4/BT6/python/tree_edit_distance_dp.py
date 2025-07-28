import sys
from collections import deque

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None
        self.children = []  # For general tree
        self.id = 0

def read_tree(filename):
    try:
        with open(filename, 'r') as f:
            n = int(f.readline().strip())
            if n == 0:
                return None
            edges = []
            for _ in range(n):
                line = list(map(int, f.readline().strip().split()))
                edges.append(line)
        return build_tree_from_edges(edges)
    except:
        return None

def build_tree_from_edges(edges):
    if not edges:
        return None
    
    nodes = {}
    children_set = set()
    
    # Create all nodes
    for parent, left, right in edges:
        if parent not in nodes:
            nodes[parent] = TreeNode(parent)
        if left != -1:
            if left not in nodes:
                nodes[left] = TreeNode(left)
            nodes[parent].left = nodes[left]
            children_set.add(left)
        if right != -1:
            if right not in nodes:
                nodes[right] = TreeNode(right)
            nodes[parent].right = nodes[right]
            children_set.add(right)
    
    # Find root
    root = None
    for val in nodes:
        if val not in children_set:
            root = nodes[val]
            break
    
    return root

def inorder_threading(root, nodes_list):
    """Left-child right-sibling representation"""
    if not root:
        return
    
    # Convert to left-child right-sibling format
    def convert(node):
        if not node:
            return None
        new_node = TreeNode(node.val)
        if node.left:
            new_node.left = convert(node.left)
        if node.right:
            new_node.left = convert(node.right)
        return new_node
    
    # Get postorder traversal
    def postorder(node, result):
        if node:
            postorder(node.left, result)
            postorder(node.right, result)
            result.append(node)
    
    postorder_list = []
    postorder(root, postorder_list)
    return postorder_list

def tree_size(node):
    if not node:
        return 0
    return 1 + tree_size(node.left) + tree_size(node.right)

def ted_dp(T1, T2):
    """Tree Edit Distance using Dynamic Programming"""
    if not T1 and not T2:
        return 0
    if not T1:
        return tree_size(T2)
    if not T2:
        return tree_size(T1)
    
    # Simple recursive approach (exponential - for demonstration)
    def cost_relabel(n1, n2):
        return 0 if n1.val == n2.val else 1
    
    def ted_recursive(t1, t2):
        if not t1 and not t2:
            return 0
        if not t1:
            return tree_size(t2)
        if not t2:
            return tree_size(t1)
        
        # Four operations:
        # 1. Relabel
        cost1 = cost_relabel(t1, t2) + ted_recursive(t1.left, t2.left) + ted_recursive(t1.right, t2.right)
        
        # 2. Delete t1
        cost2 = 1 + ted_recursive(t1.left, t2) + ted_recursive(t1.right, t2)
        
        # 3. Insert t2
        cost3 = 1 + ted_recursive(t1, t2.left) + ted_recursive(t1, t2.right)
        
        return min(cost1, cost2, cost3)
    
    return ted_recursive(T1, T2)

def main():
    T1 = read_tree('../tree1.inp')
    T2 = read_tree('../tree2.inp')
    
    distance = ted_dp(T1, T2)
    print(f"Dynamic Programming - Tree Edit Distance: {distance}")
    print("Done")

if __name__ == "__main__":
    main()