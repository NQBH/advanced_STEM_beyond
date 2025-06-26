ntoida = 1000
pk = [[0 for _ in range(ntoida)] for _ in range(ntoida)]

def solve(n):
    for i in range(n + 1):
        for j in range(n + 1):
            if i == 0 and j == 0:
                pk[0][0] = 1
            elif j == 0 or j > i:
                pk[i][j] = 0
            elif j == i:
                pk[i][j] = 1
            else:
                pk[i][j] = pk[i - 1][j - 1] + pk[i - j][j]

def p(n):
    return sum(pk[n][i] for i in range(0, n + 1))

if __name__ == "__main__":
    n = int(input("Nhap n: "))
    solve(n)
    print(f"p(n) = {p(n)}\n========")
    for i in range(n + 1):
        print(f"p_{i}({n}) = {pk[n][i]}")