class TreeNode:
    def __init__(self, label):
        self.label = label
        self.children = []

def postorder(node, postorder_list, lld, labels, parent_map):
    if node is None:
        return
    for child in node.children:
        parent_map[child] = node
        postorder(child, postorder_list, lld, labels, parent_map)
    lld[node] = node if not node.children else lld[node.children[0]]
    postorder_list.append(node)
    labels[node] = node.label

def tree_edit_distance(t1, t2):
    A, B = [], []
    lld1, lld2 = {}, {}
    labels1, labels2 = {}, {}
    parent1, parent2 = {}, {}

    postorder(t1, A, lld1, labels1, parent1)
    postorder(t2, B, lld2, labels2, parent2)

    id1 = {node: i for i, node in enumerate(A)}
    id2 = {node: i for i, node in enumerate(B)}

    n, m = len(A), len(B)
    TED = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        TED[i][0] = i
    for j in range(m + 1):
        TED[0][j] = j

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            node1 = A[i - 1]
            node2 = B[j - 1]
            cost = 0 if labels1[node1] == labels2[node2] else 1

            TED[i][j] = min(
                TED[i - 1][j] + 1,     # delete
                TED[i][j - 1] + 1,     # insert
                TED[i - 1][j - 1] + cost  # relabel
            )

    return TED[n][m]

if __name__ == "__main__":
    t1 = TreeNode("A")
    t1.children = [TreeNode("B"), TreeNode("C")]

    t2 = TreeNode("A")
    t2.children = [TreeNode("B"), TreeNode("D")]

    print("Tree Edit Distance =", tree_edit_distance(t1, t2))  