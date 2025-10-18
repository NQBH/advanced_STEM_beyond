def zero(n):
    return[[0 for _ in range(n)]for _ in range(n)]
def unit(n):
    return[[1 if i==j else 0 for j in range(n)]for i in range(n)]
def output_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str,row)))
def main():
    n = int(input())
    zero_matrix=zero(n)
    unit_matrix=unit(n)
    output_matrix(zero_matrix)
    print()
    output_matrix(unit_matrix)
main()
