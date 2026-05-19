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

# BT2
a, b, c = map(float, input("Nhập 3 số thực, cách nhau bởi khoảng trắng: ").split())

# find maximum
if (a >= b and a >= c):
	print("max = ", a)
elif (b >= a and b >= c):
	print("max = ", b)
else:
	print("max = ", c)

# find minimum
if (a <= b and a <= c):
	print("min = ", a)
elif (b <= a and b <= c):
	print("min = ", b)
else:
	print("min = ", c)

# BT3
available_balance = float(input())
withdraw_amount_money = float(input())

if (withdraw_amount_money > available_balance):
	print("Not enough money.")
else:
	print("Được phép rút tiền. Rút thành công ", withdraw_amount_money)
	print("Số dư khả dụng còn lại là ", available_balance - withdraw_amount_money)