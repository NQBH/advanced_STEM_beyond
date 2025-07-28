def al_to_amap(adj_list):
    amap = {}
    for u in range(len(adj_list)):
        for v in adj_list[u]:
            if u not in amap:
                amap[u] = {}  # Khoi tao dict con neu chua co
            amap[u][v] = 1   # Gan trong so 1 cho canh u -> v
    return amap

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
adj_list = []
print("Nhap danh sach ke (AL):")
for i in range(n):
    row = list(map(int, input(f"{i}: ").split()))
    adj_list.append(row)

amap = al_to_amap(adj_list)

print("Adjacency Map (AMap):")
for u in amap:
    for v in amap[u]:
        print(f"{u} -> {v}: {amap[u][v]}")