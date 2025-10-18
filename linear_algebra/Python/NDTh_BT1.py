def nhap_ma_tran():
    m = int(input("Nhập số hàng của ma trận: "))
    n = int(input("Nhập số cột của ma trận: ")) 
    A = []
    print("Nhập các phần tử của ma trận:")
    for i in range(m):
        row = list(map(float, input(f"Hàng {i + 1}: ").split()))
        while len(row) != n:
            print(f"Vui lòng nhập đúng {n} phần tử.")
            row = list(map(float, input(f"Hàng {i + 1}: ").split()))
        A.append(row)   
    return A
def xuat_ma_tran(A):
    print("ma tran vua nhap la:")
    for row in A:
        print(" ".join(map(str,row)))   
A = nhap_ma_tran()
xuat_ma_tran(A)