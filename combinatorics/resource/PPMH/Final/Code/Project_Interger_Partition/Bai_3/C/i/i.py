def count_self_conjugate_recursive(n, k, max_val):
    if n == 0 and k == 0:
        return 1
    if n < 0 or k <= 0 or max_val <= 0:
        return 0
    res = 0
    for i in range(min(max_val, n), 0, -2):  
        res += count_self_conjugate_recursive(n - i, k - 1, i)
    return res

n = int(input("Nhập n: "))
k = int(input("Nhập k: "))
print("Đệ quy:", count_self_conjugate_recursive(n, k, n))