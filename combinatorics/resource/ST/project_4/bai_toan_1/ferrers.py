# Ham in bieu do Ferrers
def print_ferrers(partition):
    for row in partition:
        print("*" * row)

# Ham in bieu do chuyen vi Ferrers
def print_transpose(partition):
    max_len = partition[0]  # chieu cao lon nhat cua cot
    for i in range(max_len):
        for val in partition:
            if val > i:
                print("*", end="")  # in dau * neu cot do con o hang i
            else:
                print(" ", end="")  # in khoang trang neu da het cot
        print()

# Ham de quy sinh cac phan hoach
def generate_partitions(n, k, current=[], max_val=None):
    if max_val is None:
        max_val = n  # gia tri lon nhat cho mot phan tu

    if k == 0:
        if n == 0:
            print("Phan hoach:", current)
            print("Ferrers:")
            print_ferrers(current)
            print("Transpose:")
            print_transpose(current)
            print("----------")
        return

    for i in range(min(n, max_val), 0, -1):
        generate_partitions(n - i, k - 1, current + [i], i)

# Chuong trinh chinh
if __name__ == "__main__":
    n = int(input("Nhap n: "))  # tong can phan hoach
    k = int(input("Nhap k: "))  # so thanh phan
    generate_partitions(n, k)