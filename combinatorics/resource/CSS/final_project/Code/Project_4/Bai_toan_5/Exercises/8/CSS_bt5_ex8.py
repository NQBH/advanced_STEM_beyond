import random

class Tree:
    def __init__(self, n):
        # n: so nut
        # adj: danh sach ke
        self.n = n
        self.adj = [[] for _ in range(n)]

    def add_edge(self, u, v):
        # Them canh (u,v)
        self.adj[u].append(v)
        self.adj[v].append(u)

    def generate_random_tree(self):
        # Sinh cay ngau nhien bang ma Prufer
        prufer = [random.randint(0, self.n - 1) for _ in range(self.n - 2)]
        degree = [1] * self.n
        for x in prufer:
            degree[x] += 1
        
        queue = [i for i in range(self.n) if degree[i] == 1]
        for x in prufer:
            u = queue.pop(0)
            self.add_edge(u, x)
            degree[x] -= 1
            degree[u] -= 1
            if degree[x] == 1:
                queue.append(x)
        
        u = [i for i in range(self.n) if degree[i] == 1][0]
        v = [i for i in range(self.n) if degree[i] == 1 and i != u][0]
        self.add_edge(u, v)

# Vi du su dung
if __name__ == "__main__":
    t = Tree(5)
    t.generate_random_tree()
    print("Random tree edges:", [(u, v) for u in range(t.n) for v in t.adj[u] if u < v])