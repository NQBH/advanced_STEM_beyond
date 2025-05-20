#BFS

from collections import deque

def bfs_all_paths(graph, start, target):
    queue = deque([(start, [start])])
    all_paths = []
    
    while queue:
        current, path = queue.popleft()
        
        if current == target:
            all_paths.append(path)
            continue
            
        for neighbor in graph[current]:
            if neighbor not in path: 
                queue.append((neighbor, path + [neighbor]))
    
    return all_paths

n, v_s, v_t = 8, 1, 5
graph = [[] for _ in range(n + 1)]
neighbors = [
    [2, 3],  # Node 1
    [3, 4],  # Node 2
    [1, 5],  # Node 3
    [6],     # Node 4
    [],      # Node 5
    [2],     # Node 6
    [8],     # Node 7
    []       # Node 8
]

for i in range(1, n + 1):
    graph[i].extend(neighbors[i-1])

all_paths = bfs_all_paths(graph, v_s, v_t)

if all_paths:
    print(f"All paths from {v_s} to {v_t}:")
    for path in all_paths:
        print(" -> ".join(map(str, path)))
else:
    print(f"No path found from {v_s} to {v_t}.")