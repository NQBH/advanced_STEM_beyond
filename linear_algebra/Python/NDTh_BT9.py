n = int(input("nhap n :"))
a =[list(map(int,input().split())) for _ in range(n)]

duong_cheo = tam_gaic_tren = tam_giac_duoi = tam_giac_doi_xung = True

for i in range(n):
    for j in range(n):
        if i != j and a[i][j] != 0:
            duong_cheo = False
        if i > j and a[i][j] != 0:
            tam_gaic_tren = False
        if i < j and a[i][j] != 0:
            tam_giac_duoi = False
        if a[i][j] != a[j][i]:
            tam_giac_doi_xung = False
print("duong cheo","co" if duong_cheo else "khong")
print("tam giac tren","co" if tam_gaic_tren else "khong")
print("tam giac duoi","co" if tam_giac_duoi else "khong")
print(" doi xung","co" if tam_giac_doi_xung else "khong")   