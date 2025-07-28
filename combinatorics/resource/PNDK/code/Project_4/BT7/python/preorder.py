class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build_tree(edges):
    if not edges:
        return None
    
    nodes = {}
    children = set()
    
    for parent, left, right in edges:
        if parent not in nodes:
            nodes[parent] = Node(parent)
        if left != -1:
            if left not in nodes:
                nodes[left] = Node(left)
            nodes[parent].left = nodes[left]
            children.add(left)
        if right != -1:
            if right not in nodes:
                nodes[right] = Node(right)
            nodes[parent].right = nodes[right]
            children.add(right)
    
    root_val = None
    for val in nodes:
        if val not in children:
            root_val = val
            break
    
    return nodes[root_val] if root_val else None

def preorder(root):
    if root:
        print(root.val, end=" ")
        preorder(root.left)
        preorder(root.right)
    with open('../tree_sample.inp', 'r') as f:
        n = int(f.readline().strip())
        edges = []
        for _ in range(n):
            line = list(map(int, f.readline().strip().split()))
            edges.append(line)
    
    root = build_tree(edges)
    print("Preorder:")
    preorder(root)
    print("\nDone")
