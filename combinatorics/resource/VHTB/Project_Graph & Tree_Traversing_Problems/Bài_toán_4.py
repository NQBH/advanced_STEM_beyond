def matrix_to_list(matrix):
    adj_list = {}
    for i, row in enumerate(matrix):
        adj_list[i] = [j for j, val in enumerate(row) if val]
    return adj_list

def list_to_matrix(adj_list):
    n = len(adj_list)
    matrix = [[0]*n for _ in range(n)]
    for i, neighbors in adj_list.items():
        for j in neighbors:
            matrix[i][j] = 1
    return matrix

matrix = [
    [0,1,0,1],
    [1,0,1,0],
    [0,1,0,1],
    [1,0,1,0]
]

adj_list = matrix_to_list(matrix)
print("Adjacency List:", adj_list)

new_matrix = list_to_matrix(adj_list)
print("Back to Matrix:")
for row in new_matrix:
    print(row)
