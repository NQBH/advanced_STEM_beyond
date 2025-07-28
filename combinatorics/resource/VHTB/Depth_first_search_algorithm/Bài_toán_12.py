def dfs_multigraph(adj, u, visited=None, result=None):
    if visited is None:
        visited = set()
    if result is None:
        result = []
    visited.add(u)
    result.append(u)
    for v in adj[u]:
        if v not in visited:
            dfs_multigraph(adj, v, visited, result)
    return result

graph = {
    0: [1, 1, 2],
    1: [0, 0, 2],
    2: [0, 1, 2],  # self-loop at 2
    3: []
}

print("DFS traversal:", dfs_multigraph(graph, 0))
