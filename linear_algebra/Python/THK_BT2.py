def add(a,b):
    return [[a[i][j]+b[i][j] for j in range(len(a[0]))] for i in range(len(a))]
def sub(a,b):
    return [[a[i][j]-b[i][j]for j in range(len(a[0]))]for i in range(len(a))]
a=[95,26],[43,69]
b=[42,75],[23,57]
print(add(a,b))
print(sub(a,b))