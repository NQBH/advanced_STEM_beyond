# Ham chuyen tu ma tran ke sang danh sach ke
def adjacency_matrix_to_list(matrix):
    n = len(matrix)  # So dinh cua do thi = kich thuoc cua ma tran
    adj_list = [[] for _ in range(n)]  # Khoi tao danh sach ke rong cho moi dinh

    for i in range(n):  # Duyet tung dinh i
        for j in range(n):  # Duyet tung dinh j
            if matrix[i][j] != 0:  # Neu co canh tu i den j
                adj_list[i].append(j)  # Them j vao danh sach ke cua i

    return adj_list  # Tra ve danh sach ke

# Ham in danh sach ke ra man hinh
def print_adjacency_list(adj_list):
    for i, neighbors in enumerate(adj_list):  # Duyet qua tung dinh va danh sach ke tuong ung
        print(f"{i}: {neighbors}")  # In dinh i va cac dinh ke voi no

# Vi du: do thi 4 dinh
adj_matrix = [
    [0, 1, 0, 0],  # Dinh 0 ke voi dinh 1
    [1, 0, 1, 1],  # Dinh 1 ke voi 0, 2, 3
    [0, 1, 0, 1],  # Dinh 2 ke voi 1, 3
    [0, 1, 1, 0]   # Dinh 3 ke voi 1, 2
]

# Goi ham chuyen doi va in ket qua
adj_list = adjacency_matrix_to_list(adj_matrix)
print_adjacency_list(adj_list)