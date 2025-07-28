from collections import deque
from typing import List, Optional

class TreeNode:
    """Node cho cây nhị phân"""
    def __init__(self, val: int = 0):
        self.val = val
        self.left: Optional['TreeNode'] = None
        self.right: Optional['TreeNode'] = None

class GeneralTreeNode:
    """Node cho cây tổng quát"""
    def __init__(self, val: int = 0):
        self.val = val
        self.children: List['GeneralTreeNode'] = []

class TreeTraversal:
    """Lớp xử lý các phương pháp duyệt cây"""
    
    # ===== PREORDER TRAVERSAL =====
    
    def preorder_recursive(self, root: Optional[TreeNode]) -> List[int]:
        """
        Duyệt preorder bằng đệ quy
        Thứ tự: Gốc -> Trái -> Phải
        """
        result = []
        
        def dfs(node):
            if not node:
                return
            result.append(node.val)      # Thăm gốc
            dfs(node.left)            # Duyệt trái
            dfs(node.right)           # Duyệt phải
        
        dfs(root)
        return result
    
    def preorder_iterative(self, root: Optional[TreeNode]) -> List[int]:
        """
        Duyệt preorder không đệ quy bằng stack
        """
        if not root:
            return []
        
        result = []
        stack = [root]
        
        while stack:
            node = stack.pop()
            result.append(node.val)
            
            # Push phải trước, trái sau (vì stack là LIFO)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        
        return result
    
    # ===== POSTORDER TRAVERSAL =====
    
    def postorder_recursive(self, root: Optional[TreeNode]) -> List[int]:
        """
        Duyệt postorder bằng đệ quy
        Thứ tự: Trái -> Phải -> Gốc
        """
        result = []
        
        def dfs(node):
            if not node:
                return
            dfs(node.left)            # Duyệt trái
            dfs(node.right)           # Duyệt phải
            result.append(node.val)   # Thăm gốc
        
        dfs(root)
        return result
    
    def postorder_iterative_two_stacks(self, root: Optional[TreeNode]) -> List[int]:
        """
        Duyệt postorder không đệ quy bằng 2 stack
        """
        if not root:
            return []
        
        stack1 = [root]
        stack2 = []
        result = []
        
        # Stack 1: duyệt và đẩy vào stack 2
        while stack1:
            node = stack1.pop()
            stack2.append(node)
            
            if node.left:
                stack1.append(node.left)
            if node.right:
                stack1.append(node.right)
        
        # Stack 2: lấy ra theo thứ tự postorder
        while stack2:
            result.append(stack2.pop().val)
        
        return result
    
    def postorder_iterative_one_stack(self, root: Optional[TreeNode]) -> List[int]:
        """
        Duyệt postorder không đệ quy bằng 1 stack với flag
        """
        if not root:
            return []
        
        result = []
        stack = [(root, False)]  # (node, processed)
        
        while stack:
            node, processed = stack.pop()
            
            if processed:
                result.append(node.val)
            else:
                # Đánh dấu đã xử lý và push lại
                stack.append((node, True))
                # Push con phải trước, trái sau
                if node.right:
                    stack.append((node.right, False))
                if node.left:
                    stack.append((node.left, False))
        
        return result
    
    # ===== TOP-DOWN TRAVERSAL =====
    
    def level_order_traversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        Duyệt theo mức từ trên xuống (Level order)
        """
        if not root:
            return []
        
        result = []
        queue = deque([root])
        
        while queue:
            level_size = len(queue)
            current_level = []
            
            for _ in range(level_size):
                node = queue.popleft()
                current_level.append(node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            result.append(current_level)
        
        return result
    
    def top_down_flat(self, root: Optional[TreeNode]) -> List[int]:
        """
        Duyệt top-down trả về 1 list phẳng
        """
        if not root:
            return []
        
        result = []
        queue = deque([root])
        
        while queue:
            node = queue.popleft()
            result.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        return result
    
    # ===== BOTTOM-UP TRAVERSAL =====
    
    def bottom_up_traversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        """
        Duyệt theo mức từ dưới lên
        """
        levels = self.level_order_traversal(root)
        return levels[::-1]  # Đảo ngược
    
    def bottom_up_flat(self, root: Optional[TreeNode]) -> List[int]:
        """
        Duyệt bottom-up trả về 1 list phẳng
        """
        levels = self.level_order_traversal(root)
        result = []
        
        for level in reversed(levels):
            result.extend(level)
        
        return result
    
    # ===== CÂY TỔNG QUÁT =====
    
    def preorder_general(self, root: Optional[GeneralTreeNode]) -> List[int]:
        """
        Duyệt preorder cho cây tổng quát
        """
        result = []
        
        def dfs(node):
            if not node:
                return
            result.append(node.val)
            for child in node.children:
                dfs(child)
        
        dfs(root)
        return result
    
    def postorder_general(self, root: Optional[GeneralTreeNode]) -> List[int]:
        """
        Duyệt postorder cho cây tổng quát
        """
        result = []
        
        def dfs(node):
            if not node:
                return
            for child in node.children:
                dfs(child)
            result.append(node.val)
        
        dfs(root)
        return result
    
    def level_order_general(self, root: Optional[GeneralTreeNode]) -> List[List[int]]:
        """
        Duyệt level order cho cây tổng quát
        """
        if not root:
            return []
        
        result = []
        queue = deque([root])
        
        while queue:
            level_size = len(queue)
            current_level = []
            
            for _ in range(level_size):
                node = queue.popleft()
                current_level.append(node.val)
                
                for child in node.children:
                    queue.append(child)
            
            result.append(current_level)
        
        return result
    
    # ===== UTILITY FUNCTIONS =====
    
    def create_sample_tree(self) -> TreeNode:
        """
        Tạo cây mẫu:
                1
               / \
              2   3
             / \   \
            4   5   6
        """
        root = TreeNode(1)
        root.left = TreeNode(2)
        root.right = TreeNode(3)
        root.left.left = TreeNode(4)
        root.left.right = TreeNode(5)
        root.right.right = TreeNode(6)
        return root
    
    def create_sample_general_tree(self) -> GeneralTreeNode:
        """
        Tạo cây tổng quát mẫu:
                1
              / | \
             2  3  4
            /|    |\
           5 6    7 8
        """
        root = GeneralTreeNode(1)
        root.children = [GeneralTreeNode(2), GeneralTreeNode(3), GeneralTreeNode(4)]
        
        root.children[0].children = [GeneralTreeNode(5), GeneralTreeNode(6)]
        root.children[2].children = [GeneralTreeNode(7), GeneralTreeNode(8)]
        
        return root
    
    def get_height(self, root: Optional[TreeNode]) -> int:
        """Tính chiều cao cây"""
        if not root:
            return 0
        return 1 + max(self.get_height(root.left), self.get_height(root.right))
    
    def count_nodes(self, root: Optional[TreeNode]) -> int:
        """Đếm số node trong cây"""
        if not root:
            return 0
        return 1 + self.count_nodes(root.left) + self.count_nodes(root.right)
    
    def is_balanced(self, root: Optional[TreeNode]) -> bool:
        """Kiểm tra cây có cân bằng hay không"""
        def check_balance(node):
            if not node:
                return 0
            
            left_height = check_balance(node.left)
            if left_height == -1:
                return -1
            
            right_height = check_balance(node.right)
            if right_height == -1:
                return -1
            
            if abs(left_height - right_height) > 1:
                return -1
            
            return 1 + max(left_height, right_height)
        
        return check_balance(root) != -1

def print_list(lst, name):
    """In danh sách"""
    print(f"{name}: {lst}")

def print_levels(levels, name):
    """In các mức"""
    print(f"{name}:")
    for i, level in enumerate(levels):
        print(f"  Level {i}: {level}")

# Hàm test chính
def main():
    traverser = TreeTraversal()
    
    print("=== DEMO DUYỆT CÂY NHỊ PHÂN ===")
    
    # Tạo cây mẫu
    root = traverser.create_sample_tree()
    
    print("Cây mẫu:")
    print("        1")
    print("       / \\")
    print("      2   3")
    print("     / \\   \\")
    print("    4   5   6")
    print()
    
    # Test preorder
    pre_rec = traverser.preorder_recursive(root)
    pre_iter = traverser.preorder_iterative(root)
    print_list(pre_rec, "Preorder (Đệ quy)")
    print_list(pre_iter, "Preorder (Không đệ quy)")
    
    # Test postorder
    post_rec = traverser.postorder_recursive(root)
    post_two = traverser.postorder_iterative_two_stacks(root)
    post_one = traverser.postorder_iterative_one_stack(root)
    print_list(post_rec, "Postorder (Đệ quy)")
    print_list(post_two, "Postorder (2 stack)")
    print_list(post_one, "Postorder (1 stack)")
    
    # Test level order
    top_down = traverser.level_order_traversal(root)
    bottom_up = traverser.bottom_up_traversal(root)
    print_levels(top_down, "Top-down traversal")
    print_levels(bottom_up, "Bottom-up traversal")
    
    print()
    
    # Thông tin cây
    print("=== THÔNG TIN CÂY ===")
    print(f"Chiều cao: {traverser.get_height(root)}")
    print(f"Số node: {traverser.count_nodes(root)}")
    print(f"Cân bằng: {'Có' if traverser.is_balanced(root) else 'Không'}")
    
    print()
    
    # Test cây tổng quát
    print("=== DEMO DUYỆT CÂY TỔNG QUÁT ===")
    
    gen_root = traverser.create_sample_general_tree()
    
    print("Cây tổng quát mẫu:")
    print("        1")
    print("      / | \\")
    print("     2  3  4")
    print("    /|    |\\")
    print("   5 6    7 8")
    print()
    
    gen_pre = traverser.preorder_general(gen_root)
    gen_post = traverser.postorder_general(gen_root)
    gen_levels = traverser.level_order_general(gen_root)
    
    print_list(gen_pre, "Preorder cây tổng quát")
    print_list(gen_post, "Postorder cây tổng quát")
    print_levels(gen_levels, "Level order cây tổng quát")

if __name__ == "__main__":
    main()