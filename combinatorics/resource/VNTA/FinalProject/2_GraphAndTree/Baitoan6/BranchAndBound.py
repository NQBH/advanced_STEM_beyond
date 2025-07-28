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

def count_nodes(node):
    if node is None:
        return 0
    total = 1
    for c in node.children:
        total += count_nodes(c)
    return total

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

def compute_lower_bound(c1, c2, i, j, gamma):
    n1 = len(c1) - i
    n2 = len(c2) - j

    if n1 == 0 and n2 == 0:
        return 0
    if n1 == 0:
        cost = 0
        for k in range(j, len(c2)):
            cost += 1 + count_nodes(c2[k]) - 1
        return cost
    if n2 == 0:
        cost = 0
        for k in range(i, len(c1)):
            cost += 1 + count_nodes(c1[k]) - 1
        return cost
    return abs(n1 - n2)

def branch_and_bound(t1, t2, gamma):
    if t1 is None and t2 is None:
        return 0
    if t1 is None:
        cost = 1
        for c in t2.children:
            cost += branch_and_bound(None, c, gamma)
        return cost
    if t2 is None:
        cost = 1
        for c in t1.children:
            cost += branch_and_bound(c, None, gamma)
        return cost

    cost = gamma(t1, t2)
    c1 = t1.children
    c2 = t2.children
    n, m = len(c1), len(c2)

    if n == 0 and m == 0:
        return cost

    min_cost = [float('inf')]

    def try_align(i, j, current_cost):
        lower_bound = current_cost + compute_lower_bound(c1, c2, i, j, gamma)
        if lower_bound >= min_cost[0]:
            return  # prune

        if i == n and j == m:
            min_cost[0] = min(min_cost[0], current_cost)
            return

        if i == n:
            insert_cost = current_cost
            for k in range(j, m):
                insert_cost += branch_and_bound(None, c2[k], gamma)
            min_cost[0] = min(min_cost[0], insert_cost)
            return

        if j == m:
            delete_cost = current_cost
            for k in range(i, n):
                delete_cost += branch_and_bound(c1[k], None, gamma)
            min_cost[0] = min(min_cost[0], delete_cost)
            return

        # Substitute
        try_align(i + 1, j + 1, current_cost + branch_and_bound(c1[i], c2[j], gamma))
        # Delete
        try_align(i + 1, j, current_cost + branch_and_bound(c1[i], None, gamma))
        # Insert
        try_align(i, j + 1, current_cost + branch_and_bound(None, c2[j], gamma))

    try_align(0, 0, 0)
    return cost + min_cost[0]

n1 = int(input())
edges1 = [tuple(map(int, input().split())) for _ in range(n1)]
n2 = int(input())
edges2 = [tuple(map(int, input().split())) for _ in range(n2)]

T1, root1 = build_tree(edges1)
T2, root2 = build_tree(edges2)

bnb1 = branch_and_bound(T1[root1], T2[root2], gamma_sub1)
bnb0 = branch_and_bound(T1[root1], T2[root2], gamma_sub0)

print("\n=== Branch and Bound ===")
print("Substitution cost = 1:", bnb1)
print("Substitution cost = 0:", bnb0)
