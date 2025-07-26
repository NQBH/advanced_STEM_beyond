def gen_ordered_partitions(cur, k, n_remain, part, res):
    if cur == k:
        if n_remain == 0:
            res.append(part[:])
        return
    min_val = 1
    max_val = n_remain - (k - cur - 1)
    for val in range(min_val, max_val + 1):
        part[cur] = val
        gen_ordered_partitions(cur + 1, k, n_remain - val, part, res)

def gen_partitions(cur, k, n_remain, part, res):
    if cur == k:
        if n_remain == 0:
            res.append(part[:])
        return
    start_val = 1 if cur == 0 else part[cur - 1]
    end_val = n_remain - (k - cur - 1)
    for val in range(start_val, end_val + 1):
        part[cur] = val
        gen_partitions(cur + 1, k, n_remain - val, part, res)

def ferrers(part):
    for val in part:
        print('*' * val)

def ferrers_transpose(part):
    max_height = max(part)
    k = len(part)
    for i in range(1, max_height + 1):
        for j in range(k):
            print('*' if part[j] >= i else ' ', end='')
        print()

n, k = map(int, input().split())

if k > n or k <= 0 or n <= 0:
    print("Không có phân hoạch")
else:
    partitions = []
    part = [0] * k
    gen_partitions(0, k, n, part, partitions)
    # gen_ordered_partitions(0, k, n, part, partitions)

    print(f"Có p_{k}({n}) = {len(partitions)} phân hoạch của {n} có {k} phần tử :\n")

    for idx, p in enumerate(partitions, 1):
        print(f"Phân hoạch {idx}: ({', '.join(map(str, p))})\n")

        print("Biểu đồ Ferrers:")
        ferrers(p)
        print()

        print("Biểu đồ Ferrers chuyển vị:")
        ferrers_transpose(p)
        print("\n---------------------\n")