n = int(input("Nhap kich thuoc n: "))
A = [list(map(float, input().split())) for _ in range(n)]

diag = upper = lower = sym = True

for i in range(n):
    for j in range(n):
        if i != j and A[i][j] != 0: diag = False
        if i > j and A[i][j] != 0: upper = False
        if i < j and A[i][j] != 0: lower = False
        if A[i][j] != A[j][i]: sym = False

print("\nKet qua:")
print("La ma tran duong cheo" if diag else "Khong la ma tran duong cheo")
print("La ma tran tam giac tren" if upper else "Khong la ma tran tam giac tren")
print("La ma tran tam giac duoi" if lower else "Khong la ma tran tam giac duoi")
print("La ma tran doi xung" if sym else "Khong la ma tran doi xung")
