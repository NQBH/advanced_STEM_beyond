# BÀI GIẢI MẪU ĐÈ THI GIỮA KỲ MÔN ITF2 (MINH HỌA)

# Bài 1: Tính giá trị biểu thức A(x,y,z) = x^3y^2*sqrt(z)/(sqrt(x)y*sqrt[3](y))
## 1.a.
x, y, z = map(float, input().split())
if x == 0 or y == 0:
	print("Error: Division by zero.") # print("Lỗi: Chia cho 0.")
else: # xy != 0
	if (x < 0 or z < 0): # sqrt(x) or sqrt(z) is indetermined
		print("Error: Square root of negative real number.") # print("Lỗi: Căn bậc 2 của số thực âm.")
	else: # all terms are well-defined
		# print(x**3 * y**2 * z**.5 / (x**.5 * y**(1/3)))
		print(x**(3 - .5) * y**(2 - 1/3) * z**.5)

## 1.b.
def evaluate_function(x, y, z): # or: tinh_gia_tri_bieu_thuc(x, y, z)
	if x == 0 or y == 0:
		return "Error: Division by zero." # print("Lỗi: Chia cho 0.")
	else: # xy != 0
		if (x < 0 or z < 0): # sqrt(x) or sqrt(z) is indetermined
			return "Error: Square root of negative real number." # print("Lỗi: Căn bậc 2 của số thực âm.")
		else: # all terms are well-defined
			return x**(3 - .5) * y**(2 - 1/3) * z**.5

x, y, z = map(float, input().split())
print(f"A({x}, {y}, {z}) = {evaluate_function(x, y, z)}")

# Bài 2: Dùng vòng lặp for Tính tổng sum_{i=1}^n i^2/i! với n nhập từ bàn phím
n = int(input())
if n <= 0:
	print("Error: n must be a positive integer.") # print("Lỗi: n phải là 1 số nguyên dương.")
else:
	S = 1
	factorial = 1
	for i in range(2, n + 1):
		factorial *= i
		S += i**2 / factorial
	print("S =", S)

# Bài 3: Dùng vòng lặp while để xác định số nguyên dương n_0 lớn nhất sao cho sum_{i=1}^n i^2/i! < M với M là 1 số thực được nhập vào
M = float(input())
i = S = factorial = 1
while S < M:
	i += 1
	factorial *= i
	S +=  i**2 / factorial
print("n_0 =", i - 1)

# Bài 4: Cho n điểm có tọa độ nguyên (x_i,y_i) trên mặt phẳng, xác định diện tích hình chữ nhật chứa chúng mà các điểm có thể nằm trên cạnh của hình chữ nhật đó
n = int(input()) # number of 2D points -- số điểm trên mặt phẳng
x_min = y_min = 1e9
x_max = y_max = -1e9
for i in range(n):
	x, y = map(int, input().split())
	if x < x_min:
		x_min = x
	if x > x_max:
		x_max = x
	if y < y_min:
		y_min = y
	if y > y_max:
		y_max = y
print("Minimum area of rectangle covered n given points =", (x_max - x_min) * (y_max - y_min))