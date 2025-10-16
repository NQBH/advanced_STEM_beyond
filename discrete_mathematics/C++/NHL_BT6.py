# ---- quy ước ---
p = [1, 1, 1, 1, 0, 0, 0, 0]
q = [1, 1, 0, 0, 1, 1, 0, 0]
r = [1, 0, 1, 0, 1, 0, 1, 0]
Y = [0, 0, 0, 0, 0, 0, 0, 0]
D = [0, 0, 0, 0, 0, 0, 0, 0]

def check(name, Y, D):
    if Y == D:
        print(name, ': True')
    else:
        print(name, ': False')

print('Problem 7')

# mã 1
for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        Y[i] = 0
    else: 
        Y[i] = 1

for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        D[i] = 0
    else: 
        D[i] = 1

check('1', Y, D)

# mã 2
for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        Y[i] = 0
    else: 
        Y[i] = 1

for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        D[i] = 0
    else: 
        D[i] = 1

check('2', Y, D)

# mã 3
for i in range(8):
    if (p[i] == 0) and (q[i] == 0):
        Y[i] = 0
    else: 
        Y[i] = 1

for i in range(8):
    if (p[i] == 0) and (q[i] == 0):
        D[i] = 0
    else: 
        D[i] = 1

check('3', Y, D)

# mã 4
for i in range(8):
    if (p[i] == 1) and (q[i] == 1):
        Y[i] = 1
    else: 
        Y[i] = 0

for i in range(8):
    if (p[i] == 1) and (q[i] == 1):
        D[i] = 1
    else: 
        D[i] = 0

check('4', Y, D)

# mã 5
for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        Y[i] = 1
    else: 
        Y[i] = 0

for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        D[i] = 1
    else: 
        D[i] = 0

check('5', Y, D)

# mã 6
for i in range(8):
    if (p[i] == 0) or (p[i] == q[i] == r[i] == 1):
        Y[i] = 1
    else: 
        Y[i] = 0

for i in range(8):
    if (p[i] == 1) and ((q[i] == 0) or (r[i] == 0)):
        D[i] = 0
    else: 
        D[i] = 1

check('6', Y, D)

# mã 7
for i in range(8):
    if (((p[i] == 0) and (q[i] == 0)) or (r[i] == 1)) or (p[i] == q[i] == r[i] == 1):
        Y[i] = 1
    else: 
        Y[i] = 0

for i in range(8):
    if (r[i] == 0) and ((q[i] == 1) or (p[i] == 1)):
        D[i] = 0
    else: 
        D[i] = 1

check('7', Y, D)

# mã 8
for i in range(8):
    if (p[i] == 1) and (q[i] == r[i] == 0): 
        Y[i] = 0
    else: 
        Y[i] = 1

for i in range(8):
    if (p[i] == 1) and (q[i] == r[i] == 0):
        D[i] = 0
    else: 
        D[i] = 1

check('8', Y, D)

# mã 9
for i in range(8):
    if (p[i] == q[i] == 1) and (r[i] == 0): 
        Y[i] = 0
    else: 
        Y[i] = 1

for i in range(8):
    if (p[i] == 1) and ((p[i] == q[i] == 1) and (r[i] == 0)):
        D[i] = 0
    else: 
        D[i] = 1

check('9', Y, D)

print('Problem 8')

# mã 1 
for i in range(8):
    if (p[i] == q[i]): 
        Y[i] = 1
    else: 
        Y[i] = 0

for i in range(8):
    if (p[i] == q[i]):
        D[i] = 1
    else: 
        D[i] = 0

check('1', Y, D)

# mã 2 
for i in range(8):
    if (p[i] == q[i]): 
        Y[i] = 1
    else: 
        Y[i] = 0

for i in range(8):
    if (p[i] == q[i]):
        D[i] = 1
    else: 
        D[i] = 0

check('2', Y, D)

# mã 3
for i in range(8):
    if (p[i] == q[i]): 
        Y[i] = 1
    else: 
        Y[i] = 0

for i in range(8):
    if (p[i] != q[i]):
        D[i] = 0
    else: 
        D[i] = 1

check('3', Y, D)

# mã 4
for i in range(8):
    if (p[i] == q[i]): 
        Y[i] = 0
    else: 
        Y[i] = 1

for i in range(8):
    if (p[i] != q[i]):
        D[i] = 1
    else: 
        D[i] = 0

check('4', Y, D)