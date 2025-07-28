import sys
sys.setrecursionlimit(10**7)

class Node:
    def __init__(self, id):
        self.id = id
        self.children = []

def build_tree(edges):
    nodes = {}
    children_set = set()
    for u, v in edges:
        if u not in nodes:
            nodes[u] = Node(u)
        if v not in nodes:
            nodes[v] = Node(v)
        nodes[u].children.append(nodes[v])
        children_set.add(v)
    root = None
    for node_id in nodes:
        if node_id not in children_set:
            root = node_id
            break
    return nodes, root

def gamma_sub1(a, b):
    if a is None and b is None:
        return 0
    if a is None or b is None:
        return 1
    return 0 if a.id == b.id else 1

def gamma_sub0(a, b):
    if a is None and b is None:
        return 0
    if a is None or b is None:
        return 1
    return 0

def DaC(t1, t2, gamma):
    if t1 is None and t2 is None:
        return 0
    if t1 is None:
        cost = 1
        for c in t2.children:
            cost += DaC(None, c, gamma)
        return cost
    if t2 is None:
        cost = 1
        for c in t1.children:
            cost += DaC(c, None, gamma)
        return cost

    cost = gamma(t1, t2)
    c1 = t1.children
    c2 = t2.children
    n, m = len(c1), len(c2)

    dp = [[0]*(m+1) for _ in range(n+1)]

    for i in range(n+1):
        for j in range(m+1):
            if i == 0 and j == 0:
                dp[i][j] = 0
            elif i == 0:
                dp[i][j] = dp[i][j-1] + DaC(None, c2[j-1], gamma)
            elif j == 0:
                dp[i][j] = dp[i-1][j] + DaC(c1[i-1], None, gamma)
            else:
                subCost = DaC(c1[i-1], c2[j-1], gamma)
                delCost = DaC(c1[i-1], None, gamma)
                insCost = DaC(None, c2[j-1], gamma)

                dp[i][j] = min(
                    dp[i-1][j-1] + subCost,  # substitute
                    dp[i-1][j] + delCost,    # delete
                    dp[i][j-1] + insCost     # insert
                )
    return cost + dp[n][m]

# Đọc input
n1 = int(input())
edges1 = [tuple(map(int, input().split())) for _ in range(n1)]
n2 = int(input())
edges2 = [tuple(map(int, input().split())) for _ in range(n2)]

T1, root1 = build_tree(edges1)
T2, root2 = build_tree(edges2)

dac_1 = DaC(T1[root1], T2[root2], gamma_sub1)
dac_0 = DaC(T1[root1], T2[root2], gamma_sub0)

print("\n===Divide and Conquer===")
print("Substitution cost = 1:", dac_1)
print("Substitution cost = 0:", dac_0)