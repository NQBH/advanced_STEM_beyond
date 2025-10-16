T = True
F = False
print ("Kiem tra Identity laws")
# p or T == p
print ("p or T == p")
for p in [T,F]:
    left = p and T
    right = p
    if left == right:
        print ("Dung")
    else: 
        print ("Sai")
# p and F == p
print ("p and F == p")
for p in [T,F]:
    left = p or F
    right = p
    if left == right:
        print ("Dung")
    else:
        print ("Sai")

print ("Kiem tra Domination laws")
# p and T == T   
print ("p and T == T")
for p in [T,F]:
    left = p or T
    right = T
    if left == right:
        print ("Dung")
    else:
        print ("Sai")
# p or F == F 
print ("p or F == F")
for p in [T,F]:
    left = p and F
    right = F
    if left == right:
        print ("Dung")
    else:
        print ("Sai")

print ("Kiem tra Idenpotent laws")
# p and p == p
print ("p and p == p")
for p in [T,F]:
    left = p or p
    right = p
    if left == right:
        print ("Dung")
    else:
        print ("Sai")
# p or p == p
print ("p or p == p")
for p in [T,F]:
    left = p and p
    right = p
    if left == right:
        print ("Dung")
    else:
        print ("Sai")

print ("Kiem tra Double negation law")
# - (- p) == p
print ("- (- p) == p")
for p in [T,F]:
    left = not (not p)
    right = p
    if left == right:
        print ("Dung")
    else:
        print ("Sai")

print ("Kiem tra Commutative laws")
# p and q == q and p
print ("p and q == q and p")
for p in [T,F]:
    for q in [T,F]:
        left = p or q 
        right = q or p
        if left == right:
            print ("Dung")
        else:
            print ("Sai")
# p or q == q or p
print ("p or q == q or p")
for p in [T,F]:
    for q in [T,F]:
        left = p and q
        right = q and p
        if left == right:
            print ("Dung")
        else:
            print ("Sai")

print ("Kiem tra Associative laws")
# (p and q) and r == p and (q and r)
print ("(p and q) and r == p and (q and r) ")
for p in [T,F]:
    for q in [T,F]:
        for r in [T,F]:
            left = (p or q) or r
            right = p or (q or r)
            if left == right:
                print ("Dung")
            else:
                print ("Sai")
# (p or q) or r == p or (q or r)
print ("(p or q) or r == p or (q or r)")
for p in [T,F]:
    for q in [T,F]:
        for r in [T,F]:
            left = (p and q) and r
            right = p and (q and r)
            if left == right:
                print ("Dung")
            else:
                print ("Sai")

print ("KIem tra Distributive laws")
# p and (q or r) == (p and q) or (p and r)
print ("p and (q or r) == (p and q) or (p and r)")
for p in [T,F]:
    for q in [T,F]:
        for r in [T,F]:
            left = p or (q and r)
            right = (p or q) and (p or r)
            if left == right:
                print ("Dung")
            else:
                print ("Sai")
# p or (q and r) == (p or q) and (p or r)
print ("p or (q and r) == (o or q) and (p or r)")
for p in [T,F]:
    for q in [T,F]:
        for r in [T,F]:
            left = p and (q or r)
            right = (p and q) or (p and r)
            if left == right:
                print ("Dung")
            else:
                print ("Sai")

print ("Kiem tra De Morgan's laws")
# -(p or q) == -p and -q
print ("-(p or q) == -p and -q")
for p in [T,F]:
    for q in [T,F]:
        left = not (p and q)
        right = (not p) or (not q)
        if left == right:
            print ("Dung")
        else:
            print ("Sai")
# -(p and q) == -p or -q
print ("-(p and q) == -p or -q")
for p in [T,F]:
    for q in [T,F]:
        left = not (p or q)
        right = (not p) and (not q)
        if left == right:
            print ("Dung")
        else:
            print ("Sai")
        
print ("Kiem tra Absorption laws")
# p and (p or q) == p
print ("p and (p or q) == p")
for p in [T,F]:
    for q in [T,F]:
        left = p or (p and q)
        right = p
        if left == right:
            print ("Dung")
        else:
            print ("Sai")

# p or (p and q) == p
print ("p or (p and q) == p")
for p in [T,F]:
    for q in [T,F]:
        left = p and (p or q)
        right = p
        if left == right:
            print ("Dung")
        else:
            print ("Sai")

print ("Kiem tra Negation laws")
# p and -p == T
print ("p and -p == T")
for p in [T,F]:
    for q in [T,F]:
        left = p or (not p)
        right = T
        if left == right:
            print ("Dung")
        else:
            print ("Sai")
# p or -p == F
print ("p or -p == F")
for p in [T,F]:
    for q in [T,F]:
        left = p and (not p)
        right = F
        if left == right:
            print ("Dung")
        else:
            print ("Sai")
