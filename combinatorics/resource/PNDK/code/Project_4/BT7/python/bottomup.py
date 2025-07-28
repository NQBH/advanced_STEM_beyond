from collections import deque

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
    
    # Find root
    root_val = None
    for val in nodes:
        if val not in children:
            root_val = val
            break
    
    return nodes[root_val] if root_val else None

def bottomup(root):
    if not root:
        return
    q = deque([root])
    result = []
    while q:
        node = q.popleft()
        result.append(node.val)
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)
    result.reverse()
    print(" ".join(map(str, result)))

# Read input from file
try:
    with open('../tree_sample.inp', 'r') as f:
        n = int(f.readline().strip())
        edges = []
        for _ in range(n):
            line = list(map(int, f.readline().strip().split()))
            edges.append(line)
    
    root = build_tree(edges)
    print("Bottom-up:")
    bottomup(root)
    print("\nDone")
    
except FileNotFoundError:
    print("Error: tree_sample.inp not found")
except Exception as e:
    print(f"Error: {e}")