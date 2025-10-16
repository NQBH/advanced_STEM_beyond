def nhapmatran():
    m = int(input("Nhập số hàng ma trận A: "))
    n = int(input("Nhập số cột ma trận A: "))
    print("Nhập ma trận A:")
    A = []
    for i in range(m):
        cot = list(map(float, input(f"Hàng {i+1}: ").split()))
        if len(cot) != n:
            print("Số phần tử không khớp với cột")
            exit()
        A.append(cot)
    return A
def inmatran(A):
    for cot in A:
        print(cot)
def hoandoi2dong(A,i,j):
    A[i], A[j] = A[j], A[i]
def nhanvoi1so(A,i,k):
    A[i] = [k*x for x in A[i]]
def cong1hangdanhan1so(A,i,j,k):
    A[i] = [a+b*k for a,b in zip(A[i], A[j])]
A = nhapmatran()
while True:
    print("---MENU---")
    print("1. Hoán đổi 2 dòng (Hi <-> Hj)")
    print("2. Nhân với 1 số (Hi*k)")
    print("3. Cộng vào 1 hàng đã nhân với 1 số (Hi -> Hi + k*Hj)")
    print("0. Thoát")
    choose = input("Chọn: ")
    if choose == '0':
        print("Kết thúc chương trình")
        break
    elif choose == '1':
        i = int(input("Nhập chỉ số dòng I: ")) -1
        j = int(input("Nhập chỉ số dòng II: ")) -1
        hoandoi2dong(A,i,j)
    elif choose == '2':
        i = int(input("Nhập chỉ số dòng cần nhân: ")) -1
        k = float(input("Nhập số != 0: "))
        nhanvoi1so(A,i,k)
    elif choose == '3':
        i = int(input("Nhập chỉ số dòng cần cộng: ")) -1
        j = int(input("Nhập chỉ số dòng cần nhân: ")) -1
        k = float(input("Nhập số k: "))
        cong1hangdanhan1so(A,i,j,k)
    else:
        print("Lựa chọn không hợp lệ! Thử lại.")
        continue
    print("\n Ma trận sau biến đổi: ")
    inmatran(A)