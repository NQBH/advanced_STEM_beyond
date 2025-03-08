sum = 0
for __ in range(12):
	a = float(input())
	sum += a
print("${:.2f}".format(sum / 12))