def fcns_to_parents_and_tree_edges(root, first_child, next_sibling):
    n = len(first_child)
    parents = [-1] * n
    tree_edges = []

    def traverse(node):
        child = first_child[node]
        while child != -1:
            parents[child] = node
            tree_edges.append((node, child))
            traverse(child)
            child = next_sibling[child]

    traverse(root)
    return parents, tree_edges

first_child = [1, 3, -1, 6, -1, -1, -1, -1]
next_sibling = [-1, 2, -1, 4, 5, -1, 7, -1]
root = 0

parents, edge_list = fcns_to_parents_and_tree_edges(root, first_child, next_sibling)

print("\nArray of parents:")
print(parents)
print("\nEdge List:")
for u, v in edge_list:
    print(f"{u} -> {v}")