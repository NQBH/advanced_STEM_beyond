def generate_partitions(n, k, prefix=[]):
    result = []
    if k == 0:
        if n == 0:
            result.append(prefix)
        return result

    # Gia tri bat dau: n hoac gia tri nho hon phan tu cuoi trong prefix
    start = n if not prefix else min(prefix[-1], n)

    # Duyet cac gia tri hop le cua so tiep theo
    for i in range(start, 0, -1):
        sub_partitions = generate_partitions(n - i, k - 1, prefix + [i])
        result.extend(sub_partitions)

    return result

def print_ferrers(partition):
    for row in partition:
        print('*' * row)

def print_transpose(partition):
    max_len = max(partition)
    for i in range(max_len):
        for val in partition:
            print('*' if val > i else ' ', end='')
        print()

def main():
    n = int(input("Nhap n: "))
    k = int(input("Nhap k: "))
    print(f"Tat ca cac phan hoach cua {n} thanh {k} phan:\n")

    partitions = generate_partitions(n, k)
    count = 0

    for idx, part in enumerate(partitions, 1):
        print(f"Phan hoach {idx}: {part}")
        print("Bieu do Ferrers F:")
        print_ferrers(part)
        print("Bieu do Ferrers chuyen vi F^T:")
        print_transpose(part)
        print("-" * 30)
        count += 1

    print(f"Tong so phan hoach p_{k}({n}) = {count}")

# Goi ham main
if __name__ == "__main__":
    main()