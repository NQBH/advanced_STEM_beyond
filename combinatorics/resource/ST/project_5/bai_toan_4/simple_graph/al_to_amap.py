# Ham chuyen danh sach ke sang ban do ke
def adjacency_list_to_map(adj_list, n):
    adj_map = {}  # Khoi tao tu dien rong
    for i in range(n):
        adj_map[i] = adj_list[i]  # Gan danh sach ke cua i vao map
    return adj_map

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
adj_list = []

print("Nhap danh sach ke:")
for i in range(n):
    line = list(map(int, input(f"Dinh {i}: ").split()))
    adj_list.append(line)

# Chuyen sang ban do ke
adj_map = adjacency_list_to_map(adj_list, n)

# In ban do ke
print("Adjacency Map:")
for u in adj_map:
    print(f"{u}: {adj_map[u]}")