def greeting(): # hàm in ra lời chào với lớp học ITF2
	print("Welcome to Information Technology of Fundamentals 2 again.")

greeting() # in lời chào 1 lần

for i in range(64):
	print("Student", i, ": ")
	greeting() # cách gọi hàm nhiều lần bằng vòng lặp for

def even_odd(n): # hàm xét tính chẵn lẻ: 1: chẵn, 0: lẻ
	if (n % 2 == 0):
		return 1
	else:
		return 0

for i in range(64):
	print(i, "is even if 1, odd if 0", even_odd(i))

def ATM(withdraw_amount_money, balanced_account = 1000000000):
	if (withdraw_amount_money > balanced_account):
		return balanced_account
	else:
		return balanced_account - withdraw_amount_money

withdraw_amount_money = float(input("Nhập số tiền cần rút vào: "))
balanced_account = float(input("Nhập số dư khả dụng vào: "))
print("sau khi nhập số tiền cần rút:", withdraw_amount_money, " thì số dư khả dụng = ")
print(ATM(withdraw_amount_money, balanced_account))