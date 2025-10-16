def modus_ponens(p, q, implication):
    return implication == (not p or q)

def modus_tollens(p, q, not_q):
    return (not_q and (not q)) and (not p)

def hypothetical_syllogism(p, q, r):
    return ((not p or q) and (not q or r)) and (not p or r)

def disjunctive_syllogism(p, q, not_p):
    return (p or q) and not_p and q

def addition(p, q):
    return p or q

def simplification(p, q):
    return p and q and p

def conjunction(p, q):
    return p and q

def resolution(p, q, not_p, r):
    return (p or q) and (not_p or r) and (q or r)

def test_table_7():
    print("Testing Table 7:")
    print("Modus Ponens:", modus_ponens(True, True, True))
    print("Modus Tollens:", modus_tollens(True, False, True))
    print("Hypothetical Syllogism:", hypothetical_syllogism(True, True, True))
    print("Disjunctive Syllogism:", disjunctive_syllogism(True, False, False))
    print("Addition:", addition(True, False))
    print("Simplification:", simplification(True, True))
    print("Conjunction:", conjunction(True, True))
    print("Resolution:", resolution(True, False, False, True))

test_table_7()