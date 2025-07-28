class TreeNode:
    def __init__(self, label):
        self.label = label
        self.children = []

def preorder(node):
    if node is None:
        return
    print(node.label, end=' ')
    for child in node.children:
        preorder(child)

root = TreeNode("A")
root.children = [TreeNode("B"), TreeNode("C"), TreeNode("D")]
root.children[0].children = [TreeNode("E"), TreeNode("F")]
root.children[1].children = [TreeNode("H")]
root.children[2].children = [TreeNode("G")]

preorder(root)