import numpy as np
n = int(input("Nhập số nguyên dương n: "))
if n < 0:
    print("Số không hợp lệ vui lòng nhập n > 0!!")
else:
    mat0= np.zeros((n,n),dtype =int)
    I = np.eye(n,dtype = int)
    print(f"\n Ma trân 0 {n}x{n}\n")
    print(mat0)

    print(f"Ma trận đơn vị {n}x{n}\n")
    print(I)