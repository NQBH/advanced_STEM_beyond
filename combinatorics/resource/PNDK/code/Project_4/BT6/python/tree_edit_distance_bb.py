import heapq

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

def lower_bound(T1, T2):
    """Simple lower bound estimation"""
    size1 = tree_size(T1)
    size2 = tree_size(T2)
    return abs(size1 - size2)

def ted_branch_bound(T1, T2):
    """Branch and Bound approach"""
    if not T1 and not T2:
        return 0
    if not T1:
        return tree_size(T2)
    if not T2:
        return tree_size(T1)
    
    # Priority queue: (cost, T1, T2)
    pq = [(0, T1, T2)]
    best_cost = float('inf')
    
    while pq:
        current_cost, t1, t2 = heapq.heappop(pq)
        
        if current_cost >= best_cost:
            continue
            
        if not t1 and not t2:
            best_cost = min(best_cost, current_cost)
            continue
        if not t1:
            best_cost = min(best_cost, current_cost + tree_size(t2))
            continue
        if not t2:
            best_cost = min(best_cost, current_cost + tree_size(t1))
            continue
        
        # Three operations with bounds
        lb = lower_bound(t1, t2)
        
        # Relabel
        relabel_cost = 0 if t1.val == t2.val else 1
        heapq.heappush(pq, (current_cost + relabel_cost, t1.left, t2.left))
        heapq.heappush(pq, (current_cost + relabel_cost, t1.right, t2.right))
        
        # Delete
        heapq.heappush(pq, (current_cost + 1, t1.left, t2))
        heapq.heappush(pq, (current_cost + 1, t1.right, t2))
        
        # Insert
        heapq.heappush(pq, (current_cost + 1, t1, t2.left))
        heapq.heappush(pq, (current_cost + 1, t1, t2.right))
    
    return best_cost

def main():
    T1 = read_tree('../tree1.inp')
    T2 = read_tree('../tree2.inp')
    
    distance = ted_branch_bound(T1, T2)
    print(f"Branch & Bound - Tree Edit Distance: {distance}")
    print("Done")

if __name__ == "__main__":
    main()