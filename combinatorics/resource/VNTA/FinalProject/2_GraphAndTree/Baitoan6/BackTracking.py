import sys
sys.setrecursionlimit(10 ** 7)

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

def is_leaf(node):
    return node and len(node.children) == 0

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

def backtrack(t1, t2, gamma):
    if t1 is None and t2 is None:
        return 0
    if t1 is None:
        cost = 1
        for c in t2.children:
            cost += backtrack(None, c, gamma)
        return cost
    if t2 is None:
        cost = 1
        for c in t1.children:
            cost += backtrack(c, None, gamma)
        return cost

    cost = gamma(t1, t2)
    c1 = t1.children
    c2 = t2.children
    n, m = len(c1), len(c2)

    if n == 0 and m == 0:
        return cost

    min_cost = float('inf')

    def try_align(i, j, current_cost):
        nonlocal min_cost
        if i == n and j == m:
            min_cost = min(min_cost, current_cost)
            return
        if i == n:
            insert_cost = current_cost
            for k in range(j, m):
                insert_cost += backtrack(None, c2[k], gamma)
            min_cost = min(min_cost, insert_cost)
            return
        if j == m:
            delete_cost = current_cost
            for k in range(i, n):
                delete_cost += backtrack(c1[k], None, gamma)
            min_cost = min(min_cost, delete_cost)
            return

        # Substitute
        sub_cost = backtrack(c1[i], c2[j], gamma)
        try_align(i + 1, j + 1, current_cost + sub_cost)
        # Delete
        del_cost = backtrack(c1[i], None, gamma)
        try_align(i + 1, j, current_cost + del_cost)
        # Insert
        ins_cost = backtrack(None, c2[j], gamma)
        try_align(i, j + 1, current_cost + ins_cost)

    try_align(0, 0, 0)
    return cost + min_cost

n1 = int(input())
edges1 = [tuple(map(int, input().split())) for _ in range(n1)]
n2 = int(input())
edges2 = [tuple(map(int, input().split())) for _ in range(n2)]

T1, root1 = build_tree(edges1)
T2, root2 = build_tree(edges2)

bt1 = backtrack(T1[root1], T2[root2], gamma_sub1)
bt0 = backtrack(T1[root1], T2[root2], gamma_sub0)

print("\n=== Backtrack ===")
print("Substitution cost = 1:", bt1)
print("Substitution cost = 0:", bt0)