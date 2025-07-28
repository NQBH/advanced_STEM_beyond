def print_ferrers(partition):
    for row in partition:
        print('*' * row)

def print_ferrers_transpose(partition):
    max_len = max(partition)
    for i in range(max_len):
        for row in partition:
            print('*' if row > i else ' ', end='')
        print()

def generate(n, k, current=[], max_value=None):
    if max_value is None:
        max_value = n
    if k == 0:
        if n == 0:
            print(f"Phân hoạch: {tuple(current)}")
            print("Ferrers:")
            print_ferrers(current)
            print("Ferrers chuyển vị:")
            print_ferrers_transpose(current)
            print("-" * 20)
        return
    for i in range(min(n, max_value), 0, -1):
        generate(n - i, k - 1, current + [i], i)

if __name__ == "__main__":
    n = int(input("Nhập n: "))
    k = int(input("Nhập k: "))
    generate(n, k)
