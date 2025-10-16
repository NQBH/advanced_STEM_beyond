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
p_and_q = p and q
p_or_q = p or q
not_p = not p
not_q = not q
p_xor_q = p != q
print(f"p and q = {p_and_q}")
print(f"p or q = {p_or_q}")
print(f"not p = {not_p}")
print(f"not q = {not_q}")
print(f"p xor q = {p_xor_q}")