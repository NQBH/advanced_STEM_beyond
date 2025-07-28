import random

class Tree:
    def __init__(self, n):
        self.n = n
        self.root = 0
        self.parent = [-1] * n
        self.children = [[] for _ in range(n)]

    def number_of_nodes(self):
        return self.n

    def add_child(self, p, c):
        self.children[p].append(c)
        self.parent[c] = p

def random_tree(n):
    T = Tree(n)
    for i in range(1, n):
        p = random.randint(0, i - 1)  #random parent in [0, i-1]
        T.add_child(p, i)
    return T

if __name__ == "__main__":
    n = 10
    T = random_tree(n)
    print(f"Root: {T.root}")
    for i in range(n):
        print(f"Node {i} has children: {T.children[i]}")