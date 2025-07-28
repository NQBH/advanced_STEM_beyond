class TreeNode:
    def __init__(self, label, left=None, right=None):
        self.label = label
        self.left = left
        self.right = right

def count_nodes(t):
    if t is None:
        return 0
    return 1 + count_nodes(t.left) + count_nodes(t.right)

def tree_edit_distance_dc(t1, t2):
    if t1 is None and t2 is None:
        return 0
    if t1 is None:
        return count_nodes(t2)
    if t2 is None:
        return count_nodes(t1)

    cost = 0 if t1.label == t2.label else 1

    cost1 = tree_edit_distance_dc(t1.left, t2.left) + tree_edit_distance_dc(t1.right, t2.right)
    cost2 = tree_edit_distance_dc(t1.left, t2.right) + tree_edit_distance_dc(t1.right, t2.left)

    return cost + min(cost1, cost2)
# Test
if __name__ == "__main__":
    t1 = TreeNode("A", TreeNode("B"), TreeNode("C"))

    t2 = TreeNode("A", TreeNode("B"), TreeNode("D"))

    print("TED =", tree_edit_distance_dc(t1, t2))  
