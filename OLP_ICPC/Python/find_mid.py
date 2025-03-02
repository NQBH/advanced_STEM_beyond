def get_sum(a, b):
	return (a + b) * (b - a + 1) // 2

l, r = map(int, input().split())
L, R = l, r
diff = int(1e18)
ans = 0
while L <= R:
	mid = (L + R) // 2
	left_sum = get_sum(l, mid)
	right_sum = get_sum(mid + 1, r)
	if (diff > abs(left_sum - right_sum)):
		diff = abs(left_sum - right_sum)
		ans = mid
	if (left_sum < right_sum): L = mid + 1
	else: R = mid - 1
print(ans)