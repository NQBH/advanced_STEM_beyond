n = int(input("nhap n:"))

if n <= 0:
    print("nhap lai n di fen:))")
else:
    print("Ma tran 0:")
    for i in range(n):
        print("0 " * n)

    print("Ma tran don vi:")
    for i in range(n):
        for j in range(n):
            print(1 if i == j else 0, end=" ")
        print()
