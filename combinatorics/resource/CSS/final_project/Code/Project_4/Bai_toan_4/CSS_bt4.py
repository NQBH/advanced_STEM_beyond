from collections import defaultdict

# Graph representations
class Graph:
    def __init__(self, vertices):
        self.n = vertices
        self.adjMatrix = [[0] * vertices for _ in range(vertices)]
        self.adjList = [[] for _ in range(vertices)]
        self.extAdjList = [[] for _ in range(vertices)]
        self.adjMap = [defaultdict(int) for _ in range(vertices)]

    def matrix_to_list(self):
        for i in range(self.n):
            self.adjList[i] = [j for j in range(self.n) if self.adjMatrix[i][j]]

    def list_to_matrix(self):
        self.adjMatrix = [[0] * self.n for _ in range(self.n)]
        for i in range(self.n):
            for j in self.adjList[i]:
                self.adjMatrix[i][j] = 1

# Tree representations
class Tree:
    def __init__(self, vertices):
        self.n = vertices
        self.parent = [-1] * vertices
        self.fcns = [{'firstChild': -1, 'nextSibling': -1} for _ in range(vertices)]
        self.graph = [[] for _ in range(vertices)]

    def parent_to_fcns(self):
        children = [[] for _ in range(self.n)]
        for i in range(self.n):
            if self.parent[i] != -1:
                children[self.parent[i]].append(i)
        for i in range(self.n):
            if children[i]:
                self.fcns[i]['firstChild'] = children[i][0]
                for j in range(len(children[i]) - 1):
                    self.fcns[children[i][j]]['nextSibling'] = children[i][j + 1]

# Example usage
if __name__ == "__main__":
    g = Graph(4)
    g.adjMatrix = [[0, 1, 1, 0], [1, 0, 0, 1], [1, 0, 0, 1], [0, 1, 1, 0]]
    g.matrix_to_list()
    print("Adjacency List:", g.adjList)

    t = Tree(5)
    t.parent = [-1, 0, 0, 1, 1]
    t.parent_to_fcns()
    print("FCNS:", t.fcns)