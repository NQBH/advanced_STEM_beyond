#BichHien
e = float(input("Nhập số e: "))

n = 2
d = 1 / (n + 1)  # d = |a_n - 1| = 1 / (n + 1)

while d >= e:
    n += 1
    d = 1 / (n + 1)

print("Giá trị nhỏ nhất của n sao cho |a_n - 1| < e là:", n)