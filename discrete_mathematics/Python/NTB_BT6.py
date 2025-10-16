p = [1,1,1,1,0,0,0,0]
q = [1,1,0,0,1,1,0,0]
r = [1,0,1,0,1,0,1,0]
S = [0,0,0,0,0,0,0,0]
X = [0,0,0,0,0,0,0,0]

def check(name, S, X):
    if S == X:
        print(name, ': True')
    else:
        print(name, ': False')

print('bang 7')

#cau 1
for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        S[i] = 0
    else: 
        S[i] = 1

for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        X[i] = 0
    else: 
        X[i] = 1

check('1',S,X)

#cau 2
for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        S[i] = 0
    else: 
        S[i] = 1

for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        X[i] = 0
    else: 
        X[i] = 1

check('2',S,X)

#cau 3
for i in range(8):
    if (p[i] == 0) and (q[i] == 0):
        S[i] = 0
    else: 
        S[i] = 1

for i in range(8):
    if (p[i] == 0) and (q[i] == 0):
        X[i] = 0
    else: 
        X[i] = 1

check('3',S,X)

#cau 4
for i in range(8):
    if (p[i] == 1) and (q[i] == 1):
        S[i] = 1
    else: 
        S[i] = 0

for i in range(8):
    if (p[i] == 1) and (q[i] == 1):
        X[i] = 1
    else: 
        X[i] = 0

check('4',S,X)

#cau 5
for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        S[i] = 1
    else: 
        S[i] = 0

for i in range(8):
    if (p[i] == 1) and (q[i] == 0):
        X[i] = 1
    else: 
        X[i] = 0

check('5',S,X)

#cau 6
for i in range(8):
    if (p[i] == 0) or (p[i] == q[i] == r[i] == 1):
        S[i] = 1
    else: 
        S[i] = 0

for i in range(8):
    if (p[i] == 1) and ((q[i] == 0) or (r[i] == 0)):
        X[i] = 0
    else: 
        X[i] = 1

check('6',S,X)

#cau 7
for i in range(8):
    if (((p[i] == 0) and (q[i] == 0)) or  (r[i] == 1)) or (p[i] == q[i] == r[i] == 1):
        S[i] = 1
    else: 
        S[i] = 0

for i in range(8):
    if (r[i] == 0) and ((q[i] == 1) or (p[i] == 1)):
        X[i] = 0
    else: 
        X[i] = 1

check('7',S,X)

#cau 8
for i in range(8):
    if (p[i] == 1) and (q[i] == r[i] == 0): 
        S[i] = 0
    else: 
        S[i] = 1

for i in range(8):
    if (p[i] == 1) and (q[i] == r[i] == 0):
        X[i] = 0
    else: 
        X[i] = 1

check('8',S,X)

#cau 9
for i in range(8):
    if (p[i] == q[i] == 1) and (r[i] == 0): 
        S[i] = 0
    else: 
        S[i] = 1

for i in range(8):
    if (p[i] == 1) and ((p[i] == q[i] == 1) and (r[i] == 0)):
        X[i] = 0
    else: 
        X[i] = 1

check('9',S,X)



print('bang 8')

#cau 1
for i in range(8):
    if (p[i] == q[i]): 
        S[i] = 1
    else: 
        S[i] = 0

for i in range(8):
    if (p[i] == q[i]):
        X[i] = 1
    else: 
        X[i] = 0

check('1',S,X)

#cau 2
for i in range(8):
    if (p[i] == q[i]): 
        S[i] = 1
    else: 
        S[i] = 0

for i in range(8):
    if (p[i] == q[i]):
        X[i] = 1
    else: 
        X[i] = 0

check('2',S,X)

#cau 3
for i in range(8):
    if (p[i] == q[i]): 
        S[i] = 1
    else: 
        S[i] = 0

for i in range(8):
    if (p[i] != q[i]):
        X[i] = 0
    else: 
        X[i] = 1

check('3',S,X)

#cau 4
for i in range(8):
    if (p[i] == q[i]): 
        S[i] = 0
    else: 
        S[i] = 1

for i in range(8):
    if (p[i] != q[i]):
        X[i] = 1
    else: 
        X[i] = 0

check('4',S,X)