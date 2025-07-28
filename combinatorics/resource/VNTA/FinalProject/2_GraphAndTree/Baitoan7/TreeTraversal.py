from collections import deque

class Node:
    def __init__(self, val):
        self.val = val
        self.children = []

nodes = {}

m = int(input())
edges = []
children_set = set()

for _ in range(m):
    u, v = input().split()
    edges.append((u, v))
    children_set.add(v)

    if u not in nodes:
        nodes[u] = Node(u)
    if v not in nodes:
        nodes[v] = Node(v)
    nodes[u].children.append(nodes[v])

# Tìm root
root = None
for label in nodes:
    if label not in children_set:
        root = nodes[label]
        break

if root is None:
    print("Khong tim thay root.")
    exit(1)

def preorder(root):
    if not root:
        return
    print(root.val, end=' ')
    for child in root.children:
        preorder(child)

def postorder(root):
    if not root:
        return
    for child in root.children:
        postorder(child)
    print(root.val, end=' ')

def top_down(root):
    if not root:
        return
    q = deque([root])
    while q:
        cur = q.popleft()
        print(cur.val, end=' ')
        for child in cur.children:
            q.append(child)

def bottom_up(root):
    if not root:
        return
    q = deque([root])
    levels = []
    while q:
        sz = len(q)
        level = []
        for _ in range(sz):
            cur = q.popleft()
            level.append(cur.val)
            for child in cur.children:
                q.append(child)
        levels.append(level)
    for level in reversed(levels):
        for val in level:
            print(val, end=' ')

print("\n(a) Preorder  : ", end='')
preorder(root)
print()

print("(b) Postorder : ", end='')
postorder(root)
print()

print("(c) Top-down  : ", end='')
top_down(root)
print()

print("(d) Bottom-up : ", end='')
bottom_up(root)
print()