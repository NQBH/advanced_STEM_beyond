# BT3
x = int(input('Nhap x: '))
y= int(input('Nhap y: '))
z = int(input('Nhap z: '))

p = (x + 1 == 2)
q = (x + y == z)

# Mệnh đề đảo:
if p == True:
    print("q => p:", p)
else: 
    print("q => p:", not q)

# Phản đảo:
if p == True: 
    print("-q => -p:", q)
else: 
    print("-q => -p:", p)

# Nghịch đảo: 
if p == True: 
    print("-p => -q:", p)
else: 
    print("-p => -q:", not q)
