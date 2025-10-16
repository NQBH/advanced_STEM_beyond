x = int(input('Nhap x: '))
y= int(input('Nhap y: '))
z = int(input('Nhap z: '))

P = (x + 1 == 2)
Q = (x + y == z)

print("P AND Q: " + str(P and Q))
print("P OR Q: " + str(P or Q))
print("negative P: " + str(not P))
print("negative Q: " + str(not Q))
print("P XOR Q: " + str(P != Q))
