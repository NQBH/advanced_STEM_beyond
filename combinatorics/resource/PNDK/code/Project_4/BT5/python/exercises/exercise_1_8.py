import random

class TreeNode:
    def __init__(self, val=0):
        self.val = val
        self.left = None
        self.right = None

class RandomTreeGenerator:
    @staticmethod
    def create_random_tree(n):

        if n <= 0:
            return None
        
        # Tạo danh sách nút
        nodes = [TreeNode(i) for i in range(1, n + 1)]
        
        # Nút đầu tiên là gốc
        root = nodes[0]
        used_nodes = {0}  # Chỉ số các nút đã được sử dụng
        available_parents = [0]  # Các nút có thể thêm con
        
        # Thêm n-1 nút còn lại
        for i in range(1, n):
            # Chọn ngẫu nhiên một nút cha từ các nút đã có
            parent_idx = random.choice(available_parents)
            parent = nodes[parent_idx]
            
            # Chọn thêm vào trái hay phải (nếu cả hai trống)
            if parent.left is None and parent.right is None:
                if random.choice([True, False]):
                    parent.left = nodes[i]
                else:
                    parent.right = nodes[i]
            elif parent.left is None:
                parent.left = nodes[i]
            else:
                parent.right = nodes[i]
            
            # Thêm nút mới vào danh sách các nút có thể làm cha
            available_parents.append(i)
        
        return root
    
    @staticmethod
    def count_nodes(root):
        """Đếm số nút trong cây"""
        if not root:
            return 0
        return 1 + RandomTreeGenerator.count_nodes(root.left) + RandomTreeGenerator.count_nodes(root.right)
    
    @staticmethod
    def print_tree_structure(root, level=0, prefix="Root: "):
        """In cấu trúc cây"""
        if root is not None:
            print(" " * (level * 4) + prefix + str(root.val))
            if root.left is not None or root.right is not None:
                if root.left:
                    RandomTreeGenerator.print_tree_structure(root.left, level + 1, "L--- ")
                else:
                    print(" " * ((level + 1) * 4) + "L--- None")
                if root.right:
                    RandomTreeGenerator.print_tree_structure(root.right, level + 1, "R--- ")
                else:
                    print(" " * ((level + 1) * 4) + "R--- None")

def main():
    gen = RandomTreeGenerator()
    
    print("Random Tree with 6 nodes:")
    root = gen.create_random_tree(6)
    
    print("Tree structure:")
    gen.print_tree_structure(root)
    
    print(f"\nNumber of nodes: {gen.count_nodes(root)}")
    
    print("\nGenerating another random tree:")
    root2 = gen.create_random_tree(6)
    gen.print_tree_structure(root2)

if __name__ == "__main__":
    # Đặt seed để kết quả có thể tái tạo (tùy chọn)
    random.seed(42)
    main()