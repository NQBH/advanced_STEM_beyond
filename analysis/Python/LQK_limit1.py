epsilon = float(input("Nhap epsilon cho cau b: "))

n = 1
while 1 / (n + 1) >= epsilon:
    n += 1

print(f"(b) Giá trị N_opt là: {n}")