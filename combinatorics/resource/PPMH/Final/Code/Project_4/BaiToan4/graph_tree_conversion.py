from collections import defaultdict

def matrix_to_list(matrix):
    adj_list = [[] for _ in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if matrix[i][j] != 0:
                adj_list[i].append((j, matrix[i][j]))
    return adj_list

def list_to_matrix(adj_list):
    n = len(adj_list)
    matrix = [[0]*n for _ in range(n)]
    for u in range(n):
        for v, w in adj_list[u]:
            matrix[u][v] = w
    return matrix

def list_to_map(adj_list):
    adj_map = [dict() for _ in range(len(adj_list))]
    for u in range(len(adj_list)):
        for v, w in adj_list[u]:
            adj_map[u][v] = w
    return adj_map

class TreeNode:
    def __init__(self, id):
        self.id = id
        self.children = []

class FCNSNode:
    def __init__(self, id):
        self.id = id
        self.first_child = None
        self.next_sibling = None

def array_to_fcns(parent):
    n = len(parent)
    nodes = [FCNSNode(i) for i in range(n)]
    root = None
    last_child = [None] * n

    for i in range(n):
        p = parent[i]
        if p == -1:
            root = nodes[i]
        else:
            if not nodes[p].first_child:
                nodes[p].first_child = nodes[i]
            else:
                last_child[p].next_sibling = nodes[i]
            last_child[p] = nodes[i]
    return root