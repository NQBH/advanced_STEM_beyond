matrix=[list(map(int,input().split()))for _ in range(2)]
a,b=matrix[0]
c,d=matrix[1]
detA=a*d-b*c
for row in matrix:
    print(row)
print(detA)
