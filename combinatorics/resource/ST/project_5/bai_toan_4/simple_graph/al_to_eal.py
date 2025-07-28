# Ham chuyen danh sach ke sang danh sach ke mo rong
def adjacency_list_to_extended(adj_list, n):
    extended_list = [[] for _ in range(n)]  # Tao danh sach moi cho tung dinh

    for i in range(n):
        for j in adj_list[i]:
            extended_list[i].append((j, 1))  # Them (j, 1) vi do thi khong co trong so

    return extended_list

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
adj_list = []

print("Nhap danh sach ke:")
for i in range(n):
    line = list(map(int, input(f"Dinh {i}: ").split()))
    adj_list.append(line)

# Chuyen sang EAL va in ra
extended_list = adjacency_list_to_extended(adj_list, n)

print("Danh sach ke mo rong (EAL):")
for i, neighbors in enumerate(extended_list):
    print(f"{i}: {neighbors}")