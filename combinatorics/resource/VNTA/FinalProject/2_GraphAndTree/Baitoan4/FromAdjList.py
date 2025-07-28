from collections import defaultdict

n, type_ = map(int, input().split())
directed = (type_ == 1)

adj = [[] for _ in range(n)]
for u in range(n):
    line = list(map(int, input().split()))
    m = line[0]
    edges = line[1:]
    for j in range(m):
        v = edges[2*j]
        k = edges[2*j + 1]
        adj[u].append((v, k))

edges = []
adjMatrix = [[0] * n for _ in range(n)]
ogMap = [defaultdict(int) for _ in range(n)]
icMap = [defaultdict(int) for _ in range(n)]

addedEdge = set()

for u in range(n):
    for v, k in adj[u]:
        adjMatrix[u][v] += k
        ogMap[u][v] += k
        icMap[v][u] += k

        if directed:
            edges.append((u, v, k))
        else:
            if u < v and (u, v) not in addedEdge:
                edges.append((u, v, k))
                addedEdge.add((u, v))
            elif u == v:
                edges.append((u, v, k))

og = [[] for _ in range(n)]
ic = [[] for _ in range(n)]

for u in range(n):
    for v, k in ogMap[u].items():
        og[u].append((v, k))
    for v, k in icMap[u].items():
        ic[u].append((v, k))

print("\nEdge List:")
for u, v, k in edges:
    print(u, v, k)

print("\nAdjacency Matrix:")
for i in range(n):
    print(' '.join(str(adjMatrix[i][j]) for j in range(n)))

print("\nAdjacency Map (Incoming - ic):")
for u in range(n):
    print(f"{u}: ", end='')
    for v, k in ic[u]:
        print(f"{{{v},{k}}} ", end='')
    print()

print("\nAdjacency Map (Outgoing - og):")
for u in range(n):
    print(f"{u}: ", end='')
    for v, k in og[u]:
        print(f"{{{v},{k}}} ", end='')
    print()

# Input 1: Directed graph
# 6 1
# 3 0 2 1 3 3 1
# 2 2 4 5 1
# 3 0 1 2 2 3 3
# 3 1 1 4 5 5 2
# 2 0 3 4 1
# 3 2 2 3 1 5 3

# Input 2: Undirected graph
# 6 0
# 4 0 2 1 3 2 1 4 2
# 5 0 3 1 1 2 2 3 4 5 2
# 5 0 1 1 2 2 3 3 1 4 2
# 5 1 4 2 1 3 2 4 5 5 1
# 5 0 2 2 2 3 5 4 2 5 3
# 4 1 2 3 1 4 3 5 4