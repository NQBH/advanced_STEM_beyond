A=[] 

n=int(input("nhap n: "))
print("nhap ma tran A:")
for i in range(n):
    row=[]
    for j in range(n):
        row.append(int(input(f"A[{i}][{j}] = ")))
    A.append(row)

print('Ma tran A:')
for i in range(n):
    for j in range(n):
        print(A[i][j], end=' ')
    print()

duongcheo = True
tamGiactren = True
tamGiacduoi = True
doixung = True

for i in range(n):
    for j in range(n):
        if A[i][j] !=0 and i!=j:
            duongcheo = False
        if A[i][j] !=0 and i>j:
            tamGiactren = False
        if A[i][j] !=0 and i<j:
            tamGiacduoi = False
        if A[i][j] != A[j][i]:
            doixung = False
print(f"Ma tran duong cheo {'true' if duongcheo else 'false'}")
print(f"Ma tran tam giac tren {'true' if tamGiactren else 'false'}")
print(f"Ma tran tam giac duoi {'true' if tamGiacduoi else 'false'}")
print(f"Ma tran doi xung {'true' if doixung else 'false'}")  