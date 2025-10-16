import itertools

def truth_table(expr, variables):
    table = []
    for values in itertools.product([False, True], repeat=len(variables)):
        env = dict(zip(variables, values))
        table.append(eval(expr, {}, env))
    return table

def equivalent(expr1, expr2, variables):
    return truth_table(expr1, variables) == truth_table(expr2, variables)

tests = [
    # Identity laws
    ("p and True", "p", ["p"]),
    ("p or False", "p", ["p"]),

    # Domination laws
    ("p or True", "True", ["p"]),
    ("p and False", "False", ["p"]),

    # Idempotent laws
    ("p or p", "p", ["p"]),
    ("p and p", "p", ["p"]),

    # Double negation law
    ("not (not p)", "p", ["p"]),

    # Commutative laws
    ("p or q", "q or p", ["p", "q"]),
    ("p and q", "q and p", ["p", "q"]),

    # Associative laws
    ("(p or q) or r", "p or (q or r)", ["p", "q", "r"]),
    ("(p and q) and r", "p and (q and r)", ["p", "q", "r"]),

    # Distributive laws
    ("p or (q and r)", "(p or q) and (p or r)", ["p", "q", "r"]),
    ("p and (q or r)", "(p and q) or (p and r)", ["p", "q", "r"]),

    # De Morgan’s laws
    ("not (p and q)", "(not p) or (not q)", ["p", "q"]),
    ("not (p or q)", "(not p) and (not q)", ["p", "q"]),

    # Absorption laws
    ("p or (p and q)", "p", ["p", "q"]),
    ("p and (p or q)", "p", ["p", "q"]),

    # Negation laws
    ("p or (not p)", "True", ["p"]),
    ("p and (not p)", "False", ["p"])
]

for i, (e1, e2, vars_) in enumerate(tests, 1):
    result = equivalent(e1, e2, vars_)
    print(f"Rule {i:02}: {e1} ≡ {e2} → {result}")