a = float(input("a = "))
b = float(input("b = "))
print("Sum a + b = ", a + b)
print("Difference a - b = ", a - b)
print("Product ab = ", a * b)
print("Quotient a/b = ", a / b)

n = int(input("Nhập số nguyên dương n: "))
# (a) Tổng các số nguyên dương đầu tiên
tong_a = sum(range(1, n + 1))
ct_a = n * (n + 1) // 2
print(f"(a) Tổng 1 + 2 + ... + {n} = {tong_a}, công thức = {ct_a}")
# (b) Tổng n số lẻ đầu tiên
tong_b = sum(2 * i - 1 for i in range(1, n + 1))
print(f"(b) Tổng {n} số lẻ đầu tiên = {tong_b}, công thức = {n ** 2}")

# (c) Tổng n số chẵn đầu tiên
tong_c = sum(2 * i for i in range(1, n + 1))
ct_c = n * (n + 1)
print(f"(c) Tổng {n} số chẵn đầu tiên = {tong_c}, công thức = {ct_c}")

# (d) Tổng bình phương của n số nguyên dương đầu tiên
tong_d = sum(i ** 2 for i in range(1, n + 1))
ct_d = n * (n + 1) * (2 * n + 1) // 6
print(f"(d) Tổng i^2 từ 1 đến {n} = {tong_d}, công thức = {ct_d}")

# (e) Tổng bình phương n số lẻ đầu tiên
tong_e = sum((2 * i - 1) ** 2 for i in range(1, n + 1))
print(f"(e) Tổng bình phương {n} số lẻ đầu tiên = {tong_e}")

# (f) Tổng bình phương n số chẵn đầu tiên
tong_f = sum((2 * i) ** 2 for i in range(1, n + 1))
ct_f = (2 * n * (n + 1) * (2 * n + 1)) // 3
print(f"(f) Tổng bình phương {n} số chẵn đầu tiên = {tong_f}, công thức = {ct_f}")

