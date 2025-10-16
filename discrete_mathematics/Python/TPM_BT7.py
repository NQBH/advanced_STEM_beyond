# Bài 65
print("Bài 65:")

# 65a
print("a:")
for p in [False, True]:
    for q in [False, True]:
        if (p or not q) and (not p or q) and (not p or not q):
            print("satisfiable")
            print("p =", p, "q =", q)
            break
    else:
        continue
    break
else:
    print("unsatisfiable")

# 65b
print("b:")
for p in [False, True]:
    for q in [False, True]:
        if ((not p or q) and (not p or not q) and (p or q) and (p or not q)):
            print("satisfiable")
            print("p =", p, "q =", q)
            break
    else:
        continue
    break
else:
    print("unsatisfiable")

# 65c
print("c:")
for p in [False, True]:
    for q in [False, True]:
        if ((p == q) and ((not p) == q)):
            print("satisfiable")
            print("p =", p, "q =", q)
            break
    else:
        continue
    break
else:
    print("unsatisfiable")

# Bài 66
print("Bài 66:")

# 66a
print("a:")
for p in [False, True]:
    for q in [False, True]:
        for r in [False, True]:
            for s in [False, True]:
                if ((p or q or (not r)) and (p or (not q) or (not s)) and (p or (not r) or (not s)) and ((not p) or (not q) or (not s)) and (p or q or  (not s))):
                    print("satisfiable")
                    print("p =", p, "q =", q, "r =", r, "s =", s)
                    break
            else:
                continue
            break
        else:
            continue
        break
    else:
        continue
    break
else:
    print("unsatisfiable")

# 66b
print("b:")
for p in [False, True]:
    for q in [False, True]:
        for r in [False, True]:
            for s in [False, True]:
                if ((not p or not q or r) and (not p or q or not s) and (p or not q or not s) and (not p or not r or not s) and (p or q or not r) and (p or not r or not s)):
                    print("satisfiable")
                    print("p =", p, "q =", q, "r =", r, "s =", s)
                    break
            else:
                continue
            break
        else:
            continue
        break
    else:
        continue
    break
else:
    print("unsatisfiable")

# 66c
print("c:")
for p in [False, True]:
    for q in [False, True]:
        for r in [False, True]:
            for s in [False, True]:
                if ((p or q or r) and (p or not q or not s) and (q or not r or s) and (not p or r or s) and (not p or not q or not s) and (p or not q or not r) and (not p or not q or s) and (not p or not r or not s)):
                    print("satisfiable")
                    print("p =", p, "q =", q, "r =", r, "s =", s)
                    break
            else:
                continue
            break
        else:
            continue
        break
    else:
        continue
    break
else:
    print("unsatisfiable")