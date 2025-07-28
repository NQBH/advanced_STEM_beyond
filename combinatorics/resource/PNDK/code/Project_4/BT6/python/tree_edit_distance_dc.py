class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

def read_tree(filename):
    try:
        with open(filename, 'r') as f:
            n = int(f.readline().strip())
            if n == 0:
                return None
            edges = []
            for _ in range(n):
                line = list(map(int, f.readline().strip().split()))
                edges.append(line)
        return build_tree_from_edges(edges)
    except:
        return None

def build_tree_from_edges(edges):
    if not edges:
        return None
    
    nodes = {}
    children_set = set()
    
    for parent, left, right in edges:
        if parent not in nodes:
            nodes[parent] = TreeNode(parent)
        if left != -1:
            if left not in nodes:
                nodes[left] = TreeNode(left)
            nodes[parent].left = nodes[left]
            children_set.add(left)
        if right != -1:
            if right not in nodes:
                nodes[right] = TreeNode(right)
            nodes[parent].right = nodes[right]
            children_set.add(right)
    
    # Find root
    root = None
    for val in nodes:
        if val not in children_set:
            root = nodes[val]
            break
    
    return root

def tree_size(node):
    if not node:
        return 0
    return 1 + tree_size(node.left) + tree_size(node.right)

def ted_divide_conquer(T1, T2):
    """Divide and Conquer approach"""
    if not T1 and not T2:
        return 0
    if not T1:
        return tree_size(T2)
    if not T2:
        return tree_size(T1)
    
    # Divide: split into subproblems
    # Conquer: solve subproblems recursively
    # Combine: combine results
    
    # Case 1: Relabel current nodes
    relabel_cost = 0 if T1.val == T2.val else 1
    left_cost = ted_divide_conquer(T1.left, T2.left)
    right_cost = ted_divide_conquer(T1.right, T2.right)
    cost1 = relabel_cost + left_cost + right_cost
    
    # Case 2: Delete T1 subtree
    delete_cost = 1 + tree_size(T1.left) + tree_size(T1.right)
    cost2 = delete_cost + ted_divide_conquer(None, T2)
    
    # Case 3: Insert T2 subtree
    insert_cost = 1 + tree_size(T2.left) + tree_size(T2.right)
    cost3 = insert_cost + ted_divide_conquer(T1, None)
    
    return min(cost1, cost2, cost3)

def main():
    T1 = read_tree('../tree1.inp')
    T2 = read_tree('../tree2.inp')
    
    distance = ted_divide_conquer(T1, T2)
    print(f"Divide & Conquer - Tree Edit Distance: {distance}")
    print("Done")

if __name__ == "__main__":
    main()