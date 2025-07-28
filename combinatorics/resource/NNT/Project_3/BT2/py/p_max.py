def generate_partitions(n, k, max_val=None, current=None, result=None):
    if current is None:
        current = []
    if result is None:
        result = []
    if max_val is None:
        max_val = n
    if k == 0:
        if n == 0:
            result.append(list(current))
        return result
    for i in range(min(n, max_val), 0, -1):
        current.append(i)
        generate_partitions(n - i, k - 1, i, current, result)
        current.pop()
    return result

def generate_pmax(n, k, current=None, result=None):
    if current is None:
        current = []
    if result is None:
        result = []
    if n == 0 and current:
        # Kiểm tra xem k có xuất hiện trong phân hoạch không
        if k in current:
            result.append(list(current))
        return result
    if n <= 0:
        return result
    # Đảm bảo thứ tự không tăng: phần tử tiếp theo không lớn hơn phần trước
    max_val = k if not current else min(current[-1], k)
    for i in range(max_val, 0, -1):
        current.append(i)
        generate_pmax(n - i, k, current, result)
        current.pop()
    return result

def print_partition(part):
    print(' '.join(map(str, part)))

def main():
    n = int(input('Nhap n: '))
    k = int(input('Nhap k: '))
    pk_partitions = generate_partitions(n, k)
    pmax_partitions = generate_pmax(n, k)
    print(f"\nSo phan hoach n thanh k phan (p_k(n)): {len(pk_partitions)}")
    print("Cac phan hoach p_k(n):")
    for part in pk_partitions:
        print_partition(part)
    print(f"\nSo phan hoach n co phan tu lon nhat la k (p_max(n, k)): {len(pmax_partitions)}")
    print("Cac phan hoach p_max(n, k):")
    for part in pmax_partitions:
        print_partition(part)
    print(f"\nSo sanh: p_k(n) = {len(pk_partitions)}, p_max(n, k) = {len(pmax_partitions)}")

if __name__ == '__main__':
    main()
