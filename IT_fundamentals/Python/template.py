# INPUT
'''
a = input() # input string
a = int(input()) # input an integer -- Nhập số nguyên bất kỳ
a = float(input()) # input a real number -- Nhập 1 số thực bấ t kỳ

a, b = map(int, input().split()) # Nhập nhiều số nguyên cùng 1 hàng cách nhau bởi space
a, b, c, d = map(int, input().split()) # Có thể  nhập nhiều số nguyên cùng hàng

a, b = map(float, input().split) # Nhập nhiều số thực cùng 1 hàng cách nhau bởi space
a, b, c, d = map(float, input().split) # Có thể  nhập nhiều số thực cùng hàng
'''

# Exercise 1: Compute sum, difference, product, quotient of 2 real numbers
a = float(input("a = "))
b = float(input("b = "))
print("Sum a + b = ", a + b)
print("Difference a - b = ", a - b)
print("Product ab = ", a * b)
if b == 0:
	print("error: division by 0")
else: # b != 0
	print("Quotient a/b = ", a / b)

# Exercise 2: Compute sum by for loop -- Tính tổng bằng vòng lặp for
n = int(input("Nhập số nguyên dương n: "))
# (a) Tổng các số nguyên dương đầu tiên 1 + 2 + ... + n
sum = 0
for i in range(1, n + 1): # range(a,b) trả về a, a + 1, ..., b - 1
	sum = sum + i # Equivalent: sum += i
print(sum)

# Exercise 7: Compute money
n = int(input()) # number of months
sum_tien_loi = 0
sum_tien_lo = 0

for i in range(1, n + 1):
	money = float(input())
	if money > 0: # lời
		sum_tien_loi += money
	if money < 0: # lỗ
		sum_tien_lo += money
print("Tong so tien loi: ", sum_tien_loi)
print("Tong so tien lo: ", sum_tien_lo)

# Exercise 8: Tính tiền lãi
def M(m0, r, n): # m0: tiền vốn, r: lãi suất rate of interest, n: số năm gửi
	return m0 * (1 + r / 100) ** n # **: exponent -- mũ/lũy thừa

m0, r, n = map(float, input().split()) # nhập vào 3 số thực
n = int(n) # ép kiểu n thành số nguyên
print(M(125000000, 4.9, 3))
print(M(m0, r, n))

# OUTPUT
print(a) # Print out variable a -- Xuất 1 biến a
print("Output/Result of this problem is") # Print a string -- Xuất 1 chuỗi ký tự
print("Result", a, "End of problem") # In chuỗi & biến, cách nhau bởi dấu ,