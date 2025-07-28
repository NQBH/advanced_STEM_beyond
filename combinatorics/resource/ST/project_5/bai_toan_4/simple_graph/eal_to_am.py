# Ham chuyen danh sach ke mo rong sang ma tran ke
def extended_list_to_matrix(eal, n):
    matrix = [[0] * n for _ in range(n)]  # Khoi tao ma tran toan 0

    for i in range(n):
        for (j, w) in eal[i]:  # Duyet tung canh (j, trong so)
            matrix[i][j] = w  # Ghi trong so vao ma tran

    return matrix

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
eal = []

print("Nhap danh sach ke mo rong:")
for i in range(n):
    line = input(f"Dinh {i} (dinh,trongso cach nhau boi space): ")
    pairs = []
    if line.strip() != "":
        tokens = line.split()
        for token in tokens:
            u, w = map(int, token.strip("()").split(","))
            pairs.append((u, w))
    eal.append(pairs)

# Chuyen doi va in ra
matrix = extended_list_to_matrix(eal, n)

print("Ma tran ke:")
for row in matrix:
    print(" ".join(map(str, row)))