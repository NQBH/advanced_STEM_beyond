class TreeNode:
    def __init__(self, label):
        self.label = label
        self.children = []

def postorder(node):
    if node is None:
        return
    for child in node.children:
        postorder(child)
    print(node.label, end=' ')

root = TreeNode("A")
root.children = [TreeNode("B"), TreeNode("C"), TreeNode("D")]
root.children[0].children = [TreeNode("E"), TreeNode("F")]
root.children[1].children = [TreeNode("H")]
root.children[2].children = [TreeNode("G")]

postorder(root)