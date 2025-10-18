n = int(input("Nhap so nguyen duong n "))
if n <= 0:
    print("n phai la so nguyen duong")
else:
    print('Ma tran 0')
    for i in range(n):
        for j in range(n):
            print(0, end=' ')
        print()
    print('Ma tran don vi')
    for i in range(n):
        for j in range(n):
            if i == j:
                print(1, end=' ')
            else:
                print(0, end=' ')
        print()