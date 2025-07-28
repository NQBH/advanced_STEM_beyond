def print_ferrers(partition):
    print("Ferrers diagram:")
    for row in partition:
        print("*" * row)

def print_ferrers_transpose(partition):
    print("Transpose Ferrers diagram:")
    max_row = max(partition)
    for i in range(max_row):
        line = ""
        for part in partition:
            line += "*" if i < part else " "
        print(line.rstrip())

partition = [4, 3, 1]
print_ferrers(partition)
print()
print_ferrers_transpose(partition)