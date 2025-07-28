def dfs_component(u, adj, visited, component):
    visited.add(u)
    component.append(u)
    for v in adj[u]:
        if v not in visited:
            dfs_component(v, adj, visited, component)

def general_dfs(adj):
    n = len(adj)
    visited = set()
    components = []

    for u in range(n):
        if u not in visited:
            comp = []
            dfs_component(u, adj, visited, comp)
            components.append(comp)
    return components

graph = {
    0: [1, 1],
    1: [0, 2],
    2: [1, 2],
    3: [],
    4: [5],
    5: [4]
}

result = general_dfs(graph)
for i, comp in enumerate(result):
    print(f"Component {i+1}:", comp)
