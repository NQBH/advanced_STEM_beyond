def count_spanning_trees_complete(n):
    """Số cây khung của Kn sử dụng công thức Cayley: n^(n-2)"""
    if n <= 1:
        return 1
    result = 1
    for i in range(n - 2):
        result *= n
    return result

def manual_spanning_trees_example():
    """Ví dụ thủ công cho đồ thị tam giác"""
    print("Graph: Triangle (3 vertices, 3 edges)")
    print("Spanning trees:")
    print("1. Edges: (0,1) and (0,2)")
    print("2. Edges: (0,1) and (1,2)")
    print("3. Edges: (0,2) and (1,2)")
    print("Total: 3 spanning trees")

def main():
    manual_spanning_trees_example()
    
    print("\nComplete Graphs - Number of Spanning Trees:")
    for n in range(1, 6):
        count = count_spanning_trees_complete(n)
        print(f"K{n}: {count} spanning trees")

if __name__ == "__main__":
    main()