import time
from typing import List, Optional, Tuple
from enum import Enum
import sys

class EditOperation(Enum):
    INSERT = "INSERT"
    DELETE = "DELETE"
    REPLACE = "REPLACE"
    MATCH = "MATCH"

class Operation:
    def __init__(self, op: EditOperation, from_label: str = "", to_label: str = "", cost: int = 1):
        self.op = op
        self.from_label = from_label
        self.to_label = to_label
        self.cost = cost
    
    def __str__(self):
        if self.op == EditOperation.INSERT:
            return f"INSERT '{self.to_label}' (cost: {self.cost})"
        elif self.op == EditOperation.DELETE:
            return f"DELETE '{self.from_label}' (cost: {self.cost})"
        elif self.op == EditOperation.REPLACE:
            return f"REPLACE '{self.from_label}' -> '{self.to_label}' (cost: {self.cost})"
        elif self.op == EditOperation.MATCH:
            return f"MATCH '{self.from_label}' = '{self.to_label}' (cost: {self.cost})"

class TreeNode:
    def __init__(self, label: str):
        self.label = label
        self.children: List['TreeNode'] = []
    
    def add_child(self, child: 'TreeNode'):
        self.children.append(child)
    
    def __str__(self):
        return self.label

class TreeEditDistance:
    def __init__(self, insert_cost: int = 1, delete_cost: int = 1, replace_cost: int = 1):
        self.insert_cost = insert_cost
        self.delete_cost = delete_cost
        self.replace_cost = replace_cost
        
        # Biến toàn cục cho thuật toán
        self.min_cost = float('inf')
        self.best_solution: List[Operation] = []
    
    def solve_backtracking(self, tree1: Optional[TreeNode], tree2: Optional[TreeNode]) -> int:
        """Phương pháp 1: Backtracking"""
        print("=== Phương pháp Backtracking ===")
        
        start_time = time.time()
        
        self.min_cost = float('inf')
        self.best_solution = []
        current_solution = []
        
        self._backtrack_helper(tree1, tree2, 0, current_solution)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000  # microseconds
        
        print(f"Chi phí tối thiểu: {self.min_cost}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print("Chuỗi thao tác tối ưu:")
        self._print_operations(self.best_solution)
        
        return int(self.min_cost)
    
    def solve_branch_and_bound(self, tree1: Optional[TreeNode], tree2: Optional[TreeNode]) -> int:
        """Phương pháp 2: Branch-and-Bound"""
        print("\n=== Phương pháp Branch-and-Bound ===")
        
        start_time = time.time()
        
        self.min_cost = float('inf')
        self.best_solution = []
        current_solution = []
        
        # Tính upper bound ban đầu
        upper_bound = (self._get_tree_size(tree1) * self.delete_cost + 
                      self._get_tree_size(tree2) * self.insert_cost)
        
        self._branch_and_bound_helper(tree1, tree2, 0, current_solution, upper_bound)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print(f"Chi phí tối thiểu: {self.min_cost}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print("Chuỗi thao tác tối ưu:")
        self._print_operations(self.best_solution)
        
        return int(self.min_cost)
    
    def solve_divide_and_conquer(self, tree1: Optional[TreeNode], tree2: Optional[TreeNode]) -> int:
        """Phương pháp 3: Divide-and-Conquer"""
        print("\n=== Phương pháp Divide-and-Conquer ===")
        
        start_time = time.time()
        
        result = self._divide_and_conquer_helper(tree1, tree2)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print(f"Chi phí tối thiểu: {result}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        
        return result
    
    def solve_dynamic_programming(self, tree1: Optional[TreeNode], tree2: Optional[TreeNode]) -> int:
        """Phương pháp 4: Dynamic Programming"""
        print("\n=== Phương pháp Dynamic Programming ===")
        
        start_time = time.time()
        
        # Chuyển đổi cây thành postorder traversal
        postorder1, leftmost1 = self._get_postorder_and_leftmost(tree1)
        postorder2, leftmost2 = self._get_postorder_and_leftmost(tree2)
        
        m, n = len(postorder1), len(postorder2)
        
        # Ma trận DP
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        # Khởi tạo base cases
        for i in range(m + 1):
            dp[i][0] = i * self.delete_cost
        for j in range(n + 1):
            dp[0][j] = j * self.insert_cost
        
        # Điền ma trận DP
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # Kiểm tra xem có thể mapping được không
                if leftmost1[i-1] == 0 and leftmost2[j-1] == 0:
                    # Cả hai đều là lá
                    match_cost = 0 if postorder1[i-1].label == postorder2[j-1].label else self.replace_cost
                    dp[i][j] = min(
                        dp[i-1][j] + self.delete_cost,      # Delete
                        dp[i][j-1] + self.insert_cost,      # Insert
                        dp[i-1][j-1] + match_cost           # Match/Replace
                    )
                else:
                    # Xử lý subtree
                    dp[i][j] = min(
                        dp[i-1][j] + self.delete_cost,      # Delete
                        dp[i][j-1] + self.insert_cost       # Insert
                    )
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print(f"Chi phí tối thiểu: {dp[m][n]}")
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        
        return dp[m][n]
    
    def _backtrack_helper(self, tree1: Optional[TreeNode], tree2: Optional[TreeNode], 
                         current_cost: int, current_solution: List[Operation]):
        """Helper function cho backtracking"""
        # Pruning: nếu chi phí hiện tại đã lớn hơn min thì dừng
        if current_cost >= self.min_cost:
            return
        
        # Base cases
        if tree1 is None and tree2 is None:
            if current_cost < self.min_cost:
                self.min_cost = current_cost
                self.best_solution = current_solution[:]
            return
        
        if tree1 is None:
            # Chỉ còn tree2, insert tất cả
            insert_all_cost = self._get_tree_size(tree2) * self.insert_cost
            if current_cost + insert_all_cost < self.min_cost:
                self.min_cost = current_cost + insert_all_cost
                self.best_solution = current_solution[:]
                self._add_insert_operations(tree2, self.best_solution)
            return
        
        if tree2 is None:
            # Chỉ còn tree1, delete tất cả
            delete_all_cost = self._get_tree_size(tree1) * self.delete_cost
            if current_cost + delete_all_cost < self.min_cost:
                self.min_cost = current_cost + delete_all_cost
                self.best_solution = current_solution[:]
                self._add_delete_operations(tree1, self.best_solution)
            return
        
        # Thử các thao tác
        # 1. Match/Replace
        if tree1.label == tree2.label:
            current_solution.append(Operation(EditOperation.MATCH, tree1.label, tree2.label, 0))
            self._process_children(tree1, tree2, current_cost, current_solution)
            current_solution.pop()
        else:
            current_solution.append(Operation(EditOperation.REPLACE, tree1.label, tree2.label, self.replace_cost))
            self._process_children(tree1, tree2, current_cost + self.replace_cost, current_solution)
            current_solution.pop()
        
        # 2. Delete từ tree1
        current_solution.append(Operation(EditOperation.DELETE, tree1.label, "", self.delete_cost))
        self._backtrack_helper(None, tree2, current_cost + self.delete_cost, current_solution)
        current_solution.pop()
        
        # 3. Insert từ tree2
        current_solution.append(Operation(EditOperation.INSERT, "", tree2.label, self.insert_cost))
        self._backtrack_helper(tree1, None, current_cost + self.insert_cost, current_solution)
        current_solution.pop()
    
    def _branch_and_bound_helper(self, tree1: Optional[TreeNode], tree2: Optional[TreeNode],
                                current_cost: int, current_solution: List[Operation], bound: int):
        """Helper function cho branch-and-bound"""
        # Pruning với bound
        if current_cost >= self.min_cost or current_cost >= bound:
            return
        
        # Tính lower bound
        lower_bound = current_cost + self._calculate_lower_bound(tree1, tree2)
        if lower_bound >= self.min_cost:
            return
        
        # Base cases (tương tự backtracking)
        if tree1 is None and tree2 is None:
            if current_cost < self.min_cost:
                self.min_cost = current_cost
                self.best_solution = current_solution[:]
            return
        
        if tree1 is None:
            insert_all_cost = self._get_tree_size(tree2) * self.insert_cost
            if current_cost + insert_all_cost < self.min_cost:
                self.min_cost = current_cost + insert_all_cost
                self.best_solution = current_solution[:]
                self._add_insert_operations(tree2, self.best_solution)
            return
        
        if tree2 is None:
            delete_all_cost = self._get_tree_size(tree1) * self.delete_cost
            if current_cost + delete_all_cost < self.min_cost:
                self.min_cost = current_cost + delete_all_cost
                self.best_solution = current_solution[:]
                self._add_delete_operations(tree1, self.best_solution)
            return
        
        # Thử các thao tác với bound checking
        if tree1.label == tree2.label:
            current_solution.append(Operation(EditOperation.MATCH, tree1.label, tree2.label, 0))
            self._process_children(tree1, tree2, current_cost, current_solution)
            current_solution.pop()
        else:
            if current_cost + self.replace_cost < bound:
                current_solution.append(Operation(EditOperation.REPLACE, tree1.label, tree2.label, self.replace_cost))
                self._process_children(tree1, tree2, current_cost + self.replace_cost, current_solution)
                current_solution.pop()
        
        if current_cost + self.delete_cost < bound:
            current_solution.append(Operation(EditOperation.DELETE, tree1.label, "", self.delete_cost))
            self._branch_and_bound_helper(None, tree2, current_cost + self.delete_cost, current_solution, bound)
            current_solution.pop()
        
        if current_cost + self.insert_cost < bound:
            current_solution.append(Operation(EditOperation.INSERT, "", tree2.label, self.insert_cost))
            self._branch_and_bound_helper(tree1, None, current_cost + self.insert_cost, current_solution, bound)
            current_solution.pop()
    
    def _divide_and_conquer_helper(self, tree1: Optional[TreeNode], tree2: Optional[TreeNode]) -> int:
        """Helper function cho divide-and-conquer"""
        # Base cases
        if tree1 is None and tree2 is None:
            return 0
        if tree1 is None:
            return self._get_tree_size(tree2) * self.insert_cost
        if tree2 is None:
            return self._get_tree_size(tree1) * self.delete_cost
        
        # Nếu cây chỉ có một nút
        if not tree1.children and not tree2.children:
            return 0 if tree1.label == tree2.label else self.replace_cost
        
        # Chia nhỏ bài toán
        min_cost = float('inf')
        
        # Thử match/replace root
        root_cost = 0 if tree1.label == tree2.label else self.replace_cost
        children_cost = self._compare_children_lists(tree1.children, tree2.children)
        min_cost = min(min_cost, root_cost + children_cost)
        
        # Thử delete root của tree1
        min_cost = min(min_cost, self.delete_cost + self._divide_and_conquer_helper(None, tree2))
        
        # Thử insert root của tree2
        min_cost = min(min_cost, self.insert_cost + self._divide_and_conquer_helper(tree1, None))
        
        return min_cost
    
    def _compare_children_lists(self, children1: List[TreeNode], children2: List[TreeNode]) -> int:
        """So sánh danh sách con bằng DP"""
        m, n = len(children1), len(children2)
        
        # DP cho so sánh danh sách con
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(m + 1):
            dp[i][0] = i * self.delete_cost
        for j in range(n + 1):
            dp[0][j] = j * self.insert_cost
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = min(
                    dp[i-1][j] + self.delete_cost,
                    dp[i][j-1] + self.insert_cost,
                    dp[i-1][j-1] + self._divide_and_conquer_helper(children1[i-1], children2[j-1])
                )
        
        return dp[m][n]
    
    def _process_children(self, tree1: TreeNode, tree2: TreeNode, 
                         current_cost: int, current_solution: List[Operation]):
        """Xử lý danh sách con"""
        child_cost = self._compare_children_lists(tree1.children, tree2.children)
        
        if current_cost + child_cost < self.min_cost:
            self.min_cost = current_cost + child_cost
            self.best_solution = current_solution[:]
    
    def _get_tree_size(self, tree: Optional[TreeNode]) -> int:
        """Tính kích thước cây"""
        if tree is None:
            return 0
        size = 1
        for child in tree.children:
            size += self._get_tree_size(child)
        return size
    
    def _calculate_lower_bound(self, tree1: Optional[TreeNode], tree2: Optional[TreeNode]) -> int:
        """Tính lower bound cho branch-and-bound"""
        if tree1 is None and tree2 is None:
            return 0
        if tree1 is None:
            return self._get_tree_size(tree2) * self.insert_cost
        if tree2 is None:
            return self._get_tree_size(tree1) * self.delete_cost
        
        # Lower bound đơn giản: chênh lệch kích thước
        size1 = self._get_tree_size(tree1)
        size2 = self._get_tree_size(tree2)
        return abs(size1 - size2)
    
    def _add_insert_operations(self, tree: Optional[TreeNode], operations: List[Operation]):
        """Thêm các thao tác insert"""
        if tree is None:
            return
        operations.append(Operation(EditOperation.INSERT, "", tree.label, self.insert_cost))
        for child in tree.children:
            self._add_insert_operations(child, operations)
    
    def _add_delete_operations(self, tree: Optional[TreeNode], operations: List[Operation]):
        """Thêm các thao tác delete"""
        if tree is None:
            return
        operations.append(Operation(EditOperation.DELETE, tree.label, "", self.delete_cost))
        for child in tree.children:
            self._add_delete_operations(child, operations)
    
    def _get_postorder_and_leftmost(self, tree: Optional[TreeNode]) -> Tuple[List[TreeNode], List[int]]:
        """Chuyển đổi cây thành postorder traversal và tính leftmost"""
        postorder = []
        leftmost = []
        
        if tree is None:
            return postorder, leftmost
        
        def _postorder_helper(node: TreeNode):
            for child in node.children:
                _postorder_helper(child)
            postorder.append(node)
            leftmost.append(0 if not node.children else 1)
        
        _postorder_helper(tree)
        return postorder, leftmost
    
    def _print_operations(self, operations: List[Operation]):
        """In danh sách thao tác"""
        for op in operations:
            print(f"  {op}")

def create_sample_tree1() -> TreeNode:
    """Tạo cây mẫu 1"""
    root = TreeNode("A")
    b = TreeNode("B")
    c = TreeNode("C")
    d = TreeNode("D")
    e = TreeNode("E")
    
    root.add_child(b)
    root.add_child(c)
    b.add_child(d)
    c.add_child(e)
    
    return root

def create_sample_tree2() -> TreeNode:
    """Tạo cây mẫu 2"""
    root = TreeNode("A")
    b = TreeNode("B")
    f = TreeNode("F")
    d = TreeNode("D")
    
    root.add_child(b)
    root.add_child(f)
    b.add_child(d)
    
    return root

def print_tree(tree: Optional[TreeNode], level: int = 0):
    """In cây theo cấu trúc"""
    if tree is None:
        return
    
    print("  " * level + tree.label)
    
    for child in tree.children:
        print_tree(child, level + 1)

def main():
    print("=== TREE EDIT DISTANCE PROBLEM ===")
    print("Giải bài toán Tree Edit Distance bằng 4 phương pháp khác nhau\n")
    
    # Tạo hai cây mẫu
    tree1 = create_sample_tree1()
    tree2 = create_sample_tree2()
    
    print("Cây 1:")
    print_tree(tree1)
    print("\nCây 2:")
    print_tree(tree2)
    print()
    
    solver = TreeEditDistance(1, 1, 1)  # insert_cost, delete_cost, replace_cost
    
    # Giải bằng 4 phương pháp
    result1 = solver.solve_backtracking(tree1, tree2)
    result2 = solver.solve_branch_and_bound(tree1, tree2)
    result3 = solver.solve_divide_and_conquer(tree1, tree2)
    result4 = solver.solve_dynamic_programming(tree1, tree2)
    
    print("\n=== KẾT QUẢ TỔNG KẾT ===")
    print(f"Backtracking: {result1}")
    print(f"Branch-and-Bound: {result2}")
    print(f"Divide-and-Conquer: {result3}")
    print(f"Dynamic Programming: {result4}")

if __name__ == "__main__":
    main()