m, n = map(int, input("Nhap so hang m va so cot n cua ma tran A: ").split())

A = []
print("Nhap cac phan tu cua ma tran A:")
for i in range(m):
    A.append(list(map(float,input().split())))

k = int(input("Nhap kich thuoc vector b: "))
b = list(map(float, input("Nhap cac phan tu cua vector b: ").split()))

if k != m:
    print("Impossible")
else:
    print("Ma tran bo sung [A][b]:")
    for i in range(m):
        print(*A[i], "|", b[i])