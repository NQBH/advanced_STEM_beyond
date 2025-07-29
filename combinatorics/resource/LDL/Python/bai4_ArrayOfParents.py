from collections import defaultdict

def build_children_list(parents):
    n = len(parents)
    children = defaultdict(list)
    root = -1
    for i in range(n):
        if parents[i] == -1:
            root = i
        else:
            children[parents[i]].append(i)
    return root, children

def fcns_representation(root, children, n):
    first_child = [-1] * n
    next_sibling = [-1] * n

    def dfs(node):
        if not children[node]:
            return
        
        first_child[node] = children[node][0]

        for i in range(len(children[node]) - 1):
            next_sibling[children[node][i]] = children[node][i + 1]
        for child in children[node]:
            dfs(child)

    dfs(root)
    return first_child, next_sibling

def edge_list(first_child, next_sibling):
    edges = []
    for i in range(len(first_child)):
        if first_child[i] != -1:
            edges.append((i, first_child[i]))
        if next_sibling[i] != -1:
            edges.append((i, next_sibling[i]))
    return edges

parents = [-1, 0, 0, 1, 1, 1, 3, 3]
#        0
#      /   \
#     1     2
#   / | \
#  3  4  5
# / \
# 6 7

n = len(parents)
root, children = build_children_list(parents)
first_child, next_sibling = fcns_representation(root, children, n)
edges = edge_list(first_child, next_sibling)

print("First-Child array:", first_child)
print("Next-Sibling array:", next_sibling)
print("Edge list:")
for u, v in edges:
    print(f"{u} -> {v}")