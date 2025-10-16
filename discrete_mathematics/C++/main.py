x = float(input("Nhap gia tri cua x:"))
if x+1 ==2:
    p = True
else:
    p = False
x2,y = map(float ,input("Nhap gia tri cua x va y:").split())
z = float(input("Nhap gia tri cua z:"))
if x2+y ==z:
    q = True
else:
    q = False
print(f"proposition 3 is {p}")
print(f"proposition 4 is {q}")