NIL = -1

n = int(input())

F = [0] * n
N = [0] * n
for i in range(n):
    f, nxt = map(int, input().split())
    F[i] = f
    N[i] = nxt

parent = [NIL] * n
for u in range(n):
    child = F[u]
    while child != NIL:
        parent[child] = u
        child = N[child]

root = NIL
for i in range(n):
    if parent[i] == NIL:
        root = i
        break

adj = [[] for _ in range(n)]
for v in range(n):
    if parent[v] != NIL:
        adj[parent[v]].append(v)

print("=== Array of Parents ===")
for i in range(n):
    print(f"parent[{i}] = {parent[i] if parent[i] != NIL else -1}")

print("\n=== Graph-Based Representation (Adjacency List) ===")
for u in range(n):
    print(f"{u}: ", end="")
    print(" ".join(str(v) for v in adj[u]))
