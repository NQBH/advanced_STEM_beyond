def dfs_simple_graph(adj, start, visited=None, result=None):
    if visited is None:
        visited = set()
    if result is None:
        result = []
    visited.add(start)
    result.append(start)
    for neighbor in adj[start]:
        if neighbor not in visited:
            dfs_simple_graph(adj, neighbor, visited, result)
    return result

graph = {
    0: [1, 2],
    1: [0, 3],
    2: [0],
    3: [1]
}

print("DFS traversal:", dfs_simple_graph(graph, 0))
