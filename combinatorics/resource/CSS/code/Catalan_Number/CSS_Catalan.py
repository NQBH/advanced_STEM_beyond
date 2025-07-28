import math

MAX_ULL = 2**64 - 1

def factorial(n):
    """Tính giai thừa n!"""
    return math.factorial(n)

def permutation(n, k):
    """Tính A_n^k = n! / (n-k)!"""
    if k > n:
        return 0
    return math.factorial(n) // math.factorial(n - k)

def combination(n, k):
    """Tính C_n^k = n! / (k! * (n-k)!)"""
    if k > n:
        return 0
    return math.comb(n, k)

def catalan(n):
    """Tính số Catalan thứ n: C_n = (1/(n+1)) * C(2n, n)"""
    return combination(2 * n, n) // (n + 1)

def find_overflow():
    """Tìm giá trị n khi các hàm trên gây overflow so với MAX_ULL"""
    overflow_points = {'P_n': None, 'A_n^k': None, 'C_n^k': None, 'Catalan': None}
    
    for n in range(1, 100):
        result = factorial(n)
        if result > MAX_ULL:
            overflow_points['P_n'] = n
            break
    
    for n in range(1, 100):
        k = n // 2
        result = permutation(n, k)
        if result > MAX_ULL:
            overflow_points['A_n^k'] = n
            break
    
    for n in range(1, 100):
        k = n // 2
        result = combination(n, k)
        if result > MAX_ULL:
            overflow_points['C_n^k'] = n
            break
    
    for n in range(1, 100):
        result = catalan(n)
        if result > MAX_ULL:
            overflow_points['Catalan'] = n
            break
    
    return overflow_points

if __name__ == "__main__":
    print("Tính toán và kiểm tra overflow:")
    overflow = find_overflow()
    print(f"P_n = n! gây overflow tại n = {overflow['P_n']}")
    print(f"A_n^k gây overflow tại n = {overflow['A_n^k']} (với k = n//2)")
    print(f"C_n^k gây overflow tại n = {overflow['C_n^k']} (với k = n//2)")
    print(f"Số Catalan thứ n gây overflow tại n = {overflow['Catalan']}")