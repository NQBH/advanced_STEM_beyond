# function to check whether any pair exists whose sum is equal to the given target value
def two_sum_naive(arr, target):
	n = len(arr)
	for i in range(n): # iterate through each element in the array
		for j in range(i + 1, n): # for each element arr[i], check every other element arr[j] that comes after it
			if arr[i] + arr[j] == target: return True # check if the sum of the current pair equals the target
	return False # if no pair is found after checking all possibilities

def two_sum_2_pointer(arr, target):
	arr.sort() # sort array if not sorted yet
	left, right = 0, len(arr) - 1
	while left < right: # iterate while left pointer < right pointer
		sum = arr[left] + arr[right]
		if sum == target: return True # check if the sum matches the target
		elif sum < target: left += 1 # move left pointer to the right
		else: right -= 1 # move right pointer to the left

arr = [0, -1, 2, -3, 1]
target = -2

# call the two_sum_naive function & print the result
if two_sum_naive(arr, target): print("true")
else: print("false")
if two_sum_2_pointer(arr, target): print("true")
else: print("false")