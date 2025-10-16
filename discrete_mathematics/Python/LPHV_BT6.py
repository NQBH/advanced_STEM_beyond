Python 3.13.7 (tags/v3.13.7:bcee1c3, Aug 14 2025, 14:15:11) [MSC v.1944 64 bit (AMD64)] on win32
Enter "help" below or click "Help" above for more information.
def implies(p,q):
    return (not  p) or q

def iff(p,q):
    return (p and q) or ((not p) and (not q))

values=[False,True]
for p in values:
    for q in values:
        for r in values:
            print(f"p={p},q={q},r={r}")
            print("1: ", implies(p,q)==((not p) or q))
            print("2: ", implies(p,q)==implies(not q, not p))
            print("3: ",(p or q)==implies(not p, q))
            print("4: ",(p and q)==(not implies(p, not q)))
            print("5: ",(not implies(p,q))==(p and(not q)))
            print("6: ",(implies(p,q) and implies(p,r))==implies(p, (p and r)))
            print("7: ",(implies(p,r) and implies(q, r))==implies((p or q),r))
            print("8: ",(implies(p,q) and implies(q,r))==implies(p,r))
            print("9: ",(implies(p,r) or implies(q,r))==implies((p and q),r))
            print("-"*60)

            
p=False,q=False,r=False
1:  True
2:  True
3:  True
4:  True
5:  True
6:  True
7:  True
8:  True
9:  True
------------------------------------------------------------
p=False,q=False,r=True
1:  True
2:  True
3:  True
4:  True
5:  True
6:  True
7:  True
8:  True
9:  True
------------------------------------------------------------
p=False,q=True,r=False
1:  True
2:  True
3:  True
4:  True
5:  True
6:  True
7:  True
8:  False
9:  True
------------------------------------------------------------
p=False,q=True,r=True
1:  True
2:  True
3:  True
4:  True
5:  True
6:  True
7:  True
8:  True
9:  True
------------------------------------------------------------
p=True,q=False,r=False
1:  True
2:  True
3:  True
4:  True
5:  True
6:  True
7:  True
8:  True
9:  True
------------------------------------------------------------
p=True,q=False,r=True
1:  True
2:  True
3:  True
4:  True
5:  True
6:  False
7:  True
8:  False
9:  True
------------------------------------------------------------
p=True,q=True,r=False
1:  True
2:  True
3:  True
4:  True
5:  True
6:  True
7:  True
8:  True
9:  True
------------------------------------------------------------
p=True,q=True,r=True
1:  True
2:  True
3:  True
4:  True
5:  True
6:  True
7:  True
8:  True
9:  True
------------------------------------------------------------
>>> for p in values:
...     for q in values:
...         print("1: ", iff(p,q)==(implies(p,q) and implies(q,p)))
...         print("2: ", iff(p,q)==iff(not p, not q))
...         print("3: ", iff(p,q)==((p and q) or ((not p) and (not q))))
...         print("4: ", (not iff(p,q))==iff(p,not q))
...         print("-"*60)
... 
...         
1:  True
2:  True
3:  True
4:  True
------------------------------------------------------------
1:  True
2:  True
3:  True
4:  True
------------------------------------------------------------
1:  True
2:  True
3:  True
4:  True
------------------------------------------------------------
1:  True
2:  True
3:  True
4:  True
------------------------------------------------------------
