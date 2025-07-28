def is_bipartite_Cn(n):
    # n: so dinh cua do thi Cn
    # Tra ve True neu n chan (Cn luong phan)
    return n % 2 == 0

def is_bipartite_Kn(n):
    # n: so dinh cua do thi Kn
    # Tra ve True neu n <= 2 (Kn luong phan)
    return n <= 2

# Vi du su dung
if __name__ == "__main__":
    print("Is C_4 bipartite?", is_bipartite_Cn(4))  # True
    print("Is K_3 bipartite?", is_bipartite_Kn(3))  # False