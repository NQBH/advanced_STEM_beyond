from itertools import permutations

def enumerate_perfect_matchings(p, q):
    if p != q:
        print("Không tồn tại ghép cặp hoàn hảo vì p ≠ q.")
        return

    U = [f"u{i+1}" for i in range(p)]
    V = [f"v{i+1}" for i in range(q)]

    print(f"Tất cả các perfect matching trong K_{{{p},{q}}}:\n")

    count = 0
    for perm in permutations(V):
        matching = [(U[i], perm[i]) for i in range(p)]
        print("Matching", count + 1, ":", matching)
        count += 1

    print(f"\nTổng số perfect matching: {count}")

def main():
    p = int(input("Nhập số đỉnh bên trái (p): "))
    q = int(input("Nhập số đỉnh bên phải (q): "))
    enumerate_perfect_matchings(p, q)

if __name__ == "__main__":
    main()