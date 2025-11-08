def good(x):
    return x % 2 > 0 and x % 3 > 0 and x % 5 > 0 and x % 7 > 0

def get_naive(x):
    ans = 0
    for i in range(x):
        if good(i):
            ans += 1
    return ans

def get(r):
	return (r // 210) * get_naive(210) + get_naive(r % 210)

t = int(input())
for i in range(t):
    l, r = map(int, input().split())
    print(get(r+1) - get(l))