# (g) Tổng lập phương của n số nguyên dương đầu tiên
tong_g = sum(i ** 3 for i in range(1, n + 1))
ct_g = (n * (n + 1) // 2) ** 2
print(f"(g) Tổng i^3 từ 1 đến {n} = {tong_g}, công thức = {ct_g}")

# (h) Tổng lập phương của n số lẻ đầu tiên
tong_h = sum((2 * i - 1) ** 3 for i in range(1, n + 1))
print(f"(h) Tổng lập phương {n} số lẻ đầu tiên = {tong_h}")

# (i) Tổng lập phương của n số chẵn đầu tiên
tong_i = sum((2 * i) ** 3 for i in range(1, n + 1))
ct_i = 2 * n ** 2 * (n + 1) ** 2
print(f"(i) Tổng lập phương {n} số chẵn đầu tiên = {tong_i}, công thức = {ct_i}")


n = int(input("n = "))
sum_a = 0
for i in range(1, n + 1):
    sum_a += i
print(f"(a) Tổng {n} số đầu tiên = {sum_a} (Công thức: {n*(n+1)//2})")
sum_b = 0
for i in range(1, 2*n, 2):
    sum_b += i
print(f"(b) Tổng {n} số lẻ đầu tiên = {sum_b} (Công thức: {n**2})")
sum_c = 0
for i in range(2, 2*n+1, 2):
    sum_c += i
print(f"(c) Tổng {n} số chẵn đầu tiên = {sum_c} (Công thức: {n*(n+1)})")
sum_d = 0
for i in range(1, n + 1):
    sum_d += i**2
print(f"(d) Tổng bình phương = {sum_d} (Công thức: {n*(n+1)*(2*n+1)//6})")
sum_e = 0
for i in range(1, 2*n, 2):
    sum_e += i**2
print(f"(e) Tổng bình phương số lẻ = {sum_e}")
sum_f = 0
for i in range(2, 2*n+1, 2):
    sum_f += i**2
print(f"(f) Tổng bình phương số chẵn = {sum_f}")
sum_g = 0
for i in range(1, n + 1):
    sum_g += i**3
print(f"(g) Tổng lập phương = {sum_g} (Công thức: {(n*(n+1)//2)**2})")
sum_h = 0
for i in range(1, 2*n, 2):
    sum_h += i**3
print(f"(h) Tổng lập phương số lẻ = {sum_h}")
sum_i = 0
for i in range(2, 2*n+1, 2):
    sum_i += i**3
print(f"(i) Tổng lập phương số chẵn = {sum_i}")

# Nhập số n
n = int(input("Nhập n (n ∈ N*): "))
# (a) Tổng của n số nguyên dương đầu tiên
tong_a = sum(range(1, n + 1))
cong_thuc_a = n * (n + 1) // 2
print(f"(a) Tổng 1 + 2 + ... + {n} = {tong_a} so với {cong_thuc_a}")

# (b) Tổng của n số nguyên dương lẻ đầu tiên
tong_b = sum(2 * i - 1 for i in range(1, n + 1))
cong_thuc_b = n ** 2
print(f"(b) Tổng {n} số lẻ đầu tiên = {tong_b} so với {cong_thuc_b}")

# (c) Tổng của n số nguyên dương chẵn đầu tiên
tong_c = sum(2 * i for i in range(1, n + 1))
cong_thuc_c = n * (n + 1)
print(f"(c) Tổng {n} số chẵn đầu tiên = {tong_c} so với {cong_thuc_c}")

# (d) Tổng bình phương của n số nguyên dương đầu tiên
tong_d = sum(i ** 2 for i in range(1, n + 1))
cong_thuc_d = n * (n + 1) * (2 * n + 1) // 6
print(f"(d) Tổng bình phương 1^2 + 2^2 + ... + {n}^2 = {tong_d} so với {cong_thuc_d}")

# (e) Tổng bình phương của n số lẻ đầu tiên
tong_e = sum((2 * i - 1) ** 2 for i in range(1, n + 1))
# Không có công thức đơn giản được đưa ra, chỉ tính tổng
print(f"(e) Tổng bình phương {n} số lẻ đầu tiên = {tong_e}")

# (f) Tổng bình phương của n số chẵn đầu tiên
tong_f = sum((2 * i) ** 2 for i in range(1, n + 1))
cong_thuc_f = 2 * n * (n + 1) * (2 * n + 1) // 3
print(f"(f) Tổng bình phương {n} số chẵn đầu tiên = {tong_f} so với {cong_thuc_f}")

# (g) Tổng lập phương của n số nguyên dương đầu tiên
tong_g = sum(i ** 3 for i in range(1, n + 1))
cong_thuc_g = (n * (n + 1) // 2) ** 2
print(f"(g) Tổng lập phương 1^3 + 2^3 + ... + {n}^3 = {tong_g} so với {cong_thuc_g}")

# (h) Tổng lập phương của n số nguyên dương lẻ đầu tiên
tong_h = sum((2 * i - 1) ** 3 for i in range(1, n + 1))
# Không có công thức được cung cấp, chỉ in tổng
print(f"(h) Tổng lập phương {n} số lẻ đầu tiên = {tong_h}")

# (i) Tổng lập phương của n số nguyên dương chẵn đầu tiên
tong_i = sum((2 * i) ** 3 for i in range(1, n + 1))
cong_thuc_i = 2 * n * (n + 1) * (n + 1) * n  # 2n^2(n+1)^2
print(f"(i) Tổng lập phương {n} số chẵn đầu tiên = {tong_i} so với {2 * n**2 * (n + 1)**2}")

n = int(input("n = "))
sum = 0
for i in range(n+1):
  sum = sum + i
print(sum)
tmp = n*(n + 1) // 2
if sum == tmp:
  print(" sum = n(n + 1)/2")
else:
  print(" sum != n(n + 1)/2")
sum = 0
for i in range(1, n + 1):
    sum = sum + (2 * i - 1)
print("(b) Tổng =", sum)
tmp = n**2
if sum == tmp:
  print(" sum = n**2")
else:
  print(" sum != n**2")
sum = 0
for i in range(1, n + 1):
    sum = sum + (2 * i)
print("(c) Tổng =", sum)
tmp = n*(n + 1)
if sum == tmp:
  print(" sum = n(n + 1)")
else:
  print(" sum != n(n + 1)")
sum = 0
for i in range(1, n + 1):
    sum = sum + i * i
print("(d) Tổng =", sum)
tmp = n*(n + 1) * (2 * n + 1) // 6
if sum == tmp:
  print(" sum = n*(n + 1) * (2 * n + 1) // 6")
else:
  print(" sum != n*(n + 1) * (2 * n + 1) // 6")
sum = 0
for i in range(1, n + 1):
    sum = sum + (2 * i - 1)**2
print("(e) Tổng =", sum)
tmp = n*(2 * n - 1) * (2 * n + 1) // 3
if sum == tmp:
  print(" sum = n*(2 * n - 1) * (2 * n + 1) // 3")
else:
  print(" sum != n*(2 * n - 1) * (2 * n + 1) // 3")
sum = 0
for i in range(1, n + 1):
    sum = sum + (2 * i)**2
print("(f) Tổng =", sum)
tmp = 2 * n *(n + 1) * (2 * n + 1) //3
if sum == tmp:
  print(" sum = 2 * n *(n + 1) * (2 * n + 1) //3")
else:
  print(" sum != 2 * n *(n + 1) * (2 * n + 1) //3")
sum = 0
for i in range(1, n + 1):
    sum = sum + i**3
print("(g) Tổng =", sum)
tmp = (n * (n + 1) // 2) ** 2
if sum == tmp:
    print("sum = (n(n + 1)/2)^2")
else:
    print("sum != (n(n + 1)/2)^2")
sum = 0
for i in range(1, n + 1):
    sum = sum + (2 * i)**3
print("(h) Tổng =", sum)
tmp = 2 * n**2 * (n + 1)**2
if sum == tmp:
    print("sum = 2n^2(n + 1)^2")
else:
    print("sum != 2n^2(n + 1)^2")


a = float(input("Nhập cạnh a: "))
b = float(input("Nhập cạnh b: "))
c = float(input("Nhập cạnh c: "))
if a + b > c and b + c > a and c + a > b:
    print("Là tam giác")
    if a == b == c:
        print("Tam giác đều")
    elif a == b or b == c or c == a:
        print("Tam giác cân")
    elif a*a + b*b == c*c or b*b + c*c == a*a or c*c + a*a == b*b:
        print("Tam giác vuông")
    else:
        print("Tam giác thường")
else:
    print("Không phải tam giác")

a = float(input("Nhập cạnh a: "))
b = float(input("Nhập cạnh b: "))
c = float(input("Nhập cạnh c: "))
if a + b > c and b + c > a and c + a > b:

#Chu vi
    cv = a + b + c
    print("Chu vi =", cv)
#Nửa chu vi
    p = cv / 2
# Diện tích
    S = (p * (p - a) * (p - b) * (p - c)) ** 0.5
    print("Diện tích =", S)
# Tính đường cao
    print("\nBa đường cao:")
    print("Đường cao hạ từ A =", (2 * S) / a)
    print("Đường cao hạ từ B =", (2 * S) / b)
    print("Đường cao hạ từ C =", (2 * S) / c)
else:
    print("Đây không phải tam giác!")

print("Triangle")
a=int(input("a:"))
b=int(input("b:"))
c=int(input("c:"))
if a+b>c and b+c>a and a+c>b :
  if a==c==b:
    print("tam giac deu")
  elif a==c or a==b or b==c:
    print("tam giac can")
  elif a*a+b*b==c*c or a*a+c*c==b*b or b*b+c*c==a*a:
    print("tam giac vuong")
  elif a*a>b*b+c*c or b*b>a*a+c*c or c*c >a*a+b*b:
    print("tam giac tu")
  else:
    print("tam giac nhon")
 
else:
  print("khong phai la tam giac")