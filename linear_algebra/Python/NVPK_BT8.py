def nhap_n():
 while True:
    try:
        n= int(input("Nhập kích thước n cho ma trận(sô nguyên dương): "))
        if n >0:
            return n
        else:
            print("Lỗi: vui lòng nhập số nguyê dương !")
    except ValueError:
        print("Lỗi :phần tử không hợp lệ, vui lòng nhập số nguyên!")
        
def tao_va_xuat_ma_tran():
    n= nhap_n()
    
    ma_tran_khong=[[0 for j in range(n)] for i in range(n)]
    ma_tran_don_vi=[]
    for i in range(n):
         hang = []
         for j in range(n):
             if i == j:
                 hang.append(1)
             else:
                 hang.append(0)
         ma_tran_don_vi.append(hang)
    xuat_ma_tran(ma_tran_khong, "không",n)
    xuat_ma_tran(ma_tran_don_vi, "đơn vị",n)
        
def xuat_ma_tran(ma_tran, ten_ma_tran, kich_thuoc_n):
    print(f"\n-- Ma trận {ten_ma_tran} kích thước {kich_thuoc_n}x{kich_thuoc_n} --")
    for hang in ma_tran:
        print(" ".join(map(str, hang)))
        

if __name__ == "__main__":
    tao_va_xuat_ma_tran()