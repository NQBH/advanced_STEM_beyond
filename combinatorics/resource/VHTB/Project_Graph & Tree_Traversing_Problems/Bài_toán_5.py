def dfs(adj, visited, u):
    visited[u] = True
    for v in adj[u]:
        if not visited[v]:
            dfs(adj, visited, v)

def is_connected(adj, n):
    visited = [False] * n
    dfs(adj, visited, 0)
    return all(visited)

def is_tree(adj, n):
    visited = [False] * n
    parent = [-1] * n

    def dfs_tree(u):
        visited[u] = True
        for v in adj[u]:
            if not visited[v]:
                parent[v] = u
                if not dfs_tree(v):
                    return False
            elif parent[u] != v:
                return False
        return True

    if not dfs_tree(0):
        return False
    return all(visited)

def count_components(adj, n):
    visited = [False] * n
    count = 0
    for i in range(n):
        if not visited[i]:
            dfs(adj, visited, i)
            count += 1
    return count

adj = {
    0: [1], 1: [0, 2], 2: [1], 3: []
}
n = 4
print("Connected:", is_connected(adj, n))
print("Is Tree:", is_tree(adj, n))
print("Components:", count_components(adj, n))
