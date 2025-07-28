class TreeNode:
    def __init__(self, label):
        self.label = label
        self.children = []

# (a) Backtracking
class BacktrackingTED:
    def __init__(self, T1, T2):
        self.T1 = T1
        self.T2 = T2
        self.n1, self.n2 = len(T1), len(T2)

    def ted(self, i, j):
        if i == -1 and j == -1:
            return 0
        if i == -1:
            return j + 1
        if j == -1:
            return i + 1

        relabel_cost = 0 if self.T1[i].label == self.T2[j].label else 1
        min_cost = float('inf')

        for k in range(len(self.T1[i].children)):
            for l in range(len(self.T2[j].children)):
                min_cost = min(min_cost, self.ted(self.T1[i].children[k] if k < len(self.T1[i].children) else -1,
                                                 self.T2[j].children[l] if l < len(self.T2[j].children) else -1) + relabel_cost)
        min_cost = min(min_cost, self.ted(self.T1[i].children[0] if self.T1[i].children else -1, j) + 1)
        min_cost = min(min_cost, self.ted(i, self.T2[j].children[0] if self.T2[j].children else -1) + 1)

        return min_cost

# (b) Branch-and-Bound
class BranchAndBoundTED:
    def __init__(self, T1, T2):
        self.T1 = T1
        self.T2 = T2
        self.n1, self.n2 = len(T1), len(T2)
        self.best_cost = float('inf')

    def ted(self, i, j, cost):
        if cost >= self.best_cost:
            return float('inf')
        if i == -1 and j == -1:
            self.best_cost = min(self.best_cost, cost)
            return cost
        if i == -1:
            return cost + j + 1
        if j == -1:
            return cost + i + 1

        relabel_cost = 0 if self.T1[i].label == self.T2[j].label else 1
        min_cost = float('inf')

        for k in range(len(self.T1[i].children)):
            for l in range(len(self.T2[j].children)):
                min_cost = min(min_cost, self.ted(self.T1[i].children[k] if k < len(self.T1[i].children) else -1,
                                                 self.T2[j].children[l] if l < len(self.T2[j].children) else -1, cost + relabel_cost))
        min_cost = min(min_cost, self.ted(self.T1[i].children[0] if self.T1[i].children else -1, j, cost + 1))
        min_cost = min(min_cost, self.ted(i, self.T2[j].children[0] if self.T2[j].children else -1, cost + 1))

        return min_cost

# (c) Divide-and-Conquer
class DivideAndConquerTED:
    def __init__(self, T1, T2):
        self.T1 = T1
        self.T2 = T2
        self.n1, self.n2 = len(T1), len(T2)
        self.D = [[float('inf')] * (self.n2 + 1) for _ in range(self.n1 + 1)]

    def ted(self, i, j):
        if self.D[i + 1][j + 1] != float('inf'):
            return self.D[i + 1][j + 1]
        if i == -1 and j == -1:
            return 0
        if i == -1:
            return j + 1
        if j == -1:
            return i + 1

        relabel_cost = 0 if self.T1[i].label == self.T2[j].label else 1
        min_cost = float('inf')

        for k in range(len(self.T1[i].children)):
            for l in range(len(self.T2[j].children)):
                min_cost = min(min_cost, self.ted(self.T1[i].children[k] if k < len(self.T1[i].children) else -1,
                                                 self.T2[j].children[l] if l < len(self.T2[j].children) else -1) + relabel_cost)
        min_cost = min(min_cost, self.ted(self.T1[i].children[0] if self.T1[i].children else -1, j) + 1)
        min_cost = min(min_cost, self.ted(i, self.T2[j].children[0] if self.T2[j].children else -1) + 1)

        self.D[i + 1][j + 1] = min_cost
        return min_cost

# (d) Dynamic Programming
class DynamicProgrammingTED:
    def __init__(self, T1, T2):
        self.T1 = T1
        self.T2 = T2
        self.n1, self.n2 = len(T1), len(T2)
        self.F = [[float('inf')] * (self.n2 + 1) for _ in range(self.n1 + 1)]
        self.D = [[float('inf')] * (self.n2 + 1) for _ in range(self.n1 + 1)]

    def ted(self, i, j):
        if self.D[i + 1][j + 1] != float('inf'):
            return self.D[i + 1][j + 1]
        if i == -1 and j == -1:
            return 0
        if i == -1:
            return j + 1
        if j == -1:
            return i + 1

        self.F[0][0] = 0
        for i1 in range(1, i + 2):
            self.F[i1][0] = self.F[i1-1][0] + 1
        for j1 in range(1, j + 2):
            self.F[0][j1] = self.F[0][j1-1] + 1

        for i1 in range(1, i + 2):
            for j1 in range(1, j + 2):
                relabel_cost = 0 if self.T1[i1-1].label == self.T2[j1-1].label else 1
                self.F[i1][j1] = min(
                    self.F[i1-1][j1] + 1,  # Delete
                    self.F[i1][j1-1] + 1,  # Insert
                    self.F[i1-1][j1-1] + relabel_cost  # Relabel
                )
        self.D[i + 1][j + 1] = self.F[i + 1][j + 1]
        return self.D[i + 1][j + 1]

# Example usage
if __name__ == "__main__":
    T1 = [TreeNode('a'), TreeNode('b'), TreeNode('c')]
    T1[0].children = [1, 2]
    T2 = [TreeNode('a'), TreeNode('b'), TreeNode('d')]
    T2[0].children = [1, 2]

    bt = BacktrackingTED(T1, T2)
    print(f"Backtracking TED: {bt.ted(0, 0)}")

    bnb = BranchAndBoundTED(T1, T2)
    print(f"Branch-and-Bound TED: {bnb.ted(0, 0, 0)}")

    dc = DivideAndConquerTED(T1, T2)
    print(f"Divide-and-Conquer TED: {dc.ted(0, 0)}")

    dp = DynamicProgrammingTED(T1, T2)
    print(f"Dynamic Programming TED: {dp.ted(2, 2)}")