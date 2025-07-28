def previous_sibling(parent, v):
    p = parent[v]
    result = -1
    for u in range(1, v):  
        if parent[u] == p:
            result = u
    return result

parent = [-1, -1, 1, 1, 2, 2, 3]  

for v in range(1, 7):
    print(f"previous_sibling({v}) = {previous_sibling(parent, v)}")