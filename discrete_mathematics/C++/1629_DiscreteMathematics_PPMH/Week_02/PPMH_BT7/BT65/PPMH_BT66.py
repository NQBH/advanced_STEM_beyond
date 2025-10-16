def implies(a, b):
    return (not a) or b

def biconditional(a, b):
    return a == b

def main():
    # a
    sat = False
    print("(p V !q) ^ (!p V q) ^ (!p V !q)")
    for i in range(4):
        p = bool(i // 2)
        q = bool(i % 2)
        value = ((p or not q) and (not p or q) and (not p or not q))
        if value:
            print(f"Satisfiable for p = {int(p)}, q = {int(q)}")
            sat = True
            break
    if not sat:
        print("Not satisfiable")

    # b
    sat = False
    print("\np => q) ^ (p => !q) ^ (!p => q) ^ (!p => !q)")
    for i in range(4):
        p = bool(i//2)
        q = bool(i % 2)
        value = (implies(p, q) and implies(p, not q) and 
                 implies(not p, q) and implies(not p, not q))
        if value:
            print(  f"Satisfiable for p = {int(p)}, q = {int(q)}")
            sat = True
            break
    if not sat:
        print("Not satisfiable")

    # c
    sat = False
    print("\n(p <=> q) ^ (!p <=> q)")
    for i in range(4):
        p = bool(i // 2)
        q = bool(i%2)
        value = (biconditional(p, q) and biconditional(not p, q))
        if value:
            print(f"Satisfiable for p = {int(p)}, q = {int(q)}")
            sat = True
            break
    if not sat:
        print("Not satisfiable")

if __name__ == "__main__":
    main()