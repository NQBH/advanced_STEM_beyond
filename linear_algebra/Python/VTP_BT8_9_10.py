#BT8
def nhap_so_nguyen_duong():
    while True:
        try:
            n = int(input("Nhập n và n phải là số nguyên dương: "))
            if n > 0:
                return n
            else:
                print("Lỗi: Kích thước phải là số nguyên dương (> 0). Vui lòng nhập lại.")
        except ValueError:
            print("Lỗi: Nhập sai.Nhập lai.:")

def in_ma_tran(ma_tran):
    for hang in ma_tran:
        print(" ".join(map(str, hang)))
    print("-" * 20)

def tao_ma_tran_0(n): 
    ma_tran = []
    for i in range(n):
        hang = [0] * n
        ma_tran.append(hang) 
    return ma_tran

def tao_ma_tran_don_vi(n): 
    ma_tran_don_vi = []
    for i in range(n):
        hang = [] 
        
        for j in range(n): 
            if i == j:
                hang.append(1)
            else:
                hang.append(0) 

        ma_tran_don_vi.append(hang)
    return ma_tran_don_vi

print("MA TRẬN 0 VÀ MA TRẬN ĐƠN VỊ")

n = nhap_so_nguyen_duong()

print(f"\n=> Ma trận Không ({n} x {n}):")

zero_matrix = tao_ma_tran_0(n) 
in_ma_tran(zero_matrix)

print(f"\n=> Ma trận Đơn vị ({n} x {n}):")

identity_matrix = tao_ma_tran_don_vi(n) 
in_ma_tran(identity_matrix)

try:
    import numpy as np
    print("\n--- Ví dụ với thư viện NumPy (thư viện chuyên dụng) ---")
    print(f"Ma trận Không NumPy ({n} x {n}):\n{np.zeros((n, n), dtype=int)}")
    print("-" * 30)
    print(f"Ma trận Đơn vị NumPy ({n} x {n}):\n{np.eye(n, dtype=int)}")
    print("-" * 30)
except ImportError:
    pass 

#BT9
def nhap_ma_tran(rows, cols):
    """Hàm nhập các phần tử của ma trận từ người dùng."""
    matrix = []
    print(f"Nhập các phần tử của ma trận {rows}x{cols}:")
    for i in range(rows):
        while True:
            try:
                row_str = input(f"Nhập {cols} phần tử cho hàng {i+1} (cách nhau bởi dấu cách): ")
                row = list(map(int, row_str.split()))
                
                if len(row) == cols:
                    matrix.append(row)
                    break
                else:
                    print(f"Lỗi: Cần nhập đúng {cols} phần tử. Vui lòng nhập lại.")
            except ValueError:
                print("Lỗi: Các phần tử phải là số nguyên. Vui lòng nhập lại.")
    return matrix

def kiem_tra_duong_cheo(matrix, rows, cols):
    """Kiểm tra ma trận đường chéo (a[i][j] = 0 nếu i != j)."""
    if rows != cols:
        return False 
    
    for i in range(rows):
        for j in range(cols):
            if i != j and matrix[i][j] != 0:
                return False
    return True

def kiem_tra_tam_giac_tren(matrix, rows, cols):
    """Kiểm tra ma trận tam giác trên (a[i][j] = 0 nếu i > j)."""
    if rows != cols:
        return False 
        
    for i in range(rows):
        for j in range(cols):
            if i > j and matrix[i][j] != 0:
                return False
    return True

def kiem_tra_tam_giac_duoi(matrix, rows, cols):
    """Kiểm tra ma trận tam giác dưới (a[i][j] = 0 nếu i < j)."""
    if rows != cols:
        return False 
        
    for i in range(rows):
        for j in range(cols):
            if i < j and matrix[i][j] != 0:
                return False
    return True

def kiem_tra_doi_xung(matrix, rows, cols):
    """Kiểm tra ma trận đối xứng (A = A^T, tức a[i][j] = a[j][i])."""
    if rows != cols:
        return False 
    
    for i in range(rows):
        for j in range(i + 1, cols): 
            if matrix[i][j] != matrix[j][i]:
                return False
    return True

print("KIỂM TRA CÁC LOẠI MA TRẬN TRONG PYTHON ")

while True:
    try:
        M = int(input("Nhập số hàng (M): "))
        N = int(input("Nhập số cột (N): "))
        if M > 0 and N > 0:
            break
        else:
            print("Kích thước phải là số nguyên dương.")
    except ValueError:
        print("Đầu vào không hợp lệ.")

A = nhap_ma_tran(M, N)

print("\n--- KẾT QUẢ KIỂM TRA ---")

ket_qua_duong_cheo = kiem_tra_duong_cheo(A, M, N)
print(f"1. Ma trận Đường chéo: {'CÓ' if ket_qua_duong_cheo else 'KHÔNG'}")

ket_qua_tam_giac_tren = kiem_tra_tam_giac_tren(A, M, N)
print(f"2. Ma trận Tam giác trên: {'CÓ' if ket_qua_tam_giac_tren else 'KHÔNG'}")

ket_qua_tam_giac_duoi = kiem_tra_tam_giac_duoi(A, M, N)
print(f"3. Ma trận Tam giác dưới: {'CÓ' if ket_qua_tam_giac_duoi else 'KHÔNG'}")
ket_qua_doi_xung = kiem_tra_doi_xung(A, M, N)
print(f"4. Ma trận Đối xứng (A=A^T): {'CÓ' if ket_qua_doi_xung else 'KHÔNG'}")

#BT10

def tinh_dinh_thuc_2x2():
    """
    Nhập các phần tử của ma trận 2x2 (a b; c d) và tính định thức.
    """
    print("--- CHƯƠNG TRÌNH TÍNH ĐỊNH THỨC MA TRẬN 2x2 ---")
    print("Ma trận có dạng: (a  b)")
    print("                (c  d)")

    matrix = []
    
    for i in range(2):
        while True:
            try:
                row_str = input(f"Nhập 2 phần tử cho hàng {i+1} (cách nhau bởi dấu cách): ")

                row = list(map(float, row_str.split()))
                
                if len(row) == 2:
                    matrix.append(row)
                    break 
                else:
                    print("Lỗi: Cần nhập đúng 2 phần tử. Vui lòng nhập lại.")
            except ValueError:
                print("Lỗi: Các phần tử phải là số (nguyên hoặc thực). Vui lòng nhập lại.")

    # Lấy các phần tử ra từ ma trận 2x2:
    # Hàng 1: [a, b]
    a = matrix[0][0]
    b = matrix[0][1]
    # Hàng 2: [c, d]
    c = matrix[1][0]
    d = matrix[1][1]

    dinh_thuc = (a * d) - (b * c)
    
    print("\n--- KẾT QUẢ ---")
    print(f"Ma trận A đã nhập: ({a} {b}; {c} {d})")
    print(f"Công thức: det(A) = ({a} * {d}) - ({b} * {c})")
    print(f"Định thức của ma trận là: {dinh_thuc}")

tinh_dinh_thuc_2x2()