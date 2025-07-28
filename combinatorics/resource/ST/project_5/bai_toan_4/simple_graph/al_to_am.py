# Ham chuyen danh sach ke sang ma tran ke
def adjacency_list_to_matrix(adj_list, n):
    matrix = [[0]*n for _ in range(n)]  # Khoi tao ma tran n x n toan 0

    for i in range(n):  # Duyet qua tung dinh
        for j in adj_list[i]:  # Duyet tung dinh ke cua i
            matrix[i][j] = 1  # Ghi nhan canh tu i den j

    return matrix

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
adj_list = []

print("Nhap danh sach ke:")
for i in range(n):
    line = list(map(int, input(f"Dinh {i}: ").split()))
    adj_list.append(line)

adj_matrix = adjacency_list_to_matrix(adj_list, n)

# In ma tran ke
print("Ma tran ke:")
for row in adj_matrix:
    print(' '.join(map(str, row)))