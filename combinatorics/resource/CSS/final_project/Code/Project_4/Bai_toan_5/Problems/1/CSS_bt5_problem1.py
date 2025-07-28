def size_of_Kn(n):
    # n: so dinh cua do thi Kn
    # Tra ve so canh = n * (n-1) / 2
    return n * (n - 1) // 2

def size_of_Kpq(p, q):
    # p, q: so dinh trong hai tap cua Kp,q
    # Tra ve so canh = p * q
    return p * q

# Vi du su dung
if __name__ == "__main__":
    print("Size of K_5:", size_of_Kn(5))      # 10
    print("Size of K_3,4:", size_of_Kpq(3, 4))  # 12