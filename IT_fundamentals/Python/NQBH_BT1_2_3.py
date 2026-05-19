# BT1
a, b = map(float, input("Nhập 2 số thực, cách nhau bởi khoảng trắng: ").split())

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

# BT2: 
a, b, c = map(float, input("Nhập 3 số thực, cách nhau bởi khoảng trắng: ").split())

if (a >= b and a >= c):
	print("maximum = ", a)
elif (b >= a and b >= c):
	print("maximum = ", b)
else:
	print("maximum = ", c)

if (a <= b and a <= c):
	print("maximum = ", a)
elif (b <= a and b <= c):
	print("maximum = ", b)
else:
	print("maximum = ", c)

# BT3
available_balance = float(input("Nhập số dư khả dụng = ")) # nhập số dư khả dụng là 1 số thực
withdraw_amount_money = float(input("Nhập số tiền muốn rút = ")) # nhập số tiền muốn rút
if (withdraw_amount_money > available_balance):
	print("Số dư khả dụng không đủ. Không cho phép rút")
else:
	print("Cho phép rút tiền.")
	print("Rút thành công: ", withdraw_amount_money)
	print("Số dư tài khoản khả dụng hiện tại (sau khi rút): ", available_balance - withdraw_amount_money)
