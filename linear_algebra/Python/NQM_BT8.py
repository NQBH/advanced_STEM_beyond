
n = int(input("Nhập số nguyên dương n: "))

if n <= 0:
    print("n phải là số nguyên dương!")
    exit()

mt_0 = []

for i in range(n):
    hang = []
    for j in range(n):
        hang.append(0)
    mt_0.append(hang)

mt_donvi = []

for i in range(n):
    hang = []
    for j in range(n):
        if i == j:
            hang.append(1)
        else:
            hang.append(0)
    mt_donvi.append(hang)

print("Ma trận 0 kích thước {}x{}:".format(n, n))
for hang in mt_0:
    for phan_tu in hang:
        print(phan_tu, end="\t")
    print()

print("\nMa trận đơn vị kích thước {}x{}:".format(n, n))
for hang in mt_donvi:
    for phan_tu in hang:
        print(phan_tu, end="\t")
    print()

