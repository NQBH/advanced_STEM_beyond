def inputmatrix():
    m=int(input("rows: "))
    n=int(input("columns: "))
    a=[]
    for i in range(m):
     row=list (map(int,input(f"row {i+1}: ").split()))
     a.append(row)
    return a
def outputmatrix(a):
    for row in a:
        print(" ".join(map(str,row)))
a=inputmatrix()
outputmatrix(a)