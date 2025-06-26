def thap_ha_noi(n, coc_nguon, coc_dich, coc_trung_gian):
    if n == 1:
        print(f"Chuyển đĩa 1 từ {coc_nguon} sang {coc_dich}")
        return
   
    thap_ha_noi(n - 1, coc_nguon, coc_trung_gian, coc_dich)
    
    print(f"Chuyển đĩa {n} từ {coc_nguon} sang {coc_dich}")
   
    thap_ha_noi(n - 1, coc_trung_gian, coc_dich, coc_nguon)

n = int(input("Nhập số đĩa: "))

thap_ha_noi(n, 'A', 'B', 'C')

def thap_ha_noi(n, cot_nguon, cot_dich, cot_trung_gian):
    if n == 1:
        print(f"Chuyển đĩa 1 từ cọc {cot_nguon} sang cọc {cot_dich}")
    else:
        thap_ha_noi(n-1, cot_nguon, cot_trung_gian, cot_dich)
        print(f"Chuyển đĩa {n} từ cọc {cot_nguon} sang cọc {cot_dich}")
        thap_ha_noi(n-1, cot_trung_gian, cot_dich, cot_nguon)

# Sử dụng:
n = int(input("Nhập số đĩa: "))
thap_ha_noi(n, 1, 2, 3)

def hanoi(n, start, end, temp):
    if n == 1:
        print(f"Chuyển đĩa 1 từ cọc {start} sang cọc {end}")
    else:
        hanoi(n - 1, start, temp, end)  
        print(f"Chuyển đĩa {n} từ cọc {start} sang cọc {end}")  
        hanoi(n - 1, temp, end, start)  
n = int(input("Nhập số lượng đĩa: "))
print("Các bước chuyển:")
hanoi(n, '1', '2', '3')

#bai19
thap_ha_noi = []

def giai_thap_ha_noi(n, cot_goc, cot_dich, cot_trung_gian):
    if n == 1:
        thap_ha_noi.append((1, cot_goc, cot_dich))
    else:
        giai_thap_ha_noi(n - 1, cot_goc, cot_trung_gian, cot_dich)
        thap_ha_noi.append((n, cot_goc, cot_dich))
        giai_thap_ha_noi(n - 1, cot_trung_gian, cot_dich, cot_goc)

def in_thap_ha_noi(n):
    print(f"\nBài toán: Di chuyển {n} đĩa từ cọc A sang cọc C theo đúng quy tắc.")
    print("Yêu cầu: Chỉ được di chuyển 1 đĩa mỗi lần và không đặt đĩa lớn lên đĩa nhỏ.\n")
    print("Các bước thực hiện:")

    giai_thap_ha_noi(n, "A", "C", "B")

    for i, (so_dia, cot_moc, cot_dich) in enumerate(thap_ha_noi, start=1):
        print(f"Bước {i}: Di chuyển đĩa {so_dia} từ cọc {cot_moc} sang cọc {cot_dich}.")

    print(f"\nCó tất cả {len(thap_ha_noi)} bước để hoàn thành việc di chuyển {n} đĩa.")

n = int(input("Nhập số lượng đĩa: "))
in_thap_ha_noi(n)