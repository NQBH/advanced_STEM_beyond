m, n = map(int, input("Nhap so hang va so cot cua ma tran A: ").split())
A = []
print("Nhap cac phan tu cua ma tran A:")
for i in range(m):
    A.append(list(map(int, input().split())))

p = int(input("Nhap kich thuoc vector b: "))
b = list(map(int, input("Nhap cac phan tu cua b: ").split()))

if m != p:
    print("Impossible")
else:
    print("Ma tran bo sung [A|b] la:")
    for i in range(m):
        for j in range(n):
            print(A[i][j], end=" ")
        print(b[i])
