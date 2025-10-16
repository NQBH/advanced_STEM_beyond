import itertools

def implies(p, q):
    return (not p) or q

def iff(p, q):
    return (p and q) or ((not p) and (not q))

def satisfiable(expr, variables):
    for values in itertools.product([False, True], repeat=len(variables)):
        env = dict(zip(variables, values))
        if expr(**env):
            return True, env
    return False, None

# ======================
# Problem 65
# ======================
print("=== Problem 65 ===")

expr65 = {
    "a": lambda p, q: (p or (not q)) and ((not p) or q) and ((not p) or (not q)),
    "b": lambda p, q: (implies(p,q) and implies(p,not q)
                       and implies(not p,q) and implies(not p,not q)),
    "c": lambda p, q: iff(p,q) and (not iff(p,q))
}

for key, expr in expr65.items():
    sat, model = satisfiable(expr, ["p","q"])
    if sat:
        print(f"65{key}) satisfiable  →  {model}")
    else:
        print(f"65{key}) unsatisfiable")

# ======================
# Problem 66
# ======================
print("\n=== Problem 66 ===")

expr66 = {
    # 66a
    "a": lambda p, q, r, s: (p or q or (not r)) and (p or (not q) or (not s)) and \
                            (p or (not r) or (not s)) and ((not p) or (not q) or (not s)) and \
                            ((not p) or q or s),
    # 66b
    "b": lambda p, q, r, s: ((not p) or (not q) or r) and ((not p) or q or (not s)) and \
                            ((not p) or (not r) or s) and (p or q or (not r)) and \
                            (p or (not q) or (not s)),
    # 66c
    "c": lambda p, q, r, s: (p or q or r) and (p or (not q) or (not s)) and \
                            (q or (not r) or s) and ((not p) or r or s) and \
                            ((not p) or (not q) or s) and ((not p) or (not r) or (not s))
}

for key, expr in expr66.items():
    sat, model = satisfiable(expr, ["p","q","r","s"])
    if sat:
        print(f"66{key}) satisfiable  →  {model}")
    else:
        print(f"66{key}) unsatisfiable")