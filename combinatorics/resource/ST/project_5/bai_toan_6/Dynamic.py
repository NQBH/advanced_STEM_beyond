class TreeNode:
    def __init__(self, label):
        self.label = label
        self.children = []

# Chuyen cay thanh danh sach hau tu
def post_order(node, nodes):
    for child in node.children:
        post_order(child, nodes)
    nodes.append(node)

# Tinh khoang cach giua hai cay bang DP
def tree_edit_distance_dp(t1, t2):
    t1_nodes = []
    t2_nodes = []
    post_order(t1, t1_nodes)
    post_order(t2, t2_nodes)

    m, n = len(t1_nodes), len(t2_nodes)
    dp = [[0]*(n+1) for _ in range(m+1)]

    for i in range(1, m+1):
        dp[i][0] = dp[i-1][0] + 1  # xoa nut
    for j in range(1, n+1):
        dp[0][j] = dp[0][j-1] + 1  # chen nut

    for i in range(1, m+1):
        for j in range(1, n+1):
            cost = 0 if t1_nodes[i-1].label == t2_nodes[j-1].label else 1
            dp[i][j] = min(
                dp[i-1][j] + 1,      # xoa
                dp[i][j-1] + 1,      # chen
                dp[i-1][j-1] + cost  # doi
            )
    return dp[m][n]

# Ham nhap cay tu ban phim
def input_tree():
    label = input("Nhap nhan goc: ")
    node = TreeNode(label)
    n = int(input(f"So con cua {label}: "))
    for i in range(n):
        print(f"-- Con thu {i+1} cua {label}:")
        child = input_tree()
        node.children.append(child)
    return node

if __name__ == "__main__":
    print("Nhap cay 1:")
    t1 = input_tree()
    print("Nhap cay 2:")
    t2 = input_tree()
    print("Edit distance (DP):", tree_edit_distance_dp(t1, t2))