# Ham chuyen tu ma tran ke co trong so sang danh sach ke mo rong (EAL)
def adjacency_matrix_to_extended_list(matrix):
    n = len(matrix)  # So dinh cua do thi = so dong cua ma tran
    adj_list = [[] for _ in range(n)]  # Khoi tao danh sach ke rong cho tung dinh

    for i in range(n):  # Duyet tung dinh i
        for j in range(n):  # Duyet tung dinh j
            weight = matrix[i][j]  # Lay trong so canh tu i den j
            if weight != 0:  # Neu co canh (tuc la trong so khac 0)
                adj_list[i].append((j, weight))  # Them (j, trong so) vao danh sach ke cua i

    return adj_list  # Tra ve danh sach ke mo rong

# Ham in danh sach ke mo rong ra man hinh
def print_extended_adj_list(adj_list):
    for i, neighbors in enumerate(adj_list):
        line = ", ".join([f"({v}, {w})" for v, w in neighbors])  # Chuyen danh sach thanh chuoi
        print(f"{i}: {line}")  # In danh sach cua tung dinh

# Vi du: ma tran ke co trong so
adj_matrix = [
    [0, 2, 0, 0],  # Dinh 0 ke voi 1, trong so 2
    [2, 0, 3, 1],  # Dinh 1 ke voi 0, 2, 3
    [0, 3, 0, 4],  # Dinh 2 ke voi 1, 3
    [0, 1, 4, 0]   # Dinh 3 ke voi 1, 2
]

# Chuyen va in danh sach ke mo rong
adj_list = adjacency_matrix_to_extended_list(adj_matrix)
print_extended_adj_list(adj_list)