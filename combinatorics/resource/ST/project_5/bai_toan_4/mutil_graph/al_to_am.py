def al_to_am(adj_list):
    n = len(adj_list)
    matrix = [[0]*n for _ in range(n)]  # Khoi tao ma tran 0

    for i in range(n):
        for j in adj_list[i]:
            matrix[i][j] += 1  # Tang dem so canh tu i den j

    return matrix

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
adj_list = []

print("Nhap danh sach ke:")
for i in range(n):
    row = list(map(int, input(f"Ke cua dinh {i}: ").split()))
    adj_list.append(row)

# Chuyen doi va in ket qua
matrix = al_to_am(adj_list)
print("Ma tran ke:")
for row in matrix:
    print(" ".join(map(str, row)))