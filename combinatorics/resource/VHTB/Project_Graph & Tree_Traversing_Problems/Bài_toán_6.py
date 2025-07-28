class Node:
    def __init__(self, label, children=None):
        self.label = label
        self.children = children or []

def post_order(node, result):
    if node:
        for c in node.children:
            post_order(c, result)
        result.append(node)

def ted(T1, T2):
    A, B = [], []
    post_order(T1, A)
    post_order(T2, B)
    m, n = len(A), len(B)
    dp = [[0]*(n+1) for _ in range(m+1)]

    for i in range(m+1):
        dp[i][0] = i
    for j in range(n+1):
        dp[0][j] = j

    for i in range(1, m+1):
        for j in range(1, n+1):
            cost = 0 if A[i-1].label == B[j-1].label else 1
            dp[i][j] = min(
                dp[i-1][j] + 1,      # delete
                dp[i][j-1] + 1,      # insert
                dp[i-1][j-1] + cost  # rename
            )
    return dp[m][n]

T1 = Node('a', [Node('b'), Node('c')])
T2 = Node('a', [Node('b'), Node('d')])
print("Tree Edit Distance:", ted(T1, T2))
