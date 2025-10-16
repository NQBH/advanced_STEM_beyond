import itertools

# Định nghĩa các phép logic cơ bản
def implies(p, q):
    return (not p) or q

def iff(p, q):
    return (p and q) or ((not p) and (not q))

# Tạo bảng chân trị
def truth_table(expr, variables):
    table = []
    for values in itertools.product([False, True], repeat=len(variables)):
        env = dict(zip(variables, values))
        table.append(expr(**env))
    return table

def equivalent(expr1, expr2, variables):
    return truth_table(expr1, variables) == truth_table(expr2, variables)

# ===== Table 7 =====
table7 = [
    # p → q ≡ ¬p ∨ q
    (lambda p, q: implies(p, q), lambda p, q: (not p) or q, ["p", "q"]),
    # p → q ≡ ¬q → ¬p
    (lambda p, q: implies(p, q), lambda p, q: implies(not q, not p), ["p", "q"]),
    # p ∨ q ≡ ¬p → q
    (lambda p, q: p or q, lambda p, q: implies(not p, q), ["p", "q"]),
    # p ∧ q ≡ ¬(p → ¬q)
    (lambda p, q: p and q, lambda p, q: not implies(p, not q), ["p", "q"]),
    # ¬(p → q) ≡ p ∧ ¬q
    (lambda p, q: not implies(p, q), lambda p, q: p and (not q), ["p", "q"]),
    # (p → q) ∧ (p → r) ≡ p → (q ∧ r)
    (lambda p, q, r: implies(p, q) and implies(p, r),
     lambda p, q, r: implies(p, q and r), ["p", "q", "r"]),
    # (p → r) ∧ (q → r) ≡ (p ∨ q) → r
    (lambda p, q, r: implies(p, r) and implies(q, r),
     lambda p, q, r: implies(p or q, r), ["p", "q", "r"]),
    # (p → q) ∨ (p → r) ≡ p → (q ∨ r)
    (lambda p, q, r: implies(p, q) or implies(p, r),
     lambda p, q, r: implies(p, q or r), ["p", "q", "r"]),
    # (p → r) ∨ (q → r) ≡ (p ∧ q) → r
    (lambda p, q, r: implies(p, r) or implies(q, r),
     lambda p, q, r: implies(p and q, r), ["p", "q", "r"]),
]

# ===== Table 8 =====
table8 = [
    # p ↔ q ≡ (p → q) ∧ (q → p)
    (lambda p, q: iff(p, q), lambda p, q: implies(p, q) and implies(q, p), ["p", "q"]),
    # p ↔ q ≡ ¬p ↔ ¬q
    (lambda p, q: iff(p, q), lambda p, q: iff(not p, not q), ["p", "q"]),
    # p ↔ q ≡ (p ∧ q) ∨ (¬p ∧ ¬q)
    (lambda p, q: iff(p, q), lambda p, q: (p and q) or ((not p) and (not q)), ["p", "q"]),
    # ¬(p ↔ q) ≡ p ↔ ¬q
    (lambda p, q: not iff(p, q), lambda p, q: iff(p, not q), ["p", "q"]),
]

print("=== TABLE 7 ===")
for i, (e1, e2, vars_) in enumerate(table7, 1):
    print(f"Rule 7.{i}: {equivalent(e1, e2, vars_)}")

print("\n=== TABLE 8 ===")
for i, (e1, e2, vars_) in enumerate(table8, 1):
    print(f"Rule 8.{i}: {equivalent(e1, e2, vars_)}")