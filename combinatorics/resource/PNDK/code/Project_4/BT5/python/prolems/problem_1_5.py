class TreeNode:
    def __init__(self, val):
        self.val = val
        self.first_child = None
        self.next_sibling = None
        self.parent = None
        self.last_child = None      # con cuối cùng
        self.child_count = 0        # số con

class Tree:
    def __init__(self):
        self.root_node = None
    
    def root(self):
        """O(1)"""
        return self.root_node
    
    def number_of_children(self, v):
        """O(1)"""
        if v is None:
            return 0
        return v.child_count
    
    def children(self, v):
        """O(số con)"""
        if v is None:
            return []
        result = []
        child = v.first_child
        while child:
            result.append(child)
            child = child.next_sibling
        return result
    
    def add_child(self, parent, child_val):
        """Thêm con với thời gian O(1)"""
        child_node = TreeNode(child_val)
        child_node.parent = parent
        
        if parent.first_child is None:
            # Nút đầu tiên
            parent.first_child = child_node
            parent.last_child = child_node
        else:
            # Thêm vào cuối
            parent.last_child.next_sibling = child_node
            parent.last_child = child_node
        
        parent.child_count += 1
        return child_node

def main():
    # Tạo cây ví dụ
    tree = Tree()
    root = TreeNode(1)
    tree.root_node = root
    
    # Thêm con
    child2 = tree.add_child(root, 2)
    child3 = tree.add_child(root, 3)
    tree.add_child(child2, 4)
    tree.add_child(child2, 5)
    
    print("Tree structure:")
    print(f"Root: {tree.root().val}")
    print(f"Number of children of root: {tree.number_of_children(root)}")
    
    children = tree.children(root)
    print("Children of root:")
    for child in children:
        print(f"  Child: {child.val}, Number of its children: {tree.number_of_children(child)}")

if __name__ == "__main__":
    main()