from itertools import product

def is_satisfiable_65():
    print("Bài 65:")
    for p, q, r in product([True, False], repeat=3):
        prop = (p or not q) and (q or not r) and (r or not p)
        if prop:
            print("satisfiable")
            print(f"p = {p}, q = {q}, r = {r}")
            return
    print("unsatisfiable")

def is_satisfiable_66():
    print("\nBài 66:")
    for p, q in product([True, False], repeat=2):
        prop = (p or q) and (not p or q) and (p or not q) and (not p or not q)
        if prop:
            print("satisfiable")
            print(f"p = {p}, q = {q}")
            return
    print("unsatisfiable")

is_satisfiable_65()
is_satisfiable_66()