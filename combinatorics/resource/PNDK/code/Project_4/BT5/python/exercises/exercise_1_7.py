class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

class TreeOperations:
    @staticmethod
    def create_complete_binary_tree(n):
        """Tạo cây nhị phân đầy đủ với n nút"""
        if n <= 0:
            return None
        
        # Tạo danh sách nút
        nodes = [TreeNode(i) for i in range(1, n + 1)]
        
        # Liên kết các nút theo cấu trúc cây nhị phân
        for i in range(n):
            left_idx = 2 * i + 1
            right_idx = 2 * i + 2
            
            if left_idx < n:
                nodes[i].left = nodes[left_idx]
            if right_idx < n:
                nodes[i].right = nodes[right_idx]
        
        return nodes[0]  # Trả về nút gốc
    
    @staticmethod
    def print_tree_inorder(root):
        """In cây theo thứ tự giữa"""
        if root:
            TreeOperations.print_tree_inorder(root.left)
            print(root.val, end=" ")
            TreeOperations.print_tree_inorder(root.right)
    
    @staticmethod
    def print_tree_levelorder(root):
        """In cây theo cấp độ"""
        if not root:
            return
        
        from collections import deque
        queue = deque([root])
        while queue:
            node = queue.popleft()
            print(node.val, end=" ")
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

def main():
    ops = TreeOperations()
    
    print("Complete Binary Tree with 7 nodes:")
    root = ops.create_complete_binary_tree(7)
    
    print("Level-order traversal:")
    ops.print_tree_levelorder(root)
    print()
    
    print("In-order traversal:")
    ops.print_tree_inorder(root)
    print()

if __name__ == "__main__":
    main()