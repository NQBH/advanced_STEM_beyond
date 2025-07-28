class TreeNode:
    """Lớp biểu diễn nút cây"""
    def __init__(self, label, node_id=0):
        self.label = label
        self.id = node_id
        self.children = []
    
    def add_child(self, child):
        self.children.append(child)
    
    def __str__(self):
        return f"TreeNode({self.label})"

class TreeEditDistance:
    """Lớp giải bài toán Tree Edit Distance"""
    
    def __init__(self):
        self.memo = {}  # Cho dynamic programming
        self.best_cost = float('inf')  # Cho branch-and-bound
    
    def cost_substitute(self, a, b):
        """Chi phí thay thế nhãn a bằng nhãn b"""
        return 0 if a == b else 1
    
    def cost_delete(self, a):
        """Chi phí xóa nút có nhãn a"""
        return 1
    
    def cost_insert(self, b):
        """Chi phí chèn nút có nhãn b"""
        return 1
    
    def get_post_order(self, root):
        """Duyệt cây theo thứ tự post-order"""
        if not root:
            return []
        
        result = []
        for child in root.children:
            result.extend(self.get_post_order(child))
        result.append(root)
        return result
    
    def count_nodes(self, root):
        """Đếm số nút trong cây"""
        if not root:
            return 0
        count = 1
        for child in root.children:
            count += self.count_nodes(child)
        return count
    
    def sum_insert_cost(self, nodes):
        """Tính tổng chi phí chèn danh sách các nút"""
        total = 0
        for node in nodes:
            if node:
                total += self.cost_insert(node.label)
                total += self.sum_insert_cost(node.children)
        return total
    
    def sum_delete_cost(self, nodes):
        """Tính tổng chi phí xóa danh sách các nút"""
        total = 0
        for node in nodes:
            if node:
                total += self.cost_delete(node.label)
                total += self.sum_delete_cost(node.children)
        return total
    
    # 1. Phương pháp Backtracking
    def backtracking_ted(self, t1, t2):
        """
        Giải Tree Edit Distance bằng Backtracking
        
        Args:
            t1, t2: Hai cây cần so sánh
            
        Returns:
            int: Khoảng cách chỉnh sửa tối thiểu
        """
        if not t1 and not t2:
            return 0
        if not t1:
            return self.cost_insert(t2.label) + self.sum_insert_cost(t2.children)
        if not t2:
            return self.cost_delete(t1.label) + self.sum_delete_cost(t1.children)
        
        min_cost = float('inf')
        
        # Thay thế nút gốc
        substitute_cost = self.cost_substitute(t1.label, t2.label)
        substitute_cost += self.compute_children_cost(t1.children, t2.children)
        min_cost = min(min_cost, substitute_cost)
        
        # Xóa nút gốc của t1
        delete_cost = self.cost_delete(t1.label)
        for child in t1.children:
            delete_cost += self.backtracking_ted(child, t2)
        min_cost = min(min_cost, delete_cost)
        
        # Chèn nút gốc của t2
        insert_cost = self.cost_insert(t2.label)
        for child in t2.children:
            insert_cost += self.backtracking_ted(t1, child)
        min_cost = min(min_cost, insert_cost)
        
        return min_cost
    
    # 2. Phương pháp Branch-and-bound
    def branch_bound_ted(self, t1, t2):
        """
        Giải Tree Edit Distance bằng Branch-and-bound
        
        Args:
            t1, t2: Hai cây cần so sánh
            
        Returns:
            int: Khoảng cách chỉnh sửa tối thiểu
        """
        self.best_cost = float('inf')
        self._branch_bound_helper(t1, t2, 0)
        return self.best_cost
    
    def _branch_bound_helper(self, t1, t2, current_cost):
        """Hàm đệ quy cho branch-and-bound"""
        # Ước lượng lower bound
        lower_bound = current_cost + self.estimate_lower_bound(t1, t2)
        
        if lower_bound >= self.best_cost:
            return  # Cắt tỉa nhánh này
        
        if not t1 and not t2:
            self.best_cost = min(self.best_cost, current_cost)
            return
        
        if not t1:
            cost = current_cost + self.sum_insert_cost([t2])
            self.best_cost = min(self.best_cost, cost)
            return
        
        if not t2:
            cost = current_cost + self.sum_delete_cost([t1])
            self.best_cost = min(self.best_cost, cost)
            return
        
        # Thử các phép biến đổi
        # Thay thế
        new_cost = current_cost + self.cost_substitute(t1.label, t2.label)
        children_cost = self.compute_children_cost(t1.children, t2.children)
        self.best_cost = min(self.best_cost, new_cost + children_cost)
        
        # Xóa
        for child in t1.children:
            self._branch_bound_helper(child, t2, 
                                    current_cost + self.cost_delete(t1.label))
        
        # Chèn
        for child in t2.children:
            self._branch_bound_helper(t1, child, 
                                    current_cost + self.cost_insert(t2.label))
    
    def estimate_lower_bound(self, t1, t2):
        """Ước lượng lower bound cho branch-and-bound"""
        size1 = self.count_nodes(t1)
        size2 = self.count_nodes(t2)
        return abs(size1 - size2)
    
    # 3. Phương pháp Divide-and-conquer
    def divide_conquer_ted(self, t1, t2):
        """
        Giải Tree Edit Distance bằng Divide-and-conquer
        
        Args:
            t1, t2: Hai cây cần so sánh
            
        Returns:
            int: Khoảng cách chỉnh sửa tối thiểu
        """
        if not t1 and not t2:
            return 0
        if not t1:
            return self.sum_insert_cost([t2])
        if not t2:
            return self.sum_delete_cost([t1])
        
        min_cost = float('inf')
        
        # Thay thế gốc
        substitute_cost = self.cost_substitute(t1.label, t2.label)
        substitute_cost += self.compute_children_cost(t1.children, t2.children)
        min_cost = min(min_cost, substitute_cost)
        
        # Xóa gốc t1
        delete_cost = self.cost_delete(t1.label)
        for child in t1.children:
            delete_cost += self.divide_conquer_ted(child, t2)
        min_cost = min(min_cost, delete_cost)
        
        # Chèn gốc t2
        insert_cost = self.cost_insert(t2.label)
        for child in t2.children:
            insert_cost += self.divide_conquer_ted(t1, child)
        min_cost = min(min_cost, insert_cost)
        
        return min_cost
    
    # 4. Phương pháp Dynamic Programming
    def dynamic_programming_ted(self, t1, t2):
        """
        Giải Tree Edit Distance bằng Dynamic Programming (Zhang-Shasha)
        
        Args:
            t1, t2: Hai cây cần so sánh
            
        Returns:
            int: Khoảng cách chỉnh sửa tối thiểu
        """
        if not t1 and not t2:
            return 0
        if not t1:
            return self.count_nodes(t2)
        if not t2:
            return self.count_nodes(t1)
        
        # Chuyển đổi cây thành dạng post-order
        post1 = self.get_post_order(t1)
        post2 = self.get_post_order(t2)
        
        n, m = len(post1), len(post2)
        
        # Khởi tạo bảng DP
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        
        # Trường hợp cơ sở
        for i in range(1, n + 1):
            dp[i][0] = dp[i-1][0] + self.cost_delete(post1[i-1].label)
        for j in range(1, m + 1):
            dp[0][j] = dp[0][j-1] + self.cost_insert(post2[j-1].label)
        
        # Điền bảng DP
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                # Xóa
                cost_del = dp[i-1][j] + self.cost_delete(post1[i-1].label)
                
                # Chèn
                cost_ins = dp[i][j-1] + self.cost_insert(post2[j-1].label)
                
                # Thay thế
                cost_sub = (dp[i-1][j-1] + 
                           self.cost_substitute(post1[i-1].label, post2[j-1].label))
                
                dp[i][j] = min(cost_del, cost_ins, cost_sub)
        
        return dp[n][m]
    
    def compute_children_cost(self, children1, children2):
        """Tính chi phí tối ưu để biến đổi danh sách cây con"""
        n, m = len(children1), len(children2)
        
        if n == 0:
            return self.sum_insert_cost(children2)
        if m == 0:
            return self.sum_delete_cost(children1)
        
        # Sử dụng DP đơn giản cho danh sách các cây con
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        
        for i in range(1, n + 1):
            dp[i][0] = dp[i-1][0] + self.sum_delete_cost([children1[i-1]])
        for j in range(1, m + 1):
            dp[0][j] = dp[0][j-1] + self.sum_insert_cost([children2[j-1]])
        
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                delete_cost = dp[i-1][j] + self.sum_delete_cost([children1[i-1]])
                insert_cost = dp[i][j-1] + self.sum_insert_cost([children2[j-1]])
                match_cost = (dp[i-1][j-1] + 
                             self.divide_conquer_ted(children1[i-1], children2[j-1]))
                
                dp[i][j] = min(delete_cost, insert_cost, match_cost)
        
        return dp[n][m]
    
    def print_tree(self, root, indent="", is_last=True):
        """In cây dưới dạng đồ họa"""
        if not root:
            return
        
        print(indent, end="")
        if is_last:
            print("└── ", end="")
            indent += "    "
        else:
            print("├── ", end="")
            indent += "│   "
        print(root.label)
        
        for i, child in enumerate(root.children):
            last = (i == len(root.children) - 1)
            self.print_tree(child, indent, last)
    
    def create_sample_tree1(self):
        """Tạo cây mẫu 1 để test"""
        root = TreeNode("A", 1)
        b = TreeNode("B", 2)
        c = TreeNode("C", 3)
        d = TreeNode("D", 4)
        e = TreeNode("E", 5)
        
        root.add_child(b)
        root.add_child(c)
        b.add_child(d)
        c.add_child(e)
        
        return root
    
    def create_sample_tree2(self):
        """Tạo cây mẫu 2 để test"""
        root = TreeNode("A", 1)
        c = TreeNode("C", 2)
        b = TreeNode("B", 3)
        e = TreeNode("E", 4)
        f = TreeNode("F", 5)
        
        root.add_child(c)
        root.add_child(b)
        c.add_child(e)
        c.add_child(f)
        
        return root
    
    def create_sample_tree3(self):
        """Tạo cây mẫu 3 để test (phức tạp hơn)"""
        root = TreeNode("X", 1)
        y = TreeNode("Y", 2)
        z = TreeNode("Z", 3)
        w = TreeNode("W", 4)
        
        root.add_child(y)
        y.add_child(z)
        y.add_child(w)
        
        return root
    
    def create_sample_tree4(self):
        """Tạo cây mẫu 4 để test (phức tạp hơn)"""
        root = TreeNode("A", 1)
        b = TreeNode("B", 2)
        c = TreeNode("C", 3)
        
        root.add_child(b)
        b.add_child(c)
        
        return root
    
    def benchmark_algorithms(self, tree1, tree2):
        """So sánh hiệu suất các thuật toán"""
        import time
        
        results = {}
        
        # Test Backtracking
        start_time = time.time()
        try:
            result = self.backtracking_ted(tree1, tree2)
            end_time = time.time()
            results['Backtracking'] = {
                'result': result,
                'time': end_time - start_time,
                'status': 'success'
            }
        except Exception as e:
            results['Backtracking'] = {
                'result': None,
                'time': 0,
                'status': f'error: {str(e)}'
            }
        
        # Test Branch-and-bound
        start_time = time.time()
        try:
            result = self.branch_bound_ted(tree1, tree2)
            end_time = time.time()
            results['Branch-and-bound'] = {
                'result': result,
                'time': end_time - start_time,
                'status': 'success'
            }
        except Exception as e:
            results['Branch-and-bound'] = {
                'result': None,
                'time': 0,
                'status': f'error: {str(e)}'
            }
        
        # Test Divide-and-conquer
        start_time = time.time()
        try:
            result = self.divide_conquer_ted(tree1, tree2)
            end_time = time.time()
            results['Divide-and-conquer'] = {
                'result': result,
                'time': end_time - start_time,
                'status': 'success'
            }
        except Exception as e:
            results['Divide-and-conquer'] = {
                'result': None,
                'time': 0,
                'status': f'error: {str(e)}'
            }
        
        # Test Dynamic Programming
        start_time = time.time()
        try:
            result = self.dynamic_programming_ted(tree1, tree2)
            end_time = time.time()
            results['Dynamic Programming'] = {
                'result': result,
                'time': end_time - start_time,
                'status': 'success'
            }
        except Exception as e:
            results['Dynamic Programming'] = {
                'result': None,
                'time': 0,
                'status': f'error: {str(e)}'
            }
        
        return results
    
    def print_benchmark_results(self, results):
        """In kết quả benchmark"""
        print("\n=== BẢNG SO SÁNH HIỆU SUẤT ===")
        print(f"{'Phương pháp':<20} {'Kết quả':<10} {'Thời gian (s)':<15} {'Trạng thái':<15}")
        print("-" * 65)
        
        for method, data in results.items():
            result_str = str(data['result']) if data['result'] is not None else "N/A"
            time_str = f"{data['time']:.6f}" if data['time'] > 0 else "N/A"
            print(f"{method:<20} {result_str:<10} {time_str:<15} {data['status']:<15}")


