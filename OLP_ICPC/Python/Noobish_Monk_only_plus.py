for _ in range(int(input())):
    arr = sorted(list(map(int,input().split())))
    for i in range(5):
        arr[0]+=1
        arr.sort()
    print(arr[0] * arr[1] * arr[2])