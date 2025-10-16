# CAU 1
m, n = map(int, input("Nhap so hang va so cot: ").split())
A = []
for i in range(m):
    dong = list(map(int, input(f"Nhap hang {i+1}: ").split()))
    A.append(dong)

print("Ma tran vua nhap:")
for i in range(m):
    for j in range(n):
        print(A[i][j], end=" ")
    print()
'''

'''
# CAU 2
m, n = map(int, input("Nhap so hang va so cot: ").split())
print("Nhap ma tran A:")
A = [list(map(int, input().split())) for _ in range(m)]
print("Nhap ma tran B:")
B = [list(map(int, input().split())) for _ in range(m)]

print("Tong 2 ma tran:")
for i in range(m):
    for j in range(n):
        print(A[i][j] + B[i][j], end=" ")
    print()

print("Hieu 2 ma tran:")
for i in range(m):
    for j in range(n):
        print(A[i][j] - B[i][j], end=" ")
    print()

# CAU 3
m, n = map(int, input("Nhap so hang va so cot: ").split())
A = [list(map(int, input().split())) for _ in range(m)]
c = int(input("Nhap so c: "))

print("Ma tran sau khi nhan voi", c, ":")
for i in range(m):
    for j in range(n):
        print(A[i][j] * c, end=" ")
    print()

# CAU 4
m, n = map(int, input("Nhap hang(A) va cot(A): ").split())
A = [list(map(int, input().split())) for _ in range(m)]

n2, p = map(int, input("Nhap hang(B) va cot(B) ").split())
B = [list(map(int, input().split())) for _ in range(n2)]

if n != n2:
    print("Khong nhan duoc vi so cot A != so hang B")
else:
    C = [[sum(A[i][k] * B[k][j] for k in range(n)) for j in range(p)] for i in range(m)]
    print("Tich A*B:")
    for row in C:
        print(*row)

# CAU 5
m, n = map(int, input("Nhap so hang va so cot: ").split())
A = [list(map(int, input().split())) for _ in range(m)]

print("Ma tran chuyen vi:")
for j in range(n):
    for i in range(m):
        print(A[i][j], end=" ")
    print()