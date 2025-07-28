def is_cycle_bipartite(n):
    """Kiểm tra Cn có hai phía không"""
    return n % 2 == 0

def is_complete_bipartite(n):
    """Kiểm tra Kn có hai phía không"""
    return n <= 2

def main():
    print("Cycle Graph Cn - Bipartite:")
    for n in range(1, 8):
        bipartite = is_cycle_bipartite(n)
        print(f"C{n}: {'Yes' if bipartite else 'No'}")
    
    print("\nComplete Graph Kn - Bipartite:")
    for n in range(1, 6):
        bipartite = is_complete_bipartite(n)
        print(f"K{n}: {'Yes' if bipartite else 'No'}")

if __name__ == "__main__":
    main()