# BT1: Nhập và xuất ma trận
def nhap_ma_tran(m, n):
	print(f"Nhập ma trận {m}x{n}:")
	A = []
	for i in range(m):
		row = list(map(float, input(f"Nhập hàng {i+1} (cách nhau bởi dấu cách): ").split()))
		while len(row) != n:
			print(f"Bạn phải nhập đúng {n} phần tử!")
			row = list(map(float, input(f"Nhập lại hàng {i+1}: ").split()))
		A.append(row)
	return A

def xuat_ma_tran(A):
	print("Ma trận:")
	for row in A:
		print(' '.join(f"{x:g}" for x in row))

# BT2: Cộng, trừ hai ma trận
def cong_ma_tran(A, B):
	m, n = len(A), len(A[0])
	return [[A[i][j] + B[i][j] for j in range(n)] for i in range(m)]

def tru_ma_tran(A, B):
	m, n = len(A), len(A[0])
	return [[A[i][j] - B[i][j] for j in range(n)] for i in range(m)]

# BT3: Nhân vô hướng ma trận với số thực
def nhan_vo_huong(A, c):
	m, n = len(A), len(A[0])
	return [[A[i][j] * c for j in range(n)] for i in range(m)]

# BT4: Nhân hai ma trận
def nhan_ma_tran(A, B):
	m, n = len(A), len(A[0])
	n2, p = len(B), len(B[0])
	if n != n2:
		raise ValueError("Số cột của A phải bằng số hàng của B")
	C = []
	for i in range(m):
		row = []
		for j in range(p):
			s = 0
			for k in range(n):
				s += A[i][k] * B[k][j]
			row.append(s)
		C.append(row)
	return C

# BT5: Ma trận chuyển vị
def chuyen_vi(A):
	m, n = len(A), len(A[0])
	return [[A[i][j] for i in range(m)] for j in range(n)]