def power(a, b):
    result = 1.0
    while b:
        if b % 2 == 1:
            result *= a
        a *= a
        b //= 2
    return result

def evaluate_polynomial(coeffs, x):
    return sum(coeff * power(x, i) for i, coeff in enumerate(coeffs))

def bai_158():
    x0 = float(input("Nhập x0: "))
    m = int(input("Nhap bac m cua tu so: "))
    n = int(input("Nhap bac n cua mau so: "))

    a = list(map(float, input(f"Nhap {m+1} he số tu a0 -> a{m}: ").split()))
    b = list(map(float, input(f"Nhap {n+1} he so mau b0 -> b{n}: ").split()))

    Px = evaluate_polynomial(a, x0)
    Qx = evaluate_polynomial(b, x0)

    print(f"P({x0}) = {Px:.10f}, Q({x0}) = {Qx:.10f}")
    
    eps = 1e-9
    if abs(Qx) < eps and abs(Px) < eps:
        print(f"Gioi han co dang vo đinh 0/0 tại x = {x0}")
    elif abs(Qx) < eps:
        print("Khong the tinh gioi han vi Q(x0) = 0 (chia cho 0)")
    else:
        print(f"Gia tri lim(x→{x0}) P(x)/Q(x) = {Px/Qx:.10f}")