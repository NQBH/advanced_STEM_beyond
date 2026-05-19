for i in range(5): # in các số tự nhiên từ 0 đến 4
	print(i)

n = int(input()) # nhập số nguyên n
for i in range(n): # in ra các số tự nhiên từ 0 đến n - 1
	print(i)
	if (i % 2 == 0): # i chia hết cho 2: i là số chẵn
		print(i, " là 1 số chẵn.")
	else: # i không chia hết cho 2: i là số lẻ
		print(i, " là 1 số lẻ.")