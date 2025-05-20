def dfs_all_paths(graph, current, target, visited, path, all_paths):
    visited[current] = True
    path.append(current)

    if current == target:
        all_paths.append(list(path))
    else:
        for neighbor in graph[current]:
            if not visited[neighbor]:
                dfs_all_paths(graph, neighbor, target, visited, path, all_paths)

    path.pop()      
    visited[current] = False  


n, v_s, v_t = map(int, input().split())

graph = [[] for _ in range(n + 1)]
for i in range(1, n + 1):
    neighbors = list(map(int, input().split()))
    graph[i].extend(neighbors)

visited = [False] * (n + 1)
all_paths = []

dfs_all_paths(graph, v_s, v_t, visited, [], all_paths)

if all_paths:
    print(f"All paths from {v_s} to {v_t}:")
    for path in all_paths:
        print(" -> ".join(map(str, path)))
else:
    print(f"No path found from {v_s} to {v_t}.")