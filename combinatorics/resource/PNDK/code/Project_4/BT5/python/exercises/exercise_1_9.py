class ArrayOfParentsTree:
    def __init__(self, parents):
        """
        parents[i] là chỉ số của cha nút i
        parents[root] = -1
        """
        self.parents = parents
    
    def previous_sibling(self, v):
        """
        Tìm anh/em trai trước của nút v
        Trả về chỉ số của previous sibling, hoặc -1 nếu không có
        """
        if v < 0 or v >= len(self.parents):
            return -1
        
        parent = self.parents[v]
        if parent == -1:  # Là nút gốc
            return -1
        
        # Tìm tất cả các con của cha
        siblings = []
        for i in range(len(self.parents)):
            if self.parents[i] == parent:
                siblings.append(i)
        
        # Tìm vị trí của v trong danh sách anh em
        try:
            idx = siblings.index(v)
            if idx > 0:
                return siblings[idx - 1]
            else:
                return -1  # Là con cả
        except ValueError:
            return -1
    
    def get_siblings(self, v):
        """Lấy tất cả anh em của nút v"""
        if v < 0 or v >= len(self.parents):
            return []
        
        parent = self.parents[v]
        if parent == -1:
            return []  # Nút gốc không có anh em
        
        siblings = []
        for i in range(len(self.parents)):
            if self.parents[i] == parent:
                siblings.append(i)
        
        return siblings

def main():

    parents = [-1, 0, 0, 1, 1, 2]
    tree = ArrayOfParentsTree(parents)
    
    print("Tree structure:")
    print("Node 0: root (parent = -1)")
    print("Node 1, 2: children of 0")
    print("Node 3, 4: children of 1") 
    print("Node 5: child of 2")
    
    print(f"\nSiblings of node 1: {tree.get_siblings(1)}")
    print(f"Previous sibling of node 2: {tree.previous_sibling(2)}")  # Node 1
    print(f"Previous sibling of node 4: {tree.previous_sibling(4)}")  # Node 3
    print(f"Previous sibling of node 1: {tree.previous_sibling(1)}")  # -1 (con cả)
    print(f"Previous sibling of node 0: {tree.previous_sibling(0)}")  # -1 (gốc)

if __name__ == "__main__":
    main()