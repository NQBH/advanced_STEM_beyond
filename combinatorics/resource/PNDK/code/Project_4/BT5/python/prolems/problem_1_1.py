def complete_graph_edges(n):
    """Tính số cạnh của đồ thị đầy đủ Kn"""
    if n <= 1:
        return 0
    return n * (n - 1) // 2

def complete_bipartite_edges(p, q):
    """Tính số cạnh của đồ thị hai phía đầy đủ Kp,q"""
    return p * q

def main():

    print("Complete Graph Kn:")
    for n in [1, 2, 3, 4, 5]:
        edges = complete_graph_edges(n)
        print(f"K{n}: {edges} edges")
    
    print("\nComplete Bipartite Graph Kp,q:")
    test_cases = [(1,1), (2,2), (2,3), (3,4)]
    for p, q in test_cases:
        edges = complete_bipartite_edges(p, q)
        print(f"K{p},{q}: {edges} edges")

if __name__ == "__main__":
    main()