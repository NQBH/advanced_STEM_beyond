import itertools
def check_equivalence(expr1, expr2, variables):
    for values in itertools.product([False, True], repeat=len(variables)):
        env = dict(zip(variables, values))
        if eval(expr1, env) != eval(expr2, env):
            return False, env
    return True, None
rules = [
    ("p and True", "p", ["p"]),
    ("p or False", "p", ["p"]),

    ("p or True", "True", ["p"]),
    ("p and False", "False", ["p"]),

    ("p or p", "p", ["p"]),
    ("p and p", "p", ["p"]),

    ("not (not p)", "p", ["p"]),

    ("p or q", "q or p", ["p", "q"]),
    ("p and q", "q and p", ["p", "q"]),

    ("(p or q) or r", "p or (q or r)", ["p", "q", "r"]),
    ("(p and q) and r", "p and (q and r)", ["p", "q", "r"]),

    ("p or (q and r)", "(p or q) and (p or r)", ["p", "q", "r"]),
    ("p and (q or r)", "(p and q) or (p and r)", ["p", "q", "r"]),

    ("not (p and q)", "not p or not q", ["p", "q"]),
    ("not (p or q)", "not p and not q", ["p", "q"]),

    ("p or (p and q)", "p", ["p", "q"]),
    ("p and (p or q)", "p", ["p", "q"]),

    ("p or not p", "True", ["p"]),
    ("p and not p", "False", ["p"])
]
for expr1, expr2, vars in rules:
    dung, fail_case = check_equivalence(expr1, expr2, vars)
    if dung:
        print(f"{expr1} == {expr2} : Đúng với mọi giá trị của {vars}")
    else:
        print(f"{expr1} == {expr2} : Sai tại {fail_case}")