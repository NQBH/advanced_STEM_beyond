Python 3.13.7 (tags/v3.13.7:bcee1c3, Aug 14 2025, 14:15:11) [MSC v.1944 64 bit (AMD64)] on win32
Enter "help" below or click "Help" above for more information.
def implies(p,q):
    return (not p) or q
... 
>>> values=[False,True]
>>> for p in values:
...     for q in values:
...         for r in values:
...             print("p= ",p, "q= ",q, "r= ", r)
...             print(" Identity: ",(p and True)==p,(p or False)==p)
...             print(" Domination laws: ", (p or True)==True, (p and False)==False)
...             print(" Idempotent laws: ",(p or p)==p, (p and p)==p)
...             print(" Double negation: ", (not (not p))==p)
...             print(" Commutative: ", (p or q)==(q or p), (p and q)==(q and p))
...             print(" Associative: ", ((p or q) or r)==(p or (q or r)), ((p and q) and r)==(p and (q and r)))
...             print(" Distributive: ", (p or (q and r))==((p or q) and (p or r)), (p and (q or r))==((p and q) or (q and r)))
...             print(" De Morgan: ", (not (p and q))==((not p)or(not q)), (not(p or q))==((not p) and (not q)))
...             print(" Absorption: ", (p or (p and q))==p, (p and (p or q))==p)
...             print(" Negation: ",(p or (not p))==True,(p or (not p))==False)
...             print("-"*40)
... 
...             
p=  False q=  False r=  False
 Identity:  True True
 Domination laws:  True True
 Idempotent laws:  True True
 Double negation:  True
 Commutative:  True True
 Associative:  True True
 Distributive:  True True
 De Morgan:  True True
 Absorption:  True True
 Negation:  True False
----------------------------------------
p=  False q=  False r=  True
 Identity:  True True
 Domination laws:  True True
 Idempotent laws:  True True
 Double negation:  True
 Commutative:  True True
 Associative:  True True
 Distributive:  True True
 De Morgan:  True True
 Absorption:  True True
 Negation:  True False
----------------------------------------
p=  False q=  True r=  False
 Identity:  True True
 Domination laws:  True True
 Idempotent laws:  True True
 Double negation:  True
 Commutative:  True True
 Associative:  True True
 Distributive:  True True
 De Morgan:  True True
 Absorption:  True True
 Negation:  True False
----------------------------------------
p=  False q=  True r=  True
 Identity:  True True
 Domination laws:  True True
 Idempotent laws:  True True
 Double negation:  True
 Commutative:  True True
 Associative:  True True
 Distributive:  True False
 De Morgan:  True True
 Absorption:  True True
 Negation:  True False
----------------------------------------
p=  True q=  False r=  False
 Identity:  True True
 Domination laws:  True True
 Idempotent laws:  True True
 Double negation:  True
 Commutative:  True True
 Associative:  True True
 Distributive:  True True
 De Morgan:  True True
 Absorption:  True True
 Negation:  True False
----------------------------------------
p=  True q=  False r=  True
 Identity:  True True
 Domination laws:  True True
 Idempotent laws:  True True
 Double negation:  True
 Commutative:  True True
 Associative:  True True
 Distributive:  True False
 De Morgan:  True True
 Absorption:  True True
 Negation:  True False
----------------------------------------
p=  True q=  True r=  False
 Identity:  True True
 Domination laws:  True True
 Idempotent laws:  True True
 Double negation:  True
 Commutative:  True True
 Associative:  True True
 Distributive:  True True
 De Morgan:  True True
 Absorption:  True True
 Negation:  True False
----------------------------------------
p=  True q=  True r=  True
 Identity:  True True
 Domination laws:  True True
 Idempotent laws:  True True
 Double negation:  True
 Commutative:  True True
 Associative:  True True
 Distributive:  True True
 De Morgan:  True True
 Absorption:  True True
 Negation:  True False
----------------------------------------
