from collections import defaultdict, deque

def build_tree_from_parents(parents):
    tree = defaultdict(list)
    root = -1
    for child, parent in enumerate(parents):
        if parent == -1:
            root = child
        else:
            tree[parent].append(child)
    return tree, root

def preorder(tree, node):
    print(node, end=' ')
    for child in tree[node]:
        preorder(tree, child)

def postorder(tree, node):
    for child in tree[node]:
        postorder(tree, child)
    print(node, end=' ')

def top_down(tree, root):
    queue = deque([root])
    while queue:
        node = queue.popleft()
        print(node, end=' ')
        for child in tree[node]:
            queue.append(child)

def bottom_up(tree, root):
    levels = defaultdict(list)
    max_level = 0
    queue = deque([(root, 0)])

    while queue:
        node, level = queue.popleft()
        levels[level].append(node)
        max_level = max(max_level, level)
        for child in tree[node]:
            queue.append((child, level + 1))

    for level in reversed(range(max_level + 1)):
        for node in levels[level]:
            print(node, end=' ')


print("Nhap mang cha (-1 cho root):")
parents = list(map(int, input().split()))

tree, root = build_tree_from_parents(parents)

print("Duyet preorder:")
preorder(tree, root)
print("\nDuyet postorder:")
postorder(tree, root)
print("\nDuyet top-down:")
top_down(tree, root)
print("\nDuyet bottom-up:")
bottom_up(tree, root)