# BT2
x = int(input('Nhap x: '))
y= int(input('Nhap y: '))
z = int(input('Nhap z: '))

p = (x + 1 == 2)
q = (x + y == z)

print("p AND q: " + str(p and q))
print("p OR q: " + str(p or q))
print("negative p: " + str(not p))
print("negative q: " + str(not q))
print("p XOR q: " + str(p != q))
