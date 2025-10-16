# Nhập kích thước của ma trận A
m, n = map(int, input("Nhap so hang m va so cot n cua ma tran A: ").split())

# Nhập ma trận A
A = []
print(f"Nhap ma tran A ({m}x{n}):")
for i in range(m):
    row = list(map(float, input().split()))
    A.append(row)

# Nhập vector b
mb = int(input("Nhap so phan tu cua vector b: "))
print(f"Nhap vector b ({mb} phan tu):")
b = list(map(float, input().split()))

# Kiểm tra kích cỡ
if m != mb:
    print("Impossible")
else:
    print("Ma tran bo sung [A|b]:")
    for i in range(m):
        print(*A[i], "|", b[i])
