class TreeNode:
    def __init__(self, id):
        self.id = id
        self.children = []

def build_tree_from_parents(parents):
    nodes = [TreeNode(i) for i in range(len(parents))]
    root = None
    for i, p in enumerate(parents):
        if p == -1:
            root = nodes[i]
        else:
            nodes[p].children.append(nodes[i])
    return root

def tree_edit_distance(t1, t2):
    # substitution cost = 0 if both nodes exist (ignore label)
    def compute(n1, n2):
        if n1 is None and n2 is None:
            return 0
        if n1 is None:
            return 1 + sum(compute(None, c) for c in n2.children)
        if n2 is None:
            return 1 + sum(compute(c, None) for c in n1.children)

        c1, c2 = n1.children, n2.children
        m, n = len(c1), len(c2)

        dp = [[0]*(n+1) for _ in range(m+1)]

        for i in range(m+1):
            for j in range(n+1):
                if i == 0 and j == 0:
                    dp[i][j] = 0
                elif i == 0:
                    dp[i][j] = dp[i][j-1] + compute(None, c2[j-1])
                elif j == 0:
                    dp[i][j] = dp[i-1][j] + compute(c1[i-1], None)
                else:
                    cost_sub = compute(c1[i-1], c2[j-1])
                    cost_del = compute(c1[i-1], None)
                    cost_ins = compute(None, c2[j-1])
                    dp[i][j] = min(
                        dp[i-1][j-1] + cost_sub,
                        dp[i-1][j] + cost_del,
                        dp[i][j-1] + cost_ins
                    )

        # substitution cost between n1 and n2 nodes is 0 (labels ignored)
        return dp[m][n]

    return compute(t1, t2)

def input_parents(prompt):
    print(prompt)
    arr = input("Nhap mang cha (root = -1): ")
    return list(map(int, arr.strip().split()))

if __name__ == "__main__":
    parents1 = input_parents("Cay thu nhat:")
    parents2 = input_parents("Cay thu hai:")

    root1 = build_tree_from_parents(parents1)
    root2 = build_tree_from_parents(parents2)

    dist = tree_edit_distance(root1, root2)
    print("\nTree Edit Distance:", dist)