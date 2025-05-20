from collections import defaultdict

edges = [(1, 2), (1, 3), (1, 5), (2, 3), (2, 5), (3, 4), (3, 5), (4, 5)]
graph = defaultdict(list)
used = {}
total_paths = 0

def prepare_graph():
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
        used[(min(u, v), max(u, v))] = False
    for node in graph:
        graph[node].sort()

def dfs(path, used_edges):
    global total_paths
    if used_edges == 8:
        print(''.join(map(str, path)))
        total_paths += 1
        return
    u = path[-1]
    for v in graph[u]:
        edge = (min(u, v), max(u, v))
        if not used[edge]:
            used[edge] = True
            path.append(v)
            dfs(path, used_edges + 1)
            path.pop()
            used[edge] = False

prepare_graph()
dfs([1], 0)
print(f"Total valid paths: {total_paths}")