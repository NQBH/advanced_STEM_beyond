T = True
F = False
print ("Kiem tra Identity laws")
# p ∧ T ≡ p
print ("p ∧ T ≡ p")
for p in [T,F]:
    left = p and T
    right = p
    if left == right:
        print ("Dung")
    else: 
        print ("Sai")
# p ∨ F ≡ p
print ("p ∨ F ≡ p")
for p in [T,F]:
    left = p or F
    right = p
    if left == right:
        print ("Dung")
    else:
        print ("Sai")

print ("Kiem tra Domination laws")
# p ∨ T ≡ T   
print ("p ∨ T ≡ T")
for p in [T,F]:
    left = p or T
    right = T
    if left == right:
        print ("Dung")
    else:
        print ("Sai")
# p ∧ F ≡ F 
print ("p ∧ F ≡ F")
for p in [T,F]:
    left = p and F
    right = F
    if left == right:
        print ("Dung")
    else:
        print ("Sai")

print ("Kiem tra Idenpotent laws")
# p ∨ p ≡ p
print ("p ∨ p ≡ p")
for p in [T,F]:
    left = p or p
    right = p
    if left == right:
        print ("Dung")
    else:
        print ("Sai")
# p ∧ p ≡ p
print ("p ∧ p ≡ p")
for p in [T,F]:
    left = p and p
    right = p
    if left == right:
        print ("Dung")
    else:
        print ("Sai")

print ("Kiem tra Double negation law")
# ¬ (¬ p) ≡ p
print ("¬ (¬ p) ≡ p")
for p in [T,F]:
    left = not (not p)
    right = p
    if left == right:
        print ("Dung")
    else:
        print ("Sai")

print ("Kiem tra Commutative laws")
# p ∨ q ≡ q ∨ p
print ("p ∨ q ≡ q ∨ p")
for p in [T,F]:
    for q in [T,F]:
        left = p or q 
        right = q or p
        if left == right:
            print ("Dung")
        else:
            print ("Sai")
# p ∧ q ≡ q ∧ p
print ("p ∧ q ≡ q ∧ p")
for p in [T,F]:
    for q in [T,F]:
        left = p and q
        right = q and p
        if left == right:
            print ("Dung")
        else:
            print ("Sai")

print ("Kiem tra Associative laws")
# (p ∨ q) ∨ r ≡ p ∨ (q ∨ r)
print ("(p ∨ q) ∨ r ≡ p ∨ (q ∨ r) ")
for p in [T,F]:
    for q in [T,F]:
        for r in [T,F]:
            left = (p or q) or r
            right = p or (q or r)
            if left == right:
                print ("Dung")
            else:
                print ("Sai")
# (p ∧ q) ∧ r ≡ p ∧ (q ∧ r)
print ("(p ∧ q) ∧ r ≡ p ∧ (q ∧ r)")
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
# p ∨ (q ∧ r) ≡ (p ∨ q) ∧ (p ∨ r)
print ("p ∨ (q ∧ r) ≡ (p ∨ q) ∧ (p ∨ r)")
for p in [T,F]:
    for q in [T,F]:
        for r in [T,F]:
            left = p or (q and r)
            right = (p or q) and (p or r)
            if left == right:
                print ("Dung")
            else:
                print ("Sai")
# p ∧ (q ∨ r) ≡ (p ∧ q) ∨ (p ∧ r)
print ("p ∧ (q ∨ r) ≡ (p ∧ q) ∨ (p ∧ r)")
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
# ¬(p ∧ q) ≡ ¬p ∨ ¬q
print ("¬(p ∧ q) ≡ ¬p ∨ ¬q")
for p in [T,F]:
    for q in [T,F]:
        left = not (p and q)
        right = (not p) or (not q)
        if left == right:
            print ("Dung")
        else:
            print ("Sai")
# ¬(p ∨ q) ≡ ¬p ∧ ¬q
print ("¬(p ∨ q) ≡ ¬p ∧ ¬q")
for p in [T,F]:
    for q in [T,F]:
        left = not (p or q)
        right = (not p) and (not q)
        if left == right:
            print ("Dung")
        else:
            print ("Sai")
        
print ("Kiem tra Absorption laws")
# p ∨ (p ∧ q) ≡ p
print ("p ∨ (p ∧ q) ≡ p")
for p in [T,F]:
    for q in [T,F]:
        left = p or (p and q)
        right = p
        if left == right:
            print ("Dung")
        else:
            print ("Sai")

# p ∧ (p ∨ q) ≡ p
print ("p ∧ (p ∨ q) ≡ p")
for p in [T,F]:
    for q in [T,F]:
        left = p and (p or q)
        right = p
        if left == right:
            print ("Dung")
        else:
            print ("Sai")

print ("Kiem tra Negation laws")
# p ∨ ¬p ≡ T
print ("p ∨ ¬p ≡ T")
for p in [T,F]:
    for q in [T,F]:
        left = p or (not p)
        right = T
        if left == right:
            print ("Dung")
        else:
            print ("Sai")
# p ∧ ¬p ≡ F
print ("p ∧ ¬p ≡ F")
for p in [T,F]:
    for q in [T,F]:
        left = p and (not p)
        right = F
        if left == right:
            print ("Dung")
        else:
            print ("Sai")