from collections import defaultdict

n, m, type_ = map(int, input().split())
directed = (type_ == 1)

edges = []
for _ in range(m):
    u, v, k = map(int, input().split())
    edges.append((u, v, k))

adjMatrix = [[0]*n for _ in range(n)]
adj = [[] for _ in range(n)]
ogMap = [defaultdict(int) for _ in range(n)]
icMap = [defaultdict(int) for _ in range(n)]

for u, v, k in edges:
    # Adjacency matrix
    adjMatrix[u][v] += k
    if not directed and u != v:
        adjMatrix[v][u] += k

    # Adjacency list
    adj[u].append((v, k))
    if not directed and u != v:
        adj[v].append((u, k))

    # Adjacency map
    ogMap[u][v] += k
    icMap[v][u] += k
    if not directed and u != v:
        ogMap[v][u] += k
        icMap[u][v] += k

og = [[] for _ in range(n)]
ic = [[] for _ in range(n)]
for u in range(n):
    for v, k in ogMap[u].items():
        og[u].append((v, k))
    for v, k in icMap[u].items():
        ic[u].append((v, k))

print("\nAdjacency Matrix:")
for i in range(n):
    print(" ".join(map(str, adjMatrix[i])))

print("\nAdjacency List:")
for u in range(n):
    print(f"{u}: ", end="")
    for v, k in adj[u]:
        print(f"{{{v},{k}}} ", end="")
    print()

print("\nAdjacency Map (Incoming - ic):")
for u in range(n):
    print(f"{u}: ", end="")
    for v, k in ic[u]:
        print(f"{{{v},{k}}} ", end="")
    print()

print("\nAdjacency Map (Outgoing - og):")
for u in range(n):
    print(f"{u}: ", end="")
    for v, k in og[u]:
        print(f"{{{v},{k}}} ", end="")
    print()

# Input 1: Directed graph
# 6 16 1
# 0 0 2
# 0 1 3
# 0 3 1
# 1 2 4
# 1 5 1
# 2 0 1
# 2 2 2
# 2 3 3
# 3 1 1
# 3 4 5
# 3 5 2
# 4 0 3
# 4 4 1
# 5 2 2
# 5 3 1
# 5 5 3
#
# Input 2: Undirected graph
# 6 17 0
# 0 0 2
# 0 1 3
# 0 2 1
# 0 4 2
# 1 1 1
# 1 2 2
# 1 3 4
# 1 5 2
# 2 2 3
# 2 3 1
# 2 4 2
# 3 3 2
# 3 4 5
# 3 5 1
# 4 4 2
# 4 5 3
# 5 5 4
