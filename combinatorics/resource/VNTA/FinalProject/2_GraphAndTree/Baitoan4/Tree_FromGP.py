NIL = -1

n = int(input())
adj = []
for _ in range(n):
    data = list(map(int, input().split()))
    deg = data[0]
    neighbors = data[1:] if deg > 0 else []
    adj.append(neighbors)

parent = [NIL] * n
for u in range(n):
    for c in adj[u]:
        parent[c] = u

root = NIL
for i in range(n):
    if parent[i] == NIL:
        root = i
        break

F = [NIL] * n
N = [NIL] * n
for u in range(n):
    if adj[u]:
        F[u] = adj[u][0]
        for i in range(len(adj[u]) - 1):
            N[adj[u][i]] = adj[u][i + 1]

print("=== Array of Parents ===")
for i in range(n):
    print(f"parent[{i}] = {parent[i] if parent[i] != NIL else -1}")

print("\n=== First-Child, Next-Sibling Representation ===")
for i in range(n):
    f_val = "nil" if F[i] == NIL else str(F[i])
    n_val = "nil" if N[i] == NIL else str(N[i])
    print(f"F[{i}] = {f_val}, N[{i}] = {n_val}")