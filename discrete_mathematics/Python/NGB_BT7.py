print("Cau 65a")
found_solution = False
for p in [True, False]:
    for q in [True, False]:
        part1 = p or not q
        part2 = not p or q
        part3 = not p or not q
        if part1 and part2 and part3:
            print("satisfiable")
            print("p =",p,"q =",q)
            found_solution = True
            break
    if found_solution:
        break

if not found_solution:
    print("unsatisfiable")

print()

print("Cau 65b")
found_solution = False
for p in [True, False]:
    for q in [True, False]:
        part1 = (not p) or q
        part2 = (not p) or not q
        part3 = p or q
        part4 = p or not q
        if part1 and part2 and part3 and part4:
            print("satisfiable")
            print("p =",p,"q =",q)
            found_solution = True
            break
    if found_solution:
        break

if not found_solution:
    print("unsatisfiable")

print ()

print ("Cau 65c")
found_solution = False
for p in [True, False]:
    for q in [True, False]:
        part1 = (p and q) or (not p and not q) 
        part2 = (not p and q) or (p and not q)  
        if part1 and part2:
            print("satisfiable")
            print("p =",p,"q =",q)
            found_solution = True
            break
    if found_solution:
        break

if not found_solution:
    print("unsatisfiable")