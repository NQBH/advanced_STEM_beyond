t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    A = []
    k =  0
    while k < n:
        count = nums.count(nums[k])
        k += count
        A.append(count)
    if len(A) == 1: 
        print(A[0])
    else:
        A.sort()
        B = []
        for i in range(len(A)):
            total = A[i] * (len(A) - i)
            B.append(total)
        print(max(B))
