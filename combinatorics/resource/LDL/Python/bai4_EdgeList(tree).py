from collections import defaultdict

def edge_list_to_parents_and_fcns(edges, n, root):
    children = defaultdict(list)
    parents = [-1] * n

    for u, v in edges:
        children[u].append(v)
        parents[v] = u

    parents[root] = -1

    first_child = [-1] * n
    next_sibling = [-1] * n

    for u in range(n):
        if children[u]:
            first_child[u] = children[u][0]
            for i in range(len(children[u]) - 1):
                next_sibling[children[u][i]] = children[u][i + 1]

    return parents, first_child, next_sibling

edges = [
    (0, 1),
    (1, 3),
    (3, 6),
    (3, 7),
    (1, 4),
    (1, 5),
    (0, 2)
]
n = 8
root = 0

parents, first_child, next_sibling = edge_list_to_parents_and_fcns(edges, n, root)

print("Parents array:")
print(parents)

print("\nFirst-Child array:")
print(first_child)

print("Next-Sibling array:")
print(next_sibling)