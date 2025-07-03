#Sắp xếp từ điển danh sách là chuỗi
def sapxep(lst):
    n = len(lst)
    for i in range(n):
        for j in range(0, n - i - 1):
            if lst[j] > lst[j + 1]:
                lst[j], lst[j + 1] = lst[j + 1], lst[j]
    return lst
chuoi = input().split()
sapxep2 = sapxep(chuoi)
print(sapxep2)

ds = input("Nhập các chuỗi, cách nhau bởi dấu phẩy: ").split()

n = len(ds)
for i in range(n - 1):
    for j in range(i + 1, n):
        if ds[i] > ds[j]:
            ds[i], ds[j] = ds[j], ds[i]

print("Danh sách sau khi sắp xếp:")
for x in ds:
    print(x)

# Hàm sắp xếp từ điển danh sách chuỗi
def sap_xep_tu_dien(danh_sach):
    return sorted(danh_sach)

# Chạy chương trình
ds = input("Nhập danh sách các chuỗi, cách nhau bởi dấu phẩy: ").split()
ds = [s.strip() for s in ds]  # Xoá khoảng trắng thừa nếu có
ds_sap_xep = sap_xep_tu_dien(ds)

print("Danh sách sau khi sắp xếp từ điển:")
print(ds_sap_xep)

# Hàm sắp xếp từ điển danh sách chuỗi
def sap_xep_tu_dien(danh_sach):
    return sorted(danh_sach)

# Nhập danh sách chuỗi cách nhau bằng dấu cách
ds = input("Nhập danh sách các chuỗi, cách nhau bởi dấu cách: ").split()
ds_sap_xep = sap_xep_tu_dien(ds)

print("Danh sách sau khi sắp xếp từ điển:")
for item in ds_sap_xep:
    print(item)

def sap_xep_tu_dien(danh_sach):
    return sorted(danh_sach)
danh_sach = input("Nhập các chuỗi, cách nhau bởi dấu phẩy: ").split(",")
danh_sach = [tu.strip() for tu in danh_sach]
danh_sach_sap_xep = sap_xep_tu_dien(danh_sach)
print("Danh sách sau khi sắp xếp từ điển:", danh_sach_sap_xep)