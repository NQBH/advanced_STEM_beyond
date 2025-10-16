m = int(input("Nhập số hàng ma trận A: "))
n = int(input("Nhập số cột ma trận A: "))
print("Nhập ma trận A:")
A = []
for i in range(m):
    cot = list(map(float, input(f"Hàng {i+1}: ").split()))
    if len(cot) != n:
        print("Số phần tử không khớp với cột")
        exit()
    A.append(cot)
print("Nhập vector B: ")
b = list(map(float, input().split()))
if len(b) != m:
    print("Impossible!")
else:
    ma_tran = [A[i]+[b[i]] for i in range(m)]
    print("Ma trận bổ sung (A|b): ", ma_tran)
    for cot in ma_tran:
        print(cot)