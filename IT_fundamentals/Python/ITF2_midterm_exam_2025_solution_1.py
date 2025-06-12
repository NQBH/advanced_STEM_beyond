# Problem 1
from math import sqrt

a, b = map(float, input().split())
if a <= 0 or b <= 0:
	print('a & b must be positive.')
else:
	print('P =', 2 * (a + b))
	print('S =', a * b)
	print('d =', sqrt(a * a + b * b))

# Problem 2
a, b, c = map(float, input().split())
if a < 2:
	print('Error: square root of negative real number.')
elif a == 2 or b == 0 or c == -1 or c == 1:
		print('Error: division by 0.')
else:
	print(f'A({a}, {b}, {c}) =', (a ** 4 * b ** (3 - 1/3) * c ** (1/3)) / (sqrt(a - 2) * (c ** 2 - 1)))

# Problem 3
n = int(input())
if n <= 0:
	print("Error: n must be a positive integer.") # print("Lỗi: n phải là 1 số nguyên dương.")
else:
	S = 1
	factorial = 1
	for i in range(2, n + 1):
		# factorial *= i
		S += i * math.factorial(i)
	print("S =", S)
if S == factorial * (n + 1) - 1:
	print(f'S!{n} = f({n}) =', S)
elif S > factorial * (n + 1) - 1:
	print(f'S!{n} > f({n}) =', S)
else:
	print(f'S!{n} < f({n}) =', S)

# Problem 4
a = float(input())
i = S = factorial = 1
while S < a:
	i += 1
	factorial *= i
	S += i * factorial
print(i)

# Problem 5
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
a, b = x_max - x_min + 2, y_max - y_min + 2
print('P =', 2 * (a + b))
print('S =', a * b)
print('d =', sqrt(a * a + b * b))

# Problem 6
n = int(input()) # number of 3D points
x_min = y_min = z_min = 1e9
x_max = y_max = z_max = -1e9
for i in range(n):
	x, y, z = map(int, input().split())
	if x < x_min:
		x_min = x
	if x > x_max:
		x_max = x
	if y < y_min:
		y_min = y
	if y > y_max:
		y_max = y
	if z < z_min:
		z_min = z
	if z > z_max:
		z_max = z
a, b, c = x_max - x_min, y_max - y_min, z_max - z_min
print('S_tp =', 2 * (a * b + b * c + c * a))
print('V =', a * b * c)
print('d =', sqrt(a * a + b * b + c * c))