from itertools import permutations

def enumerate_perfect_matchings(p, q):
    """Liệt kê tất cả các ghép nối hoàn hảo trong Kp,q"""
    if p != q:
        print(f"Perfect matchings only exist when p = q. Current: p={p}, q={q}")
        return []
    
    # Tập 1: đỉnh 0 đến p-1
    # Tập 2: đỉnh p đến p+q-1
    set1 = list(range(p))
    set2 = list(range(p, p + q))
    
    matchings = []
    
    # Với mỗi hoán vị của tập 2, tạo một ghép nối
    for perm in permutations(set2):
        matching = []
        for i in range(p):
            matching.append((set1[i], perm[i]))
        matchings.append(matching)
    
    return matchings

def main():
    print("Perfect matchings in K2,2:")
    matchings = enumerate_perfect_matchings(2, 2)
    print(f"Number of perfect matchings: {len(matchings)}")
    for i, matching in enumerate(matchings):
        print(f"Matching {i+1}: {matching}")
    
    print("\nPerfect matchings in K3,3:")
    matchings = enumerate_perfect_matchings(3, 3)
    print(f"Number of perfect matchings: {len(matchings)}")
    # Chỉ hiển thị 5 cái đầu để không quá dài
    for i in range(min(5, len(matchings))):
        print(f"Matching {i+1}: {matchings[i]}")
    if len(matchings) > 5:
        print(f"... and {len(matchings) - 5} more matchings")

if __name__ == "__main__":
    main()