A=[[0, 0],[0, 0]]
print('Nhap ma tran A:')
for i in range (2):
    for j in range (2):
        A[i][j]=float(input(f"A[{i}][{j}] = "))   
det=A[0][0]*A[1][1]-A[0][1]*A[1][0]
print('Det A =',det)
