# BT1
def sum_difference_product_quotient(a, b):
	## Step 2: Tính tổng a + b
	print(a + b)

	## Step 3: Tính hiệu a - b
	print(a - b)

	## Step 4: Tính tổng a * b
	print(a * b)

	## Step 5: Tính thương a / b
	if (b == 0):
		print("Error: Division by zero. End.")
	else: # b khác 0
		print(a / b)
# main
a, b = map(float, input("Nhập 2 số thực, cách nhau bởi khoảng trắng: ").split())
sum_difference_product_quotient(a, b)