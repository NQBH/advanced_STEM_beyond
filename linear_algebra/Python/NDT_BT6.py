m , n = map(int, input(" nhap so hang m va so cot n cua ma tran A: ").split())
A = []
print( " nhap ma tran A: " )
for i in range(m):
    row = list(map(int, input().split()))
    A.append(row)

k = int(input("nhap kich thuoc vector b:"))
b = list(map(float, input("nhap vector b: ").split()))
if k!= m:
    print("impossible")
else:
    print(" ma tran bo sung [A|b] la:")
    for i in range(m):
        print(A[i], "|", b[i])  