def main():
    """Hàm main để test các phương pháp"""
    print("=== TREE EDIT DISTANCE - PYTHON IMPLEMENTATION ===\n")
    
    ted = TreeEditDistance()
    
    # Test case 1: Cây đơn giản
    print("TEST CASE 1: Cây đơn giản")
    print("-" * 40)
    
    tree1 = ted.create_sample_tree1()
    tree2 = ted.create_sample_tree2()
    
    print("Cây 1:")
    ted.print_tree(tree1)
    print()
    
    print("Cây 2:")
    ted.print_tree(tree2)
    print()
    
    # Benchmark các thuật toán
    results1 = ted.benchmark_algorithms(tree1, tree2)
    ted.print_benchmark_results(results1)
    
    print("\n" + "="*70 + "\n")
    
    # Test case 2: Cây phức tạp hơn
    print("TEST CASE 2: Cây phức tạp hơn")
    print("-" * 40)
    
    tree3 = ted.create_sample_tree3()
    tree4 = ted.create_sample_tree4()
    
    print("Cây 3:")
    ted.print_tree(tree3)
    print()
    
    print("Cây 4:")
    ted.print_tree(tree4)
    print()
    
    # Benchmark các thuật toán
    results2 = ted.benchmark_algorithms(tree3, tree4)
    ted.print_benchmark_results(results2)
    
    print("\n" + "="*70 + "\n")
    
    # Test case 3: Cây rỗng
    print("TEST CASE 3: Trường hợp đặc biệt (cây rỗng)")
    print("-" * 50)
    
    empty_tree = None
    single_node = TreeNode("X", 1)
    
    print("Test: Cây rỗng vs Cây rỗng")
    result_empty = ted.backtracking_ted(empty_tree, empty_tree)
    print(f"Kết quả: {result_empty}")
    
    print("\nTest: Cây rỗng vs Cây một nút")
    result_empty_single = ted.backtracking_ted(empty_tree, single_node)
    print(f"Kết quả: {result_empty_single}")
    
    print("\nTest: Cây một nút vs Cây rỗng")
    result_single_empty = ted.backtracking_ted(single_node, empty_tree)
    print(f"Kết quả: {result_single_empty}")
    
    print("\n=== KẾT THÚC DEMO ===")


if __name__ == "__main__":
    main()