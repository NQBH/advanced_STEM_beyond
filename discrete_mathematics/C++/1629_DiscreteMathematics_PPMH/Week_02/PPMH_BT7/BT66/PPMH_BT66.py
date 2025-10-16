def implies(a, b):
    return (not a) or b

def biconditional(a, b):
    return a == b;

def main():
    # a
    print("a")
    sat = False
    for i in range(16):
        p = (i // 8) % 2 == 1
        q = (i // 4) % 2 == 1
        r = (i // 2) % 2 == 1
        s = i % 2 == 1

        value = ((p or q or not r)
            and (p or not q or not s)
            and (p or not r or not s)
            and (not p or not q or s)
            and (p or q or not s))
        
        if value:
            print(f"Satisfiable for p={int(p)}, q={int(q)}, r={int(r)}, s={int(s)}")
            sat = True
            break

    if not sat:
        print("Not satisfiable")

    # b
    print("b")
    sat = False
    for i in range(16):
        p = (i // 8) % 2 == 1
        q = (i // 4) % 2 == 1
        r = (i // 2) % 2 == 1
        s = i % 2 == 1

        value = ((not p or not q or r)
            and (not p or q or not s)
            and (p or not q or not s)
            and (not p or not r or not s)
            and (p or q or not r)
            and (p or not r or not s))

        if value:
                print(f"Satisfiable for p={int(p)}, q={int(q)}, r={int(r)}, s={int(s)}")
                sat = True
                break

    if not sat:
        print("Not satisfiable")

    # c
    print("c")
    sat = False
    for i in range(16):
        p = (i // 8) % 2 == 1
        q = (i // 4) % 2 == 1
        r = (i // 2) % 2 == 1
        s = i % 2 == 1

        value = ((p or q or r)
          and (p or not q or not s)
          and (q or not r or s)
          and (not p or r or s)
          and (not p or q or not s)
          and (p or not q or not r)
          and (not p or not q or s)
          and (not p or not r or not s))
        
        if value:
                print(f"Satisfiable for p={int(p)}, q={int(q)}, r={int(r)}, s={int(s)}")
                sat = True
                break
    if not sat:
        print("Not satisfiable")

if __name__ == "__main__":
    main()