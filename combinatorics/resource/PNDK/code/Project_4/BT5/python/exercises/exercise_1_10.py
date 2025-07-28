class ExtendedFirstChildNextSiblingTree:
    def __init__(self, size):
        """Khởi tạo cây với size nút (đánh số từ 0 đến size-1)"""
        self.size = size
        # Mỗi nút có: [first_child, next_sibling, parent, last_child, child_count]
        self.nodes = [[-1, -1, -1, -1, 0] for _ in range(size)]
        self.root_node = -1
    
    def set_root(self, node):
        """Đặt nút gốc"""
        if 0 <= node < self.size:
            self.root_node = node
    
    def root(self):
        """O(1) - Trả về nút gốc"""
        return self.root_node
    
    def number_of_children(self, v):
        """O(1) - Trả về số con của nút v"""
        if 0 <= v < self.size:
            return self.nodes[v][4]  # child_count
        return 0
    
    def children(self, v):
        """O(k) - Trả về danh sách con của nút v, k là số con"""
        if not (0 <= v < self.size):
            return []
        
        result = []
        child = self.nodes[v][0]  # first_child
        while child != -1:
            result.append(child)
            child = self.nodes[child][1]  # next_sibling
        return result
    
    def add_child(self, parent, child):
        """O(1) - Thêm con vào nút cha"""
        if not (0 <= parent < self.size and 0 <= child < self.size):
            return False
        
        # Cập nhật parent của child
        self.nodes[child][2] = parent
        
        if self.nodes[parent][0] == -1:
            # Nút đầu tiên
            self.nodes[parent][0] = child  # first_child
            self.nodes[parent][3] = child  # last_child
        else:
            # Thêm vào cuối danh sách anh em
            last_child = self.nodes[parent][3]
            self.nodes[last_child][1] = child  # next_sibling
            self.nodes[parent][3] = child      # cập nhật last_child
        
        self.nodes[parent][4] += 1  # tăng child_count
        return True
    
    def first_child(self, v):
        """O(1) - Trả về con đầu tiên"""
        if 0 <= v < self.size:
            return self.nodes[v][0]
        return -1
    
    def next_sibling(self, v):
        """O(1) - Trả về anh em kế tiếp"""
        if 0 <= v < self.size:
            return self.nodes[v][1]
        return -1
    
    def parent(self, v):
        """O(1) - Trả về cha của nút v"""
        if 0 <= v < self.size:
            return self.nodes[v][2]
        return -1

def main():
    tree = ExtendedFirstChildNextSiblingTree(6)
    tree.set_root(0)
    
    tree.add_child(0, 1)
    tree.add_child(0, 2)
    tree.add_child(0, 3)
    tree.add_child(1, 4)
    tree.add_child(1, 5)
    
    print("Extended First-Child Next-Sibling Tree:")
    print(f"Root: {tree.root()}")
    print(f"Number of children of node 0: {tree.number_of_children(0)}")
    print(f"Children of node 0: {tree.children(0)}")
    print(f"Children of node 1: {tree.children(1)}")
    print(f"Parent of node 1: {tree.parent(1)}")
    print(f"First child of node 0: {tree.first_child(0)}")
    print(f"Next sibling of node 1: {tree.next_sibling(1)}")

if __name__ == "__main__":
    main()