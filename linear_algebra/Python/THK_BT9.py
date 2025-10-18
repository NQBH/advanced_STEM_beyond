def diag(mat):
    n=len(mat)
    for i in range(n):
        for j in range(n):
            if i!=j & mat[i][j]!=0:
                return False
    return True
def uptri(mat):
    n=len(mat)
    for i in range(1,n):
        for j in range(i):
            if mat[i][j]!=0:
                return False
    return True
def lowtri(mat):
    n=len(mat)
    for i in range(n):
        for j in range(i+1,n):
            if mat[i][j]!=0:
                return False
    return True
def sym(mat):
    n=len(mat)
    for i in range(1):
        for j in range(n):
            if mat[i][j]!=mat[j][i]:
                return False
    return True
def main():
    n=int(input())
    mat=[]
    for _ in range(n):
        row=list(map(int,input().split()))
        mat.append(row)
    print("diagonal:","yes"if diag(mat)else"no")
    print("upper triangle:","yes"if uptri(mat)else"no")
    print("lower triangle:","yes"if lowtri(mat)else"no")
    print("symmetric:","yes" if sym(mat)else"no")
main()