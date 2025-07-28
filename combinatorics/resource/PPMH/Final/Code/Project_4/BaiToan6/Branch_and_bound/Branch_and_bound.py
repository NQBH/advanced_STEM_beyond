class TreeNode:
    def __init__(self, label, left=None, right=None):
        self.label = label
        self.left = left
        self.right = right

def count_nodes(t):
    if t is None:
        return 0
    return 1 + count_nodes(t.left) + count_nodes(t.right)

def tree_edit_distance_bb(t1, t2, cost_so_far, best_cost):
    if cost_so_far >= best_cost[0]:
        return float('inf')

    if t1 is None and t2 is None:
        best_cost[0] = min(best_cost[0], cost_so_far)
        return 0

    if t1 is None:
        extra = count_nodes(t2)
        if cost_so_far + extra >= best_cost[0]:
            return float('inf')
        return extra

    if t2 is None:
        extra = count_nodes(t1)
        if cost_so_far + extra >= best_cost[0]:
            return float('inf')
        return extra

    cost = 0 if t1.label == t2.label else 1
    total_cost = cost_so_far + cost

    remaining = abs(count_nodes(t1.left) + count_nodes(t1.right) -
                    count_nodes(t2.left) - count_nodes(t2.right))
    if total_cost + remaining >= best_cost[0]:
        return float('inf')

    opt1_left = tree_edit_distance_bb(t1.left, t2.left, total_cost, best_cost)
    opt1_right = tree_edit_distance_bb(t1.right, t2.right, total_cost, best_cost)

    opt2_left = tree_edit_distance_bb(t1.left, t2.right, total_cost, best_cost)
    opt2_right = tree_edit_distance_bb(t1.right, t2.left, total_cost, best_cost)

    best_local = cost + min(opt1_left + opt1_right, opt2_left + opt2_right)

    best_cost[0] = min(best_cost[0], cost_so_far + best_local)
    return best_local

def compute_tree_edit_distance(t1, t2):
    best_cost = [float('inf')]
    tree_edit_distance_bb(t1, t2, 0, best_cost)
    return best_cost[0]

if __name__ == "__main__":
    t1 = TreeNode("A", TreeNode("B"), TreeNode("C"))

    t2 = TreeNode("A", TreeNode("B"), TreeNode("D"))

    print("TED =", compute_tree_edit_distance(t1, t2))  
