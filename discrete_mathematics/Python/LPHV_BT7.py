Python 3.13.7 (tags/v3.13.7:bcee1c3, Aug 14 2025, 14:15:11) [MSC v.1944 64 bit (AMD64)] on win32
Enter "help" below or click "Help" above for more information.
sat = False
for p in [0, 1]:
    for q in [0, 1]:
        expr = (p or (not q)) and ((not p) or q) and ((not p) or (not q))
        if expr:
            sat = True
            print(f"65a: satisfiable, p={p}, q={q}")
            break
    if sat:
        break

    
65a: satisfiable, p=0, q=0
if not sat:
    print("65a: unsatisfiable")

    
sat = False
for p in [0, 1]:
    for q in [0, 1]:
        expr = ((not p) or q) and ((not p) or (not q)) and (p or (not q))
        if expr:
            sat = True
            print(f"65b: satisfiable, p={p}, q={q}")
            break
    if sat:
        break

    
65b: satisfiable, p=0, q=0
if not sat:
    print("65b: unsatisfiable")

    
sat = False
for p in [0, 1]:
    for q in [0, 1]:
        expr = ((p == q) and ((not p) == (not q)))
        if expr:
            sat = True
            print(f"65c: satisfiable, p={p}, q={q}")
            break
    if sat:
        break

    
65c: satisfiable, p=0, q=0
if not sat:
    print("65c: unsatisfiable")

    
sat = False
for p in [0, 1]:
    for q in [0, 1]:
        for r in [0, 1]:
            for s in [0, 1]:
                expr = ((p or q or (not r)) and
                        (p or (not q) or (not s)) and
                        (p or (not r) or (not s)) and
                        ((not p) or (not q) or (not s)) and
                        (p or q or (not s)))
                if expr:
                    sat = True
                    print(f"66a: satisfiable, p={p}, q={q}, r={r}, s={s}")
                    break
            if sat: break
        if sat: break
    if sat: break

    
66a: satisfiable, p=0, q=0, r=0, s=0
if not sat:
    print("66a: unsatisfiable")

    
sat = False
for p in [0, 1]:
    for q in [0, 1]:
        for r in [0, 1]:
...             for s in [0, 1]:
...                 expr = ((not p or (not q) or r) and
...                         (not p or q or (not s)) and
...                         (p or q or r) and
...                         (p or q or (not s)) and
...                         (p or (not r) or (not s)))
...                 if expr:
...                     sat = True
...                     print(f"66b: satisfiable, p={p}, q={q}, r={r}, s={s}")
...                     break
...             if sat: break
...         if sat: break
...     if sat: break
... 
...     
66b: satisfiable, p=0, q=0, r=1, s=0
>>> if not sat:
...     print("66b: unsatisfiable")
... 
>>> 
>>> sat = False
>>> for p in [0, 1]:
...     for q in [0, 1]:
...         for r in [0, 1]:
...             for s in [0, 1]:
...                 expr = ((p or q or r) and
...                         (p or (not q) or (not s)) and
...                         (q or (not r) or s) and
...                         ((not p) or r or s) and
...                         ((not p) or (not q) or (not s)) and
...                         ((not p) or q or (not s)) and
...                         ((not p) or (not r) or (not s)))
...                 if expr:
...                     sat = True
...                     print(f"66c: satisfiable, p={p}, q={q}, r={r}, s={s}")
...                     break
...             if sat: break
...         if sat: break
...     if sat: break
... 
...     
66c: satisfiable, p=0, q=0, r=1, s=1
>>> if not sat:
...     print("66c: unsatisfiable")
... 
...     
