from collections import deque

class TreeNode:
    def __init__(self, label):
        self.label = label
        self.children = []

def top_down(node):
    if node is None:
        return
    queue = deque([node])
    while queue:
        curr = queue.popleft()
        print(curr.label, end=' ')
        for child in curr.children:
            queue.append(child)

root = TreeNode("A")
root.children = [TreeNode("B"), TreeNode("C"), TreeNode("D")]
root.children[0].children = [TreeNode("E"), TreeNode("F")]
root.children[1].children = [TreeNode("H")]
root.children[2].children = [TreeNode("G")]

top_down(root)