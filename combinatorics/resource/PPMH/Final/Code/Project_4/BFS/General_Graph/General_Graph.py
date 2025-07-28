from collections import deque, defaultdict

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)
    order = []

    while queue:
        node = queue.popleft()
        order.append(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    return order

graph = defaultdict(list)
graph['A'].extend(['B', 'C'])
graph['B'].extend(['D', 'E'])
graph['C'].extend(['F'])
graph['D'].extend([])
graph['E'].extend(['F'])
graph['F'].extend([])

print("Thứ tự duyệt BFS:", bfs(graph, 'A'))