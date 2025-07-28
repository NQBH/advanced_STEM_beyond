from collections import deque

def bfs_multigraph(adj, start):
    visited = set()
    queue = deque([start])
    order = []

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            order.append(node)
            for neighbor in adj[node]:
                if neighbor not in visited:
                    queue.append(neighbor)
    return order

graph = {
    0: [1, 1, 2],
    1: [0, 0, 2],
    2: [0, 1, 3],
    3: [2]
}

print("BFS traversal:", bfs_multigraph(graph, 0))
