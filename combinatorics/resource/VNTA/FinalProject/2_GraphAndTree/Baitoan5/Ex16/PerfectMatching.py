from itertools import permutations

def enumerate_perfect_matchings(p, q):
    if p != q:
        print("Không tồn tại perfect matching vì p != q.")
        return

    P = list(range(p))
    Q = list(range(q))

    for perm in permutations(Q):
        matching = [(P[i], perm[i]) for i in range(p)]
        print(matching)

# Ví dụ
enumerate_perfect_matchings(5, 5)
