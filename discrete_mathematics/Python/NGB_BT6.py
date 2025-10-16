p = [1,1,1,1,0,0,0,0]
q = [1,1,0,0,1,1,0,0]
r = [1,0,1,0,1,0,1,0]
A = [0,0,0,0,0,0,0,0]
B = [0,0,0,0,0,0,0,0]

def check(name, A, B):
    if A == B:
        print(name, ': True')
    else:
        print(name, ': False')

print("Table 7: Logical Equivalences Involving Conditional Statements")

# p -> q == not p or q
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

# p -> q == not q -> not p
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

# p or q == not p -> q
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

# p and q == not(p -> (not q))
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

# not (p -> q) == p and not q
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

# (p -> q) and (p -> r) == p -> (q and r)
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

# (p -> r) and (q -> r) == (p or q) -> r
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

# (p -> q) or (p -> r) == p -> (q or r)
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

# (p -> r) or (q -> r) == (p and q) -> r
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



print("Table 8: Logic Equivalences Involving Biconditional Statements")

# p <-> q == (p -> q) and (q -> p)
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

# p <-> q == not p <-> not q
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

# p <-> q == (p and q) or (not p and not q)
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

# not (p <-> q) == p <-> not q
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