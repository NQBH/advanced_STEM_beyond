import sys

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

def ted_backtrack(T1, T2, current_cost, min_cost):
    """Backtracking approach"""
    if current_cost >= min_cost[0]:  # Pruning
        return
    
    if not T1 and not T2:
        min_cost[0] = min(min_cost[0], current_cost)
        return
    if not T1:
        min_cost[0] = min(min_cost[0], current_cost + tree_size(T2))
        return
    if not T2:
        min_cost[0] = min(min_cost[0], current_cost + tree_size(T1))
        return
    
    # Relabel operation
    relabel_cost = 0 if T1.val == T2.val else 1
    ted_backtrack(T1.left, T2.left, current_cost + relabel_cost, min_cost)
    ted_backtrack(T1.right, T2.right, current_cost + relabel_cost, min_cost)
    
    # Delete operation
    ted_backtrack(T1.left, T2, current_cost + 1, min_cost)
    ted_backtrack(T1.right, T2, current_cost + 1, min_cost)
    
    # Insert operation
    ted_backtrack(T1, T2.left, current_cost + 1, min_cost)
    ted_backtrack(T1, T2.right, current_cost + 1, min_cost)

def main():
    T1 = read_tree('../tree1.inp')
    T2 = read_tree('../tree2.inp')
    
    min_cost = [float('inf')]
    ted_backtrack(T1, T2, 0, min_cost)
    
    print(f"Backtracking - Tree Edit Distance: {min_cost[0]}")
    print("Done")

if __name__ == "__main__":
    main()