m, n = map(int, input("Nhap so hang va so cot cua A: ").split())

A = []
print("Nhap ma tran A:")
for i in range(m):
    A.append(list(map(int, input().split())))

AT = [[A[j][i] for j in range(m)] for i in range(n)]

print("Ma tran chuyen vi AT la:")
for i in range(n):
    for j in range(m):
        print(AT[i][j], end=" ")
    print()
