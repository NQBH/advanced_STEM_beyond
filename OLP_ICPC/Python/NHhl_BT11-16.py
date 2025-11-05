cau = input('Nhập câu: ')
y = int(input('Nhập P(x): '))
n = int(input('Nhập Q(x): '))

print("\n--- bài 11 ---")
if cau in ['a', 'b', 'c', 'd']:
    print(f"11{cau}: ", end="")
    if y == y ** 2: 
        print(1)
    else: 
        print(0)

elif cau == 'e':
    print(f"11{cau}: ", end="")
    for i in range(-y,y+1):
        if i == i ** 2: 
            print(1)
            break
    else: 
        print(0)

else:
    print(f"11{cau}: ", end="")
    for i in range(-y,y+1):
        if i != i ** 2:
            print(0)
        break    
    else: 
        print(1)

print("\n--- bài 12 ---")
if cau in ['a', 'b', 'c', 'd']:
    print(f"12{cau}: ", end="")
    if ((n + 1) > (2 * n)): 
       print(1)
    else: 
        print(0)
elif cau in ['a']:
    print(f"12{cau}: ", end="")
    for i in range(-n,n+1):
        if ((n + 1) > (2 * n)): 
            print(1)
            break
    else: 
        print(0)

elif cau in ['b']:
    print(f"12{cau}: ", end="")
    for i in range(-n,n+1): 
        if ((n + 1) <= (2 * n)):
            print(0)
    else:
        print(1)
elif cau in ['c']:
    print(f"12{cau}: ", end="")
    for i in range(-n,n+1):
        if ((n + 1) <= (2 * n)): 
            print(1)
            break
    else: 
        print(0)
elif cau in ['d']:
    print(f"12{cau}: ", end="")
    for i in range(n+1):
        if ((n + 1) > (2 * n)):
            print(0)
            break
    else:
        print(1)
print("\n--- bài 13 ---")

print("13a: ", end="")
for i in range(-n,n+1):
    if ((n+1) <= n):
        print('a: ',0)
        break 
else: 
    print('a: ',1)

print("13b: ", end="")
for i in range(-n,n+1):
    if (2*n == 3*n):
        print('b: ',1)
        break 
else: 
    print('b: ',0)

print("13c: ", end="")
for i in range(-n,n+1):
    if n == -n:
        print('c: ',1)
        break 
else: 
    print('c: ',0)

print("13d: ", end="")
for i in range(-n,n+1):
    if (3*n > 4*n):
        print('d: ',0)
        break 
else: 
    print('d: ',1)

print("\n--- bài 14 ---")
print("14a: ", end="")
for i in range(-n,n+1):
    if (n**3 == -1):
        print('a: ',1)
        break 
else: 
    print('a: ',0)

print("14b: ", end="")
for i in range(-n,n+1):
    if (n**4 < n**2):
        print('b: ',1)
        break 
else: 
    print('b: ',0)

print("14c: ", end="")
for i in range(-n,n+1):
    if ((-n)**2 != n**2):
        print('c: ',0)
        break 
else: 
    print('c: ',1)

print("14d: ", end="")
for i in range(-n,n+1):
    if (2*n <= n):
        print('d: ',0)
        break 
else: 
    print('d: ',1)


print("\n--- bài 15 ---")
print("15a: ", end="")
for i in range(-n,n+1):
    if (n**2 < 0):
        print('a: ',0)
        break 
else: 
    print('a: ',1)

print("15b: ", end="")
for i in range(-n,n+1):
    if (n**2 == 2):
        print('b: ',1)
        break 
else: 
    print('b: ',0)

print("15c: ", end="")
for i in range(-n,n+1):
    if (n**2 < n):
        print('c: ',0)
        break 
else: 
    print('c: ',1)

print("15d: ", end="")
for i in range(-n,n+1):
    if (2*n < 0):
        print('d: ',1)
        break 
else: 
    print('d: ',0)


print("\n--- bài 16 ---")
print("16a: ", end="")
for i in range(-n,n+1):
    if (n**2 == 2):
        print('a: ',1)
        break 
else: 
    print('a: ',0)

print("16b: ", end="")
for i in range(-n,n+1):
    if (n**2 == -1):
        print('b: ',1)
        break 
else: 
    print('b: ',0)

print("16c: ", end="")
for i in range(-n,n+1):
    if ((n**2 + 2) < 1):
        print('c: ',0)
        break 
else:
    print('c: ',1)

print("16d: ", end="")
for i in range(-n,n+1):
    if (n**2 == n):
        print('d: ',0)
        break 
else: 
    print('d: ',1)