# dùng đệ quy
def dfs_recursive(graph, start, visited=None):
    if visited is None:
        visited = set()

    print(start, end=' ')
    visited.add(start)

    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited)

graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

print("DFS bắt đầu từ đỉnh A:")
dfs_recursive(graph, 'A')