from collections import Counter

def al_to_eal(adj_list):
    eal = []
    for u, neighbors in enumerate(adj_list):
        freq = Counter(neighbors)  # Dem so lan moi dinh xuat hien
        for v, w in freq.items():
            eal.append((u, v, w))
    return eal

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
adj_list = []

print("Nhap danh sach ke:")
for i in range(n):
    row = list(map(int, input(f"Ke cua dinh {i}: ").split()))
    adj_list.append(row)

# Chuyen doi va in ket qua
eal = al_to_eal(adj_list)
print("Danh sach ke mo rong (EAL):")
for u, v, w in eal:
    print(f"({u}, {v}, {w})")