print("Nhập các phần tử của ma trận 2x2 (a b c d):")
a, b, c, d = map(float, input().split())

det = a * d - b * c

print("Ma trận A:")
print(f"{a}\t{b}")
print(f"{c}\t{d}")

print(f"\nĐịnh thức (det A) = {det}")
