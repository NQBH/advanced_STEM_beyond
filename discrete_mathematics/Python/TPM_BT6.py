# 1: True
# 0: False

p = [1,1,1,1,0,0,0,0]
q = [1,1,0,0,1,1,0,0]
r = [1,0,1,0,1,0,1,0]
A = [0,0,0,0,0,0,0,0]
B = [0,0,0,0,0,0,0,0]

# Hàm check
def check(name, A, B):
    if A == B:
        print(name, ': True')
    else:
        print(name, ': False')

print('Bảng 7 nhoa thầy')

#1
for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        A[i] = 0
    else: 
        A[i] = 1

for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        B[i] = 0
    else: 
        B[i] = 1

check('1',A,B)

#2
for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        A[i] = 0
    else: 
        A[i] = 1

for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        B[i] = 0
    else: 
        B[i] = 1

check('2',A,B)

#3 
for i in range(8):
    if (p[i] == 0) and (q[i] == 0):
        A[i] = 0
    else: 
        A[i] = 1

for i in range(8):
    if (p[i] == 0) and (q[i] == 0):
        B[i] = 0
    else: 
        B[i] = 1

check('3',A,B)

#4
for i in range(8):
    if (p[i] == 1) and (q[i] == 1):
        A[i] = 1
    else: 
        A[i] = 0

for i in range(8):
    if (p[i] == 1) and (q[i] == 1):
        B[i] = 1
    else: 
        B[i] = 0

check('4',A,B)

#5
for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        A[i] = 1
    else: 
        A[i] = 0

for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        B[i] = 1
    else: 
        B[i] = 0

check('5',A,B)

#6
for i in range(8):
    if (p[i] == 0) or (p[i] == q[i] == r[i] == 1):
        A[i] = 1
    else: 
        A[i] = 0

for i in range(8):
    if (p[i] == 1) and ((q[i] == 0) or (r[i] == 0)):
        B[i] = 0
    else: 
        B[i] = 1

check('6',A,B)

#7
for i in range(8):
    if (((p[i] == 0) and (q[i] == 0)) or  (r[i] == 1)) or (p[i] == q[i] == r[i] == 1):
        A[i] = 1
    else: 
        A[i] = 0

for i in range(8):
    if (r[i] == 0) and ((q[i] == 1) or (p[i] == 1)):
        B[i] = 0
    else: 
        B[i] = 1

check('7',A,B)

#8
for i in range(8):
    if (p[i] == 1) and (q[i] == r[i] == 0): 
        A[i] = 0
    else: 
        A[i] = 1

for i in range(8):
    if (p[i] == 1) and (q[i] == r[i] == 0):
        B[i] = 0
    else: 
        B[i] = 1

check('8',A,B)

#9
for i in range(8):
    if (p[i] == q[i] == 1) and (r[i] == 0): 
        A[i] = 0
    else: 
        A[i] = 1

for i in range(8):
    if (p[i] == 1) and ((p[i] == q[i] == 1) and (r[i] == 0)):
        B[i] = 0
    else: 
        B[i] = 1

check('9',A,B)



print('Bảng 8 nhoa thầy')

#1 
for i in range(8):
    if (p[i] == q[i]): 
        A[i] = 1
    else: 
        A[i] = 0

for i in range(8):
    if (p[i] == q[i]):
        B[i] = 1
    else: 
        B[i] = 0

check('1',A,B)

#2 
for i in range(8):
    if (p[i] == q[i]): 
        A[i] = 1
    else: 
        A[i] = 0

for i in range(8):
    if (p[i] == q[i]):
        B[i] = 1
    else: 
        B[i] = 0

check('2',A,B)

#3
for i in range(8):
    if (p[i] == q[i]): 
        A[i] = 1
    else: 
        A[i] = 0

for i in range(8):
    if (p[i] != q[i]):
        B[i] = 0
    else: 
        B[i] = 1

check('3',A,B)

#4
for i in range(8):
    if (p[i] == q[i]): 
        A[i] = 0
    else: 
        A[i] = 1

for i in range(8):
    if (p[i] != q[i]):
        B[i] = 1
    else: 
        B[i] = 0

check('4',A,B)