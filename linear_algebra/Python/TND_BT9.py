n = int(input("Nhập n: "))

A = []
print(f"\nNhập giá trị cho ma trận A ({n}x{n}):")
for i in range(n):
    row = []
    for j in range(n):
        x = float(input(f"A[{i}][{j}] = "))
        row.append(x)
    A.append(row)

print("\nMa trận A:")
for i in range(n):
    for j in range(n):
        print(A[i][j], end=" ")
    print()

duong_cheo = True
tam_giac_tren = True
tam_giac_duoi = True
doi_xung = True

for i in range(n):
    for j in range(n):
        if i != j and A[i][j] != 0:
            duong_cheo = False
        if i > j and A[i][j] != 0:
            tam_giac_tren = False
        if i < j and A[i][j] != 0:
            tam_giac_duoi = False
        if A[i][j] != A[j][i]:
            doi_xung = False

print("\nKết quả kiểm tra:")
print(f"- Ma trận đường chéo: {'Có' if duong_cheo else 'Không'}")
print(f"- Ma trận tam giác trên: {'Có' if tam_giac_tren else 'Không'}")
print(f"- Ma trận tam giác dưới: {'Có' if tam_giac_duoi else 'Không'}")
print(f"- Ma trận đối xứng: {'Có' if doi_xung else 'Không'}")
