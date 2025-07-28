NIL = -1

n = int(input())
parent = list(map(int, input().split()))

root = NIL
for i in range(n):
    if parent[i] == NIL:
        root = i
        break

# First-Child, Next-Sibling representation
F = [NIL] * n
N = [NIL] * n
children = [[] for _ in range(n)]

for v in range(n):
    if parent[v] != NIL:
        children[parent[v]].append(v)

for v in range(n):
    if children[v]:
        F[v] = children[v][0]
        for i in range(len(children[v]) - 1):
            N[children[v][i]] = children[v][i + 1]

# Graph-Based representation (Adjacency list)
adj = [[] for _ in range(n)]
for v in range(n):
    if parent[v] != NIL:
        adj[parent[v]].append(v)

print("\n=== First-Child, Next-Sibling Representation ===")
for i in range(n):
    f_val = "nil" if F[i] == NIL else str(F[i])
    n_val = "nil" if N[i] == NIL else str(N[i])
    print(f"F[{i}] = {f_val}, N[{i}] = {n_val}")

print("\n=== Graph-Based Representation (Adjacency List) ===")
for u in range(n):
    print(f"{u}: {' '.join(map(str, adj[u]))}")