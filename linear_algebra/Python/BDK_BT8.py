n = int(input("Nhap so nguyen     nha : "))

ma_tran_0 = []
for i in range(n):
    rows = []
    for j in range(n):
        rows.append(0)
    ma_tran_0.append(rows)

unit_ma_tran = []
for i in range(n):
    rows = []
    for j in range(n):
        if i == j:
            rows.append(1)
        else:
            rows.append(0)
    unit_ma_tran.append(rows)

print(f"\nMa trankich thuoc {n}x{n}:")
for rows in ma_tran_0:
    for phan_tu in rows:
        print(phan_tu, end=" ")
    print()

print(f"\nMa tran don vi kich thuoc {n}x{n}:")
for rows in unit_ma_tran:
    for phan_tu in rows:
        print(phan_tu, end=" ")
    print()