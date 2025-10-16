# 1 = True
# 0 = False

p = [1,1,1,1,0,0,0,0]
q = [1,1,0,0,1,1,0,0]
r = [1,0,1,0,1,0,1,0]
T = [1,1,1,1,1,1,1,1]
F = [0,0,0,0,0,0,0,0]
A = [0,0,0,0,0,0,0,0]
B = [0,0,0,0,0,0,0,0]

# Identity laws
print('1:')
    # TH1
for i in range(len(p)):
    if (p[i] == T[i]):
        A[i] = 1
    else: 
        A[i] = 0
if A == p:
    print('True')
else:
    print('False')

    # TH2
for i in range(len(p)):
    if (p[i] == 0):
        A[i] = 0
    else: 
        A[i] = 1
if A == p:
    print('True')
else:
    print('False')

# Domination laws
print('2:')
    # TH1
for i in range(len(p)):
    if (p[i] ==1) or (p[i]==0):
        A[i] = 1
    else: 
        A[i] = 0
if A == T :
    print('True')
else:
    print('False')

    # TH2
for i in range(len(p)):
    if (F[i] == 0):
        A[i] = 0
    else: 
        A[i] = 1
if A == F:
    print('True')
else:
    print('False')

# Idempotent laws
print('3:')

    # TH1
for i in range(len(p)):
    if (p[i] == 1):
        A[i] = 1
    else: 
        A[i] = 0
if A == p:
    print('True')
else:
    print('False')

# Th2
for i in range(len(p)):
    if (p[i] == 1):
        A[i] = 1
    else: 
        A[i] = 0
if A == p:
    print('True')
else:
    print('False')

# Double nagation laws
print('4:')
for i in range(len(p)):
    if (p[i] == 1):
        A[i] = 1
    else: 
        A[i] = 0
if A == p:
    print('True')
else:
    print('False')

# Commutative laws
print('5:')
     # TH1
for i in range(4):
    if p[i] == 1 or q[i] == 1:
        A[i] = 1
    else:
        A[i] = 0

for i in range(4):
    if q[i] == 1 or p[i] == 1:
        B[i] = 1
    else:
        B[i] = 0
if A == B:
    print('True')
else:
    print('False')

    # TH2
for i in range(4):
    if p[i] == 1 and q[i] == 1:
        A[i] = 1
    else:
        A[i] = 0

for i in range(4):
    if q[i] == 1 and p[i] == 1:
        B[i] = 1
    else:
        B[i] = 0
if A == B:
    print('True')
else:
    print('False')

# Associative laws
print('6:')
    # TH1
for i in range(8):
    if (p[i] == 1 or q[i] == 1) or r[i] == 1:
        A[i] = 1
    else:
        A[i] = 0

for i in range(8):
    if p[i] == 1 or (q[i] == 1 or r[i] == 1):
        B[i] = 1
    else:
        B[i] = 0
if A == B:
    print('True')
else:
    print('False')

    # TH2
for i in range(8):
    if (p[i] == 1 and q[i] == 1) and r[i] == 1:
        A[i] = 1
    else:
        A[i] = 0

for i in range(8):
    if p[i] == 1 and (q[i] == 1 and r[i] == 1):
        B[i] = 1
    else:
        B[i] = 0
if A == B:
    print('True')
else:
    print('False')

# Distributive laws
print('7:')
    # TH1
for i in range(8):
    if p[i] == 1 or (q[i] == 1 and r[i] == 1):
        A[i] = 1
    else:
        A[i] = 0

for i in range(8):
    if (p[i] == 1 or q[i] == 1) and (p[i] == 1 or r[i] == 1):
        B[i] = 1
    else:
        B[i] = 0
if A == B:
    print('True')
else:
    print('False')

    # TH2
for i in range(8):
    if p[i] == 1 and (q[i] == 1 or r[i] == 1):
        A[i] = 1
    else:
        A[i] = 0

for i in range(8):
    if (p[i] == 1 and q[i] == 1) or (p[i] == 1 and r[i] == 1):
        B[i] = 1
    else:
        B[i] = 0
if A == B:
    print('True')
else:
    print('False')

# De Morgan’s laws
print('8:')
# th1
for i in range(8):
    if not (p[i] == 1 or q[i] == 1):
        A[i] = 1
    else:
        A[i] = 0

for i in range(8):
    if not p[i] == 1 and not q[i] == 1:
        B[i] = 1
    else:
        B[i] = 0
if A == B:
    print('True')
else:
    print('False')

# th2
for i in range(8):
    if not (p[i] == 1 and q[i] == 1):
        A[i] = 1
    else:
        A[i] = 0

for i in range(8):
    if not p[i] == 1 or not q[i] == 1:
        B[i] = 1
    else:
        B[i] = 0

if A == B:
    print('True')
else:
    print('False')

# Absorption laws
print('9:')
# th1
for i in range(8):
    if p[i] == 1 or (p[i] == 1 and q[i] == 1):
        A[i] = 1
    else:
        A[i] = 0
if A == p:
    print('True')
else:
    print('False')

# th2
for i in range(8):
    if p[i] == 1 and (p[i] == 1 or q[i] == 1):
        A[i] = 1
    else:
        A[i] = 0
if A == p:
    print('True')
else:
    print('False')

# Negation laws
print('10:')
# th1
for i in range(8):
    if p[i] == 1 or not p[i] == 1:
        A[i] = 1
    else:
        A[i] = 0
if A == T:
    print('True')
else:
    print('False')
# th2
for i in range(8):
    if p[i] == 1 and not p[i] == 1:
        A[i] = 1
    else:
        A[i] = 0
if A == F:
    print('True')
else:
    print('False')

