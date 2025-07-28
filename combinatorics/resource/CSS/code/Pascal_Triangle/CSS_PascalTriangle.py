import math
from itertools import product

def pascal_triangle(n):
    """In n+1 dòng đầu tiên của tam giác Pascal"""
    triangle = []
    for k in range(n + 1):
        row = []
        for j in range(k + 1):
            row.append(math.comb(k, j))
        triangle.append(row)
    return triangle

def print_pascal_triangle(triangle):
    """In tam giác Pascal một cách định dạng đẹp"""
    print("Tam giác Pascal:")
    max_width = len(str(max(max(triangle, key=max)))) 
    for row in triangle:
        formatted_row = [str(num).center(max_width) for num in row]
        print(" ".join(formatted_row).center(max_width * (len(triangle) + 1)))

def binomial_expansion(n, a="a", b="b"):
    """Mở rộng nhị thức (a + b)^n"""
    result = []
    for k in range(n + 1):
        coef = math.comb(n, k)
        power_a = n - k
        power_b = k
        term = f"{coef}"
        if power_a > 0:
            term += f"*{a}^{power_a}" if power_a > 1 else f"*{a}"
        if power_b > 0:
            term += f"*{b}^{power_b}" if power_b > 1 else f"*{b}"
        result.append(term)
    return " + ".join(result)

def trinomial_expansion(n, a="a", b="b", c="c"):
    """Mở rộng (a + b + c)^n"""
    result = []
    for i in range(n + 1):
        for j in range(n + 1 - i):
            k = n - i - j
            coef = math.factorial(n) // (math.factorial(i) * math.factorial(j) * math.factorial(k))
            term = f"{coef}"
            if i > 0:
                term += f"*{a}^{i}" if i > 1 else f"*{a}"
            if j > 0:
                term += f"*{b}^{j}" if j > 1 else f"*{b}"
            if k > 0:
                term += f"*{c}^{k}" if k > 1 else f"*{c}"
            result.append(term)
    return " + ".join(result)

def multinomial_expansion(n, m, terms=None):
    """Mở rộng (a_1 + a_2 + ... + a_m)^n"""
    if terms is None:
        terms = [f"a_{i+1}" for i in range(m)]
    result = []
    def generate_indices(m, n):
        if m == 1:
            yield [n]
        else:
            for i in range(n + 1):
                for sub_indices in generate_indices(m - 1, n - i):
                    yield [i] + sub_indices
    
    for indices in generate_indices(m, n):
        coef = math.factorial(n)
        for k in indices:
            coef //= math.factorial(k)
        term = f"{coef}"
        for i, k in enumerate(indices):
            if k > 0:
                term += f"*{terms[i]}^{k}" if k > 1 else f"*{terms[i]}"
        result.append(term)
    return " + ".join(result)

if __name__ == "__main__":
    n = 4
    m = 3
    
    triangle = pascal_triangle(n)
    print_pascal_triangle(triangle)
    
    print(f"\nMở rộng (a + b)^{n}:")
    print(binomial_expansion(n))
    
    print(f"\nMở rộng (a + b + c)^{n}:")
    print(trinomial_expansion(n))
    
    print(f"\nMở rộng (a_1 + a_2 + ... + a_{m})^{n}:")
    print(multinomial_expansion(n, m))