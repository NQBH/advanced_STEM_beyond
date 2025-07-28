def read_dimacs(file_path):
    with open(file_path, 'r') as f:
        lines = f.readlines()
    
    n, m = 0, 0
    edges = []
    
    for line in lines:
        if line.startswith('c'):
            continue  # skip comment
        elif line.startswith('p'):
            _, _, n, m = line.strip().split()
            n, m = int(n), int(m)
        elif line.startswith('e'):
            _, u, v = line.strip().split()
            u, v = int(u), int(v)
            edges.append((u, v))
    
    return n, m, edges


def write_dimacs(n, edges, file_path):
    with open(file_path, 'w') as f:
        f.write(f"p edge {n} {len(edges)}\n")
        for u, v in edges:
            f.write(f"e {u} {v}\n")
