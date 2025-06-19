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