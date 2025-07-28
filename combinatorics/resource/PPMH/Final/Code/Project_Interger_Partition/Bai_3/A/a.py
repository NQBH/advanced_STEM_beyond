def is_self_conjugate(partition):
    for i in range(len(partition)):
        if partition[i] < i + 1:
            return False
    return True

def generate_partitions(n, max_val, current, k, result):
    if n == 0 and len(current) == k and is_self_conjugate(current):
        result.append(current[:])
        return
    for i in range(min(n, max_val), 0, -1):
        current.append(i)
        generate_partitions(n - i, i, current, k, result)
        current.pop()

n = int(input("Nhập n: "))
k = int(input("Nhập k: "))
result = []
generate_partitions(n, n, [], k, result)
for p in result:
    print(p)
print(f"Tổng số phân hoạch tự liên hợp có {k} phần: {len(result)}")
