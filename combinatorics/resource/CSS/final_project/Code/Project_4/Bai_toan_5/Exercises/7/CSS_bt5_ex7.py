from collections import deque

class Tree:
    def __init__(self, n):
        # n: so nut
        # adj: danh sach ke
        self.n = n
        self.adj = [[] for _ in range(n)]

    def add_edge(self, u, v):
        # Them canh (u,v)
        self.adj[u].append(v)

    def generate_complete_binary(self):
        # Sinh cay nhi phan day du
        if self.n == 0:
            return
        queue = deque([0])
        i = 1
        while queue and i < self.n:
            u = queue.popleft()
            if i < self.n:
                self.add_edge(u, i)
                queue.append(i)
                i += 1
            if i < self.n:
                self.add_edge(u, i)
                queue.append(i)
                i += 1

# Vi du su dung
if __name__ == "__main__":
    t = Tree(7)
    t.generate_complete_binary()
    print("Complete binary tree edges:", 
          [(u, v) for u in range(t.n) for v in t.adj[u]])