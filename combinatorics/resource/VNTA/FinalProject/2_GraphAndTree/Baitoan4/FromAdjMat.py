from collections import defaultdict

n, type_ = map(int, input().split())
directed = (type_ == 1)

adjMatrix = [list(map(int, input().split())) for _ in range(n)]

edges = []
adj = [[] for _ in range(n)]
ogMap = [defaultdict(int) for _ in range(n)]
icMap = [defaultdict(int) for _ in range(n)]

for u in range(n):
    for v in range(n):
        k = adjMatrix[u][v]
        if k == 0:
            continue

        if directed:
            edges.append((u, v, k))
            adj[u].append((v, k))
            ogMap[u][v] += k
            icMap[v][u] += k
        else:
            if u <= v:
                edges.append((u, v, k))
                if u == v:
                    # loop edge
                    adj[u].append((v, k))
                    ogMap[u][v] += k
                    icMap[u][v] += k
                else:
                    # normal undirected edge
                    adj[u].append((v, k))
                    adj[v].append((u, k))
                    ogMap[u][v] += k
                    ogMap[v][u] += k
                    icMap[v][u] += k
                    icMap[u][v] += k

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
# 6 1
# 2 3 0 1 0 0
# 0 0 4 0 0 1
# 1 0 2 3 0 0
# 0 1 0 0 5 2
# 3 0 0 0 1 0
# 0 0 2 1 0 3
#
# Input 2: Undirected graph
# 6 0
# 2 3 1 0 2 0
# 3 1 2 4 0 2
# 1 2 3 1 2 0
# 0 4 1 2 5 1
# 2 0 2 5 2 3
# 0 2 0 1 3 4
