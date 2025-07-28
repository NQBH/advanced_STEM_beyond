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

def print_ferrers(partition):
    for x in partition:
        print('* ' * x)

def print_ferrers_transpose(partition):
    max_row = max(partition)
    for i in range(max_row):
        for x in partition:
            if x > i:
                print('* ', end='')
            else:
                print('  ', end='')
        print()

def main():
    n = int(input('Nhap n: '))
    k = int(input('Nhap k: '))
    partitions = generate_partitions(n, k)
    print(f'So phan hoach: {len(partitions)}')
    for idx, part in enumerate(partitions, 1):
        print(f'Phan hoach {idx}:', ' '.join(map(str, part)))
        print('Ferrers diagram:')
        print_ferrers(part)
        print('Ferrers transpose diagram:')
        print_ferrers_transpose(part)
        print('--------------------------')

if __name__ == '__main__':
    main()
