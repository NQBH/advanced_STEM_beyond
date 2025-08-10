# function to find a continuous subarray which adds up to a given number
def subarray_sum(arr, target):
	res = []
	n = len(arr)
	for s in range(n): # pick a starting point for a subarray
		curr = 0 # initialize current calculated sum
		for e in range(s, n): # consider all ending points for the picked starting point
			curr += arr[e]
			if curr == target:
				res.append(s + 1)
				res.append(e + 1)
				return res
	return [-1] # if no subarray is found

if __name__ == "__main__":
	n, x = map(int, input().split())
	arr = list(map(int, input().split()))
	res = subarray_sum(arr, x)
	for ele in res:
		print(ele, end = " ")