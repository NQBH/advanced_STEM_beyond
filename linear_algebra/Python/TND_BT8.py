n = int(input("Nhap n: "))

if n <= 0:
    print("Vui long nhap so nguyen duong > 0.")
else:
    print(f"\nMa tran 0 :")
    for i in range(n):
        for j in range(n):
            print(0, end=" ")
        print()

    print(f"\nMa tran don vi :")
    for i in range(n):
        for j in range(n):
            if i == j:
                print(1, end=" ")
            else:
                print(0, end=" ")
        print()
