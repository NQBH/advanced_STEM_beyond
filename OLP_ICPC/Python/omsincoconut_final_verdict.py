for test_case in range(int(input())):
    n, x = [int(_) for _ in input().split()]
    a = [int(_) for _ in input().split()]
    if sum(a) == n*x:
        print("YES")
    else:
        print("NO")