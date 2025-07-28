import random

class TreeNode:
    def __init__(self, id):
        self.id = id
        self.children = []

def generate_random_tree(n):
    if n <= 0:
        return None

    nodes = [TreeNode(1)] 

    for i in range(2, n + 1):
        new_node = TreeNode(i)
        parent = random.choice(nodes)
        parent.children.append(new_node)
        nodes.append(new_node)

    return nodes[0]  

def print_tree(node, level=0):
    print(' ' * 2 * level + f'Node {node.id}')
    for child in node.children:
        print_tree(child, level + 1)

n = int(input("Nhập số nút n: "))
root = generate_random_tree(n)
print("\nCây ngẫu nhiên được sinh:")
print_tree(root)