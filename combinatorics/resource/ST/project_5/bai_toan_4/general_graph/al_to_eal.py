def al_to_eal(adj_list):
    eal = []
    for u in range(len(adj_list)):
        for v in adj_list[u]:
            eal.append((u, v, 1))  # Them canh (u, v) voi trong so 1
    return eal

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
adj_list = []
print("Nhap danh sach ke (AL):")
for i in range(n):
    row = list(map(int, input(f"{i}: ").split()))
    adj_list.append(row)

eal = al_to_eal(adj_list)

print("Danh sach ke mo rong (EAL):")
for u, v, w in eal:
    print(f"{u} {v} {w}")