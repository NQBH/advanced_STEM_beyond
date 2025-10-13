t = int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split())) 
    nums = list(set(nums))

    dem = 0
    nums.sort()
    for i in range(nums[len(nums)-1]):
        if i != nums[i]: 
            print(i)
            dem += 1
            break
    if dem == 0:
        print(nums[len(nums)-1] + 1)