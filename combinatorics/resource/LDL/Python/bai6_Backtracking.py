class TreeNode:
    def __init__(self, id):
        self.id = id
        self.children = []

def build_tree(parents):
    nodes = {}
    root = -1
    for i, p in enumerate(parents):
        if i not in nodes:
            nodes[i] = TreeNode(i)
        if p == -1:
            root = i
        else:
            if p not in nodes:
                nodes[p] = TreeNode(p)
            nodes[p].children.append(nodes[i])
    return nodes[root]

def tree_edit_distance(t1, t2):
    def substitution_cost(a, b):
        if a is None and b is None:
            return 0
        if a is None or b is None:
            return 1
        return 0  

    def compute(node1, node2):
        if node1 is None and node2 is None:
            return 0
        if node1 is None:
            return 1 + sum(compute(None, child) for child in node2.children)
        if node2 is None:
            return 1 + sum(compute(child, None) for child in node1.children)

        cost = substitution_cost(node1, node2)
        c1, c2 = node1.children, node2.children
        n, m = len(c1), len(c2)
        min_cost = float('inf')

        def align(i, j, acc):
            nonlocal min_cost
            if i == n and j == m:
                min_cost = min(min_cost, acc)
                return
            if i == n:
                extra = sum(compute(None, c2[k]) for k in range(j, m))
                min_cost = min(min_cost, acc + extra)
                return
            if j == m:
                extra = sum(compute(c1[k], None) for k in range(i, n))
                min_cost = min(min_cost, acc + extra)
                return

            # 1. Match
            align(i + 1, j + 1, acc + compute(c1[i], c2[j]))
            # 2. Delete c1[i]
            align(i + 1, j, acc + compute(c1[i], None))
            # 3. Insert c2[j]
            align(i, j + 1, acc + compute(None, c2[j]))

        align(0, 0, 0)
        return cost + min_cost

    return compute(t1, t2)

def read_parents(prompt):
    print(prompt)
    s = input("Nhap mang cha (root = -1): ")
    return list(map(int, s.strip().split()))

if __name__ == "__main__":
    parents1 = read_parents("Cay thu nhat:")
    parents2 = read_parents("Cay thu hai:")

    root1 = build_tree(parents1)
    root2 = build_tree(parents2)

    dist = tree_edit_distance(root1, root2)
    print("\nTree edit distance:", dist)