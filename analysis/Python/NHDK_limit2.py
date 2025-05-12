import math

def main():
    try:
        M = float(input("Nhập giá trị M > 0: "))
    except ValueError:
        print("Lỗi: Đầu vào không hợp lệ. Vui lòng nhập một số.")
        return

    if M <= 0:
        print("M phải lớn hơn 0.")
        return

    # Thay vì >= M, ta muốn sqrt(N + 2) > M
    m_squared_minus_2 = M * M - 2.0
    N_candidate = math.floor(m_squared_minus_2) + 1
    N = max(0, N_candidate)

    print(f"Giá trị N (số nguyên không âm nhỏ nhất sao cho sqrt(N+2) > M) cho M = {M} là: {N}")

if __name__ == "__main__":
    main()