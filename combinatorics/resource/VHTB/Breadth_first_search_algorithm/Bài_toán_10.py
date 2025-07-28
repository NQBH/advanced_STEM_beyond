from collections import deque

def bfs_general(graph):
    n = len(graph)
    visited = set()
    components = []

    for start in range(n):
        if start not in visited:
            queue = deque([start])
            component = []
            while queue:
                node = queue.popleft()
                if node not in visited:
                    visited.add(node)
                    component.append(node)
                    for neighbor in graph[node]:
                        if neighbor not in visited:
                            queue.append(neighbor)
            components.append(component)
    return components

graph = {
    0: [1, 1],
    1: [0, 2],
    2: [1, 2],
    3: [],
    4: [5],
    5: [4]
}

print("All BFS components:")
for i, comp in enumerate(bfs_general(graph)):
    print(f"Component {i+1}:", comp)
