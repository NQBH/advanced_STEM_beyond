class Node:
    def __init__(self, label, children=None):
        self.label = label
        self.children = children or []

def preorder(node, result):
    if node:
        result.append(node.label)
        for child in node.children:
            preorder(child, result)

def postorder(node, result):
    if node:
        for child in node.children:
            postorder(child, result)
        result.append(node.label)

def top_down(node):
    if not node: return []
    result = []
    queue = [node]
    while queue:
        current = queue.pop(0)
        result.append(current.label)
        queue.extend(current.children)
    return result

# Bottom-up
def bottom_up(node):
    if not node: return []
    result = []
    queue = [node]
    levels = []
    while queue:
        level = []
        next_queue = []
        for current in queue:
            level.append(current.label)
            next_queue.extend(current.children)
        levels.append(level)
        queue = next_queue
    result = []
    for level in reversed(levels):
        result.extend(level)
    return result

T = Node('A', [
    Node('B', [Node('D'), Node('E')]),
    Node('C', [Node('F')])
])

pre, post = [], []
preorder(T, pre)
postorder(T, post)

print("Preorder:", pre)
print("Postorder:", post)
print("Top-down:", top_down(T))
print("Bottom-up:", bottom_up(T))
