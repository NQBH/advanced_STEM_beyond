from collections import defaultdict, deque
import time

edges = [
    (1, 2), (2, 3), (3, 5), (5, 1),
    (5, 4), (4, 3), (1, 3), (2, 5)
]

graph = defaultdict(list)
edge_list = set()
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)
    edge_list.add((min(u, v), max(u, v)))

edge_count = len(edge_list)

# -------------------- DFS Version --------------------
def dfs_all_paths(start):
    paths = []

    def dfs(path, used_edges):
        current = path[-1]
        if len(used_edges) == edge_count:
            paths.append(path.copy())
            return
        for neighbor in graph[current]:
            edge = (min(current, neighbor), max(current, neighbor))
            if edge not in used_edges:
                used_edges.add(edge)
                path.append(neighbor)
                dfs(path, used_edges)
                path.pop()
                used_edges.remove(edge)

    dfs([start], set())
    return paths

# -------------------- BFS Version --------------------
def bfs_all_paths(start):
    paths = []
    queue = deque()
    queue.append(([start], set()))

    while queue:
        path, used_edges = queue.popleft()
        current = path[-1]

        if len(used_edges) == edge_count:
            paths.append(path)
            continue

        for neighbor in graph[current]:
            edge = (min(current, neighbor), max(current, neighbor))
            if edge not in used_edges:
                new_path = path + [neighbor]
                new_used = used_edges.copy()
                new_used.add(edge)
                queue.append((new_path, new_used))
    return paths

# -------------------- Run and Print --------------------
for name, func in [("DFS", dfs_all_paths), ("BFS", bfs_all_paths)]:
    print(f"\n{name} Search Paths:")
    start_time = time.time()
    all_paths = func(1)
    duration = time.time() - start_time

    for idx, path in enumerate(all_paths, 1):
        print(f"Path {idx}: {' -> '.join(map(str, path))}")

    print(f"\n{name} found {len(all_paths)} Eulerian paths in {duration:.6f} seconds.")