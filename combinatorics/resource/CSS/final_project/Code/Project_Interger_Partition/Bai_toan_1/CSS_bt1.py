def generate_partitions(n, k, max_val, current, partitions):
    if k == 0:
        if n == 0:
            partitions.append(current[:])
        return
    if n < k:
        return
    for i in range(1, min(n - k + 1, max_val) + 1):
        current.append(i)
        generate_partitions(n - i, k - 1, i, current, partitions)
        current.pop()

def print_ferrers(partition):
    print("Ferrers diagram:")
    for val in partition:
        print("*" * val)

def print_ferrers_transpose(partition):
    print("Ferrers transpose diagram:")
    max_val = max(partition)
    transpose = [sum(1 for x in partition if x >= i) for i in range(1, max_val + 1)]
    for val in transpose:
        print("*" * val)

def main():
    n = int(input("Nhap n: "))
    k = int(input("Nhap k: "))
    partitions = []
    generate_partitions(n, k, n, [], partitions)
    for i, partition in enumerate(partitions):
        print(f"\nPartition {i + 1}: {partition}")
        print_ferrers(partition)
        print_ferrers_transpose(partition)

if __name__ == "__main__":
    main()