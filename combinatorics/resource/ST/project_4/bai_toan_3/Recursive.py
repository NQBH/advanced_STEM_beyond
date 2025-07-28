def p_self_recursive(n, k):
    if n == 0 and k == 0:
        return 1
    if n < 0 or k <= 0:
        return 0
    return p_self_recursive(n - (2 * k - 1), k - 1)

# Example usage
n, k = 13, 3
print(f"p_{{{k}}}^{{selfcjg}}({n}) =", p_self_recursive(n, k))