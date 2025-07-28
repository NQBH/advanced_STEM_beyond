from sympy.functions.combinatorial.numbers import partition

def count_odd_partitions(n):
    count = 0
    def gen(n, max_val, curr):
        nonlocal count
        if n == 0:
            if len(curr) % 2 == 1:
                count += 1
            return
        for i in range(min(n, max_val), 0, -1):
            curr.append(i)
            gen(n - i, i, curr)
            curr.pop()
    gen(n, n, [])
    return count

n = int(input("Nhập n: "))
result = []
q_n = count_odd_partitions(n)
print(f"Số phân hoạch có số phần tử lẻ của {n}: {q_n}")
print(f"Số phân hoạch tự liên hợp p_k^selfcjg(n): {len(result)}")