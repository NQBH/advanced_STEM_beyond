n = int(input("Nhap so nut: "))
print("Nhap mang parent:")
parent = list(map(int, input().split()))

# Khoi tao danh sach ke
adj = [[] for _ in range(n)]

# Tao canh giua moi nut va cha no
for i in range(n):
    if parent[i] != -1:
        u = i
        v = parent[i]
        adj[u].append(v)
        adj[v].append(u)  # Do thi vo huong

# In danh sach ke
print("Danh sach ke (Graph tu AP):")
for i in range(n):
    print(f"{i}:", adj[i])