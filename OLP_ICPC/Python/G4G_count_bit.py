# function to get position of leftmost set bit in n
def get_leftmost_bit(n):
	m = 0
	# iterate until n becomes 1
	while n > 1:
		# right shift n by 1 bit
		n >>= 1
		# increment m to track position of leftmost set bit
		m += 1
	return m # return position of leftmost set bit
# function to get position of next leftmost set bit in n
def get_next_leftmost_bit(n, m):
	temp = 1 << m # create a mask with only mth bit set
	# iterate until n becomes >= the mask
	while n < temp:
		# right shift the mask by 1 bit
		temp >>= 1
		# decrement m to track position of next leftmost set bit
		m -= 1
	return m # return position of next leftmost set bit
#function to count number of set bits in numbers from 1 to n
def count_set_bit(n): # time complexity: O(log n) & auxiliary space: O(1)
	if n == 0:
		return 0 # base case: if n is 0, return 0
	m = get_leftmost_bit(n) # get position of leftmost set bit in n
	m = get_next_leftmost_bit(n, m) # get position of next leftmost set bit in n
	# if n is of the form 2^x - 1, return count directly
	if n == (1 << (m + 1)) - 1:
		return (m + 1) * (1 << m)
	# update n for next recursive call
	n -= 1 << m
	# return count recursively calculated based on updated n
	return (n + 1) + count_set_bit(n) + m * (1 << (m - 1))
if __name__ == "__main__":
	n = int(input())
	print(count_set_bit(n)) # print count of set bits in numbers from 1 to n