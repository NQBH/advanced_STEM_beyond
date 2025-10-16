def implies(a: bool, b: bool) -> bool:
    return (not a) or b

def equiv(a: bool, b: bool) -> bool:
    return a == b

def biconditional(a: bool, b: bool) -> bool:
    return a == b

def main():
    ok = True

    # p <=> q equiv (p => q) ∧ (q => p)
    ok = True
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        left = biconditional(p, q)
        right = implies(p, q) and implies(q, p)
        if not equiv(left, right):
            ok = False
    print("p <=> q equiv (p => q) ^ (q => p):", "True" if ok else "False")

    # p <=> q equiv !p <=> !q
    ok = True
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        left = biconditional(p, q)
        right = biconditional(not p, not q)
        if not equiv(left, right):
            ok = False
    print("p <=> q equiv !p <=> !q:", "True" if ok else "False")

    # p <=> q equiv (p ∧ q) ∨ (!p ∧ !q)
    ok = True
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        left = biconditional(p, q)
        right = (p and q) or ((not p) and (not q))
        if not equiv(left, right):
            ok = False
    print("p <=> q equiv (p ^ q) V (!p ^ !q):", "True" if ok else "False")

    # !(p <=> q) equiv p <=> !q
    ok = True
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        left = not biconditional(p, q)
        right = biconditional(p, not q)
        if not equiv(left, right):
            ok = False
    print("!(p <=> q) equiv p <=> !q:", "True" if ok else "False")


if __name__ == "__main__":
    main()