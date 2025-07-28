# Ham chuyen ma tran ke sang ban do ke (adjacency map)
def adjacency_matrix_to_map(matrix):
    n = len(matrix)
    adj_map = {}  # Khoi tao dict chinh

    for i in range(n):  # Duyet tung dinh i
        neighbors = {}  # Dict con chua dinh ke cua i
        for j in range(n):  # Duyet tung dinh j
            weight = matrix[i][j]
            if weight != 0:  # Neu co canh tu i den j
                neighbors[j] = weight  # Ghi lai j voi trong so
        adj_map[i] = neighbors  # Gan danh sach ke vao i

    return adj_map

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
matrix = []
print("Nhap ma tran ke:")
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

adj_map = adjacency_matrix_to_map(matrix)

# In ket qua
print("Adjacency Map:")
for u in adj_map:
    print(f"{u}: {adj_map[u]}")