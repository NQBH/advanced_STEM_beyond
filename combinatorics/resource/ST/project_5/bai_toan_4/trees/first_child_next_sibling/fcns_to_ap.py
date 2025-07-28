def dfs(u, p, fc, ns, parent):
    parent[u] = p  # Gan cha cho nut u
    if fc[u] != -1:
        dfs(fc[u], u, fc, ns, parent)
    if ns[u] != -1:
        dfs(ns[u], p, fc, ns, parent)  # Anh em giu cha giong nhau

n = int(input("Nhap so nut: "))
print("Nhap mang fc:")
fc = list(map(int, input().split()))
print("Nhap mang ns:")
ns = list(map(int, input().split()))

parent = [-1] * n  # Khoi tao mang cha

dfs(0, -1, fc, ns, parent)  # Goc la 0

print("Mang parent:")
print(parent)