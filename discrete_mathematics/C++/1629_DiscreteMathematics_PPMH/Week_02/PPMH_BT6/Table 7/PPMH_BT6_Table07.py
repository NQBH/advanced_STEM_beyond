def implies(a, b):
    return (not a) or b

def equiv(a,b):
    return a == b

def main():
    # Quy tac 1:
    ok = True
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        left = implies(p, q)
        right = (not p) or q
        if not equiv(left, right):
            ok = False
    print("p => q equiv !p V q:", ok)

    # Quy tac 2:
    ok = True
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        left = implies(p, q)
        right = implies(not q, not p)
        if not equiv(left, right):
            ok = False
    print("p => q equiv !q => !p:", ok)

    # Quy tac 3:
    ok = True
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        left = implies(p, q)
        right = implies (not p, q)
        if not equiv(left, right):
            ok = False
    print("p => q equiv !p => q:", ok)

    # Quy tac 4:
    ok = True
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        left = p and q
        right = not implies(p, not q)
        if not equiv(left, right):
            ok = False
    print("p ^ q equiv !(p => !q):", ok)

    # Quy tac 5:
    ok = True
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        left = not implies(p, q)
        right = p and (not q)
        if not equiv(left, right):
            ok = False
    print("!(p => q) equiv p ^ !q:", ok)

    # Quy tac 6:
    ok = True
    for i in range(8):
        p = bool((i >> 2) & 1)
        q = bool((i >> 1) & 1)
        r = bool(i & 1)
        left = implies(p, q) and implies(q, r)
        right = implies(p, q and r)
        if not equiv(left, right):
            ok = False
    print("(p => q) ^ (q => r) equiv p => (q ^ r):", ok)

    # Quy tac 7:
    ok = True
    for i in range(8):
        p = bool((i >> 2) & 1)
        q = bool((i >> 1) & 1)
        r = bool(i & 1)
        left = implies(p, r) or implies(q, r)
        right = implies(p or q, r)
        if not equiv(left, right):
            ok = False
    print("(p => r) V (q => r) equiv (p V q) => r:", ok)

    # Quy tac 8:
    ok = True
    for i in range(8):
        p = bool((i >> 2) & 1)
        q = bool((i >> 1) & 1)
        r = bool(i & 1)
        left = implies(p, q) or implies(p, r)
        right = implies(p, q or r)
        if not equiv(left, right):
            ok = False
    print("(p => q) V (p => r) equiv p => (q V r):", ok)

    # Quy tac 9:
    ok = True
    for i in range(8):
        p = bool((i >> 2) & 1)
        q = bool((i >> 1) & 1)
        r = bool(i & 1)
        left = implies(p and q, r)
        right = implies(p, implies(q, r))
        if not equiv(left, right):
            ok = False
    print("(p ^ q) => r equiv p => (q => r):", ok)

if __name__ == "__main__":
    main()