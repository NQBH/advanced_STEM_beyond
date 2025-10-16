print ("bai 65")
# Cau a): (p V not q) AND (not p V q) AND (not p V not q)
print("Caua):")
satisfiable_a = False
for p in [True, False]:
    for q in [True, False]:
        if (p or not q) and (not p or q) and (not p or not q):
            print(f"  Satisfiable. gia tri thoa man: p={p}, q={q}")
            satisfiable_a = True
            break  # thoat vong lap q
    if satisfiable_a:
        break  # thoat vong lap p
if not satisfiable_a:
    print("  Unsatisfiable.")
# caub): (p -> q) AND (p -> not q) AND (not p -> q) AND (not p -> not q)
print("\n kiem tra b):")
satisfiable_b = False
for p in [True, False]:
    for q in [True, False]:
        if ((not p or q) and (not p or not q) and (p or q) and (p or not q)):
            print(f"  Satisfiable. mot so gia tri thoa man: p={p}, q={q}")
            satisfiable_b = True
            break
    if satisfiable_b:
        break
if not satisfiable_b:
    print("  Unsatisfiable.")
# cauc): (p <-> q) AND (not p <-> q)
print("\n kiem tra c):")
satisfiable_c = False
for p in [True, False]:
    for q in [True, False]:
        if (p == q) and ((not p) == q):
            print(f"  Satisfiable. mot so gia tri thoa man: p={p}, q={q}")
            satisfiable_c = True
            break
    if satisfiable_c:
        break
if not satisfiable_c:
    print("  Unsatisfiable.")

    print ("bai 66")

 #cau a): (p or q or not r) and (p or not q or not s) and (p or not r or not s) and (not p or not q or not s) and (p or q or not s)  
satisfiable_a = False
for p in [True,False]:
    for q in [True,False]:
        for r in [True,False]:
            for s in [True,False]:
                if (p or q or not r) and (p or not q or not s) and (p or not r or not s) and (not p or not q or not s) and (p or q or not s):
                    print(f" cau a: Satisfiable. mot so gia tri thoa man: p={p}, q={q}, r={r}, s={s}")
                    satisfiable_a = True
                    break
            if satisfiable_a:
                break
        if satisfiable_a:
            break
    if satisfiable_a:
        break    
if not satisfiable_a:
    print(" Unsatisfiable")

#cau b): (not p or not q or r) and (not p or q or not s) and (p or not q or not s) and (not p or not r or not s) and (p or q or not r) and (p or not r or not s)
satisfiable_b = False
for p in [True,False]:
    for q in [True,False]:
        for r in [True,False]:
            for s in [True,False]:
                if (not p or not q or r) and (not p or q or not s) and (p or not q or not s) and (not p or not r or not s) and (p or q or not r) and (p or not r or not s):
                    print(f" cau b: Satisfiable. mot so gia tri thoa man: p={p}, q={q}, r={r}, s={s}")
                    satisfiable_b = True
                    break
            if satisfiable_b:
                break
        if satisfiable_b:
            break
    if satisfiable_b:
        break    
if not satisfiable_b:
    print(" Unsatisfiable")

#cau c): (p or q or r) and (p or not q or not s) and (p or not r or s) and (not p or r or s) and (not p or q or not s) and (p or not q or not r) and (not p or not q or s) and (not p or not r or not s)
satisfiable_c = False
for p in [True,False]:
    for q in [True,False]:
        for r in [True,False]:
            for s in [True,False]:
                if (p or q or r) and (p or not q or not s) and (p or not r or s) and (not p or r or s) and (not p or q or not s) and (p or not q or not r) and (not p or not q or s) and (not p or not r or not s):
                    print(f" cau c: Satisfiable. mot so gia tri thoa man: p={p}, q={q}, r={r}, s={s}")
                    satisfiable_c = True
                    break
            if satisfiable_c:
                break
        if satisfiable_c:
            break
    if satisfiable_c:
        break    
if not satisfiable_c:
    print(" Unsatisfiable")
