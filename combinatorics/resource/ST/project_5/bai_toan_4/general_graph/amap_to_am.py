n = int(input("Nhap so dinh: "))
num_keys = int(input("Nhap so dinh co trong AMap: "))

# Khoi tao ma tran ke n x n voi toan 0
adj_matrix = [[0 for _ in range(n)] for _ in range(n)]

print("Nhap AMap (u, so dinh ke, cac cap v w):")
for _ in range(num_keys):
    parts = input().split()
    u = int(parts[0])
    k = int(parts[1])
    for i in range(k):
        v = int(parts[2 + 2 * i])
        w = int(parts[3 + 2 * i])
        adj_matrix[u][v] = w  # Gan trong so w cho canh tu u den v

# In ma tran ke
print("Ma tran ke (AM):")
for row in adj_matrix:
    print(" ".join(map(str, row)))