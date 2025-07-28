class TreeNode:
    def __init__(self, label, left=None, right=None):
        self.label = label
        self.left = left
        self.right = right

def tree_edit_distance_bt(t1, t2):
    if t1 is None and t2 is None:
        return 0
    if t1 is None:
        return 1 + tree_edit_distance_bt(None, t2.left) + tree_edit_distance_bt(None, t2.right)
    if t2 is None:
        return 1 + tree_edit_distance_bt(t1.left, None) + tree_edit_distance_bt(t1.right, None)

    cost = 0 if t1.label == t2.label else 1

    opt1 = tree_edit_distance_bt(t1.left, t2.left) + tree_edit_distance_bt(t1.right, t2.right)
    opt2 = tree_edit_distance_bt(t1.left, t2.right) + tree_edit_distance_bt(t1.right, t2.left)

    return cost + min(opt1, opt2)

if __name__ == "__main__":
    t1 = TreeNode('A', TreeNode('B'), TreeNode('C'))

    t2 = TreeNode('A', TreeNode('B'), TreeNode('D'))

    print("TED =", tree_edit_distance_bt(t1, t2))  
