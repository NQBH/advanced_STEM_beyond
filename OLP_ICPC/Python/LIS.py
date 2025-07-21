def lis_end_at_idx(arr, idx):
	if idx == 0: return 1 # base case
	# consider all elements on the left of i, recursively compute LISs ending with them & consider the largest
	mx = 1
	for prev in range(idx):
		if arr[prev] < arr[idx]:
			mx = max(mx, lis_end_at_idx(arr, prev) + 1)
	return mx

def lis(arr):
	n = len(arr)
	res = 1
	for idx in range(1, n):
		res = max(res, lis_end_at_idx(arr, idx))
	return res

if __name__ == "__main__":
	n = int(input())
	arr = list(map(int, input().split()))
	print(lis(arr))