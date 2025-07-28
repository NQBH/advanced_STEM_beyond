from collections import defaultdict

n, type_ = map(int, input().split())
directed = (type_ == 1)

ogMap = [defaultdict(int) for _ in range(n)]
icMap = [defaultdict(int) for _ in range(n)]

# Input: outgoing map
for u in range(n):
    line = list(map(int, input().split()))
    m = line[0]
    data = line[1:]
    for j in range(m):
        v = data[2*j]
        k = data[2*j + 1]
        ogMap[u][v] += k
        icMap[v][u] += k

edges = []
adjMatrix = [[0]*n for _ in range(n)]
adj = [[] for _ in range(n)]

added = set()

for u in range(n):
    for v, k in ogMap[u].items():
        adjMatrix[u][v] += k

        if directed:
            edges.append((u, v, k))
            adj[u].append((v, k))
        else:
            if u == v:
                edges.append((u, v, k))
                adj[u].append((v, k))
            elif u < v and (u, v) not in added:
                edges.append((u, v, k))
                adj[u].append((v, k))
                adj[v].append((u, k))
                added.add((u, v))

print("\nAdjacency Map (Incoming - ic):")
for u in range(n):
    print(f"{u}: ", end="")
    for v, k in icMap[u].items():
        print(f"{{{v},{k}}} ", end="")
    print()

print("\nEdge List:")
for u, v, k in edges:
    print(u, v, k)

print("\nAdjacency Matrix:")
for i in range(n):
    print(" ".join(str(adjMatrix[i][j]) for j in range(n)))

print("\nAdjacency List:")
for u in range(n):
    print(f"{u}: ", end="")
    for v, k in adj[u]:
        print(f"{{{v},{k}}} ", end="")
    print()

# Input 1: Directed graph
# 6 1
# 3 3 1 0 2 1 3
# 2 5 1 2 4
# 3 3 3 0 1 2 2
# 3 5 2 1 1 4 5
# 2 4 1 0 3
# 3 5 3 2 2 3 1
#
# Input 2: Undirected graph
# 6 0
# 4 4 2 2 1 0 2 1 3
# 5 3 4 2 2 5 2 0 3 1 1
# 5 4 2 3 1 2 3 0 1 1 2
# 5 5 1 4 5 3 2 1 4 2 1
# 5 4 2 3 5 5 3 0 2 2 2
# 4 5 4 4 3 1 2 3 1