def nhap_epsilon():
    e = -1
    while e <= 0:
        try:
            e = float(input("Nhập epsilon (e > 0): "))
            if e <= 0:
                print("Giá trị epsilon phải lớn hơn 0.")
        except ValueError:
            print("Vui lòng nhập một số thực hợp lệ.")
    return e

def tinh_N_epsilon(e):
    n = 1
    while 1 / (2 ** n) >= e:
        n += 1
    return n

# Chương trình chính
epsilon = nhap_epsilon()
n = tinh_N_epsilon(epsilon)
print(f"Giá trị nhỏ nhất của N sao cho 1/(2^N) < epsilon là: {n}")