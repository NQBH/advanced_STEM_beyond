import time
from collections import deque
from typing import List, Optional, Deque

class BinaryTreeNode:
    """Nút của cây nhị phân"""
    def __init__(self, data: str):
        self.data = data
        self.left: Optional['BinaryTreeNode'] = None
        self.right: Optional['BinaryTreeNode'] = None
        self.parent: Optional['BinaryTreeNode'] = None
    
    def set_left(self, child: Optional['BinaryTreeNode']):
        """Thiết lập con trái"""
        self.left = child
        if child:
            child.parent = self
    
    def set_right(self, child: Optional['BinaryTreeNode']):
        """Thiết lập con phải"""
        self.right = child
        if child:
            child.parent = self

class GeneralTreeNode:
    """Nút của cây tổng quát (n-ary tree)"""
    def __init__(self, data: str):
        self.data = data
        self.children: List['GeneralTreeNode'] = []
        self.parent: Optional['GeneralTreeNode'] = None
    
    def add_child(self, child: 'GeneralTreeNode'):
        """Thêm nút con"""
        self.children.append(child)
        child.parent = self

class TreeTraversal:
    """Lớp chứa các phương pháp duyệt cây"""
    
    def __init__(self):
        self.traversal_result: List[str] = []
    
    def preorder_traversal(self, root: Optional[BinaryTreeNode]) -> List[str]:
        """Phương pháp 1: Preorder Traversal (Root -> Left -> Right)"""
        print("=== Preorder Traversal ===")
        
        start_time = time.time()
        
        self.traversal_result = []
        self._preorder_helper(root)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000  # microseconds
        
        print(f"Kết quả: {' '.join(self.traversal_result)}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print("Thứ tự: Root -> Left -> Right")
        
        return self.traversal_result[:]
    
    def postorder_traversal(self, root: Optional[BinaryTreeNode]) -> List[str]:
        """Phương pháp 2: Postorder Traversal (Left -> Right -> Root)"""
        print("\n=== Postorder Traversal ===")
        
        start_time = time.time()
        
        self.traversal_result = []
        self._postorder_helper(root)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print(f"Kết quả: {' '.join(self.traversal_result)}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print("Thứ tự: Left -> Right -> Root")
        
        return self.traversal_result[:]
    
    def top_down_traversal(self, root: Optional[BinaryTreeNode]) -> List[str]:
        """Phương pháp 3: Top-down Traversal (Level Order)"""
        print("\n=== Top-down Traversal (Level Order) ===")
        
        start_time = time.time()
        
        self.traversal_result = []
        
        if not root:
            end_time = time.time()
            execution_time = (end_time - start_time) * 1000000
            print("Cây rỗng")
            print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
            return self.traversal_result
        
        queue: Deque[BinaryTreeNode] = deque([root])
        
        while queue:
            current = queue.popleft()
            self.traversal_result.append(current.data)
            
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print(f"Kết quả: {' '.join(self.traversal_result)}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print("Thứ tự: Từ trên xuống dưới, từ trái sang phải theo level")
        
        return self.traversal_result[:]
    
    def bottom_up_traversal(self, root: Optional[BinaryTreeNode]) -> List[str]:
        """Phương pháp 4: Bottom-up Traversal"""
        print("\n=== Bottom-up Traversal ===")
        
        start_time = time.time()
        
        self.traversal_result = []
        
        if not root:
            end_time = time.time()
            execution_time = (end_time - start_time) * 1000000
            print("Cây rỗng")
            print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
            return self.traversal_result
        
        # Sử dụng queue để lưu các level
        levels: List[List[str]] = []
        queue: Deque[BinaryTreeNode] = deque([root])
        
        while queue:
            level_size = len(queue)
            current_level = []
            
            for _ in range(level_size):
                current = queue.popleft()
                current_level.append(current.data)
                
                if current.left:
                    queue.append(current.left)
                if current.right:
                    queue.append(current.right)
            
            levels.append(current_level)
        
        # Đảo ngược thứ tự levels (bottom-up)
        for level in reversed(levels):
            self.traversal_result.extend(level)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print(f"Kết quả: {' '.join(self.traversal_result)}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print("Thứ tự: Từ dưới lên trên, từ trái sang phải theo level")
        
        return self.traversal_result[:]
    
    def preorder_general_tree(self, root: Optional[GeneralTreeNode]) -> List[str]:
        """Preorder Traversal cho cây tổng quát"""
        print("\n=== Preorder Traversal - General Tree ===")
        
        start_time = time.time()
        
        self.traversal_result = []
        self._preorder_general_helper(root)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print(f"Kết quả: {' '.join(self.traversal_result)}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print("Thứ tự: Root -> Children (left to right)")
        
        return self.traversal_result[:]
    
    def postorder_general_tree(self, root: Optional[GeneralTreeNode]) -> List[str]:
        """Postorder Traversal cho cây tổng quát"""
        print("\n=== Postorder Traversal - General Tree ===")
        
        start_time = time.time()
        
        self.traversal_result = []
        self._postorder_general_helper(root)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print(f"Kết quả: {' '.join(self.traversal_result)}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print("Thứ tự: Children (left to right) -> Root")
        
        return self.traversal_result[:]
    
    def preorder_iterative(self, root: Optional[BinaryTreeNode]) -> List[str]:
        """Preorder Traversal phiên bản iterative"""
        print("\n=== Preorder Traversal (Iterative) ===")
        
        start_time = time.time()
        
        self.traversal_result = []
        
        if not root:
            end_time = time.time()
            execution_time = (end_time - start_time) * 1000000
            print("Cây rỗng")
            print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
            return self.traversal_result
        
        stack = [root]
        
        while stack:
            current = stack.pop()
            self.traversal_result.append(current.data)
            
            # Push right first, then left (vì stack là LIFO)
            if current.right:
                stack.append(current.right)
            if current.left:
                stack.append(current.left)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print(f"Kết quả: {' '.join(self.traversal_result)}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print("Phương pháp: Iterative sử dụng Stack")
        
        return self.traversal_result[:]
    
    def postorder_iterative(self, root: Optional[BinaryTreeNode]) -> List[str]:
        """Postorder Traversal phiên bản iterative"""
        print("\n=== Postorder Traversal (Iterative) ===")
        
        start_time = time.time()
        
        self.traversal_result = []
        
        if not root:
            end_time = time.time()
            execution_time = (end_time - start_time) * 1000000
            print("Cây rỗng")
            print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
            return self.traversal_result
        
        stack = []
        current = root
        last_visited = None
        
        while current or stack:
            if current:
                stack.append(current)
                current = current.left
            else:
                peek_node = stack[-1]
                
                if peek_node.right and last_visited != peek_node.right:
                    current = peek_