m, n = map(int, input().split())
t = [int(x) for x in input().split()]
d = [0] * m # devices/machines's current accomplished time
t.sort(reverse = True) # descending order
for i in range(n):
	current_max_work = t[0] # current longest work
	t.pop(0) # remove current longest work
	print(t)
	d.sort() # ascending order
	print(d)
	d[0] += int(current_max_work) # laziest device takes longest work
	print(d)
print(max(d))